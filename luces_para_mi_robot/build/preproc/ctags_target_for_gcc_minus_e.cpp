# 1 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\luces_para_mi_robot\\luces_para_mi_robot.ino"
// Definición de variables

int ledBlancoDerecha = 2;
int ledBlancoIzquierda = 4;
int ledRojoDerecha = 7;
int ledRojoIzquierda = 8;
int ledTest = 13;

// Inicialización de la placa
void setup() {
 // Iniciar pines

    pinMode(ledBlancoDerecha, 0x1);
    pinMode(ledBlancoIzquierda, 0x1);
    pinMode(ledRojoDerecha, 0x1);
    pinMode(ledRojoIzquierda, 0x1);
    pinMode(ledTest, 0x1);

    // Apagar los leds
    digitalWrite(ledBlancoDerecha, 0x0);
    digitalWrite(ledBlancoIzquierda, 0x0);
    digitalWrite(ledRojoDerecha, 0x0);
    digitalWrite(ledRojoIzquierda, 0x0);
    digitalWrite(ledTest, 0x0);

    // Saludo inicial (handshake)
    digitalWrite(ledTest, 0x1);
    delay(500);
    digitalWrite(ledTest, 0x0);
    delay(500);
    digitalWrite(ledTest, 0x1);
    delay(500);
    digitalWrite(ledTest, 0x0);
    delay(500);
    digitalWrite(ledTest, 0x1);
    delay(500);
    digitalWrite(ledTest, 0x0);
}

// Bucle infinito
void loop() {
 // Encender leds
    digitalWrite(ledBlancoDerecha, 0x1);
    digitalWrite(ledBlancoIzquierda, 0x1);
    digitalWrite(ledRojoDerecha, 0x1);
    digitalWrite(ledRojoIzquierda, 0x1);
    delay(1000);

    // Parpadear leds
    parpadeo(ledBlancoDerecha, 5, 500);
    parpadeo(ledBlancoIzquierda, 5, 500);
    parpadeo(ledRojoDerecha, 5, 500);
    parpadeo(ledRojoIzquierda, 5, 500);

    // Apagar leds
    digitalWrite(ledBlancoDerecha, 0x0);
    digitalWrite(ledBlancoIzquierda, 0x0);
    digitalWrite(ledRojoDerecha, 0x0);
    digitalWrite(ledRojoIzquierda, 0x0);
    delay(2000);
}

// Función para parpadear un led
void parpadeo(int led, int cantidad, int tiempo) {
    for (int i = 0; i < cantidad; i++) {
        digitalWrite(led, 0x0);
        delay(tiempo);
        digitalWrite(led, 0x1);
        delay(tiempo);
    }
};
