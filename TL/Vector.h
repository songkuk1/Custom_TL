#pragma once
#include <cstring>
#include <stdlib.h>
#include <cassert>

namespace JTL
{
template <typename T>
class Vector
{

	class iterator
	{
		T* data;

	};

private:
	size_t _size;
	size_t _capacity;
	T* head;
	T* tail;
	T* arr = nullptr;

public:

	//초기화 값을 안주면 쓰레기값을 넣어둠
	Vector(size_t s = 0)
	{
		_size = 0;
		_capacity = s;

		if(s > 0)
		{
			arr = (T*)malloc(sizeof(T) * s);
			head = &arr[0];
			tail = &arr[s];
		}
		else
		{
			head = nullptr;
			tail = nullptr;

		}
	}

	//초기화 값을 주면 넣어줌
	Vector(size_t s, T init)
	{
		_size = s;
		_capacity = s;

		if (s > 0)
		{
			arr = (T*)malloc(sizeof(T) * s);
			memset(arr, init, sizeof(T) * s);
			head = &arr[0];
			tail = &arr[s];
		}
		else
		{
			head = nullptr;
			tail = nullptr;

		}
	}

	T& operator [](size_t idx)
	{
		//들어있는 원소 수보다 높은 인덱스값을 넣었을때 assert
		assert(idx < _size);

		return arr[idx];
	}
		

	//rvalue일때
	void push_back(T&& rvalue)
	{
		//여유공간이 없으면 재할당
		if (_capacity == _size)
		{
			reserve();

			new (&arr[_size++]) T(rvalue);
		}
		else
			new (&arr[_size++]) T(rvalue);
	}


	//lvalue일때
	void push_back(T& lvalue)
	{
		//여유공간이 없으면 재할당
		if(_capacity == _size)
		{
			//재할당이 일어나야하므로 T& value로 들어온값이 사라져버리니 임시저장
			T tmp = lvalue;

			reserve();

			new (&arr[_size++]) T(static_cast<T&&>(tmp));
		}
		else
			new (&arr[_size++]) T(static_cast<T&&>(lvalue));
	}



	void reserve()
	{
		if(_capacity == 0)
			_capacity = 1;

		_capacity *= 2;

		T* new_arr = (T*)malloc(sizeof(T) * _capacity);

		for(size_t i =0; i < _size; ++i)
		{
			//Placement New 사용
			new (&new_arr[i]) T(static_cast<T&&>(arr[i]));
			//소멸자호출, 기본 타입이면 무시함
			arr[i].~T();
		}
			
		//기존 자원 삭제
		free(arr);
		//새로 연결
		arr = new_arr;
	}

};
}