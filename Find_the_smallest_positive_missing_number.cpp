/*
Given an unsorted array containing numbers, find the smallest missing positive number in it.
Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is 3

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(vector<int> &arr , int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


int smallest_positive_missing_number(vector<int> &nums)
{
    int i=0;
    while(i<nums.size())
    {
        if(nums[i]<=nums.size() && nums[i]>0 && nums[i]!=nums[nums[i]-1])
        {
            swap(nums,i,nums[i]-1);
        }
        else
        {
            i++;
        }
    }
    for(int i=0;i<=nums.size();i++)
    {
        if(nums[i]!=i+1)
        {
            return i+1;
        }
    }
    return -1;
}
int main()
{
    vector<int> input={1,2,3,4,5};
    cout<<smallest_positive_missing_number(input);
}


/*
Time complexity is O(N)
Space Compelxity is O(1)
*/