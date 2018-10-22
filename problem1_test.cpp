// test suite for problem1.cpp

unsigned arithmetic_series_sum(unsigned a1, unsigned n, unsigned d);
unsigned sum_of_multiples_under_n(unsigned m, unsigned n);
unsigned long long gcd(unsigned long long x, unsigned long long y);
unsigned long long lcm(unsigned x, unsigned y);

#include <cxxtest/TestSuite.h>

class Problem1TestSuite : public CxxTest::TestSuite
{
public:
    void test_arithmetic_series_sum()
    {
        unsigned a1 = 1;
        unsigned n = 99;
        unsigned d = 7;

        unsigned sum = a1;
        for (unsigned i = 2, an = a1; i <= n; ++i, an += d, sum += an){}
        TS_ASSERT_EQUALS(arithmetic_series_sum(a1, n, d), sum);
        
        a1 = 71;
        n = 999;
        d = 13;

        sum = a1;
        for (unsigned i = 2, an = a1; i <= n; ++i, an += d, sum += an){}
        TS_ASSERT_EQUALS(arithmetic_series_sum(a1, n, d), sum);
    }
};

