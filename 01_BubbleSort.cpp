void BubbleSort(vector<int> &vec){
    int length = vec.size();
    if(length <= 1){
        return;
    }
    int sortBorder = length - 1; // 记录比较的边界，也是右边界
    int lastExchangeIndex = 0; // 记录最后一次元素交换的位置
    while(sortBorder > 0){
        bool isSorted = true;
        for(int i = 0; i < sortBorder; i++){
            if(vec[i] > vec[i+1]){
                swap(vec[i], vec[i+1]);
                isSorted = false;
                lastExchangeIndex = i;
            }
        }
        if(isSorted) break;
        sortBorder = lastExchangeIndex;
    }
}