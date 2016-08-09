#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(const string &digits) {
    vector<string>  keyStr = { " ", "", "abc", "def",
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string>   result(1,"");
    for (auto d : digits){
        int m = keyStr[d - '0'].size(); //对应的字母长度
        int n = result.size();
        result.resize(n*m);
        for (int i=0;i<m;i++)
            copy(result.begin(),result.begin()+n,result.begin()+n*i);
        for (int i = 0; i< m; i++)
        {
            auto begin = result.begin();
            for_each(begin + n*i, begin + n*(i + 1), [&](string &s){
                s += keyStr[d-'0'][i];
            });

        }
    }


    return result;
    }
};
int main()
{
    Solution s;
    vector<string>   svec = s.letterCombinations("23");

    for (auto c : svec)
        cout << c << endl;
    cout << endl;


    system("pause");
    return 0;
}