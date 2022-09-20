#include "BitTable.h"

const unsigned short int zero = 0;
const unsigned short int one = 1;

void openFiles(ifstream& infile, ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];
    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName); //open input file
    //infile.open("program1_input2.txt");
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);//open out putfile
    //outfile.open("out.txt");
}

unsigned short int**& createBitwiseTable(int rowCount, int columnCount) {
    //create 2d array with rowCount rows and columnCount columns
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

void destroyBitwiseTable(unsigned short int**& bitTable, int rowCount) {

    for (int i = 0; i < rowCount; i++)
    {
        delete[] bitTable[i];
    }
    delete[] bitTable;
};

void printBitwiseTable1(ofstream& output, unsigned short int**& dataTable, int rowCount, int columnCount) {
    //Create top row of table
    char tableRow1[6]{ 'X','Y','&','|','^','~' };

    //print top of table
    for (int i = 0; i < 6; i++) {
        output << setw(8) << tableRow1[i];
    }
    output << endl;
    output << "*******************************************************" << endl;

    //print truth table
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            output << setw(8) << dataTable[i][j];
        }
        output << endl;
    }
};

void initializeBitwiseTable(unsigned short int**& dataTable, int rowCount, int columnCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            dataTable[i][j] = -1;
        }
    }

    return;
};

void populateBitwiseTable2(ifstream& input, int rowcount, int columnCount, unsigned short int**& dataTable) {
    char _operator = ' ';
    unsigned short int temp1 = -1;
    unsigned short int temp2 = -1;
    unsigned short int temp3 = -1;

    for (int i = 0; i < rowcount; i++) {
        input >> _operator;
        //cout << "_operator is: " << _operator << endl;

        switch (_operator)
        {
        case '2':
            input >> temp1;
            dataTable[i][0] = temp1;
            if (temp1 != 0) {
                temp2 = (temp1 - 1);
                //cout << "Temp2 is: " << temp2 << endl;
                if ((temp1 & temp2) == 0) {
                    dataTable[i][9] = 1;
                }
                else {
                    dataTable[i][9] = 0;
                };
            }
            else {
                dataTable[i][9] = 0;
            };
            break;
        case 'E':
            input >> temp1;
            dataTable[i][0] = temp1;
            //if temp1 AND 1 isTrue, then temp1 is not even
            if (temp1 & 1) {
                dataTable[i][7] = 0;
            }
            else {
                dataTable[i][7] = 1;
            }
            break;
        case '>':
            input >> temp1;
            dataTable[i][0] = temp1;
            dataTable[i][3] = (temp1 >> 1);
            break;
        case '<':
            input >> temp1;
            dataTable[i][0] = temp1;
            dataTable[i][4] = (temp1 << 1);
            break;
        case 'S':
            input >> temp1;
            input >> temp2;
            input >> temp3;

            dataTable[i][0] = temp1;
            dataTable[i][1] = temp2;
            dataTable[i][2] = temp3;
            if (temp3 == 1) {
                dataTable[i][5] = (temp1 | (1 << temp2));
            }
            if (temp3 == 0) {
                dataTable[i][5] = (temp1 & ~(1 << temp2));
            }
            break;
        case 'G':
            input >> temp1;
            input >> temp2;
            dataTable[i][0] = temp1;
            dataTable[i][1] = temp2;
            dataTable[i][6] = ((temp1 >> temp2) & 1);
            break;
        case 'C':
            input >> temp1;
            dataTable[i][0] = temp1;
            while (temp1 != 0) {
                temp2 = temp2 + (temp1 & 1);
                temp1 = temp1 >> 1;
            }
            dataTable[i][8] = temp2;
            break;
        default:
            break;
        }
        temp1 = temp2 = temp3 = 0;
    };
};

void printBitwiseTable2(ofstream& output, unsigned short int**& dataTable, int rowCount, int columnCount) {
    //Create top row of table
    string tableRow1[10]{ "X", "P", "V", ">>", "<<", "S", "G", "E", "C", "2" };

    //print top of table
    for (int i = 0; i < columnCount; i++) {
        output << setw(7) << tableRow1[i] << setw(1) << "|";
    }
    output << endl;
    output << "****************************************";
    output << "****************************************";
    output << endl;

    //print table
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            if (dataTable[i][j] == 65535) {
                output << setw(7) << " " << setw(1) << "|";
            }
            else {
                output << setw(7) << dataTable[i][j] << setw(1) << "|";
            }

        }
        output << endl;
    }
};