#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int>   result;
    unordered_map<string,int>  wordsmap;
    for (auto &c : words)      ++wordsmap[c];        //将需要寻找的words保存到哈希map中
    
    size_t Length = words.size()*words[0].size();
    
    for (auto i = begin(s); i <= prev(end(s), 6); ++i){
        unordered_map<string,int>   unusedmap(wordsmap);
        for (auto j = i; j != i + 6; j += 3)
        {   
      
            auto pos = unusedmap.find(string(j,next(j,3)));
           
            if (pos == unusedmap.end()||pos->second==0)   break;
            if (--pos->second == 0)     unusedmap.erase(pos);
        }
        cout << "unused.size():" << unusedmap.size() << endl;
        if (unusedmap.size() == 0){
            result.push_back(distance(begin(s),i));
         
            }
    }
    return result;
}
int main()
{
    string s = "barfoobarfo";
    vector<string>  words = {"foo","bar"};
    auto res=findSubstring(s,words);
    for (auto c:res)
        cout << c<<endl;


    system("pause");
    return 0;
}