#include <bits/stdc++.h>
using namespace std;

void CountingSort(vector<int> &arr, int n, int MAX)
{
    vector<int> count(MAX + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int dem = 0;
    for (int i = 0; i <= MAX; i++)
    {
        while (count[i] > 0)
        {
            arr[dem] = i;
            dem++;
            count[i]--;
        }
    }
}
int main()
{
    int n;
    cout << "Nhap vao kich thuoc mang : ";
    cin >> n;

    int MAX = INT_MIN;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        MAX = max(MAX, arr[i]);
    }

    CountingSort(arr, n, MAX);

    cout << "Ket qua la : "<<" ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}