#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    /*******************
    С���Ŵ���һ���ݹ�ṹ�����������������ȵݹ�ṹһ���������뵽�õݹ顣
    һ���������ַ������������ų��ִ���< n ʱ���Ϳ��Է����µ������š��������ų��ִ���С
    �������ų��ִ���ʱ���Ϳ��Է����µ������š�
    ***********/
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0) generate(n, "", 0, 0, result);
        return result;
    }
    // l ��ʾ( ���ֵĴ���, r ��ʾ) ���ֵĴ���
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