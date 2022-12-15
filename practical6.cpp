#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct node
{
    char name[20];
    node *next;
    node *down;
    int flag;
};
class Gll
{
    char ch[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node *create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};
node *Gll::create()
{
    node *p = new (struct node);
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\nEnter the Name: ";
    cin >> p->name;
    return p;
}
void Gll::insertb()
{

    if (head == NULL)
    {
        t1 = create();
        head = t1;
    }
    else
    {
        cout << "\nBook exist";
    }
}
void Gll::insertc()
{
    if (head == NULL)
    {
        cout << "\nThere is no book";
    }
    else
    {
        cout << "\nNo chapters you want to insert: ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t1 = create();
            if (head->flag == 0)
            {
                head->down = t1;
                head->flag = 1;
            }
            else
            {
                temp = head;
                temp = temp->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}
void Gll::inserts()
{

    if (head == NULL)
    {
        cout << "\nThere is no book";
    }
    else
    {
        cout << "\nEnter the name of chapter on which you want to enter the section: ";
        cin >> ch;

        temp = head;
        if (temp->flag == 0)
        {
            cout << "\nTheir are no chapters on in book";
        }
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\nHow many sections you want to enter: ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                    {

                        t1 = create();
                        if (temp->flag == 0)
                        {
                            temp->down = t1;

                            temp->flag = 1;
                            cout << "\n******";
                            t2 = temp->down;
                        }
                        else
                        {
                            cout << "\n#####";
                            while (t2->next != NULL)
                            {
                                t2 = t2->next;
                            }
                            t2->next = t1;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
void Gll::insertss()
{

    if (head == NULL)
    {
        cout << "\nThere is no book";
    }
    else
    {
        cout << "\nEnter the name of chapter on which you want to enter the section: ";
        cin >> ch;

        temp = head;
        if (temp->flag == 0)
        {
            cout << "\nTheir are no chapters on in book";
        }
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "\nEnter name of section in which you want to enter the sub section: ";
                            cin >> ch;

                    if (temp->flag == 0)
                    {
                        cout << "\nTheir are no sections ";
                    }
                    else
                    {
                        temp = temp->down;
                        while (temp != NULL)
                        {
                            if (!strcmp(ch, temp->name))
                            {
                                cout << "\nHow many subsections you want to enter: ";
                                cin >> n;
                                for (i = 0; i < n; i++)
                                {

                                    t1 = create();
                                    if (temp->flag == 0)
                                    {
                                        temp->down = t1;

                                        temp->flag = 1;
                                        cout << "\n******";
                                        t2 = temp->down;
                                    }
                                    else
                                    {
                                        cout << "\n#####";
                                        while (t2->next != NULL)
                                        {
                                            t2 = t2->next;
                                        }
                                        t2->next = t1;
                                    }
                                }
                                break;
                            }
                            temp = temp->next;
                        }
                    }
                }

                temp = temp->next;
            }
        }
    }
}
void Gll::displayb()
{

    if (head == NULL)
    {
        cout << "\nBook not exist";
    }
    else
    {
        temp = head;

        cout << "\nNAME OF BOOK: " << temp->name;
        if (temp->flag == 1)
        {
            temp = temp->down;

            while (temp != NULL)
            {
                cout << "\n\t\tNAME OF CHAPTER: " << temp->name;
                t1 = temp;
                if (t1->flag == 1)
                {
                    t1 = t1->down;
                    while (t1 != NULL)
                    {
                        cout << "\n\t\t\t\tNAME OF SECTION: " << t1->name;
                        t2 = t1;
                        if (t2->flag == 1)
                        {
                            t2 = t2->down;
                            while (t2 != NULL)
                            {
                                cout << "\n\t\t\t\t\t\tNAME OF SUBSECTION: " << t2 -> name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
}
int main()
{
    printf("SCO_19 Prathmesh Rajput\n");
    Gll g;
    int x;
    while (1)
    {
        cout << "\n 1.Insert book";
        cout << "\n 2.Insert chapter";
        cout << "\n 3.Insert section";
        cout << "\n 4.Insert subsection";
        cout << "\n 5.Display book";
        cout << "\n 6.Exit";
        cout << "\nEnter your choice: ";
        cin >> x;
        switch (x)
        {
        case 1:
            g.insertb();
            break;
        case 2:
            g.insertc();
            break;
        case 3:
            g.inserts();
            break;
        case 4:
            g.insertss();
            break;
        case 5:
            g.displayb();
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}