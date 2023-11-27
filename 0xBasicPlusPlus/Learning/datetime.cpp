#include <stdio.h>
#include "datetime.h"
#include "exception_.h"
#include <iostream>

//Время
Time::Time()
:hours(0)
,minutes(0)
{}

Time::Time(int h, int m)
:hours(h)
,minutes(m)
{
    
}

bool Time::operator == (const Time& b) const
{
    return hours == b.hours && minutes == b.minutes;
}

bool Time::operator < (const Time& b) const
{
    return hours < b.hours || (hours == b.hours && minutes < b.minutes);
}

std::ostream& operator << (std::ostream& out, const Time& t)
{
    std::string sep = t.minutes < 10 ? ":0" : ":";
    out << t.hours << sep << t.minutes;
    return out;
}

bool Time::IsCorrectHours()
{
    return hours < 24 && hours > -1;
}

bool Time::IsCorrectMinutes()
{
    return minutes < 60 && minutes > -1;
}

Time Time::operator + (const Time& b)
{
    return Time(hours + b.hours, minutes + b.minutes);
}

//Интервал времени
TimeInterval::TimeInterval(Time a, Time b)
:begin(a)
,end(b)
{
    if(!(a.IsCorrectHours() && b.IsCorrectHours()))
    {
        throw IncorrectHours("Incorrect hours");
    }
    
    if(!(a.IsCorrectMinutes() && b.IsCorrectMinutes()))
    {
        throw IncorrectMinutes("Incorrect minutes");
    }
}

bool TimeInterval::IsContain(Time a) const
{
    return (!(a < begin) && !(end < a));
}

bool TimeInterval::IsContain(TimeInterval a) const
{
    return (!(a.begin < begin) && !(end < a.end));
}

bool TimeInterval::operator == (const TimeInterval& a) const
{
    return (a.begin == begin && a.end == end);
}

bool TimeInterval::operator >= (const TimeInterval& a) const
{
    return !(begin < a.end);
}

TimeInterval TimeInterval::operator + (TimeInterval& a)
{
    begin = begin + a.begin;
    end = end + a.end;
    if(!(end < Time(24, 00)))
    {
        throw IncopetibleOperands("Incopetible operands");
    }
    return *this;
}
std::ostream& operator << (std::ostream& out,const TimeInterval r)
{
    out << r.begin << " -> " << r.end;
    return out;
}
