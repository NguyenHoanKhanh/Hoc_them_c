#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    string x;
    Node *next;
};

typedef struct Node *node;

bool empty(node top)
{
    return top == nullptr;
}

int getsize(node top)
{
    int ans = 0;
    while (top != nullptr)
    {
        ans++;
        top = top->next;
    }
    return ans;
}

node makenode(int x)
{
    node temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

node makeNode(string x)
{
    node temp = new Node();
    temp->x = x;
    temp->next = nullptr;
    return temp;
}

void push(node &top, int x)
{
    node temp = makenode(x);
    if (top == nullptr)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void Push(node &top, string x)
{
    node temp = makeNode(x);
    if (top == nullptr)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void pop(node &top)
{
    if (top == nullptr)
    {
        return;
    }
    top = top->next;
}

int gettop(node top)
{
    return top->data;
}

string getTop(node top)
{
    return top->x;
}

int main()
{
    node top = nullptr;

    long long n;
    cin >> n;

    // Chuyển đổi số nguyên sang dạng nhị phân và đẩy vào stack
    while (n)
    {
        int r = n % 2;
        push(top, r);
        n /= 2;
    }

    // In ra dạng nhị phân từ stack
    cout << "Binary representation: ";
    while (!empty(top))
    {
        cout << gettop(top);
        pop(top);
    }
    cout << endl;
    // Đọc và đẩy chuỗi vào stack
    string s;
    cin.ignore(); // Đọc bỏ kí tự '\n' sau khi nhập số nguyên
    getline(cin, s);
    stringstream ss(s);
    string word;

    // In ra chuỗi từ stack
    cout << "\nString: ";
    while (ss >> word)
    {
        Push(top, word);
    }
    while (!empty(top))
    {
        cout << getTop(top) << " ";
        pop(top);
    }

    return 0;
}
