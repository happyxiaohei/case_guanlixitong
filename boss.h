#pragma once            //防止头文件重复包含
# include<iostream>     //包含输入输出流头文件
using namespace std;	//使用标准命名空间
#include<string>

#include"worker.h"


//经理类文件
class Boss :public Worker
{

public:

	Boss(int id, string name, int dId);


	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string  getDeptName();

};