#include <stdio.h>
#define MAX 7

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;
// queue operations
// 1. Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
// 2. Check overflow
bool isFull(Queue* q) {
    return q->rear == MAX - 1;
}
// 3. Check underflow
bool isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}
// 4. push operation
void push(Queue* q, int item) {  
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
    return;
}

// 5. pop operation
int pop(Queue* q) { 
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->items[q->front++];
}

int main() {
    Queue q;
    initQueue(&q);
    
    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    
    printf("Popped item: %d\n", pop(&q));
    printf("Popped item: %d\n", pop(&q));
    
    return 0;
}