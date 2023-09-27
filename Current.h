#include <iostream>
#include "Saving.h"
#include <fstream>
using namespace std;
class Current : public Account // Derived Class (Inheritance)
{
private:
    double limit;

public:
    // Accessor
    void set_limit(double lim)
    {
        limit = lim;
    }
    // Mutator
    double get_limit()
    {
        return limit;
    }
    // Constructors
    Current() {} // default constructor
    Current(string n, double c, double m, int a, double b, int p, double lim) : Account(n,
                                                                                        m, a, b, p)
    // parameterized constructor
    {
        limit = lim;
    }
    Current(const Current &obj) : Account(obj)
    {
        limit = obj.limit;
    }
    void add()
    {
        ofstream outfile;
        outfile.open("Current.txt", ios::app);
        string n;
        double c, m, b, lim;
        int a, p;
        cout << "Enter your details!" << endl;
        cout << "Name : ";
        cin >> n;
        cout << "CNIC No. : ";
        cin >> c;
        cout << "Mobile No. : ";
        cin >> m;
        cout << "Account Number : ";
        cin >> a;
        while (Existing(a))
        {
            cout << "Account number already exists, choose another one!" << endl;
            cout << "Account No. : ";
            cin >> a;
        }
        cout << "Balance : ";
        cin >> b;
        cout << "Pin code (4 digits) : ";
        cin >> p;
        cout << "Withdraw limit : ";
        cin >> lim;
        outfile << endl
                << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
        outfile.close();
        cout << "Account create Successfully!" << endl;
        cout << "\n\n\n";
    }
    // To deposit money
    static void deposit(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        ofstream file;
        file.open("BankStatementCurrent.txt", ios::app);
        string n;
        double c, m, b, lim;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (a == temp)
                {
                    double amount;
                    cout << "Enter amount you want to deposit : ";
                    amount = get_input<double>();
                    while (amount < 0)
                    {
                        cout << "Ammount can not be negative, enter a positive value! " << endl;
                        amount = get_input<double>();
                    }
                    b += amount;
                    cout << "Amount deposited successfully!" << endl;
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                    file << endl
                         << temp << " " << 1 << " " << amount << " " << 0 << " " << b;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                }
            }
            file.close();
            infile.close();
            outfile.close();
            // Delete the original file
            remove("Current.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Current.txt");
            cout << "\n\n\n";
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    // To Withdraw money
    static void withdraw(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        ofstream file;
        file.open("BankStatementCurrent.txt", ios::app);
        string n;
        double c, m, b, lim;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (a == temp)
                {
                    double amount;
                    int check = 0;
                    while (check == 0)
                    {
                        cout << "Enter amount you want to withdraw : ";
                        amount = get_input<double>();
                        while (amount < 0)
                        {
                            cout << "Ammount can not be negative, enter a positive value! " << endl;
                            amount = get_input<double>();
                        }
                        if (b > amount)
                        {
                            if (amount < lim)
                            {
                                b -= amount;
                                check = 1;
                                file << endl
                                     << temp << " " << 2 << " " << amount << " " << 0 << " " << b;
                                outfile << endl
                                        << n << " " << c << " " << m << " " << a << " " << b << " "
                                        << p << " " << lim;
                                cout << "Amount Withdraw Successful!" << endl;
                            }
                            else
                            {
                                cout << "You are exceeding your withdraw limit!" << endl;
                            }
                        }
                        else
                        {
                            cout << "Insufficient Balance!" << endl;
                        }
                    }
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                }
            }
            file.close();
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Current.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Current.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
        cout << "\n\n\n";
    }
    // To Transfer Money
    static void transfer(int temp1, int temp2)
    {
        ifstream infile;
        infile.open("Current.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n;
        ofstream sfile;
        sfile.open("BankStatementCurrent.txt", ios::app);
        double c, m, b, lim;
        int a, p;
        double transfer_amount = 0;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (a == temp1)
                {
                    double amount;
                    int check = 0;
                    while (check == 0)
                    {
                        cout << "Enter amount you want to transfer : ";
                        amount = get_input<double>();
                        while (amount < 0)
                        {
                            cout << "Ammount can not be negative, enter a positive value! " << endl;
                            amount = get_input<double>();
                        }
                        if (b >= amount)
                        {
                            transfer_amount = amount;
                            b -= amount;
                            outfile << endl
                                    << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                            sfile << endl
                                  << temp1 << " " << 3 << " " << transfer_amount << " " << temp2 << " " << b;
                            check = 1;
                        }
                        else
                        {
                            cout << "Insufficient Balance!" << endl;
                        }
                    }
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                }
            }
            sfile.close();
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Current.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Current.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
        ofstream file;
        file.open("BankStatementCurrent.txt", ios::app);
        ifstream ifile;
        ifile.open("Current.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        while (!ifile.eof())
        {
            ifile >> n >> c >> m >> a >> b >> p >> lim;
            if (a == temp2)
            {
                b += transfer_amount;
                ofile << endl
                      << n << " " << c << " " << m << " " << a << " " << b << " " << p << " "
                      << lim;
                if (transfer_amount != 0)
                {
                    file << endl
                         << temp2 << " " << 4 << " " << transfer_amount << " " << temp1 << " " << b;
                    cout << "Amount transferred successfully!" << endl;
                }
            }
            else
            {
                ofile << endl
                      << n << " " << c << " " << m << " " << a << " " << b << " " << p << " "
                      << lim;
            }
        }
        file.close();
        ifile.close();
        ofile.close();
        // Delete the original file
        remove("Current.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Current.txt");
        cout << "\n\n\n";
    }
    // To get the bank statement of an account
    static void bank_statement(int temp)
    {
        ifstream infile;
        infile.open("BankStatementCurrent.txt");
        int acc_num1, acc_num2, action;
        double amount, remaining;
        if (infile)
        {
            cout << "__________________________________________________________________________________________________________ " << endl;
                cout
                 << "\t\t\t\t\t\tBank Statement" << endl;
            cout << "__________________________________________________________________________________________________________ " << endl;
                while (!infile.eof())
            {
                infile >> acc_num1 >> action >> amount >> acc_num2 >> remaining;
                if (temp == acc_num1)
                {
                    if (action == 1)
                    {
                        cout << "Deposited " << amount << " Rs. in the account." << endl;
                        cout << "\tRemaining Balance : " << remaining << " Rs. \n\n";
                    }
                    else if (action == 2)
                    {
                        cout << "Withdraw " << amount << " Rs. from the account." << endl;
                        cout << "\tRemaining Balance : " << remaining << " Rs. \n\n";
                    }
                    else if (action == 3)
                    {
                        cout << "Transfered " << amount << " Rs. to " << acc_num2 << " ."
                             << endl;
                        cout << "\tRemaining Balance : " << remaining << " Rs. \n\n";
                    }
                    else if (action == 4)
                    {
                        cout << "Received " << amount << " Rs. from " << acc_num2 << " ."
                             << endl;
                        cout << "\tRemaining Balance : " << remaining << " Rs. \n\n";
                    }
                }
            }
            cout << "__________________________________________________________________________________________________________ " << endl;
            infile.close();
        }
        else
        {
            cout << "File not found!" << endl;
        }
        cout << "\n\n\n";
    }
    // To get the password of the user
    static int password(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        string n;
        double c, m, b, lim;
        int a, p = -1;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (temp == a)
                {
                    return p;
                    break;
                }
            }
            infile.close();
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    // To view the details of the Account
    static void view(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        if (infile)
        {
            string n;
            double c, m, b;
            int a, p;
            double lim;
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (temp == a)
                {
                    cout << endl;
                    cout << "_____________________________________________________________________________________________________________________________ " << endl;
                        cout
                         << setw(20) << "Name" << setw(20) << "CNIC No." << setw(20)
                         << "Mobile NO." << setw(20) << "Account No." << setw(20) << "Balance" << setw(20) << "Withdraw Limit" << endl;
                    cout << "_____________________________________________________________________________________________________________________________ " << endl;
                        cout
                         << setw(20) << n << setw(20) << c << setw(20) << m << setw(20)
                         << a << setw(20) << b << setw(20) << lim << endl;
                    cout << "_____________________________________________________________________________________________________________________________ " << endl;
                }
            }
            infile.close();
        }
        else
        {
            cout << "File not found!" << endl;
        }
        cout << "\n\n\n";
    }
    static void update(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n;
        double c, m, b, lim;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (temp == a)
                {
                    int check = 0;
                    int choice;
                    while (check == 0)
                    {
                        cout << "What do you want to update : " << endl;
                        cout << "1. Name " << endl;
                        cout << "2. CNIC No. " << endl;
                        cout << "3. Mobile Number " << endl;
                        cout << "4. Pin Code " << endl;
                        cout << "5. Withdraw Limit" << endl;
                        cout << "6. Full Record" << endl;
                        cout << "\n--> ";
                        cin >> choice;
                        if (choice == 1)
                        {
                            cout << "Name : ";
                            cin >> n;
                            check = 1;
                        }
                        else if (choice == 2)
                        {
                            cout << "CNIC No. :";
                            cin >> c;
                            check = 1;
                        }
                        else if (choice == 3)
                        {
                            cout << "Mobile No. : ";
                            cin >> m;
                            check = 1;
                        }
                        else if (choice == 4)
                        {
                            cout << "Pin Code : ";
                            cin >> p;
                            check = 1;
                        }
                        else if (choice == 5)
                        {
                            cout << "Withdraw Limit : ";
                            cin >> lim;
                            check = 1;
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter new details : " << endl;
                            cout << "Name : ";
                            cin >> n;
                            cout << "CNIC No. : ";
                            cin >> c;
                            cout << "Mobile No. : ";
                            cin >> m;
                            cout << "Pin Code : ";
                            cin >> p;
                            cout << "Withdraw Limit: ";
                            cin >> lim;
                            check = 1;
                        }
                        else
                        {
                            cout << "Invalid Choice" << endl;
                        }
                    }
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Current.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Current.txt");
        }
        else
        {
            cout << "File not Found!" << endl;
        }
        cout << "\n\n\n";
    }
    // To delete the account
    static void delete_(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n;
        double c, m, b, lim;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (a == temp)
                {
                    cout << "Amount Withdraw Successful!" << endl;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << lim;
                }
            }
        }
        else
        {
            cout << "File not Found!" << endl;
        }
        outfile.close();
        infile.close();
        // Delete the original file
        remove("Current.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Current.txt");
        // Delete Bank Statement of that Account
        ifstream ifile;
        ifile.open("BankStatementCurrent.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        int acc_num1, acc_num2, action;
        double amount, remaining;
        if (ifile)
        {
            while (!ifile.eof())
            {
                ifile >> acc_num1 >> action >> amount >> acc_num2 >> remaining;
                if (acc_num1 == temp)
                {
                }
                else
                {
                    ofile << endl
                          << acc_num1 << " " << action << " " << amount << " " << acc_num2
                          << " " << remaining;
                }
            }
        }
        else
        {
            cout << "File not found!" << endl;
        }
        ofile.close();
        ifile.close();
        // Delete the original file
        remove("BankStatementCurrent.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "BankStatementCurrent.txt");
        cout << "\n\n\n";
    }
    static bool Existing(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        string n;
        double c, m, b, lim;
        int a, p;
        bool result = false;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (a == temp)
                {
                    result = true;
                }
            }
            infile.close();
            return result;
        }
        else
        {
            cout << "File not found!" << endl;
        }
        cout << "\n\n\n";
    }
    double check_limit(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        string n;
        double c, m, b, lim;
        int a, p;
        if (infile)
        {
            while (infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (a == temp)
                {
                    return lim;
                }
            }
        }
        else
        {
            cout << "File not Found!" << endl;
        }
        infile.close();
        cout << "\n\n\n";
    }
    void balance_inquiry(int temp)
    {
        ifstream infile;
        infile.open("Current.txt");
        string n;
        double c, m, b, lim;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> lim;
                if (a == temp)
                {
                    cout << "Balance : " << b << endl;
                }
            }
        }
        else
        {
            cout << "File not Found!" << endl;
        }
        infile.close();
        cout << "\n\n\n";
    }
};
