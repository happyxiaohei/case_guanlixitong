#pragma once            //防止头文件重复包含
# include<iostream>     //包含输入输出流头文件
using namespace std;	//使用标准命名空间
#include<string>


#include"workerManager.h"

#include"worker.h"      //添加抽象类头文件
#include"employee.h"    //添加员工类文件
#include"manager.h"		//添加经理类文件	
#include"boss.h"		//添加老板类文件

int main2() {


	Worker* worker = NULL;
	worker = new Employee(1, "张萨", 2);

	worker->showInfo();

	delete worker;


	worker = new Manager(2, "经理", 3);
	worker->showInfo();
	delete worker;

	worker = new Boss(4, "老板", 6);
	worker->showInfo();
	delete worker;


	system("pause");

	return 0;

}