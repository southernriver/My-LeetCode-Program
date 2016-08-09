#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int binarysearch(vector<int> &nums, int target, int left, int right){
    while (left <= right){
        int mid = (left + right) / 2;
        if (nums[mid]>target)
            right = mid - 1;
        else if (nums[mid]<target)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    if (nums.size() == 1)
        return nums[0] == target ? 0 : -1;
    int left = 0;
    int right = nums.size() - 1;
    int mid = left;  //mid为递增和递减的分界线
    while (nums[left] >= nums[right]){
        if (right - left == 1)
        {
            mid = right;
            break;
        }
        mid = (left + right) / 2;
        if (nums[mid] >= nums[left])
            left = mid;
        else if (nums[mid] <= nums[right])
            right = mid;
    }

    int r = nums.size()-1;
    if (target>nums[r])
        return binarysearch(nums, target, 0, mid);
    else if (target<nums[r])
        return binarysearch(nums, target, mid, r);
    else if (target == nums[r])
        return r;
    return -1;
}
int main(){
    vector<int>  nums{5,1,2,3};
    int r=search(nums,5);
    cout<<r<<endl;


    system("pause");
    return 0;
}