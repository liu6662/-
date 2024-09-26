#include<iostream>
#include<iostream>
#define MAX 100;
using namespace std;
struct Person//联系人结构体
{
	//姓名
	string m_Name;
	//性别 1 man  2 woman
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
};
//通讯录结构体
struct AddressBook
{
	struct Person personarray[MAX];//保证通讯录里面都是联系人
	int m_Size;//记录通讯录的人数
};



void showMenu()//通讯录菜单
{
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
int main()
{

	AddressBook abs;//创建一个通讯录
	//初始化通讯录
	abs.m_Size = 0;

	int select;//创建用户的选择按钮
	//菜单的调用
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1: addPerson(&adbs)
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0: cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}

		system("pause");
	}
	
}