#ifndef school_h
#define school_h
#include <vector>
#include "datetime.h"

//Урок
class Subject
{
public:
    
    Subject();
    
    //Инициализация урока
    //n - название урока
    //t1 - начало
    //t2 - конец
    Subject(std::string n, Time t1, Time t2);
    
    bool IsEmpty();
    
    Time GetBegin();
    
    Time GetEnd() const;
    
    TimeInterval GetDuration() const;
    
    bool operator == (Subject b) const;
    
    friend std::ostream& operator << (std::ostream& out, const Subject s);
    
    //Пустой урок
    static Subject empty;
    
private:
    std::string name; //Название урока
    Time begin;       //Начало урока
    Time end;         //Конец урока
};

//Кабинет
class Room
{
public:
    
    Room();
    
    //Инициализация
    //n - номер кабинета
    //t1 - открытие кабинета
    //t2 - закрытие кабинета
    Room(int n, Time t1, Time t2);
    
    Time GetBegin();
    
    Time GetEnd();
    
    bool AddEvent(Subject s);
    
    TimeInterval GetInterval() const;
    
    bool IsAvailable(Subject s) const;
    
    Subject GetBestEvent(Subject min, Subject s);
    
    friend std::ostream& operator << (std::ostream& out, const Room r);
    
    std::vector<Subject> events; //Вектор расписания для комнаты
private:
    int number;     //Номер кабинета
    Time begin;     //Открытие кабинета
    Time end;       //Закрытие кабинета
   
};

#endif /* school_h */
