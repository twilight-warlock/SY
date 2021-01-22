#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

int total_elements;

// declaration
void menu(int **, int[]);
void push(int);
void enqueue(int);
void pop();
int check_visited(int, int, int[]);
void bfs(int **, int[], int);
void dfs(int **, int[], int);

void main()
{
    system("cls");
    char choice;
    printf("--------- Enter Graph Values --------------\n");
    printf("Enter the no. of nodes: ");
    scanf("%d", &total_elements);
    int values_at_nodes[total_elements];
    int **matrix = (int **)malloc(total_elements * sizeof(int *));
    for (int i = 0; i < total_elements + 1; i++)
        matrix[i] = (int *)malloc(total_elements * sizeof(int));
    for (int i = 0; i < total_elements; i++)
    {
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &values_at_nodes[i]);
    }
    printf("\n");
    for (int i = 0; i < total_elements; i++)
    {
        for (int j = 0; j < total_elements; j++)
        {
            if (i == j)
                matrix[i][i] = 0;
            else if (j < i)
                continue;
            else
            {
            retry1:
                printf("Is there an edge between node %d and node %d? (y/n): ", values_at_nodes[i], values_at_nodes[j]);
                scanf(" %c", &choice);
                switch (choice)
                {
                case 'y':
                    matrix[i][j] = 1;
                    matrix[j][i] = 1;
                    break;
                case 'n':
                    matrix[i][j] = 0;
                    matrix[j][i] = 0;
                    break;
                default:
                    printf("Invalid input, enter either y/n\n");
                    goto retry1;
                }
            }
        }
    }
    menu(matrix, values_at_nodes);
}

void menu(int **matrix, int values_at_nodes[])
{
    system("cls");
    printf("---- MENU ----\n");
    printf("1. B.F.S.\n");
    printf("2. D.F.S.\n");
    printf("3. Exit");
    printf("\n\nEnter your choice: ");
    switch (getch())
    {
    case '1':
        system("cls");
        int start1;
    retry2:
        printf("Enter the starting element: ");
        scanf("%d", &start1);
        for (int i = 0; i < total_elements; i++)
        {
            if (values_at_nodes[i] == start1)
            {
                bfs(matrix, values_at_nodes, i);
                break;
            }
            else if (i + 1 == total_elements)
            {
                printf("Element not found!\n");
                goto retry2;
            }
        }
        printf("\n\nPress any key to go back ");
        if (getch())
            menu(matrix, values_at_nodes);
    case '2':
        system("cls");
        int start2;
    retry3:
        printf("Enter the starting element: ");
        scanf("%d", &start2);
        for (int i = 0; i < total_elements; i++)
        {
            if (values_at_nodes[i] == start2)
            {
                dfs(matrix, values_at_nodes, i);
                break;
            }
            else if (i + 1 == total_elements)
            {
                printf("Element not found!\n");
                goto retry3;
            }
        }
        printf("\n\nPress any key to go back ");
        if (getch())
            menu(matrix, values_at_nodes);
    case '3':
        system("cls");
        printf("Thank you");
        exit(0);
    default:
        printf("\nIncorrect input, Enter the correct choice");
        menu(matrix, values_at_nodes);
    }
}

void enqueue(int adding_element)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = adding_element;
    new->next = NULL;
    if (front == NULL)
    {
        front = new;
        rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}

void push(int adding_element)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = adding_element;
    new->next = front;
    front = new;
}

void pop()
{
    struct node *temp;
    temp = front;
    front = front->next;
    free(temp);
}

int check_visited(int x, int y, int visited[])
{
    for (int i = 0; i < y; i++)
    {
        if (visited[i] == x)
            return 0;
    }
    return 1;
}

void bfs(int **matrix, int values_at_nodes[], int start_pos)
{
    int visited[total_elements], visited_pos = 0;
    enqueue(values_at_nodes[start_pos]);
    visited[visited_pos] = values_at_nodes[start_pos];
    visited_pos++;
    printf("BFS: ");
    while (front != NULL)
    {
        for (int i = 0; i < total_elements; i++)
        {
            if (values_at_nodes[i] == front->data)
            {
                for (int j = 0; j < total_elements; j++)
                {
                    if ((matrix[i][j] == 1) && check_visited(values_at_nodes[j], visited_pos, visited))
                    {
                        visited[visited_pos] = values_at_nodes[j];
                        visited_pos++;
                        enqueue(values_at_nodes[j]);
                    }
                }
                printf("%d ", values_at_nodes[i]);
                pop();
                break;
            }
        }
    }
}

void dfs(int **matrix, int values_at_nodes[], int start_pos)
{
    int visited[total_elements], visited_pos = 0;
    push(values_at_nodes[start_pos]);
    visited[visited_pos] = values_at_nodes[start_pos];
    visited_pos++;
    printf("DFS: ");
    while (front != NULL)
    {
        for (int i = 0; i < total_elements; i++)
        {
            if (values_at_nodes[i] == front->data)
            {
                for (int j = 0; j < total_elements; j++)
                {
                    if ((matrix[i][j] == 1) && check_visited(values_at_nodes[j], visited_pos, visited))
                    {
                        visited[visited_pos] = values_at_nodes[j];
                        visited_pos++;
                        push(values_at_nodes[j]);
                        break;
                    }
                    else if (j + 1 == total_elements)
                    {
                        printf("%d ", values_at_nodes[i]);
                        pop();
                    }
                }
                break;
            }
        }
    }
}