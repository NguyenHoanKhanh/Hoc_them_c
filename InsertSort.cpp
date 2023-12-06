#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = arr[i], pos = i - 1;
        while (pos >= 0 && x < arr[pos])
        {
            arr[pos + 1] = arr[pos];
            --pos;
        }
        arr[pos + 1] = x;
    }
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
    InsertSort(arr, n);
    cout << "Ket qua la : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}