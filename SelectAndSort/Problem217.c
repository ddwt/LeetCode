void quick_sort(int *num, int l, int r) {
    if (l >= r) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1) return false;
    quick_sort(nums, 0, numsSize - 1);
    
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
}
