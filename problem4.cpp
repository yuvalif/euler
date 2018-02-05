// https://projecteuler.net/problem=4
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <string>

bool is_palindrome(unsigned n)
{
    const std::string string_n = std::to_string(n);
    std::string::const_iterator left = string_n.end() - 1;
    std::string::const_iterator right = string_n.begin();

    while (left > right)
    {
        if (*left != *right)
        {
            return false;
        }
        --left;
        ++right;
    }
    
    return true;
}

unsigned Problem4()
{
    const unsigned upper_bound = 999;
    const unsigned lower_bound = 100;
    unsigned largest_palindrome = 0;
    for (unsigned i = upper_bound; i > lower_bound; --i)
    {
        for (unsigned j = i-1; j > lower_bound; --j)
        {
            if (is_palindrome(i*j) && i*j > largest_palindrome)
            {
                largest_palindrome = i*j;
            }
        }
    }

    return largest_palindrome;
}

