# README - LED com Sensor de Som (Interruptor por Palmas)

## Descrição e Funcionamento
Este projeto utiliza um módulo sensor de som com saída digital para criar um sistema de controle de iluminação acionado por picos de ruído (como uma palma ou estalo). O sensor de som possui um microfone acoplado a um circuito comparador (geralmente com um potenciômetro de ajuste de sensibilidade). Quando o ruído ultrapassa o limite configurado, a saída digital muda de estado.

Ao captar a transição do sinal acústico, o microcontrolador inverte o estado salvo do LED. Devido à natureza do som no ambiente físico (ecos, reverbação e a própria oscilação contínua de uma palma), o sensor enviará dezenas de pulsos rápidos para uma única palma. Para contornar este problema sem complexidade excessiva de código, o programa aplica um **bloqueio intencional de longa duração** (`delay(10000)`). Isto "congela" a leitura do sensor por 10 segundos logo após o primeiro pico válido, garantindo estabilidade e evitando oscilações indesejadas (efeito estroboscópico) no LED.

## Mapeamento de Pinos
* **SOM_DIGITAL**: Pino Digital 2 (Entrada)
* **LED**: Pino Digital 13 (Saída)

## Conceitos Utilizados
* **Tratamento de Sinais de Alta Flutuação**: Uso de temporizações estendidas para isolar o sistema contra trens de pulso gerados por ruídos acústicos contínuos.
* **Ajuste de Threshold por Hardware**: Dependência do ajuste físico no potenciômetro do módulo sensor para calibração fina do ponto de disparo lógico.
* **Retenção de Estado**: Armazenamento em variável booleana para alternar o comportamento da saída a cada novo ciclo de detecção.

## Funções Utilizadas
* `digitalRead(pino)`: Amostra o estado lógico instantâneo fornecido pela placa do microfone.
* `digitalWrite(pino, valor)`: Altera o estado do LED baseado no cálculo de inversão.
* `delay(tempo)`: Suspende completamente a execução do processador por 10.000 milissegundos para neutralizar reverberações e ruídos residuais pós-disparo.
