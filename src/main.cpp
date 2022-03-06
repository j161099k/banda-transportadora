#include <Arduino.h>

#include <stdlib.h>

const int
    // Pin en el que se ubica la bomba de agua
    BOMBA_DE_AGUA = 11,
    MOTOR_BANDA = 12,

    // Cantidad de sensores que activa cada tamaño de botella
    CHICO = 1,
    MEDIANO = 2,
    GRANDE = 3,

    // tiempo que tarda cada tamaño de botella en llenarse
    TIEMPO_LLENADO_CHICO = 5000,
    TIEMPO_LLENADO_MEDIANO = 7500,
    TIEMPO_LLENADO_GRANDE = 10000,

    // Pin en el que se ubica cada sensor
    SENSOR_ABAJO = A0,
    SENSOR_EN_MEDIO = A1,
    SENSOR_ARRIBA = A2,
    SENSOR_ARRANQUE = 7;

void llenarBotella(int), 
      moverBanda();
bool sensorSeActivo(int);

void setup()
{
  Serial.begin(9600);

  pinMode(BOMBA_DE_AGUA, OUTPUT);
  pinMode(MOTOR_BANDA, OUTPUT);
  pinMode(SENSOR_ABAJO, INPUT);
  pinMode(SENSOR_EN_MEDIO, INPUT);
  pinMode(SENSOR_ARRIBA, INPUT);
  pinMode(SENSOR_ARRANQUE, INPUT);
}

void loop()
{
  if (digitalRead(SENSOR_ARRANQUE) == HIGH)
  {
     moverBanda();
  }
  int sensores_activos = (sensorSeActivo(SENSOR_ABAJO) + sensorSeActivo(SENSOR_EN_MEDIO) + sensorSeActivo(SENSOR_ARRIBA));

  switch (sensores_activos)
  {
  case CHICO:
    llenarBotella(TIEMPO_LLENADO_CHICO);
    moverBanda();
    break;
  case MEDIANO:
    llenarBotella(TIEMPO_LLENADO_MEDIANO);
    moverBanda();
    break;
  case GRANDE:
    llenarBotella(TIEMPO_LLENADO_GRANDE);
    moverBanda();
    break;
   
  }
 
}

void llenarBotella(int tiempo_de_llenado)
{
  delay(1000);
  digitalWrite(BOMBA_DE_AGUA, HIGH);
  delay(tiempo_de_llenado);
  digitalWrite(BOMBA_DE_AGUA, LOW);
}

bool sensorSeActivo(int sensor)
{
  return (analogRead(sensor) <= 6);
}

void moverBanda() 
{
  delay(500);
  digitalWrite(MOTOR_BANDA, HIGH);
  delay(10000);
  digitalWrite(MOTOR_BANDA, LOW);
}