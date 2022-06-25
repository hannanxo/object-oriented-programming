#include <iostream>
using namespace std;
//making parent class circletype
class circleType
{
	//access specifiers
private:
	double radius;
	// prototyping
public:
	void setRadius(double r);
	double getRadius();
	double area();
	double circumference();
	circleType(double r = 0);
	void print()
	{
		cout << "Radius : " << getRadius() << endl;
		cout << "Area : " << area() << endl;
		cout << "Circumference : " << circumference() << endl;
	}
};

// making set function 
void circleType::setRadius(double r)
{
	if (r >= 0)
		radius = r;
	else
		radius = 0;
}
//making get function to return radius
double circleType::getRadius()
{
	return radius;
}
// function for area to return value for area
double circleType::area()
{
	return 3.1416 * radius * radius;
}
// function for circumference to get circumference
double circleType::circumference()
{
	return 2 * 3.1416 * radius;
}
// using set function to set radius
circleType::circleType(double r)
{
	setRadius(r);
}
//making class for cylindertype which will inherit characteristics from parent class circletype
class cylinderType : public circleType
{
public:
	double height;

	void setHeight(double h)
	{
		height = h;
	}

	double getVolume()
	{
		return area() * height;
	}

	double surfaceArea()
	{
		return (circumference() * height) + (2 * area());
	}
};

int main()
{
	//making object for class cylinder type inherited from class circletype
	cylinderType c1;
	//making variables
	double r;
	double h;
	double shipcost;
	double paintcost;
    
	cout << "Enter radius for the base: " << endl;
	cin >> r;
	c1.setRadius(r);
	cout << "Enter height for the cylinder: " << endl;
	cin >> h;
	c1.setHeight(h);
	cout << "Enter shipping cost for liquid: " << endl;
	cin >> shipcost;
	cout << "Enter painting cost for cylinder: " << endl;
	cin >> paintcost;
	cout << "The total cost for painting cylinder : " << c1.surfaceArea() * paintcost << endl;
	cout << "The total cost for shipping cylinder : " << (c1.getVolume() * shipcost)/28.32 << endl;

	system("pause");
	return 0;
}

