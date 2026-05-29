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
  analogWrite(LED_VERMELHO, analogRead(VRx));
  analogWrite(LED_VERDE, analogRead(VRy));
  
  bool estadoBotao = digitalRead(SW);
  
  // Verifica se o botão foi pressionado (foi de HIGH para LOW)
  if(estadoBotao != ultimoEstadoBotao){
    estadoAzul = !estadoAzul;
    delay(50); // "congela" o processador por 50ms 
  }

  if(estadoAzul){
    digitalWrite(LED_AZUL, HIGH);
  }
  else{
    digitalWrite(LED_AZUL, LOW);
  }

}
