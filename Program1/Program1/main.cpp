/****************************************************
 *  Author:           Jered Stevens
 *  
 *  Course:         Discrete Structures
 *                  MWF 10AM
 *                  Stringfellow
 *
 *  File:           main.cpp
 * 
 *  Description:    This program creates data tables
 *                  of bitwise functions. It reads
 *                  input from a file of the users
 *                  choice and prints the results to
 *                  a seperate file of users choice.
 *  
 *  Date:           09/17/22               
 ***************************************************/

#include <fstream>
#include "BitTable.h"
using namespace std;

int main() {
    //Declare and initailize local variables
    ifstream input;
    ofstream output;
    char choice = ' ';
    int numberOperations = 0;
    int rowCount = 0;
    int columnCount = 0;

    //Main loop
    while (choice != 'n') {
        //Open in and out files, set variables
        openFiles(input, output);
        numberOperations = 0;
        input >> numberOperations;
        rowCount = numberOperations + 4;
        columnCount = 6;

        //Print header
        output << "     Jered Stevens" << endl;
        output << "     Discrete structures - Stringfellow" << endl;
        output << "     Program 1: Bitwise Operations" << endl;
        output << "     Date: 09/17/22" << endl << endl;

        //Create dataTable
        unsigned short int** dataTable = createBitwiseTable(rowCount, columnCount);

        //initialize dataTable with -1
        initializeBitwiseTable(dataTable, rowCount, columnCount);

        //Fill dataTable with values from input file
        populateBitwiseTable1(input, rowCount, columnCount, dataTable);

        //Print resulting dataTable
        printBitwiseTable1(output, dataTable, rowCount, columnCount);

        //Free Memory
        destroyBitwiseTable(dataTable, rowCount);
        output << endl << endl;

        //Read in next number of operations
        input >> numberOperations;
        rowCount = numberOperations;
        columnCount = 10;

        //Create second dataTable
        unsigned short int** dataTable2 = createBitwiseTable(rowCount, columnCount);

        //Initialize with -1
        initializeBitwiseTable(dataTable2, rowCount, columnCount);

        //Fill table with values 
        populateBitwiseTable2(input, rowCount, columnCount, dataTable2);

        //Print resulting dataTable
        printBitwiseTable2(output, dataTable2, rowCount, columnCount);

        //Free memory
        destroyBitwiseTable(dataTable2, rowCount);

        //Close in and outfiles, prompt to continue
        input.close();
        output.close();
        cout << "Would you like to run another file? (y/n)" << endl;
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            choice == 'n';
        }

    }



    return 0;
}

