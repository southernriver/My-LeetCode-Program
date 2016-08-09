#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* simplifyPath(char* path) {
    char temp[50];
    for (int i = 0; path[i] != '\0'; i++)
    {
        temp[i] = path[i];
    }
    char *token=strtok(path, "/");
    char *s="";
    while (token!=NULL)
    {
        printf("%s\n",token);
        s=token;
        token = strtok(NULL, "/");
    }
    return s;

}
int main(){   
    char path[50]= "/ ,./././ .d sf,. ,/fdd,fv/ //.//";
            
    char *s=simplifyPath(path);
    char s1[10] = "//";
    strcat(s1,s);
    printf("s=%s\n",s1);
    system("pause");
    return 0;
}
