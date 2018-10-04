//There is some error that i can't still fill out yet 
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

int main()
{
    const int max_num=100;
    int acct_array[max_num]={0};
    double balance_array[max_num]={0};
    print_acct(acctnum_array[], balance_array[], num_accts);
    char selection;
    menu();
    cin >> selection;
    while (selection != 'Q' && selection != 'q'){
        switch(selection){
            case 'W':
            case 'w':
                withdrawal(acctnum_array[], balance_array[], num_accts );
                break;
            case 'D':
            case 'd':
                deposit(acctnum_array[], balance_array[], num_accts );
                break;
            case 'N':
            case 'n':
                new_acct(acctnum_array[], balance_array[], num_accts );
                break;
            case 'B':
            case 'b':
                balance_accts(acctnum_array[], balance_array[], num_accts );
                break;
            case 'X':
            case 'x':
                delete_acct(acctnum_array[], balance_array[], num_accts );
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
            print_acct(acctnum_array[], balance_array[], num_accts);
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

int find_acct(int acctnum_array[], int num_accts)
{
    int requested_account;
    cout << "input acct#";
    cin >> requested_account;
    for (int i=0;i<num_accts;i++){
        if (acctnum_array[i]=requested_account)
            return i;
    }
    return -1;
}

void withdrawal(int acctnum_array[], double balance_array[], int num_accts){

    int acctnum=find_acct(acctnum_array[],num_accts);
    if(acctnum==-1)
    {
    cout << "ERROR";
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
    int acctnum=find_acct(acctnum_array[],num_accts);
    if(acctnum_array==-1){
        cout<<"Error Invalid Account"<<endl;
        return;
    }
    double amount;
    cout << "Enter the Deposit Amount: ";
    cin>>amount;
  balance_array[acct_num]+=amount;
    cout<<"Deposit Successful.\n";
    return;
}

int new_acct(int acctnum_array[], double balance_array[], int num_accts)
{
    double amount;
    cout << "Enter the deposit." << endl
    cin>>amount;
    if(num_accts<max_num){
    acctnum_array[num_accts]=12345;
    balance_array[num_accts]=100;
    num_accts++;

    cout<<" account "<<num_accts<<endl;
    }
    else{
   int pos = find_acct(acctnum_array)
     if (pos >= 0){
    cout << "Error! Account already exists." << endl;
    return ;
    }
    return;
}

}
int deleteAcct(int acctnum_array[], double balance_array[], int num_accts)
{
     int req;
    cout<<"Enter the request "<<endl;
      cin >> req;
     int num_accts=find_acct(acctnum_array[],num_accts,req);
      if (acctnum_array==-1){
         cout<<"Invalid account"<<endl;
      }
     else
     {
          cout<<"Closing account"<<endl;
          num_accts--;
          for (int i=acctnum_array;i<num_accts;i++)
          {
             acctnum_array[i]=acctnum_array[i+1];
             balance_array[i]=balance_array[i+1];
          }
     }
     return num_accts;
}


void balance_accts(int acctnum_array[], double balance_array[], int num_accts){
    int acct_num=find_acct(acctnum_array, num_accts);
    if (num_accts==-1 ){
    cout << "Invalid Account.\n" << endl;
    return;
    }
    cout<<"Your Balance is: $"<<balance_array[acct_num]<<endl;
    return;
}

void print_acct(int acctnum_array[], double balance_array[], int num_accts){
    for(int i=0; i<num_accts; i++){
    cout<<"YOUR ACCOUNT INFORMATION. "<<endl;
    cout<<"ACCOUNT #" <<acctnum_array[i]<<endl;
    cout<<"BALANCE: $"<<balance_accts[i]<<endl;
    cout<<"NUMBER OF ACCOUNT: "<<num_accts<<endl;
    }
    return;
}

