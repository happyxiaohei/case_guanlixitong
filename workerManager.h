#pragma once  //防止头文件重复包含
# include<iostream>
using namespace std;


class workerManager
{
public:

	//构造函数
	workerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//析构函数
	~workerManager();

};
