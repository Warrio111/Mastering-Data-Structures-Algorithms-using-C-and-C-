#include <iostream>
#include <stdio.h>
using namespace std;
struct Rectangle
{
	int lenght;
	int breadth;
};
int main()
{
	struct Rectangle r={10,5};
	cout<<r.breadth<<endl;
	cout<<r.lenght << endl;
	cout << "Area of Rectangle is: " << (r.lenght * r.breadth) << endl;
	


    return 0;
}