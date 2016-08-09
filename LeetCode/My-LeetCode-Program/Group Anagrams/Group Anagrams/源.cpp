#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
#include<map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>   result;
    vector<string>      vs;
    map<string, vector<string>>   imap;
    sort(strs.begin(),strs.end());
    for (auto c : strs){
        string key=c;
        sort(key.begin(),key.end());
        imap[key].push_back(c);
    }
    for (auto c : imap){
        //cout<<c.first<<endl;
        for (auto s : c.second){
            vs.push_back(s);
        }
        result.push_back(vs);
        vs.clear();
    }
    sort(result.begin(),result.end(),[](const vector<string> &a,const vector<string> &b){return a.size()<b.size();});


    return result;
}
int main(){
    vector<string>  strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>>  result=groupAnagrams(strs);
    for (auto i : result){
        for (auto j : i){
            cout << j << " ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}