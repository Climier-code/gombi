#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    int n;
    //초기 입력 문자열
    string s; 

    cin >> s;
    cin >> n;
    stack<char> orgin, help;

    for (auto& x : s) {
        orgin.push(x);
    }

    while (n--) {
        char cmd;
        cin >> cmd; //명령어 입력 

        if (cmd == 'L') {
            // L->왼쪽으로 커서 이동
            if (!(orgin.empty())) { 
                help.push(orgin.top());
                orgin.pop();
            }
        }
        else if (cmd == 'D') {
            // D->오른쪽으로 커서 이동
            if (!help.empty()) {
                orgin.push(help.top());
                help.pop();
            }
        }
        else if (cmd == 'B') {
            // B->커서 앞에 있는 단어 삭제 
            if (!(orgin.empty())) {
                orgin.pop();
            }

        }
        else if (cmd == 'P') {
            // P->커서 뒤에 단어 추가 
            char x;
            cin >> x;
            orgin.push(x);
        }
    }
    // 순서대로 출력하기 위해
    while (!(orgin.empty())) {
        help.push(orgin.top());
        orgin.pop();
    }
    // 출력하면서 끝날때까지 pop
    while (!(help.empty())) {
        cout << help.top();
        help.pop();
    }
    return 0;
}