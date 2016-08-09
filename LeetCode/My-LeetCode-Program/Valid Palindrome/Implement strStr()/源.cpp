#include<iostream>
#include<string>
#include<functional>
#include<numeric>
#include<algorithm>
using namespace std;

//string to integer
int atoi_1(const char *str){
    int n=0;
    int x=0;
    while (str[n]!='\0')
    {
        if (!isdigit(str[n]))   return -1;  
        x = x*10 + str[n] - '0';
       n++;
    }
    ////一共有n位数
    //int *num = new int[n];
    //int i=0;
    //while (str[i]!='\0')
    //{
    //    num[i] = str[i]-'0';i++;
    //}
    //int result=0;
    //for (int j = 0; j < n; j++){
    //   result += num[j] * pow(10,n-j-1);
    //}
    return x;
}
string addBinary(string a, string b){
    int i = a.size()-1;
    int j = b.size()-1;
    int len = max(i,j);
    string str;
    int sum=0;
    int carry=0;
    for (; min(i, j)>= 0; i--, j--){
        int a0 = a[i] - '0';
        int b0 = b[j] - '0';
        sum = (carry+(a0+b0))%2;
        carry=(a0+b0+carry)/2;
        str.insert(str.begin(),sum + '0');
    }
    while (j>=0)
    {
        str.insert(str.begin(), b[j--]);
    }
    while (i>=0)
    {
        str.insert(str.begin(), b[i--]);
    }
    if (carry>0)
        str[len]=carry;
    return str;
}
int main(){
    //char *str = "021340";
    //cout << atoi_1(str)<<endl;
    
    string result = addBinary("0100", "011");
    cout<<result<<endl;


    system("pause");
    return 0;
}