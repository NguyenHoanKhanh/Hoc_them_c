#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> x(n1);
    vector<int> y(n2);

    for (int i = 0; i < n1; i++)
    {
        x[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        y[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (x[i] <= y[j])
        {
            arr[l] = x[i];
            i++;
        }

        else
        {
            arr[l] = y[j];
            j++;
        }
        l++;
    }

    while (i < n1)
    {
        arr[l] = x[i];
        l++;
        i++;
    }
    while (j < n2)
    {
        arr[l] = y[j];
        l++;
        j++;
    }
}

void MergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge(arr, l, m, r);
}

int main()
{
    int n;
    cout << "Nhap vao kich thuoc mang : ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, n - 1);
    cout << "Ket qua sap xep la : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}