#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int reverse1(int x)
    {
        int sign=1;
        if (x<0)   sign=-sign,x=-x;
        long int p=0;
        while (x)
        {
            p=x%10+p*10;
            x=x/10;
        }
        if (p>INT_MAX || p<INT_MIN)
            return 0;
        return sign*p;
            







    }
    int itoa(int num)
    {
        string str(10,' ');
        int sign=1;
        if (num>INT_MAX||num<INT_MIN)
                     return 0;
        if (num<0){
            sign=-sign;
            num=-num;
        }
        int i=0;      
        if (sign<0)
            str[i++] =  '-';
        while (num)
        {
            str[i++] = num % 10 + '0';
            num/=10;
        }

        str.erase(str.begin()+i,str.end());
        //reverse(str.begin(), str.end());
        return  atoi(str);
    }
    int atoi(string str)
    {
        int num=0;
        int sign=1;
        int i = 0;
        if (str[i]=='-')
        {
            sign=-sign;  
            i++;
        }
        for (;i<str.length();i++)
        {
            num = 10 * num + str[i] - '0';
            
        }
        return sign*num;
    }
    

};
class Solution1 {
public:
    int myAtoi(string str) {
        int i;
        for (i = 0; isspace(str[i]); i++);
        int sign = 1;

        if (str[i] == '-')   sign = -sign;
        if (str[i] == '-' || str[i] == '+')   i++;
        long int n = 0;
        for (n = 0; isdigit(str[i]); i++)
        {
            n = 10 * n + (str[i] - '0');
        }
        if (n >INT_MAX) return (sign == 1 ? INT_MAX : INT_MIN);
        return sign*n;
    }
};
int main()
{
    Solution s;
 //   cout << s.itoa(1534236469) << endl;
   
    cout<<s.reverse1(-123)<<endl;
    string s1="10h";
    cout<<isdigit(s1[2])<<endl;
    
    
   
    system("pause");
    return 0;
}