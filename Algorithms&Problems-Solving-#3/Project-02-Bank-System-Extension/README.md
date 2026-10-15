# Bank System - Project 2

This is the second Bank System project that I built using C++.

This project is an extension of the first Bank System project. I kept the client management features and added a new Transactions Menu for working with account balances.

How It Works

When the program starts, it loads the clients from "Clients.txt" and stores them in a vector.

The main menu allows the user to manage clients or go to the Transactions Menu.

Client Management

The program can:

- List all clients
- Add a new client
- Delete a client
- Update client information
- Find a client

Transactions Menu

The Transactions Menu has three main operations:

- Deposit: Add an amount to a client's account balance.
- Withdraw: Subtract an amount from a client's account balance.
- Total Balances: Show all clients with their balances and the total balance of all accounts.

Before making a deposit or withdrawal, the program asks the user for the account number and shows the client's information.

The user can then enter the amount and confirm the transaction.

After a successful transaction, the new balance is saved to "Clients.txt".

File Storage

The client data is stored in:

"Clients.txt"

Each client is stored on a separate line using "#//#" as a separator.

The program loads the data when it starts and saves the updated data after changes or transactions.

Important Functions

## Some of the main functions in this project are:

- "DepositBalanceToClientByAccountNumber()" → adds money to an account.
- "WithdrawBalanceToClientByAccountNumber()" → subtracts money from an account.
- "ShowDepositScreen()" → handles the deposit operation.
- "ShowWithDrowScreen()" → handles the withdrawal operation.
- "ShowTotalBalances()" → displays the total balances.
- "SaveClientDataToFile()" → saves the updated client data.

What I Learned

In this project, I practiced:

- Working with vectors and structs
- File handling
- Functions and menus
- References
- Updating data inside a vector
- Saving changes to a file
- Working with account balances
- Building a larger program from smaller functions

One important thing I learned was the difference between changing a copy of a client and changing the actual client inside the vector. Using a reference allowed me to update the real client data before saving it.

My Experience

This project was more challenging than the first one because it added transactions and required me to update the client's balance correctly.

It helped me understand better how functions, vectors, references, and file handling can work together in a larger C++ project.

Project Status: Completed ✅