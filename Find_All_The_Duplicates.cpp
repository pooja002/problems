/* We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array has some duplicates, find all the duplicate numbers without using any extra space.

Example 1:

Input: [3, 4, 4, 5, 5]
Output: [4, 5]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j)
{
int temp;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}

vector<int> find_all_duplicates(vector<int> &nums)
{
    int i=0;
    vector<int> result;
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
    vector<int> duplicates;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=i+1)
        {
            duplicates.push_back(nums[i]);
        }
    }
    return duplicates;
}


int main()
{
    vector<int> input={1,2,3,3,2,4};
    for(auto res:find_all_duplicates(input))
    {
        cout<<res<<",";
    }
}