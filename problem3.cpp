// https://projecteuler.net/problem=3
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    const unsigned long long x = 600851475143;
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

    if (primes.size() > 0)
    {
        std::cout << primes[primes.size()-1] << std::endl;
    }
    return 0;
}

