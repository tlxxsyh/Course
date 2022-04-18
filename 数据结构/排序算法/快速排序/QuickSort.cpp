#include <iostream>
#include <algorithm>

using namespace std;

int Paritition1(int A[], int low, int high);
void QuickSort(int A[], int low, int high);

int main()
{
    int a[9999];
    int n;
    cout << "本程序展示按递增排序" << endl;
    cout << "你想排序几个数呢：";
    cin >> n;
    cout << "请依次输入你想排序的" << n << "个数：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    QuickSort(a, 0, n - 1);
    cout << "排序结果为：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
	return 0;
}

int Paritition1(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high) {
        int pivot = Paritition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}
