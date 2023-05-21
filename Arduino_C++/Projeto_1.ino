// C++ code
//
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

Servo servoContinuo;
Adafruit_LiquidCrystal LCD(0);
int SensorTempPino = 0;
const int PIN_SERVO_CONTINUO = 9;
int buzzer = 13;
int alerta_Azul_1 = 3;
int alerta_Azul_2 = 4;
int alerta_Azul_3 = 5;
int alerta_Laranja_1 = 6;
int alerta_Laranja_2 = 7;
int alerta_Vermelho_1 = 8;
int temp_Minima = -20;
int temp_Muito_Baixa = -10;
int temp_Baixa = 0;
int temp_Media = 10;
int temp_Media_Servo = 15;
int temp_Alta = 20;



void setup() {
  servoContinuo.attach(PIN_SERVO_CONTINUO);
  pinMode(buzzer, OUTPUT);
  LCD.begin(16,2);
  //escreve mensagem
  LCD.print("Temperatura:");
  // Muda a linha do lcd
  LCD.setCursor(0,1);
  //escreve a mensagem
  LCD.print("      C");
}


void loop()
{
    int SensorTempTensao = analogRead(SensorTempPino);
    float Tensao = SensorTempTensao * 5;
    Tensao /= 1024;
    float TemperaturaC = (Tensao - 0.5) * 100;
    LCD.setCursor(0,1);
    LCD.print(TemperaturaC);
   
  if (TemperaturaC <= temp_Minima ) {
     
    digitalWrite(alerta_Azul_1, HIGH);
    digitalWrite(alerta_Azul_2, LOW);
    digitalWrite(alerta_Azul_3, LOW);
    digitalWrite(alerta_Laranja_1, LOW);
    digitalWrite(alerta_Laranja_2, LOW);
    digitalWrite(alerta_Vermelho_1, LOW);
    servoContinuo.write(1500);
    digitalWrite(buzzer, LOW);
    delay(1000);
  
  }
  else if (TemperaturaC <= temp_Muito_Baixa) {
    digitalWrite(alerta_Azul_1, HIGH);
    digitalWrite(alerta_Azul_2, HIGH);
    digitalWrite(alerta_Azul_3, LOW);
    digitalWrite(alerta_Laranja_1, LOW);
    digitalWrite(alerta_Laranja_2, LOW);
    digitalWrite(alerta_Vermelho_1, LOW);
    digitalWrite(buzzer, LOW);
    servoContinuo.write(1500);
    delay(1000);


    
  }
  else if (TemperaturaC <= temp_Baixa) {
    digitalWrite(alerta_Azul_1, HIGH);
    digitalWrite(alerta_Azul_2, HIGH);
    digitalWrite(alerta_Azul_3, HIGH);
    digitalWrite(alerta_Laranja_1, LOW);
    digitalWrite(alerta_Laranja_2, LOW);
    digitalWrite(alerta_Vermelho_1, LOW);
    digitalWrite(buzzer, LOW);
    servoContinuo.write(1500);
    delay(1000);
   
  }
  else if (TemperaturaC <= temp_Media) {
    digitalWrite(alerta_Azul_1, HIGH);
    digitalWrite(alerta_Azul_2, HIGH);
    digitalWrite(alerta_Azul_3, HIGH);
    digitalWrite(alerta_Laranja_1, HIGH);
    digitalWrite(alerta_Laranja_2, LOW);
    digitalWrite(alerta_Vermelho_1, LOW);
    servoContinuo.write(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);

 
  }
  else if (TemperaturaC <= temp_Media_Servo){
    digitalWrite(alerta_Azul_1, HIGH);
    digitalWrite(alerta_Azul_2, HIGH);
    digitalWrite(alerta_Azul_3, HIGH);
    digitalWrite(alerta_Laranja_1, HIGH);
    digitalWrite(alerta_Laranja_2, LOW);
    digitalWrite(alerta_Vermelho_1, LOW);
    servoContinuo.write(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
  }
 
    else if (TemperaturaC <= temp_Alta) {
    digitalWrite(alerta_Azul_1, HIGH);
    digitalWrite(alerta_Azul_2, HIGH);
    digitalWrite(alerta_Azul_3, HIGH);
    digitalWrite(alerta_Laranja_1, HIGH);
    digitalWrite(alerta_Laranja_2, HIGH);
    digitalWrite(buzzer, LOW);
    servoContinuo.write(0); 
    delay(1000);
    
  }
   else if (TemperaturaC >= temp_Alta) {
    digitalWrite(alerta_Azul_1, HIGH);
    digitalWrite(alerta_Azul_2, HIGH);
    digitalWrite(alerta_Azul_3, HIGH);
    digitalWrite(alerta_Laranja_1, HIGH);
    digitalWrite(alerta_Laranja_2, HIGH);
    digitalWrite(alerta_Vermelho_1, HIGH);
    servoContinuo.write(0);
    digitalWrite(buzzer, LOW);
     delay(1000);


   }
  
   
}
