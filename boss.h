#pragma once            //��ֹͷ�ļ��ظ�����
# include<iostream>     //�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include<string>

#include"worker.h"


//�������ļ�
class Boss :public Worker
{

public:

	Boss(int id, string name, int dId);


	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string  getDeptName();

};