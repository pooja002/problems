#include<iostream>
using namespace std;

class Happy_Number
{

    public:
    static bool Is_Happy_Number(int num)
    {
        int slow=num, fast=num;
        do
        {
          slow=sumofsquares(slow);
          fast=sumofsquares(sumofsquares(fast));
        } while (slow!=fast);
        return slow==1;
    }

    private:
    static int sumofsquares(int n)
    {
        int sum=0,digit;
        while(n>0)
        {
            digit=n%10;
            sum+=digit*digit;
            n=n/10;
        }
        return sum;
    }
};

int main()
{
    cout<<Happy_Number::Is_Happy_Number(4);
}
