#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector<int> grayCode(int n) {
    int num = pow(2,n);
    vector<int>   result = {};
    for (int i = 0; i < num; i++){
     
       result.push_back( i ^ (i>>1));  //整数的格雷码公式
         
    }
    return result;
}
int main(){

    vector<int> result=grayCode(3);
    for (auto c:result)
        cout << c << " ";
    cout<<endl;


    system("pause");
    return 0;
}