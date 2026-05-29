<<<<<<< HEAD
=======
/*
OBS: como é um sensor de som se houver muito barulho será improvavel que você note um diferença muito grande entre isso e ligar o led direto no vcc
     por isso coloquei 10000ms  

*/

>>>>>>> a8869b89179c4765de72e356f88f55ca347a7135
#define SOM_DIGITAL 2
#define LED 13

bool estadoLed = false;       // Guarda o estado do led
<<<<<<< HEAD
bool ultimoSom  = LOW; // O botão com INPUT_PULLUP começa em LOW
unsigned long ultimoToque = 0;
const unsigned long cooldown = 300;
=======
bool ultimoEstado = LOW; // O botão com INPUT_PULLUP começa em LOW

>>>>>>> a8869b89179c4765de72e356f88f55ca347a7135

void setup() {
  pinMode(SOM_DIGITAL, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  bool som = digitalRead(SOM_DIGITAL);
<<<<<<< HEAD
  if (som == HIGH && ultimoSom == LOW && (millis() - ultimoToque) > cooldown) {
    estadoLed = !estadoLed;
    digitalWrite(LED, estadoLed);
    ultimoToque = millis();
  }
  ultimoSom = som;  // guarda a leitura do SOM, não do LED
}
=======

  if(som != ultimoEstado){
    estadoLed = !estadoLed;
    delay(10000); // "congela" o processador por 10000ms 
  }

  digitalWrite(LED, estadoLed); 

  ultimoEstado = estadoLed;

}
>>>>>>> a8869b89179c4765de72e356f88f55ca347a7135
