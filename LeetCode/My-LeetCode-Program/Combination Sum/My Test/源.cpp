#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void dfs(vector<int>& candidates, int target, int start, vector<int>& oneSol, vector<vector<int>>& allSol){
    if (target == 0) {
        if (oneSol.size()) 
            allSol.push_back(oneSol);
        return;
    }
    if (target < 0) return;

    for (int i = start; i < candidates.size(); i++){
        if (i > start&&candidates[i] == candidates[i - 1]) continue;
        oneSol.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i + 1, oneSol, allSol);
        oneSol.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> oneSol;
    vector<vector<int>> allSol;
    dfs(candidates, target, 0, oneSol, allSol);

    return allSol;
}


int main(){

    vector<int>  nums = {1,2,1,1};
    vector<vector<int>> res = combinationSum2(nums, 2);
    for (auto c0 : res){
        for (auto c1 : c0)
            cout << c1 << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}
