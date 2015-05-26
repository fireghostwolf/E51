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
	����������DS1302ʱ��оƬ��ʱ�����ü���ȡ
            ����ʹ�÷�װ�õĺ������в���������Ҫʹ��ֱ�Ӷ�DS18B20��д�ĺ�����
            ʹ�ø�ģ�飬����config.h�ж���DS1302_CE_SET����ΪDS1302��������ʹ���ź��ߡ�
                �� #define DS1302_CE_SET P0^0
            ʹ�ø�ģ�飬����config.h�ж���DS1302_IO_SET����ΪDS1302�����������ݴ����ߡ�
                �� #define DS1302_IO_SET P0^1
            ʹ�ø�ģ�飬����config.h�ж���DS1302_CK_SET����ΪDS1302��������ʱ���ź��ߡ�
                �� #define DS1302_CK_SET P0^2
            ʹ�ø�ģ�飬����config.h�ж���XTAL����Ϊ����Ƶ��
                �� #define XTAL 11.059200
*////////////////////////////////////////////////////////////////////////////////////////
#include<reg51.h>
#include<DS1302.h>

sbit DS1302_CE = DS1302_CE_SET;
sbit DS1302_IO = DS1302_IO_SET;
sbit DS1302_CK = DS1302_CK_SET;
//����DS1302���������߽ӿ�

/*///////////////////////////////////////////////////////////////////////////////////
*��������Delay1ms
*�������ܣ���ʱ1ms
*�����б�
*   ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2014��5��26��
*////////////////////////////////////////////////////////////////////////////////////
void Delay1ms()
{
	unsigned char i, j;
	i = (int) XTAL;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_ByteWrite
*�������ܣ���DS1302дһ��unsigned char�͵����ݻ�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫд������ݻ�����
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��9��
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_ByteWrite(unsigned char dat)
{
	unsigned char mask;
	for(mask = 0x01; mask != 0; mask <<= 1)
		{
			if(mask & dat)DS1302_IO = 1;        //�����ݰ�λд����������
			else DS1302_IO = 0;
			DS1302_CK = 1;                      //����ʱ���ź�
			DS1302_CK = 0;
		}
	DS1302_IO = 1;                              //�ͷ���������
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_ByteRead
*�������ܣ���DS1302��ȡһ��unsigned char�͵�����
*�����б�
*   ��
*����ֵ��һ��unsigned char�ͱ�������ȡ��������
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��9��
*////////////////////////////////////////////////////////////////////////////////////
unsigned char DS1302_ByteRead()
{
	unsigned char mask, dat = 0;
	DS1302_IO = 1;                              //�ͷ���������
	for(mask = 0x01; mask != 0; mask <<= 1)
		{
			if(DS1302_IO)                       //��λ��ȡ����
                dat |= mask;
			DS1302_CK = 1;                      //����ʱ���ź�
			DS1302_CK = 0;
		}
	return dat;
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_SingleRead
*�������ܣ���DS1302���Ͷ�ȡ�����������һ��unsigned char�͵�����
*�����б�
*   ddr
*       �������ͣ�unsigned char������
*       �����������Ĵ�����ַ����������ֲ�
*����ֵ��һ��unsigned char�ͱ�������ȡ��������
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��9��
*////////////////////////////////////////////////////////////////////////////////////
unsigned char DS1302_SingleRead(unsigned char addr)
{
	unsigned char dat;
	EA = 0;                                 //�ر��ж�
	DS1302_CE = 1;                          //ʹ��DS1302
	DS1302_ByteWrite(0x81 | (addr << 1));   //���Ͷ�ȡ�����ַ
	dat = DS1302_ByteRead();                //��DS1302��ȡ����
	DS1302_CE = 0;                          //����DS1302
	EA = 1;                                 //ʹ���ж�
	return dat;                             //���ض�ȡ��������
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_SingleWrite
*�������ܣ���DS1302����д���������дһ��unsigned char�͵�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫд�������
*   addr
*       �������ͣ�unsigned char������
*       �����������Ĵ�����ַ����������ֲ�
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��9��
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_SingleWrite(unsigned char addr, unsigned char dat)
{
	EA = 0;                                 //�ر��ж�
	DS1302_CE = 1;                          //ʹ��DS1302
	DS1302_ByteWrite(0x80 | (addr << 1));   //����д�������ַ
	DS1302_ByteWrite(dat);                  //����Ҫд�������
	DS1302_CE = 0;                          //����DS1302
	EA = 1;                                 //ʹ���ж�
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_Write
*�������ܣ�DS1302Brustģʽд��
*�����б�
*   time
*       �������ͣ�struct DS1302_Time���μ�DS1302.h��
*       ����������Ҫд���ʱ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��9��
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_Write(struct DS1302_Time time)
{
	unsigned char i, dat[8] = {0x00};

	dat[0] = time.sec % 10 + time.sec / 10 * 16;
	dat[1] = time.min % 10 + time.min / 10 * 16;
	dat[2] = (time.hour % 10 + time.hour / 10 * 16) | 0x80;
	dat[3] = time.day % 10 + time.day / 10 * 16;
	dat[4] = time.month % 10 + time.month / 10 * 16;
	dat[5] = time.week % 10 + time.week / 10 * 16;
	dat[6] = time.year % 10 + time.year / 10 * 16;
	//��ָ�������ݴ���ΪDS1302��ʶ��ĸ�ʽ

	EA = 0;                         //�ر��жϣ���ֹд�뱻���
	DS1302_CE = 1;                  //ʹ��DS1032
	DS1302_SingleWrite(7, 0x00);    //���DS1302д����
	DS1302_ByteWrite(0xBE);         //��DS1302����Burst Writeָ��
	for(i = 0; i < 8; i ++)         //��λд������
		DS1302_ByteWrite(dat[i]);
	DS1302_CE = 0;                  //����DS1302
	EA = 1;                         //ʹ���ж�
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_Read
*�������ܣ�DS1302Brustģʽ��ȡ
*�����б�
*   time
*       �������ͣ�struct DS1302_Time ��ָ�루�μ�DS1302.h��
*       ������������ȡ����ʱ���ŵ�λ�á�
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��9��
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_Read(struct DS1302_Time *time)
{
	unsigned char i, dat[8] = {0};
	EA = 0;                                 //�ر��жϣ���ֹ��ȡ�����
	DS1302_CE = 1;                          //ʹ��DS1302
	DS1302_ByteWrite(0xBF);                 //��DS1302����Burst Readָ��
	for(i = 0; i < 8; i ++)
		{
			dat[i] = DS1302_ByteRead();     //��ȡDS1302���ص�����
			EA = 1;
			Delay1ms();                     //��ʱ1ms����ʱ�ָ��ж�
			EA = 0;
		}
	DS1302_IO = 0;                          //����DS1302��������
	DS1302_CE = 0;
	EA = 1;                                 //ʹ���ж�

	//�Զ�ȡ������Ϣ���д�������ָ���ı����С�
	*time.sec = dat[0] %16 + dat[0] / 16 * 10;
	*time.min = dat[1] %16 + dat[1] / 16 * 10;
	*time.hour = (dat[2] %16 + dat[2] / 16 * 10) & 0x7F;
	*time.day = dat[3] %16 + dat[3] / 16 * 10;
	*time.month = dat[4] %16 + dat[4] / 16 * 10;
	*time.week = dat[5] %16 + dat[5] / 16 * 10;
	*time.year = dat[6] %16 + dat[6] / 16 * 10;
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_Init
*�������ܣ�DS1302��ʼ��
*�����б�
*   ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��9��
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_Init()
{
	DS1302_CE = 0;                  //����DS1302�������ߵ�ƽ
	DS1302_CK = 0;
	DS1302_IO = 1;
	DS1302_SingleWrite(7, 0x00);    //���д����
}
