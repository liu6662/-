#include<iostream>
#include<iostream>
#define MAX 100;
using namespace std;






struct Person//��ϵ�˽ṹ��
{
	//����
	string m_Name;
	//�Ա� 1 man  2 woman
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
};
//ͨѶ¼�ṹ��
struct AddressBook
{
	struct Person personarray[100];//��֤ͨѶ¼���涼����ϵ��
	int m_Size;//��¼ͨѶ¼������
};
//��ʾ������ϵ��
void showPerson(AddressBook* abs)
{
	if (abs->m_Size == 0) cout << "��ʾ��ϵ��Ϊ0" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personarray[i].m_Name << "\t";

			cout << "�Ա�" << (abs->personarray[i].m_Sex ==1 ? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personarray[i].m_Age << "\t";
			cout << "�绰��" << abs->personarray[i].m_Phone << endl;
		}
	}
	system("pause");
	system("cls");
}


void addPerson(AddressBook* abs)
{
	//�ж��Ƿ�����
	if (abs->m_Size == 100)
	{
	
		cout << " " << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[abs->m_Size].m_Name = name;
		//�Ա�
		int sex=0;
		cout << "�������Ա�"<<endl;
		cout << "1--man" << endl;
		cout << "2--woman" << endl;
		
		while (true) //����������1����2���������ǵĻ���������
		{
			cin >> sex;
			if (sex == 2 || sex == 1)
			{
				
				abs->personarray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "���������ҹ�ֻ�������������Ա�"<<endl;
		}

		//����
		int age;
		cout << "���������䣺";
		
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 100)
			{
				abs->personarray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�ϣ�С�����������ֻ���" << endl;
		}
		//�绰
		string phone;
		cout << "������绰��";
		cin >> phone;
		abs->personarray[abs->m_Size].m_Phone = phone;
	}
		
	abs->m_Size++;
	system("cls");
}


void showMenu()//ͨѶ¼�˵�
{
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}



//��װ���������ͨѶ¼���Ƿ���ڴ���ϵ��
int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)//����ͨѶ¼ �����֣������ϵ��
	{
		if (abs->personarray[i].m_Name == name)
		{
			return i;//�ҵ��˾ͷ���λ��
		}
	}
	return -1;//�Ҳ����Ļ��ͷ���-1��
}
void deletePerson(AddressBook *abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int ret=isExist(abs, name);
	if (ret == -1) cout << "���޴���" << endl;
	else
	{
		for (int i = ret; i < abs->m_Size; i++)//����ǰ�ƾ���ɾ��
		{
			abs->personarray[i] = abs->personarray[i + 1];
			
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(AddressBook* abs)
{
	cout << "������������ҵ��ˣ�" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personarray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personarray[ret].m_Sex ==1 ?"��":"Ů") << "\t";
		cout << "���䣺" << abs->personarray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personarray[ret].m_Phone << endl;
	}
	else cout << "���޴���" << endl;
}

//�޸���ϵ��
void modifyPerson(AddressBook* abs)
{
	cout << "�����������޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "��������Ҫ�޸ĵ�ѡ�" << endl;
		cout << "2---�Ա�" << endl;
		cout << "3---����" << endl;
		cout << "4---�绰" << endl;
		cout << "1---����" << endl;
		int s;
		cin >> s;
		switch(s)
		{
		case 1:
		{
			string name1;
			cin >> name1;
			cout << "������" << endl;
			abs->personarray[ret].m_Name = name1;
			cout << "�޸����" << endl;
		}
			break;
		case 2:
		{
			int sex1;
			cout << "������" << endl;
			cout << "1---��" << endl;
			cout << "2---Ů" << endl;
			cin >> sex1;
			while (true)
			{
				if (sex1 == 1 || sex1 == 2)
				{
					abs->personarray[ret].m_Sex = sex1;
					cout << "�޸����" << endl;
					break;
				}
				else cout << "�ҹ�ֻ�������������Ա�" << endl;
			}
		}
		case 3:
		{
			int age1;
			cout << "������" << endl;
			cin >> age1;
			abs->personarray[ret].m_Age = age1;
			cout << "�޸����" << endl;
		}
			break;
		case 4:
		{
			string phone1;
			cout << "������" << endl;
			cin >> phone1;
			abs->personarray[ret].m_Phone = phone1;
			cout << "�޸����" << endl;
		}
			break;
		}
	}
	else cout << "���޴���" << endl;
}

void cleanPerson(AddressBook* abs)
{
	abs->m_Size = 0;
	cout << "��ϵ���Ѿ����" << endl;
	system("pause");
	system("cls");
}




int main()
{

	AddressBook abs;//����һ��ͨѶ¼
	//��ʼ��ͨѶ¼
	abs.m_Size = 0;

	int select;//�����û���ѡ��ť
	//�˵��ĵ���
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1: addPerson(&abs);//�����ϵ�ˣ�
			break;
		case 2:showPerson(&abs);//��ʾ��ϵ��
			break;
		case 3:deletePerson(&abs);//ɾ����ϵ��
			break;
		case 4:findPerson(&abs);
			break;
		case 5:modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0: cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}

		system("pause");
	}

}