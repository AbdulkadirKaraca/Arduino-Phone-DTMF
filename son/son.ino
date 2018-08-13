#include <IRremote.h>
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

int q1_pin=8;
int q2_pin=9;
int q3_pin=10;
int q4_pin=11;
int q1, q2, q3, q4;
int role=5;
int buzzerPin = 4;
int a=1;
int gelen;
boolean A;



void setup(){
  pinMode(q1_pin, INPUT);
  pinMode(q2_pin, INPUT);
  pinMode(q3_pin, INPUT);
  pinMode(q4_pin, OUTPUT);
  pinMode(role, OUTPUT);
  pinMode(buzzerPin,OUTPUT);
   
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  gelen=1;
  A=HIGH;
  
}

void loop(){
 q1=digitalRead(q1_pin);
  q2=digitalRead(q2_pin);
  q3=digitalRead(q3_pin);
   digitalWrite(q4_pin,HIGH);
   
   
  if(q1==1 && q2==0 && q3==0 ) // *1 basılmışsa
  {
    
        LambaYak(gelen);
        gelen=LambaYak(gelen);
        
     
  }
  
  if(q1==0 && q2==1 && q3==0) // #2 basılmışsa
  {
    
   LambaSondur(gelen);
       gelen=LambaSondur(gelen);
    
   // exit(loop);
  }
 if(q1=0 && q2==0 && q3==1)  // *3 basılmışsa
  {
    int kontrol=LambaKontrol();
   // if(gelen==5){
   //  digitalWrite(buzzerPin,HIGH);
     //  delay(1000);
     //  digitalWrite(buzzerPin,LOW); 
     //  delay(1000);
     
        }
   if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
         gelen= LambaYak(gelen);
          
          Serial.println("1");
          break;
          case 0xFF629D:
          Serial.println("2");
          gelen=LambaSondur(gelen);
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
static int LambaYak(int sayac1){
  
  digitalWrite(role,HIGH);
  digitalWrite(3,HIGH);
  while(sayac1<3){
  digitalWrite(buzzerPin,HIGH);
  delay(1000);
  digitalWrite(buzzerPin,LOW); 
  delay(1000);
  sayac1++;
  }
  return 5;
  }
  static int LambaSondur(int sayac2){
    
    
  digitalWrite(role,LOW);
  digitalWrite(3,LOW);
  while(sayac2>1){
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW); 
  delay(100);
  sayac2--;
  
  }
  return 0;
  }
  static int LambaKontrol(){
    if(digitalRead(3)!=HIGH ){
     // int sayac4=1;
    //  while(sayac4<3){
     //   digitalWrite(buzzerPin,HIGH);
      //  delay(1000);
      //  digitalWrite(buzzerPin,LOW); 
       // delay(1000);
      //  sayac4++;
      //  }
      return 1;
      }
      else{
       // int sayac5=1;
     // while(sayac5<3){
       // digitalWrite(buzzerPin,HIGH);
       // delay(100);
       // digitalWrite(buzzerPin,LOW); 
      //  delay(100);
       // sayac5++;
      //  }
      return 0;
        }
    }
  
