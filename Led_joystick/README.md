# README - LED RGB Controlado por Joystick

## Descrição e Funcionamento
Este projeto demonstra o controle dinâmico e híbrido de um LED RGB utilizando um módulo Joystick analógico. O controle é dividido em duas lógicas de atuação simultâneas:
1. **Controle Analógico de Brilho (Eixos X e Y)**: Os eixos analógicos do joystick (VRx e VRy) variam a sua resistência interna por meio de potenciômetros. O microcontrolador lê esses valores analógicos e os injeta diretamente nos canais Vermelho e Verde do LED. Como a leitura analógica e a escrita PWM compartilham faixas compatíveis ou adaptáveis de tensão, a posição física da alavanca dita o brilho exato de cada cor.
2. **Controle Digital de Estado (Botão SW)**: O clique vertical do joystick atua como um botão digital de pressão. Ao pressioná-lo, o estado lógico do LED Azul é invertido (*toggle*), ligando ou desligando o canal completamente.

## Mapeamento de Pinos
* **VRx (Eixo X do Joystick)**: Pino Analógico A0 (Entrada)
* **VRy (Eixo Y do Joystick)**: Pino Analógico A1 (Entrada)
* **SW (Botão do Joystick)**: Pino Digital 8 (Entrada com Pull-up Interno)
* **LED_VERMELHO**: Pino Digital 11 (Saída PWM)
* **LED_VERDE**: Pino Digital 10 (Saída PWM)
* **LED_AZUL**: Pino Digital 9 (Saída)

## Conceitos Utilizados
* **Conversão Analógico-Digital (ADC)**: Mapeamento de tensões elétricas contínuas da alavanca em valores digitais compreendidos pelo processador.
* **Modulação por Largura de Pulso (PWM)**: Técnica utilizada para simular uma tensão analógica variável em saídas digitais chaveando o pino em altíssima frequência, controlando a intensidade luminosa do LED.
* **Controle Hibridizado**: Execução simultânea de processamentos analógicos de variação de intensidade e processamentos digitais discretos de liga/desliga no mesmo loop de software.

## Funções Utilizadas
* `analogRead(pino)`: Captura o posicionamento físico dos eixos do potenciômetro do joystick.
* `analogWrite(pino, valor)`: Escreve um sinal PWM no pino para modular a potência entregue e alterar o brilho do LED correspondente.
* `digitalRead(pino)` e `digitalWrite(pino, valor)`: Monitoram o estado da chave do botão e atualizam o estado estático do LED Azul.
* `delay(tempo)`: Pequeno congelamento de 50ms para estabilizar a leitura mecânica do clique (debounce).
