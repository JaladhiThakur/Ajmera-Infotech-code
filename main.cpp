#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MIN 5000

class Account {
    private:
        string accType;
        string name;
        long balance;
        vector<vector<string>> transaction;
        
    public:
        void openAccount(){
            cout << "Enter name:" << endl;
            cin >> name;
            cout << "Enter account type:" << endl;
            cout << "Please enter 'C' for checking ans 'S' for savings type account";
            cin >> accType;
            balance = 1000;
        }
        
        void showTransaction(){
            for(int i=0;i<transaction.size();i++){
                cout << transaction[i][0] << " " << transaction[i][1] << " " << transaction[i][2] << endl; 
            }
            cout << "Final Balance =" << balance << endl;
        }
        
        void credit(long amount, string date){
            if(amount<500){
                cout << "The amount must be atleast 500" << endl;
            } else {
                if(amount%500 == 0){
                    balance+=amount;
                    vector<string> temp;
                    temp.push_back(date);
                    temp.push_back("credit");
                    temp.push_back(to_string(amount));
                    transaction.push_back(temp);
                } else {
                    cout << "Please enter the amount in the multiples of 500 (e.g. 500,1000,1500 etc)" << endl;
                }
            }
        }
        
        void debit(long amount, string date){
            if(amount<500){
                cout << "The amount must be atleast 500" << endl;
            } else {
                if(amount%500 == 0){
                    balance-=amount;
                    vector<string> temp;
                    temp.push_back(date);
                    temp.push_back("debit");
                    temp.push_back(to_string(amount));
                    transaction.push_back(temp);
                } else {
                    cout << "Please enter the amount in the multiples of 500 (e.g. 500,1000,1500 etc)" << endl;
                }
            }
        }
};

int main() {

	Account acc;
	acc.openAccount();
	acc.credit(1000, "08-09-2020");
	acc.credit(200, "08-09-2020");
	acc.credit(800, "08-09-2020");

	acc.debit(500,"08-09-2020");
	acc.debit(200,"08-09-2020");
	acc.debit(800,"08-09-2020");
	acc.showTransaction();
	return 0;
}