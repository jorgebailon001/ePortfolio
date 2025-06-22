#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int increment = 0;

class Account 
{
public:
    int numberAccount = 1000000;
    string firstName;
    string lastName;
    string age;
    string typeAccount;
    int firstDeposit;

    Account()
    {
        numberAccount = numberAccount + increment;
    }
};

vector<Account> vectorAccount;

struct Bank 
{ 
    void showMenu() {
        cout << "            MENU              " << endl;
        cout << "  ------------------------" << endl;
        cout << "  | Open New Account (1) |" << endl;
        cout << "  | Deposit Money    (2) |" << endl;
        cout << "  | WithDraw Money   (3) |" << endl;
        cout << "  | Display Account  (4) |" << endl;
        cout << "  | Exit             (5) |" << endl;
        cout << "  ------------------------";
    }

    void openAccount()
    {

        cout << "  ------------------------" << endl;
        cout << "  |   Creating Account   |" << endl;
        cout << "  ------------------------" << endl << endl;

        int accountInt;

        Account account;

        cout << "  * Enter Your First Name : " << endl;
        cin >> account.firstName;
        cin.clear();

        cout << "  * Enter Your Last Name : " << endl;
        cin >> account.lastName;
        cin.clear();

        cout << "  * Enter Your Age : " << endl;
        cin >> account.age;
        cin.clear();

        int accountType; 
        do {
            cout << "  * Enter Account type (1) Checking Account, (2) Saving Account : " << endl;
            cin >> accountType;
            cin.clear();
        } while (accountType != 1 && accountType != 2);

        if (accountType == 1)
        {
            account.typeAccount = "Checking Account";
        }

        else
        {
            account.typeAccount = "Saving Account";
        }
        
        cout << "  * Enter Amount Of First Deposit : " << endl;
        cin >> account.firstDeposit;
        cin.clear();

        cout << endl << "  Account Created!" << endl << endl;
     
        increment++;

        vectorAccount.push_back(account);
    }

    void depositMoney() 
    {
        if (vectorAccount.size() == 0)
        {
            cout << "No Account Created." << endl << endl;
                return;
        }

        cout << "  ------------------------" << endl;
        cout << "  |    Deposit Portal    |" << endl;
        cout << "  ------------------------" << endl << endl;

        int numberAccount;
        int depo;

        cout << "Account Number To Deposit : ";
        cin >> numberAccount;
        cin.clear();

        cout << "Amount To Deposit : ";
        cin >> depo;
        cin.clear();

        for (int i = 0; i < vectorAccount.size(); i++)
        {
            if (vectorAccount[i].numberAccount == numberAccount)
            {
                vectorAccount[i].firstDeposit = vectorAccount[i].firstDeposit + depo;
            }
        }

        cout << "Succesfully Deposit!";
        cout << endl << endl;
    }

    void displayAccount()
    {
        if (vectorAccount.size() == 0)
        {
            cout << "No Account Created." << endl << endl;
                return;
        }

        cout << "  ------------------------" << endl;
        cout << "  |   Display Account    |" << endl;
        cout << "  ------------------------" << endl << endl;

        for (int i = 0; i < vectorAccount.size(); i++)
        {
            cout << "Account : " << i + 1 << endl;
            cout << "Account Number : " << vectorAccount[i].numberAccount << endl;
            cout << "First Name : " << vectorAccount[i].firstName << endl;
            cout << "Last Name : " << vectorAccount[i].lastName << endl;
            cout << "Age : " << vectorAccount[i].age << endl;
            cout << "Type Account : " << vectorAccount[i].typeAccount << endl;
            cout << "Account Balance : " << vectorAccount[i].firstDeposit << endl << endl;
        }
    }

    void WithdrawMoney()
    {
        if (vectorAccount.size() == 0)
        {
            cout << "No Account Created." << endl << endl;
                return;
        }

        int numberAccount;
        int amount;
        
        cout << "Account Number To Withdraw : ";
        cin >> numberAccount;
        cin.clear();

        cout << "Amount To Deposit : ";
        cin >> amount;
        cin.clear();

        for (int i = 0; i < vectorAccount.size(); i++)
        {
            if (vectorAccount[i].numberAccount == numberAccount)
            {
                vectorAccount[i].firstDeposit = vectorAccount[i].firstDeposit - amount;
            }
            cout << endl << endl;
        }

        cout << "Withdrawal Resquest Succesful!";
        cout << endl << endl;
    }
};

int main()
{

    int optionChoice = 0;
    Bank theBank;

    theBank.showMenu();
    cout << endl << endl << "  Please Choose An Option : " << endl << endl << endl;
    
    do
    {
        cin >> optionChoice;

        switch (optionChoice)
        {
        case 1:
            theBank.openAccount();
            break;
        case 2:
            theBank.depositMoney();
            break;
        case 4:
            theBank.displayAccount();
            break;
        case 3:
            theBank.WithdrawMoney();
            break;
        }
        theBank.showMenu();
        cout << endl << endl << "  Please Choose An Option : " << endl << endl << endl;
    } while (optionChoice != 5);
}
