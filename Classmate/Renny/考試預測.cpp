#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

unordered_map<int, pair<int, int>> MP;
vector<pair<int, bool>> l;
int main() {
    int n, m, count = 0, dc = 0;  // delete count
    cin >> n >> m;
    while (m--) {
        string str;
        cin >> str;
        int a, b;
        if (str == "set") {
            cin >> a >> b;

            if (MP.count(a)) {
                // 更新
                l[MP[a].s].s = false;
                l.push_back(make_pair(a, true));
                MP[a] = make_pair(b, l.size() - 1);
            } else {
                if (count >= n) {
                    while (l.at(dc).s == false)
                        dc++;
                    MP.erase(l.at(dc).f);
                    dc++;
                }
                l.push_back(make_pair(a, true));
                MP[a] = make_pair(b, l.size() - 1);
                // for (auto i = MP.begin(); i != MP.end(); i++)
                // cout << "i->first" << i->first
                //  << " i->second.f:" << i->second.f << "  i->second.s:" << i->second.s << endl;
                // for (int i = 0; i < l.size(); i++) {
                // if (i == dc)
                // cout << "dc"
                //  << endl;
                // cout << "l[i].f:" << l[i].f << " l[i].s:" << l[i].s << endl;}
                count++;
            }
        } else {
            cin >> a;
            if (MP.count(a)) {
                l[MP[a].s].s = false;
                l.push_back(make_pair(a, true));
                MP[a] = make_pair(MP[a].f, l.size() - 1);
                cout << MP[a].f;
            } else
                cout << "-1";
            cout << endl;
        }
        // cout << str << endl;
        // for (auto i = MP.begin(); i != MP.end(); i++)
        //     cout << "i->first" << i->first
        //          << " i->second.f:" << i->second.f << "  i->second.s:" << i->second.s << endl;
        // for (int i = 0; i < l.size(); i++) {
        //     if (i == dc)
        //         cout << "dc"
        //              << endl;
        //     cout << "l[i].f:" << l[i].f << " l[i].s:" << l[i].s << endl;
        // }
    }
}
/*
2 12
get 4
set 4 4
set 2 1
set 3 3
set 3 33
get 4
get 3
set 2 3
set 5 2
get 3
set 4 3
get 5

2 8
set 3 4
set 3 6
set 3 5
get 3
set 2 5
get 3
set 3 9
get 2
*/