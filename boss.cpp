//#pragma once            //��ֹͷ�ļ��ظ�����
//# include<iostream>     //�������������ͷ�ļ�
//using namespace std;	//ʹ�ñ�׼�����ռ�
//#include<string>


#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Nane = name;
	this->m_DeptId = dId;

}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����:  " << this->m_Id
		<< "\tְ������:  " << this->m_Nane
		<< "\t��λ:  " << this->getDeptName()
		<< "\t��λְ��: ����˾���е����� " << endl;

}
//��ȡ��λ����
string  Boss::getDeptName()
{
	return string("�ϰ�");

}

