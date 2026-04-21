#include<lpc21xx.h>
#include<string.h>
#include "UART_header.h"
#include "SPI_header.h"
#include "lcd_4bit_1.h"
#include "wifi_header.h"
#define ch 1
double adc_read_value(int);
int main()
{
	unsigned int x=0;float val;
	PINSEL0 |= 0x1505;	
	UART0_CONFIG();
	spi_config();
	LCD_INIT();
	WiFi_init();
	while(x++<20)
	{
		LCD_COMMAND(0x80);
		LCD_COMMAND(0x1C);
		LCD_STRING("IoT Based Data Acquisition");
		LCD_COMMAND(0xC0);
		LCD_COMMAND(0x1C);
		LCD_STRING("And Cloud Monitoring System");
		delay_ms(50);
	}
	delay_ms(500);
	LCD_COMMAND(0x01);
	while(1)
	{
		val = adc_read_value(ch);
		delay_ms(1000);
   		UART0_STRING("Temperature: ");
		UART0_FLOAT(val);
	  	UART0_STRING("\n");
		LCD_COMMAND(0x80);
	  	LCD_STRING("Temperature: ");
	  	LCD_COMMAND(0xC0);
		LCD_FLOAT(val);
		Thingspeak_data(val);
	}
}
	