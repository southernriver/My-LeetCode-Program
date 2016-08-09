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
    
    sort(nums.begin(), nums.end());

    vector<int>    ivec;
    map<int,int>  imap;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int j=i+1;
        int k = nums.size()-1;
        while (j<k)
        {
    
            int n=0;
            int x = abs(nums[i] + nums[j] + nums[k] - target);  //ºÍ²î
            if (nums[i] + nums[j] + nums[k] - target >= 0)
                imap[x]=x+target;
            else
                imap[x]=-x+target;
            ivec.push_back(x);
            if (nums[i] + nums[j] + nums[k] < target)
                        j++;
            else  if (nums[i] + nums[j] + nums[k] > target)
                        k--;
            else
                return imap[x];
        }  
    }
    sort(ivec.begin(), ivec.end());
    return  imap[ivec[0]];
    }
};

int main()
{
    vector<int>   vec = { 0,2,-2,-3};
    Solution  s;
    cout << s.threeSumClosest(vec,1)<<endl;
    system("pause");
    return 0;
}