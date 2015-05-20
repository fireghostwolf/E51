/*//////////////////////////GPL��Դ���֤////////////////////////////////////////////////
    Copyright (C) <2014>  <Xianglong He>
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
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  568629794@qq.com
	2014��12��9��
	����������DS1302ʱ��оƬ��ʱ�����ü���ȡ
*////////////////////////////////////////////////////////////////////////////////////////
#include<reg51.h>

struct StructTime{
	unsigned char sec;
	unsigned char min;
	unsigned char hour;
	unsigned char day;
	unsigned char month;
	unsigned char week;
	unsigned char year;
};

sbit DS1302_CE=P1^7;//�����ʵ������޸�
sbit DS1302_IO=P3^4;
sbit DS1302_CK=P3^5;

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}


void DS1302_ByteWrite(unsigned char dat)
{
	unsigned char mask;
	for(mask=0x01;mask!=0;mask<<=1)
		{
			if(mask&dat)DS1302_IO=1;
			else DS1302_IO=0;
			DS1302_CK=1;
			DS1302_CK=0;
		}
	DS1302_IO=1;
}

unsigned char DS1302_ByteRead()
{
	unsigned char mask,dat=0;
	DS1302_IO=1;
	for(mask=0x01;mask!=0;mask<<=1)
		{
			if(DS1302_IO)dat|=mask;
			DS1302_CK=1;
			DS1302_CK=0;
		}
	return dat;
}
unsigned char DS1302_SingleRead(unsigned char addr)		//DS1302���ֽڶ�ȡ��datΪ��ȡ���ݴ洢λ�ã�addrΪ�Ĵ�����ַ����������ֲ�
{
	unsigned char dat;
	EA=0;
	DS1302_CE=1;
	DS1302_ByteWrite(0x81|(addr<<1));
	dat=DS1302_ByteRead();
	DS1302_CE=0;
	EA=1;
	return dat;
}
void DS1302_SingleWrite(unsigned char addr,unsigned char dat)	//DS1302���ֽ�д�룬datΪд�����ݣ�addrΪ�Ĵ�����ַ����������ֲ�
{
	EA=0;
	DS1302_CE=1;
	DS1302_ByteWrite(0x80|(addr<<1));
	DS1302_ByteWrite(dat);
	DS1302_CE=0;
	EA=1;
}
void DS1302_BrustWrite(unsigned char *dat)	//DS1302Brustģʽд�룬datΪuint8�͵�ӵ��8��Ԫ�ص�����
{
	unsigned char i;
	EA=0;
	DS1302_CE=1;
	DS1302_ByteWrite(0xBE);
	for(i=0;i<8;i++)
		{
			DS1302_ByteWrite(*dat);
			dat++;
		}
	DS1302_CE=0;
	EA=1;
}
void DS1302_BrustRead(unsigned char *dat)	//DS1302Brustģʽ��ȡ��datΪuint8�͵�ӵ��8��Ԫ�ص�����
{
	unsigned char i;
	EA=0;
	DS1302_CE=1;
	DS1302_ByteWrite(0xBF);
	for(i=0;i<8;i++)
		{
			*dat=DS1302_ByteRead();
			dat++;
			EA=1;
			Delay1ms();
			EA=0;
		}
	DS1302_IO=0;
	DS1302_CE=0;
	EA=1;
}
void DS1302_Init(unsigned char *dat)	//DS1302��ʼ������������������ͷ���ã�dat�����õ�ʱ��
{
	DS1302_CE=0;
	DS1302_CK=0;
	DS1302_IO=1;
	DS1302_SingleWrite(7, 0x00);
    DS1302_BrustWrite(dat);
}
