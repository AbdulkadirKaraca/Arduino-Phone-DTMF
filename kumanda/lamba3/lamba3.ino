#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
          digitalWrite(3,HIGH); 
          delay(500);
          Serial.println("1");
          break;
          case 0xFF629D:
          Serial.println("2");
          delay(500);
          digitalWrite(3,LOW);
          break;
          case 0xFFE21D:
          Serial.println("3");
          break;
          default: 
          Serial.println(" ble buton yok kardo  ");     
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
