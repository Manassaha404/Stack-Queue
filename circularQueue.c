#include <stdio.h>
#define MAX 5
typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;
// circular queue operations
// 1. Initialize the circular queue
void initCircularQueue(CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}
// 2. Check overflow
int isFull(CircularQueue* cq) {
    return (cq->rear + 1) % MAX == cq->front;
}   
// 3. Check underflow
int isEmpty(CircularQueue* cq) {
    return cq->front == -1;
}
// 4. push operation
void push(CircularQueue* cq, int item) {  
    if (isFull(cq)) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX;
    cq->items[cq->rear] = item;
    return;
}   
// 5. pop operation
int pop(CircularQueue* cq) {    
    if (isEmpty(cq)) {
        printf("Circular Queue Underflow\n");
        return -1;
    }
    int item = cq->items[cq->front];
    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX;
    }
    return item;
}
int main() {
    CircularQueue cq;
    initCircularQueue(&cq);
    
    push(&cq, 10);
    push(&cq, 20);
    push(&cq, 30);
    push(&cq, 40);
    push(&cq, 50);
    push(&cq, 50); // overflow test
    
    printf("Popped item: %d\n", pop(&cq));
    printf("Popped item: %d\n", pop(&cq));
    printf("Popped item: %d\n", pop(&cq));
    printf("Popped item: %d\n", pop(&cq));
    printf("Popped item: %d\n", pop(&cq));

    push(&cq, 60);
    push(&cq, 70);

    printf("Popped item: %d\n", pop(&cq));
    printf("Popped item: %d\n", pop(&cq));



    
    return 0;
}