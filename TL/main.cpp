#include "Vector.h"
#include "iostream"
#include "vector"
using namespace std;


int main(void)
{
	JTL::Vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);


	for(auto& e : v1)
	{
		cout<<e<<" ";

	}


	return 0;
}