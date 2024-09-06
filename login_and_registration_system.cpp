#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
using namespace std;
class User {
private:
    string USERNAME, PASSWORD;
public:
    string username, password;
     string temp_username, temp_password;
    void user_Registration(string username, string password) {
        this->username = username;
        this->password = password;
        ofstream write_file("user.txt", ios::app); 
        write_file << username << endl;
        write_file << password << endl;
        write_file.close();
        cout << "User Registered Successfully..." << endl;
    }
    bool user_login() {
        cout << "Enter your username: ";
        cin.ignore();
        getline(cin, temp_username);
        cout << "Enter your password: ";
        getline(cin, temp_password);
        ifstream read_file("user.txt");
        while (getline(read_file, USERNAME) && getline(read_file, PASSWORD)) {
            if (temp_username == USERNAME && temp_password == PASSWORD) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    string u, p;
    int choice; 
    vector<User> users; 
do{
    cout<<endl<<endl<<endl;
    cout << "                  << LOGIN AND REGISTRATION SYSTEM >>" <<endl<< endl;
    cout << "     ENTER YOUR CHOICE:" << endl<<endl;
    cout << "     1. REGISTRATION" << endl;
    cout << "     2. LOGIN" << endl;
    cout << "     3. EXIT" << endl;
    cin >> choice;
    if (choice == 1) {
        User user;
        cout << "Enter your username: ";
        cin.ignore();
        getline(cin, u);
        cout << "Enter your password: ";
        getline(cin, p);
        user.user_Registration(u, p);
        users.push_back(user); 
        cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU ";
        getch();
    } else if (choice == 2) {
        User user;
        if (user.user_login()) {
            cout << "Valid User" << endl;
            cout << "Username is " << user.temp_username << endl;
            cout << "Password is " << user.temp_password << endl;
            cout << "Login Successfully..." << endl;
        } else {
            cout << "Invalid Username or Password" << endl;
        }
        cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU ";
        getch();
    }
    else if(choice==3){
        break;
    }
    system("cls");
}while(true);
}
