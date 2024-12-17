# Console Atm Crud System in C++

## Description
This is a simple C++-based Console Atm Crud System that allows users to perform various banking operations such as creating an account, depositing and withdrawing money, transferring funds, checking account balances, and more. It also supports functionalities like editing, deleting accounts, and generating a master list of account holders. All data is stored in a binary file (`bank.txt`) for persistence.

## Features
- **Create New Account**: Allows users to create a new bank account by entering account type, number, holder's name, and initial deposit.
- **Deposit Money**: Allows users to deposit money into their account.
- **Withdraw Money**: Allows users to withdraw money from their account.
- **Balance Inquiry**: Enables users to check the balance in their account.
- **Transfer Money**: Facilitates transferring money from one account to another.
- **Edit/Change Account**: Allows users to modify the account holder's name, account type, and balance.
- **Delete Account**: Users can delete their bank account.
- **Account Holder Masterlist**: Displays a list of all bank accounts, showing account numbers, names, account types, and balances.
  
## Requirements
- C++ compiler (e.g., GCC, Clang)
- C++ Standard Library (for I/O operations, file handling, etc.)
  
## How to Use

1. **Compile the Program**: 
   - If using GCC, compile the code using the following command:
     ```bash
     g++ main.cpp -o bank_account_system
     ```

2. **Run the Program**:
   - After compilation, run the program with the following command:
     ```bash
     ./main.exe
     ```

3. **Menu Options**:
   - Once the program starts, you will be presented with a menu with various options. Choose the desired option by entering the corresponding number.
     - `1`: Create a new account.
     - `2`: Deposit money into an account.
     - `3`: Withdraw money from an account.
     - `4`: Check balance of an account.
     - `5`: Transfer money to another account.
     - `6`: View the account holder masterlist.
     - `7`: Edit an existing account.
     - `8`: Delete an account.
     - `0`: Exit the program.

4. **Account Details**:
   - For operations that involve specific accounts (deposit, withdraw, transfer, etc.), you will be prompted to enter the account number. Afterward, you can perform the operation by following the prompts.
   
5. **Data Storage**:
   - The system stores account information in a binary file (`bank.txt`), allowing the data to persist even after the program is closed. Make sure the file is accessible to avoid data loss.

6. **Exit**:
   - To exit the program, select the `0` option from the menu.

## Screenshots
![Screenshot 1](https://github.com/Caelli22/Basic-Console-Atm-in-CPP/blob/main/screenshots/1.png)
![Screenshot 2](https://github.com/Caelli22/Basic-Console-Atm-in-CPP/blob/main/screenshots/3.png)
![Screenshot 3](https://github.com/Caelli22/Basic-Console-Atm-in-CPP/blob/main/screenshots/3.png)
