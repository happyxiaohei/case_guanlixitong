# include<iostream>
using namespace std;
#include"workerManager.h"



int main() {

	//����ļ������ļ�

	//ʵ���������߶���
	workerManager wm;

	//����չʾ�˵���Ա����

	//wm.Show_Menu();  //������  //7

	//�����û����빦��

	int choice = 0; //�����洢�û���ѡ��  

	//չʾ�˵�
	while (true)

	{
		//����չʾ�˵���Ա���� 
		wm.Show_Menu();

		cout << "�����뽫Ҫ������ѡ��:" << endl;
		cin >> choice;
		//cin.clear();
		//cin.ignore();//��������Ϊ�˽���û�������ַ��������ֵ�����   

		switch (choice)
		{
		case 0 ://�˳�ϵͳ

			wm.ExitSystem();
			break;
		case 1://����ְ��
			break;
		case 2://��ʾְ��
			break;
		case 3://ɾ��ְ��
			break;
		case 4://�޸�ְ��
			break;
		case 5://����ְ��
			break;
		case 6://����ְ��
			break;
		case 7://���ְ��
			break;

		default:
			system("cls"); //ˢ����Ļ
			break;
		}
	}




	system("pause");

	return 0;

}