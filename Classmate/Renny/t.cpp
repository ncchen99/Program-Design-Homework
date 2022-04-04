#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

bool cmp(pair<int, string> x,
         pair<int, string> y) {
    if (x.first < y.first) {
        return true;
    }

    else if (x.first > y.first) {
        return false;
    }

    else {
        if (x.second < y.second) {
            return true;
        } else {
            return false;
        }
    }
}
string printArraystring(string str[], int n, int k) {
    map<string, int> m;

    for (int i = 0; i < n; i++) {
        m[str[i]]++;
    }

    vector<pair<int, string> > vec;

    for (auto it = m.begin(); it != m.end();
         it++) {
        vec.push_back(
            make_pair(it->second, it->first));
    }

    sort(vec.begin(), vec.end(), cmp);
    for (int c = 0; c < 4; c++) {
        cout << vec[c].second << "\n";
    }
    return vec[k].second;
}

int main() {
    int num = 0;
    int k = 0;

    scanf("%d %d", &num, &k);

    string arr[num + 1];

    for (int i = 1; i <= num; i++) {
        cin >> arr[i];
    }

    int n = num + 1;

    cout << printArraystring(arr, n, k);

    return 0;
}