//int buzzerPin=4; 
#include <IRremote.h> 
int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results; 
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(3, OUTPUT);
 // pinMode(buzzerPin,OUTPUT); 
  

}

void loop() {

  if (irrecv.decode(&results)) { // sinyal algılanırsa
   Serial.println(results.value, DEC); // ekrana hex karşılığını yaz
   
        if(results.value==16736925) // CH- ise 1. Led yansın, E318261B bu kod sizin kumandanızın tuşunun HEX karşılığına göre ayarlanmalıdır, bu aşağıdaki tuşlar içinde geçerlidir.
             digitalWrite(3,HIGH); 
       
          else if(results.value==2) // CH ise 2. Led yansın, 
             digitalWrite(3,LOW);
          
          else {                       //Diğer butonlar ise Ledler sönsün
             //digitalWrite(3,LOW);
           digitalWrite(3,LOW);
         }
       
    irrecv.resume();             // Yeni bir değer yeniden veri alınacak
  }
  delay(100);                  // Gelen sinyaller arasında karışıklık olmaması
                              // icin 100ms bekleniyor
}

