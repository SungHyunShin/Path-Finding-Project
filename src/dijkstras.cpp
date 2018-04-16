// dijsktras.cpp
#include <iostream>
#include <map>
using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

    // Check if next item is the end of file
    while(cin.peek() != EOF){
        // get number of unique tiles used
        string TILES_N_STRING;
        getline(cin, TILES_N_STRING);
        int TILES_N = stoi(TILES_N_STRING);

        // get weights of each tile and insert into map
        map<char, int>  weightsMap;
        for(int i = 0; i < TILES_N; i++){
            char tile, weight;
            cin >> tile;
            cin >> weight;
            pair<char, int> weightPair = make_pair(tile, (int)(weight - '0'));
            weightsMap.insert(weightPair);
        }

        // get rows and cols of table
        string rows_str, cols_str;
        cin >> rows_str;
        cin >> cols_str;
        int rows, cols;
        rows = stoi(rows_str);
        cols = stoi(cols_str);

        // make table
        char **tileTable = new char*[rows];
        for(int i = 0; i < rows; i++){
            tileTable[i] = new char[cols];
        }

        // fill table

    }

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
