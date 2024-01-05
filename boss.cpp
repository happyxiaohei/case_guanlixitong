//#pragma once            //防止头文件重复包含
//# include<iostream>     //包含输入输出流头文件
//using namespace std;	//使用标准命名空间
//#include<string>


#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Nane = name;
	this->m_DeptId = dId;

}

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号:  " << this->m_Id
		<< "\t职工姓名:  " << this->m_Nane
		<< "\t岗位:  " << this->getDeptName()
		<< "\t岗位职责: 管理公司所有的事务 " << endl;

}
//获取岗位名称
string  Boss::getDeptName()
{
	return string("老板");

}

