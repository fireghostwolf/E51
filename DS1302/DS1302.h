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
void DS1302_Init(unsigned char *dat);  //DS1302��ʼ������������������ͷ���ã�dat�����õ�ʱ��
unsigned char DS1302_SingleRead(unsigned char addr); //DS1302���ֽڶ�ȡ��datΪ��ȡ���ݴ洢λ�ã�addrΪ�Ĵ�����ַ����������ֲ�
void DS1302_SingleWrite(unsigned char addr,unsigned char dat);   //DS1302���ֽ�д�룬datΪд�����ݣ�addrΪ�Ĵ�����ַ����������ֲ�
void DS1302_BrustWrite(unsigned char *dat);  //DS1302Brustģʽд�룬datΪuint8�͵�ӵ��8��Ԫ�ص�����
void DS1302_BrustRead(unsigned char *dat);   //DS1302Brustģʽ��ȡ��datΪuint8�͵�ӵ��8��Ԫ�ص�����

#endif // _HEAD_DS1302_
