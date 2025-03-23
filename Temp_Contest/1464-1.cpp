#include <iostream>

using namespace std;

int main()
{
    int h_lo, h_hi, s_lo, s_hi, v_lo, v_hi;
    int r, g, b;
    cin >> h_lo >> h_hi >> s_lo >> s_hi >> v_lo >> v_hi;
    cin >> r >> g >> b;

    double h, s, v;
    v = max({r, g, b});
    s = 255 * (v - min({r, g, b})) / v;
    
    if(v == r)
    {
        h = 60 * (g - b) / (v - min({r, g, b}));
    }
    else if(v == g)
    {
        h = 120 + 60 * (b - r) / (v - min({r, g, b}));
    }
    else
    {
        h = 240 + 60 * (r - g) / (v - min({r, g, b}));
    }

    if(h < 0)
    {
        h += 360;
    }

    if(h_lo <= h && h <= h_hi && s_lo <= s && s <= s_hi && v_lo <= v && v <= v_hi)
    {
        cout << "Lumi will like it.";
    }
    else
    {
        cout << "Lumi will not like it.";
    }
}