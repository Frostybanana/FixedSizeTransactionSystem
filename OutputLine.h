#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ClientData.h"

void outputLine(std::ostream& output, const ClientData& record){
    output << std::left << std::setw(10) << record.getAccNumber() 
        << std::setw(15) << record.getLName() << std::setw(11) 
        << record.getFName() << std::right << std::setw(10) 
        << std::setprecision(2) << std::fixed << std::showpoint
        << record.getBalance() << std::endl;
}