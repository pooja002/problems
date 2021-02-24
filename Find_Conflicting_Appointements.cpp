/*
Problem Statement:
Given a list of appointments, find all the conflicting appointments.
Example:
Appointments: [[4,5], [2,3], [3,6], [5,7], [7,8]]
Output: 
[4,5] and [3,6] conflict. 
[3,6] and [5,7] conflict.


In the naive approach for each interval we check if there is any other overlapping interval in the list and cout that accordingly.(2 loops i &j)
This approach would take O(N^2) time.

CAUTION: THIS PROBLEM IS SOLVED USING NAIVE APPROACH PLEASE OPTIMIZE IT USING INVERT TREE, ONCE YOU START TO UNDERSTAND TREES ! PLEASE PLEASE PLEASE! DO IT FOR FAANG BUD! 

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Interval
{
  int s,e;

};



bool compare(Interval a, Interval b)
{
    return a.s<b.s;
}


void Return_Conflicts(Interval arr[],int n)
{
    sort(arr,arr+n,compare);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
      if(arr[i].e>arr[j].s)
      {
         cout<<"["<<arr[i].s<<","<<arr[i].e<<"]"<<"&"<<"["<<arr[j].s<<","<<arr[j].e<<"]"<<"Conflict";
      }
    }
}

int main()
{
    Interval arr[]={{4,5},{2,3},{3,6},{5,7},{7,8}};
    int n=sizeof(arr)/sizeof(arr[0]);
    Return_Conflicts(arr,n);

}