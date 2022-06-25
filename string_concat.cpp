#include<iostream>
#include<string>
using namespace std;
class stringType
{
	private:
		string str1;
		string str2;
		
	public:
		//Default constructor
		stringType()
		{
			str1=("");
			str2=("");
			
		}
		//set value function
		void setvalues(string st1, string st2)
		{
			str1=st1;
			str2=st2;
		}
		//print value function
		void printvalues()
		{
			cout<<str1<<str2<<endl;
		}
		//concatenate function
		string catenation(string str1, string str2)
		{
			string result;
			cout<<"Enter string 1 : "<<str1<<endl;
			cout<<"Enter string 2 :"<<str2<<endl;
			result= str1 + str2;
			cout<<"catenation :"<<result<<endl;
			return result;
			
		}
		// Max length function
		int length(string str1,string str2)
		{
			int count1=0;
			for(int i=0;str1[i]!='\0';i++)
			{
				count1++;
			}
			int count2=0;
			for(int j=0;str2[j];j++)
			{
				count2++;
			}
			if(count1==count2)
			{
				return count1;
			}
			if(count1>count2)
			{
				return count1;
			}
			else if(count1<count2)
			{
				return count2;
			}
			
			
		}
		//comparing string function
		int comparing(string str1,string str2)
		{
			int count1=0;
			for(int i=0;str1[i]!='\0';i++)
			{
				count1++;
			}
			int count2=0;
			for(int j=0;str2[j];j++)
			{
				count2++;
			}
			if(count1==count2)
			{
				cout<<"Both are equal"<<endl;
				return 2;
			}
			else if(count1>count2)
			{
				cout<<"str1 1 is greater"<<endl;
				return 0;
			}
			else if(count1<count2)
			{
				cout<<"str2 is greater"<<endl;
				return 1;
			}
				
		}
		//search function
		int searchwords(string str1,string str2)
		{
		    char chars[200], word[20];
	        int i=0, c=0;
	
	        cout<<"Enter a paragraph: ";
	        gets (chars);
	
	        cout<<"Enter the word you want to search: ";
	        gets (word);
	
	        while (chars[i]!='\0')
	        {
		        if (chars[i]==word[c] && word[c]!='\0' && word[i]!=' ')
		         c++;
		         else
		         c=0;
		
		        i++;
	        }
	        
		}
		

	
		
};
int main()
{
	stringType sob;
	string a;
	string b;
	cout<<"Enter first string"<<endl;
	cin>>a;
	cout<<"Enter second string"<<endl;
	cin>>b;
	sob.setvalues(a,b);
	sob.printvalues();
	sob.catenation(a,b);
	sob.length(a,b);
	sob.comparing(a,b);
	sob.searchwords(a,b);
	system("pause");
	return 0;	
}
