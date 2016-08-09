#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
using namespace std;
int longValidParentheses(const string s){
    int max_len=0;int last=-1;
    stack<int>   left;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(')
        {
            left.push(i);    //依次序将左括号的下标保存起来
        }
        //当遍历到右括号的时候
        else
        {   
            if (left.empty())    last=i;  //没有与之对应的左括号
            else{
                left.pop();
                if (left.empty())
                    max_len = max(max_len,i-last);
                else
                {
                    max_len = max(max_len, i - left.top());
                }
            }
             

        }

    }
    return max_len;

}
int main(){
    cout << longValidParentheses("())")<<endl;



    system("pause");
    return 0;
}