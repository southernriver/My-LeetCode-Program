#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int climbStair(int n){
    if (n==0)
            return 0;
    if (n==1)
            return 1;
    int fibn=0;
    int f0=1;
    int f1=1;
    for (int i = 2; i <= n; i++){
        fibn=f0+f1;
        f0=f1;
        f1=fibn;
    }
    return fibn;
}
int main(){

    cout<<climbStair(2)<<endl;
    system("pause");
    return 0;
}