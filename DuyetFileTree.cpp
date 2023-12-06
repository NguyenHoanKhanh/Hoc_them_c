#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

void createNode(Node *&t)
{
    t = nullptr;
}

void addNode(Node *&t, int x)
{
    if (t == nullptr)
    {
        Node *p = new Node;
        p->data = x;
        p->pLeft = nullptr;
        p->pRight = nullptr;
        t = p;
    }

    else
    {
        if (x > t->data)
        {
            addNode(t->pRight, x);
        }

        else if (x < t->data)
        {
            addNode(t->pLeft, x);
        }
    }
}

void Input(Node *t, vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void NodeLa(Node *t)
{
    if (t != nullptr)
    {
        if (t->pLeft == nullptr && t->pRight == nullptr)
        {
            cout << t->data << " ";
        }
        NodeLa(t->pLeft);
        NodeLa(t->pRight);
    }
}

void Node1Con(Node *t)
{
    if (t != nullptr)
    {
        if ((t->pLeft == nullptr && t->pRight != nullptr) || (t->pLeft != nullptr && t->pRight == nullptr))
        {
            cout << t->data << " ";
        }
        Node1Con(t->pLeft);
        Node1Con(t->pRight);
    }
}

void Node2Con(Node *t)
{
    if (t != nullptr)
    {
        if (t->pLeft != nullptr && t->pRight != nullptr)
        {
            cout << t->data << " ";
        }
        Node2Con(t->pLeft);
        Node2Con(t->pRight);
    }
}

int FindMax(Node *t)
{
    int max_val = INT_MIN;
    if (t == nullptr)
    {
        return INT_MIN;
    }

    int maxleft = FindMax(t->pLeft);
    int maxright = FindMax(t->pRight);

    max_val = max(t->data, max(maxleft, maxright));
    return max_val;
}

void Output(Node *t, vector<int> &arr, int n)
{
    cout << "Duyet cay : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Ket qua node la : ";
    NodeLa(t);
    cout << endl;

    cout << "Ket qua node 1 con : ";
    Node1Con(t);
    cout << endl;

    cout << "Ket qua node 2 con : ";
    Node2Con(t);
    cout << endl;

    cout << "Max cua node la : " << FindMax(t);
    cout << endl;
}

int main()
{
    Node *t;
    createNode(t);
    int n;
    cout << "Nhap vao so luong phan tu trong cay : ";
    cin >> n;

    vector<int> arr(n);
    Input(t, arr, n);
    for (int i = 0; i < n; i++)
    {
        addNode(t, arr[i]);
    }

    Output(t, arr, n);
    delete[] &arr;
    return 0;
}