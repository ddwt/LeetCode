void merge(int* nums1, int m, int* nums2, int n) {
    int *temp = (int *)malloc(sizeof(int) * (m + n));
    int ind1 = 0, ind2 = 0, k = 0;
    while (ind1 < m || ind2 < n) {
        if (ind2 >= n || (ind1 < m && nums1[ind1] <= nums2[ind2])) 
            temp[k++] = nums1[ind1++];
        else 
            temp[k++] = nums2[ind2++];
    }
    for (int i = 0; i < m + n; i++) {
        printf("%d", temp[i]);
    }
    memcpy(nums1, temp, sizeof(int) * (m + n));
    free(temp);
}
