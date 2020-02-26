//
// Created by 46071 on 2020/2/26.
//

#ifndef ALGORITHM_RECURSION_H
#define ALGORITHM_RECURSION_H

#include <bits/stdc++.h>
//全排列
using namespace std;
void Perm(int list[],int k,int m){
    if(k==m){
        for(int i = 0;i <= m;i++)cout<<list[i];
        cout<<endl;
    }else{
        for(int i=k;i<=m;i++){
            swap(list[k],list[i]);
            Perm(list,k+1,m);
            swap(list[k],list[i]);
        }
    }
}
//求数组最大(最小值)
int maxRec(int A[],int i){
    if(i==1){
        return A[0];
    }else{
        int k = maxRec(A,i-1);
        if(k<A[i-1]){
            return A[i-1];
        }else{
            return k;
        }
    }
}
#endif //ALGORITHM_RECURSION_H
