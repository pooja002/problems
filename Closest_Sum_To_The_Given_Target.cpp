/* Problem Statement:
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Examples:
Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.


Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.


Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.
*/


/* Solutioning-

Approach 1: The naive approach is to explore all the subsets of size 3 and keep a track of the difference between X and the sum of this subset. Then return the subset whose difference between its sum and X is minimum.

Algorithm:

Create three nested loop with counter i, j and k respectively.
First loop will start from start to end, second loop will run from i+1 to end, third loop will run from j+1 to end.
Check if the difference of sum of ith, jth and kth element with given sum is less than the current minimum or not. Update the current minimum
Print the closest sum. Time Complexity O(n^3) , Space Complexity O(1).

CODE:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int printclosestsum(vector<int> &arr,int x)
{
    closest_sum=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            for(int k=j+1;j<arr.size();k++)
            {
                if(abs(x-closest_sum)>abs(x-arr[i]+arr[j]+arr[k]))
                {
                    closest_sum=arr[i]+arr[j]+arr[k];
                }
            }
        }
    }
    return closest_sum;
}


Efficient Approach:
By Sorting the array the efficiency of the algorithm can be improved. This efficient approach uses the two-pointer technique. Traverse the array and fix the first element of the triplet. Now use the Two Pointers algorithm to find the closest number to x – array[i]. Update the closest sum. Two pointers algorithm take linear time so it is better than a nested loop.

Algorithm: 

Sort the given array.
Loop over the array and fix the first element of the possible triplet, arr[i].
Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
If the sum is smaller than the sum we need to get to, we increase the first pointer.
Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
Update the closest sum found so far.

Complexity:
Time: O(n^2)
Space: O(1)
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int findclosestsum(vector<int> &arr, int x)
{
    sort(arr.begin(),arr.end());
     int closestsum=INT_MAX;
     for(int i=0;i<arr.size()-2;i++)
     {
         int l=i+1, r=arr.size()-1;
         while(l<r)
         {
             int sum=arr[i]+arr[l]+arr[r];
             if(abs(1LL*x-closestsum)>abs(1LL*x-sum))
             {
                 closestsum=sum;
             }
             else if(sum>x)
             {
                 r--;
             }
             else
             {
                 l++;
             }
         }
     }
     return closestsum;
}
int main()
{
    vector<int> arr={-2, 0, 1, 2};
    int target=2;
    cout<<findclosestsum(arr,target);
    return 0;
}
