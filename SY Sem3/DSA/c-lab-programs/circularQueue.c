#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
int arr[maxsize];
int front, rear, count;

void createQueue();
void Enqueue();
void Dequeue();
void getFront();
void getRear();
void display();
int IsEmpty();
int IsFull();

int main()
{
    int ch = 0;
    printf("\n======= Circular Queue Implementation =======\n");
    while (ch != 10)
    {
        printf("\n\n1. Create a Queue");
        printf("\n2. Enqueue");
        printf("\n3. Dequeue");
        printf("\n4. Get Front element");
        printf("\n5. Get Rear element");
        printf("\n6. Display all elements");
        printf("\n7. IsEmpty");
        printf("\n8. IsFull");
        printf("\n9. Number of elements in the queue");
        printf("\n10. Exit");
        printf("\nEnter your choice from 1-3: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createQueue();
            break;
        case 2:
            Enqueue();
            break;
        case 3:
            Dequeue();
            break;
        case 4:
            getFront();
            break;
        case 5:
            getRear();
            break;
        case 6:
            display();
            break;
        case 7:
            if (IsEmpty())
                printf("\nTrue");
            else
            {
                printf("\nFalse");
            }
            break;
        case 8:
            if (IsFull())
                printf("\nTrue");
            else
            {
                printf("\nFalse");
            }
            break;
        case 9:
            printf("Number of elements in the queue : %d", count);
            break;
        case 10:
            break;
        default:
            printf("\nEnter your choice from 1-10 only");
            break;
        }
    }
    printf("\nThank you");
    return 0;
}
void createQueue()
{
    front = 0;
    rear = 0;
    count = 0;
    for (int i = 0; i < maxsize; i++)
    {
        arr[i] = NULL;
    }
    printf("\nNew Queue Created\n");
}
void Enqueue()
{
    int val;
    if (count != maxsize)
    {
        printf("\nEnter the value to be added to the queue : ");
        scanf("%d", &val);
        arr[rear] = val;
        rear += 1;
        rear = rear % maxsize;
        count += 1;
        printf("\nThe value has been added to the queue\n");
    }
    else
    {
        printf("\nQueue Overflow");
    }
}
void Dequeue()
{
    if (count != 0)
    {
        int val = arr[front];
        arr[front] = NULL;
        front += 1;
        front = front % maxsize;
        count -= 1;
        printf("\nThe value that has been dequeued : %d\n", val);
    }
    else
    {
        printf("\nQueue Underflow");
    }
}
void display()
{
    if (count == 0)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe elements in the queue are : ");
        int val = front;
        if (val <= rear - 1)
        {
            while (val < rear)
            {
                printf("\n%d", arr[val]);
                val++;
            }
        }
        else
        {
            while (val < maxsize)
            {
                printf("\n%d", arr[val]);
                val++;
            }
            val = 0;
            while (val < rear)
            {
                printf("\n%d", arr[val]);
                val++;
            }
        }
    }
}
void getFront()
{
    if (count != 0)
    {
        printf("\nThe value at the front of the queue : %d", arr[front]);
    }
    else
    {
        printf("\nThe queue is empty");
    }
}
void getRear()
{
    if (count != 0)
    {
        printf("\nThe value at the end of the queue : %d", arr[(rear - 1)]);
    }
    else
    {
        printf("\nThe queue is empty");
    }
}
int IsEmpty()
{
    return count == 0;
}
int IsFull()
{
    return count == maxsize;
}