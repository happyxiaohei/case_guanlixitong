#pragma once            //��ֹͷ�ļ��ظ�����
# include<iostream>     //�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include<string>


#include"workerManager.h"

#include"worker.h"      //��ӳ�����ͷ�ļ�
#include"employee.h"    //���Ա�����ļ�
#include"manager.h"		//��Ӿ������ļ�	
#include"boss.h"		//����ϰ����ļ�

//int main2() {
//
//
//	Worker* worker = NULL;
//	worker = new Employee(1, "����", 2);
//
//	worker->showInfo();
//
//	delete worker;
//
//
//	worker = new Manager(2, "����", 3);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(4, "�ϰ�", 6);
//	worker->showInfo();
//	delete worker;
//
//
//	system("pause");
//
//	return 0;
//
//}

//void workerManager::Add_Emp()  //���ְ��
//
//{
//
//	cout << "���������ְ������:  " << endl;
//
//	int addNum = 0;  //�����û����������
//	cin >> addNum;
//
//
//	if (addNum > 0)
//	{
//
//		//���
//		//��������¿ռ��С
//
//		int newSize = this->m_EmpNum + addNum;//�¿ռ����� = ԭ����¼���� + ��������
//
//		//�����¿ռ�
//		Worker** newSpace = new Worker * [newSize];
//
//		//��ԭ���ռ��µ�����,�������¿ռ���
//
//		if (this->m_EmpArray != NULL)
//		{
//
//			for (int i = 0; i < this->m_EmpNum; i++)
//			{
//
//				newSpace[i] = this->m_EmpArray[i];
//			}
//
//		}
//
//
//			//�������������
//
//		for (int i = 0; i < addNum; i++)
//		{
//
//				int id; // ְ�����
//				string name;  //ְ������
//				int dSelect;  //����ѡ��
//
//				cout << "�������" << i + 1 << "����ְ�����:" << endl;
//				cin >> id;
//
//				cout << "�������" << i + 1 << "����ְ������:" << endl;
//				cin >> name;
//
//				cout << "��ѡ���ְ����λ:  " << endl;
//				cout << "1.��ְͨ��" << endl;
//				cout << "2.����" << endl;
//				cout << "3.�ϰ�" << endl;
//
//				cin >> dSelect;
//
//				Worker* worker = NULL;
//
//				switch (dSelect)
//				{
//				case 1:
//					worker = new Employee(id, name, 1);
//
//				case 2:
//					worker = new Manager(id, name, 2);
//
//				case 3:
//					worker = new Boss(id, name, 3);
//
//				default:
//					break;
//				}
//
//				
//				newSpace[this->m_EmpNum + i] = worker;
//
//
//
//		}
//
//			//�ͷ�ԭ�еĿռ�
//
//			delete[]this->m_EmpArray;
//
//			//�����¿ռ��ָ��
//
//			this->m_EmpArray = newSpace;
//
//			//�����µ�ְ������
//
//			this->m_EmpNum = newSize;
//
//
//			//��ʾ��ӳɹ�
//
//			cout << "�ɹ����" << addNum << "����ְ��!" << endl;
//
//
//	}

//}
//
//    