#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
void dfs(vector<int>& candidates, int& target, int start, int length, vector<vector<int>>& rst, vector<int>& temp) {
    if (target == 0) {
        // find one solution, add to the rst and return
        rst.push_back(temp);
        return;
    }
    for (int i = start; i < length; ++i) {
        if (candidates[i] == candidates[i - 1])   continue;
        if (target - candidates[i] < 0){
            // sort ensures that elements after candidates[i] are all bigger than candidates[i], so just break
            break;
        }
        else{
            temp.push_back(candidates[i]);
            target -= candidates[i];
            dfs(candidates, target, i, length, rst, temp);
            // get one solution or not, reset target and temp
            target += candidates[i];
            temp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int length = candidates.size();
    if (length == 0) return{};
    sort(candidates.begin(), candidates.end());
    // rst store all the solutions
    vector<vector<int>> rst = {};

    // temp store the current elements
    vector<int> temp = {};   
    for (int i = 0; i < length; ++i) {
       
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            target -= candidates[i];
            dfs(candidates, target, i, length, rst, temp);
            target += candidates[i];
            temp.pop_back();
        }
    }
    return rst;
}
int main(){
    
    vector<int>  nums = {8,7,4,3};
    vector<vector<int>> res = combinationSum(nums,7);
    for (auto c0 : res){
        for (auto c1:c0)
            cout << c1 << " ";
        cout<<endl;
    }

    system("pause");
    return 0;
}
