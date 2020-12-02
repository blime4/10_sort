#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int tempArr[],int left,int mid,int right){

    int l_pos = left;
    int r_pos = right;
    int pos = left;

    while(l_pos<=mid && r_pos<=right){
        if(a[l_pos]<a[r_pos]) tempArr[pos++]=a[l_pos++];
        else tempArr[pos++]=a[r_pos++];
    }

    //左半区未空
    while(l_pos<=mid){
        tempArr[pos++]=a[l_pos++];
    }
    while(r_pos<=right){
        tempArr[pos++]=a[r_pos++];
    }
    //复制回来
    while(left<=right){
        a[left]=tempArr[left];
        left++;
    }

}

void msort(int a[],int tempArr[],int left,int right){
    // 如果只有一个元素，就不用再划分
    if(left < right){
        int mid = (left + right)/2;
        msort(a,tempArr,left,mid);
        msort(a,tempArr,mid+1,right);
        merge(a,tempArr,left,mid,right);
    }
}

void MergeSort(int a[],int n){
    
    //分配一个辅助数组
    int *tempArr = (int*)malloc(n*sizeof(int));
    if(tempArr){
        msort(a,tempArr,0,n-1);
        free(tempArr);
    }else{
        printf("error: failed to allocate memory!")
    }
}