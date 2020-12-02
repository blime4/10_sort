void CountSort(int a[],int n){
    if(n<2) return;
    int imax = amax(a,n);
    int temp[imax+1];
    memset(temp,0,sizeof(temp));
    int i,j,k;
    for(i=0;i<n;i++) temp[a[i]]++;
    i = 0;
    for(j=0;j<imax+1;j++){
        for(k=0;k<temp[j];k++) a[i++]=j;
    }
}

void CountSort_Optimizer(int a[],int n){
    if(n<2) return;
    int imin,imax;
    aminmax(a,n,&imin,&imax);
    int temp[imax-imin+1];
    memset(temp,0,sizeof(temp));
    int i,j,k;
    for(i=0;i<n;i++) temp[a[i]]++;
    i = 0;
    for(j=0;j<imax-imin+1;j++){
        for(k=0;k<temp[j];k++) a[i++]=j+imin;
    }
}