# include<iostream>
using namespace std;

#include<string>
#include"workerManager.h"


workerManager::workerManager()
{

	//1.文件不存在
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //读文件

	if (!ifs.is_open())
	{

		//cout << "文件不存在!!" << endl;

		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;

		//初始化数据指针
		this->m_EmpArray = NULL;

		//初始化文件是否为空
		this->m_FileIsEmpty = true;

		//关闭文件
		ifs.close();

		return;
	}

	//2.文件存在,数据为空

	char ch;
	ifs>> ch;
	if (ifs.eof())  //eof代表读取文件内容直接读取末尾的字符   
		           // 假如直接读到末尾的字符就代表文件里的内容为空
	{

		//文件为空

		//cout << "文件为空" << endl;

		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;

		//初始化数据指针
		this->m_EmpArray = NULL;

		//初始化文件是否为空
		this->m_FileIsEmpty = true;

		//关闭文件
		ifs.close();

		return;
		
	}

	//3.文件存在,并且记录数据

	int num = this->get_EmpNum();
	//cout << "职工人数为:  " << num << endl;

	this->m_EmpNum = num;


	//开辟 空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//将文件中的数据,存到数组中

	this->intt_Emp();
	
	
	//这里是测试代码
	// 
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{

	//	cout << "职工编号:  " << this->m_EmpArray[i]->m_Id << "  "
	//		<< "职工姓名:  " << this->m_EmpArray[i]->m_Nane << "  "
	//		<< "部门编号 :  " << this->m_EmpArray[i]->m_DeptId << endl;
	//}




}

void workerManager::Show_Menu()  //展示菜单
{

	cout << "************************************" << endl;
	cout << "****** 欢迎使用职工管理系统 ********" << endl;
	cout << "******** 0.退出管理程序 ************" << endl;
	cout << "******** 1.增加职工信息 ************" << endl;
	cout << "******** 2.显示职工信息 ************" << endl;
	cout << "******** 3.删除离职职工 ************" << endl;
	cout << "******** 4.修改职工信息 ************" << endl;
	cout << "******** 5.查找职工信息 ************" << endl;
	cout << "******** 6.按照编号排序 ************" << endl;
	cout << "******** 7.清空所有文档 ************" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void workerManager::ExitSystem()  //退出系统
{

	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);  //这行代码的意思是退出程序
}


void workerManager::Add_Emp()  //添加职工
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;  //保存用户输入的数量
	cin >> addNum;
	
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数 = 原来记录人数 + 新增人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下的数据,拷贝到新空间下

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				
				newSpace[i] = this->m_EmpArray[i];

			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{

			int id; // 职工编号
			string name;  //职工姓名
			int dSelect;  //部门选择
			
			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> id;
			
			cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
			cin >> name;
			
			cout << "请选择该职工岗位:  " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			
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
			





			//将创建职工指针,保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}

			//释放原有的空间

			delete[]this->m_EmpArray;

			//更改新空间的指向

			this->m_EmpArray = newSpace;

			//更新新的职工人数

			this->m_EmpNum = newSize;

			//成功添加后,保存到文件中

			this->save();

			//更新文件内容不为空的标志
			this->m_FileIsEmpty = false;

			//提示添加成功

			cout << "成功添加" << addNum << "名新职工!" << endl;


	}

	else
	{

		cout << "您输入的数量有误." << endl;
	}
	
	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");
}


//保存文件
void workerManager::save()
{

	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //用输出的方式打开文件  -- 写文件

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{

		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Nane << "  "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();

}

//统计文件中人数

int workerManager::get_EmpNum()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //打开文件  读取内容

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		//统计人数
		num++;

	}

	return num;
}

//初始化员工

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

		if (dId == 1)//普通职工
		{

			worker = new Employee(id, name, dId);

		}
		else if (dId == 2)//普通职工
		{

			worker = new Manager(id, name, dId);

		}
		else  //老板
		{
			worker = new Boss(id, name, dId);

		}

		this->m_EmpArray[index] = worker;
		index++;
		
	}
 
	ifs.close();  //关闭文件

}

//显示职工

void workerManager::Show_Emp()
{

	//判断文件是否为空

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空!" << endl;
	}
	else
	{

		for (int i = 0; i < m_EmpNum; i++)
		{

			//利用多态调用程序接口

			this->m_EmpArray[i]->showInfo();


		}
	}
	system("pause");
	system("cls");


}

//删除职工
void workerManager::Del_Enp()
{
	if (this->m_FileIsEmpty)
	{

		cout << "文件不存在或记录为空" << endl;
	}
	else
	{

		//按照职工编号删除

		cout << "请输入想要输出职工编号:  " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//说明职工存在,并且要删除掉index位置上的职工

		{
			for (int i = index; i<this->m_EmpNum - 1; i++)
			{

				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			//更新数组中记录人员个数
			this->m_EmpNum--;

			//同步更新到文件中
			this->save();

			cout << "删除成功!" << endl;
		}
		else
		{

			cout << "删除失败,未找到该职工!" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//判断职工是否存在,如果存在返回职工所在数组的位置,不存在返回-1
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


//修改职工
void workerManager::Mod_Emp()
{

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
		system("pause");
		system("cls");
	}
	else
	{

		cout << "请输入修改职工的编号:" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1)
		{

			//查找到编号的职工

			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到:" << id << "号职工,请输入新职工工号:" << endl;
			cin >> newId;

			cout << "请输入新姓名:" << endl;
			cin >> newName;

			
			cout << "请选择该职工岗位:  " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			
			cin >> dSelect;


			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;

			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;

			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;


			default:
				break;
			}

			//更新数据 到数组中

			this->m_EmpArray[ret] = worker;

			cout << "修改成功!" << this->m_EmpArray[ret]->m_DeptId << endl;

			//保存到文件中
			this->save();

		}
		else
		{
			cout << "修改失败,查无此人!" << endl;

		}
	}

	//按任意键 清屏

	system("pause");
	system("cls");
}


//查找职工
void workerManager::Find_Emp()
{

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
		system("pause");
		system("cls");
	}
	else
	{

		cout << "请输入 查找的方式: " << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)//按照职工编号查找
		{

			int id;
			cout << "请输入查找的职工编号:  " << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功,该职工信息如下:  " << endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else
			{
				cout << "查找失败,查无此人!" << endl;

			}
		}
		else if (select == 2) //按照姓名查找
		{

			string name;
			cout << "请输入要查找的姓名:  "<<endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Nane == name)
				{

					cout << "查找成功,职工编号为:  "
						<< m_EmpArray[i]->m_Id
						<< "号的信息如下:" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();

				}
			}
			if (flag == false)
			{

				cout << "查找失败,查无此人!" << endl;
			}
		}
		else
		{

			cout << "输入选项有误,请重新输入!" << endl;

		}
	}

	//按任意键 清屏

	system("pause");
	system("cls");
}

//排序职工
void workerManager::Sort_Emp()
{

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
		system("pause");
		system("cls");
	}
	else
	{

		cout << "请选择排序方式:  " << endl;
		cout << "1.按照职工号进行升序" << endl;
		cout << "2.按照职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{

			int minOrMax = i;
			for(int j = i+1;j<m_EmpNum;j++)
				if (select == 1)//升序
				{

					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}

			if (i != minOrMax)
			{

				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;

			}


		}
		

		
	}
		cout << "排序成功,排序后结果为:  " << endl;
		this->save();
		this->Show_Emp();

}


//清空职工
void workerManager::Clean_File()
{

	cout << "是否确认清空所有职工" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{

		//打开模式,ios::trunc  如果文件存在,就删除文件并重新创建

		ofstream ofs(FILENAME, ios::trunc);

		ofs.close();

		if (this->m_EmpArray != NULL)
		{

			for (int i = 0; i < this->m_EmpNum; i++)
			{

				if (this->m_EmpArray[i] != NULL)
				{

					delete this->m_EmpArray[i];

				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功!" << endl;

	}

	//按任意键 清屏

	system("pause");
	system("cls");
}


workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;

	}
}