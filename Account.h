#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "template.h"
using namespace std;
class Account // Base Class
{
private: // Data Members
    string name;
    double cnic;
    double mobile_no;
    int acc_num;
    double balance = 0;
    int pin_code;

public: // Member Functions
    // Mutator
    void set_name(string n)
    {
        name = n;
    }
    void set_cnic(double c)
    {
        cnic = c;
    }
    void set_mobile_no(double m)
    {
        mobile_no = m;
    }
    void set_acc_num(int ac)
    {
        acc_num = ac;
    }
    void set_balance(double b)
    {
        balance = b;
    }
    void set_pin_code(int p)
    {
        pin_code = p;
    }
    // Accessors
    string get_name()
    {
        return name;
    }
    double get_cnic()
    {
        return cnic;
    }
    double get_mobile_no()
    {
        return mobile_no;
    }
    int get_acc_num()
    {
        return acc_num;
    }
    double get_balance()
    {
        return balance;
    }
    int get_pin_code()
    {
        return pin_code;
    }
    // Constructors
    Account() {}                                           // default constructor
    Account(string n, double c, double m, double b, int p) // parameterized constructor
    {
        name = n;
        cnic = c;
        mobile_no = m;
        balance = b;
        pin_code = p;
    }
    Account(const Account &obj) // copy constructor
    {
        name = obj.name;
        cnic = obj.cnic;
        mobile_no = obj.mobile_no;
        balance = obj.balance;
        pin_code = obj.pin_code;
    }
    // To Create a new Account
    void add()
    {
        ofstream outfile;
        outfile.open("Account.txt", ios::app);
        string n;
        double c, m, b;
        int ac, p;
        cout << "Enter your details" << endl;
        cout << "Name : ";
        cin >> n;
        cout << "CNIC No. : ";
        cin >> c;
        cout << "Mobile number : ";
        cin >> m;
        cout << "Account No. : ";
        cin >> ac;
        while (Existing(ac))
        {
            cout << "Account No. already exists!" << endl;
            cout << "Account No. : ";
            cin >> ac;
        }
        cout << "Balance : ";
        cin >> b;
        cout << "Pin Code (4 digits) : ";
        cin >> p;
        outfile << endl
                << n << " " << c << " " << m << " " << ac << " " << b << " " << p;
        cout << "Account created Successfully!" << endl;
        outfile.close();
    }
    // To deposit money
    static void deposit(int temp)
    {
        ifstream infile;
        infile.open("Account.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        ofstream file;
        file.open("BankStatement.txt", ios::app);
        string n;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
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
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                    file << endl
                         << temp << " " << 1 << " " << amount << " " << 0 << " " << b;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                }
            }
            file.close();
            infile.close();
            outfile.close();
            // Delete the original file
            remove("Account.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Account.txt");
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
        infile.open("Account.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        ofstream file;
        file.open("BankStatement.txt", ios::app);
        string n;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
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
                                    << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                            check = 1;
                            file << endl
                                 << temp << " " << 2 << " " << amount << " " << 0 << " " << b;
                            cout << "Amount Withdraw Successful!" << endl;
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
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                }
            }
            file.close();
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Account.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Account.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    // To Transfer Money
    static void transfer(int temp1, int temp2)
    {
        ifstream infile;
        infile.open("Account.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n;
        ofstream sfile;
        sfile.open("BankStatement.txt", ios::app);
        double c, m, b;
        int a, p;
        double transfer_amount = 0;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
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
                                    << n << " " << c << " " << m << " " << a << " " << b << " " << p;
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
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                }
            }
            sfile.close();
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Account.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Account.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
        ofstream file;
        file.open("BankStatement.txt", ios::app);
        ifstream ifile;
        ifile.open("Account.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        while (!ifile.eof())
        {
            ifile >> n >> c >> m >> a >> b >> p;
            if (a == temp2)
            {
                b += transfer_amount;
                ofile << endl
                      << n << " " << c << " " << m << " " << a << " " << b << " " << p;
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
                      << n << " " << c << " " << m << " " << a << " " << b << " " << p;
            }
        }
        file.close();
        ifile.close();
        ofile.close();
        // Delete the original file
        remove("Account.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Account.txt");
    }
    // To get the bank statement of an account
    static void bank_statement(int temp)
    {
        ifstream infile;
        infile.open("BankStatement.txt");
        int acc_num1, acc_num2, action;
        double amount, remaining;
        if (infile)
        {
            cout << "__________________________________________________________________________________________________________ " << endl;
            cout << "\t\t\t\t\t\tBank Statement" << endl;
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
                        cout << "Remaining Balance : " << remaining << " Rs. \n\n";
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
    }
    // To get the password of the user
    static int password(int temp)
    {
        ifstream infile;
        infile.open("Account.txt");
        string n;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
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
    }
    // To View the details of the Account
    static void view(int temp)
    {
        ifstream infile;
        infile.open("Account.txt");
        if (infile)
        {
            string n;
            double c, m, b;
            int a, p;
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
                if (temp == a)
                {
                    cout << endl;
                    cout << "______________________________________________________________________________________________________________ " << endl;
                    cout
                        << setw(20) << "Name"
                        << setw(20) << "CNIC No."
                        << setw(20) << "Mobile NO."
                        << setw(20) << "Account No."
                        << setw(20) << "Balance"
                        << endl;
                    cout << "______________________________________________________________________________________________________________ " << endl;
                    cout
                        << setw(20) << n << setw(20) << c << setw(20) << m << setw(20)
                        << a << setw(20) << b << endl;
                    cout << "______________________________________________________________________________________________________________ " << endl;
                }
            }
            infile.close();
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    // To update the details of the account
    static void update(int temp)
    {
        ifstream infile;
        infile.open("Account.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
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
                        cout << "5. Full record" << endl;
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
                            cout << "Enter new details : " << endl;
                            cout << "Name : ";
                            cin >> n;
                            cout << "CNIC No. : ";
                            cin >> c;
                            cout << "Mobile NO. : ";
                            cin >> m;
                            cout << "Pin Code : ";
                            cin >> p;
                        }
                        else
                        {
                            cout << "Invalid Choice" << endl;
                        }
                    }
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Account.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Account.txt");
        }
        else
        {
            cout << "File not Found!" << endl;
        }
    }
    // To delete the account
    static void delete_(int temp)
    {
        ifstream infile;
        infile.open("Account.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n;
        double c, m, b;
        int a, p;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
                if (a == temp)
                {
                    cout << "Account deleted successfully!" << endl;
                }
                else
                {
                    outfile << endl
                            << n << " " << c << " " << m << " " << a << " " << b << " " << p;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Account.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Account.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    static bool Existing(int temp)
    {
        ifstream infile;
        infile.open("Account.txt");
        string n;
        double c, m, b;
        int a, p;
        bool result = false;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> c >> m >> a >> b >> p;
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
    }
};
