//
// Created by 46071 on 2020/2/29.
//

#ifndef DATASTRUCTURE_YUESEFU2_H
#define DATASTRUCTURE_YUESEFU2_H

/*约瑟夫游戏的大意：30个游客同乘一条船，因为严重超载， 加上风浪大作，危险万分。因此船长告诉乘客，
只有将全船 一半的旅客投入海中，其余人才能幸免于难。无奈，
大家只 得同意这种办法，并议定 30 个人围成一圈，由第一个人数
起，依次报数，数到第9人，便把他投入大海中，然后再从 他的下一个人数起，
数到第9人，再将他投入大海中，如此 循环地进行，直到剩下 15 个游客为止。
问：哪些位置是将 被扔下大海的位置？
不失一般性，将 30 改为一个任意输入的正整数 n，而报数 上限（原为9）也为一个任选的正整数k
 */
#include <stdio.h>
#include <stdlib.h>
const int MAX_SIZE = 100;
typedef struct {
    int data[MAX_SIZE];
    int length;
}SqList;
int Delete(SqList *Y,int i){
    int temp = Y->data[i];
    for(;i<Y->length-1;i++){
        Y->data[i] = Y->data[i+1];
    }
    Y->length--;
    return temp;
}
void Print(int array[],int length){
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
int* Yuesefu(int n,int k){
    SqList *Y = (SqList*)malloc(sizeof(SqList));
    for(int i=0;i<n;i++){
        Y->data[i]=i+1;
    }
    Y->length=n;
    int *result = (int*)malloc(15*sizeof(int));
    for(int i=k-1,j=0;Y->length>15;i=(i+k-1)%Y->length,j++){
        result[j]=Delete(Y,i);
    }
    return result;

}

//int main() {
//    int* result=Yuesefu(30,9);
//    Print(result,15);
//    return 0;
//}
#endif //DATASTRUCTURE_YUESEFU2_H
