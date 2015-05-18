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
	��������:SPIͨ��ģ��-Sample����
	��ע:�ó�����IAP15W4K58S4��Ƭ���Ͻ��в���
		 �������Ч���ǣ�SPI���ӻ��ֱ𽫽��յ������ݼ�1����
*////////////////////////////////////////////////////////////////////////////////////////
#include<STC15W4K.h>
#include<SPI.h>
#define SPI_MODE 1
bit DataFlag = 0;
unsigned char DataResived = 0x00;
//�ó�����Ҫ�õ���ƬSTC15��Ƭ����������һƬ����Ϊ��������һƬΪ�ӻ�
void Delay10us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 25;
	while (--i);
}

int main()
{
	unsigned char dat = 0x00;
	#if SPI_MODE
		SPI_Init(0,0,1);
		SPI_Send(0x00);
		Delay10us();
		SPI_Read();
	#else
		SPI_Init(0,0,0);
	#endif

	while(1)
	{
		if(DataFlag)
		{
			DataFlag = 0;
			if(DataResived ==0xFE)DataResived +=2;
			else DataResived ++;
			SPI_Send(DataResived);
		}
	}
}
void DataResive(unsigned char dat)
{
	DataFlag = 1;
	DataResived = dat;
}