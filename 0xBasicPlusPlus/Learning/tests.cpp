#include "tests.hpp"
#include "exception_.h"
#include "datetime.h"

#define TEST(TestName, TestCase)\
    void Test_##TestName_##TestCase()

#define TEST_CALL(TestName, TestCase)\
    Test_##TestName_##TestCase()

#define EXCEPT_THROW(EX_NAME, EXPR)\
bool isCatch = false;\
try\
{\
    EXPR;\
}\
catch(EX_NAME&)\
{\
    isCatch = true;\
}\
std::cout << "Test function: " << __FUNCTION__ << std::endl << "File: " << __FILE__ << std::endl << "Line: " << __LINE__ << std::endl;\
isCatch ? std::cout << "OK" << std::endl : std::cout << "FAIL" << std::endl << std::endl;


#define NO_EXCEPT_THROW(EXPR)\
bool isCatch = false;\
try\
{\
    EXPR;\
}\
catch(...)\
{\
    isCatch = true;\
}\
std::cout << "Test function: " << __FUNCTION__ << std::endl << "File: " << __FILE__ << std::endl << "Line: " << __LINE__ << std::endl;\
!(isCatch) ? std::cout << "OK" << std::endl << std::endl : std::cout << "FAIL" << std::endl << std::endl;


TEST(Constructor, Normal)
{
    NO_EXCEPT_THROW(TimeInterval(Time(12, 0), Time(1, 23)));
}

TEST(Constructor, BadHours)
{
    EXCEPT_THROW(IncorrectHours,  TimeInterval(Time(12, 0), Time(1, 23)));
}

TEST(Constructor, BadMinutes)
{
    EXCEPT_THROW(IncorrectMinutes, TimeInterval(Time(12, 0), Time(1, 73)));
}

void test()
{
    TEST_CALL(Constructor, Normal);
    TEST_CALL(Constructor, BadHours);
    TEST_CALL(Constructor, BadMinutes);
}