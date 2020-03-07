
/*约瑟夫游戏的大意：30个游客同乘一条船，因为严重超载， 加上风浪大作，危险万分。因此船长告诉乘客，
只有将全船 一半的旅客投入海中，其余人才能幸免于难。无奈，
大家只 得同意这种办法，并议定 30 个人围成一圈，由第一个人数
起，依次报数，数到第9人，便把他投入大海中，然后再从 他的下一个人数起，
数到第9人，再将他投入大海中，如此 循环地进行，直到剩下 15 个游客为止。
问：哪些位置是将 被扔下大海的位置？
不失一般性，将 30 改为一个任意输入的正整数 n，而报数 上限（原为9）也为一个任选的正整数k
 */

//存在问题，如何返回被删除的值

#ifndef DATASTRUCTURE_YUSEFU_H
#define DATASTRUCTURE_YUSEFU_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int num;
    struct node *next;
}Person;

Person* initList(int n){
    Person *header = (Person*)malloc(sizeof(Person));
    header->num = 1;
    Person *tail = (Person*)malloc(sizeof(Person));
    tail->num = n;
    tail->next = header;
    header->next = tail;
    for(int i=n-1;i>1;i--){
        Person *newnode = (Person*)malloc(sizeof(Person));
        newnode->num = i;
        newnode->next = header->next;
        header->next = newnode;
    }
    return header;
}

int getLength(Person *header){
    int len = 0;Person *p= header;
    while(p->next!=header){
        len++;
        p=p->next;
    }
    return len+1;
}
void Print(int array[],int length){
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void printList(Person *header){
    Person *p = header;
    while(p->next!= header){
        printf("%d->",p->num);
        p=p->next;
    }
    printf("%d->\n",p->num);
}

int deleteNode(Person *&p,int n){
    for(int i=2;i<n;i++)p=p->next;
    Person *q = p->next;
    int num=q->num;
    p->next = q->next;
    free(q);
    p=p->next;
    return num;
}

int* Yuesefu(int n,int k){
    Person *L = initList(n);
    static int result[15];
    int i=0;Person* rec = L;
    while(getLength(L)>15){
        result[i]=deleteNode(rec,k);
        i++;
    }
    return result;

}
//int main() {
//    int* result=Yuesefu(30,9);
//    Print(result,15);
//    return 0;
//}
#endif //DATASTRUCTURE_YUSEFU_H
