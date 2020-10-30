#include <iostream>
using namespace std;

const int MAX = 100000 + 1;

int N;
long long int arr[MAX];
long long int resA, resB;

int main() {

	//��ü ��� �� N�Է�
	cin >> N;
	//��׵��� Ư�� �� �Է�
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//���ʿ��� �߽����� �ٰ����� index�� �ʱⰪ
	int left = 0;
	int right = N - 1;

	//������� �ʱⰪ
	int resLiquid = abs(arr[left] + arr[right]);
	resA = arr[left];
	resB = arr[right];

	//���ʿ��� �߽����� ���� ���� �ݺ�(��������), ��� ��� Ž�� �Ϸ� �� ����
	while (left < right) {
		int tempLiquid = arr[left] + arr[right];
		if (abs(tempLiquid) < resLiquid) {
			resLiquid = abs(tempLiquid);
			resA = arr[left];
			resB = arr[right];
		}

		if (tempLiquid < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	//�����ϴ� ����� Ư���� 2�� ���
	cout << resA << " " << resB << "\n";
}