#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
bool nextPermutation(vector<int>& nums) {
    return next_permutation(nums.begin(), nums.begin() + nums.size());
}
int main()
{
    vector<int> nums = {1,2,3,4,5};
    while(nextPermutation(nums))
    { 
        for (auto c:nums)
            cout << c << " ";
        cout<<endl;
    }
    system("pause");
    return 0;
}