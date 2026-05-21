# README - LED com Botão (Detecção de Borda e Debounce)

## Descrição e Funcionamento
Este sistema implementa o acionamento inteligente de um LED utilizando um botão de pressão (push-button). Em aplicações simples, um LED fica aceso apenas enquanto o botão está pressionado. Este projeto, contudo, aplica conceitos avançados de firmware para transformar o botão num interruptor do tipo *toggle* (retentivo): cada clique inverte o estado atual do LED (se estava apagado, acende; se estava aceso, apaga) e mantém esse estado.

Para garantir que o circuito funcione de forma confiável na prática, o código implementa uma lógica de **Debounce por Software** utilizando a contagem de tempo do processador. Isso evita o efeito "repique" (múltiplos acionamentos falsos causados pelo contato mecânico das lâminas internas do botão). O código também avalia a **Borda de Subida** (transição de solto para pressionado) para efetuar a ação apenas uma vez por clique.

## Mapeamento de Pinos
* **BOTAO**: Pino Digital 13 (Entrada com Pull-up Interno)
* **LED**: Pino Digital 12 (Saída)

## Conceitos Utilizados
* **Debounce por Software**: Técnica que filtra ruídos elétricos gerados no momento do impacto mecânico do botão, ignorando variações que ocorram num intervalo menor que 50 milissegundos.
* **Detecção de Borda (Edge Detection)**: Técnica de programação que monitora a transição de estado de uma variável (neste caso, de `falso` para `verdadeiro` após a inversão lógica da leitura física), garantindo que o comando seja executado apenas no instante exato do clique.
* **Temporização Não-Bloqueante**: Uso do contador interno do sistema para validar intervalos de tempo sem interromper o fluxo completo do laço de repetição (`loop`).

## Funções Utilizadas
* `millis()`: Retorna o número de milissegundos decorridos desde que a placa começou a executar o programa corrente, ideal para cronometrar eventos sem travar a CPU.
* `digitalRead(pino)`: Lê o nível lógico do botão.
* `digitalWrite(pino, valor)`: Atualiza o estado físico do LED com base no valor booleano salvo na memória.
