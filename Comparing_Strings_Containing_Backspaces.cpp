/* Problem Statement:
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

Examples:
Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.


Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
*/


/*Approaches:
Approach 1. is it use a stack or a dqueue , for stack you will iterate from the end of the string if you encounter '#' you skip the insertion otherwise proceed with insertion for each string, lastly compare the stacks if both are qual return true else return false.
For dequeue, traverse the the string, if any character except '#' is found then, push it back to dequeue, if the character '#' is found then pop character from the dequeu, finally pop all the elements from front of dequeue to form a new string.

Time Complexity O(N)- for traversing through the string.
Space Complexity O(N)- to store N elements of the string at max; 


Approach 2 : Using two pointer approach

Time complexity O(M+N) where ‘M’ and ‘N’ are the lengths of the two input strings respectively.
Space Complexity O(1)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class CompareStrings
{
   public:
   static bool  FindComparisionOfStrings(const string &str1, const string &str2)
   {
     int index1=str1.length()-1, index2=str2.length()-1;
     while(index1>=0 || index2>=0)
     {

       int i1=getNextValidCharacterIndex(str1,index1);
       int i2=getNextValidCharacterIndex(str2,index2);

       if(i1<0 && i2<0)
       {
           return true; // Reached the end of both the strings
       }
       if(i1<0 || i2<0)
       {
           return false;  // Reached the end of one of the strings
       }
       if(str1[i1]!=str2[i2]) // Check if characters are equal
       {
           return false; 
       }
         index1=i1-1;
         index2=i2-1;
     }
     return true;
   }
   
    
private:
   static int getNextValidCharacterIndex(const string &str, int index)
   {
       int backspacecount=0;
      while(index>=0)
      {
        
        if(str[index]=='#') // Found a backspace character
        {
            backspacecount++;
        }
        else if(backspacecount>0) // Found a non backspace character
        {
            backspacecount--; 
        }
        else 
        {
            break; // skip a backspace or a valid character
        }
        index--;
      }
      return index;
   }

};


int main()
{
    cout<<CompareStrings::FindComparisionOfStrings("xywrrp","xywrrmu#p");
}