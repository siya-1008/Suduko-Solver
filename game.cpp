#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#define N 9
using namespace std;

bool isSafe(int i, int j, int grid[N][N], int val) {
    for(int x = 0; x < N; x++) {
        if(grid[i][x] == val || grid[x][j] == val ||
           grid[3 * (i / 3) + (x / 3)][3 * (j / 3) + (x % 3)] == val) {
            return false;
        }
    }
    return true;
}
    bool solveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 0) {
                for(int val = 1; val <= N; val++) {
                    if(isSafe(i, j, grid, val)) {
                        grid[i][j] = val;
                        if(solveSudoku(grid)) {
                            return true;
                        }
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
             
            
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
                if((j+1)%3==0)
                {
                    cout<<"|";
                }
                
            }
            cout<<"\n";
            if((i+1)%3==0)
            {
                cout<<"---------------------"<<"\n";
            }
            
        }
    }
    void removeDigits(int grid[N][N], int numRemove)
     {
    srand(time(0));
    while (numRemove > 0) {
        int i = rand() % N;
        int j = rand() % N;
        if (grid[i][j] != 0) {
            grid[i][j] = 0;
            numRemove--;
        }
    }
}
    void generateSudoku(int grid[N][N], int numRemove) {
    // Generate a fully solved Sudoku grid
    solveSudoku(grid);
    // Remove digits to create the puzzle
    removeDigits(grid, numRemove);
}
    int main()
    {
        cout<<"Enter values: ";
        int grid[N][N]={0};
        int x;
        cin>>x;
        int numRemove = x; 
        cout<<"\n";
       generateSudoku(grid, numRemove);
    printGrid(grid);
    cout<<"\n";
    cout<<"****************************"<<"\n";
    cout<<"****************************"<<"\n";
    cout<<"****************************"<<"\n";
    solveSudoku(grid);
    //printGrid(grid);
    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }

    //return 0;
    return 0;
    }