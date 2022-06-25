#include<iostream>
#include<string>
using namespace std;
class complex1 
{
    protected:
	     int real1, imag1;
 
    public:
	     void get_data()
 
        {
            cout<<"Enter the real part: ";
 
            cin>>real1;
 
            cout<<"Enter the imaginary part: ";
 
            cin>>imag1;
 
        }
 
        void show_data()
 
        {
 
            cout<<real1<<" + i"<<imag1;
 
        }
 
};
 
 
class complex2: public complex1
 
{
 
    private:
 
        int real1, imag1;
 
    public:
 
        void get_data()
 
        {
 
            complex1::get_data();
 
            cout<<"Enter real part: ";
 
            cin>>real1;
 
            cout<<"Enter imaginary part: ";
 
            cin>>imag1;
 
        }
 
        complex2 adds(void)
 
        {
 
            complex2 temp;
 
            temp.real1 = real1 + complex1::real1;
 
            temp.imag1 = imag1 + complex1::imag1;
 
            return temp;
 
        }
 
        void show_data()
 
        {
 
            cout<<real1<<" + j"<<imag1;
 
        }
 
        friend class complex3;
 
};
 
 
class complex3
 
{
 
    private:
 
        int real, imag;
 
    public:
 
        void get_data()
 
        {
 
            cout<<"\nEnter the complex for friend class: "<<endl;
 
            cout<<"Enter real part: ";
 
            cin>>real;
 
            cout<<"Enter imaginary part: ";
 
            cin>>imag;
 
        }
 
        complex3 subtract(complex2 c)
 
        {
 
            complex3 temp;
 
            temp.real = real - c.complex1::real1;
 
            temp.imag = imag - c.complex1::imag1;
 
            return temp;
 
        }
 
        void display()
 
        {
 
            cout<<real<<" + j"<<imag;
 
        }
 
};
 
int main()
 
{
 
    complex2 c,d;
 
    complex3 e, f;
 
 
    c.get_data();
 
    d = c.adds();
 
    cout<<"After addition the result is : "<<endl;
 
    d.show_data();
 
    cout<<endl;
 
    f.get_data();
 
    e = f.subtract(c);
 
    cout<<"After subtraction the result is : "<<endl;
 
    e.display();
 
    return 0;
 
}
