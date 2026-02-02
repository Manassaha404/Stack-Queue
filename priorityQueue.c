#include <stdio.h>
#define MAX 7

typedef struct {
    int items[MAX][2]; // [0] for item, [1] for priority
    int front;
    int rear;
} PriorityQueue;

// 1. Initialize
void initPriorityQueue(PriorityQueue* pq) {
    pq->front = -1;
    pq->rear = -1;
}

// 2. overflow check
int isFull(PriorityQueue* pq) { 
    return pq->rear == MAX - 1; 
} 


// 3. underflow check
int isEmpty(PriorityQueue* pq) {    
    return pq->front == -1 || pq->front > pq->rear; 
}


// 4. Push operation with priority
void push(PriorityQueue* pq, int item, int priority){
    if (isFull(pq)) {
        printf("Priority Queue Overflow\n");
        return;
    }
    //first element insertion
    if(pq->front == -1) {
        pq->front = 0;
        pq->rear = 0;
        pq->items[pq->rear][0] = item;
        pq->items[pq->rear][1] = priority; // add priority
        return;
    }
    
    pq->rear++;
    pq->items[pq->rear][0] = item;
    pq->items[pq->rear][1] = priority; // add priority
    return;
}

// 5. Pop operation based on priority
int pop(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue Underflow\n");
        return -1;
    }
    // Find the item with the highest priority (lowest priority number)
    int highestPriorityIndex = pq->front;
    for (int i = pq->front; i <= pq->rear; i++) {
        if (pq->items[i][1] < pq->items[highestPriorityIndex][1]) {
            highestPriorityIndex = i;
        }
    }
    int item = pq->items[highestPriorityIndex][0];
    // Shift items to fill the gap
    for (int i = highestPriorityIndex; i < pq->rear; i++) {
        pq->items[i][0] = pq->items[i + 1][0];
        pq->items[i][1] = pq->items[i + 1][1];
    }
    pq->rear--;
    // Adjust front and rear if the queue is empty
    if (pq->rear < pq->front) {
        pq->front = -1;
        pq->rear = -1;
    }
    return item;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue contents:\n");
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("Item: %d, Priority: %d\n", pq->items[i][0], pq->items[i][1]);
    }
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);
    
    push(&pq, 10, 2);
    push(&pq, 20, 1);
    push(&pq, 30, 3);
    
    display(&pq);
    
    printf("Popped item: %d\n", pop(&pq));
    printf("Popped item: %d\n", pop(&pq));
    
    display(&pq);
    
    return 0;
}