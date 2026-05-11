#include "Vector.h"
#include "iostream"
#include "vector"
#include "algorithm.h"
#include "List.h"
using namespace std;


int main(void)
{
	JTL::Vector<string> v(5);

	v.push_back("b");
	v.push_back("a");
	v.push_back("ab");


	JTL::sort(v.begin(),v.end());

	for(auto& e : v)
		cout<<e<<" ";

	return 0;
}