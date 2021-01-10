//Brute Force Approach
/*
#include<iostream>
#include<vector>
using namespace std;

class findaveragesofsubarraysizek
{
public:
static vector<double> findAverages(ink K, vector<int>&arr)
{
 vector<double> result(arr.size()-K+1);
 for(int i=0;i<=arr.size()-K+1;i++)
 {
     double sum=0;
     for(int j=i;j<=i+K;j++)
     {
         sum+=arr[j];
     }
     result[i]=sum/K;
 }
 return result;
}

};


int main(int argc,char*argv[])
{
vector<double> result= findaveragesofsubarraysizek::findAverages(5,vector<int>{1,2,3-1,4,5,6,8});
double d;
for(d::result)
{
    cout<<d<<" ";
}
cout<<endl;
}*/

// Stragetic / Efficient Approach
#include<vector>
#include<iostream>
using namespace std;

class Averageofsubarraysofsizek
{
    public:
    static vector<double> findaverage(int K, const vector<int>&arr)
    {
        vector<double> result(arr.size()-K+1);
        double windowsum=0;
        int windowstart=0;
        for(int windowend=0;windowend<arr.size();windowend++)
        {
           windowsum+=arr[windowend];
           if(windowend>=K-1)
           {
              result[windowstart]=windowsum/K;
              windowsum-=arr[windowstart];
              windowstart++;
           }

        }
        return result;
    }

};

int main(int argc, char* argv[]) {
  vector<double> result =
     Averageofsubarraysofsizek ::findaverage(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
  cout << "Averages of subarrays of size K: ";
  for (double d : result) {
    cout << d << " ";
  }
  cout << endl;
}