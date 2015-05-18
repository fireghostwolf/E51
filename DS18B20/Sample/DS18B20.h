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

	�ļ�����DS18B20.h
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  admin@hxlxz.com
	����������DS18B20�¶ȴ������ļ򵥲�������ģ���ͷ�ļ�
	��ע������ʹ�÷�װ�õĺ������в���������Ҫʹ��ֱ�Ӷ�DS18B20��д�ĺ�����
          ʹ�ø�ģ�飬����config.h�ж���DS18B20_IO_SET����ΪDS18B20�����ݽӿڡ�
          �� #define DS18B20_IO_SET P0^0
          ʹ�ø�ģ�飬����config.h�ж���STC_YX����ΪSTC��Ƭ��ָ����ơ�
          �� #define STC_YX "STC_Y5"
          ʹ�ø�ģ�飬����config.h�ж���XTAL����Ϊ����Ƶ��
          �� #define XTAL 11.059200
*////////////////////////////////////////////////////////////////////////////////////////
#ifndef _HEAD_DS18B20_
#define _HEAD_DS18B20_

#include<intrins.h>
#include<config.h>

/*///////////////////////////////////////////////////////////////////////////////////
*��������DS18B20_GetTemp
*�������ܣ���ȡDS18B20������¶ȡ�
*�����б�
*   *addr
*       �������ͣ�unsigned char��ָ�루����8��unsigned char�����ݣ�
*       ����������64�ֽڵ�������š��ر�ģ�Skip ROMʱaddr[0]�봫��0x00
*����ֵ��һ��double�ͱ�������ȡ�����¶�ֵ������������ʱ������-999��
*////////////////////////////////////////////////////////////////////////////////////
double DS18B20_GetTemp(unsigned char *addr);
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS18B20_Start
*�������ܣ�����18B20�¶�ת����
*�����б�
*   *addr
*       �������ͣ�unsigned char��ָ�루����8��unsigned char�����ݣ�
*       ����������64�ֽڵ�������š��ر�ģ�Skip ROMʱaddr[0]�봫��0x00
*����ֵ��һ��bit�ͱ����������Ƿ�������1��������0��ʧ�ܣ�
*////////////////////////////////////////////////////////////////////////////////////
bit DS18B20_Start(unsigned char *addr);
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS18B20_Init
*�������ܣ���ʼ��18B20
*����ֵ��һ��bit�ͱ�������ʼ���Ƿ�������1��������0��ʧ�ܣ�
*////////////////////////////////////////////////////////////////////////////////////
bit DS18B20_Init();
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS18B20_Write  ��������Ҫֱ�ӵ��ã�
*�������ܣ���18B20дһ��unsigned char�͵����ݻ�����
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫд������ݻ�����
*////////////////////////////////////////////////////////////////////////////////////
void DS18B20_Write(unsigned char dat);
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS18B20_Read   ������Ҫֱ�ӵ��ã�
*�������ܣ���DS18B20�ж�ȡһλ����
*����ֵ��һ��unsigned char�ͱ�������ȡ��������
*////////////////////////////////////////////////////////////////////////////////////
unsigned char DS18B20_Read();

#endif // _HEAD_DS18B20_


