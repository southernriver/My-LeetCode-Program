#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;
int longestConsecutive(const vector<int> &num){
    unordered_map<int,bool> used;
    for (auto i : num)  used[i]=false;
    int longest=0;
    for (auto i : num){
        if (used[i])  continue;
        int length=1;
        used[i]=true;
        for (int j = i + 1; used.find(j) != used.end(); ++j){
            used[j]=true;
            ++length;
        }
        for (int j = i - 1; used.find(j) != used.end(); --j){
            used[j]=true;
            ++length;
        }
        longest = max(longest,length);
    }
    return longest;
}
int main(){
    vector<int>   nums = {100,4,200,1,3,2,0,6,5};
    cout << longestConsecutive(nums)<<endl;


    system("pause");
    return 0;
}