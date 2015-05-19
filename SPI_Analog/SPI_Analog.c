/*//////////////////////////GPL��Դ���֤////////////////////////////////////////////////
    Copyright (C) <2015>  <Xianglong He>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    �ļ�����SPI_Analog.c
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  admin@hxlxz.com
	����������SPIͨ�ŵ�IO��ģ��ʵ��
	��ע����ʹ�õĵ�Ƭ���Դ�SPIͨ�����Ӳ�����ܣ���STC15Wϵ�У����Ƽ�ֱ��ʹ����Ӳ��ģ�顣
          ʹ�ø�ģ�飬����config.h�ж���SPI_CPOL_SET����ΪSPIͨ�ŵ�CPOLģʽ��
          �� #define SPI_CPOL_SET 1
          ʹ�ø�ģ�飬����config.h�ж���SPI_CPOL_SET����ΪSPIͨ�ŵ�CPHAģʽ��
          ���飺���Ҫ��SPI�����ͨ�ţ���������CPHAΪ1������������߱�������ȶ��ԡ�
          �� #define SPI_CPHA_SET 1
          ʹ�ø�ģ�飬����config.h�ж���SPI_CS_SET����ΪSPI���ߵ�CSʹ�ܽӿڡ�
          �� #define SPI_CS_SET P0^0
          ʹ�ø�ģ�飬����config.h�ж���SPI_SCLK_SET����ΪSPI���ߵ�SCLKʱ���źŽӿڡ�
          �� #define SPI_SCLK_SET P0^1
          ʹ�ø�ģ�飬����config.h�ж���SPI_MOSI_SET����ΪSPI���ߵ�MOSI�źŽӿڡ�
          �� #define SPI_MOSI_SET P0^2
          ʹ�ø�ģ�飬����config.h�ж���SPI_MISO_SET����ΪSPI���ߵ�MISO�źŽӿڡ�
          �� #define SPI_MISO_SET P0^3
*////////////////////////////////////////////////////////////////////////////////////////
#include<reg52.h>
#include<SPI_Analog.h>

#define Dealy(); {_nop_();_nop_();_nop_();_nop_();_nop_();}	//SPIͨ�ŵ�С��ʱ

#define CPOL SPI_CPOL_SET
#define CPHA SPI_CPHA_SET
//����SPIͨ�ŵĲ���

sbit CS = SPI_CS_SET;	//����SPIͨ�ŵ��ĸ�IO��
sbit SCLK = SPI_SCLK_SET;
sbit MOSI = SPI_MOSI_SET;
sbit MISO = SPI_MISO_SET;

/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Master_Init
*�������ܣ�SPI��ʼ��������ģʽʹ�ã�
*�����б�
*   ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��1��8��
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Master_Init()
{
	SCLK = CPOL;
	CS = 1;
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Write
*�������ܣ�SPI��ģʽ������һλunsigned char �͵�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ���͵�����
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��1��8��
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Write(unsigned char dat)
{
	unsigned char mask;
	CS = 0;
	#if CPHA
		for(mask = 0x80; mask != 0; mask >>= 1)
			{
				SCLK = ~ SCLK;
				MOSI = dat & mask;
				Dealy();
				SCLK = ~ SCLK;
				Dealy();
			}
	#else
		for(mask = 0x80; mask != 0;)
			{
				MOSI = dat&mask;
				SCLK = ~ SCLK;
				Dealy();
				mask >>= 1;
				SCLK = ~ SCLK;
				Dealy();
			}
	#endif
	CS = 1;
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Read
*�������ܣ�SPI��ģʽ����ȡһλunsigned char �͵�����
*�����б�
*   ��
*����ֵ��һ��unsigned char�����ݣ���ȡ�������ݡ�
*�汾��1.0
*���ߣ�������
*���ڣ�2015��1��8��
*////////////////////////////////////////////////////////////////////////////////////
unsigned char SPI_Read()
{
	unsigned char dat = 0,mask = 0x80;
	CS = 0;
	#if CPHA
		for(;mask != 0;mask >>= 1)
			{
				SCLK = ~ SCLK;
				Dealy();
				if(MISO)dat |= mask;
				SCLK = ~ SCLK;
				Dealy();
			}
	#else
		for(;mask != 0;mask >>= 1)
			{
				Dealy();
				if(MISO)dat |= mask;
				SCLK = ~ SCLK;
				Dealy();
				SCLK = ~ SCLK;
				Dealy();
			}
	#endif
	CS = 1;
	return dat;
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Slave_Send
*�������ܣ�SPI��ģʽ����Ӧһλunsigned char �͵�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ�ظ�������
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��1��8��
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Slave_Send(unsigned char dat)
{
	unsigned char mask=0x80;
	while(CS);
	#if CPHA		
		for( ; mask != 0; mask >>= 1)
			{				
				while(SCLK == CPOL);
				MISO = dat & mask;				
				while(SCLK != CPOL);
			}
	#else		
		for( ; mask != 0; mask >>= 1)
			{
				MISO = dat & mask;
				while(SCLK == CPOL);			
				while(SCLK != CPOL);
			}
		
	#endif
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Slave_Resive
*�������ܣ�SPI��ģʽ������һλunsigned char �͵�����
*�����б�
*   ��
*����ֵ��һ��unsigned char�����ݣ����յ������ݡ�
*�汾��1.0
*���ߣ�������
*���ڣ�2015��1��8��
*////////////////////////////////////////////////////////////////////////////////////
unsigned char SPI_Slave_Resive()
{
	unsigned char mask = 0x80,dat = 0;
	while(CS);                              //�ȴ�SPIʹ���ź�
	#if CPHA
		for(;mask != 0;mask >>= 1)
			{
				while(SCLK == CPOL);    				
				while(SCLK != CPOL);
				if(MOSI)dat |= mask;				
			}
	#else
		for(;mask != 0;mask >>= 1)
			{								
				while(SCLK == CPOL);
				if(MOSI)dat |= mask;
				while(SCLK != CPOL);
			}
	#endif
   return dat;
}
