#pragma once  //��ֹͷ�ļ��ظ�����
# include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"



class workerManager
{
public:

	//���캯��
	workerManager();

	//չʾ�˵�
	void Show_Menu();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�˳�ϵͳ
	void ExitSystem();

	//��������
	~workerManager();

};
                                     