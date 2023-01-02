#include <iostream>
#include <stdio.h>
using namespace std;
class Rectangle {
private:
	int lenght;
	int breadth;
public:
	Rectangle()
	{
		lenght = 0;
		breadth = 0;
	}
	Rectangle(int l, int b)
	{
		lenght = l;
		breadth = b;
	}
	int area()
	{
		return lenght * breadth;
	}
	int perimeter()
	{
		return 2 * (lenght * breadth);
	}
	void setLenght(int l)
	{
		lenght = l;
	}
	void setBreadth(int b)
	{
		breadth = b;
	}
	int getLenght()
	{
		return lenght;
	}
	int getBreadth()
	{
		return breadth;
	}

	~Rectangle()
	{
		cout << "This is a destructor" << endl;
	}

};
int main()
{
	Rectangle r(10, 5);
	cout << "Area " << r.area() << endl;
	cout << "Perimiter " << r.perimeter() << endl;



	return 0;
}