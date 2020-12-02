void ChooseSort(int a[],int n){
    for(int i=0; i<n-1; i++){
        int index = i;
        for(int j =i+1;j<n; j++){
            if(a[j]<a[index]) index = j;
        }
        swap(&a[i],&a[index]);
    }
}