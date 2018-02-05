// https://projecteuler.net/problem=3
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

#include <vector>
#include <utility>
#include <math.h>

// return all prime factors in a vector, ordered from smallest to largets
std::vector<unsigned long long> prime_factors(unsigned long long x)
{
    const unsigned long long upper_bound = (const unsigned long long)sqrt(x);
    std::vector<unsigned long long> primes;

    // factors of x are in the range [2,sqrt(x)]
    for (auto i = 2ULL; i <= upper_bound; ++i)
    {
        if (x%i == 0)
        {
            // i is a factor of x
            bool is_prime = true;
            for (auto p : primes)
            {
                // i is a prime factor of x if none of the already
                // calculated prime factors of x is a factor of i
                if (i%p == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
            {
                primes.push_back(i);
            }
        }
    }

    return primes;
}

unsigned long long Problem3()
{
    const std::vector<unsigned long long>& primes = prime_factors(600851475143ULL);
    if (primes.size() > 0)
    {
        return primes[primes.size()-1];
    }
    return 0;
}

