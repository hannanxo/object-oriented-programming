#include<iostream>
using namespace std;
//declaring class clock
class clock
{
	private:
    int hr, min, sec,time,time2;
    public:
    // setting default constructor
    clock()
    {
        hr=0, min=0; sec=0;
    }
    //copy constructor
    clock(clock &t1  )
    {
    	hr=t1.hr;
    	min=t1.hr;
    	sec=t1.sec;	
	}
    // making constructor
    clock(int h, int m, int s)
    {
        hr=h, min=m; sec=s;
    }
    //overloading '==' operator
    //using friend function 
    friend bool operator==(clock &t1, clock &t2);
    // overloading '<<' operator
    //using friend function 
    friend ostream& operator << (ostream &out, clock &tm); 
};
// defining overloaded friend function
bool operator== (clock &t1, clock &t2)
{
    return ( t1.hr == t2.hr && t1.min == t2.min && t1.sec == t2.sec );
}
// defining overloaded friend function
ostream& operator << (ostream &out, clock &tm)
{
    out << "Time is: " << tm.hr << " hour : " << tm.min << " min : " << tm.sec << " sec";
    return out;
}


int main()
{
    clock t1(1,01,01);
    clock t2(1,01,01);
    if(t1 == t2)
    {
        cout << "Both the time values are equal";
    }   
    else 
    {
        cout << "Both the time values are not equal";
    }
    clock tm(1,01,01);
    cout <<endl;
	cout<< tm;
    return 0;
}
