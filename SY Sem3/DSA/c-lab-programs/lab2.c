#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <ctype.h>

struct Node
{
    char name[15];
    int roll, age;
    float avg;
    struct Node *next;
} * head, *currNode, *temp, *ptr;
int numberOfElements = 0;
void create();
void insert();
void addStart();
void addEnd();
void addIntermediate();
void delete ();
void deleteStart();
void deleteEnd();
void deleteIntermediate();
void display();

int main()
{
    head = NULL;
    int ch = 0;
    int num;
    printf("Enter number of prefilled items to be added: ");
    scanf("%d", &num);
    numberOfElements = num;
    for (int i = 0; i < num; i++)
    {
        create();
    }
    while (ch != 4)
    {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Quit");
        printf("\nEnter your choice from 1-4: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;

        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("\nEnter your choice from 1-4 only");
            continue;
        }
    }
    printf("Thank you");
    return 0;
}
void create()
{
    ptr = (struct Node *)malloc(sizeof(struct Node));
    currNode = head;
    printf("\nEnter name: ");
    scanf("%s", ptr->name);
    printf("Enter roll no. : ");
    scanf("%d", &ptr->roll);
    printf("Enter age: ");
    scanf("%d", &ptr->age);
    printf("Enter average: ");
    scanf("%f", &ptr->avg);
    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
    }
    else
    {
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = ptr;
        ptr->next = NULL;
    }
}
void insert()
{
    int ch = 0;
    while (ch != 4)
    {
        printf("\n\n1. Add at start");
        printf("\n2. Add at end");
        printf("\n3. Add at intermediate");
        printf("\n4. back");
        printf("\nEnter your choice from 1-4: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addStart();
            break;
        case 2:
            addEnd();
            break;
        case 3:
            addIntermediate();
            break;

        case 4:
            break;
        default:
            printf("\nEnter your choice from 1-4 only");
            break;
        }
    }
}
void addStart()
{
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter name: ");
    scanf("%s", ptr->name);
    printf("Enter roll no. : ");
    scanf("%d", &ptr->roll);
    printf("Enter age: ");
    scanf("%d", &ptr->age);
    printf("Enter average: ");
    scanf("%f", &ptr->avg);
    ptr->next = head;
    head = ptr;
    numberOfElements++;
    printf("\nAdded a new elemnt\n");
}
void addEnd()
{
    if (head != NULL)
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        currNode = head;
        printf("\nEnter name: ");
        scanf("%s", ptr->name);
        printf("Enter roll no. : ");
        scanf("%d", &ptr->roll);
        printf("Enter age: ");
        scanf("%d", &ptr->age);
        printf("Enter average: ");
        scanf("%f", &ptr->avg);
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = ptr;
        ptr->next = NULL;
        numberOfElements++;
        printf("\nAdded a new elemnt\n");
    }
    else
    {
        addStart();
    }
}
void addIntermediate()
{
    ptr = (struct Node *)malloc(sizeof(struct Node));
    currNode = head;
    int pos, count = 1;
    printf("\nEnter position where you want to add the element[starts from 1]: ");
    scanf("%d", &pos);
    if (pos > 1)
    {
        while (count != (pos - 1) && currNode->next != NULL)
        {
            currNode = currNode->next;
            count++;
        }

        if (count == pos - 1)
        {
            printf("\nEnter name: ");
            scanf("%s", ptr->name);
            printf("Enter roll no. : ");
            scanf("%d", &ptr->roll);
            printf("Enter age: ");
            scanf("%d", &ptr->age);
            printf("Enter average: ");
            scanf("%f", &ptr->avg);
            ptr->next = currNode->next;
            currNode->next = ptr;
            numberOfElements++;
            printf("\nAdded a new elemnt\n");
        }
        else
        {
            printf("\nPosition not found, please enter a valid position\n");
        }
    }
    else if (pos == 1)
    {
        addStart();
    }
    else
    {
        printf("\nPosition not found, please enter a valid position\n");
    }
}
// ------------------Delete Functions------------------------
void delete ()
{
    int ch = 0;
    while (ch != 4)
    {
        printf("\n\n1. Delete at start");
        printf("\n2. Delete at end");
        printf("\n3. Delete at intermediate");
        printf("\n4. back");
        printf("\nEnter your choice from 1-4: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            deleteStart();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            deleteIntermediate();
            break;

        case 4:
            break;
        default:
            printf("\nEnter your choice from 1-4 only");
            break;
        }
    }
}
void deleteStart()
{
    if (head != NULL)
    {
        currNode = head;
        head = currNode->next;
        currNode->next = NULL;
        printf("\nDeleted the elemnt\n");
        printf("%s\n", currNode->name);
        printf("%d\n", currNode->roll);
        printf("%d\n", currNode->age);
        printf("%f\n\n", currNode->avg);
        free(currNode);
        numberOfElements--;
    }
    else
    {
        printf("\nEmpty Linked List\n");
    }
}
void deleteEnd()
{
    if (head != NULL)
    {
        if (numberOfElements != 1)
        {
            currNode = head;
            while (currNode->next->next != NULL)
            {
                currNode = currNode->next;
            }
            ptr = currNode->next;
            currNode->next = NULL;
            printf("\nDeleted the elemnt\n");
            printf("%s\n", ptr->name);
            printf("%d\n", ptr->roll);
            printf("%d\n", ptr->age);
            printf("%f\n\n", ptr->avg);
            free(ptr);
            numberOfElements--;
        }
        else
        {
            deleteStart();
        }
    }
    else
    {
        printf("\nEmpty Linked List\n");
    }
}
void deleteIntermediate()
{
    currNode = head;
    int pos, count = 1;
    printf("\nEnter position where you want to delete the element: ");
    scanf("%d", &pos);
    if (pos > numberOfElements)
    {
        printf("\nPosition not found, please enter a valid position\n");
    }
    else if (pos > 1)
    {
        printf("273");
        while (count != (pos - 1))
        {
            currNode = currNode->next;
            count++;
        }
        if (pos > numberOfElements)
        {
            printf("\nPosition not found, please enter a valid position\n");
        }
        else if (count == (pos - 1))
        {
            ptr = currNode->next;
            currNode->next = ptr->next;
            ptr->next = NULL;
            printf("\nDeleted the elemnt\n");
            printf("%s\n", ptr->name);
            printf("%d\n", ptr->roll);
            printf("%d\n", ptr->age);
            printf("%f\n\n", ptr->avg);
            free(ptr);
            numberOfElements--;
        }
        else
        {
            printf("\nPosition not found, please enter a valid position\n");
        }
    }
    else if (pos == 1)
    {
        deleteStart();
    }
    else
    {
        printf("\nPosition not found, please enter a valid position\n");
    }
}
// -----------------------------------------------------------

void display()
{
    if (head != NULL)
    {

        currNode = head;
        // printf(numberOfElements);
        if (currNode->next == NULL)
        {
            printf("\n%-10s\t", currNode->name);
            printf("%-10d\t", currNode->roll);
            printf("%-10d\t", currNode->age);
            printf("%-10.2f\t", currNode->avg);
        }
        else
        {
            while (currNode != NULL)
            {
                printf("\n%-10s\t", currNode->name);
                printf("%-10d\t", currNode->roll);
                printf("%-10d\t", currNode->age);
                printf("%-10.2f\t", currNode->avg);
                currNode = currNode->next;
            }
        }
    }
    else
    {
        printf("\nEmpty Linked List\n");
    }
}