#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <ctype.h>
// tolower() method left to implement or try strcmpi()

struct player
{
    char name[50];
    int fifties, hundreds, highScore;
    float avg, strikeRate;
} p[10];
int count = 0;
void insert();
void delete ();
void display();
void search();

int main()
{
    int ch = 0;
    printf("\n===== Stack operations using linked list =======");
    while (ch != 5)
    {
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice from 1-5: ");
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
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("\nEnter your choice from 1-3 only");
            break;
        }
    }
    printf("\nThank you");
    return 0;
}
void insert()
{
    if (count != 10)
    {
        printf("\nInsert a new element : ");
        printf("\nName : ");
        scanf("%s", p[count].name);
        printf("Fifties : ");
        scanf("%d", &p[count].fifties);
        printf("Hundreds : ");
        scanf("%d", &p[count].hundreds);
        printf("HighScore : ");
        scanf("%d", &p[count].highScore);
        printf("Average : ");
        scanf("%f", &p[count].avg);
        printf("Strike Rate : ");
        scanf("%f", &p[count].strikeRate);
        printf("\nAdded a new element");
        count++;
    }
    else
    {
        printf("\nArray is Full");
    }
}
void delete ()
{
    if (count != 0)
    {
        char delname[50];
        int i = 0;
        printf("\nEnter name of player to be deleted\n");
        scanf("%s", delname);
        while (strcmp(p[i].name, delname) != 0)
        {
            if (i < count)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if (i <= count)
        {
            for (i; i < count; i++)
            {
                p[i] = p[i + 1];
            }
            count--;
            printf("\n\nRecord Deleted!");
        }
        else
        {
            printf("\n\nPlayer not found");
        }
    }
    else
    {
        printf("\nArray is Empty");
    }
}
void search()
{
    if (count != 0)
    {
        char ch[50];
        int i = 0, choice;
        printf("\nEnter name of player\n");
        scanf("%s", ch);
        while (strcmp(p[i].name, ch) != 0)
        {
            if (i < count)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if (i == count)
        {
            printf("No such element here!");
        }
        else
        {
            printf("Name\t  50s\t 100s\t  avg\tstrikeRate  highScore\n");
            printf("%-10s %-5d %-8d %-8.2f %-8.2f %-8d\n", p[i].name, p[i].fifties, p[i].hundreds, p[i].avg, p[i].strikeRate, p[i].highScore);
        }
    }
    else
    {
        printf("\nArray is Empty");
    }
}
void display()
{
    struct player temp;
    if (count != 0)
    {

        for (int j = 0; j < count; j++)
        {
            for (int i = 0; i < count - j; i++)
            {
                if (p[i].avg < p[i + 1].avg)
                {
                    temp = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = temp;
                }
                else if (p[i].avg == p[i + 1].avg && p[i].fifties < p[i + 1].fifties)
                {
                    temp = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = temp;
                }
                else if (p[i].avg == p[i + 1].avg && p[i].fifties == p[i + 1].fifties && p[i].hundreds < p[i + 1].hundreds)
                {
                    temp = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = temp;
                }
                else if (p[i].avg == p[i + 1].avg && p[i].fifties == p[i + 1].fifties && p[i].hundreds == p[i + 1].hundreds && p[i].strikeRate < p[i + 1].strikeRate)
                {
                    temp = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = temp;
                }
                else if (p[i].avg == p[i + 1].avg && p[i].fifties == p[i + 1].fifties && p[i].hundreds == p[i + 1].hundreds && p[i].strikeRate == p[i + 1].strikeRate && p[i].highScore < p[i + 1].highScore)
                {
                    temp = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = temp;
                }
                else if (p[i].avg == p[i + 1].avg && p[i].fifties == p[i + 1].fifties && p[i].hundreds == p[i + 1].hundreds && p[i].strikeRate == p[i + 1].strikeRate && p[i].highScore == p[i + 1].highScore)
                {
                    int cmp = strcmp(p[i].name, p[i + 1].name);
                    if (cmp > 0)
                    {
                        temp = p[i];
                        p[i] = p[i + 1];
                        p[i + 1] = temp;
                    }
                }
            }
        }
        printf("Name\t  50s\t 100s\t  avg\tstrikeRate  highScore\n");
        for (int i = 0; i < count; i++)
        {
            printf("%-10s %-5d %-8d %-8.2f %-8.2f %-8d\n", p[i].name, p[i].fifties, p[i].hundreds, p[i].avg, p[i].strikeRate, p[i].highScore);
        }
    }
    else
    {
        printf("\nArray is Empty");
    }
}