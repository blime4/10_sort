int amax(int a[],int n) {
    int i,imax;
    imax = a[0];
    for(i =1; i < n; i++)
        if(a[i]>imax)imax =a[i];
    return imax;
}

void _RadixSort(int a[],int n,int exp){
    int i;
    int result[n]; //存放从桶中收集后数据的临时数组。
    int buckets[10]={0};
    // 遍历a，将数据出现的次数存储在buckets中。
    for(i=0; i<n; i++){
        buckets[(a[i]/exp)%10]++;
    }
    // 调整buckets各元素的值，调整后的值就是a中元素在result中的位置。
    for(i=1;i<10; i++){
        buckets[i] = buckets[i] + buckets[i-1];
    }
    // 将a中的元素填充到result中。
    for(i=n-1;i>=0;i--){
        int iexp = (a[i]/exp)%10;
        result[buckets[iexp]-1] = a[i];
        buckets[iexp]--;
    }
    // 将排序好的数组result复制到数组a中。    
    memcpy(a,result,n*sizeof(int));
}

void RadixSort(int a[],int n){
    int imax = amax(a,n);
    int iexp ;
    for(iexp = 1;imax/iexp>0;iexp *= 10){
        _RadixSort(a,n,iexp);
    }
}