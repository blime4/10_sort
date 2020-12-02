void BubbleSort(vector<int> &vec){
    int length = vec.size();
    if(length <= 1){
        return;
    }
    int sortBorder = length - 1; // ��¼�Ƚϵı߽磬Ҳ���ұ߽�
    int lastExchangeIndex = 0; // ��¼���һ��Ԫ�ؽ�����λ��
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