#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


/*
你看这题， 让我实现 多线程下安全的循环队列，满足这些条件，而且每一个线程的读取速率不一样，实现出每一个线程怎么做，才能保证循环队列中的数据不覆盖。

一个生产者，三个消费者的情况下，保证每一个线程都能读取到a b c

循环队列，在每一个线程中维护 一份 数组 的 副本，这个我都不会 qwq

线程的入口函数吗 ， 每一个 线程都要维护 这个数组的副本
这个 数组 还要在 线程安全的循环队列中




真的不公平啊，面试官都，不问知识点，都逮住你不会的深问，然后慢慢问的我都不会说话了，然后 撕代码看我会，写得快，还换题，然后还 实现多线程，逮住多线程，一直往里问，怎么实现，我最后说我不会C++下的多线程代码，还有10min.能不能换个题  面试的时候我真的压抑了50min, 最后他说，不换了就这吧，就撂下了

*/
int main()
{
	
	system("pause");
}