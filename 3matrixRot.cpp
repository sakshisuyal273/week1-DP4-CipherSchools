#include<iostream>
using namespace std;

void rotate(vector<vector<int>>& matrix) 
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(auto &it : matrix)
        {
            reverse(it.begin(),it.end());
        }
        
    }

    int main() {
       
    }