#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> twoSum(vector<int> &num, int target){
    unordered_map<int,int> mapping;
    vector<int>   result = {};
    for (int i = 0; i<num.size(); i++){
        mapping[num[i]]=i;          
    }
    for (int i = 0; i < num.size(); i++){
        const int gap = target-num[i];
        if (mapping.find(gap) != mapping.end() && mapping[gap] != i)
        {
            result.push_back(i);
            result.push_back(mapping[gap]);
            break;
        }
    }
    return result;
}

int main(){
    vector<int> num = {2,7,11,3};
    int target=9;
    vector<int>  res = twoSum(num,target);
    for (auto i:res)
            cout<<i<<endl;


    system("pause");
    return 0;
}