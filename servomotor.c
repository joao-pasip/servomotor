#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22   // GPIO para o servo
#define LED_RGB_PIN 12 // GPIO do LED RGB (BitDogLab)

uint pwm_slice; // Slice do PWM

// Configuração do PWM para o servo
void setup_pwm()
{
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    pwm_slice = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_clkdiv(pwm_slice, 250); // Define o divisor do clock do PWM
    pwm_set_wrap(pwm_slice, 9999);  // Define o valor de wrap para obter 50Hz
    pwm_set_enabled(pwm_slice, true);
}

// Função para definir o ciclo ativo do servo
void set_servo_angle(uint16_t pulse_width)
{
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
}

// Função para movimentação suave do servo
void smooth_servo_movement(uint16_t start_angle, uint16_t end_angle)
{
    int step = (start_angle < end_angle) ? 5 : -5;

    for (uint16_t current_angle = start_angle; (step > 0) ? (current_angle <= end_angle) : (current_angle >= end_angle); current_angle += step)
    {
        set_servo_angle(current_angle);
        sleep_ms(10); // Atraso de ajuste
    }
}

int main()
{
    stdio_init_all();
    setup_pwm();

    // Configuração do LED RGB
    gpio_init(LED_RGB_PIN);
    gpio_set_dir(LED_RGB_PIN, GPIO_OUT);

    // 1) Posição de 180° (2400µs)
    set_servo_angle(2400);
    gpio_put(LED_RGB_PIN, 1); // Liga o LED
    sleep_ms(5000);

    // 2) Posição de 90° (1470µs)
    set_servo_angle(1470);
    gpio_put(LED_RGB_PIN, 0); // Desliga o LED
    sleep_ms(5000);

    // 3) Posição de 0° (500µs)
    set_servo_angle(500);
    gpio_put(LED_RGB_PIN, 1); // Liga novamente o LED
    sleep_ms(5000);

    // 4) Movimentação periódica entre 0° e 180°
    while (true)
    {
        smooth_servo_movement(500, 2400); // 0° → 180°
        smooth_servo_movement(2400, 500); // 180° → 0°
    }

    return 0;
}