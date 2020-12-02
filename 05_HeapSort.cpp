
//ά����


void heapify(int a[],int n, int i){
    int largest = i;
    int lson = i*2+1;
    int rson = i*2+2;
    if(lson < n && a[largest] < lson) largest = lson;
    if(rson < n && a[largest] < rson) largest = rson;
    if(largest != i){
        swap(&a[largest], &a[i]);
        heapify(a, n, largest);
    }
}


//������
void HeapSort(int a[],int n){
    //����
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    //����
    for(i=n-1;i>=0;i--){
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }

}