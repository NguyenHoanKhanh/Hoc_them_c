#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &a, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> x(n1);
    vector<int> y(n2);

    for (int i = 0; i < n1; i++)
    {
        x[i] = a[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        y[j] = a[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (x[i] <= y[j])
        {
            a[k] = x[i];
            i++;
        }
        else
        {
            a[k] = y[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = x[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = y[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}

int main()
{
    int n;
    cout << "Nhap vao kich thuoc mang : ";
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    MergeSort(a, 0, n - 1);
    for (int x : a)
    {
        cout << x << " ";
    }

    return 0;
}
