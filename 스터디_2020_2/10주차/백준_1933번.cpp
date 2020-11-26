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


        // before에 넣기, 0->직사각형 시작, 1->직사각형 끝
        before.push_back({ {left,high }, { right, 0 } });
        before.push_back({ {right,high }, { left, 1 } });
    }

    // x좌표 순서대로 정렬
    sort(before.begin(), before.end());

    // 직전의 최고높이:prev
    int prev = -1;
    repair[{0, 0}] = 0;

    for (int i = 0; i < before.size(); i++)
    {
        int here = before[i].first.first;
        int other = before[i].second.first;
        int high = before[i].first.second;
        int pos = before[i].second.second;

        // 0->그대로 넣기
        if (pos == 0) {
            repair[{high, here}] = other;
        }
        // 1-> 시작점을 삭제
        else {
            auto it = repair.find({ high, other });
            repair.erase(it);
        }

        // 현재 남아있는 최대 높이 탐색
        auto it = repair.begin();
        int maxH = it->first.first;

        if (maxH != prev)
        {
            // 최대 높이 갱신
            prev = maxH;

            // 0-> 최대 갱신
            if (pos == 0) {
                final[here] = max(final[here], maxH);
            }
            else {
                // 1-> (아직 표시된 적이없다면) 최대값으로 갱신
                if (final.count(here) == 0) {
                    final[here] = maxH;
                }
                // 1->(표시된 적이 있다면) 최솟값으로 갱신
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