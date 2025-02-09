#include <SoftwareSerial.h> //Thư viện sử dụng bất kỳ 2 chân digital nào để làm chân TX RX
SoftwareSerial mybluetooth(2,3); // Khai báo tên Bluetooth và chân TX RX (2-TX, 3-RX)

char docgiatri; //Biến docgiatri kiểu char
#define led1 8 //Khai báo chân led số 8
#define led2 A0 //Khai báo chân led A0

void setup() 
{
  Serial.begin(9600);
  
  mybluetooth.begin(9600); //Kết nối Bluetooth với tốc độ baud là 9600

  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  analogWrite(led2, LOW);
}

void loop() 
{
  if(mybluetooth.available() > 0) //Nếu tín hiệu của bluetooth lớn hơn 0, tức là đã kết nối OK
  {
    docgiatri = mybluetooth.read(); //Đọc các giá trị trên app được kết nối qua bluetooth và gán vào docgiatri
    Serial.print("Giá trị đọc được: ");      
    Serial.print(docgiatri); //in giá trị lên cổng Serial 
  

      if (docgiatri == '1')
      {
        digitalWrite(led1, HIGH);
        Serial.println(" - Đèn 1 ON");      
      }
      if (docgiatri == '2')
      {
        digitalWrite(led1, LOW);
        Serial.println(" - Đèn 1 OFF");
      }

    
      if (docgiatri == '3')
      {
        analogWrite(led2, 1023);
        Serial.println(" - Đèn 2 ON");
      }
      if (docgiatri == '4')
      {
        analogWrite(led2, 0);
        Serial.println(" - Đèn 2 OFF");
      }

    }
  
}
