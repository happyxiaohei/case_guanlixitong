#pragma once            //��ֹͷ�ļ��ظ�����
# include<iostream>     //�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include<string>
#include"worker.h"
//
//��ͨԱ���ļ�

class Employee :public Worker

{
	
public:

	//��ʼ��ÿ��Ա��������
	//���캯��


	Employee(int id,string name,int dId);
//
//
	//��ʾ������Ϣ

	virtual void showInfo();
//
	//��ȡ��λ����

	//virtual string gerDeptName();
	virtual string getDeptName();

};
