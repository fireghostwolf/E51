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
	2014��12��11��
	����������PCF8591 AD/DAоƬ�򵥿���
	��ע��ʹ�ø�ģ�飬����config.h�ж���IIC_SDA_SET_PCF8591����ΪPCF8591��IIC���ߵ�SDA���ݽӿڡ�
          �� #define IIC_SDA_SET_PCF8591 P0^0
          ʹ�ø�ģ�飬����config.h�ж���IIC_SDA_SET_PCF8591����ΪPCF8591��IIC���ߵ�SCL���ݽӿڡ�
          �� #define IIC_SDA_SCL_PCF8591 P0^1
*////////////////////////////////////////////////////////////////////////////////////////
#include<reg51.h>
#include<IIC_PCF8591.h>
bit PCF8591_DA_Flag = 0;	//DA�����Ƿ�򿪱�־λ
/*///////////////////////////////////////////////////////////////////////////////////
*��������Delay10ms
*�������ܣ���ʱ10����
*�����б�
*   ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��5��21��
*////////////////////////////////////////////////////////////////////////////////////
void Delay10ms()		//@33.1776MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 2;
	j = 67;
	k = 183;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

/*///////////////////////////////////////////////////////////////////////////////////
*��������PCF8591_Read
*�������ܣ���ȡADת���õ���ֵ����ͨת�����ǲ�֣�
*�����б�
*   channel
*       �������ͣ�unsigned char������
*       ����������ͨ����
*����ֵ��һ��unxigned char�����ݣ�ADֵ
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��11��
*////////////////////////////////////////////////////////////////////////////////////
unsigned char PCF8591_Read(unsigned char channel)
{
	unsigned char dat;
	IIC_Start_PCF8591();            	//��PCF8591��IIC���߷���ͨ����ʼ�ź�
	IIC_Write_PCF8591(0x90);        	//��PCF8591��IIC���߷���һλ���ݣ���ַ�����֣�������Ҫ����ʵ��������ģ�����ѡ��д����
	if(PCF8591_DA_Flag)					//��PCF8591��IIC���߷���һλ���ݣ�Ҫ��ȡ��Ƶ��������DA�����Ƿ�򿪵��жϣ���ֹ�������
		IIC_Write_PCF8591(channel + 0x40);	
	else IIC_Write_PCF8591(channel);		
	IIC_Stop_PCF8591();             	//��PCF8591��IIC���߷���ͨ�Ž����ź�
	
	Delay10ms();
	
	IIC_Start_PCF8591();            	//��PCF8591��IIC���߷���ͨ����ʼ�ź�
	IIC_Write_PCF8591(0x91);        	//��PCF8591��IIC���߷���һλ���ݣ���ַ�����֣�������Ҫ����ʵ��������ģ�����ѡ�������
	IIC_Read_PCF8591(0);
	dat = IIC_Read_PCF8591(1);      	//��PCF8591��IIC���߶�ȡһλ���ݣ�������NAK
	IIC_Stop_PCF8591();             	//��PCF8591��IIC���߷���ͨ�Ž����ź�
	return dat;
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������PCF8591_DA
*�������ܣ�����PCF8591��DA���
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ�����DAֵ
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2014��12��11��
*////////////////////////////////////////////////////////////////////////////////////
void PCF8591_DA(unsigned char dat)
{
	PCF8591_DA_Flag = 1;
	IIC_Start_PCF8591();        //��PCF8591��IIC���߷���ͨ����ʼ�ź�
	IIC_Write_PCF8591(0x90);    //��PCF8591��IIC���߷���һλ���ݣ���ַ�����֣�������Ҫ����ʵ��������ģ�����ѡ��д����
	IIC_Write_PCF8591(0x40);    //��PCF8591��IIC���߷���һλ���ݣ�����DAת������
	IIC_Write_PCF8591(dat);     //��PCF8591��IIC���߷���һλ���ݣ�Ҫת���Ĳ���ֵ
	IIC_Stop_PCF8591();         //��PCF8591��IIC���߷���ͨ�Ž����ź�
}
