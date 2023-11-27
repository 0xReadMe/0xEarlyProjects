#ifndef test_h
#define test_h
#include <iostream>
#include <exception>

class IncorrectTimeInterval : std::exception
{
public:
    IncorrectTimeInterval(std::string message_)
    :exception()
    ,message(message_)
    {}
    
    const char* what() const noexcept override
    {
        return message.c_str();
    }
    
private:
    std::string message;
};


class IncopetibleOperands : std::exception
{
public:
    IncopetibleOperands(std::string message_)
    :exception()
    ,message(message_)
    {}
    
    const char* what() const noexcept override
    {
        return message.c_str();
    }
    
private:
    std::string message;
};


class IncorrectHours : std::exception
{
public:
    IncorrectHours(std::string message_)
    :exception()
    ,message(message_)
    {}
    
    const char* what() const noexcept override
    {
        return message.c_str();
    }
    
private:
    std::string message;
};


class IncorrectMinutes : std::exception
{
public:
    IncorrectMinutes(std::string message_)
    :exception()
    ,message(message_)
    {}
    
    const char* what() const noexcept override
    {
        return message.c_str();
    }
    
private:
    std::string message;
};
#endif /* test_h */
