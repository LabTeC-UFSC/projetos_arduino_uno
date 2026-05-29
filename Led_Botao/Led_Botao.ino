#define BOTAO 13
#define LED   12

bool estadoLed = false;       // estado atual do LED (lembrado entre loops)
bool ultimoBotao = false;     // leitura anterior do botão
unsigned long ultimoDebounce = 0;
const unsigned long debounceMs = 50;

/*
  O setup roda apenas uma vez, na inicialização da placa.
  Então você deve colocar nele aquilo que so precisa ser setado uma vez
  Mas como fica em um bloco de código diferente você não pode acessar uma variavel declarada aqui no loop
*/
void setup() {
  //define o modo do pino, a entrada é o pino e depois o modo (entrada, saida)
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

}

// millis retorna o número de milissegundos desde a inicialização da placa

void loop() {

  bool botao = !digitalRead(BOTAO);  // true = apertado

  // só considera mudança se passou o tempo de debounce
  if (botao != ultimoBotao && (millis() - ultimoDebounce) > debounceMs) {
    ultimoDebounce = millis();

    // detecta a BORDA de subida (acabou de apertar)
    if (botao) {
      estadoLed = !estadoLed;       // inverte o estado
      digitalWrite(LED, estadoLed);
    }

    ultimoBotao = botao;
  }
}