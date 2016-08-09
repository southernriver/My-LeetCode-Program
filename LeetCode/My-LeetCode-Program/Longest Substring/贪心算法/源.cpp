#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX=128;
        int last[ASCII_MAX];    //记录字符上次出现过的位置
        int start=0;            //记录当前子串的起始位置
        fill(last,last+ASCII_MAX,-1);

        int max_len=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (last[s[i]] >= start){
                max_len = max(i-start,max_len);
                start = last[s[i]]+1;
            }
            
            cout <<"max_len:"<< max_len<<",start:"<<start << "  ";
           
            cout <<s[i] <<"  "<<last[s[i]] <<"   i="<<i<<endl; last[s[i]]=i;
        }
        cout<<endl;
        return max((int)s.size()-start,max_len);
    }

};

int main()
{
    string s = "qpxrjxkltfd^&&*zyx";

    Solution solute;
    cout << solute.lengthOfLongestSubstring(s) << endl;

    for (int i=0;i<26;i++)
        cout << char('a' + i)<< 'a'+i<<" ";
    cout<<endl;
    system("pause");
    return  0;
}
