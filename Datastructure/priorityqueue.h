//菜单内容：
//1. 优先队列的插入操作
//2. 最大优先级元素出队列操作
//3. 调整优先队列某个元素的优先级
//4. 求优先队列的长度
//5. 优先队列的查询操作
//6. 退出系统
//        请选择：1 – 6
#ifndef DATASTRUCTURE_PRIORITYQUEUE_H
#define DATASTRUCTURE_PRIORITYQUEUE_H


#include <stdio.h>
#include <stdlib.h>
const int MAX_SIZE = 20;
typedef struct node{
    int key;
}Element;
typedef struct {
    Element*  heap[MAX_SIZE];
    int length;
}PriQueue;
PriQueue* InitPriQueue(int keys[],int length){
    PriQueue *Q = (PriQueue*)malloc(sizeof(PriQueue));
    for(int i=1;i<=length;i++){
        Q->heap[i] = (Element*)malloc(sizeof(Element));
        Q->heap[i]->key=keys[i];
    }
    Q->length=length;
    return Q;
}
void PrintHeap(PriQueue *&Q){
    for(int i=1;i<=Q->length;i++){
        if(i==1){
            printf("       %d   \n",Q->heap[i]->key);
        }else if(i==2||i==3){
            printf("    %d",Q->heap[i]->key);
            if(i==3)printf("\n");
        }else if(i>3&&i<8){
            printf("  %d",Q->heap[i]->key);
            if(i==7)printf("\n");
        }else if(i>=8&&i<16){
            printf(" %d",Q->heap[i]->key);
            if(i==16)printf("\n");
        }
    }
    printf("\n");
}
void HeapAdjust(PriQueue *&Q,int parent,int last){
    Element* temp=Q->heap[parent];
    for (int j=2*parent; j<=last; j*=2) {
        if (j+1<last && (Q->heap[j]->key<Q->heap[j+1]->key)) {
            j++;
        }
        if (temp->key>=Q->heap[j]->key) {
            break;
        }
        Q->heap[parent]=Q->heap[j];
        parent=j;
    }
    Q->heap[parent]=temp;
}
void Swap(Element **a,Element **b){
    Element* temp=*a;
    *a=*b;
    *b=temp;
}
void HeapSort(PriQueue *&Q){
    for (int i=Q->length/2; i>0; i--) {
        HeapAdjust(Q, i, Q->length);
    }
    for (int i=Q->length; i>1; i--) {
        Swap(&Q->heap[1], &Q->heap[i]);
        HeapAdjust(Q, 1, i-1);
    }
}
void InsertElement(PriQueue *&Q,Element *e)
{
    Q->heap[++Q->length]=e;
}
Element DeleteElement(PriQueue *&Q){
    Element min,*last_element;
    min = *Q->heap[1];last_element=Q->heap[Q->length];	//保存最小值
    free(Q->heap[1]);
    Q->heap[1]=last_element;
    Q->length--;    //堆中元素数目减1
    printf("%d",Q->length);
    return min;
}
void AdjustElement(PriQueue *&Q,int index,int key){
    Q->heap[index]->key = key;
}
void Print(PriQueue *&Q){
    for(int i=1;i<=Q->length;i++){
        printf("%d ",Q->heap[i]->key);
    }
    printf("\n");
}
void UserInterface(PriQueue *&Q){
    int selection = 0;
    while(true){
        Print(Q);
        PrintHeap(Q);
        printf("菜单内容:\n");
        printf("1.优先队列的插入操作\n");
        printf("2.最大优先级元素出队列操作\n");
        printf("3.调整优先队列某个元素的优先级\n");
        printf("4.求优先队列的长度\n");
        printf("5.优先队列的查询操作\n");
        printf("6.退出系统\n");
        printf("请选择:1 - 6:");
        scanf("%d",&selection);
        switch (selection){
            case 1:{
                Element *e=(Element*)malloc(sizeof(Element));
                printf("请输入插入元素的优先级:");
                scanf("%d",&(e->key));
                InsertElement(Q,e);
                HeapSort(Q);
                break;
            }
            case 2: {
                Element e = DeleteElement(Q);
                HeapSort(Q);
                printf("优先级为%d的元素已出队\n",e.key);
                break;
            }
            case 3:{
                int index = 0;int key=0;
                printf("请输入调整优先级元素的序号:");
                scanf("%d",&index);
                printf("请输入调整后的优先级:");
                scanf("%d",&key);
                AdjustElement(Q,index,key);
                HeapSort(Q);
                break;
            }
            case 4:
                printf("优先队列的长度为:%d\n",Q->length);
                break;
            case 5:
                HeapSort(Q);
                Print(Q);
                break;
            case 6:
                exit(0);
            default:
                printf("请输入正确的选项！\n");
                break;
        }
    }

}
//int main() {
//    int keys[9] = {NULL,49,38,65,97,76,13,27,49};
//    PriQueue *Q = InitPriQueue(keys,8);
//    HeapSort(Q);
//    UserInterface(Q);
//    return 0;
//}


#endif //DATASTRUCTURE_PRIORITYQUEUE_H
