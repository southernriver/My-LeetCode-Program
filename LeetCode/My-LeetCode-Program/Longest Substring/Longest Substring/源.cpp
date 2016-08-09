#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
        bool is_in(vector<int> vec, int x)
        {
            for (int i = 0; i<vec.size(); i++)
            {
                if (vec[i] == x)
                    return true;

            }
            return false;
        }

        int lengthOfLongestSubstring(string s) {
            if (s == "")   return 0;
            vector<vector<int> >  ivec;
            for (int j = 0; j<s.length(); j++)
            {
                ivec.resize(s.length());
                ivec[j].push_back(s[j]);
                for (int i = j + 1; i < s.length(); i++)
                {
                    if (!is_in(ivec[j], s[i]))
                    {

                        ivec[j].push_back(s[i]);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            vector<int>   vec;
            for (int k = 0; k<ivec.size(); k++)
            {
                vec.push_back(ivec[k].size());
            }
            sort(vec.begin(), vec.end());
            return vec[vec.size() - 1];
        }
    
};

int main()
{
    string s = "abcde";

    Solution solute;
    cout<<solute.lengthOfLongestSubstring(s)<<endl;;

    system("pause");
    return  0;
}
