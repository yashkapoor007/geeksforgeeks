// C/C++ program to find a triplet from three linked lists with
// sum equal to a given number
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

/* A utility function to insert a node at the beginning of a
   linked list*/
void push (struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A function to chech if there are three elements in a, b
   and c whose sum is equal to givenNumber.  The function
   assumes that the list b is sorted in ascending order
   and c is sorted in descending order. */
bool isSumSorted(struct Node *headA, struct Node *headB,
                 struct Node *headC, int givenNumber)
{
    struct Node *a = headA;

    // Traverse through all nodes of a
    while (a != NULL)
    {
        struct Node *b = headB;
        struct Node *c = headC;

        // For every node of list a, prick two nodes
        // from lists b abd c
        while (b != NULL && c != NULL)
        {
            // If this a triplet with given sum, print
            // it and return true
            int sum = a->data + b->data + c->data;
            if (sum == givenNumber)
            {
               printf ("Triplet Found: %d %d %d ", a->data,
                                         b->data, c->data);
               return true;
            }

            // If sum of this triplet is smaller, look for
            // greater values in b
            else if (sum < givenNumber)
                b = b->next;
            else // If sum is greater, look for smaller values in c
                c = c->next;
        }
        a = a->next;  // Move ahead in list a
    }

    printf ("No such triplet");
    return false;
}


/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* headA = NULL;
    struct Node* headB = NULL;
    struct Node* headC = NULL;

    /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);

    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);

    /*create another sorted linked list 'c' 8->4->2->1 */
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);

    int givenNumber = 25;

    isSumSorted (headA, headB, headC, givenNumber);

    return 0;
}
