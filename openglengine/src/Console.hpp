#include <stdio.h>
#include <iostream>
#include "Concatenate.hpp"

using namespace std;

class Console{
    public:
        static void WriteLine(const char* line){cout << "[INFO] " << line << endl;}
        static void WriteError(const char* line){cout << "[ERROR] " << line << endl;}
        static void WriteWarning(const char* line){cout << "[WARNING] " << line << endl;}
};