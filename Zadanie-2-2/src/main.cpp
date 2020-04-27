#include <avr/io.h>
#define LED_LENGHT 8

int main(){

  DDRD |=0xFF; //ustawiamy wszystkie wyprowadzenia portu D jako wyjścia
  while (1){
    //kierunkowe D0 -> D7
    for (uint8_t i = 0; i < LED_LENGHT; i++){
      PORTD = (1 << i);
      for (uint32_t j = 0x1FFFF; j>0; j--){
        __asm__ __volatile__("nop");
      }
    }
    // kierunek D6 -> D1
    for (uint8_t i = 1; i < (LED_LENGHT - 1); i++){
      PORTD = (PORTD >> 1);
      for(uint32_t j = 0x1FFFF; j > 0; j--){
        __asm__ __volatile__("nop");
      }
    }
  }
}