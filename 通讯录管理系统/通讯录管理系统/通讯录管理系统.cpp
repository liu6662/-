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
	struct Person personarray[100];//保证通讯录里面都是联系人
	int m_Size;//记录通讯录的人数
};
//显示所有联系人
void showPerson(AddressBook* abs)
{
	if (abs->m_Size == 0) cout << "显示联系人为0" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personarray[i].m_Name << "\t";

			cout << "性别：" << (abs->personarray[i].m_Sex ==1 ? "男":"女") << "\t";
			cout << "年龄：" << abs->personarray[i].m_Age << "\t";
			cout << "电话：" << abs->personarray[i].m_Phone << endl;
		}
	}
	system("pause");
	system("cls");
}


void addPerson(AddressBook* abs)
{
	//判断是否满了
	if (abs->m_Size == 100)
	{
	
		cout << " " << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->m_Size].m_Name = name;
		//性别
		int sex=0;
		cout << "请输入性别："<<endl;
		cout << "1--man" << endl;
		cout << "2--woman" << endl;
		
		while (true) //如果输入的是1或者2继续，不是的话重新输入
		{
			cin >> sex;
			if (sex == 2 || sex == 1)
			{
				
				abs->personarray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，我国只承认以上两种性别"<<endl;
		}

		//年龄
		int age;
		cout << "请输入年龄：";
		
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 100)
			{
				abs->personarray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "老（小）东西会用手机？" << endl;
		}
		//电话
		string phone;
		cout << "请输入电话：";
		cin >> phone;
		abs->personarray[abs->m_Size].m_Phone = phone;
	}
		
	abs->m_Size++;
	system("cls");
}


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



//封装函数，检测通讯录中是否存在此联系人
int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)//遍历通讯录 的名字，检测联系人
	{
		if (abs->personarray[i].m_Name == name)
		{
			return i;//找到了就返回位置
		}
	}
	return -1;//找不到的话就返回-1；
}
void deletePerson(AddressBook *abs)
{
	cout << "请输入需要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs, name);
	if (ret == -1) cout << "查无此人" << endl;
	else
	{
		for (int i = ret; i < abs->m_Size; i++)//数据前移就是删除
		{
			abs->personarray[i] = abs->personarray[i + 1];
			
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(AddressBook* abs)
{
	cout << "请输入您想查找的人：" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personarray[ret].m_Sex ==1 ?"男":"女") << "\t";
		cout << "年龄：" << abs->personarray[ret].m_Age << "\t";
		cout << "电话：" << abs->personarray[ret].m_Phone << endl;
	}
	else cout << "查无此人" << endl;
}

//修改联系人
void modifyPerson(AddressBook* abs)
{
	cout << "请输入您想修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入您要修改的选项：" << endl;
		cout << "2---性别" << endl;
		cout << "3---年龄" << endl;
		cout << "4---电话" << endl;
		cout << "1---姓名" << endl;
		int s;
		cin >> s;
		switch(s)
		{
		case 1:
		{
			string name1;
			cin >> name1;
			cout << "请输入" << endl;
			abs->personarray[ret].m_Name = name1;
			cout << "修改完毕" << endl;
		}
			break;
		case 2:
		{
			int sex1;
			cout << "请输入" << endl;
			cout << "1---男" << endl;
			cout << "2---女" << endl;
			cin >> sex1;
			while (true)
			{
				if (sex1 == 1 || sex1 == 2)
				{
					abs->personarray[ret].m_Sex = sex1;
					cout << "修改完毕" << endl;
					break;
				}
				else cout << "我国只承认以上两种性别" << endl;
			}
		}
		case 3:
		{
			int age1;
			cout << "请输入" << endl;
			cin >> age1;
			abs->personarray[ret].m_Age = age1;
			cout << "修改完毕" << endl;
		}
			break;
		case 4:
		{
			string phone1;
			cout << "请输入" << endl;
			cin >> phone1;
			abs->personarray[ret].m_Phone = phone1;
			cout << "修改完毕" << endl;
		}
			break;
		}
	}
	else cout << "查无此人" << endl;
}

void cleanPerson(AddressBook* abs)
{
	abs->m_Size = 0;
	cout << "联系人已经清空" << endl;
	system("pause");
	system("cls");
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
		case 1: addPerson(&abs);//添加联系人；
			break;
		case 2:showPerson(&abs);//显示联系人
			break;
		case 3:deletePerson(&abs);//删除联系人
			break;
		case 4:findPerson(&abs);
			break;
		case 5:modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0: cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}

		system("pause");
	}

}