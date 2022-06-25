#include <iostream>
using namespace std;
class Bank{
public:
   double balance;
   double deposits;
   double serviceCharges;
   double withdrawals;
   double minimumbalance;
   double interestRate;
   string description;
   bool writeChecks;
   int accountnumber;
   string nameofowner;
   };

class Saving:public Bank{
public:
   int n;
   Saving(){
   cout<<"Saving Account created"<<endl;
   cout<<"one account:no minimum balance and lower interest rate"<<endl;
   cout<<"another account:minimum balance and highest interest rate"<<endl;
      balance=0.0;
      deposits=0.0;
      serviceCharges=0.0;
      withdrawals=0.0;
      minimumbalance=0.0;
      interestRate=0.0;
   }

   Saving(double val){
      balance=val;
   }

   double getbalance(){
      return balance;
   }

   void deposit(double money){
      if(money>0){
      balance+=money;
      deposits++;
   }
   else{
      cout<<"Amount can not be deposited";
   }
   }

   void withdraw(double money){
      if(money<=balance){
         balance-=money;
         withdrawals++;
   }
   else{
      cout<<"Not possible as Balance is:"<<balance<<" and you want money:"<<money;
   }

   }
   void calculateinterest(){
      double monthlyInterestRate=interestRate/12;
      double monthlyInterest=balance*monthlyInterestRate;
      balance+=monthlyInterest;
   }

   void getstats(){
      cout<<"\nWithdrawals:"<<withdrawals
      <<"\nDeposits:"<<deposits
      <<"\nBalance:"<<balance<<endl;
   }

   void accountselection(){
      cout<<"\nEnter account you want to make and maintain:(1,2 for different accounts)";
      cin>>n;
      if(n==1){
         cout<<"Savingfirsttype\n";
         cout<<"one account:no minimum balance and lower interest rate";
         minimumbalance=0;
         interestRate=2.0;
         calculateinterest();
         getstats();
      }
      if(n==2){
         cout<<"Saving second type\n";
         cout<<"another account:minimum balance and highest interest rate";
         minimumbalance=20;
         if(balance<minimumbalance){
            cout<<"\nDeposit first because balance is less than minimumbalance";
         }
         interestRate=10.0;
         calculateinterest();
         getstats();
      }
   }
};

class Checking:public Bank{
public:
   int checkwriting;
   int checkwritten;
   int n;
   Checking(){
   cout<<"Checking Account created"<<endl;
   cout<<"one account:monthly service charge,limited check writing,no minimum balance and no interest rate"<<endl;
   cout<<"another account:no monthly service charge,minimum balance requirement,unlimited check writing,lowerinterest rate"<<endl;
   cout<<"third account:no monthly service charge,higher minimum balance requirement,higher interest rate,unlimited check writing"<<endl;
   balance=0.0;
   deposits=0.0;
   serviceCharges=5.0;
   withdrawals=0.0;
   minimumbalance=0.0;
   interestRate=0.0;
   checkwriting=0;
   checkwritten=0;
   }

   double getbalance(){
      return balance;
   }

   void deposit(double money){
   if(money>0){
      balance+=money;
      deposits++;
   }
   else{
      cout<<"Amount can not be deposited";
   }
   }

   void withdraw(double money){
      if(money<=balance){
         balance-=money;
         withdrawals++;
   }
   else{
      cout<<"Not possible as Balance is:"<<balance<<" and you want money:"<<money;
   }
   }

   void calculateinterest(){
      double monthlyInterestRate=interestRate/12;
      double monthlyInterest=balance*monthlyInterestRate;
      balance+=monthlyInterest;
   }

   void monthlyservicecharge(){
      calculateinterest();
      balance-=serviceCharges;
   }

   void setcheckwriting(double money){
      if(money<=balance){
         balance-=money;
         withdrawals++;
   }
   else{
      cout<<"Not possible as Balance is:"<<balance<<" and you want money:"<<money;
   }
   }

   void getstats(){
      cout<<"\nWithdrawals:"<<withdrawals
      <<"\nDeposits:"<<deposits
      <<"\nBalance:"<<balance<<endl;
   }

   void accountselection(){
      cout<<"\nEnter account you want to make and maintain:(1,2,3 for different accounts)";
      cin>>n;
      if(n==1){
         cout<<"\nChecking first type\n";
         cout<<"one account:monthly service charge,limited check writing,no minimum balance and no interest rate";
         minimumbalance=0.0;
         interestRate=0.0;
         checkwriting=2;
         double value=0.0;
         char ch;
         int count=0;
         while(count<checkwriting){
            cout<<"\nDo you want to write a check:(Y for Yes)";
            cin>>ch;
            count++;
            if(ch=='Y'){
               cout<<"\nEnter amount to withdraw:";
               cin>>value;
               setcheckwriting(value);
            }
            else{
               break;
            }
      }
      monthlyservicecharge();
      getstats();
      }
      if(n==2){
         cout<<"\nChecking second type\n";
         cout<<"another account:no monthly service charge,minimum balance requirement,unlimited check writing,lowerinterest rate";
         minimumbalance=20;

      if(balance<minimumbalance){
         cout<<"\nDeposit first because balance is less than minimumbalance";
      }
      checkwriting=100;
      double value=0.0;
      char ch;
      int count=0;
      while(count<=checkwriting){
         cout<<"\nDo you want to write a check:(Y for Yes)";
         cin>>ch;
         count++;
         if(ch=='Y'){
            cout<<"\nEnter amount to withdraw:";
            cin>>value;
            setcheckwriting(value);
         }
         else{
            break;
         }
      }

      interestRate=2.0;
      calculateinterest();
      getstats();
      }
      if(n==3){
         cout<<"\nChecking third type\n";
         cout<<"third account:no monthly service charge,higher minimum balance requirement,higher interest rate,unlimited check writing";
         minimumbalance=20;
         if(balance<minimumbalance){
            cout<<"\nDeposit first because balance is less than minimumbalance";
         }
         checkwriting=100;
         double value=0.0;
         char ch;
         int count=0;
         while(count<=checkwriting){
            cout<<"\nDo you want to write a check:(Y for Yes)";
            cin>>ch;
            count++;
            if(ch=='Y'){
               cout<<"\nEnter amount to withdraw:";
               cin>>value;
               setcheckwriting(value);
            }
            else{
               break;
            }
         }

         interestRate=10.0;
         calculateinterest();
         getstats();
      }
   }
};
class certificateofDeposit:public Bank{
public:
   int maturitymonths;
   certificateofDeposit(){
   cout<<"\nCertificate of Deposit created"<<endl;
   balance=0.0;
      deposits=0.0;
      serviceCharges=5.0;
      withdrawals=0.0;
      minimumbalance=0.0;
      interestRate=15.0;
      maturitymonths=0;
   }

   double getbalance(){
      return balance;
   }
   void deposit(double money,int numberofmonths){
      if(money>0){
         balance+=money;
         maturitymonths=numberofmonths;
         calculateinterest();
         deposits++;
      }
      else{
         cout<<"Amount can not be deposited";
      }
   }
   void withdraw(double money,int numberofmonths){
      if(numberofmonths== maturitymonths){
         if(money<=balance){
            balance-=money;
            withdrawals++;
         }
         else{
            cout<<"Not possible as Balance is:"<<balance<<" and you want money:"<<money;
         }
      }
   }
   void calculateinterest(){
      double monthlyInterestRate=interestRate/12;
      double monthlyInterest=balance*monthlyInterestRate;
      balance+=monthlyInterest;
   }
   void getstats(){
      cout<<"\nWithdrawals:"<<withdrawals
      <<"\nDeposits:"<<deposits
      <<"\nMaturity months:"<<maturitymonths
      <<"\nBalance:"<<balance<<endl;
   }
};
int main(){
//Saving s(23);
//Bank *b;
Saving s;
//b=&s;
s.deposit(10);
double z=s.getbalance();
cout<<z;
s.getstats();
//s.withdraw(20);
///s.getstats();
s.accountselection();
//cout<<s.balance;

/*Checking c;
c.deposit(100);
double y=c.getbalance();
cout<<y;
c.accountselection();
*/
/*certificateofDeposit d;
d.deposit(100,2);
double x=d.getbalance();
cout<<x;
d.getstats();
d.withdraw(100,2);
d.getstats();*/
}
