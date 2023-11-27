//
//  station.h
//  Practic1
//
//  Created by Andrey on 21.05.2022.
//

#ifndef station_h
#define station_h
#include <iostream>
#include "datetime.h"
#include "vector"

class Transport
{
public:
    Transport();
    
    Transport(int n, int t, Time a, Time b);
    
    static Transport empty;
    
    TimeInterval GetDuration() const;
    
    bool IsEmpty();
    
    Time GetEnd();
    
    std::string ToStr() const;
    
    friend std::ostream& operator << (std::ostream& out, const Transport r);
    
private:
    int type;
    enum type {bus = 1, train};
    int number;
    Time arrival;
    Time departure;
};


class Station
{
public:
    virtual bool AddEvent(Transport t) = 0;
    
    virtual bool IsAvailable(Transport t) const = 0;
    
    virtual Transport GetBestEvent(Transport min, Transport t) = 0;
    
    std::vector<Transport> events;
    
protected:
    Station();
    Station(std::string n);
    std::string name;
};


class BusStation : public Station
{
public:
    BusStation();
    
    BusStation(std::string n);
    
    bool AddEvent(Transport t) override;
    
    bool IsAvailable(Transport t) const override;
    
    Transport GetBestEvent(Transport min, Transport t) override;
};


class TrainStation : public Station
{
public:
    TrainStation();
    
    TrainStation(std::string n, Time a, Time b);
    
    bool AddEvent(Transport t) override;
    
    bool IsAvailable(Transport t) const override;
    
    Transport GetBestEvent(Transport min, Transport t) override;
    
    TimeInterval GetInterval() const;
    
    Time GetEnd();
    
private:
    Time begin;
    Time end;
};
#endif /* station_h */
