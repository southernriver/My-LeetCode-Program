#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    /*******************
    小括号串是一个递归结构，跟单链表、二叉树等递归结构一样，首先想到用递归。
    一步步构造字符串。当左括号出现次数< n 时，就可以放置新的左括号。当右括号出现次数小
    于左括号出现次数时，就可以放置新的右括号。
    ***********/
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0) generate(n, "", 0, 0, result);
        return result;
    }
    // l 表示( 出现的次数, r 表示) 出现的次数
    void generate(int n, string s, int l, int r, vector<string> &result) {
        if (l == n) {
            result.push_back(s.append(n - r, ')'));
            return;
        }
        generate(n, s + '(', l + 1, r, result);
        if (l > r) generate(n, s + ")", l, r + 1, result);
    }
};
int main()
{
    Solution s;
    vector<string>  ivec = s.generateParenthesis(10);
    for (auto c:ivec)
            cout<<c<<endl;




    system("pause");
    return 0;
}