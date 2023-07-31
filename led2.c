#include<reg52.h>
sbit led=P2^2;

void delay(unsigned int time)
{
int i,j;
 for(i=0;i<time;i++)
 {
	for(j=0;j<1000;j++);
 }
}
void main()
{
P2=0x00;
 while(1)
 {
   led=1;
   delay(100);
   led=0;
   delay(100);
 }
}