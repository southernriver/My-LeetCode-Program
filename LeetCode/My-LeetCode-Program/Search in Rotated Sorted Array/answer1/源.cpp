#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int search(int A[], int n, int target){
    int first=0,last=n-1;
    while (first<=last)
    {
        const int mid = (first+last)/2;
        if (A[mid]==target)
                return mid;
        if (A[first] <A[mid]){  //�����������
            if (A[first] <= target&&target <A[mid]){//target�����
                last=mid-1;               //��last��С1/2
            }else{  //target���Ҳ�
                first=mid+1;            //��first����һ��
            }
        }
        else  if(A[first]>A[mid])               //����Ǽ�����
        {
            if (A[mid]<target&&target <= A[last])
                first=mid+1;
            else
                last=mid-1;
        }
        else
        {
            first++;
        }
    }
    return -1;
}

int main(){
    int A[5] = {0,3,1,2,5};
    int target=2;
    cout << search(A,5,target)<<endl;


    system("pause");
    return 0;
}