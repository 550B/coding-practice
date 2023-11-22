from machine import Pin, Timer, PWM
import utime

led = PWM(Pin(25))
led.freq(1000)
led_value = 0
led_space = 5

if __name__ == '__main__':
    while True:
        led_value += led_space
        if led_value >= 100:
            led_value = 100
            led_space = -5
        elif led_value <=0:
            led_value = 0
            led_space = 5
        led.duty_u16(int(led_value * 500))
        utime.sleep_ms(100)