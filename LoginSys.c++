#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Login();
void registernewuser();
void ForgetPass();

int main()
{
    system("cls");
    cout << "\t \t \t                  Welcome to User authentication System                             " << endl;
    cout << "\t Please Enter Actions : " << endl
         << "\t 1. Register a New User " << endl
         << "\t 2. Login as an existing user " << endl
         << "\t 3. Forgot Password" << endl
         << "\t 4. Close the applications" << endl;
    cout << "\t Enter Your Actions : ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        registernewuser();
        break;
    case 2:
        Login();
        break;
    case 3:
        ForgetPass();

        break;
    case 4:
        return 0;
        break;

    default:
        cout << "\t Please Enter a valid choice !" << endl;
        main();
        break;
    }
}

void Login()
{
    string username, password, ur, ps;
    system("cls");

    cout << endl
         << "Please Enter Your Username : ";
    cin >> username;
    cout << endl
         << "Please Enter Your Password : ";
    cin >> password;

    ifstream file("registry.txt");
    int count = 0;
    while (file >> ur >> ps)
    {
        if (username == ur && password == ps)
        {
            count = 1;
            system("cls");
            break; // No need to continue the loop if the credentials are found
        }
    }
    file.close();

    if (count == 1)
    {
        system("cls");
        cout << "Login Successful" << endl;
        system("Pause");
        main();
    }
    else
    {
        cout << "Login Error" << endl;
        system("Pause");
        main();
    }
}

void registernewuser()
{
    string ruser, rpass;

    cout << endl
         << "Please Enter Your Username : ";
    cin >> ruser;
    cout << endl
         << "Please Enter Your Password : ";
    cin >> rpass;
    ofstream file("registry.txt", ios::app);

    file << ruser << " " << rpass << endl;

    system("cls");

    cout << "Registration Succesful" << endl;

    system("Pause");
    main();
}

void ForgetPass()
{
    string username, us, ps;
    system("cls");
    int inp = 0;
    int countf = 0; // Declare countf outside the switch statement
    cout << "1. To find password using username : " << endl
         << "2. Go Back " << endl;

    cout << "Enter Your Choise : ";
    cin >> inp;
    if (inp == 1)
    {
        cout << "Enter Your Username : ";
        cin >> username;

        ifstream file("registry.txt");
        while (file >> us >> ps)
        {
            if (username == us)
            {
                countf = 1;
                break;
            }
        };
        file.close();
        if (countf == 1)
        {
            system("cls");
            cout << "Your Account Was Found " << endl
                 << "Your Password is " << ps << endl;
            system("Pause");
            main();
        }
        else
        {
            cout << "Sorry Your Account Couldnt be found" << endl;
            system("Pause");
            main();
        }
    }
    else if (inp == 2)
    {
        system("Pause");
        main();
    }
    else
    {
        cout << "Invalid Input";
        ForgetPass();
    }
}
