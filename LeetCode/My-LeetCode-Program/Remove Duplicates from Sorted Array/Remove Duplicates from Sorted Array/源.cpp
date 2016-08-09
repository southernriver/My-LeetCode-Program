#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std ;
int removeDuplicates(vector<int>& nums) {

    auto end_unique = unique(nums.begin(), nums.end());
    nums.erase(end_unique,nums.end());
    

    return  nums.size();
}
int main()
{
    vector<int>  ivec = {3,4,1,2,3,5,6,6,7};
    int n=removeDuplicates(ivec);
    cout<<n<<endl;


    system("pause");
    return 0;
}