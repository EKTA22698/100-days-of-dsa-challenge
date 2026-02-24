/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node* createNode(int value) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertEnd(struct Node *head, int value) 
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
struct Node* deleteKey(struct Node *head, int key)
{
    struct Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == key) 
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) 
    {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, key;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    scanf("%d", &key);

    head = deleteKey(head, key);
    display(head);

    return 0;
}