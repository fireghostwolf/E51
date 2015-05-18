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
	���������������ַ���ͨ��ģ���Sample����
*////////////////////////////////////////////////////////////////////////////////////////
#include<reg52.h>
#include<UART.h>
#include<config.h>
unsigned char T0H, T0L;		//��ʱ�������洢����
void Timer0_Init(unsigned char ms);
void UART_Action(unsigned char *dat, unsigned char len)
{
	unsigned char pdata msg[64] = "";		//�յ�����Ϣ���ݴ�����
	unsigned char i;
	for(i = 0;i < len;i ++)					//���յ�����Ϣ�ŵ��ݴ�����
	{
		msg[i] = *dat;
		dat ++;
	}
	UART_SendString("I've received ", 14);	//����"I've received "
	UART_SendString(msg, len);				//���յ�����Ϣ���͵�����
	UART_SendString("\n", 1);				//���ͻ��з�
}

int main()
{
	UART_Conf(9600);		//���ô��ڲ�����Ϊ9600
	Timer0_Init(1);			//���ö�ʱ���жϷ���Ƶ��Ϊ1msһ��
	UART_SendString("This is a demo program.\n", 24);	//����"This is a demo program.\n"
	while(1)
	{
		UART_Driver();		//��ش���
	}
}
void Timer0_Init(unsigned char ms)
{
	unsigned int temp;						//���ڼ�����м����
	temp = 65536 - ms * XTAL * 1000 / 12;	//���㶨ʱ����ֵ��������ϰ�߼Ĵ���
	T0H = (unsigned char)(temp >> 8);
	T0L = (unsigned char)(temp);
	TH0 = T0H;
	TL0 = T0L;
	TMOD &= 0XF0;							//���ö�ʱ������ģʽΪģʽ1
	TMOD |= 0X01;
	ET0 = 1;								//ʹ�ܶ�ʱ��0�ж�
	TR0 = 1;								//ʹ�ܶ�ʱ��0
}
void Interrupt_Timer0() interrupt 1
{
	TH0 = T0H;				//��ʱ���Ĵ�������ֵ
	TL0 = T0L;
	UART_RxMonitor(1);		//����ͨ�ż��
}
