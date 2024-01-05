#pragma once            //防止头文件重复包含
# include<iostream>     //包含输入输出流头文件
using namespace std;	//使用标准命名空间
#include<string>
#include"employee.h"

	//初始化每个员工的属性
	//构造函数


	Employee::Employee(int id, string name, int dId)
	{

		this->m_Id = id;
		this->m_Nane = name;
		this->m_DeptId = dId;


	}

	//获取岗位名称

	//显示个人信息

	void Employee::showInfo()
	{
		cout << "职工编号:  " << this->m_Id
			<< "\t职工姓名:  " << this->m_Nane
			<< "\t岗位:  " << this->getDeptName()
			<< "\t岗位职责:  完成经理交给的任务" << endl;

	}



	string  Employee::getDeptName()
	{

		return string("员工");
	}



