//unique path tree

#include<iostream>
using namespace std;

int path(int i,int j,int n,int m,int &c,int cnt,vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==-1 or grid[i][j]==3)
            return 0;
        
        
        if(grid[i][j]==2)
        {
        
            if(cnt-1 == c) return 1;
            return 0;
        }
        
        grid[i][j]=3;                                          
        
        // all possible paths
        int up = path(i-1,j,n,m,c,cnt+1,grid);
        int down = path(i+1,j,n,m,c,cnt+1,grid);
        int left = path(i,j-1,n,m,c,cnt+1,grid);
        int right = path(i,j+1,n,m,c,cnt+1,grid);
    
        grid[i][j]=0;                                          
        
        return up+down+left+right;                             
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int st,en;
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(grid[i][j]==1)
                {
                    st=i;
                    en=j;
                }
                
                
                if(grid[i][j]==0)
                {
                    c++;
                }
            }
        }
        return path(st,en,n,m,c,0,grid);
    }




//N queens

#include<iostream>
using namespace std;

bool isSafe(vector<vector<bool>> &Chess, int x, int y, const int &N) {
    for(int i=x; i>=0; i--) {
        if(Chess[i][y]) {
            return false;
        }
    }
    for(int i=x, j=y ; i>=0 && j>=0; i--, j-- ) {
        if(Chess[i][y]) {
            return false;
        }
    }
    return true;
}
bool NQueen(vector<vector<bool>> &chess, int y, const int &N)  {
     if(y==N){
        return true;
     }

     for(int x=0; x<N; x++) {
        if(isSafe(Chess, x, y, N)) {
            Chess[x][y] = true;
            if(NQueen(Chess, y+1, N)) {
                return true;
            }

            Chess[x][y] = false;
        }
     }
     return false;
}
