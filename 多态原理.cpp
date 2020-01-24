#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
using namespace std;

//class Base
//{
//public:
//	//虚函数存在哪？？
//	// 和普通函数一样都存在代码段 
//
//	void Func()
//	{
//		cout << "Func()" << endl;
//	}
//	//虚函数的地址，还要存在对象的虚函数表里面。 
//	virtual void Func1() 
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//private:
//	char _c;
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//
//	Derive d;
//	cout << sizeof(d) << endl;
//	system("pause");
//}
//
//class _Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class _Derive :public _Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//int main()
//{
//	// 验证虚函数表存在哪里， vfptr就是虚函数表的首元素地址 把头四个字节取出来
//	_Base _b;
//
//	// int*  vftptr = (int*)&_b;
//	int*  vftptr1 = (int*)(*((int*)&_b)); // (int*)（取到头上的四个字节）
//	cout << "vftptr1 :" << vftptr1 << endl;
//
//	static int s = 0;
//	printf("static:%p\n", &s);
//
//	char* ptr = "hello";
//	printf("常量区:%p\n", ptr);
//	printf("函数地址(代码段)：%p\n", &_Base::func1);
//	//虚函数表指针 
//
//	Base b;
//	cout << sizeof(Base) << endl;
//
//	Derive d;
//	cout << sizeof(Derive) << endl;
//
//
	//Base* ptr = &b;
	//ptr->Func1();

	//ptr = &d;
	//ptr->Func1();

	//b.Func();
	//b.Func1(); //都不满足多态，对象去调用的


	//虚表存在哪？ 
	//先分析会不会存在栈上？
	// 栈是某个函数所有的，一个函数调用完就没了， 虚表不会没有，栈会被释放、 局部对象才在栈上
	// 会不会在堆上 ？ 申请释放的时候 才会用堆
	// 静态区 
	// 代码段(只读数据段) 
	/*
	函数名根据函数名修饰规则到符号表里去找，链接的时候。

	先定义的虚函数在前面，指向谁调用谁，其实就是去谁的虚表里找谁覆盖以后的虚函数，多态实现的真正原理依靠的是虚表

	多态的构成：
	1.虚函数的重写 
	2.必须是父类的指针或者引用 ，指向父类看父类， 指向子类看子类。
	指针和引用是看这一部分，看父类的大小， 子类多余的部分都被"切片"，多余的部分看不见了，看的是子类的一部分

	必须是指针或引用（引用的底层也是指针)
	指向父类找父类的虚表
	指向子类找子类的虚表

	为什么要重写？
	父类的虚表里面存的是父类的虚函数，子类的虚表里面存的是子类的虚函数
	指向父类找的是父类的虚函数，指向子类找的是子类的虚函数

	只有满足多态 才会去虚表里面

	*/
//
//	system("pause");
//}

/*

vftptr8
 _c
 _b

 虚函数表，简称虚表， 存的是虚函数的地址

 虚表指针还会指向一个表，指向虚函数表表  

 虚函数的地址都得往虚函数表里去放。

 覆盖是实现层面上的。
 
 指向的是一个函数指针数组 叫做虚函数表

 虚函数和普通函数一样存在的是代码段中
 对象存的是虚表指针， vfptr(指向这个数组(虚函数表)的指针)， 是指向虚函数表的指针，指向的是虚函数表
 虚表存的是虚函数的指针，虚函数和普通函数都是存在在代码段中的，只是把虚函数的地址额外存了一份到虚函数表(虚表)中去

 达成覆盖， 达到指向谁调用谁的作用，实现多态。

 对象中存的是虚表指针

 虚表存在哪》和平台有关系，VS中是存在在代码段中的。

 

 */

//class A
//{
//public:
//	A() :m_iVal(0) { test(); }
//	virtual void func() {
//		cout << m_iVal << " ";
//	}
//	void test() { func(); }
//public:
//	int m_iVal;
//};
//class B : public A
//{
//public:
//	B() { test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		cout << m_iVal << " ";
//	}
//};
//int main()
//{
//	A *p1 = new B;
//	
//	p1->test();
//	cout << endl;
//
//	B *p2 = new B; //结果一样 p->test(); 要把p的指针传过去。因为不管谁调用test， test函数的原型是  test(A*this) 都会被强转成A* 这里不是多态，test()
//	//不是虚函数，所以不是多态调用，所以跟类型有关（普通调用） p的类型就是A 所以就是调用A的test ， test(A*this)，就算B的传给他，赋值兼容规则也会
//	//把B的强转成A* 子类可以给父类
//
//	p2->test();
//	cout << endl;
//	system("pause");
//}