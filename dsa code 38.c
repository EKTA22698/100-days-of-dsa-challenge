/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize
void init(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// Check full
bool full(Deque* dq) {
    return dq->size == MAX;
}

// push_front
void push_front(Deque* dq, int x) {
    if (full(dq)) return;

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = x;
    dq->size++;
}

// push_back
void push_back(Deque* dq, int x) {
    if (full(dq)) return;

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = x;
    dq->size++;
}

// pop_front
void pop_front(Deque* dq) {
    if (empty(dq)) return;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }

    dq->size--;
}

// pop_back
void pop_back(Deque* dq) {
    if (empty(dq)) return;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }

    dq->size--;
}

// front element
int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

// rear element
int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

// size
int size(Deque* dq) {
    return dq->size;
}

// clear
void clear(Deque* dq) {
    dq->front = dq->rear = -1;
    dq->size = 0;
}

// display
void display(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// reverse (simple)
void reverse(Deque* dq) {
    int i = dq->front;
    int j = dq->rear;

    for (int count = 0; count < dq->size / 2; count++) {
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

// sort (simple bubble sort)
void sortDeque(Deque* dq) {
    int temp[MAX];
    int idx = 0;

    int i = dq->front;
    while (1) {
        temp[idx++] = dq->arr[i];
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }

    // bubble sort
    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j < idx - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    // copy back
    dq->front = 0;
    dq->rear = idx - 1;
    dq->size = idx;

    for (int i = 0; i < idx; i++) {
        dq->arr[i] = temp[i];
    }
}

// MAIN (Demo)
int main() {
    Deque dq;
    init(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_back(&dq, 30);

    display(&dq);   // 5 10 20 30

    pop_front(&dq);
    pop_back(&dq);

    display(&dq);   // 10 20

    printf("Front: %d\n", front(&dq));
    printf("Rear: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    reverse(&dq);
    display(&dq);

    clear(&dq);
    printf("Empty: %d\n", empty(&dq));

    return 0;
}