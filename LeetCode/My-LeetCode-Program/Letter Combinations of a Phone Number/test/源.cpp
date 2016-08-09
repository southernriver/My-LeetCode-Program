#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
  

    vector<string> letterCombinations(const string &digits) {    
    const vector<string> keyboard{ " ", "", "abc", "def", // '0','1','2',...
        "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> result(1, "");
        for (auto d : digits) {
            const size_t n = result.size();
                       // cout<<"n:"<<n<<endl;
            const size_t m = keyboard[d - '0'].size();
           
            result.resize(n * m);
            for (size_t i = 0; i < m; ++i)
                copy(result.begin(), result.begin() + n, result.begin() + n * i);
            for (size_t i = 0; i < m; ++i) {
                auto begin = result.begin();
                for_each(begin + n * i, begin + n * (i + 1), [&](string &s) {
                    s += keyboard[d - '0'][i];
                  //  cout<<"s:"<<s<<endl;
                });
                //for (auto c:result)
                //    cout << c << " ";
                //cout<<endl;
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<string>   svec=s.letterCombinations("2");

    for (auto c:svec)
        cout << c <<endl;
    cout<<endl;


    system("pause");
    return 0;
}