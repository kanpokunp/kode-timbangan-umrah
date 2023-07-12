// Inisialisasikan Library HX711 sebelum Startup. 
//Download dulu Library HX711 melalui Sketch > Include Libraries > Manage Libraries. cari "HX711 by Bogdan Necula" lalu install versi 0.7.5
#include <HX711.h>

HX711 timbangan; // deklarasikan instance dari class HX711, bernama 'timbangan'.

const float calibration_factor = 1000.0;  // atur sesuai kebutuhan.

void setup() { //setup board Arduino
  Serial.begin(9600); //baud rate
  
  // initialisasikan HX711 scale
  timbangan.begin(2, 3);  // Koneksikan DT ke pin 2, dan SCK ke pin 3
  
  timbangan.set_scale(calibration_factor);  // Set faktor calibration dari timbangan
  timbangan.tare();  // kosongkan timbangan kembali ke 0;
}

void loop() { //loop yang terus berjalan ketika arduino board digunakan

  float berat = timbangan.get_units(); // baca nilai berat dari strain gauge, melalui HX711 Amplifier, berupa gram
  berat /= 1000; //konversikan berat dari gram ke kilogram

  // output hasil nilai berat ke monitor (melalui Command Line Interface)
  Serial.print("Berat: ");
  Serial.print(berat);
  Serial.println(" kilogram");
  
  delay(1000);  // Tunggu sekitar 1 detik sebelum melakukan pengukuran berikutnya.
}