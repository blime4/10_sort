void InsertSort(int a[],int length){
    int i,j;
    for(i = 1; i < length; i++){
        int tmp = a[i];
        for(j = 0; j >0 && a[j-1]>tmp; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}