#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class  Solution
{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)  return "";
    size_t len=strs[0].length();
    for (int i = 0; i<strs.size();i++)
    {  
        len = min(len,strs[i].length());
    }
    int j=0;
    bool flag=true;
    for (; j < len; j++)
    {
        cout<<j<<endl;
        char ch = strs[0][j];
        for (auto k = 1; k < strs.size(); k++){
            if (strs[k][j] != ch){
                   flag=false;
                   break;
            }
        }
        if (!flag)
                break;
    }
    if (j == 0){
            return "";
    }
    else
    {
        string s;
        for (int l=0;l<j;l++)
            s += strs[0][l];
        return  s; 
    }



      
    }
};
int main()
{
    Solution s;
    vector<string>  strs = {"shae", "shahh", "shadsf", "shassdf", "shasdffdg"};
    cout << s.longestCommonPrefix(strs)<<endl;
    




    system("pause");
    return 0;
}