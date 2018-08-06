bool isPalindrome(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    int l = 0, r = len - 1;
    int flag = 1;
    while (l <= r) {
        if (s[l] < '0' || (s[l] > '9' && s[l] < 'A') || (s[l] > 'Z' && s[l] < 'a') || s[l] > 'z') {l++; continue;}
        if (s[r] < '0' || (s[r] > '9' && s[r] < 'A') || (s[r] > 'Z' && s[r] < 'a') || s[r] > 'z') {r--; continue;}
        if (s[r] == s[l]) {
            l++, r--;
            continue;
        }
        return false;
    }
    return true;
}
