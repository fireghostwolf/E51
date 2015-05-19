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

    �ļ�����SPI_Analog.h
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  admin@hxlxz.com
	����������SPIͨ�ŵ�IO��ģ��ʵ��-ͷ�ļ�
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
#ifndef _HEAD_SPI_Analog_
#define _HEAD_SPI_Analog_

#include<intrins.h>
#include<config.h>

/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Init
*�������ܣ�SPI��ʼ��������ģʽʹ�ã�
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Init();
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Write
*�������ܣ�SPI��ģʽ������һλunsigned char �͵�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ���͵�����
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Write(unsigned char dat);
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Read
*�������ܣ�SPI��ģʽ����ȡһλunsigned char �͵�����
*����ֵ��һ��unsigned char�����ݣ���ȡ�������ݡ�
*////////////////////////////////////////////////////////////////////////////////////
unsigned char SPI_Read();
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Slave_Send
*�������ܣ�SPI��ģʽ����Ӧһλunsigned char �͵�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ�ظ�������
*////////////////////////////////////////////////////////////////////////////////////
void SPI_Slave_Send(unsigned char dat);
/*///////////////////////////////////////////////////////////////////////////////////
*��������SPI_Slave_Resive
*�������ܣ�SPI��ģʽ������һλunsigned char �͵�����
*����ֵ��һ��unsigned char�����ݣ����յ������ݡ�
*////////////////////////////////////////////////////////////////////////////////////
unsigned char SPI_Slave_Resive();
#endif // _HEAD_SPI_Analog_
