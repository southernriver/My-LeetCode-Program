#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i=0,j=0,k=0;
    vector<double>   nums;
    nums.resize(nums1.size()+nums2.size());
   
    
    while (i<nums1.size()&&j<nums2.size())
    {
        if ((nums1[i])>nums2[j])
            nums[k++] = nums2[j++];
        if ((nums1[i])<=nums2[j])
            nums[k++] = nums1[i++];
        if (i>=nums1.size()||j>=nums2.size())
        {
            break;
        }
    }
    while (i == nums1.size() && j<nums2.size())
    {
        nums[k++] = nums2[j++];
    }
    while (j == nums2.size() && i<nums1.size())
    {
 
        
        nums[k++] = nums1[i++];
      
    }
    for (auto c : nums)
        cout << c << " ";
    cout<<endl;
    if (nums.size()%2)
        return nums[nums.size()/2];
    else
   { 
        return (nums[nums.size() / 2 - 1] + nums[nums.size()/2])/2;
    }
    }
};
int main()
{
    Solution s;
    vector<int>  num1={};
    vector<int>  num2={};
//    cout << num2.size()<<endl;
    cout<<(double)s.findMedianSortedArrays(num1,num2)<<endl;

    


    system("pause");
    return 0;
}