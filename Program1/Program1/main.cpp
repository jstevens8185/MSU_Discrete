#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

const unsigned short int zero = 0;
const unsigned short int one = 1;

void makeTopOfTable1();
void openFiles(ifstream& infile, ofstream& outfile);
unsigned short int**& createBitwiseTable1(int rowCount, int columnCount);
void populateBitwiseTable1(ifstream& input, int rowcount, int columnCount, unsigned short int**& dataTable);

int main() {

    
    //print Header
    cout << "     Jered Stevens" << endl;
    cout << "     Program 1: Bitwise Operations" << endl;
    cout << "     Date: 09/17/22" << endl << endl;
    
    ifstream input;
    ofstream output;
    
    openFiles(input, output);

    //read how many operations there will be.
    int numberOps = 0;
    input >> numberOps;
    int rowCount = numberOps + 4;
    int columnCount = 6;

    //print top of table
    makeTopOfTable1();
    cout << endl;

    unsigned short int** dataTable = createBitwiseTable1(rowCount, columnCount);
    populateBitwiseTable1(input, rowCount, columnCount, dataTable);

    //print truth table
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            cout << setw(8) << dataTable[i][j];
        }
        cout << endl;
    }

    input.close();
    output.close();

    return 0;
}




void makeTopOfTable1() {
    //Initialize first row of table
    char tableRow1[6]{ 'X','Y','&','|','^','~' };
    //print top row of table
    for (int i = 0; i < 6; i++) {
        cout << setw(8) << tableRow1[i];
    }

    return;
};

void openFiles(ifstream& infile, ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];
    //cout << "Enter the input file name: ";
    //cin >> inFileName;
    //infile.open(inFileName); //open input file
    infile.open("program1.txt");
    //cout << "Enter the output file name: ";
    //cin >> outFileName;
    //outfile.open(outFileName);//open out putfile
    outfile.open("out.txt");
}

unsigned short int**& createBitwiseTable1(int rowCount, int columnCount) {
    //create 2d array with numberOps+4 rows and 6 columns
    unsigned short int** dataTable = new unsigned short int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        dataTable[i] = new unsigned short int[columnCount];
    }

    return dataTable;
};

void populateBitwiseTable1(ifstream& input, int rowCount, int columnCount, unsigned short int**& dataTable) {

    unsigned short int temp1 = 0;
    unsigned short int temp2 = 0;

    //fill first section of truth table
    dataTable[0][0] = dataTable[0][1] = dataTable[1][0] = dataTable[2][1] = zero;
    dataTable[1][1] = dataTable[2][0] = dataTable[3][0] = dataTable[3][1] = one;



    ////fill first 2 columns with input values
    cout << "*******************************************************" << endl;
    for (int i = 4; i < rowCount; i++) {
        input >> temp1;
        input >> temp2;
        dataTable[i][0] = temp1;
        dataTable[i][1] = temp2;
        //cout << setw(8) << dataTable[i][0];
        //cout << setw(8) << dataTable[i][1] << endl;
    }

    //assign truth table ops
    for (int i = 0; i < rowCount; i++) {
        dataTable[i][2] = dataTable[i][0] & dataTable[i][1];
        dataTable[i][3] = dataTable[i][0] | dataTable[i][1];
        dataTable[i][4] = dataTable[i][0] ^ dataTable[i][1];
        if (i > 3) {
            dataTable[i][5] = ~dataTable[i][0];
        }
        else {
            // AND with 1 to get right-most bit
            dataTable[i][5] = ~dataTable[i][0] & 1;
        }
    }

};