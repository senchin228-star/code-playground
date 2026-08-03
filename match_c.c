#include <stdio.h>
int match(const char* str, const char* pat) 
{
    int i;
    for (;; str++, pat++){
        switch(*pat){
            case 0:
                if (*str) return 0;
                else return 1;
                break;
            case '*':
                for (i = 0;; i ++){
                    if (match(str + i, pat + 1)){
                        return 1;
                    }
                    if(!str[i]){
                        return 0;
                    }
                }
                break;
            case '?':
                    if (!*str) return 0;
                    break;
            default:
                    if (*pat != *str){
                        return 0;
                    }
                    break;
        }
    }
}
int main(int argc, char** argv)
{
    if (argc != 3){
        printf("the wrong number of arguments");
        return 0;
    }
    if (match(argv[1], argv[2])){
        printf("True");
    }
    else
    {
        printf("False");
    }
}


