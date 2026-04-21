void UART0_CONFIG(){
	
	PINSEL0 |= 0x5;
	U0LCR = 0X83;
	U0DLL = 97;
	U0DLM = 0;
	U0LCR = 0X03;
	 	
}
void UART0_TX(unsigned char data){
	
	U0THR = data;
	while(((U0LSR>>5)&1)==0); 		

}
unsigned char UART0_RX(void){
	
	while((U0LSR&1)==0);
	return U0RBR;
	
}
void UART0_STRING(char *s)
{
	while(*s)
		UART0_TX(*s++);
}
void UART0_INT(int n)
{
	if(n<10)
	{
		UART0_TX('0');
		UART0_TX(n+48);
	}
 	else
 	{
		UART0_TX((n/10)+48);
		UART0_TX((n%10)+48);
 	}
}
void UART0_FLOAT(float f_val)
{
 	int x;
  	x = f_val;
  	UART0_INT(x);
  	UART0_TX('.');
  	x=(f_val-x)*100;
  	UART0_INT(x);	
}
