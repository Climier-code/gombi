#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<pair<pii, pii> > before;

map<pii, int, greater<> > repair;

map<int, int> final;

int main()
{
    int n;
    scanf("%d", &n);

    
    
    for (int i = 0; i < n; i++)
    {
        int left,  high, right;
        scanf("%d %d %d", &left, &high, &right);


        // before�� �ֱ�, 0->���簢�� ����, 1->���簢�� ��
        before.push_back({ {left,high }, { right, 0 } });
        before.push_back({ {right,high }, { left, 1 } });
    }

    // x��ǥ ������� ����
    sort(before.begin(), before.end());

    // ������ �ְ����:prev
    int prev = -1;
    repair[{0, 0}] = 0;

    for (int i = 0; i < before.size(); i++)
    {
        int here = before[i].first.first;
        int other = before[i].second.first;
        int high = before[i].first.second;
        int pos = before[i].second.second;

        // 0->�״�� �ֱ�
        if (pos == 0) {
            repair[{high, here}] = other;
        }
        // 1-> �������� ����
        else {
            auto it = repair.find({ high, other });
            repair.erase(it);
        }

        // ���� �����ִ� �ִ� ���� Ž��
        auto it = repair.begin();
        int maxH = it->first.first;

        if (maxH != prev)
        {
            // �ִ� ���� ����
            prev = maxH;

            // 0-> �ִ� ����
            if (pos == 0) {
                final[here] = max(final[here], maxH);
            }
            else {
                // 1-> (���� ǥ�õ� ���̾��ٸ�) �ִ밪���� ����
                if (final.count(here) == 0) {
                    final[here] = maxH;
                }
                // 1->(ǥ�õ� ���� �ִٸ�) �ּڰ����� ����
                else {
                    final[here] = min(final[here], maxH);
                }
            }
        }
    }

    prev = -1;
    for (auto it = final.begin(); it != final.end(); it++) {
        if (it->second != prev)
            printf("%d %d ", it->first, it->second);
        prev = it->second;
    }
    return 0;
}