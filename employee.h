#pragma once            //防止头文件重复包含
# include<iostream>     //包含输入输出流头文件
using namespace std;	//使用标准命名空间
#include<string>
#include"worker.h"
//
//普通员工文件

class Employee :public Worker

{
	
public:

	//初始化每个员工的属性
	//构造函数


	Employee(int id,string name,int dId);
//
//
	//显示个人信息

	virtual void showInfo();
//
	//获取岗位名称

	//virtual string gerDeptName();
	virtual string getDeptName();

};
