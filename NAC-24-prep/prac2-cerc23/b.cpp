#include <bits/stdc++.h>
#define pb push_back
#define N 55

#define CI const int&
using namespace std;
struct Point {
    int x,y;
    inline Point(const int& X = 0, const int& Y = 0) { x = X; y = Y; }
    int quad(void) {
        if (x > 0 && y >= 0)
            return 1;
        if (x <= 0 && y > 0)
            return 2;
        if (x < 0 && y <= 0)
            return 3;
        if (x >= 0 && y < 0)
            return 4;
        return 0;
    }
    inline int Cross(const Point& ots) {
        return x * ots.y - y * ots.x;
    }
    friend inline bool operator < (Point A, Point B) {
        if (A.quad() != B.quad())
            return A.quad() < B.quad();
        return A.Cross(B) < 0;
    }
};

inline double dist(const Point& A, const Point& B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int n, x, y;
char s[N];
vector <Point> P[2];

inline double solve(vector <Point> pnt) {
    if (pnt.empty())
        return 0;
    Point s = pnt[0];
    for (auto [x,y] : pnt)
        if (x < s.x || (x == s.x && y < s.y))
            s = Point(x,y);
    for (auto& [x,y] : pnt) {
        x -= s.x;
        y -= s.y;
    }
    sort(pnt.begin(), pnt.end());
    int m = pnt.size() / 2;
    double ret = 0;
    for (int i = 0; i + m < pnt.size(); ++ i)
        ret += dist(pnt[i], pnt[i + m]);
    return ret;
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++ i) {
        cin >> x >> y;
        P[s[i] == 'B'].pb(Point(x, y));
    }
    cout << setprecision(9) << solve(P[0]) + solve(P[1]);
    return 0;
}
