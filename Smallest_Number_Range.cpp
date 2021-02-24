/*
Given ‘M’ sorted arrays, find the smallest range that includes at least one number from each of the ‘M’ lists.

Example 1:
Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
Output: [4, 7]
Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
Example 2:

Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
Output: [9, 12]
Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,pair<int,int>> ppi;

pair<int,int> Find_smallest_Range(vector<vector<int>> &lists)
{
   
   priority_queue<ppi,vector<ppi>,greater<ppi>> minheap;

   int Range_Start=0;
   int Range_End= numeric_limits<int>::max();
   int MaxCurrentNum=numeric_limits<int>::min();


   for(int i=0;i<lists.size();i++)
   {
       if(!lists[i].empty())
       {
           minheap.push({lists[i][0],{i,0}});
           MaxCurrentNum=max(MaxCurrentNum,lists[i][0]);
       }
   }

   while(minheap.size()==lists.size())
   {

    ppi node=minheap.top();
    minheap.pop();

    if(Range_End-Range_Start > MaxCurrentNum-node.first)
     {
      
      Range_Start=node.first;
      Range_End=MaxCurrentNum;
     }
    node.second.second++;

    if(lists[node.second.first].size()>node.second.second)
    {
        node.first=lists[node.second.first][node.second.second];
        minheap.push(node);
        MaxCurrentNum=max(MaxCurrentNum,node.first);
    }
   }
    return make_pair(Range_Start,Range_End);
}


int main()
{
    vector<vector<int>> lists={{1,5,8},{4,12},{7,8,10}};
    auto result=Find_smallest_Range(lists);
    cout<<result.first<<endl;
    cout<<result.second<<endl;
}


/* Time Complexity : O(N * Log M)
we’ll be going through all the elements of all the arrays and will 
remove/add one element in the heap in each step, the time complexity
 of the above algorithm will be O(N*logM)O(N∗logM) where ‘N’ is the total 
 number of elements in all the ‘M’ input arrays.


Space Complexity: The space complexity will be O(M)
because, at any time, our min-heap will be store one number from all the ‘M’ input arrays.
*/