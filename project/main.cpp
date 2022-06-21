#include <bits/stdc++.h>
#include"project.h"

using namespace std;
int main()
{
    details data;
    pay payment;
    seat sat;
    cost total;

    int time;
    int movie_num;
    string movie[4] = {"Kong", "Island", "Friends", "Lost:The horror"};

    cout << "****Welcome to bookmyticketgujarat.com****" << endl;
jump:
    cout<<"---------------------------------------------------"<<endl;
    cout<< "Choose your movie:" << endl;
    cout<< "1.Kong(14+)                  (350 rupees)" << endl;
    cout<< "2.island(14+)                (300 rupees)" << endl;
    cout<< "3.Friends(10+)               (250 rupees)" << endl;
    cout<< "4.lost:The horror(16+)       (200 rupees)" << endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Enter a number: ";
    cin >> movie_num;
    if (movie_num>0 && movie_num <= 4)
    {

        char a;
        cout << "Are you satisfied or Do you want to continue:(YES-y/NO-n)" << endl;

        cin >> a;
        cout<<"------------------------------------------------"<<endl;
        if (a == 'y')
        {

            data.getdetails();
            int el_age = data.movie_eligible(movie_num);
            if (el_age == 1 || el_age == 2 || el_age == 3 || el_age == 4)
            {
                while (1)
                {
                    cout<<"------------------------------------------------"<<endl;

                    cout << "Choose movie time:" << endl;
                    cout << "1)8:30 to 11:30" << endl;
                    cout << "2)12:00 to 3:00" << endl;
                    cout << "3)6:00 to 9:00" << endl;
                    cout<<"Enter number to your respective time: ";
                    cin >> time;
                    cout<<"------------------------------------------------"<<endl;
                    if (time > 0 && time <= 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Please choose 1 to 3 for time!!" << endl;
                        cout<<"------------------------------------------------"<<endl;
                        continue;
                    }
                }

                total.choose_seat(data.py_eligible());
                total.cost_seat(data.py_eligible());
                total.moive_cost(movie_num);
                cout << "Yore total cost is: " << total.total_cost << endl;
                cout<<"------------------------------------------------"<<endl;
                payment.choose_pay();
                cout<<"-----------------------------------"<<endl;
                cout<<"---------------BILL----------------"<<endl;
                cout<<"-----------------------------------"<<endl;

//------------------------------------------------------------------------
                ofstream outo;
                outo.open("total_bill.txt");
                outo<<"Show: "<<movie[movie_num-1]<<endl;
                outo<<"Name: "<<data.name<<" "<<data.name_last<<endl;
                outo<<"Gender: "<<data.gender[data.gender_num-1]<<endl;
                outo<<"Theater: "<<data.th_arr[data.treater-1]<<endl;
                outo<<"Selected seat: "<<total.a<<endl;
                outo<<"Payment-Method: "<<payment.pay_arr[payment.a-1]<<endl;
                outo<<"Total Amount: "<<total.total_cost<<endl;
                if (data.py_eligible())
                {
                    outo << "Physically Disabled: YES"<< endl;
                }
                else
                {
                    outo << "Physically Disabled: NO" << endl;
                }
                switch (time)
                {
                case 1:
                    outo << "Time: 8:30 to 11:30" << endl;
                    break;
                case 2:
                    outo << "Time: 12:00 to 3:00" << endl;
                    break;
                case 3:
                    outo << "Time: 6:00 to 9:00" << endl;
                    break;
                default:
                    break;
                }
                outo.close();
//-----------------------------------------------------------------------------

                ifstream show;
                string e;
                show.open("total_bill.txt");
                while (show.eof() == 0)
                {
                    getline(show, e);
                    cout << e << endl;
                }
                show.close();
//-------------------------------------------------------------------------------

            }
            else
            {
                cout << "Your age is not eligible for: " << movie[movie_num - 1] << endl;
                cout<<"------------------------------------------------"<<endl;
                goto jump;
            }
        }
        else
            goto jump;
    }
    else
    {
        cout<<"Enter 1 to 4 for different movie!!"<<endl;
        cout<<"------------------------------------------------"<<endl;
        goto jump;
    }

    return 0;
}
