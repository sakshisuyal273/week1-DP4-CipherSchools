//word search

#include<iostream>
using namespace std;

bool isSafe(vector<vector<char>> &board, vector<vector<bool>> & visited, int index, int x, int y, const int &R, const int &C) {
    return (x>=0 && x<R && y>=0 && y<C && !visited[x][y] && board[x][y]==word[index]);
}

int xMoves[] = {0, 0, 1, -1};
int yMoves[] = {1, -1, 0, 0};

bool exist(vector<vector<char>> &board, vector<vector<bool>> & visited, int index, int x, int y, const int &R, const int &C) {
     if(index >= word.size()) {
        return true;
     }
     else{
        visited[x][y] = true;

        for(int i=0; i<4; i++) {
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if(isSafe()) {
                if(exist(board, visited, word, index+1, R, C)) {
                    return true;
                }
            }
        }
     }
}

bool exist(vector<vector<char>> & board, string word) {
    if(word == "") {
        return true;
    }
    int R = board.size();
    if(R==0) {
        return false;
    }
    int C= board[0].size();

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for(int i = 0 ; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(board[i][j]==word[0] && exist(board, visited, 1, 1, j , R, C)) {
               return true;
            }
        }
    }
    return false;

}

int main() {

}


//power(x.n)

#include<iostream>
using namespace std;

double findP(double x, long long n) {
        // Base Case
        if (n == 0) {
            return 1;
        }
 
        if (n == 1) {
            return x;
        }
 
        // Recursive step
        // double answer = x * findP(x, n - 1);
 
        double answer = findP(x, n / 2);
        answer = answer * answer; // power became n here
        if (n % 2 == 1) {
            answer = answer * x;
        }
 
        // What to return
        return answer;
    }
 
    double myPow(double x, int n) {
        if (n >= 0) return findP(x, n);

        
        return 1.0 / findP(x, abs(n));
    }




//power set

#include<iostream>
using namespace std;

 vector<vector<int>>ans;
    void backtrack(vector<int>&arr,int start,vector<int>&temp){
        ans.push_back(temp);
        for(int i=start;i<arr.size();i++){
            temp.push_back(arr[i]);
            backtrack(arr,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp;
        backtrack(arr,0,temp);
        return ans;
    }

    int main() {
        
    }