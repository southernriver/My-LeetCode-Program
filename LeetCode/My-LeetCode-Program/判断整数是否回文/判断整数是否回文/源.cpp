#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrom(int x)
{
    if (x<0)
            return false;
    char ch[10];
    int i=0,j=0;
    int num=x;
    while (num)
    {
        ch[i++]=num%10+'0';
        num/=10;
    }
    ch[i] = '\0';
    
    for (j = 0; j <strlen(ch) / 2; j++)
    {
        if (ch[j]!=ch[strlen(ch)-j-1])
                return false;
    }
    return true;
}
bool isPalindrom1(int x)
{
    if (x<0)
        return false;   
    
        




        
    return true;
}
int reverseInteger(int x){
    int r=0;
    while (x)
    {     
        r = r * 10 + x % 10;
        x/=10;
    }
    return r;
}

int main()
{
    int num=0;
    cout<<isPalindrom(num)<<endl;


    cout<<reverseInteger(123)<<endl;
    

    system("pause");
    return 0;
}