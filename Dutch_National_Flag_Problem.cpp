/*
Problem Statement-Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.


Examples
Input: [1, 0, 2, 1, 0]
Output: [0 0 1 1 2]

Input: [2, 2, 0, 1, 2, 0]
Output: [0 0 1 2 2 2 ]
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> solution(vector<int>&arr)
{
   int low=0,high=arr.size()-1;

   for(int i=0;i<=high;)
   {
       if(arr[i]==0)
       {
           swap(arr[i],arr[low]);
           i++;
           low++;
       }
       else if(arr[i]==1)
       {
           i++;
       }
       else
       {
           swap(arr[i],arr[high]);
           high--;
       }
   }
   return arr;
}

int main()
{
  vector<int> arr={0,1,0,2,1,2};
  vector<int> result=solution(arr);
  for(int i=0;i<result.size();i++)
  {
      cout<<result[i]<<" ";
  }
  return 0;

}