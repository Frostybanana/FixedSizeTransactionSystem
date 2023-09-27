#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ClientData.h"
#include "OutputLine.h"
void printTextFile(std::fstream& readBinaryFile){
    std::ofstream printFile("print.txt", std::ios::out);

    if(!printFile){
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    printFile << std::left << std::setw(10) << "Account" << std::setw(16) << "Last Name" 
            << std::setw(11) << "First Name" << std::right << std::setw(10) << "Balance" << std::endl;

    readBinaryFile.seekg(0);

    ClientData client;
    readBinaryFile.read(reinterpret_cast<char *> (&client), sizeof(ClientData));

    while(!readBinaryFile.eof()){
        if(client.getAccNumber() != 0)
            outputLine(printFile, client);
        }
        readBinaryFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));   

}