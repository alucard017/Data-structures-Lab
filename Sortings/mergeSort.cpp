#include <bits/stdc++.h>
using namespace std;

void MERGE(int *arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[q + i + 1];
    }
    // L[n1] = INT_MAX;
    // R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i];
            i++;
        }
        else
        {
            arr[k++] = R[j];
            j++;
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}
void MERGE_SORT(int *arr, int p, int r)
{
    if (p >= r)
        return;
    int q = floor((p + r) / 2);
    MERGE_SORT(arr, p, q);
    MERGE_SORT(arr, q + 1, r);
    MERGE(arr, p, q, r);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    MERGE_SORT(arr, 0, n - 1);
    cout << "After Sorting\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}