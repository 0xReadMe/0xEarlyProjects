#include <stdio.h>
#include "school.h"
#include <iostream>

//Пустой урок
Subject Subject::empty;

Subject::Subject()
:name("")
,begin(Time())
,end(Time())
{}

Subject::Subject(std::string n, Time t1, Time t2)
:name(n)
,begin(t1)
,end(t2)
{}

bool Subject::operator == (Subject b) const
{
    return name == b.name && begin == b.begin && end == b.end;
};

std::ostream& operator << (std::ostream& out,const Subject s)
{
    out << s.name << " - " << s.begin << " -> " << s.end;
    return out;
}

bool Subject::IsEmpty()
{
    return (name == Subject::empty.name &&
            begin == Subject::empty.begin &&
            end == Subject::empty.end);
}

//Возвращает начало урока
Time Subject::GetBegin()
{
    return begin;
}

//Возвращает конец урока
Time Subject::GetEnd() const
{
    return end;
}

//Возвращает интервал начала и конца урока
TimeInterval Subject::GetDuration() const
{
    return TimeInterval(begin, end);
}

//Кабинет

Room::Room()
:number(0)
,begin(Time())
,end(Time())
,events()
{}

//Инициализация
//n - номер кабинета
//t1 - открытие кабинета
//t2 - закрытие кабинета
Room::Room(int n, Time t1, Time t2)
:number(n)
,begin(t1)
,end(t2)
,events()
{}

Time Room::GetBegin()
{
    return begin;
}

Time Room::GetEnd()
{
    return end;
}

TimeInterval Room::GetInterval() const
{
    return TimeInterval(begin, end);
}

bool Room::IsAvailable(Subject s) const
{
    TimeInterval t = GetInterval();
    if (!(events.empty()))
    {
        Subject back = events.back();
        return t.IsContain(s.GetDuration()) && (s.GetDuration() >= back.GetDuration());
    }
    return t.IsContain(s.GetDuration());
}
 
bool Room::AddEvent(Subject s)
{
    if (!(s.IsEmpty()))
    {
        events.push_back(s);
        return true;
    }
    else
    {
        return false;
    }
}

Subject Room::GetBestEvent(Subject min, Subject s)
{
    if ((s.GetEnd() < min.GetEnd() || min.IsEmpty()) && (s.GetEnd() < GetEnd()))
    {
        min = s;
    }
    return min;
}

std::ostream& operator << (std::ostream& out,const Room r)
{
    out << r.number << " - " << r.begin << " -> " << r.end;
    return out;
}
