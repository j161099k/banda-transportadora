#include <stdio.h>
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

    // Se cuenta cuantos sensores se activaron, a traves de una suma
    const int tamano_del_contenedor = ( sensorSeActivo(SENSOR_ABAJO) + sensorSeActivo(SENSOR_EN_MEDIO) + sensorSeActivo(SENSOR_ARRIBA) );

    switch (tamano_del_contenedor)
    {
    case CONTENEDOR_CHICO: // si el valor de tamano_del_contenedor es 1:
      llenarBotella(TIEMPO_LLENADO_CONTENEDOR_CHICO);
      break;

    case CONTENEDOR_MEDIANO: // si el valor de tamano_del_contenedor es 2:
      llenarBotella(TIEMPO_LLENADO_CONTENEDOR_MEDIANO);
      break;

    case CONTENEDOR_GRANDE: // si el valor de tamano_del_contenedor es 3:
      llenarBotella(TIEMPO_LLENADO_CONTENEDOR_GRANDE);
      break;
    }

    moverBanda(2500);
  }
}