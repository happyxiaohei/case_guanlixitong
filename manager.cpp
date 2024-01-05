//#pragma once            //防止头文件重复包含
//# include<iostream>     //包含输入输出流头文件
//using namespace std;	//使用标准命名空间
//#include<string>


#include"manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Nane = name;
	this->m_DeptId = dId;

}

//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号:  " << this->m_Id
		<< "\t职工姓名:  " << this->m_Nane
		<< "\t岗位:  " << this->getDeptName()
		<< "\t岗位职责: 完成老板交给的任务,并下发任务给员工 " << endl;

}
//获取岗位名称
string  Manager::getDeptName()
{
	return string("经理");

}

