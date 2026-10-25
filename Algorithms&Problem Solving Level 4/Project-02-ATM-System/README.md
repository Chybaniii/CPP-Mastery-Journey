# ATM System (C++ Console)

A small ATM simulation written in C++. A client logs in with an account number and a PIN, then can withdraw, deposit and check the balance. The data is stored in a text file.

I made it while following a C++ course, after finishing the bank system project. It reuses the same client file and a lot of the same ideas, so it was a good way to practice them again.

## What it does

- Login with account number and PIN
- Quick withdraw: pick one of 20, 50, 100, 200, 400, 600, 800 or 1000
- Normal withdraw: any amount that is a multiple of 5
- Deposit
- Check balance
- Logout, which takes you back to the login screen

A withdrawal is refused if the amount is more than the balance. Every deposit and withdrawal asks for confirmation first.

## The data file

The program reads `Clients.txt` from the same folder. Fields are separated by `#//#`, one client per line:

```
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
```

Example line:
```
1001#//#1234#//#Ali Ahmed#0612345678#5000.000000
```
(Use `#//#` between every field, including before the phone.)

This is the same file the Bank System project uses, so you can run both on the same data.

Test login: account `1001`, PIN `1234`.

## How to run

It uses `system("cls")` and `system("pause")`, so it works on Windows only.

1. Open the `.cpp` file in Visual Studio (or any C++ compiler)
2. Put a `Clients.txt` file next to the program, with at least one client
3. Build and run

## What I practiced

- Reading and writing the same text file from different screens
- Keeping the logged-in client in a global variable and updating it after each operation
- Using a function's return value to decide whether to change the balance
- Input validation with while loops

## Known issues

- The PIN is saved as plain text
- It only works on Windows because of the `system()` calls
