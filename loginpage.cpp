
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void registration();
void login();
void forgot();
int main()
{
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t||-----------WELCOME TO LOGIN PAGE-----------||\t\t\t\n";
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t||(1):->LOGIN      ||(2):->REGISTER YOURSELF ||\t\t\t\n";
    cout << "\t\t\t||(4):->EXIT       ||(3):->FORGOT PASSWORD   ||\t\t\t\n";
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    int choice;
    cout << "\t\t\t  ENTER YOUR CHOICE  :";

    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        login();
        break;
    }
    case 2:
    {
        registration();
        break;
    }
    case 3:
    {
        forgot();
        break;
    }
    case 4:
    {
        cout << "\t\t\t||--------THANK YOU !HAVE A NICE DAY---------||\t\t\t\n";
        break;
    }
    default:
    {
        cout << "\t\t\t||--------------INVALID INPUT----------------||\t\t\t\n";
        break;
    }
    }

    return 0;
}
void registration()
{
    int count = 0;
    string rusername, rpassword;
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t  ENTER USER NAME  :";
    cin >> rusername;
    cout << "\t\t\t  ENTER PASSWORD   :";
    cin >> rpassword;
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";

    ofstream input;
    input.open("data.txt", ios::app);
    input << rusername << " " << rpassword << endl;
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t||----------REGISTRATION SUCCESS-------------||\t\t\t\n";
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    main();
};
void login()
{
    ifstream input;
    input.open("data.txt");
    bool run = false;
    string password, username, uname, upass;
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t  ENTER USER NAME  :";
    cin >> username;
    cout << "\t\t\t  ENTER PASSWORD   :";
    cin >> password;
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    while (input >> uname >> upass)
    {
        if (uname == username && upass == password)
        {
            run = true;
            break;
        }
    }
    input.close();
    if (run)
    {
        cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
        cout << "\t\t\t||-----------YOU ARE LOGGED IN---------------||\t\t\t\n";
        cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
        main();
    }
    else
    {
        cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
        cout << "\t\t\t||----------LOGIN ERROR TRY AGAIN -----------||\t\t\t\n";
        cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
        main();
    }
    // main();
}
void forgot()
{
    int option;
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t||-------FORGOT PASSWARD DON'T WORRY---------||\t\t\t\n";
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t||(1):->LOGIN BY OLD USERNAME................||\t\t\t\n";
    cout << "\t\t\t||(2):->BACK TO MENUBAR......................||\t\t\t\n";
    cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
    cout << "\t\t\t  ENTER YOUR CHOICE  :";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string username, userid, password;
        cout << "\t\t\t  ENTER YOUR USERID YOU KNOW  :";
        cin >> userid;
        ifstream cheak;
        cheak.open("data.txt");
        while (cheak >> username >> password)
        {
            if (userid == username)
            {
                count = 1;
                break;
            }
        }
        cheak.close();
        if (count == 1)
        {
            cout << "\t\t\t||-------WELL YOUR ACCOUNT IS FOUND !--------||\t\t\t\n";
            cout << "\t\t\t||YOUR PASSWORD IS : " << password << " -----||\t\t\t\n";
            cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
            main();
        }
        else
        {
            cout << "\t\t\t||-----SORRY YOUR ACCOUNT IS NOT FOUND !-----||\t\t\t\n";
            cout << "\t\t\t||-------------------------------------------||\t\t\t\n";
            main();
        }
    }
    }
}
