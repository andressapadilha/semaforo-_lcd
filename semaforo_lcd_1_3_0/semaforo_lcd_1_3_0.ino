/* semaforo_lcd_1_3_0

  Deseja-se controlar dois semáforos em um cruzamento de duas vias (Atividade Aula 03).
  É solicitado que na caixa de controle do sistema tenha um lcd 16 x 2 para informar o estado de cada semáforo.

    Onde no display com I2C, aparecerão as seguintes mensagens:

    Caso 1:

    S1: ABERTO
    S2: FECHADO

    Caso 2:

    S1: ESPERA
    S2: FECHADO

    Caso 3:

    S1: FECHADO
    S2: ABERTO

    Caso 3:

    S1: FECHADO
    S2: ESPERA

    Caso 4:

    S1: ABERTO
    S2: FECHADO

    A partir do caso 4, repete-se o ciclo novamente.

    Componentes:

    - Arduino Uno CP2102
    - Display 16x2 com I2C
    - Leds
      2 vermelhos
      2 amarelos
      2 verdes
    - Resistores
    - Jumpers diversos


   Conexões Arduino:

   LCD I2C – SDA (A4)
             SCL (A5)

   Semáforo 1

   Led Vermelho  (7)
   Led Amarelo   (6)
   Led Verde     (5)

   Semáforo 2

   Led Vermelho  (4)
   Led Amarelo   (3)
   Led Verde     (2)


   Versão:
   0.0.0 -> Arrumando o cabeçalho
   0.1.0 -> Colocando a biblioteca I2C e #defines
   1.2.0 -> definindo pinos do arduino e arrumando o void setup (acrescentando o pinMode)
   1.3.0 -> Criando a void SemaforoA e SemaforoB
   - Acrescentando o lcd.setCursor, lcd.print e delay 

   Data: 21/09/2021
   Andressa Mikaela Padilha
*/

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
