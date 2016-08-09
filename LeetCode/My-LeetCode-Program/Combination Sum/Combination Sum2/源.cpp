#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void dfs(vector<int> candidates, int target, int start, vector<int> &temp, vector<vector<int>> &res)
{
    if (target == 0){
        res.push_back(temp);
        return ;
    }
    if (target<0)   return ; 
    for (int i = start; i < candidates.size(); i++){
        if (i>start&&candidates[i]==candidates[i-1])  continue;
        temp.push_back(candidates[i]);
        dfs(candidates,target-candidates[i],i+1,temp,res);
        temp.pop_back();
    }


}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int>   temp = {};
    vector<vector<int>> res = {};
    dfs(candidates,target,0,temp,res);
    
    
    return res;

}
int main(){

    vector<int>  nums = { 1, 2,1, 1 };
    vector<vector<int>> res = combinationSum2(nums, 2);
    for (auto c0 : res){
        for (auto c1 : c0)
            cout << c1 << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}