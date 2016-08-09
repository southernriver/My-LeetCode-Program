#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace  std;
class Solution {
public:
    bool isValid(const string &s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for (auto c : s) {
            if (left.find(c) != string::npos) {
                stk.push(c);      //’“µΩleft
            }
            else {
                if (stk.empty() || stk.top() != left[right.find(c)])
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
   
};
int main()
{
    Solution s;
   cout<< s.isValid("([{}])")<<endl;;

    
    system("pause");
    return 0;
}