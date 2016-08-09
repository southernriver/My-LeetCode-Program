#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    string multiply(string num1, string num2) {
     //   size_t n = num1.size()>num2.size() ? num1.size() : num2.size();
        string str,str2;
        vector<string> svec;
        int carry=0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end()); 
        for (int i = 0; i < num2.size(); i++)
        {
            string str1;          
            for (int m = 0; m<i; m++)
                str1.push_back('0');
            const int a = num2[i] - '0';
            for (int j=0;j<num1.size();j++)
            {             
                const int b = num1[j] - '0';
                const int value=(a*b+carry)%10;
                carry = (a*b+carry)/10;
                str1.insert(str1.begin(),value+'0');
            }        
            if (carry>0)
               str1.insert(str1.begin(),carry);            
            svec.push_back(str1); 
             
        }
        for (auto c:svec)   
                cout<<c<<endl;
        return "hello";
    }
};
int main()
{
    string num1 = "123";
    string num2 = "14";
    Solution s;
    cout << s.multiply(num1,num2)<<endl;


    system("pause");
    return 0;
}