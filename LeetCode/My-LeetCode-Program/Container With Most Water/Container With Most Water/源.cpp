#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height){    
    int nwidth = height.size()-1;   //×î´óµÄ¿í
    int max0=0;
    int h=-1;
    for(int k=0;k<height.size()-1;k++)
    { 
        int h1 = height[k];
        for (int i = k+1; i < height.size(); i++)
        {
            int h2 = height[i];
            h = min(h1,h2);
            max0 = max(max0,h*(i-k));
        }
    }
        return max0;
    }
};


int main()
{
    vector<int>   ivec = {1,3,4,5,5,3};
    Solution s;
    cout << s.maxArea(ivec)<<endl;


    system("pause");
    return 0;
}