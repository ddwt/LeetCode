double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *temp = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    int x = 0, y = 0, k = 0;
    while (x < nums1Size || y < nums2Size) {
        if (y >= nums2Size || (x < nums1Size && nums1[x] <= nums2[y])) {
            temp[k++] = nums1[x++];
        } else {
            temp[k++] = nums2[y++];
        }
    }
    int size = nums1Size + nums2Size;
    printf("%d\n", size);
    double ans = 0;
    if (size % 2 == 0) {
        ans = (double)(temp[size / 2] + temp[size / 2 - 1])/ 2;
    } else {
        ans = (double)(temp[size / 2]);
    }
    return ans;
}
