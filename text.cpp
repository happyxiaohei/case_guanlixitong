#pragma once            //��ֹͷ�ļ��ظ�����
# include<iostream>     //�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include<string>


#include"workerManager.h"

#include"worker.h"      //��ӳ�����ͷ�ļ�
#include"employee.h"    //���Ա�����ļ�
#include"manager.h"		//��Ӿ������ļ�	
#include"boss.h"		//����ϰ����ļ�

int main2() {


	Worker* worker = NULL;
	worker = new Employee(1, "����", 2);

	worker->showInfo();

	delete worker;


	worker = new Manager(2, "����", 3);
	worker->showInfo();
	delete worker;

	worker = new Boss(4, "�ϰ�", 6);
	worker->showInfo();
	delete worker;


	system("pause");

	return 0;

}