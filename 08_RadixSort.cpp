int amax(int a[],int n) {
    int i,imax;
    imax = a[0];
    for(i =1; i < n; i++)
        if(a[i]>imax)imax =a[i];
    return imax;
}

void _RadixSort(int a[],int n,int exp){
    int i;
    int result[n]; //��Ŵ�Ͱ���ռ������ݵ���ʱ���顣
    int buckets[10]={0};
    // ����a�������ݳ��ֵĴ����洢��buckets�С�
    for(i=0; i<n; i++){
        buckets[(a[i]/exp)%10]++;
    }
    // ����buckets��Ԫ�ص�ֵ���������ֵ����a��Ԫ����result�е�λ�á�
    for(i=1;i<10; i++){
        buckets[i] = buckets[i] + buckets[i-1];
    }
    // ��a�е�Ԫ����䵽result�С�
    for(i=n-1;i>=0;i--){
        int iexp = (a[i]/exp)%10;
        result[buckets[iexp]-1] = a[i];
        buckets[iexp]--;
    }
    // ������õ�����result���Ƶ�����a�С�    
    memcpy(a,result,n*sizeof(int));
}

void RadixSort(int a[],int n){
    int imax = amax(a,n);
    int iexp ;
    for(iexp = 1;imax/iexp>0;iexp *= 10){
        _RadixSort(a,n,iexp);
    }
}