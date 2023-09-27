#include <iostream>
#include "Employee.h"
#include <fstream>
using namespace std;
class Customer : public Person
{
private:
    int customer_id;

public: // Member Functions
    // Mutator Function
    void set_Customer_id(int c_id)
    {
        customer_id = c_id;
    }
    // Accessor Function
    int get_customer_id()
    {
        return customer_id;
    }
    Customer()
    {
    }
    Customer(string n, string g, double c, double c_no, string e, string p, int c_id) : Person(n, g, c, c_no, e)
    {
        customer_id = c_id;
    }
    // To add details of the record
    void add()
    {
        ofstream outfile;
        Person::add("Customer.txt");
        int c_id;
        outfile.open("Customer.txt", ios::app);
        cout << "Enter Customer id : ";
        cin >> c_id;
        while (Existing(c_id))
        {
            cout << "Customer Id already Exists!" << endl;
            cout << "Enter Customer id : ";
            cin >> c_id;
        }
        outfile << " " << c_id;
        outfile.close();
        cout << "Account create Successfully!" << endl;
    }
    // To View the details of the Account
    static void view(int temp)
    {
        ifstream infile;
        infile.open("Customer.txt");
        if (infile)
        {
            string n, g, e;
            double c, c_no;
            int c_id;
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> c_id;
                if (temp == c)
                {
                    cout << endl;
                    cout << "_____________________________________________________________________________________________________________________________ " << endl;
                    cout << setw(20) << "Name"<< setw(20) << "Gender"<< setw(20) << "CNIC No." << setw(20) << "Contact No." << setw(20) << "Email" << setw(20) << "Customer ID" << endl;
                    cout << "_____________________________________________________________________________________________________________________________ " << endl;
                    cout << setw(20) << n << setw(20) << g << setw(20) << c << setw(20) << c_no << setw(20) << e << setw(20) << c_id << endl;
                    cout << "_____________________________________________________________________________________________________________________________ " << endl;
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
        infile.open("Customer.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, g, e;
        double c, c_no;
        int c_id;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> c_id;
                if (temp == c)
                {
                    int check = 0;
                    int choice;
                    while (check == 0)
                    {
                        cout << "What do you want to update : " << endl;
                        cout << "1. Name " << endl;
                        cout << "2. Gender " << endl;
                        cout << "3. CNIC No. " << endl;
                        cout << "4. Contact Number " << endl;
                        cout << "5. Email" << endl;
                        cout << "6. Customer ID" << endl;
                        cout << "7. Full Record " << endl;
                        cin >> choice;
                        if (choice == 1)
                        {
                            cout << "Enter name : ";
                            cin >> n;
                            check = 1;
                        }
                        else if (choice == 2)
                        {
                            cout << "Enter gender :";
                            cin >> g;
                            check = 1;
                        }
                        else if (choice == 3)
                        {
                            cout << "Enter CNIC No. : ";
                            cin >> c;
                            check = 1;
                        }
                        else if (choice == 4)
                        {
                            cout << "Enter Contact No. : ";
                            cin >> c_no;
                            check = 1;
                        }
                        else if (choice == 5)
                        {
                            cout << "Enter email : ";
                            cin >> e;
                            check = 1;
                        }
                        else if (choice == 6)
                        {
                            cout << "Enter Customer ID : ";
                            cin >> c_id;
                            check = 1;
                        }
                        else if (choice == 7)
                        {
                            cout << "Enter new details : " << endl;
                            cout << "Name : ";
                            cin >> n;
                            cout << "Gender : ";
                            cin >> g;
                            cout << "CNIC No. : ";
                            cin >> c;
                            cout << "Contact No. : ";
                            cin >> c_no;
                            cout << "Email : ";
                            cin >> e;
                            cout << "Customer ID : ";
                            cin >> c_id;
                        }
                        else
                        {
                            cout << "Invalid Choice" << endl;
                        }
                    }
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e << " " << c_id;
                }
                else
                {
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e << " " << c_id;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Customer.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Customer.txt");
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
        infile.open("Customer.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, g, e;
        double c, c_no;
        int c_id;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> c_id;
                if (c == temp)
                {
                }
                else
                {
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e << " " << c_id;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Customer.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Customer.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    static bool Existing(int temp)
    {
        ifstream infile;
        infile.open("Customer.txt");
        string n, g, e;
        double c, c_no;
        int c_id;
        bool result = false;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> c_id;
                if (c_id == temp)
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