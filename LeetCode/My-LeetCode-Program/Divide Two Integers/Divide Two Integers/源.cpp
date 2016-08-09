#include<iostream>
#include<vector>
#include<string>
using namespace std;
int divide0(int dividend, int divisor) {
    long long a = (long long)dividend;
    long long b = (long long)divisor;
    long long result=0;
    while (a>=b)
    {
        long long c=b;
        for (int i = 0; a >= c; c << 1){
            a-=c;
            result++;
            result<<i;
        }
    }

      return result;
}
int main()
{
    cout << divide0(12,12)<<endl;

    system("pause");
    return 0;
}