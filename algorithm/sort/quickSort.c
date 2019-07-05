void quickSort(int * num, int start, int end);

int* sortArray(int* nums, int numsSize, int* returnSize){
    quickSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}



void quickSort(int * num, int start, int end){
    if (start >= end)
        return;
    int temp = num[start];
    int i = start, k = end;
    while (i < k){
        for (k; num[k] >= temp && k > i; k--);
        num[i] = num[k];
        num[k] = temp;
        for (i; num[i] <= temp && i < k; i++);
        num[k] = num[i];
        num[i] = temp;
    }
    quickSort(num, start, i-1);
    quickSort(num, k+1, end);
}