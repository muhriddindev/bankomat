#include <iostream>
using namespace std;

int main() {
    string pass="1010",input,history;
    double balance=100000, transaction;
    int step=0,option;
    bool checked=false;
    while (step<3 && pass!=input){
        cout<<"Parol kiriting\n";
        cin >> input;
        step++;
        if(pass==input) {
            checked = true;
            step=0;
        }
    }




    if(checked){
        cout << "Welcome \n";

        while (true) {
            cout<< "\n1 show balance  2 deposite\n"
                   "3 withdraw  4 change password\n"
                   "5 exit\n";

            cin >> option;

            switch (option) {
                case 1:
                    cout << "Your current balance is " << balance << " sum\n";
                    history+="Balance checked\n";
                    break;
                case 2:
                    cout << "Enter amount of deposite\n";
                    cin >> transaction;
                    balance += transaction;
                    cout << "Your current balance is " << balance << " sum\n";
                    history+="You have deposited\n";
                    break;
                case 3:
                    cout << "Enter amount of withdrawal sum\n";
                    cin >> transaction;
                    if (transaction * 1.01 <= balance) {
                        balance -= transaction * 1.01;
                        cout << "Your current balance is " << balance << " sum\n";
                        history+="You have succeessfully withdrawed money\n";
                    }else{
                        cout<<"You have not enough money\n";
                        history+="You couldn't withdrawed money\n";
                    }
                    break;
                case 4:
                    cout << "Enter old password\n";
                    cin >>input;
                    if(input!=pass){
                        cout<<"Password incorrect\n";

                        break;
                    }
                    cout<<"Entere new password\n";
                    cin >> pass;
                    history+="You have changed your password"+pass+"\n";
                    checked= false;
                    while (step<3 && pass!=input){
                        cout<<"Parol kiriting\n";
                        cin >> input;
                        step++;
                        if(pass==input){
                            checked= true;
                            step=0;
                        }
                    }
                    if (!checked){
                        cout<<"Blocked\n";
                        history+="Someone tryed to hack your card\n";
                        cout<<history;
                        return 0;
                    }
                    break;
                case 5:
                    cout << "Bye bye\n";
                    cout << history;
                    return 0;
            }
        }
    }else{
        cout<<"Dastur blocklandi\n";
    }

}