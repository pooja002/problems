/* Problem Statement:
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example:
Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero. */

/*Solutioning : 
Approach-1
One way of solving this problem is , using three concurrent loops i,j,k and checking a[i]+a[j]+a[k]==0.
This takes  Time Complexity of order O(n^3) , Space complexity of O(1) since no extra space is being used.

Approach-2 could be iterating through the array with a loop, then creating a hashmap and checking if there is a pair with sum -arr[i] in the hashmap, using the second loop j
this takes Time complexity of order O(n^2), Space complexity of O(N) for using hashmap.

Approach-3 The third approach would be, This method uses sorting to arrive at the correct result and is solved in O(n^2) time
For every element check for a pair whose sum is equal to the negative of that element 
Time complexity- O(n^2)
Auxilary Complexity- O(1)
*/

/* Approach-2

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void findTriplets(int arr[],int n)
{
    bool found =false;
    for(int i=0;i<n-1;i++)
    {
        unordered_set<int> s;
        for(int j=i+1;j<n;j++)
        {
            x=-(arr[i]+ arr[j]);
            if(s.find(x)!=s.end())
            {
                cout<<x<<" "<<arr[i]<<arr[j];
                found=true;
            }
            else
            {
                s.insert(arr[j]);
            }
        }
    }
    if(found==false)
    {
        cout<<"No triplet found";
    }
}


int main()
{
int arr[]={0,-1,2,-3,1};
int n=sizeof(arr)/sizeof(arr[0]);
findTriplets(arr,n);
return 0;
}
*/


/* Approach 3 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findtriplets(int arr[],int n)
{
    bool found=false;
   
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
    {
       int l=i+1, r=n-1;
       int x=arr[i];
       while(l<r)
       {
           if(x+arr[l]+arr[r]==0)
           {
               cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r];
               l++;
               r--;
               found=true;
           }

           else if(arr[i]+arr[l]+arr[r]<0)
           {
               l++;
           }
           else 
           {
               r--;
           }

       }

    }
    
    if(found==false)
    {
        cout<<"No triplets exist";
    }

}


int main()
{
    int arr[]={-3, 0, 1, 2, -1, 1, -2};
    int n=sizeof(arr)/sizeof(arr[0]);
    findtriplets(arr,n);
    return 0;
}