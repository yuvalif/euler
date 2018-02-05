// https://projecteuler.net/problem=4
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
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

int main()
{
    unsigned largest_palindrome = 0;
    for (unsigned i = 999; i > 100; --i)
    {
        for (unsigned j = i-1; j > 100; --j)
        {
            if (is_palindrome(i*j) && i*j > largest_palindrome)
            {
                largest_palindrome = i*j;
            }
        }
    }

    std::cout << largest_palindrome << std::endl;
        
    return 0;
}

