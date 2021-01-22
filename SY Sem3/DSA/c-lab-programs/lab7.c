#include <stdio.h>

struct hashTable
{
    int arr[100];
    int ct;
};

struct hashTable createHashTable(int size)
{
    struct hashTable t;
    for (int i = 0; i < size; i++)
    {
        t.arr[i] = -1;
    }
    t.ct = 0;
    return t;
}

void insert(struct hashTable *t, int val, int type, int size)
{
    if (t->ct != size)
    {
        if (type == 1)
        {
            int count = 0;
            int key = val % size;
            do
            {
                if (t->arr[key] == -1)
                {
                    t->arr[key] = val;
                    printf("%d inserted at the position - %d\n", val, key);
                    count = 1;
                }
                else
                {
                    printf("Collision Detected\t");
                    key = (key + 1) % size;
                    printf("Will Try to insert at next index %d\n", key);
                }
            } while (count == 0);
        }
        else
        {
            int count = 0;
            int key = val % size;
            for (int i = 0; count == 0; i++)
            {
                if (i == size)
                    break;
                if (t->arr[key] == -1)
                {
                    t->arr[key] = val;
                    printf("%d inserted at the position - %d\n", val, key);
                    count = 1;
                }
                else
                {
                    key = val % size;
                    printf("Collision Detected!");
                    key = (key + (i * i)) % size;
                    printf("Trying insert at next index %d\n", key);
                }
            }
        }
        t->ct++;
    }
    else
        printf("The Hash Table is full\n");
}

int isempty(struct hashTable *t)
{
    if (t->ct == 0)
        return 1;
    else
        return 0;
}

int search(struct hashTable *t, int val, int type, int size)
{
    if (isempty(t) == 0)
    {
        int counter = 0;
        if (type == 1)
        {
            int key = val % size;
            while (t->arr[key] != val)
            {
                key = (key + 1) % size;
                counter++;
                if (counter == size)
                    break;
            }
            if (t->arr[key] == val)
                return key;
            else
                return -1;
        }
        else
        {
            int i = 0;
            int key = val % size;
            while (t->arr[key] != val)
            {
                key = val % size;
                key = (key + (i * i)) % size;
                i++;
                counter++;
                if (counter == size - 1)
                    break;
            }
            if (t->arr[key] == val)
                return key;
            else
                return -1;
        }
    }
    else
    {
        printf("The Hash Table is empty.\n");
        return -1;
    }
}

int deleteElement(struct hashTable *t, int val, int type, int size)
{
    int key = search(t, val, type, size);
    if (key != -1)
    {
        t->arr[key] = -1;
        t->ct--;
    }
    return key;
}

void display(struct hashTable *t, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (t->arr[i] != -1)
            printf("arr[%d] = %d\n", i, t->arr[i]);
        else
            printf("arr[%d] = NULL\n", i);
    }
}

int size(struct hashTable *t)
{
    if (isempty(t) == 0)
        return t->ct;
    else
    {
        printf("The Hash Table is empty.\n");
        return 0;
    }
}

int main()
{
    int choice, key, value, n, c = 1, i, s, sz, type = 1;
    printf("--------- Hash Table -----------\n");
    printf("Enter size of Hash Table:");
    scanf("%d", &s);
    struct hashTable t;
    t = createHashTable(s);
    printf("\nChoose the type of probing:\n1.Linear\n2.Quadratic\nEnter your choice:");
label:
    scanf("%d", &type);
    if (type > 2)
    {
        printf("Choose from given options only.\nEnter you choice:");
        goto label;
    }
    do
    {
        printf("\n\tMENU \n1.Insert element \n2.Delete element \n3.Search element \n4.Size of Table \n5.Display \n6.Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Inserting an element:-\n");
            printf("Enter key:");
            scanf("%d", &key);
            insert(&t, key, type, s);
            break;
        case 2:
            printf("Deleting element:-\nEnter the value to delete:");
            scanf("%d", &value);
            key = deleteElement(&t, value, type, s);
            if (key != -1)
                printf("%d found at position: %d\nElement deleted from table\n", value, key);
            else
                printf("Entered value does not exist\n");
            break;
        case 3:
            printf("Enter value to be searched:");
            scanf("%d", &value);
            key = search(&t, value, type, s);
            if (key != -1)
                printf("Value %d found at position:%d\n", value, key);
            else
                printf("Entered value does not exist\n");
            break;
        case 4:
            sz = size(&t);
            if (sz != 0)
                printf("Size of Hash Table is: %d\n", sz);
            break;
        case 5:
            printf("Hash Table is:\n");
            display(&t, s);
            break;
        case 6:
            c = 0;
            break;
        default:
            printf("Choose from the given options only.\n");
        }
    } while (c == 1);
}