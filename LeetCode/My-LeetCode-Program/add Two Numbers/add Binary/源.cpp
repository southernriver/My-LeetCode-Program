#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
/*
class Solution{
public:
    string addBinary(string a, string b) {
    int x = btoi(a);
    int y = btoi(b);
    
    int sum=x+y;
        
    return itob(sum);
    
    }
    int btoi(string str)
    {
    int n=0;
    int sum=0;
         for (int i = str.size() - 1; i >= 0; i--)
         {
            int x0 = str[i] - '0';
            sum += x0*me(2,n);
            n++;
         }
        return sum;
   }
    int me(int x,int n)
    {
        if (n==0)
                return 1;
        if (n==1)
               return x;  
        int sum=x;
        for (int i = 1; i < n; i++)
        {
            sum=sum*x;
        }
        
        return sum;
    }
    
    string itob(int num)
    {
        string str;
        vector<int> svec;
        int i=0;
        while (num/2)
        {
            i=num%2;
            svec.push_back(i);
            num/=2;
        }
        svec.push_back(num%2);
        reverse(svec.begin(), svec.end());
        int j=0; 
       
        for (auto c:svec)
           str.push_back(c+'0');
        return str;
    }
    

};
*/
class Solution{
public :
    string addBinary(string a, string b)
    {
        string str;
        size_t lenA = a.length();
        size_t lenB = b.length();

        size_t len=lenA>lenB?lenA:lenB;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry=0;
        for (int i=0;i<len;i++)
        {
            const int ai = i>=lenA ? 0 : a[i]-'0';
            const int bi = i>=lenB ? 0 : b[i]-'0';
            const int value = (ai+bi+carry)%2;
            carry = (ai+bi+carry)/2;
            str.insert(str.begin(),value+'0');
        }
        if (carry>0)
            str.insert(str.begin(), carry + '0');
        return str;
    }


};
int main()
{
    string a = "11";
    string b = "1";
    Solution s;
     
    cout << s.addBinary(a,b)<<endl;

    


    system("pause");
    return 0;
}