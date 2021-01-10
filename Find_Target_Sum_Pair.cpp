//Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

// Example:
/*Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6*/

// Below is the approach for solvig the problem in an efficient way using hashmap
// This problem can also be solved using two pointer go to Find_Target_Sum_Pair_In_The_Given_Array in the same parent file location



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Target_Sum_Pair
{
   public:

   static pair<int,int> Find_Target_Sum_Pair(const vector<int>arr, int targetsum)
   {
       unordered_map<int,int> indexmap;
       for(int i=0;i<arr.size();i++)
       {
           int required=targetsum-arr[i];
           if(indexmap.find(required)!=indexmap.end())
           {
              return  make_pair(indexmap[required],i);

           }
           else
           {
               indexmap[arr[i]]=i;
           }
       }
       return make_pair(-1,-1);
   }
};

int main()
{
    auto result=Target_Sum_Pair::Find_Target_Sum_Pair(vector<int>{1,2,3,4,6},6);
    cout<<result.first<<" "<<result.second;
}