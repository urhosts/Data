// 测试内存对象池的常规使用和内存对象的重复使用
#include<iostream>
#include<vector>
#include<string>
#include"ObjectPool.h"

using namespace std;

//void TestObjectPool()
//{
//	vector<string*> v;
//
//	ObjectPool<string> pool;
//	for (size_t i = 0; i < 32; ++i)
//	{
//		v.push_back(pool.New());
//		printf("Pool New [%d]: %p\n", i, v.back());
//	}
//
//	while (!v.empty())
//	{
//		pool.Delete(v.back());
//		v.pop_back();
//	}
//
//	for (size_t i = 0; i < 32; ++i)
//	{
//		v.push_back(pool.New());
//		printf("Pool New [%d]: %p\n", i, v.back());
//	}
//
//	//v.push_back(pool.New());
//	for (size_t i = 0; i < 4; ++i)
//	{
//		v.push_back(pool.New());
//		printf("Pool New [%d]: %p\n", i, v.back());
//	}
//}



#include <Windows.h>

 //针对当前的内存对象池进行简单的性能测试
void TestObjectPoolOP()
{
	size_t begin , end;
	vector<string*> v;
	const size_t N = 100000;
	v.reserve(N);

	cout<<"pool new/delete==============================="<<endl;
	// 反复申请释放5次
	begin = GetTickCount();
	ObjectPool<string> pool;
	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(pool.New());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}


	end = GetTickCount();
	cout<<"Pool:"<<end - begin<<endl;

	cout<<"new/delete==============================="<<endl;
	begin = GetTickCount();

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(new string);
	}

	while (!v.empty())
	{
		delete v.back();
		v.pop_back();
	}

	end = GetTickCount();
	cout<<"new/delete:"<<end - begin<<endl;
}

int main()
{
	//TestObjectPool();
	TestObjectPoolOP();

	system("pause");
	return 0;
}