/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};

int main()
{
    int n, i, val;
    struct Node *head = NULL, *temp = NULL, *newnode;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) 
        {
            head = newnode;
            temp = head;
        } 
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}