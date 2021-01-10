#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LongestSubarraysWithOnesAfterReplacement
{
    public:
    static int FindLongestSubarrayWithOnesAfterReplacement(int k, const vector<int> &arr)
    {
        int maxcount=0,windowstart=0,maxlength=0;
        for(int windowend=0;windowend<arr.size();windowend++)
        {
           if(arr[windowend]==1)
           {
               maxcount++;
           }
           if(windowend-windowstart+1-maxcount>k)
           {
               if(arr[windowstart]==1)
               {
                   maxcount--;
               }
               windowstart++;
           }
           maxlength=max(maxlength,windowend-windowstart+1);
        }
        return maxlength;

    }
};


int main()
{
  int result=LongestSubarraysWithOnesAfterReplacement::FindLongestSubarrayWithOnesAfterReplacement(2,vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1});
  cout<<result;
}