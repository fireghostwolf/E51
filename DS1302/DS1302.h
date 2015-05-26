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
#ifndef _HEAD_DS1302_
#define _HEAD_DS1302_

#include<intrins.h>
#include<config.h>
struct DS1302_Time{         //����ʱ��ṹ��
    unsigned char year;     //ʱ���꣨��ʹ��ʮ���Ʊ�ʾ��
    unsigned char month;    //ʱ���£���ʹ��ʮ���Ʊ�ʾ��
    unsigned char day;      //ʱ���գ���ʹ��ʮ���Ʊ�ʾ��
    unsigned char week;     //����  ����ʹ��ʮ���Ʊ�ʾ��
	unsigned char hour;     //ʱ��ʱ����ʹ��ʮ���Ʊ�ʾ��
	unsigned char min;      //ʱ��֣���ʹ��ʮ���Ʊ�ʾ��
	unsigned char sec;      //ʱ���루��ʹ��ʮ���Ʊ�ʾ��
};

/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_SingleRead
*�������ܣ���DS1302���Ͷ�ȡ�����������һ��unsigned char�͵�����
*�����б�
*   ddr
*       �������ͣ�unsigned char������
*       �����������Ĵ�����ַ����������ֲ�
*����ֵ��һ��unsigned char�ͱ�������ȡ��������
*////////////////////////////////////////////////////////////////////////////////////
unsigned char DS1302_SingleRead(unsigned char addr);
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
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_SingleWrite(unsigned char addr, unsigned char dat);
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_Write
*�������ܣ�DS1302Brustģʽд��
*�����б�
*   time
*       �������ͣ�struct DS1302_Time���μ�DS1302.h��
*       ����������Ҫд���ʱ��
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_Write(struct DS1302_Time time);
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_Read
*�������ܣ�DS1302Brustģʽ��ȡ
*�����б�
*   time
*       �������ͣ�struct DS1302_Time ��ָ�루�μ�DS1302.h��
*       ������������ȡ����ʱ���ŵ�λ�á�
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_Read(struct DS1302_Time *time);
/*///////////////////////////////////////////////////////////////////////////////////
*��������DS1302_Init
*�������ܣ�DS1302��ʼ��
*////////////////////////////////////////////////////////////////////////////////////
void DS1302_Init();

#endif // _HEAD_DS1302_
