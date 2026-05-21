# README - Buzzer Batida (Beethoven's 5th Symphony)

## Descrição e Funcionamento
Este projeto utiliza um sensor digital para disparar uma melodia rítmica clássica (o famoso "Dun, dun, dun... da-da, dun" da 5ª Sinfonia de Beethoven) através de um buzzer piezoelétrico. O circuito baseia-se numa leitura de entrada configurada com o resistor de pull-up interno do microcontrolador, o que garante estabilidade no sinal elétrico e evita a captação de ruídos mecânicos ou eletromagnéticos do ambiente. 

Quando o sensor é ativado (sinal vai para nível lógico BAIXO, pois está conectado ao GND), o microcontrolador executa uma função customizada para gerar as ondas sonoras manualmente, alternando o estado do pino do buzzer entre ligado e desligado com tempos controlados em microssegundos. Após tocar a melodia, o programa introduz uma pausa de 3 segundos como uma proteção (debounce de longa duração) para evitar reacionamentos acidentais consecutivos.

## Mapeamento de Pinos
* **BUZZER**: Pino Digital 13 (Saída)
* **SENSOR**: Pino Digital 8 (Entrada com Pull-up Interno)

## Conceitos Utilizados
* **Resistores de Pull-up Internos (`INPUT_PULLUP`)**: Garante que o pino de leitura permaneça em nível lógico ALTO (5V ou 3.3V) por padrão quando o sensor estiver aberto/desativado, eliminando flutuações de ruído.
* **Geração Manual de Onda Quadrada**: Criação de tons de áudio definindo manualmente o período da onda. A frequência é inversamente proporcional ao dobro do tempo de atraso em microssegundos.
* **Atrasos Temporizados Bloqueantes**: Utilização de `delay()` e `delayMicroseconds()` para controlar o andamento rítmico das notas e a frequência fundamental do som.

## Funções Utilizadas
* `pinMode(pino, modo)`: Configura o comportamento dos pinos como entrada com pull-up ou saída.
* `digitalRead(pino)`: Lê o estado digital atual do sensor.
* `digitalWrite(pino, valor)`: Altera o estado do pino do buzzer entre `HIGH` e `LOW`.
* `delayMicroseconds(tempo)`: Fornece o atraso de curtíssima duração necessário para moldar a frequência da nota musical.
* `delay(tempo)`: Executa pausas rítmicas entre notas e o tempo de espera pós-execução do sistema.
