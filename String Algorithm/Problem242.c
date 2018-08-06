bool isAnagram(char* s, char* t) {
    int len1 = strlen(s), len2 = strlen(t);
    if (len1 != len2) return false;
    int flag1[128] = {0};
    int flag2[128] = {0};
    for (int i = 0; s[i]; i++) {
        flag1[s[i]] += 1;
    }
    for (int i = 0; t[i]; i++) {
        flag2[t[i]] += 1;
    }
    int k = 0;
    
    for (int i = 0; s[i]; i++) {
        if (flag1[s[i]] != flag2[s[i]]) return false;
    }
    return true;
}
