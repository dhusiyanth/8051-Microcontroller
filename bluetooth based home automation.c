#include<reg52.h>
sbit red=P1^0;
sbit white=P1^3;
sbit green =P1^2;
int val;
void uart_init()
{
	TMOD=0x20;
	SCON=0x50;
	TH1=0XFD;
	TR1=1;
}
void rx()
{
	while(RI==0);
	RI=0;
	val=SBUF;
}
void main()
{
	P1=0x00;
	red=0;
	white=0;
	green=0;
	uart_init();
	while(1)
	{
	rx();
		if(val=='1')
		{
		red=0;
		green=1;
		white=1;
		}
		else if(val=='2')
		{
			white=0;
			green=1;
			red=1;
		}
		else
		{
			green=0;
			red=1;
			white=1;
		}	
	}
}