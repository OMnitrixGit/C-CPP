//菜单内容：
//1. 建立二叉树存储结构
//2. 求二叉树的前序遍历
//3. 求二叉树的中序遍历
//4. 求二叉树的后序遍历
//5. 求指定结点的路径
//6. 退出系统
//请选择：1 – 6：
#ifndef DATASTRUCTURE_BITREE_H
#define DATASTRUCTURE_BITREE_H
#include <stdio.h>
#include <stdlib.h>
typedef char elemtype;
typedef struct node{
    elemtype data;
    struct node* left;
    struct node* right;
}BiTNode,*BiTree;

void InitBiTree(BiTree T){
    elemtype ch;
    scanf("%c",&ch);
    if(ch=='#'){
        T= nullptr;
    }
    else{
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=ch;
        InitBiTree(T->left);
        InitBiTree(T->right);
    }
}
void InOrder(BiTree T){
    if(T){
        printf("%c",T->data);
        InOrder(T->left);
        InOrder(T->right);
    }
}
void MidOrder(BiTree T){
    if(T){
        printf("%c",T->data);
        MidOrder(T->left);
        MidOrder(T->right);
    }
}
void PostOrder(BiTree T){
    if(T){
        printf("%c",T->data);
        PostOrder(T->left);
        PostOrder(T->right);
    }
}
void Path(BiTree T,elemtype e){
    static BiTNode* stack[20];static int i=0;
    if(T->data=='e'){
        stack[i++]=T;
    }else if(T==NULL){
        i=0;
    }else{
        stack[i++]=T;
        InOrder(T->left);
        stack[i++]=T;
        InOrder(T->right);
    }
}
//BiTree T;
//InitBiTree(T);
//InOrder(T);
//MidOrder(T);
//PostOrder(T);
#endif //DATASTRUCTURE_BITREE_H
