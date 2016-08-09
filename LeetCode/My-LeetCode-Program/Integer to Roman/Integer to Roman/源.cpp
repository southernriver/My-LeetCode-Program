#include<iostream>
#include<string>
using namespace std;
//整形转化成罗马数字
/*************************
1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

1000~3000: {"M", "MM", "MMM"}.
*******************/
string intToRoman(int num) {
    string Ge[10]  = { "","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    string Shi[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string Bai[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    string Qian[4] = { "","M", "MM", "MMM" };
    int nums[5];
    memset(nums,0,sizeof(nums));       //将各位置零

    int i=1;   
    while (num)
    {
     
        nums[i++]=num%10;
        num=num/10;
    }
    return  Qian[nums[4]] + Bai[nums[3]] + Shi[nums[2]] + Ge[nums[1]] + "";
}
/*********
罗马数字转换成整形
***********/
int trans(const char c){
    switch (c)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        default:   return 0;
    }
}
int romanToInt(string s) {
    int result=0;
    for (int i = 0; i < s.size(); i++){
        if (i>0 && trans(s[i])>trans(s[i-1]))
            result += trans(s[i]) - 2*trans(s[i-1]);  //在没有扫面到之前已经叠加了一次，需要减去
        else
        {
            result += trans(s[i]);
        }
    }
    return result;
}
int main(){
    cout << intToRoman(234)<<endl;
    cout << romanToInt("CCXXXIV")<<endl;


    system("pause");
    return 0;
}