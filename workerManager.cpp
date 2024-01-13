# include<iostream>
using namespace std;

#include<string>
#include"workerManager.h"


workerManager::workerManager()
{

	//1.�ļ�������
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //���ļ�

	if (!ifs.is_open())
	{

		//cout << "�ļ�������!!" << endl;

		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		//�ر��ļ�
		ifs.close();

		return;
	}

	//2.�ļ�����,����Ϊ��

	char ch;
	ifs>> ch;
	if (ifs.eof())  //eof�����ȡ�ļ�����ֱ�Ӷ�ȡĩβ���ַ�   
		           // ����ֱ�Ӷ���ĩβ���ַ��ʹ����ļ��������Ϊ��
	{

		//�ļ�Ϊ��

		//cout << "�ļ�Ϊ��" << endl;

		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		//�ر��ļ�
		ifs.close();

		return;
		
	}

	//3.�ļ�����,���Ҽ�¼����

	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ:  " << num << endl;

	this->m_EmpNum = num;


	//���� �ռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//���ļ��е�����,�浽������

	this->intt_Emp();
	
	
	//�����ǲ��Դ���
	// 
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{

	//	cout << "ְ�����:  " << this->m_EmpArray[i]->m_Id << "  "
	//		<< "ְ������:  " << this->m_EmpArray[i]->m_Nane << "  "
	//		<< "���ű�� :  " << this->m_EmpArray[i]->m_DeptId << endl;
	//}




}

void workerManager::Show_Menu()  //չʾ�˵�
{

	cout << "************************************" << endl;
	cout << "****** ��ӭʹ��ְ������ϵͳ ********" << endl;
	cout << "******** 0.�˳�������� ************" << endl;
	cout << "******** 1.����ְ����Ϣ ************" << endl;
	cout << "******** 2.��ʾְ����Ϣ ************" << endl;
	cout << "******** 3.ɾ����ְְ�� ************" << endl;
	cout << "******** 4.�޸�ְ����Ϣ ************" << endl;
	cout << "******** 5.����ְ����Ϣ ************" << endl;
	cout << "******** 6.���ձ������ ************" << endl;
	cout << "******** 7.��������ĵ� ************" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void workerManager::ExitSystem()  //�˳�ϵͳ
{

	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);  //���д������˼���˳�����
}


void workerManager::Add_Emp()  //���ְ��
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;  //�����û����������
	cin >> addNum;
	
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ����� = ԭ����¼���� + ��������

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ��µ�����,�������¿ռ���

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				
				newSpace[i] = this->m_EmpArray[i];

			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{

			int id; // ְ�����
			string name;  //ְ������
			int dSelect;  //����ѡ��
			
			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;
			
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;
			
			cout << "��ѡ���ְ����λ:  " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			
			cin >> dSelect;
			
			
	
			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;

			case 2:
				worker = new Manager(id, name, 2);
				break;

			case 3:
				worker = new Boss(id, name, 3);
				break;
	

			default:
				break;
			}
			





			//������ְ��ָ��,���浽������
			newSpace[this->m_EmpNum + i] = worker;

		}

			//�ͷ�ԭ�еĿռ�

			delete[]this->m_EmpArray;

			//�����¿ռ��ָ��

			this->m_EmpArray = newSpace;

			//�����µ�ְ������

			this->m_EmpNum = newSize;

			//�ɹ���Ӻ�,���浽�ļ���

			this->save();

			//�����ļ����ݲ�Ϊ�յı�־
			this->m_FileIsEmpty = false;

			//��ʾ��ӳɹ�

			cout << "�ɹ����" << addNum << "����ְ��!" << endl;


	}

	else
	{

		cout << "���������������." << endl;
	}
	
	//��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}


//�����ļ�
void workerManager::save()
{

	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //������ķ�ʽ���ļ�  -- д�ļ�

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{

		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Nane << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();

}

//ͳ���ļ�������

int workerManager::get_EmpNum()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //���ļ�  ��ȡ����

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		//ͳ������
		num++;

	}

	return num;
}

//��ʼ��Ա��

void workerManager::intt_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//��ְͨ��
		{

			worker = new Employee(id, name, dId);

		}
		else if (dId == 2)//��ְͨ��
		{

			worker = new Manager(id, name, dId);

		}
		else  //�ϰ�
		{
			worker = new Boss(id, name, dId);

		}

		this->m_EmpArray[index] = worker;
		index++;
		
	}
 
	ifs.close();  //�ر��ļ�

}

//��ʾְ��

void workerManager::Show_Emp()
{

	//�ж��ļ��Ƿ�Ϊ��

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{

		for (int i = 0; i < m_EmpNum; i++)
		{

			//���ö�̬���ó���ӿ�

			this->m_EmpArray[i]->showInfo();


		}
	}
	system("pause");
	system("cls");


}

//ɾ��ְ��
void workerManager::Del_Enp()
{
	if (this->m_FileIsEmpty)
	{

		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{

		//����ְ�����ɾ��

		cout << "��������Ҫ���ְ�����:  " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//˵��ְ������,����Ҫɾ����indexλ���ϵ�ְ��

		{
			for (int i = index; i<this->m_EmpNum - 1; i++)
			{

				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			//���������м�¼��Ա����
			this->m_EmpNum--;

			//ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{

			cout << "ɾ��ʧ��,δ�ҵ���ְ��!" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����,������ڷ���ְ�����������λ��,�����ڷ���-1
int workerManager::IsExist(int id)
{

	int index = -1;

	for (int i = 0;i<this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{

			index = i;

			break;
		}

	}
	return index;
}


workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;

	}
}