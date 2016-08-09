#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int trap(int A[], int n){
    int *max_left = new int[n]();   //Öµ³õÊ¼»¯Îª0
    int *max_right = new int[n]();
    
    for (int i = 1; i<n; i++){
        max_left[i] = max(max_left[i-1],A[i-1]);   //´Ó×óÍùÓÒÉ¨Ãè
        max_right[n - i - 1] = max(max_right[n-i],A[n-i]);//´ÓÓÒÍù×óÉ¨Ãè
    }
    int sum=0;
    for (int i = 0; i < n; i++){
        cout << max_left[i] << ",i=" << i << "," << max_right[i]<<endl;
        if (min(max_left[i], max_right[i]) - A[i]>0)
         sum+=min(max_left[i], max_right[i]) - A[i];
    }
    return sum;
}
int main(){
    int a[12] = {0,1,0,2,1,0,1,3,2,1,2,1} ; 
    int n=12;
    cout<<trap(a,n)<<endl;

    system("pause");
    return 0;
}