/*
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.

Example 1:

Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void swap(vector<int> &nums , int a ,int b)
{
    int temp=nums[a];
    nums[a]=nums[b];
    nums[b]=temp;
}

vector<int> find_the_corrupt_pair(vector<int> &nums)
{
    int i=0;
    while(i<nums.size())
    {
        if(nums[i]!=nums[nums[i]-1])
        {
            swap(nums,i,nums[i]-1);
        }
        
        else
        {
            i++;
        }
    }
    vector<int> result;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=i+1)
        {
            result.push_back(nums[i]);
            result.push_back(i+1);
        }
    }
    return result;
}

int main()
{
    vector<int> input={3,1,2,3,6,4};
    for(auto res: find_the_corrupt_pair(input))

    {
        cout<<res<<" ";
    }
}


/*
Time Complexity : O(n)
Space Complexity: O(1)
*/