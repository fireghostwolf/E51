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
	�����������õ�Ƭ��IO��ģ��ʵ��IICͨ��-Sample����
	��ע�����ڳ�����Լ򵥣��ʲ��ṩ��ϸע��
*////////////////////////////////////////////////////////////////////////////////////////
#include"reg52.h"
#include"IIC.h"
void Delay500ms();
int main()
{
	unsigned char i = 0;
	while(1)
	{
		i ++;
		IIC_Start();
		IIC_Write(i);
		IIC_Stop();
		Delay500ms();
	}
}
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
