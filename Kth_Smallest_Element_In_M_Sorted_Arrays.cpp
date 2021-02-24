/*
Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be verified from the merged 
list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7], K=3
Output: 7
Explanation: The 3rd smallest number among all the arrays is 7
*/

/* This problem can be solved using two approaches 1. Copy all elements into a single array and apply merge sort. This would Take O(N LogN) time complexity
Second approach is to use a minheap of size M  the time complexity for this apporach is O(K * Log M)

Space complexity #
The space complexity will be O(M) because, at any time, our min-heap will be storing one number from all the ‘M’ input arrays.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


typedef pair<int,pair<int,int>> ppi;

int _find_kth_smallest(vector<vector<int>> arr, int k)
{
  priority_queue<ppi, vector<ppi>, greater<ppi> > minheap; 
  for(int i=0;i<arr.size();i++)
  {
      minheap.push({arr[i][0],{i,0}});
  }
  int count=0;
  int i=0,j=0;

 while(count<k && minheap.empty()==false )
 {
     ppi curr=minheap.top();
     minheap.pop();
      i=curr.second.first;
      j=curr.second.second;

     if(j+1<arr[i].size())
     {
         minheap.push({arr[i][j+1],{i,j+1}});
     }
     count++;
 }
 return arr[i][j];
}


int main()
{
     vector<vector<int> > arr{ { 2, 6, 8 }, 
                              { 3, 6, 7 }, 
                              {1,3,4} }; 

    vector<vector<int> > arr1{ { 5, 8, 9 }, 
                              {1,7} }; 
 
    cout<<_find_kth_smallest(arr,5)<<endl;
    cout<<_find_kth_smallest(arr1,3)<<endl;

}

/* Time Complexity O(K * Log M) */