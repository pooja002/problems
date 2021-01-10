/*
Problem Statement: Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Examples:
Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted

Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted


Approach 1 : to find all possible subarrays and check for sorted array! This method is tedious as it requires three nested loops and O(N^3) time.


Approach 2: is to use two pointer approach left and right , as we iterate from left to right mark the area were sorting order breaks , 
and do the same from traversing right to left , so that the whole subarray that needs to be sorted is identified. Now, we need to make sure that minimumof the identified subarray is not less than the elements that are sorted in the beggining,similarly maximum of the identified subaarray should not be greater than the first element from sorted right half of the array
Taking care of just this mistake would bring down time complexity from O(N^3) to O(N), space complexity is however zero for both the above approaches(1&2).

Approach 3 : is to take the unsorted array and sort it and store it . Then we would check for the first and last encounters where the sorting condition fails in the original unsorted array. This approach is similar to 2nd  one but uses an extra space O(N) and Time Complexity with O(N^2)
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Minimum_Window
{
  public:
  static int Find_Minimum_Window (const vector<int> &arr)
  {
     int low=0,high=arr.size()-1;
     //find the first number out of sorting order fromt the beggining
     while(low<arr.size()-1 && arr[low]<=arr[low+1])
     {
         low++;
     }
     
     if(low==arr.size()-1) // if the array is sorted
     {
         return 0;
     }
     //find the first numebr out of sorting order from the end
     while(high>0 && arr[high]>=arr[high-1])
     {
         high--;
     }

     //Find maximum and minimum of the subarray

     int subarraymax=numeric_limits<int>::min(); 
     int subarraymin=numeric_limits<int>::max();
     for(int k=low;k<=high;k++)
     {
         subarraymax=max(subarraymax,arr[k]);
         subarraymin=min(subarraymin,arr[k]);
     }
     // extend the subarray to include any numbe rwhich is bigger than the sminimum of the subarray
     while(low>0 && arr[low-1]>subarraymin)
     {
         low--;
     }

     //extend the subarray to include any number which is smaller than the maximum of the subarray
     while(high<arr.size()-1 && arr[high+1]<subarraymax)
     {
         high++;
     }
     return (high-low+1);
  }
};


int main()
{
    cout<<Minimum_Window::Find_Minimum_Window(vector<int>{1,2,5,3,7,10,9,12})<<endl;
}