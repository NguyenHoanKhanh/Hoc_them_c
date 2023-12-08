#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef struct Node *node;

node makeNode(int x)
{
    node temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

bool empty(node a)
{
    return a == nullptr;
}

int size_node(node a)
{
    int count = 0;
    while (a != nullptr)
    {
        count++;
        a = a->next;
    }
    return count;
}

node insertNode(int x)
{
    node temp = makeNode(x);
    return temp;
}

node InsertNnode(int n)
{
    node head = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Nhap vao phan tu thu " << i + 1 << " : ";
        cin >> x;
        node newnode = insertNode(x);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            node p = head;
            while (p->next != nullptr)
            {
                p = p->next;
            }
            p->next = newnode;
        }
    }
    return head;
}

void insertFirst(node &a, int x)
{
    node temp = makeNode(x);
    if (a == nullptr)
    {
        a = temp;
    }
    else
    {
        temp->next = a;
        a = temp;
    }
}

void insertLast(node &a, int x)
{
    node temp = makeNode(x);
    if (a == nullptr)
    {
        a = temp;
    }
    else
    {
        node p = a;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void insertMidle(node &a, int x, int pos)
{
    int n = size_node(a);
    if (pos <= 0 || pos > n + 1)
    {
        cout << "Khong the chen!!!" << endl;
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
    else
    {
        node p = a;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        node temp = makeNode(x);
        temp->next = p->next;
        p->next = temp;
    }
}

void deleteFirt(node &a)
{
    if (a == nullptr)
    {
        return;
    }
    a = a->next;
}

void deleteLast(node &a)
{
    if (a == nullptr)
    {
        return;
    }
    node truoc = nullptr, sau = a;
    while (sau->next != nullptr)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr)
    {
        a = nullptr;
    }
    else
    {
        truoc->next = nullptr;
    }
}

void deleteMid(node &a, int pos)
{
    if (pos <= 0 || pos > size_node(a))
    {
        return;
    }
    node truoc = a, sau = nullptr;
    for (int i = 0; i < pos; i++)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr)
    {
        a = a->next;
    }
    else
    {
        truoc->next = sau->next;
    }
}

void Output(node a)
{
    while (a != nullptr)
    {
        cout << a->data << " ";
        a = a->next;
    }
}

int main()
{
    node head = nullptr;
    int choose = 99;
    int n;
    cout << "Nhap vao so luong phan tu cua n : ";
    cin >> n;
    head = InsertNnode(n);
    while (choose != 0)
    {
        cout<<endl;
        cout << "1. Chen phan tu vao dau" << endl;
        cout << "2. Chen phan tu vao cuoi" << endl;
        cout << "3. Chen phan tu vao giua" << endl;
        cout << "4. Xoa phan tu o dau" << endl;
        cout << "5. Xoa phan tu o cuoi" << endl;
        cout << "6. Xoa phan tu o giua" << endl;
        cout << "7. In" << endl;
        cout << "0. Ket thuc chuong trinh !!!" << endl;
        cout << "Nhap vao lua chon : ";
        cin >> choose;

        if (choose == 1)
        {
            int x;
            cout << "Nhap vao gia tri can chen : ";
            cin >> x;
            insertFirst(head, x);
        }
        else if (choose == 2)
        {
            int x;
            cout << "Nhap vao gia tri can chen : ";
            cin >> x;
            insertLast(head, x);
        }
        else if (choose == 3)
        {
            int x, pos;
            cout << "Nhap vao gia tri can chen : ";
            cin >> x;
            cout << "Nhap vi tri can chen : ";
            cin >> pos;
            insertMidle(head, x, pos);
        }
        else if (choose == 4)
        {
            deleteFirt(head);
        }
        else if (choose == 5)
        {
            deleteLast(head);
        }
        else if (choose == 6)
        {
            int pos;
            cout << "Nhap vao vi tri muon xoa : ";
            cin >> pos;
            deleteMid(head, pos);
        }
        else if (choose == 7)
        {
            Output(head);
        }
    }
    cout << "Da ket thuc chuong trinh !!!";
    return 0;
}
