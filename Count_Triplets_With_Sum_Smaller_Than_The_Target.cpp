/*
Problem Statement:
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

Examples:
Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]


Solutioning:

Approach 1: Is to use three nested loops and keep a variable count, to increment whenever arr[i]+arr[j]+arr[k]<target and return count.
Time Complexity- O(n^3)
Space Complexity- O(1)

Approach 2: sort the array, take a variable count and Take one loop, with two pointers left=i+1 and right=n-1 and check if(arr[i]+arr[l]+a[r]<target), count++;
else if(arr[i]+arr[l]+arr[r]>target) do right-- else left++;

Time Complexity: O(n^2)
Space Complexity : O(1)
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int counttriplets(vector<int> &arr, int x)
{
    int count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++)
    {
        int l=i+1,r=arr.size()-1;
        
       while(l<r)
       {

        int sum=arr[i]+arr[l]+arr[r];
        if(sum>=x)
        {
            r--;
        }
        else
        {
            count+=r-l;
            l++;
        }
       }
    }
    return count;
}

int main()
{
    vector<int> arr={-1,0,2,3,3};
    cout<<counttriplets(arr,3);
    return 0;
}