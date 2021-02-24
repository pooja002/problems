/*
Problem Statement:
Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.
Example 1:
Appointments: [[1,4], [2,5], [7,9]]
Output: false
Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.



*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Interval
{
    int start,end;

};
bool compare(Interval a, Interval b)
{
    return a.start<b.start;
}

bool Conflicting_Intervals(Interval arr[], int n)
{

    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
    {
        if(arr[i-1].end>arr[i].start)
        {
            return false;
        }
    }
    return true;

}

int main()
{
    Interval arr[]={{1,4},{2,5},{7,9}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Conflicting_Intervals(arr,n);
}


/*

Time complexity taken for this algorithm is O(Nlogn), O(N) for iterating through the loop and O(NlogN) for sorting
Space Complexity taken for this algorithm is O(N) 
*/