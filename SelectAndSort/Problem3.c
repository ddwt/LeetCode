int lengthOfLongestSubstring(char* s) {
    if (s == NULL) return 0;
    int len = strlen(s);
    //printf("len = %d\n", len);
    if (len == 1) return 1;
    int l = 0, r = 0, max_size = 0;
    int flag[10000] = {0};
    while (l < len && r < len) {
        if (flag[s[r] + 256]) {
            //printf("l = %d, r = %d\n", l, r);
            if (r - l > max_size) max_size = r - l;
            while (s[l] != s[r]) {
                flag[s[l] + 256] = 0;
                l++;
            }
            l++;
            r++;
        } else {
            flag[s[r] + 256] = 1;
            r++;
        }
    }
    if (len - l> max_size) max_size = len - l;
    return max_size;
}
