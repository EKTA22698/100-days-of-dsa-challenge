/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void append(struct node **head, int data) 
{
    struct node* temp = newNode(data);
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
int findIntersection(struct node* h1, struct node* h2) 
{
    struct node *p1, *p2;
    for (p1 = h1; p1 != NULL; p1 = p1->next) 
    {
        for (p2 = h2; p2 != NULL; p2 = p2->next)
        {
            if (p1->data == p2->data)
                return p1->data;  
        }
    }
    return -1;
}
int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        append(&head1, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        append(&head2, x);
    }

    int ans = findIntersection(head1, head2);
    if (ans != -1)
        printf("%d", ans);
    else
        printf("No Intersection");

    return 0;
}