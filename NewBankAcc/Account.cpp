  #include <iostream>

    using namespace std;
    void menu();

void withdrawal(int acctnum, double &balance ){
    double amount;
    int n;
    cout << "PLEASE ENTER ACCOUNT NUMBER :" << endl;
    cin >>n;
    if (n!=acctnum ){
        cout << "WRONG ACCOUNT  PLEASE TRY AGAIN" << endl;

    }
    else

    cout << "HOW MUCH DO YOU WANT TO WITHDRAWAL?" << endl;
    cin>>amount;
    if(amount<=balance){
    balance-=amount;
      cout<<"ACCOUNT #" <<acctnum<<" BALANCE : $"<<balance<<endl;
    }
    else
      cout << "INSUFFICIENT FUND" << endl;

}
void deposit (int acctnum, double &balance){
    double amount2;
    int n2;
    cout << "PLEASE ENTER ACCOUNT NUMBER :" << endl;
    cin >>n2;
    if (n2!=acctnum ){
        cout << "WRONG ACCOUNT  PLEASE TRY AGAIN" << endl;

    }
    else
    cout << "HOW MUCH DO YOU WANT TO DEPOSIT  " << endl;
    cin>>amount2;
    balance+=amount2;
    cout<<"ACCOUNT #" <<acctnum<<" BALANCE : $"<<balance<<endl;
}
/*
void deleteAcc(int acctnum, double &balance){
    int n;
    cout << "PLEASE ENTER ACCOUNT NUMBER :" << endl;
    cin >>n2;
    if (n2!=acctnum ){
        cout << "WRONG ACCOUNT  PLEASE TRY AGAIN" << endl;

    }
    else
}
void balance(int acctnum, double &balance){
    cout << "HERE ARE YOUR ACCOUNT BALANCE"<<endl;
    int n;
    cout << "PLEASE ENTER ACCOUNT NUMBER :" << endl;
    cin >>n;
    if (n!=acctnum ){
        cout << "WRONG ACCOUNT  PLEASE TRY AGAIN" << endl;

    }
    else

}*/
void printAcc(int acctnum, double balance){
    cout<<"ACCOUNT #" <<acctnum<<endl;
    cout<<"BALANCE: $"<<balance<<endl;
}
int main()
{
    int accountNum_try, accbalance_try;
    int accountNum=1234567; //int accountNum[];
    double  accbalance=500.00;  //int accbalance[];
    cin>>accountNum_try>>accbalance_try;
    if ( accountNum!= accountNum_try && accbalance !=accbalance_try ){
            cout<<"Error"<<endl;
            return 0;
    }
        else
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
              //  balance(accountNum, accbalance );
                break;
            case 'X':
            case 'x':
                //deleteAcct(accountNum, accbalance );
                break;
            case 'Q':
            case 'q':

                cout << "Thank You for using the bank. Please come again!" << endl;
                break;
            default:
                cout << "ERROR that is not a valid selection. Please try again" << endl;
        }
    }
                cout << "Thank You for using the bank. Please come again!" << endl;

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
