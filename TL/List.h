#include "iterator.h"
#include <utility>

namespace JTL
{
	template<typename T>
	class List
	{

		struct List_Node
		{
			List_Node* next;
			List_Node* prev;
			T value;

			List_Node(T&& v,List_Node* p) : value(std::move(v)), prev(p),next(nullptr)
			{}

			List_Node(T&& v, List_Node* p,List_Node* n) : value(move(v)), prev(p), next(n)
			{}

			List_Node(const T& v, List_Node* p) : value(v), prev(p), next(nullptr)
			{}
		};

		struct iterator
		{
			List_Node* ptr;

			T& operator*() const { return ptr->value; };

			iterator& operator++()
			{
				ptr = ptr->next;
				return *this;
			}

			bool operator!=(const iterator& other)const
			{
				return ptr != other.ptr;
			}


		};


		List_Node* head = nullptr;
		List_Node* tail = nullptr;



	public:
		iterator begin() { return iterator{ head }; }
		iterator end() { return iterator{ nullptr }; }
		~List()
		{
			List_Node* cur = head;
			while(cur != nullptr)
			{
				List_Node* nextNode =  cur->next;
				delete cur;
				cur = nextNode;
			}

		}


		void push_back(T&& rvalue)
		{

			if(tail == nullptr)
			{
				List_Node* newNode = new List_Node(std::move(rvalue),nullptr);
				head = newNode;
				tail = newNode;
			}
			else
			{
				List_Node* newNode = new List_Node(std::move(rvalue), tail);
				tail->next = newNode;
				tail = newNode;
			}
			

		}

		void push_back(T& lvalue)
		{
			if (tail == nullptr)
			{
				List_Node* newNode = new List_Node(lvalue, nullptr);
				head = newNode;
				tail = newNode;
			}
			else
			{
				List_Node* newNode = new List_Node(lvalue, tail);
				tail->next = newNode;
				tail = newNode;
			}
		}

		void insert(iterator it,T&& rvalue)
		{
			List_Node* curr = it.ptr;
			List_Node* prevNode = curr->prev;


			List_Node* newNode = new List_Node(std::move(rvalue), prevNode);
			newNode->next = curr;

			if (prevNode != nullptr)
				prevNode->next = newNode;
			else
				head = newNode;

			curr->prev = newNode;
			
		}

		T front()
		{

			return head->value;
		}

		T back()
		{

			return tail->value;
		}


	};
}