#include <Keypad.h>

const byte ROWS = 4; //4 baris
const byte COLS = 3; //3 kolom
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //koneksi baris ke pin Arduino
byte colPins[COLS] = {6, 7, 8}; //koneksi kolom ke pin Arduino

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600); //baud rate 9600 bps
}
  
void loop(){
  char key = keypad.getKey();//baca keypad
  
  if (key != NO_KEY){ //jika ada tombol ditekan
    Serial.println(key);//kirim tombol ke serial
  }
}

