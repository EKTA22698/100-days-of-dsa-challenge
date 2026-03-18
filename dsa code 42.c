/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int top;
    int capacity;
    int* arr;
};

// Queue structure
struct Queue {
    int front, rear, size, capacity;
    int* arr;
};

// Stack functions
struct Stack* createStack(int capacity) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(capacity * sizeof(int));
    return s;
}

void push(struct Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

// Queue functions
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

void enqueue(struct Queue* q, int x) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(struct Queue* q) {
    int x = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
}

// Reverse queue using stack
void reverseQueue(struct Queue* q) {
    struct Stack* s = createStack(q->capacity);

    // Step 1: Push all queue elements into stack
    while (q->size > 0) {
        push(s, dequeue(q));
    }

    // Step 2: Push back to queue
    while (s->top != -1) {
        enqueue(q, pop(s));
    }

    free(s->arr);
    free(s);
}

// Main
int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue(N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    reverseQueue(q);

    // Print reversed queue
    while (q->size > 0) {
        printf("%d ", dequeue(q));
    }

    return 0;
}