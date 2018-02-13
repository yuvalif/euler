// test suite for problem2.cpp

unsigned long long fibonacci(unsigned n);
unsigned find_nearest_fibonacci_index(unsigned long long n);

#include <cxxtest/TestSuite.h>

class Problem2TestSuite : public CxxTest::TestSuite
{
public:
    void test_fibonacci()
    {
        TS_ASSERT_EQUALS(fibonacci(0), 0ULL);
        TS_ASSERT_EQUALS(fibonacci(1), 1ULL);
        TS_ASSERT_EQUALS(fibonacci(29), 514229ULL);
        TS_ASSERT_EQUALS(fibonacci(33), 3524578ULL);
        TS_ASSERT_EQUALS(fibonacci(59), 956722026041ULL);
    }
    
    void test_find_nearest_fibonacci_index()
    {
        TS_ASSERT_EQUALS(find_nearest_fibonacci_index(514229ULL), 29);
        TS_ASSERT_EQUALS(find_nearest_fibonacci_index(3524578ULL), 33);
        TS_ASSERT_EQUALS(find_nearest_fibonacci_index(956722026041ULL), 59);
        
        TS_ASSERT_EQUALS(find_nearest_fibonacci_index(514229ULL+1), 29);
        TS_ASSERT_EQUALS(find_nearest_fibonacci_index(3524578ULL+3), 33);
        TS_ASSERT_EQUALS(find_nearest_fibonacci_index(956722026041ULL+7), 59);
    }
};

