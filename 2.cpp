//Merge Sort (Ques 2)

#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &nums, int start, int end, int target) {
   if(start>end) {
    return -1;
   }
   else if(start==end) {
    return (nums[start] == target ? start : -1);
   }
   else {
       int mid = start + (end-start)/2;
       if(nums[mid] < target) {
         return firstOccurrence(nums, mid+1, end, target);
       }
       else if(nums[mid]> target) {
        return firstOccurrence(nums, start, mid-1, target);
       }
       else {
        if(mid == 0 && (mid>=1 && nums[mid-1]< nums[mid])) {
            return mid;
        }
        return firstOccurrence(nums, start, mid-1, target);
       }
   }
}

int lastOccurrence(vector<int> &nums, int start, int end, int target) {
    
    if(start>end) {
    return -1;
   }
   else if(start==end) {
    return (nums[start] == target ? start : -1);
   }
   else {
       int mid = start + (end-start)/2;
       if(nums[mid] < target) {
         return firstOccurrence(nums, mid+1, end, target);
       }
       else if(nums[mid]> target) {
        return firstOccurrence(nums, start, mid-1, target);
       }
       else {
        if((mid == end) && (mid+1 <= end && nums[mid-1]< nums[mid])) {
            return mid;
        }
        return lastOccurrence(nums, mid+1, end, target);
       }
   }
}


void firstAndLastOccurrence(vector<int> &nums, int target) {
    int first = firstOccurrence(nums, 0, nums.size()-1, target);
    int last = lastOccurrence(nums, first , nums.size()-1, target);
    cout<<first<<" "<<last;
}

int main() {

    int target = 5;

    vector<int> nums = {1,2,3,5,5,5,6};

    firstAndLastOccurrence(nums,target);

}


//H.W Iterative solution

#include<bits/stdc++.h>
using namespace std;

int firstOcurrence(vector<int> &nums, int target) {
    int l=0; int h=nums.size()-1;
    while(l<=h) {
        int mid= l+(h-l)/2;
        if(nums[mid]<target) {
            l=mid+1;
        }
        else if(target<nums[mid]){
            h=mid-1;
        }
        else {
            if(mid==0) return mid;
            else if(nums[mid-1] != target) return mid;
            else {
                h=mid-1;
            }
        }
        
    }
    return -1;
}

int lastOcurrence(vector<int> &nums, int target) {
    int l=0; int h=nums.size()-1;
    while(l<=h) {
        int mid = l+(h-l)/2;
        if(target > nums[mid]) l=mid+1;
        else if( target < nums[mid]) h=mid-1;
        else {
            if(mid == nums.size()-1) return mid;
            else if(nums[mid+1] != target) return mid;
            else{
                l=mid+1;
            }
        }
    }
    return -1;
}


    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1) {
            if(target == nums[0]){
                return {0,0};
            }
            else {
                return {-1,-1};
            }
        }
        return {firstOcurrence(nums, target) , lastOcurrence(nums, target)};
    }

int main() {

    int target = 5;

    vector<int> nums = {1,2,3,5,5,5,6};

    vector<int> ans = searchRange(nums,target);

    for(auto it:ans) {
        cout<<it<<" ";
    }
}