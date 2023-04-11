# 1 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\motores\\motores.ino"
// Definición de variables
// Se definen como const ya que no van a variar
const int AIA = 3; //pin 3 connectado al pin A-IA
const int AIB = 11; //pin 11 connectado al pin A-IA
const int BIA = 9; //pin 9 connectado al pin A-IA
const int BIB = 10; //pin 10 connectado al pin A-IA
const int ledTest = 13;

void setup() {
 // Configuración de los pines como salidas
    pinMode(AIA, 0x1);
    pinMode(AIB, 0x1);
    pinMode(BIA, 0x1);
    pinMode(BIB, 0x1);
    pinMode(ledTest, 0x1);

    // Inicialización de los pines
    digitalWrite(AIA, 0x0);
    digitalWrite(AIB, 0x0);
    digitalWrite(BIA, 0x0);
    digitalWrite(BIB, 0x0);
    digitalWrite(ledTest, 0x0);

    // Saludo inicial (handshake)
    for (int i = 0; i < 3; i++) {
        digitalWrite(ledTest, 0x1);
        delay(500);
        digitalWrite(ledTest, 0x0);
        delay(500);
    }
}

void loop() {
 parpadeo(1);
    adelante();
    delay(1500);
    parar();

    parpadeo(2);
    atras();
    delay(1500);
    parar();

    parpadeo(3);
    derecha();
    delay(1000);
    parar();

    parpadeo(4);
    izquierda();
    delay(1000);
    parar();
}

// Función para hacer parpader el ledTest
void parpadeo (int n) {
    for (int j = 0; j < n; j++) {
        digitalWrite(ledTest, 0x1);
        delay(200);
        digitalWrite(ledTest, 0x0);
        delay(200);
    }
};

/* 

    Colocamos en alto los IA y en bajo los IB de los dos motores

    Esto produce el movimiento hacia "adelante"

*/
# 69 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\motores\\motores.ino"
void adelante () {
    digitalWrite(AIA, 0x1);
    digitalWrite(AIB, 0x0);
    digitalWrite(BIA, 0x1);
    digitalWrite(BIB, 0x0);
};

/*

    Colocamos en alto los IB y en bajo los IA de los dos motores

    Esto produce el movimiento hacia "atrás"

*/
# 80 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\motores\\motores.ino"
void atras () {
    digitalWrite(AIA, 0x0);
    digitalWrite(AIB, 0x1);
    digitalWrite(BIA, 0x0);
    digitalWrite(BIB, 0x1);
};

/*

    Combinamos adelante y atras, para hacer que las ruedas giren invertidas

    AIA y BIB en LOW + AIB y BIA en HIGH = Girar a la izquierda

*/
# 91 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\motores\\motores.ino"
void izquierda () {
    digitalWrite(AIA, 0x0);
    digitalWrite(AIB, 0x1);
    digitalWrite(BIA, 0x1);
    digitalWrite(BIB, 0x0);
};

/*

    Combinamos adelante y atras, para hacer que las ruedas giren invertidas

    AIA y BIB en HIGH + AIB y BIA en LOW = Girar a la derecha

*/
# 102 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\motores\\motores.ino"
void derecha () {
    digitalWrite(AIA, 0x1);
    digitalWrite(AIB, 0x0);
    digitalWrite(BIA, 0x0);
    digitalWrite(BIB, 0x1);
};

/*

    Colocamos los dos valores en alto y por corto circuito frena.

*/
# 112 "C:\\Users\\ranuc\\Desktop\\BOTS\\Bots - REPO\\U2\\motores\\motores.ino"
void parar () {
    digitalWrite(AIA, 0x1);
    digitalWrite(AIB, 0x1);
    digitalWrite(BIA, 0x1);
    digitalWrite(BIB, 0x1);
    delay(500);
};
