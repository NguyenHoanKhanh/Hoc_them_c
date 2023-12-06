#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(int data, vector<Node *> &hash_table, int n)
{
    int index = data % n;
    Node *temp = new Node;
    temp->data = data;
    if (hash_table[index] == nullptr)
    {
        hash_table[index] = temp;
        return;
    }
    temp->next = hash_table[index];
    hash_table[index] = temp;
}

int find(int data, vector<Node *> &hash_table, int n)
{
    int index = data % n;
    Node *curr = hash_table[index];
    while (curr)
    {
        if (curr->data == data)
        {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int main()
{
    int n;
    cout << "Nhap vao so phan tu trong hash_table : ";
    cin >> n;
    vector<Node *> hash_table(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao cac phan tu thu " << i + 1 << " : ";
        int x;
        cin >> x;
        insert(x, hash_table, n);
    }

    int f;
    cout << "Nhap vao phan tu can tim kiem : ";
    cin >> f;

    int check = find(f, hash_table, n);
    if (check)
    {
        cout << "tim thay phan tu " << f << " !!! ";
    }
    else
    {
        cout << "Khong tim thay phan tu " << f << " !!! ";
    }
    return 0;
}