#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace  std;
class Solution {
public:
    bool isValid(const string &s) {
        string left  =  {"([{"};
        string right =  {")]}"};
        stack<char> ss;
        for (auto c:s)
        {
            if (left.find(c)!=string::npos)
                ss.push(c);
            else
            {
                if (ss.empty()||(left[right.find(c)] != ss.top()))
                {
                    return false;
                }
                ss.pop();
            }
        }
    return ss.empty();
    }

};
int main()
{
    Solution s;
    cout << s.isValid("([{}])") << endl;

    
   
    

    system("pause");
    return 0;
}