#include<reg52.h>
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
#define  lcd P3
unsigned int k,j;
void delay(unsigned char time);
void init(void);
void dat(unsigned char a);
void cmd(unsigned char b);
//void string(unsigned char *s);

void main()
{
	//P0=0x00;
	//P2=0x00;	
unsigned char name[10]={"DHUSIYANTH"};
	while(1)
	{
	init();
		//string("DHUSIYANTH");	
		for(j=0;j<=10;j++)
		{
		dat(name[j]);	
		delay(1000);
		}
	}
}
void init(void)
{
	cmd(0x01);
	cmd(0x02);
	cmd(0x0c);
	cmd(0x38);
	cmd(0x80);
}
void delay(unsigned char time)	
	{
	unsigned int k,l;
	for(k=0;k<time;k++)
		{
			for(l=0;l<=100;l++);
		}
	}
	void dat(unsigned char a)
{
	rs=1;
	rw=0;
  lcd=a;
	en=1;
	delay(2);
	en=0;
}
void cmd(unsigned char b)
{
  rs=0;
	rw=0;
  lcd=b;
	en=1;
	delay(2);
	en=0;	
}
//void string(unsigned char *s)
//{
// while(*s)
//	 dat(*s++);
//}