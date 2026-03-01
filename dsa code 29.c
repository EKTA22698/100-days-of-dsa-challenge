/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void append(struct node **head, int data) 
{
    struct node* temp = createNode(data);
    if (*head == NULL) 
    {
        *head = temp;
        return;
    }
    struct node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}
void rotateRight(struct node **head, int k) 
{
    if (*head == NULL || k == 0)
        return;
    struct node *curr = *head;
    int len = 1;
    while (curr->next != NULL)
    {
        curr = curr->next;
        len++;
    }

    k = k % len;
    if (k == 0)
        return;
    curr->next = *head;
    int steps = len - k;
    while (steps--) {
        curr = curr->next;
    }
    *head = curr->next;
    curr->next = NULL;
}

int main() 
{
    struct node *head = NULL;
    int n, x, k;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }
    scanf("%d", &k);
    rotateRight(&head, k);
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}