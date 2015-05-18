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
	��������:SPIͨ��ģ��-ͷ�ļ�
	��ע:�������ڴ���SPI���ܵ�STC15ϵ�е�Ƭ��
*////////////////////////////////////////////////////////////////////////////////////////
#ifndef _HEAD_SPI_
#define _HEAD_SPI_

#include<intrins.h>
#include<config.h>
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Read
*�������ܣ�SPI����ģʽ����ȡһλunsigned char������
*��ע����ȡ�����ݺ󣬻�����û����б�д��DataResive�������ӻ�ģʽ�£��˺��������á����ӻ��յ����ݻ��Զ�����DataResive������
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Read();
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Send
*�������ܣ�SPI����һλunsigned char �͵�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ���͵�����
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Send(unsigned char dat);
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Init
*�������ܣ�SPI�жϺ���
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
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Init(bit cpha, bit cpol, bit mode);
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Close
*�������ܣ��ر�SPI
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Close();
#endif
