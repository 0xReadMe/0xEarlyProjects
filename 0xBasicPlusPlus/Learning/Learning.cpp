#include <iostream>
#include <vector>
#include "datetime.h"
#include "alg_schedule.h"
#include "school.h"
#include "station.h"
#include "exception_.h"
#include "tests.hpp"

int main()
{
    //Предметы
    
    std::vector<Subject> subjects = {
        Subject("Рисование", Time(9, 0), Time(10, 0)),
        Subject("Английский", Time(8, 30), Time(10, 30)),
        Subject("Математика", Time(10, 0), Time(11, 0)),
        Subject("Информатика", Time(10, 30), Time(11, 30)),
        Subject("Музыка", Time(11, 30), Time(13, 00))
    };
    
    std::vector<Transport> buses = {
        Transport(2, 1, Time(8, 0), Time(10, 0)),
        Transport(4, 1, Time(8, 30), Time(10, 30)),
        Transport(6, 1, Time(10, 0), Time(11, 0)),
        Transport(22, 1, Time(10, 30), Time(11, 30)),
        Transport(6, 1, Time(11, 30), Time(13, 00))
    };
    
    std::vector<Transport> trains = {
        Transport(10, 2, Time(8, 0), Time(10, 0)),
        Transport(14, 2, Time(8, 30), Time(10, 30)),
        Transport(5, 2, Time(10, 0), Time(11, 0)),
        Transport(12, 2, Time(10, 30), Time(11, 30)),
        Transport(6, 2, Time(11, 30), Time(14, 00))
    };
    
    Room r(11, Time(8, 0), Time(14, 0));
    TrainStation t("Казанский", Time(8, 0), Time(14, 0));
    BusStation b("Красногвардейская");
    
    
    //Создаем расписание при помощи GetSchedule
    GetSchedule(b, buses);
    GetSchedule(t, trains);
    GetSchedule(r, subjects);
    
    //Печатаем расписания
    
    for(int i = 0; i < r.events.size(); i++)
    {
        std::cout << r.events[i] << std::endl;
    }
    
    std::cout << std::endl;
    for(int i = 0; i < b.events.size(); i++)
    {
        std::cout << b.events[i] << std::endl;
    }
    
    std::cout << std::endl;
    for(int i = 0; i < t.events.size(); i++)
    {
        std::cout << t.events[i] << std::endl;
    }
    
    std::cout << std::endl;
    test();
    return 0;
}
