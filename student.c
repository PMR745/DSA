#include <stdio.h>
#include <string.h>

struct student
{
    int roll_no;
    char name[50];
    float cgpa;
};

void swap(struct student *s, int i, int j)
{
    struct student s1 = s[i];
    s[i] = s[j];
    s[j] = s1;
}

void bubbleSort(struct student *s, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].cgpa > s[j + 1].cgpa)
            {
                swap(s, j, j + 1);
            }
        }
    }
}

void insertionSort(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                swap(s, i, j);
            }
        }
    }
}

int partition(struct student *s, int low, int high)
{
    int pivot = s[high].roll_no;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (s[j].roll_no < pivot)
        {
            i++;
            swap(s, i, j);
        }
    }
    swap(s, i + 1, high);
    return i + 1;
}

void quickSort(struct student *s, int low, int high)
{
    if (low < high)
    {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

void linear_search(struct student *s, int n)
{
    char key[50];
    printf("Enter Name to be Searched: ");
    scanf("%s", &key);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(s[i].name, key) == 0)
        {
            printf("Element Found!\n");
            printf("\nName: %s\nRoll No: %d\nCGPa: %.2f\n", s[i].roll_no, s[i].name, s[i].cgpa);
        }
    }
}

void display(struct student *s, int n)
{
    printf("\nRoll No\t\tName      \t\t\tCGPA\n");
    for (int i = 0; i < n; i++)
    {
        if (strlen(s[i].name) > 7)
        {
            printf("\n%d\t\t%s\t\t\t%.2f", s[i].roll_no, s[i].name, s[i].cgpa);
        }
        else
        {
            printf("\n%d\t\t%s\t\t\t\t%.2f", s[i].roll_no, s[i].name, s[i].cgpa);
        }
    }
}

int main()
{
    int n, choice, repeat = 1;
    printf("Enter the Number of Students Record: ");
    scanf("%d", &n);
    struct student s[n];
    for (int i = 0; i < n; i++) // Input from User
    {
        printf("Enter the Roll No of Student: ");
        scanf("%d", &s[i].roll_no);
        printf("Enter the Name of Student: ");
        scanf("%s", &s[i].name);
        printf("Enter the CGPA of student: ");
        scanf("%f", &s[i].cgpa);
    }
    printf("\nRoll No\t\tName\t\t\tCGPA");

    display(s, n);
    while (repeat == 1)
    {
        printf("\n\tMenu\n");
        printf("1. Bubble Sort (CGPA)\n2. Insertion Sort (Name)\n3. Quick Sort(Roll No.)\n4. Search By CGPA\n5. Search By Name\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubbleSort(s, n);
            display(s, n);

            break;

        case 2:
            insertionSort(s, n);
            display(s, n);

            break;

        case 3:
            quickSort(s, 0, n);
            display(s, n);

            break;

        case 4:
            linear_search(s, n);
            break;

        case 6:
            repeat = 0;
            break;
        default:
            break;
        }
    }
}
