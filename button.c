#include<reg52.h>
#define button P0
#define led P1

void main()
{
P1=0x00;
P0=0xff;
while(1)
{
if(button==0)
{
led=1;
}
else
{
led=0;
}
}
}