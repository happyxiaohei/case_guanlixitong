#pragma once  //防止头文件重复包含
# include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"  //这里文件名是可以自定义的


class workerManager
{
public:

	//构造函数
	workerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker ** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空  标志
	
	bool m_FileIsEmpty;

	//统计文件中人数

	int get_EmpNum();

	//初始化员工
	
	void intt_Emp();

	//显示职工
 
	void Show_Emp();

	//删除职工
	void Del_Enp();

	//判断职工是否存在,如果存在返回职工所在数组的位置,不存在返回-1
	int IsExist(int id);

	//析构函数
	~workerManager();

};
                                     