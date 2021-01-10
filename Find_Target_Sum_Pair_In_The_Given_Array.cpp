//Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

// Example:
/*Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6*/

//Below is the approach to solve the problem in an efficient wy using two pointers
// Another way is using hashmap , got to Find_Target_Sum_Pair in the same parent file location to see this approach
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Target_Sum_Pair
{
 public:
 static pair<int,int> Find_Target_Sum_Pair(const vector<int> arr, const int target)
 {
     int start_pointer=0;
     int end_pointer=arr.size()-1;
     vector<int> result;
     while(start_pointer<end_pointer)
     {
         if(arr[start_pointer]+arr[end_pointer]==target)
         {
            return make_pair(start_pointer,end_pointer);
         }
         else if(arr[start_pointer]+arr[end_pointer]>target)
         {
             end_pointer-=1;
         }
         else 
         {
             start_pointer+=1;
         }
     }
     return make_pair(-1,-1);
 }
};
int main()
{
auto result=Target_Sum_Pair::Find_Target_Sum_Pair(vector<int>{1,2,3,4,6},6);
cout<<result.first<<" "<<result.second;
}