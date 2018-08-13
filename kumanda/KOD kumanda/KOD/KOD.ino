#include <IRremote.h>  // Kütüphane Eklendi

int RECV_PIN = 11;   // 11 pin VS1838B IN pini

IRrecv irrecv(RECV_PIN); // Alıcı Tanımlandı

decode_results results; // alıcıya gelen sinyalin 
                        // dijital karşılığı
void setup()
{
  Serial.begin(9600); // Ekrana yazmak için
                      // Seri haberleşme başlatıldı
  irrecv.enableIRIn(); // IR haberleşme başlatıldı.
  pinMode(2,OUTPUT);   // 2. ve 3. pindeki Led ayarlandı
  pinMode(3,OUTPUT);


}
void loop() {
  if (irrecv.decode(&results)) { // sinyal algılanırsa
   Serial.println(results.value, HEX); // ekrana hex karşılığını yaz
   
        if(results.value==0xE318261B) // CH- ise 1. Led yansın, E318261B bu kod sizin kumandanızın tuşunun HEX karşılığına göre ayarlanmalıdır, bu aşağıdaki tuşlar içinde geçerlidir.
             digitalWrite(2,HIGH); 
       
          else if(results.value==0x511DBB) // CH ise 2. Led yansın, 
             digitalWrite(3,HIGH);
             
          else if(results.value==0xEE886D7F){ // CH ise 2. ve 3. Led yansın
             digitalWrite(2,HIGH);
             digitalWrite(3,HIGH);
           }
           
          else {                       //Diğer butonlar ise Ledler sönsün
             digitalWrite(2,LOW);
           digitalWrite(3,LOW);
         }
       
    irrecv.resume();             // Yeni bir değer yeniden veri alınacak
  }
  delay(100);                  // Gelen sinyaller arasında karışıklık olmaması
                              // icin 100ms bekleniyor
}
