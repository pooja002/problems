/* PROBLEM STATEMENT--->
Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the new length of the array.*/

//EXAMPLE----->

/*Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9]. */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Remove_Duplicates
{
    public:

    static int Find_Duplicates_Remove(const vector<int> arr)
    {
        int start_pointer=0;
        int next_pointer=1;
        int length=arr.size();
        if(length==0)
        {
            return 0;
        }
        while(start_pointer<next_pointer && next_pointer<arr.size())
        {
        if(arr[start_pointer]==arr[next_pointer])
        {
              length-=1;
              next_pointer+=1;
        }
        else
        {
            start_pointer=next_pointer;
            next_pointer+=1;
        }
        }
        return length;
    }
};


int main()
{
    int result=Remove_Duplicates::Find_Duplicates_Remove( vector<int> {});
    cout<<result;
}

//Another Approach to this problem goes like---->
/* 
static int remove(vector<int> &arr)
{
    int nextNonDuplicate=1;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[nextNonDuplicate-1]!=arr[i])
        {
            arr[nextNonDuplicate]=arr[i];
            nextNonDuplicate++;
        }

    }
    return nextNonDuplicate;
}



*/