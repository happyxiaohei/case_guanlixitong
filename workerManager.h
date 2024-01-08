#pragma once  //防止头文件重复包含
# include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"



class workerManager
{
public:

	//构造函数
	workerManager();

	//展示菜单
	void Show_Menu();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker ** m_EmpArray;

	//添加职工
	void Add_Emp();

	//退出系统
	void ExitSystem();

	//析构函数
	~workerManager();

};
                                     