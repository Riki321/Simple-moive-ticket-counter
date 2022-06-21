#ifndef PROJECT_H
#define PROJECT_H


#include <bits/stdc++.h>
using namespace std;

class details
{
    int age;
    int city;
    string mobile;
    char disabled;

public:
    int treater;
    string th_arr[3]= {"multiplex", "sinemax", "pVr"};
    string name;
    string name_last;
    string gender[3]= {"Male", "Female","Others"};
    int gender_num;
    int movie_eligible(int);
    int py_eligible();
    void getdetails();
};
class pay
{
public:
    int a;
    string pay_arr[2]= {"Online","Offline"};
    void online_pay();
    void offline_pay();
    void choose_pay();
};
class seat
{
public:
    string a;
    int extra_cost;
    void choose_seat(int);
    void cost_seat(int);
};
class cost : public seat
{
public:
    int total_cost;
    void moive_cost(int);
};

#endif // PROJECT_H
