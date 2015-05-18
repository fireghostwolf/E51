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

	�ļ�����main.c
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  admin@hxlxz.com
	����������DS18B20�¶ȴ������ļ򵥲�������ģ���Sample����
*////////////////////////////////////////////////////////////////////////////////////////
#include<reg51.h>
#include<DS18B20.h>
unsigned char addr = 0x00;                          //Skip ROM
bit UART_SendFlag = 0;
void Delay1000ms();
void UART_Conf(unsigned int baud);
void UART_SendString(unsigned char *dat,unsigned char len);
int main()
{
	double temperature;                             //��ȡ�����¶ȴ洢���������
	int temp;                                       //�м���ʱ����
	char SendString[10]={0};                        //���ڴ������ַ����ݴ�
	UART_Conf(9600);                                //����ͨ�����ú���
	while(1)
	{
		if(! DS18B20_Start(&addr))                  //���Գ�ʼ��
		{
			UART_SendString("ERROR\n", 6);          //���ʧ�ܣ����ڷ���ERROR
			Delay1000ms();                          //��ʱ1��
		}
		else
		{
			Delay1000ms();                          //��ʱ1��
			temperature = DS18B20_GetTemp(&addr);   //��ȡDS18B20����ȡ�¶���Ϣ
			temp = (int) temperature;               //�����¶�����
			SendString[0] = temp / 100 + '0';
			SendString[1] = temp / 10 % 10 + '0';
			SendString[2] = temp % 10 + '0';
			SendString[3] = '.';
			temp = (temperature - temp) * 100;
			SendString[4] = temp / 10 + '0';
			SendString[5] = temp % 10 + '0';
			SendString[6] = '\n';
			UART_SendString(SendString, 7);         //ͨ�����ڷ����¶�����
		}
	}
}
void interrupt_UART() interrupt 4                   //�����жϺ���
{
	if(TI)
	{
		TI = 0;
		UART_SendFlag = 1;
	}
	if(RI)
	{
		RI = 0;
	}
}
void UART_Conf(unsigned int baud)                   //UART���ú�����buad�������õĲ����ʣ�
{
	TL1 = TH1 = 256 - 11059200 / 12 / 32 / baud;
	EA = 1;
	ES = 1;
	TMOD &= 0X0F;
	TMOD |= 0X20;
	SCON = 0X50;
	TR1 = 1;
}
void UART_SendString(unsigned char *dat,unsigned char len)  //����ͨ�ţ�����һ���ַ�����dat��Ҫ���͵��ַ�����len���ַ������ȣ�
{
	while(len)
	{
		len --;
		SBUF =* dat;
		dat ++;
		while(! UART_SendFlag);
		UART_SendFlag = 0;
	}
}
void Delay1000ms()		//�����ʱ����
{
	unsigned char i, j, k;

	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
