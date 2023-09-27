#pragma once

#include <string>

class ClientData {
    private:
        int accNumber;
        char fName[10];
        char lName[15];
        double balance;
    public:
        ClientData(int = 0, const std::string& = "", const std::string& = "", double balance = 0.0);
        
        void setAccNumber(int number);
        void setFName(const std::string& first);
        void setLName(const std::string& last);
        void setBalance(double number);
        
        int getAccNumber() const;
        std::string getFName() const;
        std::string getLName() const;
        double getBalance() const;
};