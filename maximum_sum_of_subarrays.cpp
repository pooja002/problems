//Brute Force Approach
/*
#include<iostream>
#include<vector>
using namespace std;

class findmaxsumofsubarrayofsizek
{
    public:
    static int findmaxofsubarrays(int K, const vector<int> &arr)
    {
        
        int max=arr[0];
        for(int i=0;i<arr.size();i++)
        {
            int sum=0;
            
            for(int j=i;j<i+K;j++)
            {
                sum+=arr[j];
            }
            
            if(sum>max)
            {
                max=sum;
            }


        }
        return max;
     
    }
};


int main(int argc, char* argv[])
{
    int result=
    findmaxsumofsubarrayofsizek::findmaxofsubarrays(3,vector<int> {2,1,5,1,3,2});
    cout<<result;
    
}
*/

//Efficient Algorithm (Sliding Window)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class findmaxsumofsubarraysofsizek
{
    public:
    static int findmaxofsubarrays(int K, const vector<int> &arr)
    {
       int maxsum=0;
        int windowstart=0;
        int windowsum=0;
        for(int windowend=0;windowend<arr.size();windowend++)
        {
            windowsum+=arr[windowend];
            
            if(windowend>=K-1)
            {
                if(windowsum>maxsum)
            {
                maxsum=windowsum;
            }
                windowsum-=arr[windowstart];
                windowstart++;
            }
            
        }
        return maxsum;
    }
};


int main(int argc, char* argv[])
{
 int result=findmaxsumofsubarraysofsizek::findmaxofsubarrays(2,vector<int>{2,3,4,1,5});
 cout<<result;
}