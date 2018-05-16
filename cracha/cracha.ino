  

// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

String frases[] = {
  "                Membro da staff =)",
  "                Hoje eh um dia lindo, nao?",
  "                Que evento fantastico esse!",
  "                Bora hackear alguma coisa?",
  "                So vai!",
  "                Nao tem coffee break =(",
  "                Vale mais um arduino na mao, do que varios queimados!",
  "                Quem mexe com ferro de solda, com ferro de solda se queima!",
  "                Imagina se fizesse isso com arduino!",
  "                Arduino faz ate cafe!"
};

void printfrase(int idx){
  int fim;
  for(int i = 0; i < frases[idx].length() + 1; i++){
    lcd.setCursor(0,1);
    lcd.print(frases[idx].substring(i + 0, i + 16) + "                ");
    delay(250);
  }
}
 
void setup()
{
  lcd.begin (16,2);
  randomSeed(analogRead(0));
}
 
void loop()
{
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("  Daniel Junho  ");
  printfrase(random(sizeof(frases)/sizeof(String)));
  delay(1000);
  lcd.setBacklight(LOW);
  delay(1000);
}

