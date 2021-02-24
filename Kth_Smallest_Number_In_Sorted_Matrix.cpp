/*
Given an N * NN∗N matrix where each row and column is sorted in ascending order, find the Kth smallest element in the matrix.

Example 1:

Input: Matrix=[
    [2, 6, 8], 
    [3, 7, 10],
    [5, 8, 11]
  ], 
  K=5
Output: 7
Explanation: The 5th smallest number in the matrix is 7.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Find
{
public:

static int findKthSmallest(const vector<vector<int>> &mat,const int k)
{
    int n=mat.size();
    int start=mat[0][0], end=mat[n-1][n-1];

    while(start<end)
    {
       int mid=start+(end-start)/2;
        pair<int,int> smalllargepair={mat[0][0],mat[n-1][n-1]};
       int count=countlessequal(mat,mid,smalllargepair);
  
       if(count==k)
       {
           return smalllargepair.first;
       }

       if(count<k)
       {
           start=smalllargepair.second; 
       }
       else
       {
           end=smalllargepair.first;
       }
    }
   return start;
}

private:
static int countlessequal(vector<vector<int>> mat, int mid, pair<int,int> &smallargepair)
{
    int count=0;
    int n=mat.size();
    int row=n-1;
    int col=0;
    while(row>=0 &&col<n)
    {
       if(mid<mat[row][col])
       {
           smallargepair.second=min(smallargepair.second,mat[row][col]);
           row--;
       }
       else 
       {
           smallargepair.first=max(smallargepair.first, mat[row][col]);
           count+=row+1;
           col++;
       }
    }
    return count;
}
};
int main()
{
    vector<vector<int>> matrix2={vector<int> {2,6,8}, vector<int> {3,7,10}, vector<int> {5,8,11}};
    int result=Find::findKthSmallest(matrix2,5);
    cout<<result;
}


