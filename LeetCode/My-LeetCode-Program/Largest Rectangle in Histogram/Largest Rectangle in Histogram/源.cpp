#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &height){
    stack<int>  s;
  //  height.push_back(0);
    int result=0;
    int i = 0; 
    while(i < height.size()){
        if (s.empty() || height[i]>height[s.top()])
            s.push(i++);
        else
        {
            int tmp = s.top();
            s.pop();
            result = max(result, height[tmp] * (s.empty()?i:i-s.top()-1));
        }
    }
    return result;
}
int main(){
    vector<int>  height = {2,1,5,6,2,3};
    cout<<largestRectangleArea(height)<<endl;



    system("pause");
    return 0;
}