#define _CRT_SECURE_NO_WARNINGS 1 

//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
//namespace lth
//{
//	template<class T>
//	struct __list_node
//	{
//		__list_node<T>* _next;
//		__list_node<T>* _prev;
//		T _data;
//
//		__list_node(const T& x = T())
//			:_data(x)
//			, _next(nullptr)
//			, _prev(nullptr)
//		{
//
//		}
//	};
//
//	template<class T, class Ref, class Ptr>
//	struct __list_iterator
//	{
//		typedef __list_node<T> node;
//		typedef __list_iterator<T, Ref, Ptr> Self;
//
//		node * _node;
//
//		__list_iterator(node* node)
//			:_node(node)
//		{
//
//		}
//
//		Ref operator*()  // 内置类型
//		{
//			return _node->_data; 
//		} 
//		Ptr operator->() // 自定义类型
//		{
//			return &_node->_data;
//		}
//
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//		Self operator++(int)
//		{
//			__list_interator<T> tmp(*this);
//			_node = _node->_next;
//			return tmp;
//		}
//		Self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//		Self operator--(int)
//		{
//			__list_interator<T> tmp(*this);
//			_node = _node->_prev;
//			return tmp;
//		}
//
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//	};
//	template <class T>
//	class list
//	{
//		typedef __list_node<T> node;
//		typedef __list_iterator<T, T&, T*> iterator;
//
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//
//		iterator end()
//		{
//			return iterator(_head);
//		}
//	};
//}
//#include "w.h";
#include <stdio.h>


int foo(int a, int b)
{
	return a + b;
}
