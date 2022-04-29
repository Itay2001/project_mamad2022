
#include "initsys.h"

U8 D[20];
U16 PageID;	
sbit d0=P0^7;
//trasmit
U8 code collect[]= {0XEF,0X01,0XFF,0XFF,0XFF,0XFF,0X01,0X00,0X03,0X01,0X00,0X05};
U8 code generate[]={0XEF,0X01,0XFF,0XFF,0XFF,0XFF,0X01,0X00,0X04,0X02,0X01,0X00,0X08};
U8 code search[]=  {0XEF,0X01,0XFF,0XFF,0XFF,0XFF,0X01,0X00,0X08,0X1B,0X01,0X00,0X00,0X03,0XE9,0X01,0X11};


void ClearFIFO(void)
{	
	char tav;	
	do
	{
		SCON1=SCON1&0Xfe;
		tav=SBUF1;
	}
	while(SCON1&1);
	SCON1=SCON1&0X7f; //clear ovr1 
}

void PUTCHAR1(char tav)
{
	SBUF1=tav;
	while((SCON1&2)==0); //(TI1==0)
	SCON1=SCON1&(~2);    //TI1 = 0;  
}

char GETCHAR1(void)
{
	char tav;
	//read from uart
	while((SCON1&1)==0); //(RI1==0);
	SCON1=SCON1&0Xfe;  //RI1=0;
	tav=SBUF1;
	return(tav);
}


void PUTCHAR0(char tav)
{
	SBUF0=tav;
	while(TI0==0);
	TI0=0;
}

char GETCHAR0(void)
{
	while(RI0==0); 
	RI0=0;
	return SBUF0;
}
int FindFinger(void)
{
	int i;
	ClearFIFO();
	/////////////////collect////////////////////////////////

	LCD_print2C(120,230,"collect   ",2,BLACK, YELLOW);	
	do
	{
		for(i=0;i<12;i++)
			PUTCHAR1(collect[i]);

		for(i=0;i<12;i++)
			D[i]=GETCHAR1();

		delay_ms(100);		
	}
	while(D[9]);


	/////////////////////generate//////////////////////////////////////
	LCD_print2C(120,230,"generate   ",2,BLACK, YELLOW);	 	
	do
	{
		for(i=0;i<13;i++)
			PUTCHAR1(generate[i]);

		for(i=0;i<12;i++)
			D[i]=GETCHAR1();

		delay_ms(100);		
	}
	while(D[9]);

	///////////////search//////////////////////////
	LCD_print2C(120,230,"search  ",2,BLACK, YELLOW);	 	

	for(i=0;i<17;i++)
		PUTCHAR1(search[i]);
	for(i=0;i<16;i++)
		D[i]=GETCHAR1();

	if(D[9]==0)
	{
		PageID=(D[10]<<8)+D[11];
		return 1;
	}
	else
	{
		return 0;
	}
}

