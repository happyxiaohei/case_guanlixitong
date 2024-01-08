#pragma once            //防止头文件重复包含
# include<iostream>     //包含输入输出流头文件
using namespace std;	//使用标准命名空间
#include<string>


#include"workerManager.h"

#include"worker.h"      //添加抽象类头文件
#include"employee.h"    //添加员工类文件
#include"manager.h"		//添加经理类文件	
#include"boss.h"		//添加老板类文件

//int main2() {
//
//
//	Worker* worker = NULL;
//	worker = new Employee(1, "张萨", 2);
//
//	worker->showInfo();
//
//	delete worker;
//
//
//	worker = new Manager(2, "经理", 3);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(4, "老板", 6);
//	worker->showInfo();
//	delete worker;
//
//
//	system("pause");
//
//	return 0;
//
//}

//void workerManager::Add_Emp()  //添加职工
//
//{
//
//	cout << "请输入添加职工数量:  " << endl;
//
//	int addNum = 0;  //保存用户输入的数量
//	cin >> addNum;
//
//
//	if (addNum > 0)
//	{
//
//		//添加
//		//计算添加新空间大小
//
//		int newSize = this->m_EmpNum + addNum;//新空间人数 = 原来记录人数 + 新增人数
//
//		//开辟新空间
//		Worker** newSpace = new Worker * [newSize];
//
//		//将原来空间下的数据,拷贝到新空间下
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
//			//批量添加新数据
//
//		for (int i = 0; i < addNum; i++)
//		{
//
//				int id; // 职工编号
//				string name;  //职工姓名
//				int dSelect;  //部门选择
//
//				cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
//				cin >> id;
//
//				cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
//				cin >> name;
//
//				cout << "请选择该职工岗位:  " << endl;
//				cout << "1.普通职工" << endl;
//				cout << "2.经理" << endl;
//				cout << "3.老板" << endl;
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
//			//释放原有的空间
//
//			delete[]this->m_EmpArray;
//
//			//更改新空间的指向
//
//			this->m_EmpArray = newSpace;
//
//			//更新新的职工人数
//
//			this->m_EmpNum = newSize;
//
//
//			//提示添加成功
//
//			cout << "成功添加" << addNum << "名新职工!" << endl;
//
//
//	}

//}
//
//    