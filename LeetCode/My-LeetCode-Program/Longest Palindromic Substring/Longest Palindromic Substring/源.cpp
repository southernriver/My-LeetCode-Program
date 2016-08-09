#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        
    const int  n = s.size();
    bool f[50][50];
    memset(&f[0][0],false,n*n);
    size_t max_len=1,start=0;
    cout << "time to start:"<<endl;
    for (size_t i = 0; i < s.size(); i++)
    {
        f[i][i] = true;
        for (size_t j = 0; j < i; j++)
        {
            cout<<i-j<<endl;
            f[j][i] = (s[j]==s[i]&&(i-j<2||f[j+1][i-1]));
            if (f[j][i] && max_len<(i - j + 1)){
                cout << "     "<<max_len;
                max_len=i-j+1;
                start=j;
            }
        }
    }
    return s.substr(start,max_len);
    }
};

int main()
{
    Solution s;
    cout<<s.longestPalindrome("hahscdj2334332jcxxccdska")<<endl;



    system("pause");
    return 0;
}