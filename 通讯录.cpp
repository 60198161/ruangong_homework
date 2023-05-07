#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct person
{
	//姓名
	string m_name;
	//性别 1、男  2、女
	int m_sex;
	//年龄
	int age;
	//电话
	string m_phone;
	//住址
	string m_adder;
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct person personArray[MAX];
	//通讯录中当前保存的人数
	int m_size;
};
void addPerson(struct Addressbooks *abs)
{
	//判断通讯录是否已满
	if(abs->m_size==MAX)
	{
		cout<<"通讯录已满，无法添加！"<<endl;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout<<"请输入姓名：  "<<endl;
		cin>>name;
		abs->personArray[abs->m_size].m_name=name;
		//性别
		cout<<"请输入性别：  "<<endl;
		cout<<"1--男"<<endl;
		cout<<"2--女"<<endl;
		int sex=0;
		while(true)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
			abs->personArray[abs->m_size].m_sex=sex;
			break;
			}
			cout<<"输入有误请重新输入"<<endl;
		
		}
		//年龄
		cout<<"请输入年龄"<<endl;
		int age=0;
		cin>>age;
		abs->personArray[abs->m_size].age=age;
		//电话
		cout<<"请输入电话"<<endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_size].m_phone=phone;
		//住址
		cout<<"请输入家庭住址"<<endl;
		string address;
		cin>>address;
		abs->personArray[abs->m_size].m_adder=address;
		//更新通讯录人数
		abs->m_size++;
		cout<<"添加成功"<<endl;
		system("pause");
		system("cls");
	}
}
//2、显示联系人
void showperson(struct Addressbooks *abs)
{
	//判断人数是否为0；
	if(abs->m_size==0)
	{
		cout<<"当前记录为空"<<endl;
	}
	else
	{
		for(int i=0;i<abs->m_size;i++)
		{
			cout<<"姓名： "<<abs->personArray[i].m_name<<"\t";
			cout<<"性别： "<<(abs->personArray[i].m_sex==1?"男":"女")<<"\t";
			cout<<"年龄： "<<abs->personArray[i].age<<"\t";
			cout<<"电话： "<<abs->personArray[i].m_phone<<"\t";
			cout<<"住址： "<<abs->personArray[i].m_adder<<endl;
		}
	}
	system("pause");
	system("cls");

}
//检测联系人是否存在
int isexit(Addressbooks *abs,string name)
{
	for(int i=0;i<abs->m_size;i++)
	{
		if(abs->personArray[i].m_name==name)
			return i;
	}
	return -1;
}
//3、删除指定联系人
void deleteperson(Addressbooks *abs)
{
	cout<<"请输入要删除联系人"<<endl;
	string name;
	cin>>name;
	int ret=isexit(abs,name);
	if(ret==-1)
	{
		cout<<"查无此人"<<endl;
	}
	else
	{
		for(int i=ret;i<abs->m_size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];
		}
		abs->m_size--;
		cout<<"删除成功"<<endl;
	}
	system("pause");
	system("cls");
}
//4、查找指定联系人
void findperson(Addressbooks *abs)
{
	cout<<"请输入要查找的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isexit(abs,name);
		if(ret!=-1)
		{
			cout<<"姓名"<<abs->personArray[ret].m_name<<"\t";
			cout<<"性别"<<abs->personArray[ret].m_sex<<"\t";
			cout<<"电话"<<abs->personArray[ret].m_phone<<"\t";
			cout<<"住址： "<<abs->personArray[ret].m_adder<<endl;
		}
		else
		{
			cout<<"未找到"<<endl;
		}
		system("pause");
		system("cls");
}
//5、修改联系人
void modifyperson(Addressbooks *abs)
{
	cout<<"请输入要修改的联系人"<<endl;
	string name;
	cin>>name;
	int ret=isexit(abs,name);
	if(ret!=-1)
	{
		string name1;
		cout<<"请输入姓名："<<endl;
		cin>>name1;
		abs->personArray[ret].m_name=name1;

		cout<<"请输入性别："<<endl;
		cout<<"1--男"<<endl;
		cout<<"2--女"<<endl;
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
				cout<<"输入有无，请重新输入"<<endl;
			}
		}

		cout<<"请输入年龄："<<endl;
		int age;
		cin>>age;
		abs->personArray[ret].age=age;

		cout<<"请输入电话："<<endl;
		string phone;
		cin>>phone;
		abs->personArray[ret].m_phone=phone;

		cout<<"请输入住址："<<endl;
		string add;
		cin>>add;
		abs->personArray[ret].m_adder=add;

		cout<<"修改成功"<<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");
		system("cls");
}
//6、清空联系人
void cleanpreson(Addressbooks *abs)
{
	
	int choose=0;
	while(true)
	{
		cout<<"确认是否清空"<<endl;
	cout<<"1--确认"<<endl;
	cout<<"2--放弃"<<endl;
		cin>>choose;
		if(choose==1||choose==2)
		{
			if(choose==1)
			{
			abs->m_size=0;
	cout<<"清空成功"<<endl;
	break;
			}
			else
			{
				cout<<"放弃成功"<<endl;
				break;
			}
		}
		else
		{
			cout<<"选择错误，请重新选择"<<endl;
		}
	}
	
	system("pause");
		system("cls");
}
//菜单界面
void showMenu()
{	cout<<"***************************"<<endl;
	cout<<"*****  1、添加联系人  *****"<<endl;
	cout<<"*****  2、显示联系人  *****"<<endl;
	cout<<"*****  3、删除联系人  *****"<<endl;
	cout<<"*****  4、查找联系人  *****"<<endl;
	cout<<"*****  5、修改联系人  *****"<<endl;
	cout<<"*****  6、清空联系人  *****"<<endl;
	cout<<"*****  0、退出通讯录  *****"<<endl;
	cout<<"***************************"<<endl;
}
int main()
{
	//创建通讯录结构体变量；
	Addressbooks abs;
	//初始化通讯录当前人数
	abs.m_size=0;

	int select=0;
	
	while(true)
	{
		//菜单调用
		showMenu();

		cin>>select;

	switch(select)
		{
	case 1:   // 1、添加联系人
		addPerson(&abs);
		break;
	case 2:   // 2、显示联系人
		showperson(&abs);
		break;
	case 3:   // 3、删除联系人
	deleteperson(&abs);
		break;
	case 4:   // 4、查找联系人
		findperson(&abs);
		break;
	case 5:   // 5、修改联系人
		modifyperson(&abs);
		break;
	case 6:   // 6、清空联系人 
		cleanpreson(&abs);
		break;
	case 0:   // 0、退出通讯录
		cout<<"欢迎下次使用"<<endl;
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