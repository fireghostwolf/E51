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

    �ļ���:SPI_Analog.c
	����:������
	����:qwgg9654@gmail.com
		  admin@hxlxz.com
	��������:SPIͨ��ģ��
	��ע:�������ڴ���SPI���ܵ�STC15ϵ�е�Ƭ��
*////////////////////////////////////////////////////////////////////////////////////////
#include<STC15W4K.h>
#include<SPI.h>
bit IS_Master = 0;
sbit SS = P1^2;

void DataResive(unsigned char dat);
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Send
*�������ܣ�SPI����һλunsigned char �͵�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ���͵�����
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��5��18��
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Send(unsigned char dat)
{
    if(IS_Master == 1)
    {
        SS = 0;
		SPDAT = dat;
    }
    else SPDAT = dat;
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������Interrupt_SPI
*�������ܣ�SPI�жϺ���
*�����б�
*   ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��5��18��
*////////////////////////////////////////////////////////////////////////////////////
void Interrupt_SPI() interrupt 9
{
	SPSTAT = 0xB0;
	if(IS_Master == 1)
    {
		SS = 1;
		SS = 0;
		DataResive(SPDAT);
    }
    else
		DataResive(SPDAT);
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Init
*�������ܣ�SPI����һλunsigned char �͵�����
*�����б�
*   cpha
*       �������ͣ�bit������
*       ����������SPI CPHA����ֵ
*   cpol
*       �������ͣ�bit������
*       ����������SPI CPOL����ֵ
*   mode
*       �������ͣ�bit������
*       ����������SPI ����ģʽ���ã�1����ģʽ��0����ģʽ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��5��18��
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Init(bit cpha, bit cpol, bit mode)
{
	if(mode == 1)
    {
        SPCTL = 0xD0;
        IS_Master = 1;
    }
	else
		SPCTL = 0x40;
	if(cpol == 1)
		SPCTL |= 0x08;
	if(cpha == 1)
		SPCTL |= 0x04;
	EA = 1;
	IE2 |= 0x02;
}
