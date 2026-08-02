void reverse_in_place(char *str) {
    int left = 0;
    int right = string_length(str) - 1;
    
    while (left < right) {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        left++;
        right--;
    }
}
