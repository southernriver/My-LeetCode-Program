#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//二分搜索的时间耗费是O(logn)
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>   res{ 0, 0 };
    if (nums.size() == 1 && nums[0] == target)   return res;
    res.clear();
    int left = 0;
    int right = nums.size() - 1;
    int  mid = (left + right) / 2;
    while (left <= right){

        if (target<nums[mid]){
            right = mid - 1;
        }
        else if (target>nums[mid]){
            left = mid + 1;
        }
        else{   //target==nums[mid]
            int t = mid;
            cout<<t<<endl;
            while (t>=left&&nums[t] == target)  t--;
            int i = t + 1;
            cout<<i<<endl;
            res.push_back(i);
            while (mid<=right&&nums[mid] == target) mid++;
            res.push_back(mid - 1);
            return res;
        }
        mid = (left + right) / 2;

    }
    res.clear();
    res = { -1, -1 };
    return res;
}
int main(){
    vector<int>   nums{1,4,5};
    vector<int>  result = searchRange(nums,4);
    for (auto c:result)
        cout << c << " ";
    cout<<endl;

    system("pause");
    return 0;
}