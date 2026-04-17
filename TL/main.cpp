#include "Vector.h"
#include "iostream"

using namespace std;


int main(void)
{
	JTL::Vector<int> v1(2,-1);


	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);


	cout<<v1[3]<<'\n';


	return 0;
}