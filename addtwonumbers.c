struct ListNode {
    int val;
    struct ListNode* next;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* stack = malloc(sizeof(struct ListNode));
    struct ListNode* StartOffStack = stack;
    int DoPlusOne = 0;
    int l1val;
    int l2val;
    while (l1 != NULL || l2 != NULL || DoPlusOne != 0) { 
        if (l1 == NULL) {
            l1val =  0;
        }
        else {
            l1val = l1->val;
        }
        if (l2 == NULL) {
            l2val =  0;
        }
        else {
            l2val = l2->val;
        }
        int num = (l1val + l2val + DoPlusOne);
        if (num >= 10) {
            DoPlusOne = 1;
            num = num % 10;
        }
        else {
            DoPlusOne = 0;
        }
        stack->val = num;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;

        if (l1 != NULL || l2 != NULL || DoPlusOne != 0){ 
            struct ListNode *nextAddres = malloc(sizeof(struct ListNode)); 
            stack->next = nextAddres;
            stack = stack->next;   
        }
        else {
            stack->next = NULL;
        }
    }
    struct ListNode* OutList;
    OutList = StartOffStack;
    return OutList;
}
int main(){
}
