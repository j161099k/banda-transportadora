void llenarBotella(int tiempo_de_llenado)
{
    delay(1000);
    digitalWrite(BOMBA_DE_AGUA, HIGH);
    delay(tiempo_de_llenado);
    digitalWrite(BOMBA_DE_AGUA, LOW);
}

bool sensorSeActivo(int sensor)
{
    int lectura_del_sensor = analogRead(sensor);

    Serial.print("Lectura de la fotoresistencia => ");
    Serial.println(lectura_del_sensor);

    return (lectura_del_sensor <= 6);
}

void moverBanda(int tiempo_en_movimiento)
{
    delay(500);
    digitalWrite(MOTOR_BANDA, HIGH);
    delay(tiempo_en_movimiento);
    digitalWrite(MOTOR_BANDA, LOW);
}