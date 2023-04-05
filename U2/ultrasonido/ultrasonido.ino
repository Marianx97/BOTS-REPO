// Definición de variables
int trigger = 2;
int echo = 4;
int ledTest = 13;
long pulseTime;
float distance;

// Inicialización de la placa
void setup() {
    // Iniciar transmisión serie
    Serial.begin(9600); // baudrate: 9600

	// Iniciar pines
    pinMode(ledTest, OUTPUT);
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    digitalWrite(trigger, LOW);
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
void loop() {
    // Disparo de la señal de ultrasonido
	digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    // Medicion del tiempo
    pulseTime = pulseIn(echo, HIGH);

    // Calculo de la distancia
    distance = 0.0340 / 2 * pulseTime;

    // Transmitimos serialmente la información
    Serial.println("Tiempo/Distancia");
    Serial.print(pulseTime);
    Serial.print("/");
    Serial.print(distance);
    Serial.println("");

    delay(1000);
}
