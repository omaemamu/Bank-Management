#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define str string
bool loggedin = false;
void login()
{
    str accounts;
    int response, depo,withd;
    ifstream myfile("Account.txt");
    while (getline(myfile, accounts)) {
        cout << accounts << endl;
    }
    myfile.close();
    cin >> response;
    if (response == 1)
    {
        cout << "You have logged into Karim account!" << endl;
        loggedin = true;
    }
    cout << "Welcome to the bank management app!" << endl;
    cout << "\nPlease enter your selection: " << endl;
    cout << "1-Deposit\n";
    cout << "2-Withdraw\n";
    cout << "3-Check account balance\n";
    cin >> response;

    if (response == 1)
    {
        cout << "How much do you want to deposit?: $";
        cin >> depo;
        if (depo <= 0)
            cout << "Amount of money must be higher than 0: ";
        else
        {
            cout << "You have added to your account balance: " << depo << "$" << endl;
            ofstream depofile("MoneyBalance.txt", ios::app);
            depofile << "Karim: " << depo << "$" << "\n";
            depofile.close();
        }
    }
    if (response == 2)
    {
        cout << "How much money do you want to withdraw?: $";
        cin.ignore();
        cin >> withd;
        if (withd < depo)
        {
            cout << "You don't have enough money!";
        }
    }
 }
int main()
{
    str name;
    int response;
    cout << "Welcome to the bank management app!" << endl;
    cout << "\nPlease enter your selection: " << endl;
    cout << "1-Create an account\n";
    cout << "2-Login\n";
    cin >> response;

    if (response == 1)
    {
        cout << "Enter the name of the account: ";
        cin >> name;
        if (name.empty())
            cout << "\nPlease enter a valid name: ";
        else {
            cout << "The account was created successfully!";
            ofstream myfile("Account.txt", ios::app);
            myfile << (name + "\n");
            myfile.close();
        }

    }
    if (response == 2)
    {
        login();
    }
}