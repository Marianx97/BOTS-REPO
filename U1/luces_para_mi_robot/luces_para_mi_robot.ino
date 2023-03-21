// Definición de variables

int ledBlancoDerecha = 2;
int ledBlancoIzquierda = 4;
int ledRojoDerecha = 7;
int ledRojoIzquierda = 8;
int ledTest = 13;

// Inicialización de la placa
void setup() {
	// Iniciar pines

    pinMode(ledBlancoDerecha, OUTPUT);
    pinMode(ledBlancoIzquierda, OUTPUT);
    pinMode(ledRojoDerecha, OUTPUT);
    pinMode(ledRojoIzquierda, OUTPUT);
    pinMode(ledTest, OUTPUT);

    // Apagar los leds
    digitalWrite(ledBlancoDerecha, LOW);
    digitalWrite(ledBlancoIzquierda, LOW);
    digitalWrite(ledRojoDerecha, LOW);
    digitalWrite(ledRojoIzquierda, LOW);
    digitalWrite(ledTest, LOW);

    // Saludo inicial (handshake)
    digitalWrite(ledTest, HIGH);
    delay(500);
    digitalWrite(ledTest, LOW);
    delay(500);
    digitalWrite(ledTest, HIGH);
    delay(500);
    digitalWrite(ledTest, LOW);
    delay(500);
    digitalWrite(ledTest, HIGH);
    delay(500);
    digitalWrite(ledTest, LOW);
}

// Bucle infinito
void loop() {
	// Encender leds
    digitalWrite(ledBlancoDerecha, HIGH);
    digitalWrite(ledBlancoIzquierda, HIGH);
    digitalWrite(ledRojoDerecha, HIGH);
    digitalWrite(ledRojoIzquierda, HIGH);
    delay(1000);

    // Parpadear leds
    parpadeo(ledBlancoDerecha, 5, 500);
    parpadeo(ledBlancoIzquierda, 5, 500);
    parpadeo(ledRojoDerecha, 5, 500);
    parpadeo(ledRojoIzquierda, 5, 500);

    // Apagar leds
    digitalWrite(ledBlancoDerecha, LOW);
    digitalWrite(ledBlancoIzquierda, LOW);
    digitalWrite(ledRojoDerecha, LOW);
    digitalWrite(ledRojoIzquierda, LOW);
    delay(2000);
}

// Función para parpadear un led
void parpadeo(int led, int cantidad, int tiempo) {
    for (int i = 0; i < cantidad; i++) {
        digitalWrite(led, LOW);
        delay(tiempo);
        digitalWrite(led, HIGH);
        delay(tiempo);
    }
};
