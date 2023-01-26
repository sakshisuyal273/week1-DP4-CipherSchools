#include<iostream>
using namespace strd;
 
void generateParenthesis(string strSoFar, vector<string> &result, int open, int close) {
     if(open>close) {
        return;
     }
     if(open== 0 && close == 0){
        result.push_back(strSoFar);
        return;
     }

     strSoFar.push_back('(');
     generateParenthesis(strSoFar, result, open-1, close);
     strSoFar.pop_back();

     strSoFar.push_back(')');
     generateParenthesis(strSoFar, result, open, close-1);
     strSoFar.pop_back();
}

vector<string> generateParenthesis(const int n) {
    vector<string> result;
    int open = n, close = n;
    string strSoFar = "";
    generateParenthesis(strSoFar, result, open, close);
    return result;
}



//ques2 ph. keypad

#include<iostream>
using namespace std;
  map<char,string> data;

    void fillData(){
        data['2'] = "abc";
        data['3'] = "def";
        data['4'] = "ghi";
        data['5'] = "jkl";
        data['6'] = "mno";
        data['7'] = "pqrs";
        data['8'] = "tuv";
        data['9'] = "wxyz";
    }

    void helper(vector<string>&res, string temp, int i, string digits, int j){
        if(temp.length() == digits.length() && temp != "") {
            res.push_back(temp);
            return;
        }
        if(i >= digits.length()) return;

        for(int idx = j; idx < data[digits[i]].length(); idx++){
            temp.push_back(data[digits[i]][idx]);
            helper(res,temp,i+1,digits,j);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        fillData();
        vector<string> res;
        string temp = "";

        helper(res,temp,0,digits,0);

        return res;
    }

int main() [

]


//ques3

#include<iostream>
using namespace std;
    vector<int> slice(int ind, vector<int>& nums) {
        vector<int> slicedVector;
        for(int i = 0; i < nums.size(); i++) {
            if (i == ind) continue;
            slicedVector.push_back(nums[i]);
        }
 
        return slicedVector;
    }
 
    vector<vector<int>> findPerm(vector<int> nums) {
        // Base case
        if (nums.size() == 1) {
            return {nums};
        }
 
        // Recursive step
        vector<vector<int>> allPerms;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> remainingElements = slice(i, nums);
            vector<vector<int>> perms = findPerm(remainingElements);
 
            for(int j = 0; j < perms.size(); j++) {
                perms[j].push_back(nums[i]);
            }

            for(int j = 0; j < perms.size(); j++) {
                allPerms.push_back(perms[j]);
            }
        }
 
        return allPerms;
    }
 
    vector<vector<int>> permute(vector<int>& nums) {
        return findPerm(nums);
    }



//ques4

#include<iostream>
using namespace std;

void find(string s,int i,set<string>&ans)
    {
        if(i==s.size())
        {
            ans.insert(s);
            return ;
        }
        
        for(int k=i;k<s.size();k++)
        {
            swap(s[i],s[k]);
            find(s,i+1,ans);
            swap(s[i],s[k]);
        }
    }
		vector<string>find_permutation(string s)
		{
		     set<string>ans;
             find(s,0,ans);
             vector<string>v;
             v.assign(ans.begin(),ans.end());
             return v;
		}

        int main() {

        }


//ques5
//grid

#include<iostream>
using namespace std;

#define POSSIBLMOVES 4
int xMoves[] = {0,0,1,-1};
int yMoves[] = {1,-1,0,0};

bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y. const int &R, const int &C ) {
    return ((x >= 0 && x < R && y >=0 && y< C) && !visited[x][y] && mat[x][y]==1 );
}

bool ratInMaze(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y. const int &R, const int &C ) {

    if(x==R-1 && y==C-1) {
        visited[x][y] = true;
        return true;
    }

    if(isSafe(mat, visited, x, y, R, C)) {
        visited[x][y] = true;
        for(int i=0; i<POSSIBL_MOVES; i++) 
        {
            int nextX = x+ xMoves[i];
            int nextY = y + yMoves[i];
            if(ratInMaze(mat, visited, nextX, nextY,  R, C)) {
                return true;
            }
        }

        visited[x][y] = false;
    }

}

bool ratInMaze(vector<vector<int>> &mat) {
    int R = mat.size();
    if(R == 0) {
        return true;
    }
    int C = mat[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    return ratInMaze(mat, visited, 0, 0, R, C);
}

int main() {

}
