#include <iostream>
#include "Person.h"
#include <fstream>
using namespace std;
class Employee : public Person
{
private:
    string post;
    int employee_id;

public: // Member Functions
    // Mutator Function
    void set_post(string p)
    {
        post = p;
    }
    void set_employee_id(int e_id)
    {
        employee_id = e_id;
    }
    // Accessor Function
    string get_post()
    {
        return post;
    }
    int get_e_id()
    {
        return employee_id;
    }
    Employee() // Default Constructor
    {
    }
    // Parameterized Constructor
    Employee(string n, string g, double c, double c_no, string e, string p, int e_id)
        : Person(n, g, c, c_no, e)
    {
        post = p;
        employee_id = e_id;
    }
    Employee(const Employee &obj) : Person(obj) // Copy Constructor
    {
        post = obj.post;
        employee_id = obj.employee_id;
    }
    // To add details of the record
    void add()
    {
        ofstream outfile;
        Person::add("Employee.txt");
        string p;
        int e_id;
        outfile.open("Employee.txt", ios::app);
        cout << "Post : ";
        cin >> p;
        cout << "Employee Id : ";
        cin >> e_id;
        while (Existing(e_id))
        {
            cout << "ID already exists, choose another ID!" << endl;
            cout << "Employee Id : ";
            cin >> e_id;
        }
        outfile << " " << p << " " << e_id;
        outfile.close();
        cout << "Account create Successfully!" << endl;
    }
    // To View the details of the Account
    static void view(int temp)
    {
        ifstream infile;
        infile.open("Employee.txt");
        if (infile)
        {
            string n, g, e, p;
            double c, c_no;
            int e_id;
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> p >> e_id;
                if (temp == e_id)
                {
                    cout << endl;
                    cout << "___________________________________________________________________________________________________________________________________________________________ " << endl;
                        cout
                         << setw(20) << "Name"
                         << setw(20) << "Gender"
                         << setw(20) << "CNIC No."
                         << setw(20) << "Contact No."
                         << setw(30) << "Email"
                         << setw(20) << "Post"
                         << setw(20) << "Employee Id"
                         << endl;
                    cout << "___________________________________________________________________________________________________________________________________________________________ " << endl;
                    cout << setw(20) << n << setw(20) << g << setw(20) << c << setw(20) << c_no << setw(30) << e << setw(20) << p << setw(20) << e_id << endl;
                    cout << "___________________________________________________________________________________________________________________________________________________________ " << endl;
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
        infile.open("Employee.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, g, e, p;
        double c, c_no;
        int e_id;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> p >> e_id;
                if (temp == e_id)
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
                        cout << "6. Post" << endl;
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
                            cout << "Enter post : ";
                            cin >> p;
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
                            cout << "Post : ";
                            cin >> p;
                        }
                        else
                        {
                            cout << "Invalid Choice" << endl;
                        }
                    }
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e << " " << p << " " << e_id;
                }
                else
                {
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e << " " << p << " " << e_id;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Employee.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Employee.txt");
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
        infile.open("Employee.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, g, e, p;
        double c, c_no;
        int e_id;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> p >> e_id;
                if (e_id == temp)
                {
                    cout << "Account deleted successfully!" << endl;
                }
                else
                {
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e << " " << p << " " << e_id;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Employee.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Employee.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    static bool Existing(int temp)
    {
        ifstream infile;
        infile.open("Employee.txt");
        string n, g, e, p;
        double c, c_no;
        int e_id;
        bool result = false;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e >> p >> e_id;
                if (e_id == temp)
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
