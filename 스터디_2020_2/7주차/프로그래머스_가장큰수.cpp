#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//���� ������ ���� � ���� ū�� �Ǻ��ϴ� bigS�Լ� ����
bool bigS(const string& a, const string& b) {
	return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {

	string answer = "";
	vector<string> strArr;

	//numbers�� �������� string���� ����ȯ �Ͽ� strArr�� ����
	for (int i = 0; i < numbers.size(); i++) {
		strArr.push_back(to_string(numbers.at(i)));
	}

	//������ ���� bigS�� �̿��� sort(<algorithm>������Ͽ� ����)
	sort(strArr.begin(), strArr.end(), bigS);

	//������ �͵��� �̾����
	for (string str : strArr) {
		answer += str;
	}

	//���࿡ 0 �Ѱ��̸� ���ڿ� "0"��ȯ
	if (answer[0] == '0') {
		return "0";
	}
	return answer;
}