#pragma once            //��ֹͷ�ļ��ظ�����
# include<iostream>     //�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include<string>

//ְ��������

class Worker
{

public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string  getDeptName() = 0 ;

	//ְ�����
	int m_Id;
	//ְ������
	string m_Nane;
	//���ű��
	int m_DeptId;

};




