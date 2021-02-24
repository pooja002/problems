/*
Problem Statement: Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.


Example:
Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
Output: [2, 3], [5, 6], [7, 7]
Explanation: The output list contains the common intervals between the two lists.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


struct Interval
{
    int s,e;
};


vector<Interval> Make_Intersection(Interval arr1[], Interval arr2[],int n1, int n2 )
{
    vector<Interval> Intersection;

    int i=0,j=0;

    while(i<n1 && j<n2)
    {
        if((arr1[i].s>=arr2[j].s && arr1[i].s<=arr2[j].e )||
           (arr2[j].s>=arr1[i].s && arr2[j].s<=arr1[i].e))
        {
            Intersection.push_back({max(arr1[i].s,arr2[j].s),min(arr1[i].e,arr2[j].e)});
        }

        if(arr1[i].e<arr2[j].e)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return Intersection;
}



int main()
{
    Interval arr1[]={{1,3},{5,7},{9,12}};
    Interval arr2[]={{5,10}};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    vector<Interval> result;
    result=Make_Intersection(arr1,arr2,n1,n2);
    for(auto interval: result )
    {
        cout<<"["<<interval.s<<","<<interval.e<<"]";
    }
}

/*
Time Complexity Taken by this algorithm is O(N+M) where and N & M are total number of intervals in the input arrays respectively
Space Complexity : If space needed for the result list is ignored , the algorithm runs in O(1) , constant space.
*/