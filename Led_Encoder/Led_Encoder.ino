// =====================================================================
// PROJETO: SELETOR DE CORES DIGITAL
// Leia os comentários! Eles explicam como a mágica acontece.
// =====================================================================

// 1. Dando nomes aos pinos do Arduino para facilitar a leitura
#define LED_VERMELHO    11  
#define LED_VERDE       10 
#define LED_AZUL        9 
#define BOTAO_SW        7  // Pino onde ligamos o clique do botão

/* =====================================================================
   O QUE É O PINO CLK (ROTAÇÃO)?
   Dentro do botão giratório existe um disco cheio de "dentes" de metal.
   Enquanto você gira, o pino CLK fica raspando nesses dentes:
   - Se ele parar encostado num dente: Ele envia energia (1 / LIGADO).
   - Se ele parar no buraco vazio: Ele corta a energia (0 / DESLIGADO).
   
   Girar esse botão é como acender e apagar um interruptor bem rápido!
   ===================================================================== */
#define ROTACAO         6  // Ligue o pino CLK do Encoder aqui


// 2. Criando etiquetas para os números ficarem mais fáceis de ler
#define VERMELHO 1 
#define VERDE    2 
#define AZUL     3 

// 3. As "Caixas de Memória" (Variáveis) do Arduino
int escolhaCor = 1; // Começamos controlando a cor 1 (Vermelho)

// Estas caixas vão guardar apenas 0 (Apagado) ou 1 (Aceso) para cada cor
int vermelho_intensidade = 0;  
int verde_intensidade = 0; 
int azul_intensidade = 0; 


void setup() { 
  // OUTPUT: O Arduino vai ENVIAR energia para acender os LEDs
  pinMode(LED_VERMELHO, OUTPUT); 
  pinMode(LED_VERDE, OUTPUT); 
  pinMode(LED_AZUL, OUTPUT); 
  
  // INPUT_PULLUP: O Arduino vai LER a energia do botão. 
  // O "PULLUP" liga um resistor de proteção interno no Arduino.
  pinMode(BOTAO_SW, INPUT_PULLUP); 
  
  // INPUT: O Arduino vai LER o giro (0 ou 1) do botão
  pinMode(ROTACAO, INPUT); 
} 


void loop() { 
  
  // ===================================================================
  // PASSO 1: O BOTÃO (Descobrir qual cor o usuário quer mexer)
  // ===================================================================
  // Se o botão for apertado (Ele lê LOW / 0 quando apertado)
  if (digitalRead(BOTAO_SW) == LOW) {
    
    // Soma 1 na cor atual. Ex: Estava no 1(Vermelho), vai pro 2(Verde).
    escolhaCor = escolhaCor + 1;
    
    // Se passar do número 3 (Azul), mandamos voltar pro 1 (Vermelho)
    if (escolhaCor > 3) {
      escolhaCor = 1; 
    }
    
    // Uma pausa de 300 milissegundos. 
    // O Arduino é tão rápido que sem isso ele pularia as cores sem parar!
    delay(300); 
  }
  
  
  // ===================================================================
  // PASSO 2: O GIRO (Descobrir se o giro parou no LIGADO ou DESLIGADO)
  // ===================================================================
  // O comando digitalRead vai ler 1 (dente) ou 0 (buraco) do pino CLK
  int estadoRotacao = digitalRead(ROTACAO); 
  
  
  // ===================================================================
  // PASSO 3: A LÓGICA (Salvar o 0 ou 1 apenas na cor escolhida)
  // ===================================================================
  if(escolhaCor == VERMELHO){ 
    vermelho_intensidade = estadoRotacao; 
  } 
  if(escolhaCor == VERDE){ 
    verde_intensidade = estadoRotacao; 
  } 
  if(escolhaCor == AZUL){ 
    azul_intensidade = estadoRotacao; 
  } 


  // ===================================================================
  // PASSO 4: EXECUTAR (Mandar energia pros LEDs baseado na nossa lógica)
  // ===================================================================
  // Se a intensidade for 1, a luz acende. Se for 0, apaga.
  digitalWrite(LED_VERMELHO, vermelho_intensidade); 
  digitalWrite(LED_VERDE, verde_intensidade); 
  digitalWrite(LED_AZUL, azul_intensidade); 
  
}