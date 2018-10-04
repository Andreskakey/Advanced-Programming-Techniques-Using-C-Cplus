#include <iostream>
using namespace std;

void menu();
int read_accts(int acctnum_array[],double balance_array[], int max_accts);
int find_acct(int acctnum_array[], int num_accts, int requested_account);
void withdrawal(int acctnum_array[], double balance_array[], int num_accts);
void deposit (int acctnum_array[], double balance_array[], int num_accts);
int new_acct(int acctnum_array[], double balance_array[], int num_accts);
int delete_acct(int acctnum_array[], double balance_array[], int num_accts);
void balance_accts(int acctnum_array[], double balance_array[], int num_accts);
void print_acct(int acctnum_array[], double balance_array[], int num_accts);

const int max_num=8;

int main()
{

    int acctnum_array[max_num]={0,1,2,3,4,5};
    double balance_array[max_num]={50,200,700,1600,500,600};
    int num_accts=6;
    print_acct(acctnum_array, balance_array, num_accts);
    char selection;
    menu();
    cin >> selection;
    while (selection != 'Q' && selection != 'q'){
        switch(selection){
            case 'W':
            case 'w':
                withdrawal(acctnum_array, balance_array, num_accts );
                break;
            case 'D':
            case 'd':
                deposit(acctnum_array, balance_array, num_accts );
                break;
            case 'N':
            case 'n':
                num_accts=new_acct(acctnum_array, balance_array, num_accts );
                break;
            case 'B':
            case 'b':
                balance_accts(acctnum_array, balance_array, num_accts );
                break;
            case 'X':
            case 'x':
                num_accts=delete_acct(acctnum_array, balance_array, num_accts );
                break;
            case 'Q':
            case 'q':
                cout << "Thank your  for using bank abc. Please come again."<<endl;
                break;
            default:
                cout << "Invalid menu." << endl;
        }
        menu();
        cin>>selection;
    }
            print_acct(acctnum_array, balance_array, num_accts);
            return 0;
}

void menu(){
    cout << "Select one of the following:" << endl;
    cout << "W - Withdraw" << endl;
    cout << "D - Deposit"  << endl;
    cout << "N - New Account" << endl;
    cout << "B - Balance" << endl;
    cout << "Q - Quit" << endl;
    cout << "X - Delete Account" <<endl;
    cout << endl;
}

int find_acct(int acctnum_array[], int num_accts, int requested_account)
{
    for (int i=0;i<num_accts;i++){
        if (acctnum_array[i]==requested_account)
            return i;
    }
    return -1;
}

void withdrawal(int acctnum_array[], double balance_array[], int num_accts){

    int requested_account;
    cout<<"requesting account# "<<endl;
    cin>>requested_account;

    int acctnum=find_acct(acctnum_array,num_accts,requested_account);
    if(acctnum==-1)
    {
    cout << "ERROR, Invalid account "<<endl;
    return;
    }
    double withdraw;
    cout << "Enter Withdrawal Amount: ";
    cin >> withdraw;
    if (withdraw>balance_array[acctnum]){
        cout << "Insufficient Funds.\n";
        return;
    }
    balance_array[acctnum]-=withdraw;
    cout << "Successful Withdrawal.\n";
}

void deposit (int acctnum_array[], double balance_array[], int num_accts){
    int requested_account;
    cout<<"requesting acct"<<endl;
    cin>>requested_account;

    int acctnum=find_acct(acctnum_array,num_accts,requested_account);
    if(acctnum==-1){
        cout<<"Error Invalid Account"<<endl;
        return;
    }
    double amount;
    cout << "Enter the Deposit Amount: ";
    cin>>amount;
    balance_array[acctnum]+=amount;
    cout<<"Deposit Successful.\n";
    return;
}

int new_acct(int acctnum_array[], double balance_array[], int num_accts)
{
    int requested_account;
    cout<<"requesting account# "<<endl;
    cin>>requested_account;

    int pos = find_acct(acctnum_array,num_accts,requested_account);
    if (pos >= 0){
    cout << "Error! Account already exists." << endl;
    return num_accts;
    }

    if(num_accts<max_num){
        acctnum_array[num_accts]=requested_account;
        balance_array[num_accts]=0;
        num_accts++;

        cout<<"Creating new account in index: "<<num_accts<<endl;
    }
    else{
            cout<<"ERROR!, Too many account"<<endl;

    }
    return num_accts;
}

int delete_acct(int acctnum_array[], double balance_array[], int num_accts)
{
    int requested_account;
    cout<<"requesting account# "<<endl;
    cin>>requested_account;

    int numdelete=find_acct(acctnum_array,num_accts,requested_account);

      if (numdelete==-1){
      cout<<"Invalid account"<<endl;
      }
     else
     {
          cout<<"Closing account"<<endl;

          for (int i=numdelete;i<num_accts-1;i++)
          {
             acctnum_array[i]=acctnum_array[i+1];
             balance_array[i]=balance_array[i+1];
          }
            acctnum_array[num_accts]=0;
            balance_array[num_accts]=0.0;
            num_accts--;
            return num_accts;
    }

}

void balance_accts(int acctnum_array[], double balance_array[], int num_accts){

    int requested_account;
    cout<<"requesting account# "<<endl;
    cin>>requested_account;

    int acct_num=find_acct(acctnum_array, num_accts,requested_account);
    if (num_accts==-1 ){
    cout << "Invalid Account.\n" << endl;
    return;
    }
    cout<<"Your Balance is: $"<<balance_array[acct_num]<<endl;
    return;
}

void print_acct(int acctnum_array[], double balance_array[], int num_accts){
    for(int i=0; i<num_accts; i++){
    cout<<"ACCOUNT #" <<acctnum_array[i]<<endl;
    cout<<"BALANCE: $"<<balance_array[i]<<"\n"<<endl;
    }
    return;
}
