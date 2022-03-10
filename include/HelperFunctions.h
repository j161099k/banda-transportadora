void llenarBotella(int tiempo_de_llenado)
{
    delay(RETARDO_LLENADO_DE_CONTENEDOR);
    digitalWrite(BOMBA_DE_AGUA, HIGH);
    delay(tiempo_de_llenado);
    digitalWrite(BOMBA_DE_AGUA, LOW);
}

bool sensorSeActivo(int sensor)
{
    return (analogRead(sensor) <= VALOR_MINIMO_FOTORESISTENCIA);
}

void moverBanda(int tiempo_en_movimiento)
{
    delay(RETARDO_ARRANQUE_DE_BANDA);
    digitalWrite(MOTOR_BANDA, HIGH);
    delay(tiempo_en_movimiento);
    digitalWrite(MOTOR_BANDA, LOW);
}