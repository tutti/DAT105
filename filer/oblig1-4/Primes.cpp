#include <vector>
#include <math.h>

using namespace std;

vector<int> primes(int max) {
    vector<int> p;
    vector<bool> marks;

    marks.push_back(false);
    marks.push_back(false);

    for (int i = 2; i <= max; ++i) {
        marks.push_back(true);
    }

    for (int i = 2; i <= sqrt(max); ++i) {
        if (!marks[i]) {
            continue;
        }

        for (int j = 2; j*i <= max; ++j) {
            marks[j*i] = false;
        }
    }

    for (int i = 0; i < marks.size(); ++i) {
        if (marks[i]) {
            p.push_back(i);
        }
    }

    return p;
}