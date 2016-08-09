#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"ThreeSum.h"
using namespace std;

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  re{};
        if (nums.size()<3)
                        return re;
        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size() - 2; i++)
        {

            int target = -nums[i];
            for (int j = i + 1; j<nums.size() - 1; j++)
            {
                for (int k = i + 2; k<nums.size(); k++)
                {     vector<int>   vec;
                    if (nums[j] + nums[k] ==target)
                    {
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
                        sort(vec.begin(), vec.end());
                        int m=0;
                        for(;m<re.size();m++)
                        {
                            if (re[m]==vec)
                                    break; 
                        }


                        if (m==re.size())
                           re.push_back(vec);
                        continue;
                    }
               
                }
            }

        }


        return re;
    }
};
*/


int main()
{
    Solute s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> r=s.threeSum(nums);
    cout << r.size()<<endl;

    for (auto it = r.begin(); it != r.end(); it++)
    {
        for (auto iter = it->begin(); iter != it->end(); iter++)
        {
            cout << *iter << ",";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}