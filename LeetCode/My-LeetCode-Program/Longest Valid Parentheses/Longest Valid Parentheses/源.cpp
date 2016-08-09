#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
int longestValidParentheses(string s) {
    
    int Max;
    stack<int>   st;
    unordered_map<int,int>  prevMap;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            st.push(i);
        }else{
            if (st.empty())  continue;
            int index = st.top();
            st.pop();
            if (prevMap.find(index - 1) != prevMap.end()){
                prevMap[i] = prevMap[index-1]+i-index+1;;
            } else{
                prevMap[i]=i-index+1;
            }
            Max = max(Max, prevMap[i]);
        }
    }
    return Max;

}
int main()
{
    string s("())((()))(()");
    int num = longestValidParentheses(s);
    cout<<num<<endl;

    system("pause");
    return 0;
}