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

	�ļ�����IIC.h
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  admin@hxlxz.com
	�����������õ�Ƭ��IO��ģ��ʵ��IICͨ��-ͷ�ļ�
	��ע��ʹ�ø�ģ�飬���ڳ����ж���IIC_SDA����ΪIIC���ߵ�SDA���ݽӿڡ�
          �� #define IIC_SDA_SET P0^0
          ʹ�ø�ģ�飬���ڳ����ж���IIC_SCL����ΪIIC���ߵ�SCL���ݽӿڡ�
          �� #define IIC_SCL_SET P0^1
*////////////////////////////////////////////////////////////////////////////////////////
#ifndef _HEAD_IIC_
#define _HEAD_IIC_

#include<intrins.h>
#include<config.h>

/*///////////////////////////////////////////////////////////////////////////////////
*��������IIC_Start
*�������ܣ�����IIC������ʼ�ź�
*////////////////////////////////////////////////////////////////////////////////////
void IIC_Start();
/*///////////////////////////////////////////////////////////////////////////////////
*��������IIC_Stop
*�������ܣ�����IIC����ֹͣ�ź�
*////////////////////////////////////////////////////////////////////////////////////
void IIC_Stop();
/*///////////////////////////////////////////////////////////////////////////////////
*��������IIC_Write
*�������ܣ���IIC���߷���һ��unsigned char������
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ���͵�����
*����ֵ��һ��bit�������Ƿ�������ɲ�����1��������0���쳣��
*////////////////////////////////////////////////////////////////////////////////////
bit IIC_Write(unsigned char dat);
/*///////////////////////////////////////////////////////////////////////////////////
*��������IIC_Read
*�������ܣ���IIC���߶�ȡһ��unsigned char������
*�����б�
*   ACK
*       �������ͣ�bit������
*       �������������ݶ�ȡ�������͵�Ӧ��λ���Ӧ��λ
*����ֵ��һ��unsigned char�ͱ�������ȡ��������
*////////////////////////////////////////////////////////////////////////////////////
unsigned char IIC_Read(bit ACK);

#endif // _HEAD_IIC_
