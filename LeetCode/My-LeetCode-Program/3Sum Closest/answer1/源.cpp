#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target){
    sort(nums.begin(),nums.end());
    int len = nums.size();
    int result=0;
    int min_gap=INT_MAX;
    for (int i=0;i<nums.size()-2;i++){
        
    
        int j=i+1;
        int k=len-1;
        while (j<k)
        {
            const int sum = nums[i] + nums[j] + nums[k];
            const int gap = abs(target-sum);
            if (gap<min_gap){
                result=sum;
                min_gap=gap;
            }
            if (sum<target) j++;
            else      k--;
        }

    }
        return result;
    }
};

int main()
{
    vector<int>   vec = { -1, 2, 1, -4 };
    Solution  s;
    cout << s.threeSumClosest(vec, 1) << endl;
    system("pause");
    return 0;
}