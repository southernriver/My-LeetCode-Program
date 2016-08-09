#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>>   re = {};

        int target = 0;
        if (nums.size()<3)  return re;
        sort(nums.begin(), nums.end());    //先将数据排好序
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])  continue;
            target = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j<k)
            {

                if (nums[j] + nums[k] == target)
                {
                    vector<int>     vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    vec.push_back(nums[k]);
                    re.push_back(vec);
                    while (j<k&&nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while (j<k&&nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    ++j; --k;

                }
                else if (nums[j] + nums[k] < target)
                {
                    j++;
                }
                else
                    k--;
            }
        }
        return re;

        /*暴力方法遍历会超时*/
    //sort(nums.begin(),nums.end());
    //for (auto c:nums)
    //    cout << c<<"  ";
    //cout<<endl;
    //

    //vector<vector<int>>    vec;;
    //vector<int>    ivec;
    //for (int i = 0; i < nums.size()-2; i++)
    //{
    //    if (i!=0&&nums[i] == nums[i-1])   continue;
    //    for (int j = i + 1;j<nums.size()-1;j++)
    //    { 
    //        if (nums[j] == nums[j + 1])   continue;
    //        for (int k = j+1; k<nums.size();k++)
    //        {
    //            //if (k<nums.size()-1&&nums[k] == nums[k + 1])   continue;
    //            if (nums[j] + nums[k] == -nums[i])
    //            {         
    //                ivec.push_back(i);
    //                ivec.push_back(j);
    //                ivec.push_back(k);
    //                vec.push_back(ivec);
    //                ivec.clear();
    //            }
    //        }
    //    }
    //}

    //return vec;

    }
};

int main()
{
    Solution  s;
    vector<int>  nums = {-1, 0, 1, 2 ,- 1, - 4 };
    vector<vector<int>>  vec = s.threeSum(nums);

    cout << vec.size()<<endl;
    for (auto c : vec){
        for (auto i:c)
            cout << i << " ";
        cout<<endl;
    }
    



    system("pause");
    return 0;
}