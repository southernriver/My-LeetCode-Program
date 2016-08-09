#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        int last[26];  //用来保存前面出现字符的位置
        int start=0;  //标记起始搜索位置
        int max_len=0;
        fill(last,last+26,-1);
        
        for (int i = 0; i < s.size(); i++)
        {
            if (last[s[i] - 'a'] >= start)
            {
                max_len = max(i-start,max_len);
                start = last[s[i]-'a']+1;
            }
            last[s[i]-'a']=i;   
        }
        return max((int)(s.size())-start,max_len);
    }
};


int main()
{
    string s = "qpxrjxkltzyx";

    Solution solute;
    cout << solute.lengthOfLongestSubstring(s) << endl;



    system("pause");
    return 0;
}