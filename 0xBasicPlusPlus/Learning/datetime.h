#ifndef base_h
#define base_h
#include <iostream>

//Время в часах и минутах
class Time
{
public:
    
    Time();
    
    //Инициализация времени
    //h - часы
    //m - минуты
    Time(int h, int m);
    
    bool operator == (const Time& a) const;
    
    bool operator < (const Time& a) const;
    
    friend std::ostream& operator << (std::ostream& out, const Time& t);
    
    Time operator + (const Time& b);
    
    bool IsCorrectHours();
    
    bool IsCorrectMinutes();
    
private:
    int hours, minutes;
};

//Интервал времени
class TimeInterval
{
public:
    
    TimeInterval(Time a, Time b);
    
    bool IsContain(Time a) const;
    
    bool IsContain(TimeInterval a) const;
    
    bool operator == (const TimeInterval& a) const;
    
    bool operator >= (const TimeInterval& a) const;
    
    TimeInterval operator + (TimeInterval& a);
    
    friend std::ostream& operator << (std::ostream& out,const TimeInterval r);
    
private:
    Time begin;
    Time end;
};

#endif /* base_h */
