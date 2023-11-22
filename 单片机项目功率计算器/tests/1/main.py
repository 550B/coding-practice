from machine import Pin
if __name__ == '__main__':
    LED = Pin(25, Pin.OUT)
    LED.value(1)