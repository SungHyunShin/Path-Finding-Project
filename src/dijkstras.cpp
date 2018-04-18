// dijsktras.cpp
#include <iostream>
#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Compare{
    public:
        bool operator()(tuple<int, pair<int, int>, pair<int, 
        int>>n1, tuple<int, pair<int, int>, pair<int, int>>n2){
            return get<0>(n1) > get<0>(n2);
        }
};

// Dijkstra's Algorithm
void dijkstras(int **graph, pair<int, int> runnerStart, pair<int, int> runnerEnd,int cols, int rows){
    priority_queue<tuple<int, pair<int, int>, pair<int, int> >, vector< tuple< int, pair<int, int>, pair<int, int> > >, Compare> frontier;

    vector<pair<int,int>> ans;

    set< pair<int,int> > marked;
    frontier.push(make_tuple(graph[runnerStart.first][runnerStart.second], runnerStart, make_pair(-1,-1)));

    int x,total;
    total = 0; 
    pair<int, int> v, u;

    while(!frontier.empty()){
        x = get<0>(frontier.top());
        v = get<1>(frontier.top());
        u = get<2>(frontier.top());
        frontier.pop();

        if(marked.find(v) != marked.end()){
            continue;
        }
        cout << "GOING TO " << v.first << " " << v.second << endl;
        
        total += x;
        ans.push_back(v);
        
        marked.insert(v);
        
        if(v == runnerEnd){
            break;
        }

        if(v.first-1 >= 0){
            cout << "ABOVE " << v.first-1 << " " << v.second << " " << graph[v.first-1][v.second] << endl;
            frontier.push(make_tuple(graph[v.first-1][v.second],make_pair(v.first-1,v.second),v));
        }
        if(v.first+1 != rows){
            cout << "BELOW " << v.first+1 << " " << v.second << " " << graph[v.first+1][v.second] << endl;
            frontier.push(make_tuple(graph[v.first+1][v.second],make_pair(v.first+1,v.second),v));
        }
        if(v.second-1 >= 0){
            cout << "LEFT " << v.first << " " << v.second-1 << " " << graph[v.first][v.second-1] << endl;
            frontier.push(make_tuple(graph[v.first][v.second-1],make_pair(v.first,v.second-1),v));
        }
        if(v.second+1 != cols){
            cout << "RIGHT " << v.first << " " << v.second+1 << " " << graph[v.first][v.second+1] << endl;
            frontier.push(make_tuple(graph[v.first][v.second+1],make_pair(v.first,v.second+1),v));
        }
    }
    /*cout << total << endl;

    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << it->first << " " << it->second << endl;
    }*/

}

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
        int **tileTable = new int*[rows];
        for(int i = 0; i < rows; i++){
            tileTable[i] = new int[cols];
        }

        // fill table
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                char tmp;
                cin >> tmp;
                tileTable[i][j] = weightsMap[tmp];
            }
        }

        // parse runner start and end
        pair<int,int> RUNNER_START;
        pair<int,int> RUNNER_END;

        cin >> RUNNER_START.first >> RUNNER_START.second;
        cin >> RUNNER_END.first >> RUNNER_END.second;
        cin.ignore(256,'\n');
        dijkstras(tileTable, RUNNER_START, RUNNER_END, cols, rows);

        for(int i = 0; i < rows; i++){
            delete[] tileTable[i];
        }
        delete[] tileTable;
    }

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
