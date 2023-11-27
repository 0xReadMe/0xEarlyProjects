#include "datetime.h"
#include "school.h"
#ifndef algorithm_h
#define algorithm_h

//Возвращает предмет на вход
template <typename Schedule, typename Event>
bool GetNextEvent(Schedule& eventQueue, std::vector<Event> events)
{
    Event min = Event::empty;

    for (auto& event : events)
    {
        if (eventQueue.IsAvailable(event))
        {
            min = eventQueue.GetBestEvent(min, event);
        }
    }
    return eventQueue.AddEvent(min);
}

//Составляет расписание
template <typename Schedule, typename Event>
Schedule GetSchedule(Schedule& eventQueue, std::vector<Event> events)
{
    while(GetNextEvent(eventQueue, events))
    {}
    return eventQueue;
}

#endif /* algorithm_h */
