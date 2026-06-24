//=====================================================
//                 Bank Management System      
//=====================================================

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Database; // Forward Declaration

class LoginPanel {

private:

    string Username;
    string Password;

public:

    LoginPanel() {

        Username = "";
        Password = "";
    }

    bool Login() {

        cout << "================================" << endl;
        cout << "          Login Panel           " << endl;
        cout << "================================" << endl;
        cout << endl;
        cout << "Enter User name:" << endl;
        getline(cin, Username);

        cout << "Enter Password:" << endl;
        getline(cin, Password);

        if (Username == "HamKhan5619" && Password == "Hamza21") {
            cout << "Login Successfully!" << endl;
            return true;
        } else {
            cout << "Invalid Credentials!" << endl;
            return false;
        }
    }

    friend class Database;

};

class Customer {

private:

    string Customer_Name;
    string CNIC;
    string Phone_Number;
    float Account_Number;

public:

    Customer() {
        Customer_Name = "";
        CNIC = "";
        Phone_Number = "";
        Account_Number = 0;
    }

    void CreateAccount() {

        cout << "================================" << endl;
        cout << "         Create Account         " << endl;
        cout << "================================" << endl;
        cout << endl;
        cout << "Enter Customer Name:" << endl;
        getline(cin, Customer_Name);
        cout << "Enter Customer CNIC Number:" << endl;
        getline(cin, CNIC);
        if (CNIC.length() == 13) {
            cout << "CNIC Verified!" << endl;
        } else {
            cout << "CNIC Unverified!" << endl;
        }

        cout << "Enter Customer Phone Number:" << endl;
        getline(cin, Phone_Number);
        cout << "Enter Customer Account Number:" << endl;
        cin >> Account_Number;
        if (Account_Number > 0) {
            cout << "Account Number Issued Successfully!" << endl;
        } else {
            cout << "Invalid Account Number!" << endl;
        }
    }

    void DisplayCustomerDetails() {

        cout << "================================" << endl;
        cout << "        Customer Details        " << endl;
        cout << "================================" << endl;
        cout << endl;
        cout << "Name: " << Customer_Name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Phone: " << Phone_Number << endl;
        cout << "Account: " << Account_Number << endl;
        cout << "--------------------------"<<endl;
    }

    friend class Database;

};

class Transaction {

private:

    float Balance;
    float LastDeposit;
    float LastWithdraw;

public:

    Transaction() {

        Balance = 0;
        LastDeposit = 0;
        LastWithdraw = 0;
    }

    void Deposit() {

        float amount;

        cout << "Enter Amount:" << endl;
        cin >> amount;
        if (amount > 0) {
            Balance += amount;
            LastDeposit = amount;
            cout << "Amount Deposited Successfully!" << endl;
        } else {
            cout << "Invalid Amount" << endl;
        }
    }

    void Withdraw() {

        float amount;

        cout << "Enter Amount:" << endl;
        cin >> amount;
        if (amount > 0) {
            if (amount <= Balance) {
                Balance -= amount;
                LastWithdraw = amount;
                cout << "Amount Withdrawn Successfully!" << endl;
            } else {
                cout << "Insufficient Balance!" << endl;
            }
        } else {
            cout << "Invalid Amount" << endl;
        }
    }

    void CheckBalance() {

        cout << "Total Balance: " << Balance << endl;
    }

    void TransactionHistory() {

        cout << "================================" << endl;
        cout << "       Transaction History       " << endl;
        cout << "================================" << endl;
        cout << endl;
        cout << "Last Deposit: " << LastDeposit << endl;
        cout << "Last Withdraw: " << LastWithdraw << endl;
        cout << "Balance: " << Balance << endl;
        cout << "--------------------------------" << endl;
    }

    friend class Database;
};

class Feedback {
private:
    string feedback;

public:
    void GiveFeedback() {
        cout << "Feedback:" << endl;
        cin.ignore();
        getline(cin, feedback);
    }
};

class Database {
public:
    void SaveAdmin(LoginPanel obj) {
        ofstream file("admin.txt", ios::app);

        cout << "================================" << endl;
        cout << "        Password Manager        " << endl;
        cout << "================================" << endl;
        cout << endl;
        file << "Username: " << obj.Username << endl;
        file << "Password: " << obj.Password << endl;
        file << "------------------------" << endl;

        file.close();
    }

    void SaveCustomer(Customer obj) {

        ofstream file("customer.txt", ios::app);

        cout << "================================" << endl;
        cout << "      Saved Customer Record     " << endl;
        cout << "================================" << endl;
        cout << endl;
        file << "Name: " << obj.Customer_Name << endl;
        file << "CNIC: " << obj.CNIC << endl;
        file << "Phone: " << obj.Phone_Number << endl;
        file << "Account: " << obj.Account_Number << endl;
        file << "------------------------" << endl;

        file.close();
    }

    void SaveTransaction(Transaction obj) {
        ofstream file("transaction.txt", ios::app);

        cout << "================================" << endl;
        cout << "   Saved Transaction History    " << endl;
        cout << "================================" << endl;
        cout << endl;
        file << "Balance: " << obj.Balance << endl;
        file << "Deposit: " << obj.LastDeposit << endl;
        file << "Withdraw: " << obj.LastWithdraw << endl;
        file << "--------------------------" << endl;

        file.close();
    }
};

int main() {

    Database db;
    LoginPanel login;
    Customer customer;
    Transaction transaction;
    Feedback feedback;

    if (login.Login()) {

        db.SaveAdmin(login);

        int choice;

        do {

            cout << endl;
            cout << "================================" << endl;
            cout << "     Bank Management System     " << endl;
            cout << "================================" << endl;
            cout << endl;
            cout << "1. Create Customer Account" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Transaction History" << endl;
            cout << "5. Display Customer" << endl;
            cout << "6. Give Feedback" << endl;
            cout << "7. Exit" << endl;
            cout<<"-----------------------------------"<<endl;

            cout << "Enter Choice:" << endl;
            cin >> choice;

            cin.ignore();

            switch (choice) {

                case 1:
                    customer.CreateAccount();
                    db.SaveCustomer(customer);
                    break;

                case 2:
                    transaction.Deposit();
                    db.SaveTransaction(transaction);
                    break;

                case 3:
                    transaction.Withdraw();
                    db.SaveTransaction(transaction);
                    break;

                case 4:
                    transaction.TransactionHistory();
                    break;

                case 5:
                    customer.DisplayCustomerDetails();
                    break;

                case 6:
                    feedback.GiveFeedback();
                    break;

                case 7:
                    cout << "Thank You for Using Bank Management System!" << endl;
                    break;

                default:
                    cout << "Invalid Choice!" << endl;
            }

        } while (choice != 7);

    }

    return 0;

}