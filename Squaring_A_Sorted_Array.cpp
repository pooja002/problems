/*Problem Statement:

Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.
 */

/*Example:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
 */



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Squaring_A_Sorted_Array
{
    public:
    static vector<int> Find_Sqaured_Sorted_Array(const vector<int>&arr)
    {
        int n=arr.size();
        vector<int> squares(n);
        
        int left=0;
        int right=n-1;
        int highestsquareindex=n-1;
        while(left<=right)
        {
            int leftsquare=arr[left]*arr[left];
            int rightsquare=arr[right]*arr[right];
            if(leftsquare<rightsquare)
            {
                squares[highestsquareindex--]=rightsquare;
                right--;
            }
            else 
            {
                squares[highestsquareindex--]=leftsquare;
                left++;
            }

        }

        return squares;
    }
};


int main()
{
    vector<int> result=Squaring_A_Sorted_Array::Find_Sqaured_Sorted_Array(vector<int>{-2,-1,0,2,3});
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;

}