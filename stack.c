#include <stdio.h>
#define MAX 7

typedef struct {
    int items[MAX];
    int top;
} Stack;
// stack operations
// 1. Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}
// 2. Check overflow
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
// 3. Check underflow
int isEmpty(Stack* s) {
    return s->top == -1;
}
// 4. Push operation
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->items[s->top] = item;
    return;
}
// 5. Pop operation
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("Popped item: %d\n", pop(&s));
    printf("Popped item: %d\n", pop(&s));
    
    return 0;
}