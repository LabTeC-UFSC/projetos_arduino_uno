# README - LED Alternado com Foto-Interruptor

## Descrição e Funcionamento
Este projeto utiliza um sensor foto-interruptor para controlar o estado de um LED no estilo *toggle* (retentivo): cada vez que um objeto passa pela fenda do sensor, o LED inverte o seu estado atual — se estava apagado, acende; se estava aceso, apaga. O estado se mantém indefinidamente até a próxima passagem.

O foto-interruptor é composto por um LED infravermelho e um receptor montados frente a frente, com uma fenda no meio. Quando algo bloqueia o feixe, a saída do sensor muda de nível lógico. O grande cuidado de implementação está em **não reagir continuamente** enquanto o objeto permanecer dentro da fenda: como o laço `loop()` executa milhares de vezes por segundo, uma lógica ingênua faria o LED piscar descontroladamente durante todo o tempo de bloqueio. A solução é detectar apenas o **instante da transição** (a borda), agindo uma única vez no momento exato em que o objeto entra na fenda.

## Mapeamento de Pinos
* **SENSOR**: Pino Digital 2 (Entrada)
* **LED**: Pino Digital 12 (Saída)

## Conceitos Utilizados
* **Detecção de Borda (*Edge Detection*)**: Técnica de programação que monitora a transição do estado de leitura entre duas iterações consecutivas do laço, garantindo que a ação seja disparada uma única vez por evento físico — neste caso, na borda de descida (`HIGH` → `LOW`), correspondente ao instante em que o feixe infravermelho é interrompido.
* **Estado Retentivo via Variável Global**: O estado do LED é mantido em uma variável `bool` declarada fora das funções, preservando o valor entre as repetições do `loop()` e permitindo que o sistema "lembre" se a luz está acesa ou apagada.
* **Variável de Histórico (*Last State*)**: Armazenamento da última leitura do sensor para comparação na próxima iteração. Esta segunda variável é o que torna possível identificar uma transição em vez de apenas o estado atual.
* **Polaridade do Sensor (Ativo-Baixo vs. Ativo-Alto)**: Sensores foto-interruptores podem variar em sua lógica de saída conforme o módulo. O código adota a convenção ativo-baixo (saída `LOW` quando bloqueado), mas pode ser facilmente invertido caso o módulo utilizado tenha comportamento oposto.

## Funções Utilizadas
* `digitalRead(pino)`: Lê o nível lógico (`HIGH` ou `LOW`) do pino de saída do sensor a cada iteração do laço.
* `digitalWrite(pino, valor)`: Atualiza o estado físico do LED com base no valor booleano armazenado em memória.
* `delay(tempo)`: Insere uma pequena pausa de 10 ms ao final do laço para reduzir ruídos elétricos na leitura do sensor sem comprometer a responsividade.

## Ajuste para Módulos com Polaridade Invertida
Caso o LED reaja ao contrário do esperado — acendendo quando o objeto **sai** da fenda em vez de quando entra — o módulo em uso é ativo-alto. Basta inverter os níveis lógicos da condição de detecção de borda no `if`, trocando `LOW` por `HIGH` e vice-versa.
