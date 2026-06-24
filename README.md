# 🏦 Bank Management System

A console-based Bank Management System built in C++ that simulates core banking operations including account creation, deposits, withdrawals, and transaction history — all secured behind a login panel with file-based data persistence.

---

## 📋 Features

- **Secure Login Panel** — Admin authentication before accessing any banking operations
- **Customer Account Management** — Create and display customer profiles with CNIC verification
- **Deposit & Withdrawal** — Real-time balance updates with input validation
- **Transaction History** — View last deposit, last withdrawal, and current balance
- **Customer Feedback** — Built-in feedback collection module
- **File Persistence** — All records (admin, customer, transactions) are saved to `.txt` files

---

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts:** Object-Oriented Programming (OOP), File I/O, Friend Classes
- **Paradigm:** Class-based design with encapsulation and access control

---

## 🏗️ Project Structure

```
BankManagementSystem/
├── main.cpp          # Main source file
├── admin.txt         # Saved admin login records
├── customer.txt      # Saved customer records
└── transaction.txt   # Saved transaction history
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (GCC / G++ recommended)
- Terminal or Command Prompt

### Compile & Run

```bash
g++ main.cpp -o BankSystem
./BankSystem
```

### Default Login Credentials

| Field    | Value        |
|----------|--------------|
| Username | `HamKhan5619` |
| Password | `Hamza21`     |

---

## 📌 Menu Options

| Option | Description               |
|--------|---------------------------|
| 1      | Create Customer Account   |
| 2      | Deposit Money             |
| 3      | Withdraw Money            |
| 4      | View Transaction History  |
| 5      | Display Customer Details  |
| 6      | Give Feedback             |
| 7      | Exit                      |

---

## 🧱 Class Overview

| Class         | Responsibility                                      |
|---------------|-----------------------------------------------------|
| `LoginPanel`  | Handles admin authentication                        |
| `Customer`    | Stores and displays customer information            |
| `Transaction` | Manages deposits, withdrawals, and balance tracking |
| `Feedback`    | Collects user feedback                              |
| `Database`    | Saves all records to text files via `ofstream`      |

---

## 📂 Sample Output Files

**customer.txt**
```
Name: John Doe
CNIC: 3520212345678
Phone: 03001234567
Account: 100001
------------------------
```

**transaction.txt**
```
Balance: 5000
Deposit: 5000
Withdraw: 0
--------------------------
```

---

## ⚠️ Limitations

- Single-user session (one customer per run)
- Credentials are hardcoded (not stored securely)
- No database integration; records stored in plain text files
- No duplicate account detection

---

## 🔮 Future Improvements

- Multi-customer support with search functionality
- Encrypted credential storage
- GUI interface using Qt or a web front-end
- Proper database integration (SQLite / MySQL)

---

## 👨‍💻 Author

**Hamza Khan**
GitHub: [@itxkhan8080-Maker](https://github.com/itxkhan8080-Maker)

---

## 📄 License

This project is for educational purposes. Feel free to use and modify it.
