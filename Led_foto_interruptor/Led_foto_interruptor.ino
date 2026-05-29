// =====================================================================
// PROJETO: LED ALTERNADO COM FOTO-INTERRUPTOR
// Cada vez que algo passa pela fenda do sensor, o LED muda de estado:
// estava apagado -> acende; estava aceso -> apaga.
// =====================================================================

// 1. Pinos
#define SENSOR 2     // pino de sinal do foto-interruptor
#define LED    12    // LED que vai ser controlado

// 2. Variáveis que guardam o estado entre as repetições do loop
bool estadoLed    = false;   // o LED começa apagado
bool ultimoEstado = HIGH;    // sem nada na fenda, o sensor costuma ler HIGH

/* =====================================================================
   COMO FUNCIONA
   O foto-interruptor tem um LED infravermelho de um lado da fenda e
   um receptor do outro. Quando algo entra na fenda e BLOQUEIA a luz,
   a saída do sensor muda de HIGH para LOW (na maioria dos módulos).

   Não basta fazer "se sensor == LOW, alterna" — enquanto o objeto
   estiver parado dentro da fenda, o loop rodaria milhares de vezes
   por segundo e o LED ficaria piscando sem parar.

   Por isso detectamos só o INSTANTE em que a leitura muda (a "borda"):
   agimos uma única vez, quando o objeto acaba de entrar no sensor.
   ===================================================================== */

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(LED,    OUTPUT);
}

void loop() {
  bool leitura = digitalRead(SENSOR);

  // Detecta a borda de descida: o sensor acabou de ir de HIGH para LOW
  // (ou seja, algo ACABOU de entrar na fenda)
  if (leitura == LOW && ultimoEstado == HIGH) {
    estadoLed = !estadoLed;            // inverte: ligado <-> desligado
    digitalWrite(LED, estadoLed);
  }

  ultimoEstado = leitura;   // guarda a leitura para a próxima volta do loop

  delay(10);   // pequena pausa para evitar ruídos de leitura
}

/* =====================================================================
   SE O LED AGIR AO CONTRÁRIO
   (acender quando você TIRA o objeto da fenda em vez de quando coloca)
   significa que o seu módulo é "ativo-alto" em vez de "ativo-baixo".
   Basta inverter no if:    if (leitura == HIGH && ultimoEstado == LOW)
   ===================================================================== */
