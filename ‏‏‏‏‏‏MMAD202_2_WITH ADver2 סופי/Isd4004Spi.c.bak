
#include "initsys.h"
#include "Isd4004Spi.h"


void SpiWrite(U8 cod);    
void SpiWriteAddCode(U16 add, U8 cod);
U8 reverse (U8 num);


void SpiWrite(U8 cod)             
{
	SS=0;
	SPIF = 0;    // 
	SPI0DAT = reverse(cod);  // start SPI transmision 
	while(!SPIF);    // wait for SPI finish 
	SPIF = 0;
	SS=1;	
}



void SpiWriteAddCode(U16 add, U8 cod)
{
	SS=0;
	SPIF = 0;	
	SPI0DAT = reverse(add);
	while(!SPIF);
	SPIF = 0;
	SPI0DAT = reverse(add>>8);
	while(!SPIF);
	SPIF = 0;
	SPI0DAT = reverse(cod);
	while(!SPIF);
	SS=1;
}



void Play(unsigned int add)
{
	U8 temp;
	temp=SPI0CKR;
	SPI0CKR   = 0x17;//1MHz

	add=(add*5)/2; //sec

	SpiWrite(0x20); //powerup
	delay_ms(60);    //60msec
	SpiWriteAddCode(add,0xe0); //send address+setplay

	//while(INT);
	//SPI_RW(0x10);  //stoppowerdown

	delay_ms(110);//Tstop

	SPI0CKR   = temp;
}

void PlayI(unsigned int add)
{
	U8 temp;
	temp=SPI0CKR;
	SPI0CKR   = 0x17;//1MHz

	add=(add*5)/2; //sec

	SpiWrite(0x20); //powerup
	delay_ms(60);    //60msec
	SpiWriteAddCode(add,0xe0); //send address+setplay

	while(INT);
	SpiWrite(0x10);  //stoppowerdown

	delay_ms(110);//Tstop

	SPI0CKR   = temp;
}



void Record(unsigned int add)
{
	U8 temp;
	temp=SPI0CKR;
	SPI0CKR   = 0x17;//1MHz

	add=(add*5)/2; //sec
	while(rec==1);
	delay_ms(20);

	SpiWrite(0x20); //powerup
	delay_ms(60);    //60msec
	SpiWrite(0x20);  //powerup
	delay_ms(110);
	SpiWriteAddCode(add,0xa0); //send address+setrec
	while(rec==0);  //wait end record
	SpiWrite(0x10);  //stoppowerdown
	delay_ms(110); //Tstop 

	SPI0CKR   = temp;
}


U8 ReadStatus(void)
{
	U8 temp;
	long status=0;
	temp=SPI0CKR;
	SPI0CKR   = 0x17;//1MHz

	SS=0;

	SPIF = 0;
	SPI0DAT = 0;
	while(!SPIF);
	status=reverse(SPI0DAT);

	SS=1;
	SPI0CKR   = temp;

	return status;
}



U8 reverse (volatile U8 num)
{
	num = ((num & 0xf0) >> 4)|(( num & 0x0f) << 4);  // efghabcd
	num = ((num & 0xcc) >> 2) | ((num & 0x33 )<< 2);  // ghefcdab 
	num = ((num & 0xaa) >> 1) | ((num & 0x55) << 1);  // hgfedcba
	return num;
}

