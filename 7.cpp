//bitonic array

#include <iostream>
using namespace std;


int ascendingBinarySearch(int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


int descendingBinarySearch(int arr[], int low,int high, int key)
						
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


int findBitonicPoint(int arr[], int n,int l, int r)
					
{
	int mid;
	int bitonicPoint = 0;
	mid = (r + l) / 2;
	if (arr[mid] > arr[mid - 1]
		&& arr[mid] > arr[mid + 1])
	{
		return mid;
	}

	else if (arr[mid] > arr[mid - 1]
			&& arr[mid] < arr[mid + 1])
	{
		bitonicPoint = findBitonicPoint(arr, n, mid, r);
	}

	else if (arr[mid] < arr[mid - 1]
			&& arr[mid] > arr[mid + 1])
	{
		bitonicPoint = findBitonicPoint(arr, n, l, mid);
	}
	return bitonicPoint;
}


int searchBitonic(int arr[], int n,int key, int index)
{
				
	if (key > arr[index])
		return -1;

	else if (key == arr[index])
		return index;

	else {
		int temp= ascendingBinarySearch(arr,0, index - 1,key);
			
									
									
		if (temp != -1) {
			return temp;
		}

		
		return descendingBinarySearch(arr,index + 1,n - 1,key);
									
									
	}
}


int main()
{
	int arr[] = { -8, 1, 2, 3, 4, 5, -2, -3 };
	int key = 1;
	int n, l, r;
	n = sizeof(arr) / sizeof(arr[0]);
	l = 0;
	r = n - 1;
	int index;

	
	index = findBitonicPoint(arr, n, l, r);

	int x = searchBitonic(arr, n, key, index);

	if (x == -1)
		cout << "Element Not Found" << endl;
	else
		cout << "Element Found at index " << x << endl;

	return 0;
}



//3sum

#include<iostream>
using namespacestd;

vector<vector<int>> triplets(vector<int> &nums) {
    if(nums.size() <= 2) {
        return {};
    }

    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i=0; i < nums.size()-2; i++) {
        int curr1 = nums[i];
        int start = i+1, end= nums.size()-1;

        while(start < end) {
            int mid = start + (end-start)/2;
            if(curr1 + nums[start] + nums[end] == 0) {
                result.push_back({curr1, nums[start], nums[end]});
                start++; end--;
            

                while(start < end && nums[start-1]== nums[start]) {
                   start++;
                }
 
                while(start < end && nums[end] == nums[end+1]) {
                  end--;
                }
            }
            else if (curr1 + nums[start] + nums[end] < 0) {
                start++;
            }
            else {
                end--;
            }

        }

        while(i < nums.size()-1 && nums[i] == nums[i+1]) {
            i++;
        }
    }
    return result;
}