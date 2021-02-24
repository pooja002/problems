#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*1. write a structure to sort according to sum values for heap

2. Data Type pushed into heap is pair<int,int>

*/

class Largest_Sums
{
    public:
    struct SumCompare
    {
     bool operator()(const pair<int,int> &x, const pair<int,int> &y)
     {
         return x.first+s.second>y.first+y.second;
     }
    };


    vector<pair<int,int>> Find_K_Largest(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, SumCompare()> minheap;
        for(int i=0;i<nums1.size() && i<k ;i++)
        {
            for(int j=0; j<nums2.size() && j<k ; j++)
            {
               if(minheap.size()<k)
               {
                   minheap.push_back({nums1[i],nums2[j]});
                   push_heap(minheap.begin(),minheap.end(),SumCompare());
               }
               else{
                   if(nums1[i]+nums2[j] < minheap.front().first+minheap.front().second)
                   {
                       break;
                   }

                   else
                   {
                       pop_heap(minheap.begin(),minheap.end(),SumCompare());
                       minheap.pop_back();
                       minheap.push_back(make_pair(nums1[i],nums2[j]));
                       push_heap(minheap.begin(),minheap.end(), SumCompare());
                   }

               }
            }
        }
        return minheap;
    }

};


int main()
{
    auto result=Largest_Sums::Find_K_Largest({{9,8,2},{6,3,1},3});
    for(auto pair: result)
    {
        cout<<pair.first<<pair.second;
    }
}



