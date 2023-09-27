#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h"
#include "OutputLine.h"
#include "CreateTextFile.h"
#include "BinaryFileModification.h"

using namespace std;

int main(){
    std::fstream inOutCredit("credit.dat", std::ios::out | std::ios::in | std::ios::binary);

    if(!inOutCredit){
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    ClientData blankClient;
    for(int i = 0; i < 100; i++){
        inOutCredit.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
    }

    int choice;

    cout << "\nEnter your choice" << endl
        << "1 - store a formatted text file of accounts" << endl
        << " called \"print.txt\" for printing" << endl
        << "2 - update an account" << endl
        << "3 - add a new account" << endl
        << "4 - delete an account" << endl
        << "5 - end program\n? ";

    cin >> choice;

    while(choice != 5){
        switch(choice){
            case 1:
                printTextFile(inOutCredit);
                break;
            case 2:
                updateClient(inOutCredit);
                break;
            case 3:
                addClient(inOutCredit);
                break;
            case 4:
                deleteClient(inOutCredit);
            default:
                cerr << "Invalid " << endl;
                break;
        }
        inOutCredit.clear();
        cout << "\nEnter your choice:";
        cin >> choice;
    }
    inOutCredit.close();
}
