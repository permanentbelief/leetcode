#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
using namespace std;

//class Base
//{
//public:
//	//�麯�������ģ���
//	// ����ͨ����һ�������ڴ���� 
//
//	void Func()
//	{
//		cout << "Func()" << endl;
//	}
//	//�麯���ĵ�ַ����Ҫ���ڶ�����麯�������档 
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
//	// ��֤�麯���������� vfptr�����麯�������Ԫ�ص�ַ ��ͷ�ĸ��ֽ�ȡ����
//	_Base _b;
//
//	// int*  vftptr = (int*)&_b;
//	int*  vftptr1 = (int*)(*((int*)&_b)); // (int*)��ȡ��ͷ�ϵ��ĸ��ֽڣ�
//	cout << "vftptr1 :" << vftptr1 << endl;
//
//	static int s = 0;
//	printf("static:%p\n", &s);
//
//	char* ptr = "hello";
//	printf("������:%p\n", ptr);
//	printf("������ַ(�����)��%p\n", &_Base::func1);
//	//�麯����ָ�� 
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
	//b.Func1(); //���������̬������ȥ���õ�


	//�������ģ� 
	//�ȷ����᲻�����ջ�ϣ�
	// ջ��ĳ���������еģ�һ�������������û�ˣ� �����û�У�ջ�ᱻ�ͷš� �ֲ��������ջ��
	// �᲻���ڶ��� �� �����ͷŵ�ʱ�� �Ż��ö�
	// ��̬�� 
	// �����(ֻ�����ݶ�) 
	/*
	���������ݺ��������ι��򵽷��ű���ȥ�ң����ӵ�ʱ��

	�ȶ�����麯����ǰ�棬ָ��˭����˭����ʵ����ȥ˭���������˭�����Ժ���麯������̬ʵ�ֵ�����ԭ�������������

	��̬�Ĺ��ɣ�
	1.�麯������д 
	2.�����Ǹ����ָ��������� ��ָ���࿴���࣬ ָ�����࿴���ࡣ
	ָ��������ǿ���һ���֣�������Ĵ�С�� �������Ĳ��ֶ���"��Ƭ"������Ĳ��ֿ������ˣ������������һ����

	������ָ������ã����õĵײ�Ҳ��ָ��)
	ָ�����Ҹ�������
	ָ����������������

	ΪʲôҪ��д��
	���������������Ǹ�����麯��������������������������麯��
	ָ�����ҵ��Ǹ�����麯����ָ�������ҵ���������麯��

	ֻ�������̬ �Ż�ȥ�������

	*/
//
//	system("pause");
//}

/*

vftptr8
 _c
 _b

 �麯���������� ������麯���ĵ�ַ

 ���ָ�뻹��ָ��һ����ָ���麯�����  

 �麯���ĵ�ַ�������麯������ȥ�š�

 ������ʵ�ֲ����ϵġ�
 
 ָ�����һ������ָ������ �����麯����

 �麯������ͨ����һ�����ڵ��Ǵ������
 �����������ָ�룬 vfptr(ָ���������(�麯����)��ָ��)�� ��ָ���麯�����ָ�룬ָ������麯����
 ��������麯����ָ�룬�麯������ͨ�������Ǵ����ڴ�����еģ�ֻ�ǰ��麯���ĵ�ַ�������һ�ݵ��麯����(���)��ȥ

 ��ɸ��ǣ� �ﵽָ��˭����˭�����ã�ʵ�ֶ�̬��

 �����д�������ָ��

 �������ġ���ƽ̨�й�ϵ��VS���Ǵ����ڴ�����еġ�

 

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
//	B *p2 = new B; //���һ�� p->test(); Ҫ��p��ָ�봫��ȥ����Ϊ����˭����test�� test������ԭ����  test(A*this) ���ᱻǿת��A* ���ﲻ�Ƕ�̬��test()
//	//�����麯�������Բ��Ƕ�̬���ã����Ը������йأ���ͨ���ã� p�����;���A ���Ծ��ǵ���A��test �� test(A*this)������B�Ĵ���������ֵ���ݹ���Ҳ��
//	//��B��ǿת��A* ������Ը�����
//
//	p2->test();
//	cout << endl;
//	system("pause");
//}