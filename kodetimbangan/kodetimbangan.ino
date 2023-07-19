#include <HX711.h> //Include Library HX711 Bogdan Necula
#include <Wire.h>  //Include Library Wire untuk I2C
#include <LiquidCrystal_I2C.h>  //Include Library LiquidCrystal_I2C untuk LCD

HX711 timbangan; //deklarasikan instance dari class HX711, bernama 'timbangan'.
const float calibration_factor = 1000.0; //atur sesuai kebutuhan.

LiquidCrystal_I2C lcd(0x27, 16, 2);  //Inisialisasikan modul LCD dengan I2C address and besar LCD, yakni 16x2

void setup() { //setup board Arduino
  lcd.begin(16, 2);  //Initialisasikan LCD
  
  //initialisasikan timbangan dengan HX711
  timbangan.begin(2, 3);  //Koneksikan DT ke pin 2, dan SCK ke pin 3
  timbangan.set_scale(calibration_factor); //set faktor calibration dari timbangan
  timbangan.tare();  //kosongkan timbangan kembali ke 0;
  
  lcd.setCursor(0, 0); //set cursor LCD ke pojok kiri atas
  lcd.print("Weight: "); //print "Weight: " pada LCD
}

void loop() { //loop yang terus berjalan ketika arduino digunakan

  float berat = timbangan.get_units(); //baca nilai berat dari strain gauge, melalui HX711 Amplifier, berupa gram
  berat /= 1000; //konversikan berat dari gram ke kilogram

  lcd.setCursor(8, 0);
  //output hasil nilai berat ke LCD
  lcd.print(berat, 2); //tampilkan sebagai desimal dua digit
  lcd.print(" kg");
  delay(1000);  //Tunggu sekitar 1 detik sebelum melakukan pengukuran berikutnya
} 