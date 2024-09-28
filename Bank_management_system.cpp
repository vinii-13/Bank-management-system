#include <bits/stdc++.h>
using namespace std;

class account {
private:
    string acc_num;
    string acc_pass;
    double acc_balance;
    friend class user;
public:
    account(string num, string pass) {
        acc_num = num;
        acc_pass = pass;
        acc_balance = 0.0;
    }
};

class user {
private:
    string name;
    string email;
    vector<account> alist;
public:
    // Default constructor
    user() {}

    // Constructor with name and email
    user(string n, string e) {
        name = n;
        email = e;
    }

    // Adding accounts
    void addAcc(account acc) {
        alist.push_back(acc);
        cout << "Account added successfully!" << endl<< endl;
    }

    // Deposit function
    void depositSum(string num, string pass, double balance) {
        for (auto& it : alist) {  // Use reference to modify original
            if (it.acc_num == num && it.acc_pass == pass) {
                it.acc_balance += balance;
                cout << "An amount of " << balance << " has successfully been deposited to account number " << num << endl<<endl;
                return;
            }
        }
        cout << "Invalid account number or password." << endl << endl;
    }

    // Withdraw function
    void withdrawSum(string num, string pass, double bal) {
        for (auto& it : alist) {  // Use reference to modify original
            if (it.acc_num == num && it.acc_pass == pass) {
                if (it.acc_balance < bal) {
                    cout << "Insufficient balance." << endl << endl;
                } else {
                    it.acc_balance -= bal;
                    cout << "Withdrawal Successful" << endl << endl;
                }
                return;
            }
        }
        cout << "Invalid account number or password." << endl << endl;
    }

    // Get balance function
    void getbalance(string num, string pass) {
        for (auto& it : alist) {  // Use reference to access original
            if (it.acc_num == num && it.acc_pass == pass) {
                cout << "Current balance: " << it.acc_balance << endl << endl;
                return;
            }
        }
        cout << "Invalid account number or password." << endl << endl;
    }

    // Display user details
    void user_details() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Accounts:" << endl;
        for (auto& it : alist) {
            cout << it.acc_num << endl;
        }
        cout<< endl;
    }
};

void showMainMenu() {
    cout << "______________________" << endl;
    cout << "|  1. New user       |" << endl;
    cout << "|  2. Existing user  |" << endl;
    cout << "|__3. Exit___________|" << endl;
}

void showUserMenu() {
    cout << "Please select your service:" << endl;
    cout << "_____________________" << endl;
    cout << "|  1. Add account   |" << endl;
    cout << "|  2. Deposit sum   |" << endl;
    cout << "|  3. Withdraw sum  |" << endl;
    cout << "|  4. Get balance   |" << endl;
    cout << "|  5. User details  |" << endl;
    cout << "|__6. Exit__________|" << endl;
}

unordered_map<string, user> users;

int main() {
    int main_choice;
    string namee, email;

    while (true) {
        cout << "_________________________" << endl;
        cout << "|__Welcome to the Bank__|" << endl;

        showMainMenu();
        cout << "Enter your choice: ";
        cin >> main_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline
        cout << endl;

        if (main_choice == 3) {  // Exit option
            cout << "Exiting the system." << endl<< endl;
            break;
        }

        switch (main_choice) {
        case 1: { // New user creation
            cout << "Enter your name: ";
            getline(cin, namee);  // Use getline for name
            cout << "Enter your email: ";
            cin >> email;

            users[email] = user(namee, email);
            cout << "User added successfully!" << endl;

            int user_choice;
            bool user_menu_exit = false;  // Flag to break out of user menu

            while (!user_menu_exit) {
                showUserMenu();
                cout << "Enter your choice: ";
                cin >> user_choice;
                cout << endl;

                switch (user_choice) {
                case 1: {
                    string acc_num, acc_pass;
                    cout << "Enter new account number: ";
                    cin >> acc_num;
                    cout << "Enter account password: ";
                    cin >> acc_pass;
                    cout << endl;
                    users[email].addAcc(account(acc_num, acc_pass));
                    break;
                }
                case 2: {
                    string acc_num, acc_pass;
                    double deposit_amount;
                    cout << "Enter account number: ";
                    cin >> acc_num;
                    cout << "Enter account password: ";
                    cin >> acc_pass;
                    cout << "Enter amount to deposit: ";
                    cin >> deposit_amount;
                    cout << endl;
                    users[email].depositSum(acc_num, acc_pass, deposit_amount);
                    break;
                }
                case 3: {
                    string acc_num, acc_pass;
                    double withdraw_amount;
                    cout << "Enter account number: ";
                    cin >> acc_num;
                    cout << "Enter account password: ";
                    cin >> acc_pass;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdraw_amount;
                    cout << endl;
                    users[email].withdrawSum(acc_num, acc_pass, withdraw_amount);
                    break;
                }
                case 4: {
                    string acc_num, acc_pass;
                    cout << "Enter account number: ";
                    cin >> acc_num;
                    cout << "Enter account password: ";
                    cin >> acc_pass;
                    cout << endl;
                    users[email].getbalance(acc_num, acc_pass);
                    break;
                }
                case 5:
                    users[email].user_details();
                    break;
                case 6:
                    user_menu_exit = true;  // Exit user menu
                    break;
                default:
                    cout << "Invalid choice!" << endl<< endl;
                }
            }
            break;
        }

        case 2: { // Existing user
            cout << "Enter your email: ";
            cin >> email;

            if (users.find(email) != users.end()) {
                cout << "User found!" << endl<< endl;

                int user_choice;
                bool user_menu_exit = false;  // Flag to break out of user menu

                while (!user_menu_exit) {
                    showUserMenu();
                    cout << "Enter your choice: ";
                    cin >> user_choice;
                    cout << endl;

                    switch (user_choice) {
                    case 1: {
                        string acc_num, acc_pass;
                        cout << "Enter new account number: ";
                        cin >> acc_num;
                        cout << "Enter account password: ";
                        cin >> acc_pass;
                        users[email].addAcc(account(acc_num, acc_pass));
                        break;
                    }
                    case 2: {
                        string acc_num, acc_pass;
                        double deposit_amount;
                        cout << "Enter account number: ";
                        cin >> acc_num;
                        cout << "Enter account password: ";
                        cin >> acc_pass;
                        cout << "Enter amount to deposit: ";
                        cin >> deposit_amount;
                        users[email].depositSum(acc_num, acc_pass, deposit_amount);
                        break;
                    }
                    case 3: {
                        string acc_num, acc_pass;
                        double withdraw_amount;
                        cout << "Enter account number: ";
                        cin >> acc_num;
                        cout << "Enter account password: ";
                        cin >> acc_pass;
                        cout << "Enter amount to withdraw: ";
                        cin >> withdraw_amount;
                        users[email].withdrawSum(acc_num, acc_pass, withdraw_amount);
                        break;
                    }
                    case 4: {
                        string acc_num, acc_pass;
                        cout << "Enter account number: ";
                        cin >> acc_num;
                        cout << "Enter account password: ";
                        cin >> acc_pass;
                        users[email].getbalance(acc_num, acc_pass);
                        break;
                    }
                    case 5:
                        users[email].user_details();
                        break;
                    case 6:
                        user_menu_exit = true;  // Exit user menu
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                    }
                }
            } else {
                cout << "User not found!" << endl;
            }
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}