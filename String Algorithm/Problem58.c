int lengthOfLastWord(char* s) {
    if (s[0] == NULL) return 0;
    int len = strlen(s), flag = 0, size = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z') {
            if (flag == 0) 
                continue;
            else 
                break;
        }
        flag = 1;
        size += 1;
    }
    return size;
}
