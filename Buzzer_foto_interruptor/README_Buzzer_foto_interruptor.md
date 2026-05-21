# README - Buzzer com Foto-Interruptor (Enter Sandman)

## Descrição e Funcionamento
Este projeto demonstra o uso de um sensor foto-interruptor para disparar o famoso riff de introdução da música *Enter Sandman* da banda Metallica num buzzer. O sensor atua monitorando a interrupção de um feixe de luz infravermelha. Quando um objeto bloqueia a luz, o estado do pino muda, disparando a rotina musical no microcontrolador.

Diferente de métodos manuais de oscilação, este código adota uma abordagem mais abstrata e organizada, utilizando arrays paralelos para separar a estrutura das frequências das notas musicais da estrutura de suas respectivas durações rítmicas. Para conferir uma sonoridade de rock percussivo ideal, foi adicionado um multiplicador dinâmico de `1.30` sobre a duração original de cada nota, criando o intervalo de silêncio (pausa) perfeito entre os tons.

## Mapeamento de Pinos
* **BUZZER**: Pino Digital 8 (Saída)
* **SENSOR**: Pino Digital 2 (Entrada com Pull-up Interno)

## Estrutura da Melodia
O código define notas específicas com frequências pré-estabelecidas (E4, A4, AS4, E5, G5) e uma constante de repouso (`REST`). A melodia e o ritmo são controlados por:
* `melodia[]`: Vetor contendo a sequência exata de notas e pausas.
* `duracoes[]`: Vetor contendo o tempo em milissegundos que cada nota correspondente deve soar.

## Conceitos Utilizados
* **Arrays Paralelos**: Técnica de programação para correlacionar dois conjuntos de dados através do mesmo índice sequencial (uma nota e a sua duração correspondente).
* **Cálculo Dinâmico de Tamanho (`sizeof`)**: Determina automaticamente a quantidade de elementos de um array dividindo o tamanho total em bytes pelo tamanho de um único elemento, permitindo expandir ou alterar a música facilmente.
* **Pausas Articuladas**: Multiplicação do tempo de delay por um fator superior a 1 para garantir que a nota termine antes que a próxima comece, imitando o ataque de instrumentos reais.

## Funções Utilizadas
* `tone(pino, frequencia, duracao)`: Gera uma onda quadrada de frequência específica em um pino para emitir o som musical.
* `noTone(pino)`: Interrompe a geração de som no pino do buzzer, essencial para processar as notas de pausa (`REST`).
* `delay(tempo)`: Controla o tempo de sustentação e os intervalos mecânicos entre os ciclos.
