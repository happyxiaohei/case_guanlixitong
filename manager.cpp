//#pragma once            //��ֹͷ�ļ��ظ�����
//# include<iostream>     //�������������ͷ�ļ�
//using namespace std;	//ʹ�ñ�׼�����ռ�
//#include<string>


#include"manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Nane = name;
	this->m_DeptId = dId;

}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����:  " << this->m_Id
		<< "\tְ������:  " << this->m_Nane
		<< "\t��λ:  " << this->getDeptName()
		<< "\t��λְ��: ����ϰ彻��������,���·������Ա�� " << endl;

}
//��ȡ��λ����
string  Manager::getDeptName()
{
	return string("����");

}

