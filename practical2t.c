#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member
{
    int mis_id;
    char name[25];
    char post[10];
    struct member *next;
};

void addMember(struct member *head)
{
    int position, newMis;
    char newName[25];
    printf("Enter the Position: ");
    scanf("%d", &position);
    printf("Enter the MIS Id: ");
    scanf("%d", &newMis);
    printf("Enter the Name of New Member: ");
    scanf("%s", &newName);

    struct member *newMember;
    newMember = malloc(sizeof(struct member));
    newMember->mis_id = newMis;
    strcpy(newMember->name, newName);
    strcpy(newMember->post, "Member");

    struct member *temp = head;
    for (int i = 2; i < position; i++)
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
    }

    newMember->next = temp->next;
    temp->next = newMember;
}

void deleteMember(struct member *head)
{
    int position;
    printf("Enter the Position: ");
    scanf("%d", &position);

    if (position == 1)
    {
        head->next = head->next->next;
    }
    else
    {
        struct member *temp = head;
        for (int i = 2; i < position; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }

        temp->next = temp->next->next;
    }
}

void display(struct member *head)
{
    printf("\nMIS ID\t| Name\t\t| Post\n");
    printf("--------|---------------|----------\n");
    struct member *temp = head;
    while (temp != NULL)
    {
        printf("%d\t| %s\t\t| %s\n", temp->mis_id, temp->name, temp->post);
        temp = temp->next;
    }
}

int main()
{
    int n, repeat = 1;
    printf("Enter No of Members: ");
    scanf("%d", &n);
    int choice;
    struct member *head;
    struct member *m[n];

    // Allocating Memory
    for (int i = 0; i < n; i++)
    {
        m[i] = malloc(sizeof(struct member));
    }

    // Inserting Data
    for (int i = 0; i < n; i++)
    {
        int temp_id;
        char temp_name[25];
        printf("Enter the Mis Id: ");
        scanf("%d", &temp_id);
        printf("Enter the Name of Member: ");
        scanf("%s", &temp_name);
        m[i]->mis_id = temp_id;
        strcpy(m[i]->name, temp_name);

        if (i == 0)
        {
            strcpy(m[i]->post, "President");
        }
        else if (i == n - 1)
        {
            strcpy(m[i]->post, "Secretary");
        }
        else
        {
            strcpy(m[i]->post, "Member");
        }
    }

    // Passing Address of next node
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            m[i]->next = NULL;
        }
        else
        {
            m[i]->next = m[i + 1];
        }
    }

    head = m[0];

    display(head);

    while (repeat != 0)
    {
        printf("\n1. Add Member\n2. Delete Member\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addMember(head);
            display(head);
            break;

        case 2:
            deleteMember(head);
            display(head);
            break;

        case 3:

            break;

        default:
            repeat = 0;
            break;
        }
    }

    return 0;
}