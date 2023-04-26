#include <chrono>
#include <ctime>
#include "TReceipt.h"

using namespace std::chrono;



TReceipt::TReceipt(TDate* date, TTime* time, TContainer<TRecipline>* products) {
    //#INITIALISING
    date = new TDate;
    time = new TTime;
    TContainer<TRecipline>* products = new TContainer<TRecipline>;

    //#creating a structure of type std::tm
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_tm = *std::localtime(&now_time_t);

    //#SET TIME
    time->hour = now_tm.tm_hour;
    time->minute = now_tm.tm_min;
    time->second = now_tm.tm_sec;

    //#SET DATE
   date->year = now_tm.tm_year + 1900;
   date->month = now_tm.tm_mon + 1;
   date->day = now_tm.tm_mday;
}
