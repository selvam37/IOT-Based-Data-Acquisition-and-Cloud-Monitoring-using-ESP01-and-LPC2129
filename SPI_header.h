void spi_config()
{
		PINSEL0 |= 0x1500;
		S0SPCCR = ((60000000/4)/100000); //(PCLK/SPI_SPEED)
		S0SPCR = (1<<5)|((1<<3)|(1<<4)); //MSTR_bit | MODE_3
		IODIR0 |= 1<<7;//chip select
		IOSET0 = 1<<7;//chip select
}

unsigned char spi(unsigned char data)
{
	char stat;
	stat = S0SPSR;
	S0SPDR = data;
	while(!((S0SPSR>>7)&1));
	return S0SPDR;
}
/*double adc_read_value(int num){
	
		unsigned char x,y;float temp;int value;		
		IOCLR0 = 1<<7;
		spi(0x06);
		x = spi(num<<6);
		y = spi(0x00);
		IOSET0 = 1<<7;
	  	value = ((x&0x0f)<<8)|y;
	  	temp = (value*3.3)/(4095.0);//to convert the temperature
	 	return (temp*100);
}
*/
 double adc_read_value(int num)   // num = 0 for CH0
{
    unsigned char x,y;
    int value;
    double temp;

    IOCLR0 = 1<<7;        // CS LOW
    spi(0x06);            // Start + single ended
    x = spi(num<<6);      // Channel select (CH0 ? 0)
    y = spi(0x00);        // Read data
    IOSET0 = 1<<7;        // CS HIGH

    value = ((x & 0x0F) << 8) | y;

    // FINAL CORRECT FORMULA
    temp = (value * 3.3 * 100) / 4095.0;

    return temp;
}
