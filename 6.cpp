//sorting problem given array [0,1,2] no. of times like [1,2,1,1,1,0,0,0,2] return after sorting

#include<iostream>
using namespace std;

void sort012(vector<int> &nums) {
    int p0=0 , p1=0. p2=nums.size()-1;
    while(p1<=p2) {
        switch(nums[p1]) {
            case 0:
                swap(nums[p0], nums[p1]);
                p0++;
                p1++;
                break;
            case 1:
                p1++;
                break;
            case 2:
                swap(nums[p1], nums[p2]);
                p2--;
                break;     
        }
    }
}

int main() {

}


//ques2
//73 set matrix zero

#include<iostream>
using namespace std;
 void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
       vector<pair<int,int>> mp;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(matrix[i][j]==0) mp.push_back(make_pair(i,j));

        for(auto i:mp){
            int j=0;
            while(j<cols){
                matrix[i.first][j]=0;
                j++;
            }
            j=0;
              while(j<rows){
                matrix[j][i.second]=0;
                j++;
            }
        }
    }




//ques3
//search a 2D matrix ||

#include<iostream>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start=0;
        int end=row*col-1;
        int mid = start + (end-start)/2;
        while(start<=end) {
            int ele = matrix[mid/col][mid%col];
            if(ele==target) {
                return true;
            }
            if(ele > target) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid=start+(end-start)/2;
        }
        return 0;
    }



//ques4
//seach in sorted rotated matrix

#include<iostream>
using namespace std;
int search(vector<int>& nums, int target) {
        int l=0; int h=nums.size()-1;
     
        while(l<=h) {
               int mid=l+(h-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[l] <= nums[mid]) {
                if(target>=nums[l] && target < nums[mid]) {
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else {
                if(nums[mid]<target && target<=nums[h]) {
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }

    int main() {

    }