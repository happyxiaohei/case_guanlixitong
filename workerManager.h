#pragma once  //��ֹͷ�ļ��ظ�����
# include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"  //�����ļ����ǿ����Զ����


class workerManager
{
public:

	//���캯��
	workerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��  ��־
	
	bool m_FileIsEmpty;

	//ͳ���ļ�������

	int get_EmpNum();

	//��ʼ��Ա��
	
	void intt_Emp();

	//��ʾְ��
 
	void Show_Emp();

	//ɾ��ְ��
	void Del_Enp();

	//�ж�ְ���Ƿ����,������ڷ���ְ�����������λ��,�����ڷ���-1
	int IsExist(int id);

	//��������
	~workerManager();

};
                                     