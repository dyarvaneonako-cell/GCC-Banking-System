#include <iostream>

#include <string>

using namespace std;

void displayMenu()
{
    cout<<"================================================================================="<<endl;
    cout<<"GCC BANK"<<endl;
    cout<<"1.Deposit"<<endl;
    cout<<"2.Withdraw"<<endl;
    cout<<"3.Send Cash"<<endl;
    cout<<"4.Check balance"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter your choice"<<endl;
}

  double calculateDeposit(double balance, int amount)
{
    return balance + amount;
}
   double calculateWithdraw(double balance, int amount)
{
    return balance - amount;
}

   double calculateSendCash(double balance, int amount)
{
    return balance - amount;
}

   double calculateRecipientBalance(double balance, int amount)
{
    return balance + amount;
}

  double checkBalance(double balance)
{
    return balance;
}

int main()
{
    double balance1 = 8000, balance2 = 6500, balance3 = 9500;

    string name1="Customer1";
    string name2="Customer2";
    string name3="Customer3";

    string accountNumber1="10010001";
    string accountNumber2="10010002";
    string accountNumber3="10010003";

    int options;
    int customerChoice;
    int PinInput;
    int amount;

    int Pin1 = 1975, Pin2 = 2005, Pin3 = 2007;

    do
    {
        displayMenu();
        cin >> options;

    switch (options)
    {

      case 1: { // Deposit

        cout<<"You have selected Deposit"<<endl;
        cout<<"Select customer"<<endl;
        cout<<"1."<<name1<<endl;
        cout<<"2."<<name2<<endl;
        cout<<"3."<<name3<<endl;
        cin>>customerChoice;

                double balance = 0;
                int correctPin = 0;

                if (customerChoice == 1)
                {
                    balance = balance1;
                    correctPin = Pin1;
                }
                else if (customerChoice == 2)
                {
                    balance = balance2;
                    correctPin = Pin2;
                }
                else if (customerChoice == 3)
                {
                    balance = balance3;
                    correctPin = Pin3;
                }
                else
                {
                    cout<<"Invalid customer"<<endl;
                    break;
                }

                cout<<"Enter Pin"<<endl;
                cin>>PinInput;

                if (PinInput != correctPin)
                {
                    cout<<"Incorrect Pin"<<endl;
                    break;
                }

                cout<<"Enter the amount you want to deposit"<<endl;
                cin>>amount;

                if (amount <= 0)
                {
                    cout<<"Invalid amount"<<endl;
                    break;
                }

                balance = calculateDeposit(balance, amount);

                if (customerChoice == 1)
                    balance1 = balance;
                else if (customerChoice == 2)
                    balance2 = balance;
                else if (customerChoice == 3)
                    balance3 = balance;

                cout<<"You have deposited: R"<<amount<<endl;
                cout<<"Your new balance is R"<<balance<<endl;
                break;
            }

            case 2: { // Withdraw

                cout<<"You have selected Withdraw"<<endl;
                cout<<"Select Customer"<<endl;
                cout<<"1."<<name1<<endl;
                cout<<"2."<<name2<<endl;
                cout<<"3."<<name3<<endl;
                cin>>customerChoice;

                double balance = 0;
                int correctPin = 0;

                if (customerChoice == 1)
                {
                    balance = balance1;
                    correctPin = Pin1;
                }
                else if (customerChoice == 2)
                {
                    balance = balance2;
                    correctPin = Pin2;
                }
                else if (customerChoice == 3)
                {
                    balance = balance3;
                    correctPin = Pin3;
                }
                else
                {
                    cout<<"Invalid Customer"<<endl;
                    break;
                }

                cout<<"Enter Pin"<<endl;
                cin>>PinInput;

                if (PinInput != correctPin)
                {
                    cout<<"Incorrect Pin"<<endl;
                    break;
                }

                cout<<"Enter the amount you want to withdraw: R"<<endl;
                cin>>amount;

                if (amount <= 0)
                {
                    cout<<"Invalid amount"<<endl;
                    break;
                }

                if (amount > balance)
                {
                    cout<<"Insufficient balance"<<endl;
                    break;
                }

                balance = calculateWithdraw(balance, amount);

                if (customerChoice == 1)
                    balance1 = balance;
                else if (customerChoice == 2)
                    balance2 = balance;
                else if (customerChoice == 3)
                    balance3 = balance;

                cout<<"You have withdrawn R"<<amount<<endl;
                cout<<"Your new balance is: R"<<balance<<endl;
                break;
            }

            case 3: { // Send Cash

                cout<<"You have selected Send Cash"<<endl;
                cout<<"Select customer"<<endl;
                cout<<"1."<<name1<<endl;
                cout<<"2."<<name2<<endl;
                cout<<"3."<<name3<<endl;
                cin>>customerChoice;

                cout<<name1<<"-"<<accountNumber1<<endl;
                cout<<name2<<"-"<<accountNumber2<<endl;
                cout<<name3<<"-"<<accountNumber3<<endl;

                double balance = 0;
                int correctPin = 0;

                if (customerChoice == 1)
                {
                    balance = balance1;
                    correctPin = Pin1;
                }
                else if (customerChoice == 2)
                {
                    balance = balance2;
                    correctPin = Pin2;
                }
                else if (customerChoice == 3)
                {
                    balance = balance3;
                    correctPin = Pin3;
                }
                else
                {
                    cout<<"Invalid Customer"<<endl;
                    break;
                }

                cout<<"Enter Pin"<<endl;
                cin>>PinInput;

                if (PinInput != correctPin)
                {
                    cout<<"Incorrect Pin"<<endl;
                    break;
                }

                cout<<"Enter the amount you want to send: R"<<endl;
                cin>>amount;

                if (amount <= 0)
                {
                    cout<<"Invalid amount"<<endl;
                    break;
                }

                if (amount > balance)
                {
                    cout<<"Insufficient balance"<<endl;
                    break;
                }

                cout<<"Select recipient"<<endl;
                cout<<"1."<<name1<<endl;
                cout<<"2."<<name2<<endl;
                cout<<"3."<<name3<<endl;

                int recipientChoice;
                cin>>recipientChoice;

                if (recipientChoice < 1 || recipientChoice > 3)
                {
                    cout<<"Invalid recipient"<<endl;
                    break;
                }

                if (recipientChoice == customerChoice)
                {
                    cout<<"You cannot send money into your own account"<<endl;
                    break;
                }

                // Deduct money from sender
                balance = calculateSendCash(balance, amount);

                if (customerChoice == 1)
                    balance1 = balance;
                else if (customerChoice == 2)
                    balance2 = balance;
                else if (customerChoice == 3)
                    balance3 = balance;

                // Add money to recipient
                if (recipientChoice == 1)
                    balance1 = calculateRecipientBalance(balance1, amount);
                else if (recipientChoice == 2)
                    balance2 = calculateRecipientBalance(balance2, amount);
                else if (recipientChoice == 3)
                    balance3 = calculateRecipientBalance(balance3, amount);

                cout<<"You have successfully sent: R"<<amount<<endl;
                cout<<"Your remaining balance is: R"<<balance<<endl;
                break;
            }

            case 4: { // Check Balance

                cout<<"You have selected Check Balance"<<endl;
                cout<<"Select Customer"<<endl;
                cout<<"1."<<name1<<endl;
                cout<<"2."<<name2<<endl;
                cout<<"3."<<name3<<endl;
                cin>>customerChoice;

                double balance = 0;
                int correctPin = 0;

                if (customerChoice == 1)
                {
                    balance = balance1;
                    correctPin = Pin1;
                }
                else if (customerChoice == 2)
                {
                    balance = balance2;
                    correctPin = Pin2;
                }
                else if (customerChoice == 3)
                {
                    balance = balance3;
                    correctPin = Pin3;
                }
                else
                {
                    cout<<"Invalid Customer"<<endl;
                    break;
                }

                cout<<"Enter Pin"<<endl;
                cin>>PinInput;

                if (PinInput != correctPin)
                {
                    cout<<"Incorrect Pin"<<endl;
                    break;
                }

                cout<<"Your balance is R"<<checkBalance(balance)<<endl;
                break;
            }

            case 5:
                cout<<"You have selected Exit"<<endl;
                cout<<"You have Exited"<<endl;
                cout<<"Thank you for banking with GCC"<<endl;
                break;

            default:
                cout<<"Invalid Option"<<endl;
                break;
        }

    } while (options != 5);

    return 0;
}








