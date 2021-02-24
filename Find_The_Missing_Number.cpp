/* Problem Statement :

We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]
Output: 2


Naive Approach is to find the sum of n natural numbers and calculate sum of the elements of the array. Spit out the number missing by subtracting nsum-arraysum
Time Compelxity Taken by this problem is O(n);
Space Complexity is O(1);
*/
/*
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int find_missing_number(vector<int> &nums)
{
    int n=nums.size();
    int sum=(n*(n+1))/2;
    int array_sum=0;
    for(int i=0;i<nums.size();i++)
    {
        array_sum+=nums[i];
    }

    return sum-array_sum;

}

int main()
{
    vector<int> nums={8,3,5,2,4,6,0,1};
    cout<<find_missing_number(nums);
}
*/
/*Another efficient way to solve this problem is using cyclic sort, just put the numbers in their correct locatioin in the array, after doing so iterate through the entire array and return the index whose number is not matching with the index */



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


int find_the_missing_number(vector<int> &nums)
{
    int i=0;
    while(i<nums.size())
    {
        if(nums[i]<nums.size() && nums[i]!=nums[nums[i]])
        {
            swap(nums,i,nums[i]);
        }
        else
        {
            i++;
        }
    }
    for(int i=0;i<nums.size();i++)
    {
        if(i!=nums[i])
        {
            return i;
        }
    }
    return nums.size();
}

int main()
{
    vector<int> nums={8,3,5,2,4,6,0,1};
    cout<<find_the_missing_number(nums);
}


/*Time complexity for this solution is O(N)
Space Complexity is O(1)*/