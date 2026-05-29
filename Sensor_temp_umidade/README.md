# README - Monitor de Temperatura e Umidade com DHT11

## Descrição e Funcionamento
Este projeto realiza a leitura periódica de dados meteorológicos e ambientais de temperatura e umidade usando o sensor digital DHT11. Como o DHT11 utiliza um protocolo de comunicação proprietário de fio único (Single-Bus) com restrições rígidas de tempo, o projeto integra a biblioteca especializada da Adafruit para extrair os dados de forma limpa e confiável.

O programa colhe amostras das variáveis a cada 2 segundos (tempo mínimo exigido pelo hardware para estabilização térmica do sensor). Antes de processar os dados, o firmware realiza uma verificação de consistência para garantir que a leitura foi bem-sucedida. Em caso positivo, os valores de umidade (em %) e temperatura (em °C) são formatados e transmitidos via comunicação Serial UART para visualização em tempo real no Monitor Serial do computador.

## Mapeamento de Pinos
* **DHTPIN**: Pino Digital 13 (Barramento de Dados Bidirecional)

## Requisitos de Software (Instalação de Bibliotecas)
Para compilar este código, é necessário instalar as seguintes ferramentas no Arduino IDE:
1. Ir a **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**.
2. Procurar por **"DHT sensor library"** e instalar a versão desenvolvida pela **Adafruit**.
3. Se solicitado para instalar dependências, selecionar **"Install All"** (isto instalará a biblioteca acessória *Adafruit Unified Sensor*).

## Conceitos Utilizados
* **Comunicação Serial UART**: Interface assíncrona ponto a ponto para transmissão de strings formatadas e diagnóstico de dados entre o microcontrolador e o computador a uma taxa de 9600 bps.
* **Tratamento de Exceções Matemáticas (`isnan`)**: Validação de dados para detectar falhas físicas de hardware (como fios desconectados ou mau contato) antes de realizar a exibição.
* **Abstração por Objetos**: Uso de uma biblioteca externa para ocultar a complexidade do chaveamento de microsegundos exigido pelo barramento de comunicação do chip.

## Funções Utilizadas
* `Serial.begin(baudrate)`: Inicializa os buffers e pinos de comunicação serial.
* `dht.begin()`: Configura internamente os temporizadores e pinos para o correto funcionamento da biblioteca do sensor.
* `dht.readHumidity()`: Retorna um valor de ponto flutuante (`float`) contendo o percentual de umidade relativa do ar.
* `dht.readTemperature()`: Retorna um valor de ponto flutuante contendo a temperatura atual em graus Celsius.
* `isnan(valor)`: Macro que verifica se a variável contém um valor numérico válido ou se falhou (Is Not a Number).
* `Serial.print()` e `Serial.println()`: Enviam textos e variáveis de forma segmentada e realizam a quebra de linha na tela de recepção.
