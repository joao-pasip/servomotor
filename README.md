# Controle de Servo Motor com Raspberry Pi Pico

## Descrição

Este projeto utiliza um Raspberry Pi Pico para controlar um servo motor através de um sinal PWM. Além disso, um LED RGB (BitDogLab) é acionado conforme a movimentação do servo. O projeto permite movimentação suave do servo entre diferentes posições.

## Componentes Necessários

- Raspberry Pi Pico
- Servo motor (compatível com sinal PWM de 50Hz)
- LED RGB (BitDogLab) ou LED comum
- Resistores (se necessário para o LED)
- Fios jumper
- Fonte de alimentação adequada

## Ligações

- **Servo motor**

  - Sinal (amarelo) -> GPIO 22 do Raspberry Pi Pico
  - VCC (vermelho) -> 5V (ou 3.3V dependendo do servo)
  - GND (preto) -> GND do Raspberry Pi Pico

- **LED RGB**
  - Anodo (positivo) -> GPIO 12 do Raspberry Pi Pico
  - Câtodo (negativo) -> GND do Raspberry Pi Pico

## Funcionamento

O programa inicializa o PWM no GPIO 22 para controlar o servo. O LED é utilizado como indicador do estado do servo.

### Etapas do Movimento

1. **Posição de 180° (2400µs)**

   - Servo é movido para a posição de 180°
   - LED é ligado por 5 segundos

2. **Posição de 90° (1470µs)**

   - Servo é movido para a posição de 90°
   - LED é desligado por 5 segundos

3. **Posição de 0° (500µs)**

   - Servo é movido para a posição de 0°
   - LED é ligado por mais 5 segundos

4. **Movimentação Contínua**
   - O servo se movimenta suavemente entre 0° e 180° repetidamente

## Compilando e Executando

### Requisitos

- SDK do Raspberry Pi Pico instalado
- Compilador GCC para ARM
- Ferramentas CMake

### Compilação

1. Clone o repositório e entre no diretório do projeto:
   ```sh
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DO_DIRETORIO>
   ```
2. Crie um diretório de build e compile o código:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Envie o arquivo `.uf2` para o Raspberry Pi Pico conectando-o no modo de bootloader.

## Autor

Desenvolvido por João Paulo Silva Piauhy.
