#include <iostream> 
#include <string> 
#include<iomanip>

using namespace std;

enum format{
    USA, EUROPEAN
};

struct Time{
    int seconds;
    int minutes;
    int hours;
};

Time operator+(const Time& givenTime1, const Time& givenTime2 ){
    Time newTime;
    int rest;
    newTime.seconds = (givenTime1.seconds+givenTime2.seconds)%60;
    rest = (givenTime1.seconds+givenTime2.seconds)/60;
    newTime.minutes = (givenTime1.minutes+givenTime2.minutes+rest)%60;
    rest = (givenTime1.minutes+givenTime2.minutes)/60;
    newTime.hours = (givenTime1.hours+givenTime2.hours+rest)%24;
    return newTime;
}

Time& operator++(Time& givenTime){
    Time unit{1,0,0};
    givenTime = operator+(givenTime, unit);
    return givenTime;
}

Time operator++(Time& givenTime, int){
    Time tmp{givenTime};
    givenTime++;
    return tmp;
}



bool operator==(const Time& givenTime1, const Time& givenTime2){
    if ((givenTime1.hours == givenTime2.hours) and (givenTime1.minutes == givenTime2.minutes) and (givenTime1.seconds == givenTime2.seconds)){
        return true;
    }
    else {
        return false;
    }   
}

bool operator<(const Time& givenTime1, const Time& givenTime2){
    if (givenTime1.hours < givenTime2.hours)
    {
        return true;
    }
    else if (givenTime1.hours == givenTime2.hours)
    {
        if (givenTime1.minutes < givenTime2.minutes)
        {
            return true;
        }
        else if (givenTime1.minutes == givenTime2.minutes)
        {
            return givenTime1.seconds < givenTime2.seconds;
        }
    }

    return false;
}

bool operator<=(const Time& givenTime1, const Time& givenTime2){
    if((givenTime1 < givenTime2) or (givenTime1 == givenTime2) ){
        return true;
    }
    else {
        return false;
    }
}

bool is_valid(Time& givenTime){
    bool timeValidity = true;
    if(givenTime.seconds<0 or givenTime.seconds >=60){
        cout << "Unvalid seconds" << endl;
        timeValidity = false;
    }
    if(givenTime.minutes<0 or givenTime.minutes >=60){
        cout << "Unvalid minutes" << endl;
        timeValidity = false;
    }
    if(givenTime.hours<0 or givenTime.hours >=24){
        cout << "Unvalid hours" << endl;
        timeValidity = false;
    }
    return timeValidity;
}

bool is_am(Time& givenTime){
    if(givenTime.hours >= 12){
        cout << "PM hour" << endl;
        return false;
    }
    cout << "AM hour" << endl;
    return true;
}



string to_string(Time const&  givenTime, format timeFormat){
    string timeString;
    if(timeFormat == USA){

    }else{
        //timeString = (string) givenTime.hours+ ":" + (string) givenTime.minutes+ ":" + (string) givenTime.seconds ;
    }
    
    return timeString;
}

ostream& operator<<(ostream& os, Time const&  givenTime){
    os << to_string(givenTime, EUROPEAN) << endl;
    return os;
}

int main() { 
    Time newTime1{};
    Time newTime2{};
    Time newTime3{};
    newTime1.seconds=50;
    newTime2.seconds=39;
    newTime1.minutes=13;
    newTime2.minutes=39;
    newTime1.hours=13;
    newTime2.hours=9;
    newTime3=newTime1+newTime2;
    ++newTime3;
    cout << newTime3.seconds << " " << is_valid(newTime3) << endl;

    return 0;
}