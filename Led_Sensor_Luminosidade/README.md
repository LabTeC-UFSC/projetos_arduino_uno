# README - Luz Automática com Sensor de Luminosidade (LDR)

## Descrição e Funcionamento
Este projeto implementa um sistema de **iluminação automática**: o LED acende sozinho quando o ambiente fica escuro e apaga quando há luz suficiente. A leitura é feita por um módulo LDR (*Light Dependent Resistor*) ligado a um pino analógico, que devolve um valor inteiro entre 0 e 1023 proporcional à quantidade de luz incidente.

A decisão "claro ou escuro" é feita comparando essa leitura contra um **limiar** definido em código (variável `limiteLuz`). Como a sensibilidade do LDR varia conforme o ambiente, o circuito eletrônico do módulo e até a posição do trimpot, o valor adequado do limiar **não pode ser fixado teoricamente** — ele precisa ser descoberto na prática. Por isso, o código imprime continuamente a leitura no Monitor Serial: o usuário cobre o sensor com a mão, observa o número, descobre o valor de transição entre "claro" e "escuro" e ajusta o limiar de acordo.

## Mapeamento de Pinos
* **LDR**: Pino Analógico A0 (Entrada)
* **LED**: Pino Digital 13 (Saída — observe que este pino também aciona o LED embutido na placa)

## Conceitos Utilizados
* **Conversão Analógico-Digital (ADC)**: O microcontrolador converte a tensão variável de saída do LDR (entre 0 V e 5 V) em um número inteiro de 10 bits (0 a 1023), permitindo o tratamento digital de um sinal contínuo.
* **Limiar de Decisão (*Threshold*)**: Valor de referência usado para classificar a leitura analógica em uma decisão binária (acender ou apagar). Define a fronteira entre os estados "claro" e "escuro".
* **Calibração Empírica via Monitor Serial**: Estratégia de ajuste em que os dados brutos lidos pelo sensor são exibidos em tempo real no computador, permitindo ao desenvolvedor descobrir experimentalmente o valor ideal do limiar para o ambiente em que o sistema vai operar.
* **Lógica Condicional Binária**: Estrutura `if/else` que mapeia uma faixa contínua de leituras em duas ações mutuamente exclusivas (LED ligado ou desligado).

## Funções Utilizadas
* `analogRead(pino)`: Realiza a conversão analógico-digital, retornando um inteiro de 0 a 1023 que representa a tensão lida no pino especificado.
* `digitalWrite(pino, valor)`: Define o nível lógico (`HIGH` ou `LOW`) do pino de saída que aciona o LED.
* `Serial.begin(velocidade)`: Inicializa a comunicação serial entre a placa e o computador, configurada por padrão em `9600 baud`.
* `Serial.print()` e `Serial.println()`: Enviam os dados de leitura para o Monitor Serial; o `println` adiciona uma quebra de linha ao final de cada amostra, facilitando a leitura sequencial dos valores.
* `delay(tempo)`: Insere uma pausa de 200 ms entre as amostragens, evitando que a tela do Monitor Serial seja preenchida com leituras numa velocidade ilegível.

## Procedimento de Calibração
1. Faça o upload do código e abra o Monitor Serial (`Ctrl + Shift + M`), garantindo que a velocidade selecionada seja `9600 baud`.
2. Observe os valores impressos com o sensor sob luz ambiente normal.
3. Cubra o LDR com a mão (ou apague a luz) e anote a faixa de valores correspondente ao estado "escuro".
4. Defina um valor para `limiteLuz` que fique **entre** as duas faixas observadas (claro e escuro) e faça o upload novamente.
