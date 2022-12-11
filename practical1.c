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
        struct student temp = s[i];
        int j = i - 1;
        while (strcmp(s[j].name, temp.name) > 0 && j >= 0)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = temp;
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
    float key;
    printf("Enter the CGPA to be Searched: ");
    scanf("%f", &key);
    for (int i = 0; i < n; i++)
    {
        if(s[i].cgpa == key) {
            printf("\nStudent Found!\n");
            printf("\nName: %s\nRoll No: %d\nCGPA: %.2f\n", s[i].name, s[i].roll_no, s[i].cgpa);
        }
    }
}

void binarySearch(struct student *s, int n) {
    insertionSort(s, n);
    char key[50];
    printf("Enter Name to be Searched: ");
    scanf("%s", &key);
    int low = 0;
    int high = n;
    while(low <= high) {
        int mid = (low+high)/2;
        if(strcmp(s[mid].name, key) == 0) {
            printf("Student Found!\n");
            printf("\nName: %s\nRoll No: %d\nCGPA: %.2f\n", s[mid].name, s[mid].roll_no, s[mid].cgpa);
            break;
        }
        else if(strcmp(s[mid].name, key) > 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
}

void display(struct student *s, int n)
{
    printf("\nRoll No\t\t| Name      \t\t\t| CGPA");
    for (int i = 0; i < n; i++)
    {
        if (strlen(s[i].name) >= 7)
        {
            printf("\n----------------|-------------------------------|------");
            printf("\n%d\t\t| %s\t\t\t| %.2f", s[i].roll_no, s[i].name, s[i].cgpa);
        }
        else
        {
            printf("\n----------------|-------------------------------|------");
            printf("\n%d\t\t| %s\t\t\t\t| %.2f", s[i].roll_no, s[i].name, s[i].cgpa);
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

        case 5:
            binarySearch(s, n);
            break;

        case 6:
            repeat = 0;
            break;

        default:
            break;
        }
    }
}