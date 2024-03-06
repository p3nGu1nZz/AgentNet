// AgentNetTerm.cpp : Defines the entry point for the application.
//

#include "AgentNetTerm.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string sourcePath = "./path/to/llama2/sources"; // Default path to Llama2 sources
    ifstream sourceCheck(sourcePath);

    if (!sourceCheck.good()) {
        // If the sources are not found in the default path, ask the user for the location
        cout << "Llama2 sources not found. Please enter the path to the Llama2 sources on your machine: ";
        cin >> sourcePath;

        // You might want to perform another check to ensure the new path is correct
        ifstream newSourceCheck(sourcePath);
        if (!newSourceCheck.good()) {
            cerr << "Error: The path provided is not valid." << endl;
            return 1; // Exit with an error code
        }
    }

    // Proceed with the rest of your program logic using the valid sourcePath
    cout << "Llama2 sources found. Continuing with the program..." << endl;

    // ... rest of your code ...

    return 0;
}
