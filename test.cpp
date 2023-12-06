#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *pleft;
    Node *pright;
};

void createTree(Node *&t)
{
    t = nullptr;
}

void addNodetoTree(Node *&t, int x)
{
    if (t == nullptr)
    {
        Node *p = new Node;
        p->data = x;
        p->pleft = nullptr;
        p->pright = nullptr;
        t = p;
    }
    else
    {
        if (x < t->data)
        {
            addNodetoTree(t->pleft, x);
        }

        else if (x > t->data)
        {
            addNodetoTree(t->pright, x);
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

void NodeLeftRight(Node *t)
{
    if (t != nullptr)
    {
        cout << t->data << " ";
        NodeLeftRight(t->pleft);
        NodeLeftRight(t->pright);
    }
}

void NodeRightLeft(Node *t)
{
    if (t != nullptr)
    {
        cout << t->data << " ";
        NodeRightLeft(t->pright);
        NodeRightLeft(t->pleft);
    }
}

void LeftNodeRight(Node *t)
{
    if (t != nullptr)
    {
        LeftNodeRight(t->pleft);
        cout << t->data << " ";
        LeftNodeRight(t->pright);
    }
}

void LeftRightNode(Node *t)
{
    if (t != nullptr)
    {
        LeftRightNode(t->pleft);
        LeftRightNode(t->pright);
        cout << t->data << " ";
    }
}

void RightNodeLeft(Node *t)
{
    if (t != nullptr)
    {
        RightNodeLeft(t->pright);
        cout << t->data << " ";
        RightNodeLeft(t->pleft);
    }
}

void RightLeftNode(Node *t)
{
    if (t != nullptr)
    {
        RightLeftNode(t->pright);
        RightLeftNode(t->pleft);
        cout << t->data << " ";
    }
}

bool CheckSoNguyenTo(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        if (x == 2)
        {
            return true;
        }
        else
        {
            if (x % 2 == 0)
            {
                return false;
            }

            else
            {
                for (int i = 2; i < x; i++)
                {
                    if (x % i == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void DemSoNguyenTo(Node *t, int &count)
{
    if (t != nullptr)
    {
        if (CheckSoNguyenTo(t->data) == true)
        {
            count++;
        }

        DemSoNguyenTo(t->pleft, count);
        DemSoNguyenTo(t->pright, count);
    }
}

Node *FindElement(Node *t, int x)
{
    if (t == nullptr)
    {
        return nullptr;
    }

    else
    {
        if (x < t->data)
        {
            return FindElement(t->pleft, x);
        }
        else if (x > t->data)
        {
            return FindElement(t->pright, x);
        }
        else
        {
            return t;
        }
    }
}

void Node2Con(Node *t)
{
    if (t != nullptr)
    {
        if (t->pleft != nullptr && t->pright != nullptr)
        {
            cout << t->data << " ";
        }

        Node2Con(t->pleft);
        Node2Con(t->pright);
    }
}

void Node1Con(Node *t)
{
    if (t != nullptr)
    {
        if ((t->pleft != nullptr && t->pright == nullptr) || (t->pleft == nullptr && t->pright != nullptr))
        {
            cout << t->data << " ";
        }

        Node1Con(t->pleft);
        Node1Con(t->pright);
    }
}

void NodeLa(Node *t)
{
    if (t != nullptr)
    {
        if (t->pleft == nullptr && t->pright == nullptr)
        {
            cout << t->data << " ";
        }

        NodeLa(t->pleft);
        NodeLa(t->pright);
    }
}

int FindMax(Node *t)
{
    int max_val = INT_MIN;
    if (t == nullptr)
    {
        return INT_MIN;
    }

    int maxleft = FindMax(t->pleft);
    int maxright = FindMax(t->pright);

    max_val = max(t->data, max(maxleft, maxright));
    return max_val;
}

int FindMin(Node *t)
{
    int min_val = INT_MAX;
    if (t == nullptr)
    {
        return INT_MAX;
    }

    int minleft = FindMax(t->pleft);
    int minright = FindMax(t->pright);

    min_val = min(t->data, min(minleft, minright));
    return min_val;
}

void FindNodeReplace(Node *&x, Node *&y)
{
    if (y->pleft != nullptr)
    {
        FindNodeReplace(x, y->pleft);
    }
    else
    {
        x->data = y->data;
        x = y;
        y = y->pright;
    }
}

void DeleteNode(Node *&t, int data)
{
    if (t == nullptr)
    {
        return;
    }
    else
    {
        if (data < t->data)
        {
            DeleteNode(t->pleft, data);
        }
        else if (data > t->data)
        {
            DeleteNode(t->pright, data);
        }
        else
        {
            Node *x = t;
            if (t->pleft == nullptr)
            {
                t = t->pright;
            }
            else if (t->pright == nullptr)
            {
                t = t->pleft;
            }
            else
            {
                // Node* y = t->pright;
                FindNodeReplace(x, t->pright);
            }
            delete x;
        }
    }
}

void OutputAfterDelete(Node *t)
{
    if (t != nullptr)
    {
        cout << t->data << " ";
        OutputAfterDelete(t->pleft);
        OutputAfterDelete(t->pright);
    }
}

void Output(Node *t, vector<int> &arr, int n)
{
    cout << "Duyet cay : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Ket qua cua node - left - right : ";
    NodeLeftRight(t);
    cout << endl;

    cout << "Ket qua cua node - right - left : ";
    NodeRightLeft(t);
    cout << endl;

    cout << "Ket qua cua left - node - right : ";
    LeftNodeRight(t);
    cout << endl;

    cout << "Ket qua cua left - right - node : ";
    LeftRightNode(t);
    cout << endl;

    cout << "Ket qua cua right - node - left : ";
    RightNodeLeft(t);
    cout << endl;

    cout << "Ket qua cua right - left - node : ";
    RightLeftNode(t);
    cout << endl;

    int count = 0;
    DemSoNguyenTo(t, count);
    cout << "So luong so nguyen to trong tree : " << count;
    cout << endl;

    int x;
    cout << "Nhap vao phan tu can tim kiem trong tree : ";
    cin >> x;

    Node *p = FindElement(t, x);
    if (p == nullptr)
    {
        cout << "Khong tim thay phan tu !!!" << endl;
    }
    else
    {
        cout << "Tim thay phan tu " << x << endl;
    }

    cout << "Ket qua node co 2 con : ";
    Node2Con(t);
    cout << endl;

    cout << "Ket qua node co 1 con : ";
    Node1Con(t);
    cout << endl;

    cout << "Ket qua node la : ";
    NodeLa(t);
    cout << endl;

    cout << "Tim max : " << FindMax(t) << endl;
    cout << "TIm min : " << FindMin(t) << endl;

    int d;
    cout << "Nhap vao so phan tu can xoa trong node : ";
    cin >> d;
    vector<int> a(d);
    for (int i = 0; i < d; i++)
    {
        cin >> a[i];
        DeleteNode(t, a[i]);
    }
    cout << "Ket qua node : ";
    OutputAfterDelete(t);
    cout << endl;
}

int main()
{
    Node *t;
    createTree(t);
    int n;
    cout << "Nhap vao kich thuoc mang : ";
    cin >> n;

    vector<int> arr(n);

    Input(t, arr, n);
    for (int i = 0; i < n; i++)
    {
        addNodetoTree(t, arr[i]);
    }

    Output(t, arr, n);
    delete[] &arr;
    return 0;
}