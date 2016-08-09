#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
bool isMatch(const char *s, const char *p)
{
    int i=0,j=0;
    if (s==p)
                return true;
    if (p==".*")
                return true;
    for (; p[i] != '\0';i++)
        if (p[i]=='*')  break;
    for (; j < i-1; j++)
    {
        if (s[j]!=p[j])
                  return false;                  
    }
    if (s[j] == p[j]){
        for (int m = j + 1; s[m] != '\0'; m++)
        {
            if (s[s[j]!=s[m]])
                               
        }
    }

}
int main(){

    isMatch("hello","dsfsgfg*gvfhg");




    system("pause");
    return 0;
}