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
        if (s[i] == '('){     //�жϵ�ǰ���Ƿ���'('
            stack1.push(i); //  ��������±�
        }
        //�����ǰ����')'
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