#include <Streaming.h>
#include <EEPROM.h>

int c;
int d;

void setup(){
Serial.begin(9600);  
}

void loop(){
  Serial.println("1: Read single");
  Serial.println("2: Read block");
  Serial.println("3: Write single");
  Serial.println("4: Erase all");
  
  Serial.flush(); 
  do{}while(!(Serial.available()));
  c=Serial.read();
  Serial.flush();
  Serial.println("");
  
  switch (c){
    case '1': Serial.println("Which address?");
              do{}while(!(Serial.available()));
              c=Serial.parseInt();
              Serial << "Address " << _DEC(c) << " is " << EEPROM.read(c) << endl << endl << endl;
              break;
            
    case '2': Serial << "Enter start address: ";
              do{}while(!(Serial.available()));
              c=Serial.parseInt();
              Serial << _DEC(c) << endl << "Enter end address: ";
              do{}while(!(Serial.available()));
              d=Serial.parseInt();
              Serial << _DEC(d) << endl;
              for(int i = c; i<=d; i++){
                Serial << "Address " << _DEC(i) << " is " << EEPROM.read(i) << endl;
                }
                Serial << endl << endl;
              break;
  }
}
    
