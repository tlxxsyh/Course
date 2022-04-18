#include <iostream>
#include <algorithm>

using namespace std;

int BinSearch(int arr[], int target,int length);

int main()
{
	int a[10];
	int n,ans, target;
	cout << "你需要在多少个数中查找呢:" << endl;
	cin >> n;
	cout << "请输入这"<<n<<"个数：" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "你要找哪个数呢:" << endl;
	cin >> target;
	ans = BinSearch(a, target,n);
	if (ans == -1)
		cout << "Not Found!" << endl;
	else
		cout << "在" << ans + 1 << "位置" << endl;
	return 0;
}

int BinSearch(int arr[], int target,int length)
{
	int high, low, mid;
	low = arr[0];
	high = arr[length-1];
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
