#include <EEPROM.h>
char c;

void setup(){
Serial.begin(9600);  
}

void loop(){
  Serial.println("1: Read single");
  Serial.println("2: Read block");
  Serial.println("3: Read all");
  Serial.println("4: Write single");
  Serial.println("5: Erase all");
  
  Serial.flush(); 
  do{}while(!(Serial.available()));
  c=Serial.read();
  Serial.flush();
  Serial.println("");
  
  switch (c){
    case '1': Serial.println("Which address?");
            do{}while(!(Serial.available()));
            c=Serial.parseInt();
            Serial.println(EEPROM.read(c));
            break;
  }
}
    
