#include "Vector.h"
#include "iostream"
#include "vector"
#include "algorithm.h"
#include "List.h"
using namespace std;


int main(void)
{
	JTL::List<int> ls;


	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);

	for(auto& e : ls)
		cout<<e<<" ";


	ls.insert(ls.begin(),3);

	cout<<'\n';

	for (auto& e : ls)
		cout << e << " ";
	return 0;
}