char* reverseVowels(char* s) {
    int len = strlen(s);
    char *temp = (char *)malloc(len);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            temp[k++] = s[i];
        }
    }
    for (int i = 0; i < k / 2; i++) {
        char t = temp[i];
        temp[i] = temp[k - 1 - i];
        temp[k - 1 - i] = t;
    }
    k = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            s[i] = temp[k++];
        }
    }
    
    return s;
}
