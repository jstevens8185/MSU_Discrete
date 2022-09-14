#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;





int main() {
    //Initialize first row of table
    char tableRow1[6]{'X','Y','&','|','^','~'};
    
   

    //fill first 4 rows
    //read 2 values into table. perform operations and
    //  save them into next 4 spaces.
    //move to next row. Repeat

    //read how many ops there will be. int numberOps
    int numberOps = 0;
    cout << "How many operations? ";
    cin >> numberOps;

    //create 2d array with numberOps+4 rows and 6 columns
    unsigned short int** dataTable = new unsigned short int*[6];
    for (int i = 0; i < 6; i++) {
        dataTable[i] = new unsigned short int [numberOps + 4];
    }

    unsigned short int zero = 0;
    unsigned short int one = 1;
 
    //fill first section of truth table
    dataTable[0][0] = dataTable[0][1] = dataTable[1][0] = dataTable[2][1] = zero;
    dataTable[1][1] = dataTable[2][0] = dataTable[3][0] = dataTable[3][1] = one;

    //print top row of table
    for (int i = 0; i < 6; i++) {
        cout << setw(8) << tableRow1[i];
    }
    cout << endl;



    //assign truth table ops
    for (int i = 0; i < 4; i++) {
         dataTable[i][2] = dataTable[i][0] & dataTable[i][1];
         dataTable[i][3] = dataTable[i][0] | dataTable[i][1];
         dataTable[i][4] = dataTable[i][0] ^ dataTable[i][1];
         // AND with 1 to get right-most bit
         dataTable[i][5] = ~dataTable[i][0] & 1;

    }

    //print truth table
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cout << setw(8) << dataTable[i][j];
        }
        cout << endl;
    }
}