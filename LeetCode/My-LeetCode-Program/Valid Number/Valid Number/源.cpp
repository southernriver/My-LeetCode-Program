#include<iostream>
#include<string>
#include<algorithm>
#include<algorithm>
using namespace std;

bool isNumber(const char* s1){
    //消除后面的空格
    int end=0;
    for (end = 0; s1[end]!='\0';end++);
    int o=end-1;
    for (; isspace(s1[o]); o--);
    //消除前面的空格
    int l=0;
    for (l = 0; isspace(s1[l]);l++);
  
    char *s = new char[end];
    int w=0;
    for (int p=l;p<=o;p++)
        s[w++] = s1[p];
    s[w] = '\0';
    int i=0;
 
    if (s[0] != '+'&&s[0] != '-'&&s[0]!='.'&&!isdigit(s[0]))     return false;
    if (s[0] == '+' || s[0] == '-') i++;
    if (s==".")   return false ;  
    for (; s[i] != '\0'; i++){
        
        //确认第一个字符是数字
        if (isdigit(s[i]))  //如果是数字
                continue;
        else if (s[i]=='.')  //如果是'.'
        {   
            int j=i+1;
          
            //下一个必须是数字，否则返回false
            if ((s[j] != '\0' && !isdigit(s[j])))     return false;  cout << "hellow";
            //后面只能出现最多两个字符并且相邻。"e+"或者"e-";
            if (s[j]=='\0'||(isdigit(s[j]) && s[j + 1] == '\0'))      return true;
            for (int j = i + 1; s[j] != '\0'; j++){
                if (s[j] == 'e' && (s[j + 1] == '+' || s[j + 1] == '-' || isdigit(s[j + 1])))
                {
                    for (int k = j + 1; s[k] != '\0'; k++){
                        if (!isdigit(s[k]))     return false; 
                    }
                    return true;
                }
                else if (!isdigit(s[j]))   return false;
                else
                    continue;
           
            } 
            if (s[j]=='\0')
                    return true;
        }else if (s[i]=='e')
        {
            if (s[i + 1] == '\0')   return false;
            for (int m = i + 1; s[m] != '\0'; m++){
                if ( s[m + 1] == '+' || s[m + 1] == '-' || isdigit(s[m, + 1]))
                {
                    for (int n = m + 1; s[n] != '\0'; n++){
                        if (!isdigit(s[n]))     return false;
                    }
                    return true;
                }
                else
                {
                    continue;
                }
            }

          }    
        else
            return false;
    }
           return true;
}

int main(){
    
    cout << isNumber("1.")<<endl;


    system("pause");
    return 0;
}