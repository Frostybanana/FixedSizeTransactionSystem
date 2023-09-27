#include "ClientData.h"
#include <string>
using namespace std;

ClientData::ClientData(int accountValue, const string& firstName,
    const string& lastName, double credit)
        :accNumber(accountValue), balance(credit)
{
    setFName(firstName);
    setLName(lastName);
}

void ClientData::setAccNumber(int number){
    accNumber = number;
}

void ClientData::setFName(const string& first){
    int length = first.length();
    length = (length < 10 ? length : 9);
    first.copy(fName, length);
    fName[length] = '\0';
}

void ClientData::setLName(const string& last){
    int length = last.length();
    length = (length < 15 ? length : 14);
    last.copy(lName, length);
    lName[length] = '\0';
}

void ClientData::setBalance(double number){
    balance = number;
}

int ClientData::getAccNumber() const {
    return accNumber;
}

string ClientData::getFName() const {
    return fName;
}

string ClientData::getLName() const {
    return lName;
}

double ClientData::getBalance() const {
    return balance;
}