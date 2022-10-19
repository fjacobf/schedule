#ifndef SCHEDULE_TIME_SLOT_H
#define SCHEDULE_TIME_SLOT_H
#include <string>
using namespace std;
//Conceptualmente, uma aula é identificada por um código da UC, dia da semana, hora de início, duração e
//tipo (T/TP/PL).

class Time_slot {
private:
    string weekday;
    float startHour;
    float duration;
    string type;

public:

};


#endif //SCHEDULE_TIME_SLOT_H
