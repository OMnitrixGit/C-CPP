//
// Created by 46071 on 2020/2/25.
//

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
#endif //DATASTRUCTURE_YUSEFU_H
