//
//  station.cpp
//  Practic1
//
//  Created by Andrey on 21.05.2022.
//

#include <stdio.h>
#include "station.h"

Transport Transport::empty;

Transport::Transport()
:number()
,arrival(Time(0, 0))
,departure(Time(0, 0))
,type()
{}

Transport::Transport(int n, int t, Time a, Time b)
:number(n)
,arrival(a)
,departure(b)
,type(t)
{}

bool Transport::IsEmpty()
{
    return (number == empty.number) && (GetDuration() == empty.GetDuration()) && (type == empty.type);
}

TimeInterval Transport::GetDuration() const
{
    return TimeInterval(arrival, departure);
}

Time Transport::GetEnd()
{
    return departure;
}

std::string Transport::ToStr() const
{
    switch (type) {
        case bus:
            return "bus";
        case train:
            return "train";
        default:
            return "unknown type";
    }
}
Station::Station()
:name()
{}

Station::Station(std::string n)
:name(n)
{}

BusStation::BusStation()
:Station()
{}

BusStation::BusStation(std::string n)
:Station(n)
{}

bool BusStation::AddEvent(Transport t)
{
    if (!(t.IsEmpty()))
    {
        events.push_back(t);
        return true;
    }
    return false;
}

bool BusStation::IsAvailable(Transport t) const
{
    if (!(events.empty()))
    {
        Transport back = events.back();
        return t.GetDuration() >= back.GetDuration();
    }
    return true;
}

Transport BusStation::GetBestEvent(Transport min, Transport s)
{
    if ((s.GetEnd() < min.GetEnd() || min.IsEmpty()))
    {
        min = s;
    }
    return min;
}

TrainStation::TrainStation()
:Station()
,begin(Time(0, 0))
,end(Time(0, 0))
{}

TrainStation::TrainStation(std::string n, Time a, Time b)
:Station(n)
,begin(a)
,end(b)
{}

bool TrainStation::AddEvent(Transport t)
{
    if (!(t.IsEmpty()))
    {
        events.push_back(t);
        return true;
    }
    return false;
}

TimeInterval TrainStation::GetInterval() const
{
    return TimeInterval(begin,end);
}

bool TrainStation::IsAvailable(Transport t) const
{
    TimeInterval a = GetInterval();
    if (!(events.empty()))
    {
        Transport back = events.back();
        return a.IsContain(t.GetDuration()) && (t.GetDuration() >= back.GetDuration());
    }
    return a.IsContain(t.GetDuration());
}

Time TrainStation::GetEnd()
{
    return end;
}

Transport TrainStation::GetBestEvent(Transport min, Transport s)
{
    if ((s.GetEnd() < min.GetEnd() || min.IsEmpty()) && (s.GetEnd() < GetEnd()))
    {
        min = s;
    }
    return min;
}

std::ostream& operator << (std::ostream& out, const Transport r)
{
    out << r.ToStr() << " № " <<r.number << " - " << r.arrival << " -> " << r.departure;
    return out;
}
