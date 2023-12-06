#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r ; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
    }
    i++;
    swap(a[i], a[r]);
    
    return i;
}

void QuickSort(vector<int>&a, int l, int r)
{
    if(l < r)
    {
    int q = partition(a, l, r);
    QuickSort(a, l, q - 1);
    QuickSort(a, q + 1, r);     
    }
}
int main()
{
    int n;
    cout << "Nhap va kich thuoc mang : ";
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    QuickSort(a, 0, n - 1);
    cout<<"Ket qua sap xep : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}