# 1 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\ultrasonido_uso\\ultrasonido_uso.ino"
// Definición de variables
int trigger = 4;
int echo = 2;
int ledTest = 13;
int ledRojo = 11;
int ledVerde = 10;
int ledAzul = 9;
int intensity = 0;
long pulseTime;
long totalValue;

// Inicialización
void setup() {
    // Iniciar pines
    pinMode(ledRojo, 0x1);
    pinMode(ledVerde, 0x1);
    pinMode(ledAzul, 0x1);
    pinMode(ledTest, 0x1);
    pinMode(trigger, 0x1);
    pinMode(echo, 0x0);

    // Inicializar salidas
    digitalWrite(trigger, 0x0);
    analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 0);
    analogWrite(ledAzul, 0);

 // Saludo inicial (handshake)
    for (int i = 0; i < 3; i++) {
        digitalWrite(ledTest, 0x1);
        delay(500);
        digitalWrite(ledTest, 0x0);
        delay(500);
    }
}

// Bucle infinito
void loop() {
 // Disparo de la señal de ultrasonido
    digitalWrite(trigger, 0x1);
    delayMicroseconds(10);
    digitalWrite(trigger, 0x0);

    // Medicion del tiempo
    pulseTime = pulseIn(echo, 0x1);

    if (pulseTime < 550) {
        // Luz ROJA
        analogWrite(ledRojo, 255);
        analogWrite(ledVerde, 0);
        analogWrite(ledAzul, 0);
    } else if (pulseTime >= 550 && pulseTime < 860) {
        // Luz AMARILLA
        analogWrite(ledRojo, 255);
        analogWrite(ledVerde, 255);
        analogWrite(ledAzul, 0);
    } else if (pulseTime >= 860 && pulseTime < 1140) {
        // Luz VERDE
        analogWrite(ledRojo, 0);
        analogWrite(ledVerde, 255);
        analogWrite(ledAzul, 0);
    } else {
        totalValue = ((pulseTime)<(1140)?(1140):((pulseTime)>(5700)?(5700):(pulseTime)));
        intensity = map(totalValue, 1140, 5700, 0, 255);
        analogWrite(ledRojo, intensity);
        analogWrite(ledVerde, intensity);
        analogWrite(ledAzul, intensity);
    }
}
