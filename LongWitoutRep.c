int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int lastIndex[256]; // store last index of each character
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0; // start of current window

    for (int end = 0; end < n; end++) {
        char c = s[end];

        // If character already seen, move start
        if (lastIndex[(unsigned char)c] >= start) {
            start = lastIndex[(unsigned char)c] + 1;
        }

        lastIndex[(unsigned char)c] = end;

        int len = end - start + 1;
        if (len > maxLen) maxLen = len;
    }

    return maxLen;
   } 
}   
