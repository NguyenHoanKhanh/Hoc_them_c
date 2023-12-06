#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *makeNode(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

bool empty(Node *a)
{
    return a == nullptr;
}

int Size(Node *a)
{
    int count = 0;
    while (a != nullptr)
    {
        count++;
        a = a->next;
    }
    return count;
}

void insertFirst(Node *&a, int x)
{
    Node *temp = makeNode(x);
    if (a == nullptr)
    {
        a = temp;
    }
    else
    {
        temp = a->next;
        a = temp;
    }
}

void insertLast(Node *&a, int x)
{
    Node *temp = makeNode(x);
    if (a == nullptr)
    {
        a = temp;
    }
    else
    {
        Node *p = a;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void insertMiddle(Node *&a, int x, int pos)
{
    int n = Size(a);
    if (pos <= 0 || pos > pos + 1)
    {
        cout << "Vi tri chen khong hop le !!! ";
    }
    if (n == 1)
    {
        insertFirst(a, x);
        return;
    }
    else if (n == pos + 1)
    {
        insertLast(a, x);
        return;
    }
    Node* p = a;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    Node* temp = makeNode
}

int main()
{
    Node *head = nullptr;
    return 0;
}
