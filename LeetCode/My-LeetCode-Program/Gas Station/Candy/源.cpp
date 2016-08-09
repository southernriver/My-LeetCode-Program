#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
int candy(vector<int> ratings) {
    sort(ratings.begin(),ratings.end());
 //   reverse(ratings.begin(),ratings.end());
    vector<int> rating = {};
    rating.resize(ratings.size());
    rating[0]=1;
    for (int i = 1; i < ratings.size(); i++){
        if (ratings[i]==ratings[i-1])
            rating[i] = rating[i - 1];
        else
            rating[i] = rating[i-1]+1;
        
    }
    return accumulate(&rating[0], &rating[0] + ratings.size(), 0);
}
int main(){
    vector<int>  ratings = {1,2,2};
    cout << candy(ratings)<<endl;



    system("pause");
    return 0;
}