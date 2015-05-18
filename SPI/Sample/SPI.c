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
bit IS_Master = 0;  //SPI���� ��־
sbit SS = P1^2;     //����SPIʹ������
unsigned char DataToSend = 0xFF;	//�ӻ������������ݴ���
#define Disable_0xFF 1
//�����Ƿ����ν��յ���0xFF ע�⣺���ȡ�����Σ������û�������DataResive�������жϽ��յ���0xFF�Ƿ�Ϊ��Ч�����ݡ�
void DataResive(unsigned char dat);
//�����յ����ݣ����Զ����øú��������û����б�д����ע�⣺0xFFĬ������²��������Ϸ������ݣ�������
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Read
*�������ܣ�SPI����ģʽ����ȡһλunsigned char������
*�����б�
*   ��
*����ֵ����
*��ע����ȡ�����ݺ󣬻�����û����б�д��DataResive�������ӻ�ģʽ�£��˺��������á����ӻ��յ����ݻ��Զ�����DataResive������
*�汾��1.0
*���ߣ�������
*���ڣ�2015��5��18��
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Read()
{
    if(IS_Master == 1)  //�����SPI����ģʽ
    {
        SPI_Send(0xFF);	//���ﲻ�Ƿ����źţ����ǲ���һ��SPI��ȡ��SCLKʱ��
    }
}
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
    if(IS_Master == 1)  //�����SPI����ģʽ
    {
        SS = 0;         //ʹ�ܴӻ�
		SPDAT = dat;    //��������
    }
    else 
	{
		SPDAT = dat;   //����Ǵӻ�ģʽ����Ҫ���͵����ݷ����ݴ������ȴ�����ʹ���ź�
		DataToSend = dat;
	}
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
	SPSTAT = 0xB0;          	//���SPI״̬��־
	if(IS_Master == 1)      	//���������ģʽ
    {
		SS = 1;             	//����SPI�ӻ�
		#if Disable_0xFF
		if(SPDAT != 0xFF)
		#endif
			DataResive(SPDAT);  //�������յ������ݣ������û��Զ���ĺ���
    }
    else
    {
		#if Disable_0xFF
		if(SPDAT != 0xFF)
		{
			DataResive(SPDAT);  //�������յ������ݣ������û��Զ���ĺ���
		}
		else SPDAT = DataToSend;
		#else
		DataResive(SPDAT);  //�������յ������ݣ������û��Զ���ĺ���
		#endif
			
    }
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Init
*�������ܣ�SPI��ʼ��
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
	if(mode == 1)       //���������ģʽ
    {
        SPCTL = 0xD0;   //����SPI����Ϊ����
        IS_Master = 1;  //����������־
    }
	else
		SPCTL = 0x40;   //����SPI����Ϊ�ӻ�
	if(cpol == 1)       //����CPOL����
		SPCTL |= 0x08;
	if(cpha == 1)       //����CPHA����
		SPCTL |= 0x04;
	EA = 1;             //ʹ�����ж�
	IE2 |= 0x02;        //ʹ��SPI�ж�
}
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Close
*�������ܣ��ر�SPI
*�����б�
*   ��
*����ֵ����
*�汾��1.0
*���ߣ�������
*���ڣ�2015��5��18��
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Close()
{
    SPCTL = 0x00;
    IE2 &= 0xFD;
}
