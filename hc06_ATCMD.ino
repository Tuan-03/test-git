#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(2,3); //TX Bluetooth - RX 2, RX Bluetooth - TX 3

void setup(){
  //Khởi tạo Serial
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Khởi tạo Bluetooth
  Bluetooth.begin(9600);
}

void loop()
{
  //Đọc dữ liệu từ HC-06 gửi đến Arduino
  if (Bluetooth.available()){
    Serial.write(Bluetooth.read());
  }
  
  //Đọc dữ liệu từ arduino gửi đến HC-06
  if (Serial.available()){
    Bluetooth.write(Serial.read());
  }  
}
