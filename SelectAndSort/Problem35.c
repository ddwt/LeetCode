int searchInsert(int* nums, int numsSize, int target) {
    if (target > nums[numsSize - 1]) return numsSize;
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target) 
            r = mid - 1;
        else
            l = mid + 1;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > target) return i; 
    }
    return 0;
}
