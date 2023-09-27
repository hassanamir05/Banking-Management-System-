#include <iostream>
#include "Account.h"
#include <fstream>
using namespace std;
class Saving : public Account // Derived Class (Inheritance)
{
private:
    string purpose;

public:
    // Accessor
    void set_minimum(string pur)
    {
        purpose = pur;
    }
    // Mutator
    string get_minimum()
    {
        return purpose;
    }
    // Constructors
    Saving() {} // default constructor
    Saving(string n, double c, double m, int a, double b, int p, string pur) : Account(n,
                                                                                       m, a, b, p)
    // parameterized constructor
    {
        purpose = pur;
    }
    Saving(const Saving &obj) : Account(obj)
    {
        purpose = obj.purpose;
    }
    void add()
    {
        ofstream outfile;
        outfile.open("Saving.txt", ios::app);
        string n, pu;
        double c, m, b;
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
        cout << "Purpose (business/education) : ";
        cin >> pu;
        outfile << endl
                << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pu;
        outfile.close();
        cout << "Account create Successfully!" << endl;
        cout << "\n\n\n";
    }
    // To deposit money
    static void deposit(int temp)
    {
        ifstream infile;
        infile.open("Saving.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        ofstream file;
        file.open("BankStatementSaving.txt", ios::app);
        string n, pur;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
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
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                    file << endl
                         << temp << " " << 1 << " " << amount << " " << 0 << " " << b;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                }
            }
            file.close();
            infile.close();
            outfile.close();
            // Delete the original file
            remove("Saving.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Saving.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
        cout << "\n\n\n";
    }
    // To Withdraw money
    static void withdraw(int temp)
    {
        ifstream infile;
        infile.open("Saving.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        ofstream file;
        file.open("BankStatementSaving.txt", ios::app);
        string n, pur;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
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
                            b -= amount;
                            outfile << endl
                                    << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                            if (amount != 0)
                            {
                                file << endl
                                     << temp << " " << 2 << " " << amount << " " << 0 << " " << b;
                                cout << "Money Withdraw Successfull!" << endl;
                                check = 1;
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
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                }
            }
            file.close();
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Saving.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Saving.txt");
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
        infile.open("Saving.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, pur;
        ofstream sfile;
        sfile.open("BankStatementSaving.txt", ios::app);
        double c, m, b;
        int a, p;
        double transfer_amount = 0;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
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
                                    << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                            if (amount != 0)
                            {
                                sfile << endl
                                      << temp1 << " " << 3 << " " << transfer_amount << " " << temp2 << " " << b;
                                cout << "Money Transfer Successfull!" << endl;
                            }
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
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                }
            }
            sfile.close();
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Saving.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Saving.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
        ofstream file;
        file.open("BankStatementSaving.txt", ios::app);
        ifstream ifile;
        ifile.open("Saving.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        while (!ifile.eof())
        {
            ifile >> n >> c >> m >> a >> b >> p >> pur;
            if (a == temp2)
            {
                b += transfer_amount;
                ofile << endl
                      << n << " " << c << " " << m << " " << a << " " << b << " " << p << " "
                      << pur;
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
                      << pur;
            }
        }
        file.close();
        ifile.close();
        ofile.close();
        // Delete the original file
        remove("Saving.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Saving.txt");
        cout << "\n\n\n";
    }
    // To get the bank statement of an account
    static void bank_statement(int temp)
    {
        ifstream infile;
        infile.open("BankStatementSaving.txt");
        int acc_num1, acc_num2, action;
        double amount, remaining;
        if (infile)
        {
            cout << "__________________________________________________________________________________________________________ " << endl;
            cout<< "\t\t\t\t\t\tBank Statement" << endl;
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
        infile.open("Saving.txt");
        string n, pur;
        double c, m, b;
        int a, p = -1;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
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
            cout << "Account not found!" << endl;
        }
        cout << "\n\n\n";
    }
    // To view the details of the Account
    static void view(int temp)
    {
        ifstream infile;
        infile.open("Saving.txt");
        if (infile)
        {
            string n, pur;
            double c, m, b;
            int a, p;
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
                if (temp == a)
                {
                    cout << endl;
                    cout << "_________________________________________________________________________________________________________________________ " << endl;
                    cout << setw(20) << "Name" << setw(20) << "CNIC No." << setw(20) << "Mobile NO." << setw(20) << "Account No." << setw(20) << "Balance" << setw(20) << "Purpose" << endl;
                    cout << "_________________________________________________________________________________________________________________________ " << endl;
                    cout << setw(20) << n << setw(20) << c << setw(20) << m << setw(20) << a << setw(20) << b << setw(20) << pur << endl;
                    cout << "_________________________________________________________________________________________________________________________ " << endl;
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
        infile.open("Saving.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, pur;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
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
                        cout << "5. Purpose" << endl;
                        cout << "6. Full Record" << endl;
                        cout << "Enter choice : ";
                        cin >> choice;
                        if (choice == 1)
                        {
                            cout << "Enter name : ";
                            cin >> n;
                            check = 1;
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter CNIC No. :";
                            cin >> c;
                            check = 1;
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter Mobile NO. : ";
                            cin >> m;
                            check = 1;
                        }
                        else if (choice == 4)
                        {
                            cout << "Enter Pin Code : ";
                            cin >> p;
                            check = 1;
                        }
                        else if (choice == 5)
                        {
                            cout << "Purpose : ";
                            cin >> pur;
                            check = 1;
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter new details : " << endl;
                            cout << "Name : ";
                            cin >> n;
                            cout << "CNIC No. : ";
                            cin >> c;
                            cout << "Mobile NO. : ";
                            cin >> m;
                            cout << "Pin Code : ";
                            cin >> p;
                            cout << "Purpose : ";
                            cin >> pur;
                            check = 1;
                        }
                        else
                        {
                            cout << "Invalid Choice" << endl;
                        }
                    }
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Saving.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Saving.txt");
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
        infile.open("Saving.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, pur;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
                if (a == temp)
                {
                    cout << "Amount Withdraw Successful!" << endl;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p << " " << pur;
                }
            }
        }
        else
        {
            cout << "File not found!" << endl;
        }
        outfile.close();
        infile.close();
        // Delete the original file
        remove("Saving.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Saving.txt");
        // Delete Bank Statement of that Account
        ifstream ifile;
        ifile.open("BankStatementSaving.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        int acc_num1, acc_num2, action;
        double amount, remaining;
        if (ifile)
        {
            while (!ifile.eof())
            {
                ifile >> acc_num1 >> action >> amount >> acc_num2 >> remaining;
                if (temp == acc_num1)
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
        remove("BankStatementSaving.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "BankStatementSaving.txt");
        cout << "\n\n\n";
    }
    static bool Existing(int temp)
    {
        ifstream infile;
        infile.open("Saving.txt");
        string n, pur;
        double c, m, b;
        int a, p;
        bool result = false;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
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
    void balance_inquiry(int temp)
    {
        ifstream infile;
        infile.open("Saving.txt");
        string n, pur;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p >> pur;
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
        cout << "\n\n\n";
    }
};