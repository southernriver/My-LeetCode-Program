#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<functional>
using namespace std;
//结点类
template<class T> class  BinaryTreeNode{
public:
    BinaryTreeNode<T>(T elem){
        m_nValue=elem;
        m_pLeft=NULL;
        m_pRight=NULL;
    }
public:
    T m_nValue;
    BinaryTreeNode<T>*m_pLeft;
    BinaryTreeNode<T>*m_pRight;  
};
//二叉树类
template<class T> 
class BinaryTree{
public:
    //创建结点
    BinaryTreeNode<T>* CreateNode(BinaryTreeNode<T> *l, BinaryTreeNode<T> *r, T elem){
        root = new BinaryTreeNode<T>(elem);
        root->m_pLeft=l;
        root->m_pRight=r;
        return root;
    }
    //递归前序遍历二叉树
    void PreOrder(BinaryTreeNode<T> *root){
        if (root)
        {
            cout<<root->m_nValue;
            PreOrder(root->m_pLeft);
            PreOrder(root->m_pRight);
        }
    }
    
    //按层次遍历二叉树
    void displayLevel(BinaryTreeNode<T> *root){
        queue<BinaryTreeNode<T>*> q;
        q.push(root);
        while (!q.empty())
        {
            BinaryTreeNode<T> *p = q.front();
            q.pop();
            cout<<p->m_nValue;
            if (p->m_pLeft)
                q.push(p->m_pLeft);
            if (p->m_pRight)
                q.push(p->m_pRight);
        }
    cout<<endl;
    }
    //按编号显示
    void displayWithNo(BinaryTreeNode<T> *root,int i){
        max_set.insert(i);
        cout << "Position:" << i << " ,Value:" << root->m_nValue << endl;
        if (root->m_pLeft)  displayWithNo(root->m_pLeft, 2 * i);
        if (root->m_pRight)  displayWithNo(root->m_pRight, 2 * i + 1);
    }
    int Depth(BinaryTreeNode<T> *root){
        if (root==nullptr)
            return 0;
        int nLeft = Depth(root->m_pLeft);
        int nRight = Depth(root->m_pRight);
        return (nLeft>nRight) ? (nLeft + 1) : (nRight+1);
    }
        

public:
    //根节点
    BinaryTreeNode<T>*root;
    set<int,greater<int>>    max_set;
};
int main(){
    //1.创建一颗二叉树
    BinaryTree<int> tree;
    BinaryTreeNode<int> *r1=tree.CreateNode(NULL,NULL,7);
    BinaryTreeNode<int> *r2 = tree.CreateNode(NULL, NULL, 4);
    BinaryTreeNode<int> *r3 = tree.CreateNode(NULL, NULL, 6);
    BinaryTreeNode<int> *r4 = tree.CreateNode(r1,NULL,5);
    BinaryTreeNode<int> *r5 = tree.CreateNode(r2,r4,2);
    
    BinaryTreeNode<int> *r6 = tree.CreateNode(NULL,r3,3);
    BinaryTreeNode<int> *root = tree.CreateNode(r5,r6,1);
        
    tree.PreOrder(root);
    cout<<endl; 
    tree.displayLevel(root);
    tree.displayWithNo(root,1);

    cout << tree.Depth(root)<<endl;
    system("pause");
    return 0;
}