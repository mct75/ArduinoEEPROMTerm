#include <Streaming.h>
#include <EEPROM.h>

int c;
int d;
int e;

void setup(){
  Serial.begin(9600);  
  Serial << "Simple EEPROM management tool" << endl << "EEPROM is " << _DEC(E2END+1) << " bytes on your board." << endl 
    << "Therefore, valid addresses are 0 to " << E2END << "." << endl << "Valid data for a single byte is 0 to 255." << endl << endl;
}

void loop(){
  Serial.println("1: Read single");
  Serial.println("2: Read block");
  Serial.println("3: Write single");
  Serial.println("4: Erase all");

  Serial.flush(); 
  do{
  }
  while(!(Serial.available()));
  c=Serial.read();
  Serial.flush();
  Serial.println("");

  switch (c){
  case '1': 
    Serial.println("Which address?");
    do{
    }
    while(!(Serial.available()));
    c=Serial.parseInt();
    d=EEPROM.read(c);
    Serial << "Address " << _DEC(c) << " | " << _DEC(d) << " | 0b" << _BIN(d) 
    << " | 0x" << _HEX(d) << " | ASCII " << _BYTE(d) << endl << endl << endl;
    break;

  case '2': 
    Serial << "Enter start address: ";
    do{
    }
    while(!(Serial.available()));
    c=Serial.parseInt();
    Serial << _DEC(c) << endl << "Enter end address: ";
    do{
    }
    while(!(Serial.available()));
    d=Serial.parseInt();
    Serial << _DEC(d) << endl;
    for(int i = c; i<=d; i++){
      e=EEPROM.read(i);
      Serial << "Address " << _DEC(i) << " | " << _DEC(e) << " | 0b" << _BIN(e) 
      << " | 0x" << _HEX(e) << " | ASCII " << _BYTE(e) << endl;
    }
    Serial << endl << endl;
    break;

  case '3': 
    Serial << "Enter the address to write to: ";
    do{
    }
    while(!(Serial.available()));
    c=Serial.parseInt();
    Serial << _DEC(c) << endl << "Enter the byte to write to this address: ";
    do{
    }
    while(!(Serial.available()));
    d=Serial.parseInt();
    EEPROM.write(c,d);
    d=EEPROM.read(c);
    Serial << "Address " << _DEC(c) << " is now " << _DEC(c) << " | " << _DEC(d) << " | 0b" << _BIN(d) 
    << " | 0x" << _HEX(d) << " | ASCII " << _BYTE(d) << endl << endl << endl;
    break;

  case '4': 
    Serial << "Are you sure you want to reinit the whole flash? (Y/N): ";
    do{
    }
    while(!(Serial.available()));
    c=Serial.read();
    Serial << _BYTE(c) << endl;

    switch(c){
    case 'Y':
    case 'y': 
      Serial << "Programming EEPROM..."<<endl;
      for(int i = 0; i<=E2END; i++){
        EEPROM.write(i,255);
      }
      Serial << "Erase Complete." << endl << endl;
    }
  }
} 


