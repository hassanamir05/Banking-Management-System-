#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class Person
{
private:
    string name;
    string gender;
    double cnic;
    double contact_no;
    string email;

public: // Member Functions
    // Mutator Functions
    void set_name(string n)
    {
        name = n;
    }
    void set_gender(string g)
    {
        gender = g;
    }
    void set_cnic(double c)
    {
        cnic = c;
    }
    void set_contact_no(double c_no)
    {
        contact_no = c_no;
    }
    void set_email(string e)
    {
        email = e;
    }
    // Accessor Functions
    string get_name()
    {
        return name;
    }
    string get_gender()
    {
        return gender;
    }
    double get_cnic()
    {
        return cnic;
    }
    double get_contact_no()
    {
        return contact_no;
    }
    string get_email()
    {
        return email;
    }
    Person() // Default Constructor
    {
    }
    Person(string n, string g, double c, double c_no, string e) // Parameterized Constructor
    {
        name = n;
        gender = g;
        cnic = c;
        contact_no = c_no;
        email = e;
    }
    Person(const Person &obj) // Copy Contructor
    {
        name = obj.name;
        gender = obj.gender;
        cnic = obj.cnic;
        contact_no = obj.contact_no;
        email = obj.email;
    }
    // To Create a new Account
    void add()
    {
        ofstream outfile;
        outfile.open("Person.txt", ios::app);
        string n, g, e;
        double c, c_no;
        cout << "Enter your details" << endl;
        cout << "Name : ";
        cin >> n;
        cout << "Gender : ";
        cin >> g;
        cout << "CNIC No. : ";
        cin >> c;
        cout << "Contact number : ";
        cin >> c_no;
        cout << "Email : ";
        cin >> e;
        outfile << endl
                << n << " " << g << " " << c << " " << c_no << " " << e;
        cout << "Account created Successfully!" << endl;
        outfile.close();
    }
    void add(string file)
    {
        ofstream outfile;
        outfile.open(file, ios::app);
        {
            string n, g, e;
            double c, c_no;
            cout << "Enter your details" << endl;
            cout << "Name : ";
            cin >> n;
            cout << "Gender : ";
            cin >> g;
            cout << "CNIC No. : ";
            cin >> c;
            cout << "Contact number : ";
            cin >> c_no;
            cout << "Email : ";
            cin >> e;
            outfile << endl
                    << n << " " << g << " " << c << " " << c_no << " " << e;
        }
        outfile.close();
    }

    // To View the details of the Account
    static void view(int temp)
    {
        ifstream infile;
        infile.open("Person.txt");
        if (infile)
        {
            string n, g, e;
            double c, c_no;
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e;
                if (temp == c)
                {
                    cout << endl;
                    cout << "______________________________________________________________________________________________________________ " << endl;
                    cout << setw(20) << "Name" << setw(20) << "Gender" << setw(20) << "CNIC No." << setw(20) << "Contact No." << setw(20) << "Email" << endl;
                    cout << "______________________________________________________________________________________________________________ " << endl;
                    cout << setw(20) << n << setw(20) << g << setw(20) << c << setw(20) << c_no << setw(20) << e << endl;
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
        infile.open("Person.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, g, e;
        double c, c_no;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e;
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
                        cout << "6. Full Record " << endl;
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
                        }
                        else
                        {
                            cout << "Invalid Choice" << endl;
                        }
                    }
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e;
                }
                else
                {
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Person.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Person.txt");
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
        infile.open("Person.txt");
        ofstream outfile;
        outfile.open("temp.txt");
        string n, g, e;
        double c, c_no;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e;
                if (c == temp)
                {
                }
                else
                {
                    outfile << endl
                            << n << " " << g << " " << c << " " << c_no << " " << e;
                }
            }
            outfile.close();
            infile.close();
            // Delete the original file
            remove("Person.txt");
            // Rename the temporary file to the original filename
            rename("temp.txt", "Person.txt");
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    static bool Existing(int temp)
    {
        ifstream infile;
        infile.open("Person.txt");
        string n, g, e;
        double c, c_no;
        bool result = false;
        if (infile)
        {
            while (!infile.eof())
            {
                infile >> n >> g >> c >> c_no >> e;
                if (c == temp)
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