### Semáforo com Display com I2C


semaforo_lcd_1_3_0

  Deseja-se controlar dois semáforos em um cruzamento de duas vias (Atividade Aula 03).
  É solicitado que na caixa de controle do sistema tenha um lcd 16 x 2 para informar o estado de cada semáforo.

   Onde no display com I2C, aparecerão as seguintes mensagens:

   Caso 1:

   - S1: ABERTO
   - S2: FECHADO

   Caso 2:

   - S1: ESPERA
   - S2: FECHADO

   Caso 3:

   - S1: FECHADO
   - S2: ABERTO

   Caso 3:

   - S1: FECHADO
   - S2: ESPERA

   Caso 4:

   - S1: ABERTO
   - S2: FECHADO

   A partir do caso 4, repete-se o ciclo novamente.

   Componentes:

   - Arduino Uno CP2102
   - Display 16x2 com I2C
   - Leds
   -  2 vermelhos
   -  2 amarelos
   -  2 verdes
   - Resistores
   - Jumpers diversos

   Conexões Arduino:

   LCD I2C – SDA (A4)
           - SCL (A5)

   Semáforo 1

 -  Led Vermelho  (7)
 -  Led Amarelo   (6)
 -  Led Verde     (5)

   Semáforo 2

 -  Led Vermelho  (4)
 -  Led Amarelo   (3)
 -  Led Verde     (2)


   Versão:
  -  0.0.0 -> Arrumando o cabeçalho
  - 0.1.0 -> Colocando a biblioteca I2C e #defines
  -  1.2.0 -> definindo pinos do arduino e arrumando o void setup (acrescentando o pinMode)
  -  1.3.0 -> Criando a void SemaforoA e SemaforoB
  - Acrescentando o lcd.setCursor, lcd.print e delay 

 -->  Data: 21/09/2021
 
 -->  Andressa Mikaela Padilha
