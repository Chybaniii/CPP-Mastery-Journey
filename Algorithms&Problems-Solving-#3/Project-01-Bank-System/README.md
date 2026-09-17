Bank System - Project 1

This is a simple Bank System project that I built using C++ as part of my learning journey.

The program allows the user to manage bank clients through a console menu. Client information is stored in a text file called "Clients.txt".

How It Works

When the program starts, it reads the clients from "Clients.txt" and stores them in a "vector" of "sClient" records.

The main menu then allows the user to choose what they want to do:

- List Clients: Shows all clients and their information.
- Add New Client: Adds a new client after checking that the account number is not already used.
- Delete Client: Finds a client by account number, asks for confirmation, and removes the client.
- Update Client: Finds a client and allows changing the PIN, name, phone, and balance.
- Find Client: Searches for a client using the account number.
- Exit: Closes the program.

When the client data is changed, the program saves the updated data back to "Clients.txt".

Client Information

Each client contains:

- Account Number
- PIN Code
- Name
- Phone
- Account Balance

The data is stored in the file using "#//#" as a separator.

For example:

A200#//#1234#//#Mohammed#//#00222333#//#5000

The program splits this line into separate parts and converts them into an "sClient" record.

Main Parts of the Code

The project is divided into functions, where each function has a specific job.

Some important functions are:

- "SplitString()" → splits a line into parts.
- "ConvertLinToRecord()" → converts a file line into a client record.
- "ConvertRecordToLine()" → converts a client record back into a file line.
- "LoadClientsDataFromFile()" → loads all clients from the file.
- "SaveClientDataToFile()" → saves the clients to the file.
- "FindClientByAccountNumber()" → searches for a client.
- "ClientExistsByAccountNumber()" → checks if an account number already exists.

What I Practiced

This project gave me practice with:

- Structs
- Vectors
- Functions
- Enums
- Strings
- File handling
- Searching
- References
- Reading and writing data
- Debugging

My Experience

This was one of my first bigger C++ projects.

I had some problems while working on it, especially with reading and saving data from the file. Debugging these problems helped me understand the code better and understand how the different functions work together.

Project Status: Completed ✅