#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <limits>

int main()
{
    using Num = long double;
    std::ifstream in("in");
    std::ofstream out("out");
    size_t s;
    in >> s;

    std::vector<Num> v;
    v.reserve(s);
    std::copy(std::istream_iterator<Num>(in), std::istream_iterator<Num>(), std::back_inserter(v));

    switch (s) {
    case 0:
        out << 0 ;
        return 0;
    case 1: {
        auto v0(v[0]);
        out << (v0 > 0 ? v0 : 0);
        return 0; }
    case 2: {
        auto v0(v[0]), v1(v[1]);
        out << (v0 > 0 && v1 > 0 ? v0 + v1 : v0 > v1? v0 : v1);
        return 0; }
    }

    auto c  = *v.begin() > *++v.begin() ? v.begin() : ++v.begin();
    auto p1 = c + 1;
    auto p2 = c + 2;
    auto e  = v.end();
    while (true) {
        if (p1 == e || p2 == e) break;
        *p1 += *c;
        *p2 += *c;
        c = (*p1 > *p2 ? p1 : p2);
        p1 = c + 1;
        p2 = c + 2;
    }

    out << (*(e-1) > *(e-2) ? *(e-1): *(e-2));


    return 0;
}

