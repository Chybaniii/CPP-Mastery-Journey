# Bank System (C++ Console)

A console bank system written in C++. It stores everything in plain text files, so there is no database to set up. You log in with a user account, and what you can do depends on the permissions that user has.

I built it while following a C++ course.

## What it does

**Clients**
- Show all clients
- Add, delete, update and find a client
- Transactions: deposit, withdraw, and show the total balances

**Users**
- Login and logout
- List, add, delete, update and find users
- Each user has permissions. A user without a permission gets an "Access Denied" message when they try that option
- The `Admin` user can't be deleted

## How permissions work

Every permission is a power of 2 (1, 2, 4, 8, 16, 32, 64), and a user's permissions are stored as one number in the file. To check a permission I use the bitwise AND operator (`&`). The value `-1` means full access.

For example, a user with permissions `5` (1 + 4) can list clients and delete clients, and nothing else.

## Files

The program reads and writes two text files next to the executable. Fields are separated by `#//#`.

`Clients.txt`
```
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
1001#//#1234#//#Ali Ahmed#0612345678#5000.000000
```
(Write it with `#//#` between every field, including before the phone.)

`Users.txt`
```
UserName#//#Password#//#Permissions
Admin#//#1234#//#-1
```

You need a `Users.txt` with at least one user before the first run, otherwise you can't log in. Test login: `Admin` / `1234`.

## How to run

It uses `system("cls")` and `system("pause")`, so it works on Windows only.

1. Open the `.cpp` file in Visual Studio (or any C++ compiler)
2. Create `Users.txt` in the same folder as the program, with the Admin line above
3. Build and run

## What I practiced

- Structs, vectors and enums
- Reading and writing text files
- Splitting a string and converting lines to records
- Bitwise operators for permissions
- Splitting a program into small functions

## Known issues

- Passwords are saved as plain text
- Some screens go back to the menu through recursion, which is fine here but not good for a long session
