// Bibliotecas
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


// --> Apelidos <--

//Semáforo 1

#define vmA 7 // Led Vermelho   A
#define amA 6 // Led Amarelo    A
#define vdA 5 // Led Verde      A

//Semáforo 2

#define vmB 4 // Led Vermelho   B
#define amB 3 // Led Amarelo    B
#define vdB 2 // Led Verde      B

//Display LCD

#define endereco 0x27  // Endereço representa o chip do módulo I2C
#define colunas 16     // Número de colunas do Display 
#define linhas 2       // Número de linhas do Display 

//Criando uma estrutura com o nome "lcd" nos parâmetros indicados
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

// variáveis globais
int x = 0;

void setup() {

  //Display LCD
  lcd.init();       // Inicializando o LCD
  lcd.backlight();  // Ligando a luz de fundo do LCD

  //Semáforo 1
  pinMode(vmA, OUTPUT);
  pinMode(amA, OUTPUT);
  pinMode(vdA, OUTPUT);

  //Semáforo 2
  pinMode(vmB, OUTPUT);
  pinMode(amB, OUTPUT);
  pinMode(vdB, OUTPUT);

}

void loop() {

  //Situação 1

  lcd.setCursor(0, 0);
  lcd.print("S1: ABERTO ");
  lcd.setCursor(0, 1);
  lcd.print("S2: FECHADO ");

  semaforoA (LOW, LOW, HIGH);  //S1: ABERTO  (Led verde)
  semaforoB (HIGH, LOW, LOW);  //S2: FECHADO (Led vermelho)

  //Temporizador de 6 segundos
  lcd.setCursor(14, 1);
  lcd.print("9s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("8s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("7s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("6s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("5s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("4s");
  delay(1000);

  //Situação 2

  lcd.setCursor(0, 0);
  lcd.print("S1: ESPERA  ");
  lcd.setCursor(0, 1);
  lcd.print("S2: FECHADO       ");

  semaforoA (LOW, HIGH, LOW);  //S1: ESPERA  (Led amarelo)
  semaforoB (HIGH, LOW, LOW);  //S2: FECHADO (Led vermelho)

  //Temporizador de 3 segundos
  lcd.setCursor(14, 1);
  lcd.print("3s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("2s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("1s");
  delay(1000);

  //Situação 3

  lcd.setCursor(0, 0);
  lcd.print("S1: FECHADO   ");
  lcd.setCursor(0, 1);
  lcd.print("S2: ABERTO       ");

  semaforoA(HIGH, LOW, LOW);   //S1: FECHADO (Led vermelho)
  semaforoB(LOW, LOW, HIGH);   //S2: ABERTO  (Led verde)

  //Temporizador de 6  segundos
  lcd.setCursor(14, 1);
  lcd.print("9s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("8s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("7s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("6s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("5s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("4s");
  delay(1000);


  //Situação 4

  lcd.setCursor(0, 0);
  lcd.print("S1: FECHADO     ");
  lcd.setCursor(0, 1);
  lcd.print("S2: ESPERA");

  semaforoA(HIGH, LOW, LOW);  //S1: FECHADO (Led vermelho)
  semaforoB(LOW, HIGH, LOW);  //S2: ESPERA  (Led amarelo)

  //Temporizador de 3 segundos
  lcd.setCursor(14, 1);
  lcd.print("3s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("2s");
  delay(1000);

  lcd.setCursor(14, 1);
  lcd.print("1s");
  delay(1000);


}

//Semáforo 1
void semaforoA(int estadoVm, int estadoAm, int estadoVd) {

  digitalWrite(vmA, estadoVm);
  digitalWrite(amA, estadoAm);
  digitalWrite(vdA, estadoVd);

}

void semaforoB(int estadoVm, int estadoAm, int estadoVd) {

  digitalWrite(vmB, estadoVm);
  digitalWrite(amB, estadoAm);
  digitalWrite(vdB, estadoVd);
}
