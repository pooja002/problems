/*
Problem Statement Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.

Example:
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].
*/


/*Naive Approach goes like take the new interval put it into the array of intervals at the last, then sort the intervals according to start time, and merge accordingly

Time Complexity : O(N logn)
Space Compexity : O(1)

Efficient idea would be to make use of sorting property given int he problem statement which reduces time complexity to O(N)

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Interval
{
int s,e;
};

vector<Interval> Mergeintervals(Interval arr[], Interval NewInterval, int n)
{
    if(n==0)
    {
        vector<Interval> NewInterval;
    }
    vector<Interval> MergedIntervals;
    int i=0;
    while(i<n && arr[i].e<NewInterval.s)
    {
      MergedIntervals.push_back(arr[i]);
      i+=1;
    }

    while(i<n && arr[i].s<=NewInterval.e)
    {
        NewInterval.s=min(NewInterval.s,arr[i].s);
        NewInterval.e=max(NewInterval.e,arr[i].e);
        i++;
    }

    MergedIntervals.push_back(NewInterval);

    while(i<n)
    {
        MergedIntervals.push_back(arr[i]);
        i+=1;
    }

   return MergedIntervals;
}

int main()
{
    Interval arr[]={{1,3},{5,7},{8,12}};
    Interval NewInterval={4,10};
    int n=sizeof(arr)/sizeof(arr[0]);
   vector<Interval> result;
    for(auto result : Mergeintervals(arr,NewInterval,n))
    {
        cout<<"["<<result.s<<","<<result.e<<"]";
    }
}