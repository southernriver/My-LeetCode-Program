class Solute{
public:vector<vector<int>> threeSum(vector<int>& nums) {
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
}
};