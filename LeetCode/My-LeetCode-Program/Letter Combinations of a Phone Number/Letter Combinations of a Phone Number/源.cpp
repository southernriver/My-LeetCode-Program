#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits){
    init();
    vector<string>   svec;
    for (int i=0;i<digits.size();i++)
    { 
            cout<<ismap[digits[i]-'0']<<endl;
            svec.push_back(ismap[digits[i] - '0']);
    }
    string ch[9][4];
    for (int i = 0; i < svec.size(); i++)
    {
        for (int j = 0; j < svec[i].length(); j++){
            ch[i][j] = svec[i][j];
            cout << ch[i][j]<<" ";
        }
         cout<<endl;   
    }
    vector<string>     vs;
    
    for (int k = 0; k<svec[0].size();k++)
    {
        string s = ch[0][k];
           int l=1;
            for (int m = 0; l<svec.size()&&m < svec[l].size(); m++){
                for (; l<svec.size();l++)
                { 
                     s += ch[l][m];  
                }  
                l = 1;
                vs.push_back(s);
                s = ch[0][k];
            }  
        
    }
    for (auto c: vs)
          cout<<c<<endl;
    return svec;
    }
public:
    void init(){
        vector<string>  v = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for (int i = 2; i <= 9; i++)
        {
            ismap[i] = v[i-2];
        }
    }
    
private:
    map<int,string>  ismap;
};
int main()
{
   Solution s;
   s.letterCombinations("234");




    system("pause");
    return 0;
}