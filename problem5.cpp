// https://projecteuler.net/problem=5
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// 
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <unordered_map>
#include <algorithm>
#include <math.h>

typedef std::unordered_map<unsigned, unsigned char> prime_factors_t;

// factorize a number into its prime factors
// the returned list is holding the prime factor and its exponent
prime_factors_t factorize(unsigned n)
{
    prime_factors_t v;
    unsigned m = 2;
    // 1 is always a factor of n
    v[1] = 1;
    while (n > 1)
    {
        if (n%m == 0)
        {
            // m is a factor of n
            const auto it = v.find(m);
            if (it == v.end())
            {
                // insert new prime and set exponent to 1
                v[m] = 1;
            }
            else
            {
                // prime exists- increment exponent
                ++(it->second);
            }
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

// given a list of prime factors, the original number is calculated
// under the assumptions that each entry in the vector indicate the power of the prime factor
unsigned defactorize(const prime_factors_t& v)
{
    auto total = 1U;
    std::for_each(v.begin(), v.end(), 
            [&](const auto& f){total *= pow(f.first, f.second);});
    return total;
}

unsigned long long Problem5()
{
    prime_factors_t max_factors;
    for (auto i = 1U; i <= 20; ++i)
    {
        // factorize the next number
        const prime_factors_t& v = factorize(i);
        for (const auto& f: v)
        {
            // check if prime is already in the max factors list
            const auto it = max_factors.find(f.first);
            if (it == v.end())
            {
                // add to list
                max_factors.insert(f);
            }
            else
            {
                // update to max value between existing and new
                it->second = std::max(it->second, f.second);
            }
        }
    }

    return defactorize(max_factors);
}

