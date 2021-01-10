/* 
Problem Statment: Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.

Example:
Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.


Approaches:
Naive-Sort the array Approach is two use three nested loops,i,j,k and binary search the remaining element(target-(arr[i]+arr[j]+arr[k]))
tore the quadraples in a datastructure and retrieve non-duplicate quadraples only.

Time Complexity:
 O(N^3Logn+NLogn)
 N^3 for three nested loops and traversing, NLogn for binary search, Nlog N for sorting.
 Space Complexity:
 O(Size of hash set)

 Approach 2:

 Use two pointer approach, take two nested loops i,j and two pointers left and right, for taregt-sum(arr[i]+arr[j]) check if target-(arr[left]+arr[right]) exists if target-(arr[left]>arr[right]) move towards left by decrementing right pointer, else increment left pointer
 Skip over the duplicate elements and store the quadraples in a hashmap.
 Time Complexity: O(Nlogn+O(N^3))= O(N^3) (  Nlog N for sorting and N^3 for two nested loops and while loop (nested with i,j))
 Space Complexity: O(N) for sorting


*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Quadraples
{
    public:
     static vector<vector<int>> searchQuadraplets(vector<int> &arr, int target)
     {
         sort(arr.begin(),arr.end());
         vector<vector<int>> quadraples;
         for(int i=0;i<arr.size()-3;i++)
         {
             if(i>0 && arr[i]==arr[i-1])
             {
                continue;
             }

             for(int j=i+1;j<arr.size()-2;j++)
             {
                 if(j>i+1 && arr[j]==arr[j-1])
                 {
                     continue;
                 }

                 searchpairs(arr, target, i, j, quadraples);
             }
         }
         return quadraples;
     }


     private:
     static void searchpairs(const vector<int> &arr,int target,int first,int second,vector<vector<int>> &quadraples)
     {

         int left=second+1;
         int right=arr.size()-1;
         while(left<right)
         {
             int sum=arr[first]+arr[second]+arr[left]+arr[right];
             if(sum==target)
             {
                 quadraples.push_back({arr[first],arr[second],arr[left],arr[right]});
                 left++;
                 right--;
                while(left<right && arr[left]==arr[left-1])
                {
                  left++; // skip same element to avoid duplicates
                }
                while(left<right && arr[right]==arr[right+1])
                {
                    right--; // skip same element to avoid duplicates
                }
             }
             else if(sum>target)
             {
                 right--; // We need lesser sum
             }
             else
             {
                 left++; // We need bigger sum
             }
         }
     }
};


int main()
{
    vector<int> vec={4,1,2,-1,1,-3};
    auto result=Quadraples::searchQuadraplets(vec,1);
    for( auto vec: result)
    {
        cout<<"[";
        for(auto num: vec)
        {
            cout<<num<<",";
        }
        cout<<"]";
    }
    cout<<endl;
}

