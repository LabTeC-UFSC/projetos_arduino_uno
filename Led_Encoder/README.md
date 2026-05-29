# README - Seletor de Cores Digital com Rotary Encoder

## Descrição e Funcionamento
Este projeto consiste num seletor de cores digital para um LED RGB utilizando um Rotary Encoder (Codificador Rotativo) com botão integrado. O sistema opera como uma máquina de estados simples controlada por duas ações distintas do usuário:
1. **O Clique do Botão (`BOTAO_SW`)**: Alterna ciclicamente qual canal de cor do LED RGB está selecionado no momento. A sequência avança de Vermelho (1) para Verde (2), depois Azul (3), retornando ao Vermelho (1).
2. **A Rotação do Eixo (`ROTACAO`)**: Lê o movimento giratório do encoder através do pino CLK. O encoder funciona internamente com um disco dentado mecânico que abre e fecha contatos elétricos muito rapidamente. O estado lido desse giro (se parou sobre um dente ou sobre um espaço vazio) é imediatamente atribuído à intensidade da cor selecionada.

Com esta lógica, o utilizador pode selecionar uma cor clicando no botão e, em seguida, girar o eixo para acender ou apagar aquele canal específico, combinando os estados para formar cores secundárias.

## Mapeamento de Pinos
* **LED_VERMELHO**: Pino Digital 11 (Saída)
* **LED_VERDE**: Pino Digital 10 (Saída)
* **LED_AZUL**: Pino Digital 9 (Saída)
* **BOTAO_SW**: Pino Digital 7 (Entrada com Pull-up Interno)
* **ROTACAO (Pino CLK)**: Pino Digital 6 (Entrada)

## Conceitos Utilizados
* **Máquina de Estados de Seleção**: Variável numérica (`escolhaCor`) que direciona o fluxo lógico do programa para atualizar apenas a memória do canal selecionado, preservando os estados dos demais canais.
* **Leitura de Encoder Rotativo**: Interpretação de pulsos rápidos de rotação como chaves binárias dinâmicas para modificar dados em tempo real.
* **Atraso de Controle Comportamental**: Introdução de um pequeno delay de 300ms no acionamento do botão para evitar o avanço involuntário de múltiplos estados devido à alta velocidade de processamento do microcontrolador.

## Funções Utilizadas
* `digitalRead(pino)`: Monitora tanto a ação mecânica do clique do botão central quanto os pulsos gerados pela rotação do eixo.
* `digitalWrite(pino, valor)`: Envia os sinais lógicos atualizados de ligado ou desligado para os três pinos catódicos/anódicos do LED RGB.
