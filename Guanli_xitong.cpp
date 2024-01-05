# include<iostream>
using namespace std;
#include"workerManager.h"



int main() {

	//这个文件是主文件

	//实例化管理者对象
	workerManager wm;

	//调用展示菜单成员函数

	//wm.Show_Menu();  //测试用  //7

	//设置用户输入功能

	int choice = 0; //用来存储用户的选项  

	//展示菜单
	while (true)

	{
		//调用展示菜单成员函数 
		wm.Show_Menu();

		cout << "请输入将要操作的选项:" << endl;
		cin >> choice;
		//cin.clear();
		//cin.ignore();//这两个是为了解决用户输入的字符不是数字的问题   

		switch (choice)
		{
		case 0 ://退出系统

			wm.ExitSystem();
			break;
		case 1://添加职工
			break;
		case 2://显示职工
			break;
		case 3://删除职工
			break;
		case 4://修改职工
			break;
		case 5://查找职工
			break;
		case 6://排序职工
			break;
		case 7://清空职工
			break;

		default:
			system("cls"); //刷新屏幕
			break;
		}
	}




	system("pause");

	return 0;

}