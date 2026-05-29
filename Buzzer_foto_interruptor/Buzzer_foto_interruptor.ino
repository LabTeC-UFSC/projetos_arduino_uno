#define BUZZER 8
#define SENSOR 2 // Pino onde o sensor foto-interruptor está ligado

// Frequências das notas (Intro de Enter Sandman)
#define NOTE_E4  330
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_E5  659
#define NOTE_G5  784
#define REST     0

// A melodia
int melodia[] = {
  NOTE_E4, REST, // Booooom inicial
  
  // Riff Principal (4 repetições)
  NOTE_E4, NOTE_E5, NOTE_G5, NOTE_AS4, NOTE_A4, REST,
  NOTE_E4, NOTE_E5, NOTE_G5, NOTE_AS4, NOTE_A4, REST,
  NOTE_E4, NOTE_E5, NOTE_G5, NOTE_AS4, NOTE_A4, REST,
  NOTE_E4, NOTE_E5, NOTE_G5, NOTE_AS4, NOTE_A4, REST
};

// Duração de cada nota
int duracoes[] = {
  1600, 400, // Duração da nota inicial
  
  400, 400, 200, 400, 400, 200, 
  400, 400, 200, 400, 400, 200, 
  400, 400, 200, 400, 400, 200, 
  400, 400, 200, 400, 400, 200  
};

int totalNotas = sizeof(melodia) / sizeof(melodia[0]);

void setup() {
  pinMode(BUZZER, OUTPUT);
  
  // Habilita o resistor interno (como no seu código que já estava funcionando)
  pinMode(SENSOR, INPUT_PULLUP); 
}

void tocarMetallica() {
  for (int i = 0; i < totalNotas; i++) {
    if (melodia[i] == REST) {
      noTone(BUZZER);
      delay(duracoes[i]);
    } else {
      tone(BUZZER, melodia[i], duracoes[i]);
      // O multiplicador 1.30 cria a pausa percussiva ideal para rock
      delay(duracoes[i] * 1.30); 
    }
    noTone(BUZZER); 
  }
}

void loop() {
  // Lê o sensor. Mude de LOW para HIGH se o seu módulo funcionar invertido!
  if (digitalRead(SENSOR) == HIGH) { 
    
    // Alguém passou pelo sensor! Dispara o riff.
    tocarMetallica();
    
    // Espera 2 segundos após a música acabar para evitar 
    // que dispare duas vezes seguidas sem querer.
    delay(2000); 
  }
}