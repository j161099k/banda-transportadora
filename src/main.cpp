#include <Arduino.h>

#include <stdlib.h>
#include <time.h>

#include "ContenedorStruct.h"
#include "HelperFunctions.h"

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
  float volumen_botella = (rand() % 10 + 1) * 100.0;

  struct contenedor botella_seleccionada;

  bool botella_coincide = false;

  for (struct contenedor botella : botellas)
  {
    if (botella.volumen != volumen_botella)
    {
      continue;
    }

    botella_seleccionada = botella;
    botella_coincide = true;
    break;
  }

  if (botella_coincide)
  {
    delay(botella_seleccionada.tiempo_llenado);

    Serial.print("Botella Llenada en ");
    Serial.print(botella_seleccionada.tiempo_llenado / 1000);
    Serial.println("s");
  }
}