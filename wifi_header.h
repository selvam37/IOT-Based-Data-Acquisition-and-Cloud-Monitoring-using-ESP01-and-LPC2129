#include<string.h>
unsigned char UART0_RX(void);
void esp_read()
{
    char ch;int i;
    for( i=0;i<200;i++)
    {
        if(U0LSR&1)
        {
            ch = U0RBR;
            UART0_TX(ch);   // echo back to terminal
        }
    }
}

void WiFi_init(void)
{
	UART0_STRING("AT\r\n");
	delay_ms(1000);
	esp_read();
	UART0_STRING("AT+CWMODE=1\r\n");
	delay_ms(1000);
	esp_read();
	UART0_STRING("AT+CWJAP=\"Galaxy A32\",\"12345678\"\r\n");
	delay_ms(2000);
	esp_read();
}
void Thingspeak_data(float val)
{		
	char str[100];
	char s[100];
	sprintf(str,"GET /update?api_key=E2SJF9L6SZ5VNBME&field1=%.2f\r\n""Host: api.thingspeak.com\r\n""Connection: close\r\n\r\n", val);
	sprintf(s,"AT+CIPSEND=%d\r\n",strlen(str)); 
	UART0_STRING("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	delay_ms(2000);
	esp_read();
	UART0_STRING(s);
	delay_ms(2000);
	esp_read();	
	UART0_STRING(str);
	delay_ms(15000);
	esp_read();	
}	