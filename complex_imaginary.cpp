#include <iostream>

using namespace std;

class Complex
{
public:
	int real, img;
	Complex(int r=0,int i=0)
	{
		real = r, img = i;
	}
	void display()
	{
		cout << real << "+ j" << img << endl;
	}
};

class AddComplex :public Complex
{
private:
public:
	AddComplex(int r=0,int i=0) {
		real = r, img = i;
	}

	AddComplex operator+( Complex a)
	{
		real += a.real;
		img += a.img;
		return *this;
	}
	friend class DiffComplex;
};
class DiffComplex:public Complex {
public:
	DiffComplex(int r = 0, int i = 0) {
		real = r, img = i;
	}

	DiffComplex operator - ( Complex a)
	{
		real -= a.real;
		img -= a.img;
		return *this;
	}
	void display()
	{
		cout << real << "+ j" << img << endl;
	}

};

int main()
{
	Complex a(3,4);
	AddComplex b(3,4);
	DiffComplex c(3, 4);
	a.display();
	b.display();
	c.display();
	(b + a).display();
	(c-a).display();
	return 0;
}
