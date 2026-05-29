#define VRx A0 
#define VRy A1
#define SW 8
#define LED_VERMELHO 11
#define LED_VERDE 10
#define LED_AZUL 9


bool estadoAzul = false;       // Guarda se o LED azul está ligado ou desligado
bool ultimoEstadoBotao = HIGH; // O botão com INPUT_PULLUP começa em HIGH

void setup() {
  pinMode(SW, INPUT_PULLUP);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

}

void loop() {
  analogWrite(LED_VERMELHO, map(analogRead(VRx), 0, 1023, 0, 255));
  analogWrite(LED_VERDE,    map(analogRead(VRy), 0, 1023, 0, 255));
  
  bool estadoBotao = digitalRead(SW);
  
  // Verifica se o botão foi pressionado (foi de HIGH para LOW)
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
  estadoAzul = !estadoAzul;
  }
  ultimoEstadoBotao = estadoBotao;


  digitalWrite(LED_AZUL, estadoAzul);

  delay(10);

}
