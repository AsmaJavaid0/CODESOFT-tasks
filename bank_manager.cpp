#include<iostream>
#include<conio.h>
#include<fstream>
#include<vector>
using namespace std;
class Menu;
class Customer{
    private:
    string customer_name,customer_fname, customer_ID,address,phone_no,account,password;
    double balance;
    public:
    void Create_Account();
    void Edit_Account();
    void Get_Account_Details();
};
   void Customer::Create_Account(){
    s:
    system("cls");
    cout<<"\n\n\t\t\t\t USER ACCOUNT "<<endl;
    cout<<"\n\t First Name :  ";
    cin>>customer_name;
    cout<<"\n\t Father's Name :  ";
    cin>>customer_fname;
    cout<<"\n\t Country :  ";
    cin>>address;
    cout<<"\n\t Phone Number :  ";
    cin>>phone_no;
    cout<<"\n\t ID :  ";
    cin>>customer_ID;
    cout<<"\n\t Password : ";
    cin>>password;
    cout<<"\n\t Current Balance : ";
    cin>>balance;
     fstream file("bank.txt", ios::in);
    string name, fname, ID, addr, phone, pass;
    double b;
    while (file >> name >> fname >> addr >> phone >> ID >> pass >> b) {
        if (ID == customer_ID) {
            cout << "\n\n\t\tUser ID Already Exists..." << endl<<"\t\tChange your ID.";
            file.close();
            getch();
            goto s;
        }
    }
    file.close();
    file.open("bank.txt", ios::app);
    file << customer_name << " " << customer_fname << " " << address << " " << phone_no << " " << customer_ID << " " << password << " " << balance << endl;
    file.close();
    cout << "\n\n\t\t Account Created Successfully..." << endl;
    getch(); 
}
void Customer::Edit_Account(){
    s1:
    system("cls");
    int choice;
    string temp_id, temp_password;
    cout<<"\n\n\t\t\t\t EDIT USER ACCOUNT "<<endl;
    cout<<"\n\n\t LOGIN :"<<endl;
    cout<<"\tEnter Your Id : ";
    cin>>temp_id;
    cout<<"\n\tEnter Your Password : ";
    cin>>temp_password;
    fstream file("bank.txt", ios::in);
    fstream temp_file("temp.txt", ios::out); 
    if (!file) {
        cout << "\t\tFailed to Open File..." << endl;
        return;
    }
    bool found = false;
    string name, fname, ID, addr, phone, pass;
    double balance;
    while (file >> name >> fname >> addr >> phone >> ID >> pass >> balance) {
        if (temp_id == ID && temp_password == pass) {
            found = true;
            e:
            cout<<"\n\t\t EDIT ACCOUNT"<<endl;
            cout<<"\t1. Change Name :"<<endl;
            cout<<"\t2. Change Father Name :"<<endl;
            cout<<"\t3. Change Country Name :"<<endl;
            cout<<"\t4. Change Phone Number :"<<endl;
            cout<<"\t5. Change ID :"<<endl;
            cout<<"\t6. Change Password :"<<endl;
            cout<<"\n\t Enter Your Choice... "<<endl;
            cin>>choice;
            system("cls");
            cout << "\n\tEnter New Value: ";
            string new_value;
            cin >> new_value;
            switch (choice) {
                case 1: name = new_value; break;
                case 2: fname = new_value; break;
                case 3: addr = new_value; break;
                case 4: phone = new_value; break;
                case 5: ID = new_value; break;
                case 6: pass = new_value; break;
                default: 
                    cout<<"\tInvalid Choice";
                    getch();
                    goto e;
            }
            cout << "\n\n\t\t Account Edited Successfully..." << endl;
        }
        temp_file << name << " " << fname << " " << addr << " " << phone << " " << ID << " " << pass << " " << balance << endl;
    }
    file.close();
    temp_file.close();
    if (!found) {
        cout << "\tInvalid ID or Password." << endl;
        getch();
        goto s1;
    }
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    getch();
}
void Customer::Get_Account_Details(){
    s:
    system("cls");
    string id,password;
    cout<<"\n\n\t\t\t GET ACCOUNT INFORMATION "<<endl;
    cout<<"\t\t LOGIN "<<endl;
    cout<<"\tEnter your Id : ";
    cin>>id;
    cout<<"\tEnter your password : ";
    cin>>password;
    fstream file("bank.txt",ios::in);
    if (!file) {
        cout << "\t\tFailed to Open File..." << endl;
    }
     bool found = false;
    string name, fname, ID, addr, phone, pass;
    double balance;
    while (file >> name >> fname >> addr >> phone >> ID >> pass >> balance) {
        if (id == ID &&password == pass) {
            found = true;
             cout<<"\n\n\t First Name :  "<<name;
             cout<<"\n\t Father's Name :  "<<fname;
             cout<<"\n\t Country :  "<<addr;
             cout<<"\n\t Phone Number :  "<<phone;
             cout<<"\n\t ID :  "<<ID;
             cout<<"\n\t Password : "<<pass;
             cout<<"\n\t Current Balance : "<<balance;
             cout<<"\n\n\t\t\tPRESS ANY KEY TO RETURN TO MAIN MENU ";
             getch();
}
    }   
    if(!found){
        cout<<"\tInvalid ID or User name "<<endl;
        getch();
        goto s;
    }
} 
class Transactions{
private:
double User_balance;
public:
    void Deposit_Money();
    void Withdraw_Money();
} ;
void Transactions::Deposit_Money(){
    string id,password;
    s1:
    system("cls");
    cout<<"\n\n\t\t\t DEPOSIT MONEY "<<endl;
     cout<<"\t\t LOGIN "<<endl;
    cout<<"\tEnter your Id : ";
    cin>>id;
    cout<<"\tEnter your password : ";
    cin>>password;
     fstream file("bank.txt",ios::in);
     fstream temp_file("temp.txt", ios::out);
    if (!file) {
        cout << "\t\tFailed to Open File..." << endl;
    }
     bool found = false;
    string name, fname, ID, addr, phone, pass;
    double balance,amount;
    while (file >> name >> fname >> addr >> phone >> ID >> pass >> balance) {
        if (id == ID &&password == pass) {
            found = true;
            cout<<"\n\t\tEnter the amount you want to deposit ";
            cin>>amount;
            balance= balance+amount;
}
    
    temp_file << name << " " << fname << " " << addr << " " << phone << " " << ID << " " << pass << " " << balance << endl;
    }cout<<"\t\tMoney has been Deposited to your account..."<<endl;
     file.close();
    temp_file.close();
    if (!found) {
        cout << "\tInvalid ID or Password." << endl;
        getch();
        goto s1;
    }
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    getch();
}
void Transactions::Withdraw_Money(){
 string id,password;
    s1:
    system("cls");
    cout<<"\n\n\t\t\t Withdraw MONEY "<<endl;
     cout<<"\t\t LOGIN "<<endl;
    cout<<"\tEnter your Id : ";
    cin>>id;
    cout<<"\tEnter your password : ";
    cin>>password;
     fstream file("bank.txt",ios::in);
     fstream temp_file("temp.txt", ios::out);
    if (!file) {
        cout << "\t\tFailed to Open File..." << endl;
    }
     bool found = false;
    string name, fname, ID, addr, phone, pass;
    double balance,amount;
    while (file >> name >> fname >> addr >> phone >> ID >> pass >> balance) {
        if (id == ID &&password == pass) {
            found = true;
            e:
            cout<<"\n\t\tEnter the amount you want to Withdraw ";
            cin>>amount;
            if(amount<balance){
              balance= balance-amount;
            }
            else{
            cout<<"\t\t You Do not have enough money to withdraw...";
            getch();
            goto e;
            }
}
    
    temp_file << name << " " << fname << " " << addr << " " << phone << " " << ID << " " << pass << " " << balance << endl;
    }cout<<"\t\tMoney has been Withdrawn..."<<endl;
     file.close();
    temp_file.close();
    if (!found) {
        cout << "\tInvalid ID or Password." << endl;
        getch();
        goto s1;
    }
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    getch();   
}
class Menu{
    private:
    public:
    Customer C;
    Transactions T;
    void menu1();
    void menu2();
    void menu3();
};
void Menu::menu1(){
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t\t CONTROL PANEL "<<endl;
    cout<<"\n\t1. Bank Management  "<<endl;
    cout<<"\t2. ATM Management "<<endl;
    cout<<"\t3. Exit.."<<endl;
    cout<<"\n\t\t Enter your choice..."<<endl;
    cin>>choice;
    switch(choice){
    case 1:
        menu3();
        break;
    case 2:
        menu2();
        break;
    case 3:
        exit(0);
    }
}
void Menu::menu2(){
    s:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t\t ATM MANAGEMENT"<<endl;
    cout<<"\n\t1. Deposit Amount "<<endl;
    cout<<"\t2. Withdraw Amount "<<endl;
    cout<<"\t3. User Login and Check Balance "<<endl;
    cout<<"\t4. Go Back To Main Menu "<<endl;
    cout<<"\n\t\t Enter your choice...";
    cin>>choice;
    switch(choice){
        case 1:
          T.Deposit_Money();
        break;
        case 2:
          T.Withdraw_Money();
        break;
        case 3:
          C.Get_Account_Details();
        break;
        case 4:
        menu1();
        break;
        default:
        cout<<"Enter a valid option "<<endl;
        getch();
    } goto s;
}
void Menu::menu3(){
    s:
    system("cls");
    int choice;
     cout<<"\n\n\t\t\t\t BANK MANAGEMENT"<<endl;
    cout<<"\n\t1. Create Account "<<endl;
    cout<<"\t2. Edit Account "<<endl;
    cout<<"\t3. Get Account Details "<<endl;
    cout<<"\t4. Go Back To Main Menu "<<endl;
    cout<<"\n\t\t Enter your choice...";
    cin>>choice;
     switch(choice){
        case 1:
           C.Create_Account();
        break;
        case 2:
           C.Edit_Account();
        break;
        case 3:
           C.Get_Account_Details();
        break;
        case 4:
        menu1();
        break;
        default:
        cout<<"Enter a valid option "<<endl;
        getch();
     }
        goto s;
    
}
int main(){
    Menu M;
   M.menu1();
    
}