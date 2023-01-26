#include<iostream>
using namespace std;

void generateSet(vector<vector<int> > &result, vector<int> &setSoFar, const vector<int> &vec, int index) {
    if(index>= vec.size()) {
        result.push_back(setSoFar);
    }
    else {
        setSoFar.push_back(vec[index]);
        generateSet(result, setSoFar, vec, index+1);
        setSoFar.pop_back();
        generateSet(result, setSoFar, vec, index+1);
    }
}

vector<vector<int>> generateSet(vector<int> &vec) {
    if(vec.size() == 0) {
        return {};
    }
    vector<vector<int>> result;
    vector<int> setSofFar;
    generateSet(result, setSoFar, vec, 0);
    return result;
}

int main() {

}


//sudoko

#define Size 9
bool isEmpty(vector<vector<int>> &sudoko, int &row, int &col) {
    for(row=0; row< Size; row++) {
        for(col=0; col<Size; col++) {
            if(sudoko[row][col]==0) {
                return true;
            }
        }
    }
    return false;
}

bool usedInRow(vector<vector<int>> &sudoko, const int row, int fill) {
    for(int j=0; j<Size; j++) {
        if(sudoko[i][col] == fill) {
            return true;
        }
    }
    return false;
}

bool usedInCol(vector<vector<int>> &sudoko, const int col, int fill) 
{
    for(int i=0; i<Size; i++) {
        if(sudoko[i][col]==fill) {
            return true;
        }
    }
    return false;
}

bool usedInBox(vector<vector<int>> &sudoko, const int row, const int col, int fill) {
     for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(sudoko[i+row][j+col] == fill) {
                return true;
            }
        }
     }
     return false;
}


bool isSafe(vector<vector<int>> &sudoko, const int row, const int col, int fill) {
    return (!usedInRow(sudoko, row, col, fill) &&  !usedInCol(sudoko, col, fill) && !usedInBox(sudoko, row, col))
}

bool solveSudoko(vector<vector<int>> &sudoko) {
    int row, col;
    if(!isEmpty(grid, row, col)) {
        return true;
    }

    for(int i=1; i<= 9; i++) {
        if(isSafe(sudoko, row, col, i)) {
            sudoko[row][col] = i;
            if(solveSudoko(sudoko)) {
                return true;
            }
            sudoko[row][col] = 0;
        }
    }
}




//knight tour


#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[], int yMove[]);


int isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);
}


void printSolution(int sol[N][N])
{
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << " " << setw(2) << sol[x][y] << " ";
		cout << endl;
	}
}


int solveKT()
{
	int sol[N][N];

	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	sol[0][0] = 0;

	
	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	else
		printSolution(sol);

	return 1;
}


int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[8], int yMove[8])
{
	int k, next_x, next_y;
	if (movei == N * N)
		return 1;

	
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol,
							xMove, yMove)
				== 1)
				return 1;
			else
				
			
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}


int main()
{
	
	solveKT();
	return 0;
}




