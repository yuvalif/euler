// https://projecteuler.net/problem=5
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// 
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <vector>
#include <algorithm>
#include <math.h>

// factorize a number into its prime factors
// the returned vector is holding the power of each prime factor
// first element in the vector (element zero) indicate the power of 1
// second element (element one) indicate the power of 2 etc.
std::vector<unsigned> factorize(unsigned n)
{
    std::vector<unsigned> v(n, 0);
    unsigned m = 2;
    // 1 is always a factor of n
    v[0] = 1;
    while (n > 1)
    {
        if (n%m == 0)
        {
            // m is a factor of n
            ++v[m-1];
            n /= m;
        }
        else
        {
            // m is not a factor of n
            ++m;
        }
    }

    return v;
}

// given a vectror of prime factors, the original number is calculated
// under the assumptions that each entry in the vector indicate the power of the factor
// first element in the vector (element zero) indicate the power of 1
// second element (element one) indicate the power of 2 etc.
unsigned defactorize(const std::vector<unsigned> v)
{
    auto total = 1U;
    auto index = 1U;
    std::for_each(v.begin(), v.end(), [&](unsigned n){total *= pow(index++, n);});
    return total;
}

unsigned long long Problem5()
{
    std::vector<unsigned> max_factors(20, 0);
    for (auto i = 1U; i <= max_factors.size(); ++i)
    {
        const std::vector<unsigned>& v = factorize(i);
        for (auto j = 0U; j < v.size(); ++j)
        {
            max_factors[j] = std::max(max_factors[j], v[j]);
        }
    }

    return defactorize(max_factors);
}

