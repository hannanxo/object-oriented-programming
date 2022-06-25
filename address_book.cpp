#include<iostream>                      
#include<fstream>
#include<string>  
using namespace std;

//declaring class for address 
class addressType                        
{
//access specifiers
private:
	string address;
	string city;
	string state;
	int zip_code;

public:
	//Copy Constructor 
	addressType(const addressType &obj)
	{
		address=obj.address;
		city=obj.city;
		state=obj.state;
		zip_code=obj.zip_code;
	}
//making constructor for class address
	addressType()               
	{
		address = "";
		city = "";
		state = "";
		zip_code = 0;
	}

//msking set functions for address
	void setaddress(string s)
	{
		address = s;
	}

	void setcity(string s)
	{
		city = s;
	}

	void setstate(string s)
	{
		state = s;
	}

	void setzip(int a)
	{
		zip_code = a;
	}
//making get functions
	string getaddress()
	{
		return address;
	}

	string getcity()
	{
		return city;
	}

	string getstate()
	{
		return state;
	}
	int getzip()
	{
		return zip_code;
	}
	//making friend function of displayAll to addresstype
	friend void displayAll();
};

//declaring class for data type
class datatype                        
{
	//access specifiers
private:
	int dyear;
	int dmonth;
	int dday;

public:
	//making constructor
	datatype(int month, int day, int year)
	{
		dyear = year;
		dmonth = month;
		dday = day;
	}

	datatype()
	{
		dyear = 1900;
		dmonth = 1;
		dday = 1;
	}
	// set function
	void setdate(int month, int day, int year)
	{
		dmonth = month;
		dday = day;
		dyear = year;
	}
//making get get function
	int getday() const
	{
		return dday;

	}

	int getmonth() const
	{
		return dmonth;
	}

	int getyear() const
	{
		return dyear;
	}

//making print function
	void printdate() const
	{
		cout << dmonth << "/" << dday << "/" << dyear;
	}
};

//declaring class for person
class persontype                                     
{
	//access specifiers
private:
	string firstname;
	string lastname;
public:
//making default constructor for class person type
	persontype()                           
	{
		string first = "";
		string last = "";
	}
//making print function
	void print() const
	{
		cout << firstname << " " << lastname;
	}
//making set functions
	void setname(string first, string last)
	{
		firstname = first;
		lastname = last;
	}
//making get functions for first and last name
	string getfirstname() const
	{
		return firstname;
	}

	string getlastname() const
	{
		return lastname;
	}


};


//declaring child class inherited from address,person and data class
class extpersontype :public addressType, public persontype,public datatype                   
{
	//access specifiers
private:
	int num;
	string relation;
	string nickName;
public:
	
// default constructor
	extpersontype()            
	{
		relation = "";
		num = 0;
	}
//making set function
	void setphone(int p)
	{
		num = p;
	}
	void setrelation(string r)
	{
		relation = r;
	}
//making get function
	int getphone()
	{
		return num;
	}

	string getrelation()
	{
		return relation;
	}
//making print function
	void printp()
	{
		cout << num << endl;
	}

	void printr()
	{
		cout << relation << endl;
	}
	//making friend class of myfriend class to extperson class
	friend class myfriend;
	
};
//declaring friend class of myFriend to extperson
class myFriend
{
	//access specifiers
	private:
	string name;
	int  age;
	
	public:
		//making constructor
		myFriend()
		{
			string name="";
			int age=0;
			string nickName="";
		}
		//making set function for nickName
		void setnickName(extpersontype Obj)
		{
			string nk;
			Obj.nickName = nk;
		}
		string getnickName(extpersontype Obj)
		{
			return Obj.nickName;
		}
};

//declaring addressbook class 
class addressbooktype
	{
		//access specifiers
	private:
		static const int MAX_ENTRIES = 2;
	public:
		//declaring array 
		extpersontype ex[500];
	};
//making search function
	void searchlast(addressbooktype Obj, string last)
	{
		int i = 0;
		while (i != 500)
		{
			if (Obj.ex[i].getlastname() == last)
				Obj.ex[i].print();
			i++;
		}
	}
//making print function for address
	void printAddress(addressbooktype Obj, string first, string last)
	{
		int i = 0;
		while (i != 500)
		{
			if (Obj.ex[i].getfirstname() == first && Obj.ex[i].getlastname() == last)
			{
				cout << Obj.ex[i].getaddress();
				cout << Obj.ex[i].getstate();
				cout << Obj.ex[i].getcity();
				cout << Obj.ex[i].getzip();
				Obj.ex[i].printp();
				Obj.ex[i].printdate();
			}
			i++;
		}
	}
//making print functin for month
	void printMonth(addressbooktype Obj, int month)
	{
		int i = 0;
		while (i != 500)
		{
			if (Obj.ex[i].getmonth() == month)

				Obj.ex[i].printdate();
		}
	}
//making print request functon
	void printRequest(addressbooktype Obj, string r)
	{
		int i = 0;
		while (i != 500)
		{
			if (Obj.ex[i].getrelation() == r)

				Obj.ex[i].print();
		}
	}
//making DisplayAll functiom
   void displayAll(addresstype Obj)
   {
   	
   }
//making birthday function
	void bDaySearch(addressBookType Obj ,int month)
	{
	    for(int i = 0; i < MAX_ENTRIES; i++)
		{
		     if(addrBook[i].getBday() == month)
			{
			     addrBook[i].printNames();
				 cout << endl;
			}
		}
	}


   
int main()
{
    addressBookType Obj;
    string first,last,r;
    int month;
    int option;
    cout<<"press 1 for display all"<<endl;
    cout<<"press 2 for birthday search"<<endl;
    cout<<"press 3 for print requet"<<endl;
    cout<<"press 4 for to print month"<<endl;
    cout<<"press 5 for printing address"<<endl;
    cout<<"press 6 for  search"<<endl;
   
    cin>>option;
    if(option==1)
    {
    	Obj.displayAll();
	}
	else if(option==2)
    {
	    cout<<"enter month"<<endl;
    	cin>>month;
    	Obj.bDaySearch(month);
	}
	else if(option==3)
    {
    	cin>>r;
    	Obj.printRequest(r);
	}
    else if(option==4)
    {
    	cout<<"enter month"<<endl;
    	cin>>month;
    	Obj.printMonth(month);
	}
	else if(option==5)
    {
    	cout<<"enter first and last name"<<endl;
    	cin>>first;
    	cin>>last;
    	Obj.printAddress(first,last);
	}
	else if(option==6)
    {
    	cin>>last;
    	Obj.searchlast(last);
	}
	return 0;
}
    
    





