#include <bits/stdc++.h>
using namespace std;

void in1()
{
    freopen("a.txt", "r", stdin);
    freopen("a_out.txt", "w", stdout);
}
void in2()
{
    freopen("b.txt", "r", stdin);
    freopen("b_out.txt", "w", stdout);
}
void in3()
{
    freopen("c.txt", "r", stdin);
    freopen("c_out.txt", "w", stdout);
}
void in4()
{
    freopen("d.txt", "r", stdin);
    freopen("d_out.txt", "w", stdout);
}
void in5()
{
    freopen("e.txt", "r", stdin);
    freopen("e_out.txt", "w", stdout);
}
void in6()
{
    freopen("f.txt", "r", stdin);
    freopen("f_out.txt", "w", stdout);
}
struct building
{
    int x, y, l, c;
};
struct antena
{
    int r, c, id;
};

bool c(building a, building b)
{
    if (a.c != b.c)
        return a.c > b.c;
    // else
    //     return false;
    else if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y > b.y;
}
bool c1(antena a, antena b)
{
    if (a.c != b.c)
        return a.c > b.c;
    else
        return a.r < b.r;
}
building b[1000000];
antena a[1000000];

void solve()
{
    int h, w;
    cin >> h >> w;
    int n, m, R;
    cin >> n >> m >> R;
    for (int i = 0; i < n; i++)
        cin >> b[i].x >> b[i].y >> b[i].l >> b[i].c;
    for (int i = 0; i < m; i++)
        cin >> a[i].r >> a[i].c, a[i].id = i;

    sort(b, b + n, c);
    sort(a, a + m, c1);
    int x = min(n, m);
    cout << x << "\n";
    for (int i = 0; i < x; i++)
    {
        cout << a[i].id << " " << b[i].x << " " << b[i].y << "\n";
    }
}

int32_t main()
{
    in1();
    // in2();
    // in3();
    // in4();
    // in5();
    // in6();

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    cerr << "YES\n";
    return 0;
}