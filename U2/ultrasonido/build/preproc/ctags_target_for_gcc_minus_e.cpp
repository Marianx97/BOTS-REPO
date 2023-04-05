# 1 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\ultrasonido\\ultrasonido.ino"
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
    pinMode(ledTest, 0x1);
    pinMode(trigger, 0x1);
    pinMode(echo, 0x0);

    digitalWrite(trigger, 0x0);
    digitalWrite(ledTest, 0x0);

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
