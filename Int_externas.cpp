
#include <avr/io.h>
#include <stdio.h>   // para sprintf
#include "lcd.h"
#define F_CPU 8000000UL    // Frecuencia a la que está trabajando el microcontrolador
#include <util/delay.h>
#include <avr/interrupt.h>


volatile uint8_t contadorInterrup = 0;
int main(void)
{
      lcd_init(LCD_DISP_ON);  // inicia el lcd
      lcd_clrscr();
	  // configuracion interrupcion externa INT0, cuenta el flanco de bajada y de subida
	  EICRA |= (1<<ISC00);
	  EIMSK |= (1<<INT0);
	  sei();   // ACtivador global de interrupciones
	  
	  lcd_gotoxy(0,0); lcd_puts(" Interrupciones");
	  lcd_gotoxy(5,1); lcd_puts(" Externas ");
	  _delay_ms(500);
	  lcd_clrscr();

	  
      
    while (1) 
    {
		lcd_gotoxy(0,0);lcd_puts("cont:");
		lcd_gotoxy(6,0); lcd_write_value(contadorInterrup,3);// 

			
		
    }
}



ISR(INT0_vect)  // encoder derecho B
{

	contadorInterrup++;
}
