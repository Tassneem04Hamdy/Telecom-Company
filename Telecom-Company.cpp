#include <iostream>
#include <string>
using namespace std;
const int LINES_NUMBER = 3, CUSTOMERS_NUMBER = 5, CARDS_NUMBER = 4;

struct date
{
    int day, year;
    string month;
};

struct line
{
    string mobileNumber, packageType;
    float balance;
    date startDate, renewalDate;
};

struct user
{
    string name, e_mail, address, password;
    int ID, noOfLines;
    line userLines[LINES_NUMBER];

} customer[CUSTOMERS_NUMBER];

void signedInCustomer();
void logIn(int& j, int i);
void showMyInformation(int customerIndex);
void newRegistr(int customerIndex);
void changeAndRenew(int customerIndex);
void renew(int customerIndex);
void callOrMesg(int customerIndex);
void balanceRecharge(int validSerialNumber[], int customerIndex);
void transferBalance(int customerIndex);

int main()
{
    int i = 0, j = 0, accountType, opperationType, validSerialNumber[CARDS_NUMBER] = { 151, 348, 845, 981 };
    char anotherOperation = 'Y', anotherAccount = 'Y';

    signedInCustomer(); ///Make a customer profile

    cout << "\t\t\t\t***** Welcome to FCIS Telecom Application *****\n";
    while ((i < 5 && anotherAccount == 'Y') || (i < 5 && anotherAccount == 'y'))
    {
        cout << "If you have an account please enter 1. Otherwise, please enter 2.\n" << "Your answer : ";
        cin >> accountType;
        while (accountType != 1 && accountType != 2)
        {
            cout << "Invalid number!\n" << "If you have an account please enter 1. Otherwise, please enter 2.\n" << "Your answer : ";
            cin >> accountType;
        }
        if (accountType == 1)
        {
            logIn(j, i);
        }
        else if (accountType == 2)
        {
            i++;
            if (i == 5)
            {
                cout << "OH OH! Sorry you have exceeded number of users limit!\n"
                    << "\n\t\t***** Thanks for using our application. We wish you enjoyed with it :) *****\n";
                return 0;
            }
            newRegistr(i);
        }
        do
        {
            cout << "Please choose what you want to operate.\n" << "* 1\t->\tShow my information\n" << "* 2\t->\tChange and Renew the package\n"
                << "* 3\t->\tRenew the package\n" << "* 4\t->\tMake a call OR send a message\n" << "* 5\t->\tRecharge the balance\n"
                << "* 6\t->\tTransfer balance\n";
            cin >> opperationType;

            if (opperationType == 1)
            {
                if (accountType == 1)
                {
                    showMyInformation(j);
                }
                else if (accountType == 2)
                {
                    showMyInformation(i);
                }
            }
            else if (opperationType == 2)
            {
                if (accountType == 1)
                {
                    changeAndRenew(j);
                }
                else if (accountType == 2)
                {
                    changeAndRenew(i);
                }
            }
            else if (opperationType == 3)
            {
                if (accountType == 1)
                {
                    renew(j);
                }
                else if (accountType == 2)
                {
                    renew(i);
                }
            }
            else if (opperationType == 4)
            {
                if (accountType == 1)
                {
                    callOrMesg(j);
                }
                else if (accountType == 2)
                {
                    callOrMesg(i);
                }
            }
            else if (opperationType == 5)
            {
                if (accountType == 1)
                {
                    balanceRecharge(validSerialNumber, j);
                }
                else if (accountType == 2)
                {
                    balanceRecharge(validSerialNumber, i);
                }
            }
            else if (opperationType == 6)
            {
                if (accountType == 1)
                {
                    transferBalance(j);
                }
                else if (accountType == 2)
                {
                    transferBalance(i);
                }
            }
            cout << "Do you want any other operation?(Y/N) : ";
            cin >> anotherOperation;
        } while (anotherOperation == 'Y' || anotherOperation == 'y');
        cout << "Do you want to access another account?(Y/N) : ";
        cin >> anotherAccount;
    }
    cout << "\n\t\t***** Thanks for using our application. We wish you enjoyed with it :) *****\n";
    return 0;
}

void signedInCustomer()
{
    customer[0].name = "Sam Alex";
    customer[0].e_mail = "samalex@gmail.com";
    customer[0].address = "Washington City";
    customer[0].password = "sam210alex";
    customer[0].ID = 210;

    customer[0].userLines[0].mobileNumber = "01836975412";
    customer[0].userLines[0].packageType = "SuperConnect";
    customer[0].userLines[0].balance = 55.50;
    customer[0].userLines[0].startDate.day = 5;
    customer[0].userLines[0].startDate.month = "Apr";
    customer[0].userLines[0].startDate.year = 2011;
    customer[0].userLines[0].renewalDate.day = 5;
    customer[0].userLines[0].renewalDate.month = "May";

    customer[0].userLines[1].mobileNumber = "01829784236";
    customer[0].userLines[1].packageType = "FamilyPackage";
    customer[0].userLines[1].balance = 23.00;
    customer[0].userLines[1].startDate.day = 10;
    customer[0].userLines[1].startDate.month = "Sept";
    customer[0].userLines[1].startDate.year = 2013;
    customer[0].userLines[1].renewalDate.day = 10;
    customer[0].userLines[1].renewalDate.month = "Oct";

    customer[0].userLines[2].mobileNumber = "01821569852";
    customer[0].userLines[2].packageType = "HkayaMix";
    customer[0].userLines[2].balance = 44.75;
    customer[0].userLines[2].startDate.day = 15;
    customer[0].userLines[2].startDate.month = "Dec";
    customer[0].userLines[2].startDate.year = 2015;
    customer[0].userLines[2].renewalDate.day = 15;
    customer[0].userLines[2].renewalDate.month = "Jan";
}

///Log in to an already registered account
void logIn(int& j, int i)
{
    string e_mail, password;
    bool found = false;
    cout << "Please enter your E_mail : ";
    cin >> e_mail;
    while (!found)
    {
        for (j = 0; j <= i; j++)
        {
            if (customer[j].e_mail == e_mail)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Invalid E_mail!\n" << "Please try again : ";
            cin >> e_mail;
        }
    }
    cout << "Please enter your password : ";
    cin >> password;
    while (password != customer[j].password)
    {
        cout << "Invalid password!\n" << "Please try again : ";
        cin >> password;
    }
}

///Filling customer profile
void newRegistr(int customerIndex)
{
    cout << "Please enter your name : ";
    cin.ignore();
    getline(cin, customer[customerIndex].name);
    cout << "Please enter your address : ";
    cin.ignore();
    getline(cin, customer[customerIndex].address);
    cout << "Please enter your E_mail : ";
    cin >> customer[customerIndex].e_mail;
    cout << "Please enter your password : ";
    cin >> customer[customerIndex].password;
    customer[customerIndex].ID = customer[customerIndex - 1].ID + 5;
    cout << "Your ID is : " << customer[customerIndex].ID << endl;
    cout << "How many lines do you have? Please notice that you only can own maximum 3 lines.\n";
    cin >> customer[customerIndex].noOfLines;
    while (customer[customerIndex].noOfLines > 3)
    {
        cout << "Sorry, you can't own more than 3 lines!\n" << "Please try again : ";
        cin >> customer[customerIndex].noOfLines;
    }
    for (int j = 0; j < customer[customerIndex].noOfLines; j++)
    {
        cout << "For line " << j + 1 << ", please enter the mobile number : ";
        cin >> customer[customerIndex].userLines[j].mobileNumber;
        changeAndRenew(customerIndex);
        customer[customerIndex].userLines[j].startDate.day = (customer[0].userLines[j].startDate.day) + 2 + customerIndex;
        customer[customerIndex].userLines[j].startDate.month = customer[0].userLines[j].startDate.month;
        customer[customerIndex].userLines[j].startDate.year = (customer[0].userLines[j].startDate.year) + 1 + customerIndex;
        customer[customerIndex].userLines[j].renewalDate.day = customer[customerIndex].userLines[j].startDate.day;
        customer[customerIndex].userLines[j].renewalDate.month = customer[0].userLines[j].renewalDate.month;

        cout << "The start date of line " << j + 1 << " is : " << customer[customerIndex].userLines[j].startDate.day
            << ' ' << customer[customerIndex].userLines[j].startDate.month << ' ' << customer[customerIndex].userLines[j].startDate.year
            << "\nThe renewal date of line " << j + 1 << " is : " << customer[customerIndex].userLines[j].renewalDate.day
            << ' ' << customer[customerIndex].userLines[j].renewalDate.month << '\n';
    }
}

///Mobile Services Functions

void showMyInformation(int customerIndex)
{
    cout << "Here is your data.\n" << "Your username : " << customer[customerIndex].name << "\nYour e_mail : " << customer[customerIndex].e_mail
        << "\nYour address : " << customer[customerIndex].address << "\nYour ID : " << customer[customerIndex].ID << endl;
    for (int i = 0; i < customer[customerIndex].noOfLines; i++)
    {
        cout << "\nData of line " << i + 1 << ".\n" << "Mobile number : " << customer[customerIndex].userLines[i].mobileNumber << "\nPackage type : "
            << customer[customerIndex].userLines[i].packageType << "\nBalance : " << customer[customerIndex].userLines[i].balance
            << "\nLine start date : " << customer[customerIndex].userLines[i].startDate.day << ' '
            << customer[customerIndex].userLines[i].startDate.month << ' ' << customer[customerIndex].userLines[i].startDate.year << "\nRenewal date : "
            << customer[customerIndex].userLines[i].renewalDate.day << ' ' << customer[customerIndex].userLines[i].renewalDate.month << endl;
    }
}

void changeAndRenew(int customerIndex)
{
    int newType;
    string mobileNumber;
    cout << "Please choose the package type.\n" << "* 1\t->\t" << "SuperConnect\n"
        << "* 2\t->\t" << "FamilyPackage\n" << "* 3\t->\t" << "HkayaMix\n";
    cin >> newType;
    cout << "Please enter the mobile number you want to set this package for : ";
    cin >> mobileNumber;
    for (int i = 0; i < LINES_NUMBER; i++)
    {
        if (customer[customerIndex].userLines[i].mobileNumber == mobileNumber)
        {
            if (newType == 1)
            {
                customer[customerIndex].userLines[i].packageType = "SuperConnect";
                customer[customerIndex].userLines[i].balance += 150.00;
            }
            else if (newType == 2)
            {
                customer[customerIndex].userLines[i].packageType = "FamilyPackage";
                customer[customerIndex].userLines[i].balance += 100.00;
            }
            else if (newType == 3)
            {
                customer[customerIndex].userLines[i].packageType = "HkayaMix";
                customer[customerIndex].userLines[i].balance += 75.00;
            }
            cout << "Your balance now is : " << customer[customerIndex].userLines[i].balance << endl;
        }
    }
}

void renew(int customerIndex)
{
    string mobileNumber;
    cout << "Please enter the mobile number : ";
    cin >> mobileNumber;
    for (int i = 0; i < LINES_NUMBER; i++)
    {
        if (customer[customerIndex].userLines[i].mobileNumber == mobileNumber)
        {
            if (customer[customerIndex].userLines[i].packageType == "SuperConnect")
            {
                customer[customerIndex].userLines[i].balance += 150.00;
            }
            else if (customer[customerIndex].userLines[i].packageType == "FamilyPackage")
            {
                customer[customerIndex].userLines[i].balance += 100.00;
            }
            else if (customer[customerIndex].userLines[i].packageType == "HkayaMix")
            {
                customer[customerIndex].userLines[i].balance += 75.00;
            }
            cout << "Your balance now is : " << customer[customerIndex].userLines[i].balance << endl;
        }
    }
}

void callOrMesg(int customerIndex)
{
    string mobileNumber;
    cout << "Which mobile number would you like to make a call from ? ";
    cin >> mobileNumber;
    for (int i = 0; i < LINES_NUMBER; i++)
    {
        if (customer[customerIndex].userLines[i].mobileNumber == mobileNumber)
        {
            if (customer[customerIndex].userLines[i].balance < 0.25) ///Checking if the user has enough balance to make a call or send a message or not
            {
                cout << "Sorry, your balance isn't enough to make a call or send a message!";
            }
            else
            {
                customer[customerIndex].userLines[i].balance -= 0.25;
                cout << "Your balance now is : " << customer[customerIndex].userLines[i].balance << endl;
            }
        }
    }
}

void balanceRecharge(int validSerialNumber[], int customerIndex)
{
    int cardSerialNumber, simCard;
    cout << "Which line do you want to charge (1, 2, or 3)? : ";
    cin >> simCard;
    cout << "Choose the suitable Serial No.\n" << "* 10 LE\t->\t" << "151\n"
        << "* 25 LE\t->\t" << "348\n" << "* 50 LE\t->\t" << "845\n" << "* 75 LE\t->\t" << "981\n";
    cin >> cardSerialNumber;
    bool valid = false;
    while (!valid) ///Checking if the user has entered a correct serial number or not
    {
        for (int i = 0; i < CARDS_NUMBER; i++)
        {
            if (cardSerialNumber == validSerialNumber[i])
            {
                valid = true;
                break;
            }
        }
        if (!valid)
        {
            cout << "Invalid card serial number!\n";
            cout << "Choose the suitable Serial No.\n" << "* 10 LE\t->\t" << "151\n"
                << "* 25 LE\t->\t" << "348\n" << "* 50 LE\t->\t" << "845\n" << "* 75 LE\t->\t" << "981\n";
            cin >> cardSerialNumber;
        }
    }
    switch (cardSerialNumber)
    {
    case 151:
        customer[customerIndex].userLines[--simCard].balance += 10.00;
        break;
    case 348:
        customer[customerIndex].userLines[--simCard].balance += 25.00;
        break;
    case 845:
        customer[customerIndex].userLines[--simCard].balance += 50.00;
        break;
    case 981:
        customer[customerIndex].userLines[--simCard].balance += 75.00;
        break;
    }
    cout << "Your balance now is : " << customer[customerIndex].userLines[simCard].balance << endl;
}

void transferBalance(int customerIndex)
{
    string mobileNumber, transferedMobileNumber;
    float transferedAmount;
    cout << "Please enter your mobile number : ";
    cin >> mobileNumber;
    cout << "Please enter the mobile number to which you want to transfer : ";
    cin >> transferedMobileNumber;

    while (mobileNumber[0] != transferedMobileNumber[0] || mobileNumber[1] != transferedMobileNumber[1]
        || mobileNumber[2] != transferedMobileNumber[2]) ///Checking if the mobile number is on the same network
    {
        cout << "This mobile number isn't on the same network! Please enter a valid number : ";
        cin >> transferedMobileNumber;
    }
    cout << "Please enter the amount to be transfered : ";
    cin >> transferedAmount;
    for (int i = 0; i < LINES_NUMBER; i++)
    {
        if (customer[customerIndex].userLines[i].mobileNumber == mobileNumber)
        {
            while (transferedAmount > customer[customerIndex].userLines[i].balance) ///Checking if the balance is enough for the transferring process
            {
                cout << "Sorry this amount is larger than your balance! Please enter amount less than "
                    << customer[customerIndex].userLines[i].balance << " : ";
                cin >> transferedAmount;
            }
            customer[customerIndex].userLines[i].balance -= transferedAmount;
            cout << "Your balance now is : " << customer[customerIndex].userLines[i].balance << endl;
        }
    }
}
