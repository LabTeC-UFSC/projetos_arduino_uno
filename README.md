# 💻 Projetos com Arduino

Bem-vindo a esta coleção de projetos criados com Arduino. O repositório documenta ideias e testes práticos de hardware e software, funcionando como um arquivo vivo de desenvolvimento e prototipagem.

Cada projeto é independente e foi construído com foco em testar diferentes componentes, lógicas de controle e interações físicas. Os arquivos `.ino` estão organizados em pastas individuais com o mesmo nome do projeto.

## 📂 Índice de Projetos

* [**Buzzer_Batida**](./Buzzer_Batida)
    * [cite_start]*Um alarme musical que toca uma melodia usando frequências como G4 (~392 Hz), Eb4 (~311 Hz) e Bb4 (~466 Hz) em um buzzer no pino 13[cite: 1, 8, 9, 10]. [cite_start]O disparo é ativado quando o sensor ligado ao pino 8 envia um sinal LOW[cite: 1, 7].*

* [**Buzzer_foto_interruptor**](./Buzzer_foto_interruptor)
    * [cite_start]*Toca o riff da introdução de "Enter Sandman" quando um objeto passa pelo sensor foto-interruptor no pino 2[cite: 14, 24]. [cite_start]A lógica aplica um multiplicador de 1.30 na duração das notas para criar uma pausa percussiva ideal para o estilo rock[cite: 20].*

* [**Led_Botao**](./Led_Botao)
    * [cite_start]*Controle de um LED no pino 12 através de um botão no pino 13, detectando a borda de subida ao apertar[cite: 26, 32]. [cite_start]O código introduz o conceito de temporização não-bloqueante usando a função `millis()` para criar um debounce de 50ms[cite: 28, 31].*

* [**Led_Encoder**](./Led_Encoder)
    * [cite_start]*Um seletor de cores digital para um módulo LED RGB[cite: 34, 35]. [cite_start]Utiliza o clique do botão para alternar entre as cores vermelho, verde e azul, e a leitura do pino CLK (que raspa nos dentes de metal internos do botão giratório) para ligar ou desligar a luz[cite: 36, 37, 48].*

* [**Led_joystick**](./Led_joystick)
    * [cite_start]*Usa os eixos analógicos VRx e VRy de um joystick para dosar o brilho dos canais vermelho e verde do LED, além de usar o botão digital (SW) do próprio joystick para alternar o estado do canal azul[cite: 57, 60, 61].*

* [**Led_Sensor_Som**](./Led_Sensor_Som)
    * [cite_start]*Alterna o estado de um LED ao detectar sons através de um sensor digital[cite: 64, 66]. Para evitar leituras falsas causadas por excesso de barulho, o código congela o processador por 10000ms após cada acionamento[cite: 64, 67].*

* [**Sensor_temp_umidade**](./Sensor_temp_umidade)
    * [cite_start]*Realiza a leitura de umidade e temperatura (em Celsius) utilizando o sensor DHT11 e a biblioteca da Adafruit[cite: 68, 71, 75, 76]. [cite_start]Os dados são impressos no Monitor Serial utilizando múltiplos comandos `print`, pois a função do Arduino não suporta as máscaras de formatação usadas no `printf` do C tradicional[cite: 78, 79].*

---

## 🚀 Como testar os códigos

1.  Navegue até a pasta do projeto desejado.
2.  Abra o arquivo `.ino` na **IDE do Arduino**.
3.  Verifique no início de cada código as definições de `#define` para saber exatamente em quais pinos conectar os seus componentes.
4.  Conecte a sua placa, selecione a porta correta em `Ferramentas` e faça o upload (`Ctrl + U`).

## 🛠️ Notas de Configuração Padrão

* [cite_start]**Pinos PULL-UP:** Vários projetos usam o recurso de `INPUT_PULLUP` nativo do microcontrolador para evitar a necessidade de resistores físicos e ruídos do ambiente em botões e interruptores[cite: 2, 3, 44].
* [cite_start]**Velocidade Serial:** Quando aplicável, a comunicação serial nos códigos está configurada por padrão para `9600 baud`[cite: 72].
