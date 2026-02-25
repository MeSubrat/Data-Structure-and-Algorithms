#include <bits/stdc++.h>
using namespace std;

int getWeekRank(string day){
    if(day == "mon") return 1;
    else if(day == "tue") return 2;
    else if(day == "wed") return 3;
    else if(day == "thur") return 4;
    else if(day == "fri") return 5;
    else if(day == "sat") return 6;
    else if(day == "sun") return 7;
    return 0;
}


int main()
{
    string day;
    getline(cin, day);
    int daysPassed;
    cin>>daysPassed;

    int currentDate = getWeekRank(day);
    int remainingDays = 30 - daysPassed;
    if()



}