#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    int n;
    //�ʱ� �Է� ���ڿ�
    string s; 

    cin >> s;
    cin >> n;
    stack<char> orgin, help;

    for (auto& x : s) {
        orgin.push(x);
    }

    while (n--) {
        char cmd;
        cin >> cmd; //��ɾ� �Է� 

        if (cmd == 'L') {
            // L->�������� Ŀ�� �̵�
            if (!(orgin.empty())) { 
                help.push(orgin.top());
                orgin.pop();
            }
        }
        else if (cmd == 'D') {
            // D->���������� Ŀ�� �̵�
            if (!help.empty()) {
                orgin.push(help.top());
                help.pop();
            }
        }
        else if (cmd == 'B') {
            // B->Ŀ�� �տ� �ִ� �ܾ� ���� 
            if (!(orgin.empty())) {
                orgin.pop();
            }

        }
        else if (cmd == 'P') {
            // P->Ŀ�� �ڿ� �ܾ� �߰� 
            char x;
            cin >> x;
            orgin.push(x);
        }
    }
    // ������� ����ϱ� ����
    while (!(orgin.empty())) {
        help.push(orgin.top());
        orgin.pop();
    }
    // ����ϸ鼭 ���������� pop
    while (!(help.empty())) {
        cout << help.top();
        help.pop();
    }
    return 0;
}