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

// Functions
int menu(struct member *);
void display(struct member *);
void addMember(struct member *);
void deleteMember(struct member *);
int editMembers(struct member *);
struct member *changePresident(struct member *);
struct member *changeSecreteary(struct member *);
int total_members(struct member *);

int menu(struct member *head) {
    int choice;
    while (1)
    {
        printf("\nMenu:");
        printf("\n1. Edit Members\n2. Total No of Members\n3. Display Members\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            editMembers(head);
            display(head);
            break;

        case 2:
            printf("Total Members are %d\n", total_members(head));
            break;

        case 3:
            display(head);
            break;

        default:
            return 0;
            break;
        }
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

int editMembers(struct member *head) {
    while(1) {
    int ch;
    printf("\n1. Add Member\n2. Delete Member\n3. Change President\n4. Change Secretary\n5. Back\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
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
        head = changePresident(head);
        display(head);
        break;

    case 4:
        head = changeSecreteary(head);
        display(head);
        break;

    case 5:
        menu(head);
        break;
    default:
        break;
    }
    }
    return 0;
}

struct member *changePresident(struct member *head) {
    char newName[20];
    struct member *newPresident = (struct member *)malloc(sizeof(struct member));
    struct member *ptr = head;
    struct member *temp = head->next;
    newPresident->next = temp;
    printf("\nEnter the Mis Id: ");
    scanf("%d", &newPresident->mis_id);
    printf("Enter the Name of New President: ");
    scanf("%s", &newName);
    strcpy(newPresident->name, newName);
    strcpy(newPresident->post, "President");
    head = newPresident;
    free(ptr);
    return head;
}

struct member *changeSecreteary(struct member *head) {
    struct member *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("Enter the Mis Id: ");
    scanf("%d", &temp->mis_id);
    printf("Enter the Name of New Secreteary: ");
    scanf("%s", &temp->name);
    return head;
}

int total_members(struct member *head) {
    struct member *temp = head->next;
    int count;
    do{
        count ++;
        temp = temp->next;
    }while(temp->next != NULL);
    return count;
}
int main()
{
    int n;
    printf("Enter No of Members: ");
    scanf("%d", &n);
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

    menu(head);

    return 0;
}
