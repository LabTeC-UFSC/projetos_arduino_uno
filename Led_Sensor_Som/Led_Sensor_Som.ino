#define SOM_DIGITAL 2
#define LED 13

bool estadoLed = false;       // Guarda o estado do led
bool ultimoSom  = LOW; // O botão com INPUT_PULLUP começa em LOW
unsigned long ultimoToque = 0;
const unsigned long cooldown = 300;

void setup() {
  pinMode(SOM_DIGITAL, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  bool som = digitalRead(SOM_DIGITAL);
  if (som == HIGH && ultimoSom == LOW && (millis() - ultimoToque) > cooldown) {
    estadoLed = !estadoLed;
    digitalWrite(LED, estadoLed);
    ultimoToque = millis();
  }
  ultimoSom = som;  // guarda a leitura do SOM, não do LED
}