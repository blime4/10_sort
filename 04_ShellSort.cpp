void ShellSort(int a[],int n){
    int i,j,inc,key;
    for(inc = n ; inc > 0 ; inc /= 2){
        //每一趟采用插入排序
        for(i = inc ; i < n ; i++){
            key = a[i];
            for(j = i ; j>= inc&&key<a[j-inc]; j-=inc){
                a[j] = a[j-inc];
            }
            a[j] = key;
        }
    }
}