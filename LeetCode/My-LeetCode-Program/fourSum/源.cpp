#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:

    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> p(numRows, "");
        int size = 2 * numRows - 2;
        for (int i = 0; i<s.size(); i++) p[abs(numRows - 1 - i%size)] += s[i];
        return accumulate(p.begin(), p.end(), string(""));

    }

};

int main()
{
    Solution s;
    
    cout<<s.convert("PAYPALISHIRING",4)<<endl;
    vector<string>   p(4,"");
    p[2] = "hello";
    p[3] = "world";
    

    cout<<accumulate(p.rbegin(), p.rend(),string(""))<<endl;
    system("pause");
    return 0;
}