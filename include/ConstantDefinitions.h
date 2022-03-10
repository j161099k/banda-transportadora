
// Pin en el que se ubica la bomba de agua
#define BOMBA_DE_AGUA                               11

// Pin en el que se ubica el motor de la banda transportadora
#define MOTOR_BANDA                                 12

// Cantidad de sensores que activa cada tamaño de botella
#define CONTENEDOR_CHICO                            1
#define CONTENEDOR_MEDIANO                          2
#define CONTENEDOR_GRANDE                           3

// tiempo que tarda cada tamaño de botella en llenarse
#define TIEMPO_LLENADO_CONTENEDOR_CHICO             5000
#define TIEMPO_LLENADO_CONTENEDOR_MEDIANO           7500
#define TIEMPO_LLENADO_CONTENEDOR_GRANDE            10000

// Pin en el que se ubica cada sensor
#define SENSOR_ABAJO                                A0
#define SENSOR_EN_MEDIO                             A1
#define SENSOR_ARRIBA                               A2

#define SENSOR_ARRANQUE                             7


// Constantes para el control del programa
#define VALOR_MINIMO_FOTORESISTENCIA                6
#define RETARDO_LLENADO_DE_CONTENEDOR               250
#define RETARDO_ARRANQUE_DE_BANDA                   500