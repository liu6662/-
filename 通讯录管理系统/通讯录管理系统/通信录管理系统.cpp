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
	struct Person personarray[MAX];//��֤ͨѶ¼���涼����ϵ��
	int m_Size;//��¼ͨѶ¼������
};



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
		case 0: cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}

		system("pause");
	}
	
}