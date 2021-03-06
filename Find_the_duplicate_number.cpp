/*
Problem Statement: We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.

Input: [1, 4, 4, 3, 2]
Output: 4
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void swap(vector<int> &nums, int i,int j)
{
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}

int find_the_duplicate_numebr(vector<int> &nums )
{
    int i=0;
    while(i<nums.size())
    {
        if(nums[i]!=i+1)
        {
            if(nums[i]!=nums[nums[i]-1])
            {
                swap(nums,i,nums[i]-1);
            }
            else
            {
                return nums[i];
            }
            
        }
        else{
            i++;
        }

    }
    return -1;

}



int main()
{
    vector<int> input={1,1,2};
    cout<<find_the_duplicate_numebr(input);
}