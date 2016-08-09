#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

int longestValidParentheses(string s){
    stack<int>    stack1;
    int max_len=0;
    int last=-1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){     //判断当前的是否是'('
            stack1.push(i); //  保存起点下标
        }
        //如果当前的是')'
        else{
            if (stack1.empty()){
               last=i; 
            }else
            {
                stack1.pop();
                if (stack1.empty()){
                    max_len=max(max_len,i-last);
                }
                else
                {
                    max_len = max(max_len, i - stack1.top());
                }
            }
        }
    }
    return max_len;
}
int main(){
    cout << longestValidParentheses("()")<<endl;


    system("pause");
    return 0;
}