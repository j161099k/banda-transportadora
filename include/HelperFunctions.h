#include <Arduino.h>

void entrada(int pin) {
    pinMode(pin, INPUT);
}

void salida(int pin) {
    pinMode(pin, OUTPUT);
}

bool estaActivo(int pin) {
    return (digitalRead(pin) == HIGH);
}

void activar(int pin) {
    digitalWrite(pin, HIGH);
}

void desactivar(int pin) {
    digitalWrite(pin, LOW);
}

void invertir(int pin) {
    if(!estaActivo(pin)) {
        activar(pin);
    } else {
        desactivar(pin);
    }
}