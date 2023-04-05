#include <Arduino.h>
#line 1 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U1\\luces_rgb\\luces_rgb.ino"
// Definición de variables

int ledRojo = 9;
int ledVerde = 10;
int ledAzul = 11;

int ledTest = 13;

int rojo = 0;
int verde = 0;
int azul = 0;
int todos = 0;

// Inicialización de la placa
#line 15 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U1\\luces_rgb\\luces_rgb.ino"
void setup();
#line 39 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U1\\luces_rgb\\luces_rgb.ino"
void loop();
#line 103 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U1\\luces_rgb\\luces_rgb.ino"
void gradualUp(int led);
#line 110 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U1\\luces_rgb\\luces_rgb.ino"
void gradualDown(int led);
#line 117 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U1\\luces_rgb\\luces_rgb.ino"
void setLedRGB(int r, int g, int b);
#line 15 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U1\\luces_rgb\\luces_rgb.ino"
void setup () {
    // Iniciar pines

    pinMode(ledRojo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAzul, OUTPUT);
    pinMode(ledTest, OUTPUT);

    // Apagar los leds
    analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 0);
    analogWrite(ledAzul, 0);
    digitalWrite(ledTest, LOW);

    // Saludo inicial (handshake)
    for (int i = 0; i < 3; i++) {
        digitalWrite(ledTest, HIGH);
        delay(500);
        digitalWrite(ledTest, LOW);
        delay(500);
    }
}

// Bucle infinito
void loop () {
    // Enciendo y apago gradualmente el led rojo
    gradualUp(ledRojo);
    gradualDown(ledRojo);

    // Enciendo y apago gradualmente el led verde
    gradualUp(ledVerde);
    gradualDown(ledVerde);

    // Enciendo y apago gradualmente el led azul
    gradualUp(ledAzul);
    gradualDown(ledAzul);

    // Enciendo gradualmente el rojo
    gradualUp(ledRojo);
    delay(500);

    // Sumo gradualmente el verde
    gradualUp(ledVerde);
    delay(500);

    // Sumo gradualmente el azul
    gradualUp(ledAzul);
    delay(500);

    // Resto gradualmente el verde
    gradualDown(ledVerde);
    delay(500);

    // Resto gradualmente el rojo
    gradualDown(ledRojo);
    delay(500);

    // Resto gradualmente el azul
    gradualDown(ledAzul);

    delay(500);

    for (todos = 0; todos <= 255; todos++) {
        analogWrite(ledRojo, todos);
        analogWrite(ledVerde, todos);
        analogWrite(ledAzul, todos);
        delay(10);
    }

    for (todos = 255; todos >= 0; todos--) {
        analogWrite(ledRojo, todos);
        analogWrite(ledVerde, todos);
        analogWrite(ledAzul, todos);
        delay(10);
    }

    delay(2000);

    // R = 56, G = 29, B = 98 -->
    setLedRGB(56, 29, 98);
    delay(2000);

    // R = 224, G = 5, B = 227 -->
    setLedRGB(224, 5, 227);
    delay(2000);
    
}

void gradualUp (int led) {
    for (int i = 0; i <= 255; i++) {
        analogWrite(led, i);
        delay(10);
    }
}

void gradualDown(int led) {
    for (int i = 255; i >= 0; i--) {
        analogWrite(led, i);
        delay(10);
    }
}

void setLedRGB (int r, int g, int b) {
    analogWrite(ledRojo, r);
    analogWrite(ledVerde, g);
    analogWrite(ledAzul, b);
}
