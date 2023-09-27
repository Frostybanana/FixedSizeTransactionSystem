#pragma once

#include <iostream>
#include <fstream>
#include "ClientData.h"
#include "OutputLine.h"
#include <cstdlib>

int getAccountNumber(const char* const line){
    int accountNumber;

    do{
        std::cout << line << " (1 - 100): ";
        std::cin >> accountNumber;
    }
    while(accountNumber < 1 && accountNumber > 100);

    return accountNumber;
}

void addClient(std::fstream& insertFile){
    int accountNum = getAccountNumber("Enter new account number");

    insertFile.seekg((accountNum-1)*sizeof(ClientData));

    ClientData client;
    insertFile.read(reinterpret_cast<char*> (&client), sizeof(ClientData));

    if(client.getAccNumber() == 0){
        std::string lastName;
        std::string firstName;
        double balance;

        std::cout << "Enter lastname, firstname, balance\n? ";
        std::cin >> lastName;
        std::cin >> firstName;
        std::cin >> balance;

        client.setAccNumber(accountNum);
        client.setBalance(balance);
        client.setFName(firstName);
        client.setLName(lastName);

        insertFile.seekp((accountNum-1)*sizeof(ClientData));
        insertFile.write(reinterpret_cast<char*> (&client), sizeof(ClientData));
    }
    else {
        std::cerr << "Account #" << accountNum << "already exists" << std::endl;
    }
}

void deleteClient(std::fstream& deleteFile){
    int accountNumber = getAccountNumber("Enter your account number");

    deleteFile.seekg((accountNumber - 1)*sizeof(ClientData));

    ClientData client;
    deleteFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if(client.getAccNumber() != 0){
        ClientData blankclient;
        deleteFile.seekp((accountNumber - 1)*sizeof(ClientData));
        deleteFile.write(reinterpret_cast<char*>(&blankclient), sizeof(ClientData));

        std::cout << "Account #" << accountNumber << " deleted.\n";
    }
    else {
        std::cerr << "Account #" << accountNumber << " is empty.\n";
    }
}

void updateClient(std::fstream& updateFile){
    int accountNumber = getAccountNumber("Enter your account number");

    updateFile.seekg((accountNumber - 1)*sizeof(ClientData));

    ClientData client;
    updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if(client.getAccNumber() != 0){
        outputLine(std::cout, client);

        std::cout << "\nEnter charge (+) or payment (-): ";
        double change;
        std::cin >> change;

        double oldBalance = client.getBalance();
        client.setBalance(oldBalance + change);
        outputLine(std::cout, client);

        updateFile.seekp((accountNumber - 1)*sizeof(ClientData));

        updateFile.write(reinterpret_cast<char *>( &client ),sizeof(ClientData));
    }
    else{
        std::cerr << "Account #" << accountNumber << " has no information." << std::endl;
    }
}
