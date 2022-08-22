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
//		throw string("发送错误，除数不能为0");//抛出一个int异常
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

//标准的异常

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
//定义自定义类
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
//		throw MyException(1,"b的除数为0");//抛出一个int异常
//	}
//	cout << a / b << endl;
//}
//
//void func3()
//{
//	FILE* f=fopen("test.ca", "r");
//	if (f == nullptr)
//	{
//		throw MyException(3, "fopen 失败");
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
//	catch (const int& d)//捕获int类型的异常
//	{
//		cout << d << endl;
//	}
//	catch (const string s)//捕获string类型异常
//	{
//		cout << s << endl;
//	}
//	catch (const MyException& e)//捕获MyException类型异常
//	{
//		cout << e.What() << endl;
//		if (e.GetErrId() == 2)
//		{
//			delete p;
//			p = nullptr;
//		}
//	}
//	catch (...)//捕获任意类型的异常
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}

//如果写一个大项目

//抛出派生类对象，基类类型捕获
class MyException
{
public:
	MyException(int _i, const string _s) :
		_errid(_i),
		_errmsg(_s)
	{}
	virtual void What()const//定义虚函数，不同派生类调用what打印不同的结果
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