// test suite for problem2.cpp

unsigned long long fibonacci(unsigned n);
unsigned find_nearest_fibonacci_index(unsigned long long n);

#include <cxxtest/TestSuite.h>
#include <map>

class Problem2TestSuite : public CxxTest::TestSuite
{
    // list of fibonacci numbers and indexes to test
    const std::map<unsigned, unsigned long long> results {
        {0, 0}, 
        {2, 1}, 
        {10, 55},
        {14, 377},
        {20, 6765},
        {29, 514229},
        {33, 3524578},
        {59, 956722026041}
    };

public:
    void test_fibonacci()
    {
        for (auto result : results)
        {
            TS_ASSERT_EQUALS(fibonacci(result.first), result.second);
        }
    }
    
    void test_find_nearest_fibonacci_index()
    {
        for (auto result : results)
        {
            TS_ASSERT_EQUALS(find_nearest_fibonacci_index(result.second), result.first);
        }
    }
};

