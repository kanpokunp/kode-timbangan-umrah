#include <Wire.h>  //Include Library Wire untuk I2C
#include <LiquidCrystal_I2C.h>  //Include Library LiquidCrystal_I2C untuk LCD
#include <HX711.h> //Include Library HX711 Bogdan Necula

HX711 timbangan; //deklarasikan instance dari class HX711, bernama 'timbangan'.
const float kalibrasi = 1200.0; //atur sesuai kebutuhan.

LiquidCrystal_I2C lcd(0x27, 16, 2);  //Inisialisasikan modul LCD dengan I2C address and besar LCD, yakni 16x2

void setup() { //setup board Arduino
  lcd.init();
  lcd.backlight();

   //inisialisasikan timbangan dengan HX711
  timbangan.begin(2, 3);  //Koneksikan DT ke pin 2, dan SCK ke pin 3
  timbangan.set_scale(kalibrasi); //set faktor kalibrasi dari timbangan
  timbangan.tare();  //kosongkan timbangan kembali ke 0;

  // tambah delay 100 milidetik agar sensor bisa stabil dahulu
  delay(100);

  lcd.setCursor(0, 0); //set cursor LCD ke pojok kiri atas
  lcd.print("Berat: "); //print "Weight: " pada LCD
}

void loop() { //loop yang terus berjalan ketika arduino digunakan

  float berat_gram = timbangan.get_units(); //baca berat dari sensor, berupa gram

  if (berat_gram < 0) {
    berat_gram = 0;   //pastikan berat tidak muncul negatif
  }

  float berat_kg = berat_gram / 1000; //konversikan berat dari gram ke kilogram

  lcd.setCursor(8, 0); //output hasil nilai berat ke LCD
  lcd.print(berat_kg, 3); //tampilkan sebagai desimal dua digit
  lcd.print(" kg");
  
  delay(500);  //Tunggu sekitar 0.5 detik sebelum melakukan pengukuran berikutnya
}
