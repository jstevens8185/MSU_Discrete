#include <fstream>
#include "BitTable.h"
using namespace std;

int main() {
    ifstream input;
    ofstream output;
    char choice = ' ';
    
    while (choice != 'n') {
        openFiles(input, output);

        //print Header
        output << "     Jered Stevens" << endl;
        output << "     Program 1: Bitwise Operations" << endl;
        output << "     Date: 09/17/22" << endl << endl;



        //read how many operations there will be.
        int numberOperations = 0;
        input >> numberOperations;
        int rowCount = numberOperations + 4;
        int columnCount = 6;



        unsigned short int** dataTable = createBitwiseTable(rowCount, columnCount);
        initializeBitwiseTable(dataTable, rowCount, columnCount);
        populateBitwiseTable1(input, rowCount, columnCount, dataTable);
        printBitwiseTable1(output, dataTable, rowCount, columnCount);
        destroyBitwiseTable(dataTable, rowCount);
        output << endl << endl;

        input >> numberOperations;
        rowCount = numberOperations;
        columnCount = 10;

        unsigned short int** dataTable2 = createBitwiseTable(rowCount, columnCount);
        initializeBitwiseTable(dataTable2, rowCount, columnCount);
        populateBitwiseTable2(input, rowCount, columnCount, dataTable2);
        printBitwiseTable2(output, dataTable2, rowCount, columnCount);
        destroyBitwiseTable(dataTable2, rowCount);

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

