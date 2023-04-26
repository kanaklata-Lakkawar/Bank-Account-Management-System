#include <iostream>

using namespace std;

class AccountHolder
{
public:
   
    string fname;
    string lname;
    string mname;
    string add;
    string uname;
    string pass;
    string tuname;
    string rname;
    int aType;//cbalanace
    int balance=0,damt=0,wamt=0,tamt=0,ramt=0;
    int wcount=0;
              string tempUname;
              string tempPass;
              string tempFname;
              string tempLname;
              string tempMname;
              string tempadd;
              int tempaType;
              AccountHolder()
              {
                  fname="UNKNOWN";
                  lname="UNKNOWN";
                  mname="UNKNOWN";
                  uname="NOT SET";
                  pass="NOT SET";
                  add="UNKNOWN";
                  aType=0;
              }

    void createAcct(AccountHolder a[],int n)
{
         cout<<"---------------------------::CREATE ACCOUNT::-------------------"<<endl;
        cout<<"ENTER FIRST NAME :";
        cin>>fname;
        cout<<"OK.."<<endl;
        cout<<"ENTER LAST NAME :";
        cin>>lname;
        cout<<"OK.."<<endl;
        cout<<"ENTER MOTHER'S NAME :";
        cin>>mname;
        cout<<"OK.."<<endl;
        cout<<"ENTER ADDRESS :";
        cin>>add;
        cout<<"OK.."<<endl;
    cout<<"CREATE USERANME :";
    cin>>uname;
    cout<<"CREATE PASSWORD :";
    cin>>pass;
    cout<<"1.SAVING ACCOUNT"<<endl;
    cout<<"2.CURRENT ACCOUNT"<<endl;
    cout<<"SELECT ACCOUNT TYPE :";
    cin>>aType;
    switch(aType)
    {
       case 1:
             cout<<"SAVING ACCOUNT"<<endl;
             break;
       case 2:
            cout<<"CURRENT ACCOUNT"<<endl;
            break;
    }
        cout<<endl<<"ACCOUNT CREATED SUCCESSFULLY..."<<endl;
}

void loginAcct(AccountHolder a[], int n,int i)
{
cout<<"WELCOME "<<fname<<endl;
int lp1=1;
while(lp1)
{
    {
    cout<<"1.CHECK BALANCE "<<endl;
    cout<<"2.DEPOSIT CASH"<<endl;
    cout<<"3.WITHDRAWL CASH"<<endl;
    cout<<"4.TRANSFER MONEY"<<endl;
    cout<<"5.ACCOUNT INFORMATION"<<endl;
    cout<<"6.UPDATE INFORMATION"<<endl;
    cout<<"0.BACK TO MAIN MENU"<<endl;
    }
    int ch1;
    cout<<"ENTER YOUR CHOICE :";
    cin>>ch1;
    switch(ch1)
    {
    case 1:
           checkBalance(a,n);
           break;
    case 2:
           depositCash();
           break;
    case 3:
           withdrawlCash();
           break;
    case 4:
           transferMoney(a,n);
           break;
    case 5:
           acctInfo(a,n);
          break;
    case 6:
        {
          updateAccount();
        }
        break;
    case 0:lp1=0;
    break;

    }
}
wcount=0;
}
void checkBalance(AccountHolder a[],int n)
{
            cout<<"-----------::BALANCE DASHBOARD::-------------"<<endl;
            cout<<"-----------------------------------------"<<endl;
            cout<<"TRANSACTION"<<"  | "<<"AMOUNT"<<endl;
            cout<<"-----------------------------------------"<<endl;
             if(damt!=0)
            cout<<"CASH DEPOSIT"<<"   "<<"+"<<damt<<endl;
            if(wamt>0)
            cout<<"CASH WITHDRAWL"<<"   "<<"-"<<wamt<<endl;
            if(tamt>0)
            cout<<"CASH TRANSFERRED TO "<<tuname<<" "<<"-"<<tamt<<endl;
            for(int i=0;i<n;i++)
            {
            if(balance>=ramt && uname==a[i].tuname)
            cout<<"CASH RECIEVEDED FROM "<<"  "<<a[i].uname<<" "<<"+"<<ramt<<endl;
            }
            cout<<"-----------------------------------------"<<endl;
            cout<<"ACCOUNT BALANCE :"<<balance<<endl<<endl;
}
void depositCash()
{
          cout<<"-----------::DEPOSIT CASH::----------------"<<endl;
          cout<<"CURRENT BALANCE :"<<balance<<endl;
          cout<<"ENTER DEPOSIT AMOUNT :";
          cin>>damt;
          balance+=damt;
         cout<<"CASH DEPOSITED SUCCESSFULLY..."<<endl;
         cout<<"OK..."<<endl;
}
void withdrawlCash()
{
        cout<<"-----------::WITHDRAWL CASH::----------------"<<endl;
        cout<<"CURRENT BALANCE :"<<balance<<endl;
        cout<<"ENTER WITHDRAWL AMOUNT :";
        cin>>wamt;
          if(balance>wamt)
           {
        balance-=wamt;
         cout<<"CASH WITHDRAWL SUCCESSFULLY..."<<endl;
         cout<<"OK..."<<endl;
        }
       else
       {
         cout<<"INSUFFICIENT BALANCE !!!"<<endl;
         wamt=0;
       }

}
 void transferMoney(AccountHolder a[],int n)
{
cout<<"-----------::TRANSFER CASH::----------------"<<endl;
        cout<<"CURRENT BALANCE :"<<balance<<endl;
        cout<<"ENTER THE AMOUNT TO BE TRANSFER :";
        cin>>tamt;
        if(tamt<balance)
        {
            cout<<"ENTER USERNAME :";
            cin>>tuname;
            for(int i=0;i<n;i++)
            {
                if(tuname==a[i].uname)
                {
                a[i].balance=a[i].balance+tamt;
                a[i].ramt=a[i].balance;
                balance-=tamt;
                cout<<"TRANSFERRED TO "<<tuname<<endl;
                cout<<"OK..."<<endl;
                cout<<"AMOUNT TRANSFERRED SUCCESSFULLY.."<<endl;
                }
            }
        }
       else
       {
         cout<<"INSUFFICIENT BALANCE!!!"<<endl;
        tamt=0;
       }
}
void acctInfo(AccountHolder a[], int n)
{
          cout<<"-----------------------::ACCOUNT INFORMATION::----------------------"<<endl;
          cout<<"ACCOUNT TYPE :";
    switch(aType)
    {
       case 1:
           cout<<"SAVING ACCOUNT"<<endl;
               break;
        case 2:
            cout<<"CURRENT ACCOUNT"<<endl;
               break;
    }
             cout<<"USERNAME :"<<uname<<endl;
             cout<<"PASSWORD :"<<pass<<endl;
             cout<<"FIRST NAME :"<<fname<<endl;
             cout<<"LAST NAME :"<<lname<<endl;
             cout<<"MOTHER NAME :"<<mname<<endl;
             cout<<"ADDRESS  :"<<add<<endl;
             cout<<"ok.."<<endl;

}

void updateAccount()
{
  cout<<"-------------------::UPDATE INFORMATION::-------------------------"<<endl;
  int lp3=1;
  while(lp3)
  {
    {
    cout<<"1.ACCOUNT TYPE :"<<endl;
    cout<<"2.USERNAME"<<endl;
    cout<<"3.PASSWORD"<<endl;
    cout<<"4.FIRST NAME"<<endl;
    cout<<"5.LAST NAME"<<endl;
    cout<<"6.MOTHER NAME"<<endl;
    cout<<"7.ADDRESS"<<endl;
    cout<<"0.BACK TO MAIN MENU"<<endl;
   }
   int ch4;
   cout<<"ENTER YOUR CHOICE :";
   cin>>ch4;
  switch(ch4)
              {
              case 1:
                {
cout<<"-------------------::UPDATE ACCOUNT TYPE::-------------------------"<<endl;
              cout<<"CURRENT ACCOUNT TYPE IS "<<aType<<endl;
              cout<<"1.SAVING ACCOUNT"<<endl;
              cout<<"2.CURRENT ACCOUNT"<<endl;
              cout<<"SELECT ACCOUNT TYPE :"<<endl;
              cin>>tempaType;
              switch(tempaType)
    {
        case 1:
           cout<<"SAVING ACCOUNT"<<endl;
               break;
        case 2:
            cout<<"CURRENT ACCOUNT"<<endl;
               break;
    }

              cout<<"DO YOU REALLY WANT TO CHANGE "<<aType<<" TO "<<tempaType<<endl;
              cout<<"1. YES"<<endl<<"2. NO"<<endl;
              cout<<"ENTER YOUR CHOICE :";
              int ch;
              cin>>ch;
              switch(ch)
              {
              case 1:
                 aType=tempaType;
                 cout<<"OK ACCOUNT TYPE UPDATED..."<<endl;
                break;
              case 2:
                cout<<"OK ACCOUNT IS NOT UPDATED..."<<endl;
                break;
              }
                }
                break;
            case 2:
                {
              cout<<"-------------------::UPDATE USERNAME::-------------------------"<<endl;
              cout<<"CURRENT NAME IS "<<uname<<endl;
              cout<<"ENTER NEW NAME :";
              cin>>tempUname;
              cout<<"DO YOU REALLY WANT TO CHANGE "<<uname<<" TO "<<tempUname<<endl;
              cout<<"1. YES"<<endl<<"2. NO"<<endl;
              cout<<"ENTER YOUR CHOICE :";
              int ch;
              cin>>ch;
              switch(ch)
              {
              case 1:
                 uname=tempUname;
                 cout<<"OK NAME UPDATED..."<<endl;
                break;
              case 2:
                cout<<"OK NAME IS NOT UPDATED..."<<endl;
                break;
              }
                }
                break;
                         case 3:
                {
                 cout<<"-------------------::UPDATE PASSWORD::-------------------------"<<endl;
              cout<<"CURRENT PASSWORD IS "<<pass<<endl;
              cout<<"ENTER NEW NAME :";
              cin>>tempPass;
              cout<<"DO YOU REALLY WANT TO CHANGE "<<pass<<" TO "<<tempPass<<endl;
              cout<<"1. YES"<<endl<<"2. NO"<<endl;
              cout<<"ENTER YOUR CHOICE :";
              int ch;
              cin>>ch;
              switch(ch)
              {
              case 1:
                 pass=tempPass;
                 cout<<"OK PASSWORD UPDATED..."<<endl;
                break;
              case 2:
                cout<<"OK PASSWORD IS NOT UPDATED..."<<endl;
                break;
              }
                }
                break;
                case 4:
                {
                 cout<<"-------------------::UPDATE FIRST NAME::-------------------------"<<endl;
              cout<<"CURRENT FIRST NAME IS "<<fname<<endl;
              cout<<"ENTER NEW FIRST NAME :";
              cin>>tempFname;
              cout<<"DO YOU REALLY WANT TO FIRST CHANGE "<<fname<<" TO "<<tempFname<<endl;
              cout<<"1. YES"<<endl<<"2. NO"<<endl;
              cout<<"ENTER YOUR CHOICE :";
              int ch;
              cin>>ch;
              switch(ch)
              {
              case 1:
                 fname=tempFname;
                 cout<<"OK FIRST NAME UPDATED..."<<endl;
                break;
              case 2:
                cout<<"OK FIRST NAME IS NOT UPDATED..."<<endl;
                break;
              }

                }
                break;
                case 5:
                {
                 cout<<"-------------------::UPDATE LAST NAME::-------------------------"<<endl;
              cout<<"CURRENT LAST NAME IS "<<lname<<endl;
              cout<<"ENTER NEW LAST NAME :";
              cin>>tempLname;
              cout<<"DO YOU REALLY WANT TO CHANGE "<<lname<<" TO "<<tempLname<<endl;
              cout<<"1. YES"<<endl<<"2. NO"<<endl;
              cout<<"ENTER YOUR CHOICE :";
              int ch;
              cin>>ch;
              switch(ch)
              {
              case 1:
                 lname=tempLname;
                 cout<<"OK LAST NAME UPDATED..."<<endl;
                break;
              case 2:
                cout<<"OK LAST NAME IS NOT UPDATED..."<<endl;
                break;
              }
                }
                break;
                case 6:
                {
                cout<<"-------------------::UPDATE MOTHER's NAME::-------------------------"<<endl;
              cout<<"CURRENT MOTHER NAME IS "<<mname<<endl;
              cout<<"ENTER MOTHER'S NEW NAME :";
              cin>>tempMname;
              cout<<"DO YOU REALLY WANT TO CHANGE "<<mname<<" TO "<<tempMname<<endl;
              cout<<"1. YES"<<endl<<"2. NO"<<endl;
              cout<<"ENTER YOUR CHOICE :";
              int ch;
              cin>>ch;
              switch(ch)
              {
              case 1:
                 mname=tempMname;
                 cout<<"OK MOTHER'S NAME IS UPDATED..."<<endl;
                break;
              case 2:
                cout<<"OK MOTHER'S NAME IS NOT UPDATED..."<<endl;
                break;
              }
                }
                break;
                case 7:
                {
                 cout<<"-------------------::UPDATE ADDRESS::-------------------------"<<endl;
              cout<<"CURRENT ADDRESS IS "<<add<<endl;
              cout<<"ENTER NEW ADDRESS :";
              cin>>tempadd;
              cout<<"DO YOU REALLY WANT TO CHANGE "<<add<<" TO "<<tempadd<<endl;
              cout<<"1. YES"<<endl<<"2. NO"<<endl;
              cout<<"ENTER YOUR CHOICE :";
              int ch;
              cin>>ch;
              switch(ch)
              {
              case 1:
                 add=tempadd;
                 cout<<"OK ADDRESS IS UPDATED..."<<endl;
                break;
              case 2:
                cout<<"OK ADDRESS IS NOT UPDATED..."<<endl;
                break;
              }
              }
         case 0:lp3=0;
                break;
                }
  }
}
};
int menu()
{
    int ch;
    cout<<"1.CREATE ACCOUNT"<<endl;
    cout<<"2.LOGIN ACCOUNT"<<endl;
    cout<<"0.EXIT"<<endl;
    cout<<"ENTER YOUR CHOICE :";
    cin>>ch;
    return ch;
}
int main()
{
   int n,choice,lp=1;
AccountHolder a[15];
              string uname;
              string pass;
              int wcount=0;
              cout<<"::WELCOME TO BANK::"<<endl<<endl;
   while(lp)
         {
   choice= menu();
switch(choice)
{
   case 1:
         a[n].createAcct(a,n);
         n++;
    break;
     case 2:
    {
     cout<<"---------------------------::LOGIN ACCOUNT::-------------------"<<endl;
        cout<<"USERNAME :";
        cin>>uname;
        cout<<"PASSWORD :";
        cin>>pass;
        for(int i=0;i<n;i++)
     {
       if(a[i].uname==uname && a[i].pass==pass)
       {
           cout<<"LOGIN SUCCESSFULY.."<<endl;
           a[i].loginAcct(a,n,i);
       }
       else
        {
        wcount++;
        }
        if(wcount==n)
        {
            cout<<"WRONG USERNAME"<<endl;
            wcount=0;
        }
}
}
    break;
    case 0:
           cout<<"THANK YOU FOR VISITING OUR BANK...";
           lp=0;
          break;
    default:
            cout<<"CHOOSE CORRECT OPTION !!!"<<endl;
        break;
}
}
    return 0;
}

