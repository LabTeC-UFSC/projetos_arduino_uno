#include <DHT.h> // baixe a biblioteca DHT sensor library feito pela Adafruit

/*
No Arduino IDE, vá em Sketch > Incluir Biblioteca > Gerenciar Bibliotecas.

Busque por "DHT sensor library" e instale a versão feita pela Adafruit.

Se o programa perguntar se você deseja instalar dependências (como a Adafruit Unified Sensor), clique em "Install All" (Instalar tudo).
*/

#define DHTPIN 13      // Pino digital onde o cabo de dados do sensor está conectado
#define DHTTYPE DHT11 // Avisamos a biblioteca qual é o nosso sensor

// Cria o objeto para controlar o sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicia a comunicação com o computador (Monitor Serial)
  Serial.begin(9600);
  Serial.println("Iniciando o sensor DHT11...");
  
  // Inicia o sensor
  dht.begin();
}

void loop() {
  // DHT11 é um sensor lento. 
  // Precisamos esperar pelo menos 2 segundos (2000ms) entre cada leitura.
  delay(2000);

  // Lê a umidade (em %)
  float umidade = dht.readHumidity();
  // Lê a temperatura em graus Celsius (padrão)
  float temperatura = dht.readTemperature();

  // Verifica se a leitura falhou (se algum fio soltou ou o sensor travou)
  // isnan significa "Is Not a Number" (Não é um número)
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do sensor DHT!");
    return; // Interrompe este ciclo do loop e tenta novamente no próximo
  }

  // Imprime os valores no Monitor Serial
  Serial.print("Umidade: "); // O arduino não suporta usar mascaras de formatação como no printf do C, por isso esta separado
  Serial.print(umidade);
  Serial.print("%  |  ");
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C"); // O println aqui faz a quebra para a próxima linha
}

// Vá no monitor serial, é so clicar no icone da lupa no canto superior esquerdo