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
    pinMode(ledRojo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAzul, OUTPUT);
    pinMode(ledTest, OUTPUT);
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    // Inicializar salidas
    digitalWrite(trigger, LOW);
    analogWrite(ledRojo, 0);
    analogWrite(ledVerde, 0);
    analogWrite(ledAzul, 0);

	// Saludo inicial (handshake)
    for (int i = 0; i < 3; i++) {
        digitalWrite(ledTest, HIGH);
        delay(500);
        digitalWrite(ledTest, LOW);
        delay(500);
    }
}

// Bucle infinito
void loop() {
	// Disparo de la señal de ultrasonido
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    // Medicion del tiempo
    pulseTime = pulseIn(echo, HIGH);

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
        totalValue = constrain(pulseTime, 1140,5700);
        intensity = map(totalValue, 1140, 5700, 0, 255);
        analogWrite(ledRojo, intensity);
        analogWrite(ledVerde, intensity);
        analogWrite(ledAzul, intensity);
    }
}
