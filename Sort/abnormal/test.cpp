#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<stdio.h>
//
//void func()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//	{
//		throw string("���ʹ��󣬳�������Ϊ0");//�׳�һ��int�쳣
//	}
//	cout << a / b << endl;
//}
//int main()
//{
//	try
//	{
//		func();
//		cout << "hello world" << endl;
//	}
//	catch (const int& d)
//	{
//		cout << d<< endl;
//	}
//	catch (const string s)
//	{
//		cout << s << endl;
//	}
//	return 0;
//}

//��׼���쳣

//int main()
//{
//	try
//	{
//		int* p=new int[0xfffffff];
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
//�����Զ�����
//class MyException
//{
//public:
//	MyException(int _i, const string _s) :
//		_errid(_i),
//		_errmsg(_s)
//	{}
//	string What()const
//	{
//		return _errmsg;
//	}
//
//	int	GetErrId()const
//	{
//		return _errid;
//	}
//private:
//	int _errid;
//	string _errmsg;
//};
//void func1()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//	{
//		throw MyException(1,"b�ĳ���Ϊ0");//�׳�һ��int�쳣
//	}
//	cout << a / b << endl;
//}
//
//void func3()
//{
//	FILE* f=fopen("test.ca", "r");
//	if (f == nullptr)
//	{
//		throw MyException(3, "fopen ʧ��");
//	}
//
//}
//int* p;
//void func2()
//{
//	p = new int;
//	if (p == nullptr)
//	{
//		throw MyException(2, "fopen fail");
//	}
//}
//
//int main()
//{
//	try
//	{
//		func1();
//		func2();
//		func3();
//		cout << "hello world" << endl;
//	}
//	catch (const int& d)//����int���͵��쳣
//	{
//		cout << d << endl;
//	}
//	catch (const string s)//����string�����쳣
//	{
//		cout << s << endl;
//	}
//	catch (const MyException& e)//����MyException�����쳣
//	{
//		cout << e.What() << endl;
//		if (e.GetErrId() == 2)
//		{
//			delete p;
//			p = nullptr;
//		}
//	}
//	catch (...)//�����������͵��쳣
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	return 0;
//}

//���дһ������Ŀ

//�׳���������󣬻������Ͳ���
class MyException
{
public:
	MyException(int _i, const string _s) :
		_errid(_i),
		_errmsg(_s)
	{}
	virtual void What()const//�����麯������ͬ���������what��ӡ��ͬ�Ľ��
	{
		cout << _errmsg << endl;
	}

	int	GetErrId()const
	{
		return _errid;
	}
protected:
	int _errid;	
	string _errmsg;
};

class CacheExcetion :public::MyException
{
public:
	CacheExcetion(int _i, const string _s)
		:MyException(_i,_s)
	{

	}
	void What()const
	{
		cout << _errmsg << endl;
	}
};

int main()
{
	try
	{

	}
	catch (const MyException& e)
	{

	}
}