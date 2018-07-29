/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

int binary_search(int *num, int len, int target) {
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (num[mid] == target) return mid;
        else if (num[mid] > target) r = mid - 1;
        else l = mid;
    }
    return l;
}

int ind_select(int *num, int len, int target) {
    for (int i = 0; i < len; i++) {
        if (num[i] == target) return i;
    }
    return 0;
}

int ind2_select(int *num, int len, int target) {
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == target) return i;
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target) {
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    memcpy(temp, nums, sizeof(int) * numsSize);
    quick_sort(nums, 0, numsSize - 1);
    int l = 0, r = numsSize - 1;
    int *ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = 0;
    ret[1] = 0;
    while (l < r) {
        if (nums[l] + nums[r] == target) {
            ret[0] = ind_select(temp, numsSize, nums[l]);
            ret[1] = ind2_select(temp, numsSize, nums[r]);
            break;
        } else if (nums[l] + nums[r] < target) {
            l++;
        } else {
            r--;
        }
    }
    return ret;
}
