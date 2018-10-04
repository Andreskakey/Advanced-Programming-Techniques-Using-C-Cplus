#include <iostream>
using namespace std;
void menu();

void withdrawal(int acctnum, double &balance ){
    int n;
    cout << "Enter Account Number: ";
    cin >> n;
    if (n!=acctnum){
    cout << "Invalid account number.\n";
    return;
    }
    double withdraw;
    cout << "Enter Withdrawal Amount: ";
    cin >> withdraw;
    if (withdraw>balance){
    cout << "Insufficient Funds.\n";
    return;
    }
    balance-=withdraw;
    cout << "Successful Withdrawal.\n";
}

void deposit (int acctnum, double &balance){
    double amount;
    int n;
    cout << "Enter Account Number: ";
    cin >>n;
    if (n!=acctnum ){
    cout << "Invalid Account Number.\n";
    return;
    }
    cout << "Enter the Deposit Amount: ";
    cin>>amount;
    balance+=amount;
    cout<<"Deposit Successful.\n";
    return;
}

void deleteAcct(int acctnum, double &balance){
    int n;
    cout << "Enter Account Number To Delete Account: ";
    cin >>n;
    if (n!=acctnum ){
    cout << "Invalid Account." << endl;
    return;
    }
    balance=0;
    cout << "Deletion Successful\n";
    return;
}

void balance(int acctnum, double balance){
    int n;
    cout << "Enter Account Number To See The Balance: ";
    cin >>n;
    if (n!=acctnum ){
    cout << "Invalid Account.\n" << endl;
    return;
    }
    cout<<"Your Balance is: $"<<balance<<endl;
    return;
}

void printAcc(int acctnum, double balance){
    cout<<"YOUR ACCOUNT INFORMATION. "<<endl;
    cout<<"ACCOUNT #" <<acctnum<<endl;
    cout<<"BALANCE: $"<<balance<<endl;
}

int main()
{
    int accountNum=1234567; //int accountNum[];
    double  accbalance=500.00;  //int accbalance[];
    printAcc(accountNum,accbalance);
    char selection;
    while (selection != 'Q' && selection != 'q'){
        menu();
        cin >> selection;
        switch(selection){
            case 'W':
            case 'w':
                withdrawal( accountNum, accbalance );
                break;
            case 'D':
            case 'd':
                deposit(accountNum, accbalance );
                break;
            case 'B':
            case 'b':
                balance(accountNum, accbalance );
                break;
            case 'X':
            case 'x':
                deleteAcct(accountNum, accbalance );
                break;
            case 'Q':
            case 'q':
                cout << "Thank your  for using bank abc. Please come again."<<endl;
                break;
            default:
                cout << "Invalid menu. " << endl;
        }
    }
            printAcc(accountNum,accbalance);
            return 0;
}

void menu(){
    cout << "Select one of the following:" << endl;
    cout << "W - Withdraw" << endl;
    cout << "D - Deposit"  << endl;
    cout << "B - Balance" << endl;
    cout << "Q - Quit" << endl;
    cout << "X - Delete Account" <<endl;
    cout << endl;
}
