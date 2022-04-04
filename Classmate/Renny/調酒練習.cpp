#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int, string> x,
         pair<int, string> y) {
    if (x.first != y.first) {
        return x.first > y.first;
    } else {
        return strcmp(x.second.c_str(), y.second.c_str()) < 0;
    }
}
string printArraystring(string str[], int n, int k) {
    map<string, int> m;

    for (int i = 1; i < n; i++) {
        m[str[i]]++;
    }

    vector<pair<int, string> > vec;

    for (auto it = m.begin(); it != m.end();
         it++) {
        vec.push_back(
            make_pair(it->second, it->first));
    }

    sort(vec.begin(), vec.end(), cmp);
    // for (int c = 0; c < 4; c++) {
    //     cout << "f: " << vec[c].first << ", s: " << vec[c].second << "\n";
    // }
    return vec[k - 1].second;
}

int main() {
    int num = 0;
    int k = 0;

    scanf("%d %d", &num, &k);

    string arr[500001];

    for (int i = 1; i <= num; i++) {
        cin >> arr[i];
    }

    int n = num + 1;

    cout << printArraystring(arr, n, k);

    return 0;
}