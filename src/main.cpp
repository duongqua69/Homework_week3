#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>


LED led(LED_PIN, LED_ACT);

void btnPush();
void btnDoubleClick(); // Hàm mới cho double click
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led.off();
    button.attachClick(btnPush);
    button.attachDoubleClick(btnDoubleClick); // Liên kết double click
}

void loop()
{
    led.loop();
    button.tick();
}

void btnPush()
{
    led.flip();
}

void btnDoubleClick()
{
    led.blink(200); // Bắt đầu nhấp nháy LED
}
