#include <lib/GPIO/GPIO.h>
#include <lib/PLL/PLL.h>
#include <lib/Timer/Timer.h>

static const int DELAY = 200;

/**
 * main.c
 */
int main(void) {
    Timer_t timer = DelayInit();
	GPIOConfig_t LED_R = {PIN_F1, GPIO_PULL_DOWN, true, 0, false, GPIO_DRIVE_2MA, false};
	GPIOInit(LED_R);
	GPIOConfig_t LED_B = {PIN_F2, GPIO_PULL_DOWN, true, 0, false, GPIO_DRIVE_2MA, false};
    GPIOInit(LED_B);
    GPIOConfig_t LED_G = {PIN_F3, GPIO_PULL_DOWN, true, 0, false, GPIO_DRIVE_2MA, false};
    GPIOInit(LED_G);

    int i;

    for(i = 0; i < 100; i++) {
        GPIOSetBit(PIN_F3, false);
        GPIOSetBit(PIN_F1, true); // red
        DelayMillisec(DELAY);

        GPIOSetBit(PIN_F1, false);
        GPIOSetBit(PIN_F2, true); // blue
        DelayMillisec(DELAY);

        GPIOSetBit(PIN_F2, false);
        GPIOSetBit(PIN_F3, true); // green
        DelayMillisec(DELAY);
        GPIOSetBit(PIN_F2, true);
        GPIOSetBit(PIN_F3, true); // blue + green
        DelayMillisec(DELAY);
        GPIOSetBit(PIN_F2, false);
        GPIOSetBit(PIN_F1, true);
        GPIOSetBit(PIN_F3, true); // green + red
        DelayMillisec(DELAY);
        GPIOSetBit(PIN_F3, false);
        GPIOSetBit(PIN_F2, true); // blue + red
        DelayMillisec(DELAY);
        GPIOSetBit(PIN_F3, true); // white
        DelayMillisec(DELAY);
        GPIOSetBit(PIN_F1, false);
        GPIOSetBit(PIN_F2, false);
        GPIOSetBit(PIN_F3, false); // nothing :(
        DelayMillisec(DELAY);
    }
}
