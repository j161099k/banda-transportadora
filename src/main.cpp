#include <Arduino.h>

// ../include/ConstantsDefinition.h
#include "ConstantDefinitions.h"

// ../include/HelperFunctions.h
#include "HelperFunctions.h"

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
    moverBanda(10000);

    const int tamano_del_contenedor = ( sensorSeActivo(SENSOR_ABAJO) + sensorSeActivo(SENSOR_EN_MEDIO) + sensorSeActivo(SENSOR_ARRIBA) );

    switch (tamano_del_contenedor)
    {
    case CHICO:
      llenarBotella(TIEMPO_LLENADO_CHICO);
      break;

    case MEDIANO:
      llenarBotella(TIEMPO_LLENADO_MEDIANO);
      break;

    case GRANDE:
      llenarBotella(TIEMPO_LLENADO_GRANDE);
      break;
    }

    moverBanda(2500);
  }
}