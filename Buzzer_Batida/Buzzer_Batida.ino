#define BUZZER 13
#define SENSOR 8

void setup() {
  pinMode(BUZZER, OUTPUT);
  
  // O INPUT_PULLUP garante que o pino fique em HIGH sempre que o sensor estiver desligado.
  // Assim ele não capta "ruídos" do ambiente.
  pinMode(SENSOR, INPUT_PULLUP);
}

// Função para criar a onda sonora manualmente
void tocarNota(int atrasoMicro, int duracaoMili) {
  long tempoTotal = (long)duracaoMili * 1000;
  long ciclos = tempoTotal / (atrasoMicro * 2);
  
  for (long i = 0; i < ciclos; i++) {
    digitalWrite(BUZZER, HIGH);
    delayMicroseconds(atrasoMicro);
    digitalWrite(BUZZER, LOW);
    delayMicroseconds(atrasoMicro);
  }
  
  delay(50); 
}

void loop() {
  // Como o sensor está ligado ao GND, verificar se ele foi ativado 
  // significa verificar se a leitura é LOW.
  if (digitalRead(SENSOR) == LOW) {

    int notaSol = 1275;      // G4 (~392 Hz)
    int notaMiBemol = 1607;  // Eb4 (~311 Hz)
    int notaSiBemol = 1072;  // Bb4 (~466 Hz)

    // Dun, dun, dun... 
    tocarNota(notaSol, 500); 
    tocarNota(notaSol, 500); 
    tocarNota(notaSol, 500); 
    
    // ...da-da, dun... 
    tocarNota(notaMiBemol, 350); 
    tocarNota(notaSiBemol, 150); 
    tocarNota(notaSol, 500);     
    
    // ...da-da, duuuuuuuun.
    tocarNota(notaMiBemol, 350); 
    tocarNota(notaSiBemol, 150); 
    tocarNota(notaSol, 1000);    

    // Aguarda 3 segundos antes de permitir que o sensor dispare a música novamente
    delay(3000); 
  }
}