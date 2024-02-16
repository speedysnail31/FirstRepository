#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
char letter;
struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    if (head == NULL)
    {
        return 0;
    }

    int counter = 0;
    node* temp = head;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    node* temp = head;
    int size = length(temp);
    char* string = malloc((size+1) * sizeof(char));
    string[0] = '\0';
    for (int i = 0; i<size; i++)
    {
        strncat(string, &(temp->letter), 1);
        temp = temp -> next;
    }
    return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* temp;
    node* newNode = (node *)malloc(sizeof(node));
    newNode -> letter = c;
    newNode -> next = NULL;

    if (*pHead == NULL)
    {
        *pHead = newNode;
    }
    
    else
    {
        temp = *pHead;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* current = *pHead;
    node* temp;

    while (current != NULL)
    {
        temp = current -> next;
        free(current);
        current = temp;
    }
    *pHead = NULL;
}

int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}

str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}
