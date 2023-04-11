// Definición de variables
// Se definen como const ya que no van a variar
const int AIA = 3;      //pin 3 connectado al pin A-IA
const int AIB = 11;     //pin 11 connectado al pin A-IA
const int BIA = 9;      //pin 9 connectado al pin A-IA
const int BIB = 10;     //pin 10 connectado al pin A-IA
const int ledTest = 13;

void setup() {
	// Configuración de los pines como salidas
    pinMode(AIA, OUTPUT);
    pinMode(AIB, OUTPUT);
    pinMode(BIA, OUTPUT);
    pinMode(BIB, OUTPUT);
    pinMode(ledTest, OUTPUT);

    // Inicialización de los pines
    digitalWrite(AIA, LOW);
    digitalWrite(AIB, LOW);
    digitalWrite(BIA, LOW);
    digitalWrite(BIB, LOW);
    digitalWrite(ledTest, LOW);

    // Saludo inicial (handshake)
    for (int i = 0; i < 3; i++) {
        digitalWrite(ledTest, HIGH);
        delay(500);
        digitalWrite(ledTest, LOW);
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
        digitalWrite(ledTest, HIGH);
        delay(200);
        digitalWrite(ledTest, LOW);
        delay(200);
    }
};

/* 
    Colocamos en alto los IA y en bajo los IB de los dos motores
    Esto produce el movimiento hacia "adelante"
*/
void adelante () {
    digitalWrite(AIA, HIGH);
    digitalWrite(AIB, LOW);
    digitalWrite(BIA, HIGH);
    digitalWrite(BIB, LOW);
};

/*
    Colocamos en alto los IB y en bajo los IA de los dos motores
    Esto produce el movimiento hacia "atrás"
*/
void atras () {
    digitalWrite(AIA, LOW);
    digitalWrite(AIB, HIGH);
    digitalWrite(BIA, LOW);
    digitalWrite(BIB, HIGH);
};

/*
    Combinamos adelante y atras, para hacer que las ruedas giren invertidas
    AIA y BIB en LOW + AIB y BIA en HIGH = Girar a la izquierda
*/
void izquierda () {
    digitalWrite(AIA, LOW);
    digitalWrite(AIB, HIGH);
    digitalWrite(BIA, HIGH);
    digitalWrite(BIB, LOW);
};

/*
    Combinamos adelante y atras, para hacer que las ruedas giren invertidas
    AIA y BIB en HIGH + AIB y BIA en LOW = Girar a la derecha
*/
void derecha () {
    digitalWrite(AIA, HIGH);
    digitalWrite(AIB, LOW);
    digitalWrite(BIA, LOW);
    digitalWrite(BIB, HIGH);
};

/*
    Colocamos los dos valores en alto y por corto circuito frena.
*/
void parar () {
    digitalWrite(AIA, HIGH);
    digitalWrite(AIB, HIGH);
    digitalWrite(BIA, HIGH);
    digitalWrite(BIB, HIGH);
    delay(500);
};

/*
    Para girar ya sea a izquierda o derecha, se puede controlar la "suavidad"
    del giro utilizando analogWrite en lugar de digitalWrite y dandole valores
    diferentes de potencia a los pines del motor.

    Por ejemplo:

    void derecha() {
        analogWrite(AIA, 255);
        analogWrite(AIB, 0);
        analogWrite(BIA, 80);
        analogWrite(BIB, 0);
    }
    void izquierda() {
        analogWrite(AIA, 80);
        analogWrite(AIB, 0);
        analogWrite(BIA, 255);
        analogWrite(BIB, 0);
    }
*/
