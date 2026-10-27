
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    printf("%d inserted successfully.\n", value);
}

void deleteFromBeginning(void)
{
    struct Node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display(void)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

void freeList(void)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;

        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            struct Node *last = head;

            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;
        }

        free(temp);
    }
}

int main(void)
{
    int choice, value;

    do
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            freeList();
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value: ");

                if (scanf("%d", &value) != 1)
                {
                    printf("Invalid input!\n");
                    freeList();
                    return 1;
                }

                insertAtEnd(value);
                break;

            case 2:
                deleteFromBeginning();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    freeList();
    return 0;
}
