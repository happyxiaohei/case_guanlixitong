#pragma once            //��ֹͷ�ļ��ظ�����
# include<iostream>     //�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include<string>
#include"employee.h"

	//��ʼ��ÿ��Ա��������
	//���캯��


	Employee::Employee(int id, string name, int dId)
	{

		this->m_Id = id;
		this->m_Nane = name;
		this->m_DeptId = dId;


	}

	//��ȡ��λ����

	//��ʾ������Ϣ

	void Employee::showInfo()
	{
		cout << "ְ�����:  " << this->m_Id
			<< "\tְ������:  " << this->m_Nane
			<< "\t��λ:  " << this->getDeptName()
			<< "\t��λְ��:  ��ɾ�����������" << endl;

	}



	string  Employee::getDeptName()
	{

		return string("Ա��");
	}



