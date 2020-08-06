#define _CRT_SECURE_NO_WARNINGS 1 


using namespace std;
#include <queue>
#include "Hash.h"



class A
{
public:
	int a = 10;
};

class B: public A
{
public:
	int c = 100;
};

 int main()
 {
	 A* a = new A();
	 B* b = new B();
	 //a = b;
	 b = (B*)a;
	 cout << b->a << endl;
	// CLOSE_HASH::Test();
	//// test();
	
	 system("pause");
 }
