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
*////////////////////////////////////////////////////////////////////////////////////////
#ifndef _HEAD_PCF8591_
#define _HEAD_PCF8591_

#include<intrins.h>
#include<config.h>
/*///////////////////////////////////////////////////////////////////////////////////
*��������PCF8591_Read
*�������ܣ���ȡADת���õ���ֵ����ͨת�����ǲ�֣�
*�����б�
*   chanl
*       �������ͣ�unsigned char������
*       ����������ͨ����
*����ֵ��һ��unxigned char�����ݣ�ADֵ
*////////////////////////////////////////////////////////////////////////////////////
unsigned char PCF8591_Read(unsigned char chanl);
/*///////////////////////////////////////////////////////////////////////////////////
*��������PCF8591_DA
*�������ܣ�����PCF8591��DA���
*�����б�
*   dat
*       �������ͣ�unsigned char������
*       ����������Ҫ�����DAֵ
*////////////////////////////////////////////////////////////////////////////////////
void PCF8591_DA(unsigned char dat);

#endif
