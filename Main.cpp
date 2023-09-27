#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Current.h"
#include "Customer.h"
using namespace std;
int main()
{
    // Objects for each class
    Saving s;
    Current c;
    Employee e;
    Customer cu;
    int choice,  // used in main menu choice
        choice1, // used in Accounts menu choice
        choice2, // used in Current Account menu choice and Saving Account menu
        choice3;
    double temp_acc_num, temp_acc_num1; // will be used throughout the program when ever the user is asked to enter his/her account number
    int temp_acc_pin;                   // will be used throughout the program when ever the user is asked to enter his/her pin code
    int temp_choice;                    // used in Invalid choice option
    int check = 0;                      // To exit to if statements
    int pass;                           // To compare pin code
    int i = 0, j = 0;                   // To control Loop
    while (choice != 0)
    {
        cout << "\n\n";
        cout << "__________________________________________________" << endl;
        cout << "\t\tMain Menu" << endl;
        cout << "__________________________________________________" << endl;
        cout << "1. Employee" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Accounts" << endl;
        cout << "0. Exit" << endl;
        cout << "\n-->";
        cin >> choice;
        if (choice == 1)
        {
            do
            {
                cout << "\n\n";
                cout << "__________________________________________________" << endl;
                cout << "\t\tEmployee" << endl;
                cout << "__________________________________________________" << endl;
                cout << "1. Hire Employee" << endl;
                cout << "2. View Details" << endl;
                cout << "3. Update Details" << endl;
                cout << "4. Delete Record" << endl;
                cout << "0. Back" << endl;
                cout << "\n-->";
                cin >> choice1;
                if (choice1 == 1)
                {
                    e.add();
                }
                else if (choice1 == 2)
                {
                    cout << "Employee ID : ";
                    cin >> temp_acc_num;
                    if (e.Existing(temp_acc_num))
                    {
                        e.view(temp_acc_num);
                    }
                    else
                    {
                        cout << "Employee doesn't Exists" << endl;
                    }
                }
                else if (choice1 == 3)
                {
                    cout << "Employee ID : ";
                    cin >> temp_acc_num;
                    if (e.Existing(temp_acc_num))
                    {
                        e.update(temp_acc_num);
                        continue;
                    }
                    else
                    {
                        cout << "Employee doesn't Exists" << endl;
                    }
                }
                else if (choice1 == 4)
                {
                    cout << "Employee ID : ";
                    cin >> temp_acc_num;
                    if (e.Existing(temp_acc_num))
                    {
                        e.delete_(temp_acc_num);
                    }
                    else
                    {
                        cout << "Employee doesn't Exists" << endl;
                    }
                }
                else if (choice1 != 0)
                {
                    cout << "Invalid Choice!" << endl;
                }
            } while (choice1 != 0);
        }
        else if (choice == 2)
        {
            do
            {
                cout << "\n\n";
                cout << "__________________________________________________" << endl;
                cout << "\t\tCustomer" << endl;
                cout << "__________________________________________________" << endl;
                cout << "1. New Customer" << endl;
                cout << "2. View Details" << endl;
                cout << "3. Update Details" << endl;
                cout << "4. Delete Record" << endl;
                cout << "0. Back" << endl;
                cout << "\n-->";
                cin >> choice1;
                if (choice1 == 1)
                {
                    cu.add();
                }
                else if (choice1 == 2)
                {
                    cout << "Customer ID : ";
                    cin >> temp_acc_num;
                    if (cu.Existing(temp_acc_num))
                    {
                        cu.view(temp_acc_num);
                    }
                    else
                    {
                        cout << "Customer doesn't Exists" << endl;
                    }
                }
                else if (choice1 == 3)
                {
                    cout << "Customer ID : ";
                    cin >> temp_acc_num;
                    if (cu.Existing(temp_acc_num))
                    {
                        cu.update(temp_acc_num);
                        continue;
                    }
                    else
                    {
                        cout << "Customer doesn't Exists" << endl;
                    }
                }
                else if (choice1 == 4)
                {
                    cout << "Customer ID : ";
                    cin >> temp_acc_num;
                    if (cu.Existing(temp_acc_num))
                    {
                        cu.delete_(temp_acc_num);
                    }
                    else
                    {
                        cout << "Customer doesn't Exists" << endl;
                    }
                }
                else if (choice1 != 0)
                {
                    cout << "Invalid Choice!" << endl;
                }
            } while (choice1 != 0);
        }
        else if (choice == 3)
        {
            do
            {
                cout << "\n\n";
                cout << "Select Account Type!" << endl;
                cout << "1. Current " << endl;
                cout << "2. Saving" << endl;
                cout << "0. Back" << endl;
                cout << "\n-->";
                cin >> choice1;
                if (choice1 == 1)
                {
                    do
                    {
                        cout << "\n\n";
                        cout << "__________________________________________________" << endl;
                        cout << "\t\tCurrent Account" << endl;
                        cout << "__________________________________________________" << endl;
                        cout << "1. Transaction " << endl;
                        cout << "2. Create Account " << endl;
                        cout << "3. View Account Details" << endl;
                        cout << "4. Update Account Details" << endl;
                        cout << "5. Delete Account" << endl;
                        cout << "0. Back" << endl;
                        cout << "\n-->";
                        cin >> choice2;
                        if (choice2 == 1)
                        {
                            do
                            {
                                cout << "\n\n";
                                cout << "__________________________________________________" << endl;
                                cout << "\t\tDashboard" << endl;
                                cout << "__________________________________________________" << endl;
                                cout << "1. Deposit" << endl;
                                cout << "2. Withdraw" << endl;
                                cout << "3. Transfer" << endl;
                                cout << "4. Bank Statement" << endl;
                                cout << "5. Balance Inquiry" << endl;
                                cout << "0. Back" << endl;
                                cout << "\n-->";
                                cin >> choice3;
                                if (choice3 == 1)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (c.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = c.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                c.deposit(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 2)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (c.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = c.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                c.withdraw(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 3)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (c.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = c.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                cout << "Receiver's account number : ";
                                                cin >> temp_acc_num1;
                                                if (c.Existing(temp_acc_num1))
                                                {
                                                    c.transfer(temp_acc_num, temp_acc_num1);
                                                }
                                                else
                                                {
                                                    cout << "Account doesn't Exists!" << endl;
                                                }
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 4)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (c.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = c.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                c.bank_statement(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 5)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (c.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = c.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                c.balance_inquiry(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 != 0)
                                {
                                    cout << "Enter valid choice!" << endl;
                                }
                            } while (choice3 != 0);
                        }
                        else if (choice2 == 2)
                        {
                            c.add();
                        }
                        else if (choice2 == 3)
                        {
                            cout << "Account Number : ";
                            cin >> temp_acc_num;
                            if (c.Existing(temp_acc_num))
                            {
                                i = 0;
                                while (i < 3)
                                {
                                    cout << "Pin Code : ";
                                    cin >> temp_acc_pin;
                                    i++;
                                    pass = c.password(temp_acc_num);
                                    if (pass == temp_acc_pin)
                                    {
                                        i = 3;
                                        c.view(temp_acc_num);
                                    }
                                    else
                                    {
                                        cout << "Wrong Pin Code" << endl;
                                        cout << 3 - i << " trials left!" << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Account doesn't Exists!" << endl;
                            }
                        }
                        else if (choice2 == 4)
                        {
                            cout << "Account Number : ";
                            cin >> temp_acc_num;
                            if (c.Existing(temp_acc_num))
                            {
                                i = 0;
                                while (i < 3)
                                {
                                    cout << "Pin Code : ";
                                    cin >> temp_acc_pin;
                                    i++;
                                    pass = c.password(temp_acc_num);
                                    if (pass == temp_acc_pin)
                                    {
                                        i = 3;
                                        c.update(temp_acc_num);
                                    }
                                    else
                                    {
                                        cout << "Wrong Pin Code" << endl;
                                        cout << 3 - i << " trials left!" << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Account doesn't Exists!" << endl;
                            }
                        }
                        else if (choice2 == 5)
                        {
                            cout << "Account Number : ";
                            cin >> temp_acc_num;
                            if (c.Existing(temp_acc_num))
                            {
                                i = 0;
                                while (i < 3)
                                {
                                    cout << "Pin Code : ";
                                    cin >> temp_acc_pin;
                                    i++;
                                    pass = c.password(temp_acc_num);
                                    if (pass == temp_acc_pin)
                                    {
                                        i = 3;
                                        c.delete_(temp_acc_num);
                                    }
                                    else
                                    {
                                        cout << "Wrong Pin Code" << endl;
                                        cout << 3 - i << " trials left!" << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Account doesn't Exists!" << endl;
                            }
                        }
                        else if (choice2 != 0)
                        {
                            cout << "Enter Valid choice!" << endl;
                        }
                    } while (choice2 != 0);
                }
                else if (choice1 == 2)
                {
                    do
                    {
                        cout << "\n\n";
                        cout << "__________________________________________________" << endl;
                        cout << "\t\tSaving Account" << endl;
                        cout << "__________________________________________________" << endl;
                        cout << "1. Transaction " << endl;
                        cout << "2. Create Account " << endl;
                        cout << "3. View Account Details" << endl;
                        cout << "4. Update Account Details" << endl;
                        cout << "5. Delete Account" << endl;
                        cout << "0. Back" << endl;
                        cout << "\n-->";
                        cin >> choice2;
                        if (choice2 == 1)
                        {
                            do
                            {
                                cout << "\n\n";
                                cout << "__________________________________________________" << endl;
                                cout << "\t\tDashboard" << endl;
                                cout << "__________________________________________________" << endl;
                                cout << "1. Deposit" << endl;
                                cout << "2. Withdraw" << endl;
                                cout << "3. Transfer" << endl;
                                cout << "4. Bank Statement" << endl;
                                cout << "5. Balance Inquiry" << endl;
                                cout << "0. Back" << endl;
                                cout << "\n-->";
                                cin >> choice3;
                                if (choice3 == 1)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (s.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = s.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                s.deposit(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 2)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (s.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = s.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                s.withdraw(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 3)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (s.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = s.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                cout << "Receiver's account number : ";
                                                cin >> temp_acc_num1;
                                                if (s.Existing(temp_acc_num1))
                                                {
                                                    s.transfer(temp_acc_num, temp_acc_num1);
                                                }
                                                else
                                                {
                                                    cout << "Account doesn't Exists!" << endl;
                                                }
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 4)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (s.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = s.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                s.bank_statement(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 == 5)
                                {
                                    cout << "Account Number : ";
                                    cin >> temp_acc_num;
                                    if (s.Existing(temp_acc_num))
                                    {
                                        i = 0;
                                        while (i < 3)
                                        {
                                            cout << "Pin Code : ";
                                            cin >> temp_acc_pin;
                                            i++;
                                            pass = s.password(temp_acc_num);
                                            if (pass == temp_acc_pin)
                                            {
                                                i = 3;
                                                s.balance_inquiry(temp_acc_num);
                                            }
                                            else
                                            {
                                                cout << "Wrong Pin Code" << endl;
                                                cout << 3 - i << " trials left!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Account doesn't Exists!" << endl;
                                    }
                                }
                                else if (choice3 != 0)
                                {
                                    cout << "Enter valid choice!" << endl;
                                }
                            } while (choice3 != 0);
                        }
                        else if (choice2 == 2)
                        {
                            s.add();
                        }
                        else if (choice2 == 3)
                        {
                            cout << "Account Number : ";
                            cin >> temp_acc_num;
                            if (s.Existing(temp_acc_num))
                            {
                                i = 0;
                                while (i < 3)
                                {
                                    cout << "Pin Code : ";
                                    cin >> temp_acc_pin;
                                    i++;
                                    pass = s.password(temp_acc_num);
                                    if (pass == temp_acc_pin)
                                    {
                                        i = 3;
                                        s.view(temp_acc_num);
                                    }
                                    else
                                    {
                                        cout << "Wrong Pin Code" << endl;
                                        cout << 3 - i << " trials left!" << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Account doesn't Exists!" << endl;
                            }
                        }
                        else if (choice2 == 4)
                        {
                            cout << "Account Number : ";
                            cin >> temp_acc_num;
                            if (s.Existing(temp_acc_num))
                            {
                                i = 0;
                                while (i < 3)
                                {
                                    cout << "Pin Code : ";
                                    cin >> temp_acc_pin;
                                    i++;
                                    pass = s.password(temp_acc_num);
                                    if (pass == temp_acc_pin)
                                    {
                                        i = 3;
                                        s.update(temp_acc_num);
                                    }
                                    else
                                    {
                                        cout << "Wrong Pin Code" << endl;
                                        cout << 3 - i << " trials left!" << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Account doesn't Exists!" << endl;
                            }
                        }
                        else if (choice2 == 5)
                        {
                            cout << "Account Number : ";
                            cin >> temp_acc_num;
                            if (s.Existing(temp_acc_num))
                            {
                                i = 0;
                                while (i < 3)
                                {
                                    cout << "Pin Code : ";
                                    cin >> temp_acc_pin;
                                    i++;
                                    pass = s.password(temp_acc_num);
                                    if (pass == temp_acc_pin)
                                    {
                                        i = 3;
                                        s.delete_(temp_acc_num);
                                    }
                                    else
                                    {
                                        cout << "Wrong Pin Code" << endl;
                                        cout << 3 - i << " trials left!" << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Account doesn't Exists!" << endl;
                            }
                        }
                        else if (choice2 != 0)
                        {
                            cout << "Enter Valid choice!" << endl;
                        }
                    } while (choice2 != 0);
                }
                else if (choice1 != 0)
                {
                    cout << "Enter Valid Choice!" << endl;
                }
            } while (choice1 != 0);
        }
        else if (choice != 0)
        {
            cout << "Invalid Choice!" << endl;
        }
        else if (choice == 0)
        {
            cout << "Thanks for using our service!" << endl;
        }
    }
}