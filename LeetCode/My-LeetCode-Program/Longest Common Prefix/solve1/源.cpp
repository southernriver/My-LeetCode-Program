#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//找出若干字符串的最长相同字符串
string LongestCommonPrefix(vector<string> &strs){
    if (strs.size() == 0)  return "";
    size_t len = strs.size();   //给定字符串的个数
    //将长度按小到大的顺序排序
    sort(strs.begin(),strs.end(),[](const string &a,const string &b){return a.size()<b.size();});
    int max_common_len = strs[0].length();  //最长相同字符串的长度最大值
    string s = strs[0];
    for (int j = 0; j<max_common_len; j++){
        int i=1;  
        for (i = 1; i < len; i++){
            if (strs[i].find((s.substr(0, max_common_len - j))) !=0)
                     break;
        }
        if (i == len){
            return s.substr(0, max_common_len - j);
        }      
    }
    return "";
}
int main(){

    vector<string>  strs = { "shae", "shahh", "shadsf", "shassdf", "shasdffdg" };
    cout << LongestCommonPrefix(strs) << endl;



    system("pause");
    return 0;
}