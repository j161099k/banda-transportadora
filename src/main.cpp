#include <Arduino.h>

#include <stdlib.h>

#include "ContenedorStruct.h"
#include "HelperFunctions.h"

/**
 * @brief Aquí se declara un arreglo de 3 contenedores,
 * los cuales representan las botellas que se utilizaran.
 * La estructura del contenedor es la siguiente:
 * {capacidad del contenedor, tiempo que tarda en llenarse el contenedor} 
 */
struct contenedor botellas[3] = {
    {500, 5000},
    {750, 7500},
    {1000, 10000}
};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Se utiliza un generador aleatorio de números para simular una lectura en el sensor, esto debe ser remplazado por la verdadera lectura y calculo del volumen del contenedor
  float volumen_botella = (rand() % 10 + 1) * 100.0; 

  struct contenedor botella_seleccionada; //Se define un contenedor vacío
  
  //Se define una variable de control, para identificar si la botella que se mide coincide con alguna de las que existen en el arreglo
  bool botella_coincide = false;

  //Se realiza una iteración de los contenedores registrados en el arreglo
  for (struct contenedor botella : botellas)
  {
    if (botella.volumen != volumen_botella)
    {
      continue; //Si el volumen de la botella no se corresponde con el que fue calculado con ayuda del sensor, revisa la siguiente botella
    }

    //Caso contrario, se iguala el contenido del contenedor vacío con el del contenedor que se está revisando y se rompe el ciclo

    botella_seleccionada = botella;
    botella_coincide = true;
    break;
  }

  if (botella_coincide)
  {
    //Aquí debería de activarse la válvula que se utilizará para llenar el contenedor

    //Espera el tiempo que tarda el contenedor en llenarse
    delay(botella_seleccionada.tiempo_llenado);

    //Finalmente imprime el tiempo en el que se llenó el contenedor, aquí debe ir el código que active nuevamente la banda para que esta continue su funcionamiento
    Serial.print("Botella Llenada en ");
    Serial.print(botella_seleccionada.tiempo_llenado / 1000);
    Serial.println("s");
  }
}