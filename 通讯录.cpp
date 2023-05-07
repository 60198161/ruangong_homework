#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//�����ϵ�˽ṹ��
struct person
{
	//����
	string m_name;
	//�Ա� 1����  2��Ů
	int m_sex;
	//����
	int age;
	//�绰
	string m_phone;
	//סַ
	string m_adder;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct person personArray[MAX];
	//ͨѶ¼�е�ǰ���������
	int m_size;
};
void addPerson(struct Addressbooks *abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if(abs->m_size==MAX)
	{
		cout<<"ͨѶ¼�������޷���ӣ�"<<endl;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout<<"������������  "<<endl;
		cin>>name;
		abs->personArray[abs->m_size].m_name=name;
		//�Ա�
		cout<<"�������Ա�  "<<endl;
		cout<<"1--��"<<endl;
		cout<<"2--Ů"<<endl;
		int sex=0;
		while(true)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
			abs->personArray[abs->m_size].m_sex=sex;
			break;
			}
			cout<<"������������������"<<endl;
		
		}
		//����
		cout<<"����������"<<endl;
		int age=0;
		cin>>age;
		abs->personArray[abs->m_size].age=age;
		//�绰
		cout<<"������绰"<<endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_size].m_phone=phone;
		//סַ
		cout<<"�������ͥסַ"<<endl;
		string address;
		cin>>address;
		abs->personArray[abs->m_size].m_adder=address;
		//����ͨѶ¼����
		abs->m_size++;
		cout<<"��ӳɹ�"<<endl;
		system("pause");
		system("cls");
	}
}
//2����ʾ��ϵ��
void showperson(struct Addressbooks *abs)
{
	//�ж������Ƿ�Ϊ0��
	if(abs->m_size==0)
	{
		cout<<"��ǰ��¼Ϊ��"<<endl;
	}
	else
	{
		for(int i=0;i<abs->m_size;i++)
		{
			cout<<"������ "<<abs->personArray[i].m_name<<"\t";
			cout<<"�Ա� "<<(abs->personArray[i].m_sex==1?"��":"Ů")<<"\t";
			cout<<"���䣺 "<<abs->personArray[i].age<<"\t";
			cout<<"�绰�� "<<abs->personArray[i].m_phone<<"\t";
			cout<<"סַ�� "<<abs->personArray[i].m_adder<<endl;
		}
	}
	system("pause");
	system("cls");

}
//�����ϵ���Ƿ����
int isexit(Addressbooks *abs,string name)
{
	for(int i=0;i<abs->m_size;i++)
	{
		if(abs->personArray[i].m_name==name)
			return i;
	}
	return -1;
}
//3��ɾ��ָ����ϵ��
void deleteperson(Addressbooks *abs)
{
	cout<<"������Ҫɾ����ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isexit(abs,name);
	if(ret==-1)
	{
		cout<<"���޴���"<<endl;
	}
	else
	{
		for(int i=ret;i<abs->m_size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];
		}
		abs->m_size--;
		cout<<"ɾ���ɹ�"<<endl;
	}
	system("pause");
	system("cls");
}
//4������ָ����ϵ��
void findperson(Addressbooks *abs)
{
	cout<<"������Ҫ���ҵ���ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isexit(abs,name);
		if(ret!=-1)
		{
			cout<<"����"<<abs->personArray[ret].m_name<<"\t";
			cout<<"�Ա�"<<abs->personArray[ret].m_sex<<"\t";
			cout<<"�绰"<<abs->personArray[ret].m_phone<<"\t";
			cout<<"סַ�� "<<abs->personArray[ret].m_adder<<endl;
		}
		else
		{
			cout<<"δ�ҵ�"<<endl;
		}
		system("pause");
		system("cls");
}
//5���޸���ϵ��
void modifyperson(Addressbooks *abs)
{
	cout<<"������Ҫ�޸ĵ���ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isexit(abs,name);
	if(ret!=-1)
	{
		string name1;
		cout<<"������������"<<endl;
		cin>>name1;
		abs->personArray[ret].m_name=name1;

		cout<<"�������Ա�"<<endl;
		cout<<"1--��"<<endl;
		cout<<"2--Ů"<<endl;
		int sex=0;
		while(true)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				abs->personArray[ret].m_sex=sex;
				break;
			}
			else
			{
				cout<<"�������ޣ�����������"<<endl;
			}
		}

		cout<<"���������䣺"<<endl;
		int age;
		cin>>age;
		abs->personArray[ret].age=age;

		cout<<"������绰��"<<endl;
		string phone;
		cin>>phone;
		abs->personArray[ret].m_phone=phone;

		cout<<"������סַ��"<<endl;
		string add;
		cin>>add;
		abs->personArray[ret].m_adder=add;

		cout<<"�޸ĳɹ�"<<endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");
		system("cls");
}
//6�������ϵ��
void cleanpreson(Addressbooks *abs)
{
	
	int choose=0;
	while(true)
	{
		cout<<"ȷ���Ƿ����"<<endl;
	cout<<"1--ȷ��"<<endl;
	cout<<"2--����"<<endl;
		cin>>choose;
		if(choose==1||choose==2)
		{
			if(choose==1)
			{
			abs->m_size=0;
	cout<<"��ճɹ�"<<endl;
	break;
			}
			else
			{
				cout<<"�����ɹ�"<<endl;
				break;
			}
		}
		else
		{
			cout<<"ѡ�����������ѡ��"<<endl;
		}
	}
	
	system("pause");
		system("cls");
}
//�˵�����
void showMenu()
{	cout<<"***************************"<<endl;
	cout<<"*****  1�������ϵ��  *****"<<endl;
	cout<<"*****  2����ʾ��ϵ��  *****"<<endl;
	cout<<"*****  3��ɾ����ϵ��  *****"<<endl;
	cout<<"*****  4��������ϵ��  *****"<<endl;
	cout<<"*****  5���޸���ϵ��  *****"<<endl;
	cout<<"*****  6�������ϵ��  *****"<<endl;
	cout<<"*****  0���˳�ͨѶ¼  *****"<<endl;
	cout<<"***************************"<<endl;
}
int main()
{
	//����ͨѶ¼�ṹ�������
	Addressbooks abs;
	//��ʼ��ͨѶ¼��ǰ����
	abs.m_size=0;

	int select=0;
	
	while(true)
	{
		//�˵�����
		showMenu();

		cin>>select;

	switch(select)
		{
	case 1:   // 1�������ϵ��
		addPerson(&abs);
		break;
	case 2:   // 2����ʾ��ϵ��
		showperson(&abs);
		break;
	case 3:   // 3��ɾ����ϵ��
	deleteperson(&abs);
		break;
	case 4:   // 4��������ϵ��
		findperson(&abs);
		break;
	case 5:   // 5���޸���ϵ��
		modifyperson(&abs);
		break;
	case 6:   // 6�������ϵ�� 
		cleanpreson(&abs);
		break;
	case 0:   // 0���˳�ͨѶ¼
		cout<<"��ӭ�´�ʹ��"<<endl;
		system("pause");
		return 0;
		break;
	default:
			break;
		}
	}
	system("pause");
		return 0;
}