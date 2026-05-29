// =====================================================================
// PROJETO: LUZ AUTOMÁTICA COM SENSOR DE LUMINOSIDADE (LDR)
// =====================================================================

#define PINO_LDR A0    // O sensor de luz DEVE ser ligado em um pino analógico
#define PINO_LED 13    // O LED que vai acender no escuro

// Essa é a variável mais importante do código! 
// Ela define a "linha de corte" entre o claro e o escuro.
// Você precisará ajustar esse número baseando-se no Monitor Serial.
int limiteLuz = 300; 

void setup() {
  pinMode(PINO_LED, OUTPUT);
  
  // Pinos analógicos não precisam obrigatoriamente do pinMode, 
  // mas colocar aqui ajuda a lembrar quem é ENTRADA e quem é SAÍDA.
  pinMode(PINO_LDR, INPUT);
  
  // Inicia a comunicação com o computador para vermos os números
  Serial.begin(9600);
}

void loop() {
  // 1. LER O SENSOR
  // O LDR vai retornar um valor entre 0 e 1023
  int leituraLuz = analogRead(PINO_LDR);

  // 2. MOSTRAR NO MONITOR SERIAL (Para Calibragem)
  Serial.print("Nivel de luz atual: ");
  Serial.println(leituraLuz);

  // 3. A LÓGICA DE DECISÃO
  // Se a luz medida for MENOR que o nosso limite, significa que escureceu
  if (leituraLuz < limiteLuz) {
    digitalWrite(PINO_LED, HIGH); // Acende a luz
  } 
  else {
    digitalWrite(PINO_LED, LOW);  // Apaga a luz
  }

  // Uma pequena pausa para os números não passarem voando na tela
  delay(200); 
}