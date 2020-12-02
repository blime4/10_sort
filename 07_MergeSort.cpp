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

    //�����δ��
    while(l_pos<=mid){
        tempArr[pos++]=a[l_pos++];
    }
    while(r_pos<=right){
        tempArr[pos++]=a[r_pos++];
    }
    //���ƻ���
    while(left<=right){
        a[left]=tempArr[left];
        left++;
    }

}

void msort(int a[],int tempArr[],int left,int right){
    // ���ֻ��һ��Ԫ�أ��Ͳ����ٻ���
    if(left < right){
        int mid = (left + right)/2;
        msort(a,tempArr,left,mid);
        msort(a,tempArr,mid+1,right);
        merge(a,tempArr,left,mid,right);
    }
}

void MergeSort(int a[],int n){
    
    //����һ����������
    int *tempArr = (int*)malloc(n*sizeof(int));
    if(tempArr){
        msort(a,tempArr,0,n-1);
        free(tempArr);
    }else{
        printf("error: failed to allocate memory!")
    }
}