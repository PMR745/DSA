#include <stdio.h>

struct student
{
    int roll_no;
    char name[50];
    float cgpa;
};

void bubbleSort(struct student *s, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].cgpa > s[j + 1].cgpa)
            {
                struct student s1 = s[j];
                s[j] = s[j + 1];
                s[j + 1] = s1;
            }
        }
    }
}

void insertionSort(struct student *s, int n) {
    for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++)
            {
                if(s[i].roll_no > s[j].roll_no) {
                    struct student s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
            }
            
        }
}

int main()
{
    int n, choice;
    printf("Enter the Number of Students Record: ");
    scanf("%d", &n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Roll No of Student: ");
        scanf("%d", &s[i].roll_no);
        printf("Enter the Name of Student: ");
        scanf("%s", &s[i].name);
        printf("Enter the CGPA of student: ");
        scanf("%f", &s[i].cgpa);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%s\t%.2f", s[i].roll_no, s[i].name, s[i].cgpa);
    }
    printf("\n\tMenu\n");
    printf("1. Bubble Sort (CGPA)\n2. Insertion Sort (Roll No)\n3. Quick Sort\n4. Search By CGPA\n5. Search By Name\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bubbleSort(s, n);
        break;

    case 2:
        insertionSort(s, n);
        break;
        
    default:
        break;
    }


    printf("\nRoll No\t\tName\t\tCGPA\n");
    for (int i = 0; i < n; i++)
    {

        printf("\n%d\t\t%s\t\t%.2f", s[i].roll_no, s[i].name, s[i].cgpa);
    }
}