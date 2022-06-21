#include "project.h"

#include  <iostream>
#include  <bits/stdc++.h>

using namespace std;

void details::getdetails()
{

    cout << endl;
    cout<< "Enter details:" << endl;
    while(1)
    {
        cout << "Name(first-name): ";
        cin>>name;
        cout<<"Name(last-name): ";
        cin>>name_last;
        cout<<"------------------------------------------------"<<endl;
        int temp=0;
        for(int i=0; i<name.length(); i++)
        {
            if(name[i]>=48 && name[i]<=57)
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            break;
        }
        else
        {
            cout<<"Invalid name!!"<<endl;
            cout<<"------------------------------------------------"<<endl;
        }
    }
    while (1)
    {
        cout << "Gender-(1)male (2)female (3)other: "<<endl;
        cout<<"Enter number to your respective gender: ";
        cin >> gender_num;
        cout<<"------------------------------------------------"<<endl;
        if (gender_num == 1 || gender_num == 2 || gender_num == 3)
        {
            break;
        }
        else
        {
            cout << "Please enter valid number for gender!" << endl;
            cout<<"------------------------------------------------"<<endl;
        }
    }
    while (1)
    {
        cout << "Mobile: ";
        cin >> mobile;
        cout<<"------------------------------------------------"<<endl;
        int q = 0;
        for (int i = 0; i < mobile.length(); i++)
        {
            if (mobile[i] <= 48 && mobile[i] >= 57)
            {
                q = 1;
                break;
            }
        }
        if (mobile.length() == 10 && q == 0)
        {
            string st[25];
            int run;
            ofstream out;
            out.open("mobile_num.txt", ios::app);
            out << mobile << " ";
            out.close();

            ifstream in;
            in.open("mobile_num.txt");

            for (run = 0; in.eof() == 0; run++)
            {
                in >> st[run];
                //cout << st[run] << " ";
            }
            //cout<<"Run="<<run<<endl;
            in.close();
            int rt = 0;
            for (int i = 0; i < run-2 ; i++)
            {
                if (st[i] == mobile)
                {
                    rt = 1;
                    break;
                }
            }
            if(rt==1)
            {
                cout<<"This mobile number has been occupiedd!!"<<endl;
                cout<<"------------------------------------------------"<<endl;
                continue;
            }
            break;
        }
        else
        {
            cout << "Please enter valid number!!" << endl;
            cout<<"------------------------------------------------"<<endl;
        }
    }
    while (1)
    {

        cout << "City: ";
        cout << "1.Ahmadabad |2.Amreli |3. Anand |4.Banas Kantha |5.Bharuch |6.Bhavnadar |7.Dahod |8.Gandhinagar |9. Jamnagar|" << endl;
        cout << "      |10.Junagadh |11.Kachchh |12.Kheda |13.Mahesana | 14.Narmada |15.Navsari |16.Panch-Mahal |17.PAtan |" << endl;
        cout << "      |18. Porbandar|19.Rajkot |20.Sabar-Kantha |21.Surat |22.Surendranager |23.Tapi |24.Dang |25.Vadodara |26. Valsad|" << endl;
        cout<<"Enter a number: ";
        cin >> city;
        cout<<"------------------------------------------------"<<endl;
        if (city >= 1 && city <= 26)
        {
            break;
        }
        else
        {
            cout << "Please enter valid number for different cities!" << endl;
            cout<<"------------------------------------------------"<<endl;
            continue;
        }
    }

    cout << "PHYSICALLY DISABLED-(YES-y/NO-n): ";
    cin >> disabled;
    cout<<"------------------------------------------------"<<endl;
    while (1)
    {
        cout << "There are 3 theater near you: (1)multiplex (2)sinemax (3)pVr" << endl;
        cout<<"Enter number to your respective theater: ";
        cin >> treater;
        cout<<"------------------------------------------------"<<endl;
        if (treater > 0 && treater <= 3)
        {
            break;
        }
        else
        {
            cout << "Choose 1 to 3 for different theater!!" << endl;
            cout<<"------------------------------------------------"<<endl;
            continue;
        }
    }
    while(1)
    {
        cout << "Age: ";
        cin >> age;
        cout<<"------------------------------------------------"<<endl;
        if (age >= 5 && age < 110)
        {
            break;
        }
        else
        {
            cout << "Enter a valid age!" << endl;
            cout<<"------------------------------------------------"<<endl;
            continue;
        }
    }
}
int details::py_eligible()
{

    if (disabled == 'y')
    {
        return 1;
    }
    return 0;
}
int details::movie_eligible(int num)
{
    if (num == 1 && age >= 14)
    {
        return 1;
    }
    else if (num == 2 && age >= 14)
    {
        return 2;
    }
    else if (num == 3 && age >= 10)
    {
        return 3;
    }
    else if (num == 4 && age >= 16)
    {
        return 4;
    }
    return 0;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------


void pay::choose_pay()
{
    //pay_arr[2]= {"Online","Offline"};
    while (1)
    {
        cout << "Choose payment method-(1)online (2)offline: ";
        cin >> a;
        if (a == 1)
        {
            online_pay();
            break;
        }
        else if (a == 2)
        {
            offline_pay();
            break;
        }
        else
        {
            cout << "Choose 1 or 2 for payment method" << endl;
            cout<<"------------------------------------------------"<<endl;
            continue;
        }
    }
}
void pay::online_pay()
{
jump1:
    int num;
    cout << "Choose one of this online method:" << endl;
    cout << "1.BHIM UPI | 2.Add Debit/ATM/credit card | 3.Net banking" << endl;
    cin >> num;
    if (num == 1)
    {
        int i = 0;
        string s;
        while (1)
        {
            cout << "Enter your existing BHIM UPI ID:(mobile_number@bank_name)" << endl;
            cin >> s;
            for (i; s[i] != '@'; i++);
            if (i == 10)
            {
                cout << "Your UPI ID recognized successfuly!!" << endl;
                cout<<"------------------------------------------------"<<endl;
                break;
            }
            else
            {
                cout << "Dose not recognize ID!!" << endl;
                cout << "please re-enter your ID" << endl;
                cout<<"------------------------------------------------"<<endl;
                continue;
            }
        }
    }
    else if (num == 2)
    {
        string s, number,s_last;
        int mm,yyyy;
        int i;
        cout << "->Name(First_name): ";
        cin>>s;
        cout << "->Name(last_name): ";
        cin>>s_last;
        while (1)
        {
            cout << "->Card number(16 numbers): ";
            cin >> number;
            if (number.length() == 16)
            {
                cout << "Card number recognized!!" << endl;
                cout<<"------------------------------------------------"<<endl;
                break;
            }
            else
            {
                cout << "Card number dose not exist or there are not 16 numbers !!" << endl;
                cout << "please re-enter your card number" << endl;
                cout<<"------------------------------------------------"<<endl;
                continue;
            }
        }
        while(1)
        {
            cout << "->Expiry Mouth(MM): ";
            cin >> mm;
            if(mm>0 && mm<=12)
            {
                break;
            }
            else
                continue;
        }

        while(1)
        {
            cout << "->Expiry year(YYYY): ";
            cin >> yyyy;
            if(yyyy>2021 && yyyy<=2050)
            {
                break;
            }
            else
                continue;
        }

        cout<<"------------------------------------------------"<<endl;
    }
    else if (num == 3)
    {
        string s, username, password;
        cout << "Enter bank name(short): ";
        cin >> s;
        cout << "Welcome to " << s << " internet banking" << endl;
        cout<<"-----------------------------------------------"<<endl;
        while (1)
        {
            int c = 0;
            cout << "->Username(Ex-Ramesh243): ";
            cin >> username;
            cout << "->Password: ";
            cin >> password;
            for (int i = 0; i < username.length(); i++)
            {
                if (username[i]=='0' || username[i] == '1' || username[i] == '2' || username[i] == '3' || username[i] == '4' || username[i] == '5' || username[i] == '6' || username[i] == '7' || username[i] == '8' || username[i] == '9')
                {
                    c = 1;
                    break;
                }
            }
            if (c == 1)
            {
                cout << "Net-banking successful!!" << endl;
                cout<<"------------------------------------------------"<<endl;
                break;
            }
            else
            {
                cout << "Username or Password incorrect!!" << endl;
                cout << "please re-enter your username and password" << endl;
                cout<<"------------------------------------------------"<<endl;
                continue;
            }
        }
    }
    else
    {
        cout << "please choose 1 to 3 for payment!" << endl;
        cout<<"------------------------------------------------"<<endl;
        goto jump1;
    }
    char c;
    cout << "Do you agree for online-payment? (YES-y/NO-n): ";
    cin >> c;
    cout<<"------------------------------------------------"<<endl;
    if (c == 'n')
    {
        choose_pay();
    }
    else
    {
        cout << "Online-payment successful!" << endl;
        cout<<"------------------------------------------------"<<endl;
    }
}
void pay::offline_pay()
{
    char c;
    cout << "You have to pay when you will reach at movie counter" << endl;
    cout << "Do you agree for offline-payment? (YES-y/NO-n)" << endl;
    cin >> c;
    if (c == 'y')
    {
        cout << "Offline-payment successful!" << endl;
        cout<<"------------------------------------------------"<<endl;
    }
    else
    {
        choose_pay();
    }
}
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


void seat::choose_seat(int q)
{

    /*ifstream rundata;
    rundata.open("run_num.txt");
    rundata >> run;
    rundata.close();
    run++;
    ofstream runtime;
    runtime.open("run_num.txt");
    runtime << (run);
    runtime.close();*/

    if (q == 1)
    {
        int run;
        string st[22] = {"0"};
        string seat[4][4] = {{"*", "*", "*", "   (+30 rupees)"}, {"*", "*", "*", "   (+20 rupees)"}, {"*", "*", "*", "   (+10 rupees)"}, {"*", "*", "*", "   (+0 rupees)"}};
jump_py:
        ifstream we;
        string e;
        we.open("seat_py.txt");
        while (we.eof() == 0)
        {
            getline(we, e);
            cout << e << endl;
        }
        we.close();
        cout << "seat num: " << endl;
        cin >> a;

        if ((a[0] == '1' || a[0] == '2' || a[0] == '3' || a[0] == '4') && (a[1] == 'E' || a[1] == 'F' || a[1] == 'G'))
        {
            ofstream out;
            out.open("seat_no_py.txt", ios::app);
            out << a << " ";
            out.close();

            ifstream in;
            in.open("seat_no_py.txt");

            for (run = 0; in.eof() == 0; run++)
            {
                in >> st[run];
                //cout << st[run] << " ";
            }
            //cout<<"Run="<<run<<endl;
            in.close();
            int rt = 0;
            for (int i = 0; i < run-2 ; i++)
            {
                if (st[i] == a)
                {
                    rt = 1;
                    break;
                }
            }
            if (rt == 1)
            {
                cout << "seat have been occupied!!" << endl;
                cout<<"Please choose another seat:"<<endl;
                cout<<"------------------------------------------------"<<endl;
                goto jump_py;
            }
            else
            {
                cout << "successful!!" << endl;
                cout<<"------------------------------------------------"<<endl;
            }
            //cout<<"yryryryryryryryryr"<<endl;
            for (int i = 0; i < run-1; i++)
            {
                string rt = st[i];
                int row1 = (int)(rt[0] - 49);
                char colon1 = (char)rt[1];

                if (colon1 == 'E')
                {
                    seat[row1][0] = "-";
                }
                if (colon1 == 'F')
                {
                    seat[row1][1] = "-";
                }
                if (colon1 == 'G')
                {
                    seat[row1][2] = "-";
                }
            }
            //cout<<"yryryryryryryryryr"<<endl;
            ofstream as;
            as.open("seat_py.txt");
            as<<"***SCREEN***"<<endl;
            as << "   E F G " << endl;
            for (int i = 0; i < 4; i++)
            {
                as << i + 1 << "  ";
                for (int j = 0; j < 4; j++)
                {
                    as << seat[i][j] << " ";
                }
                as << endl;
            }
            as.close();
            //cout<<"ir gvcryfhdsjvkgyihbvkcxntgiusbvkcyrwugsbvkjc"<<endl;
        }
        else
        {
            cout << "Please enter valid row and colon!" << endl;
            goto jump_py;
        }
    }
    else
    {
        int run;
        string st[30] = {"0"};
        string seat[5][5] = {{"*", "*", "*", "*", "   (+50 rupees)"}, {"*", "*", "*", "*", "   (+40 rupees)"}, {"*", "*", "*", "*", "   (+20 rupees)"}, {"*", "*", "*", "*", "   (+10 rupees)"}, {"*", "*", "*", "*", "   (+0 rupees)"}};
jump_el:
        ifstream wee;
        string e;
        wee.open("seat.txt");
        while (wee.eof() == 0)
        {
            getline(wee, e);
            cout << e << endl;
        }
        wee.close();
        cout << "seat num: " << endl;
        cin >> a;
        if ((a[0] == '1' || a[0] == '2' || a[0] == '3' || a[0] == '4' || a[0] == '5') && (a[1] == 'A' || a[1] == 'B' || a[1] == 'C' || a[1] == 'D'))
        {
            ofstream outt;
            outt.open("seat_no.txt", ios::app);
            outt << a << " ";
            outt.close();

            ifstream inn;
            inn.open("seat_no.txt");
            for (run = 0; inn.eof() == 0; run++)
            {
                inn >> st[run];
                //cout << st[run] << " ";
            }
            //cout<<"Run="<<run<<endl;
            inn.close();
            int rt = 0;
            for (int i = 0; i < run-2 ; i++)
            {
                if (st[i] == a)
                {
                    rt = 1;
                    break;
                }
            }
            if (rt == 1)
            {
                cout << "seat have been occupied!!" << endl;
                cout<<"------------------------------------------------"<<endl;
                goto jump_el;
            }
            else
            {
                cout << "successful!!" << endl;
                cout<<"------------------------------------------------"<<endl;
            }
            //cout<<"yryryryryryryryryr"<<endl;
            for (int i = 0; i < run-1; i++)
            {
                string rt = st[i];
                int row1 = (int)(rt[0] - 49);
                char colon1 = (char)rt[1];

                if (colon1 == 'A')
                {
                    seat[row1][0] = "-";
                }
                if (colon1 == 'B')
                {
                    seat[row1][1] = "-";
                }
                if (colon1 == 'C')
                {
                    seat[row1][2] = "-";
                }
                if (colon1 == 'D')
                {
                    seat[row1][3] = "-";
                }
            }
            //cout<<"yryryryryryryryryr"<<endl;
            ofstream asa;
            asa.open("seat.txt");
            asa<<"****SCREEN***"<<endl;
            asa << "   A B C D" << endl;
            for (int i = 0; i < 5; i++)
            {
                asa << i + 1 << "  ";
                for (int j = 0; j < 5; j++)
                {
                    asa << seat[i][j] << " ";
                }
                asa << endl;
            }
            asa.close();
            //cout<<"gyrsbfvxkcgierukfjsdxcyriufhsdkbvcxmuyerdfhvjncx"<<endl;
        }

        else
        {
            cout << "Please enter valid row and colon!" << endl;
            cout<<"------------------------------------------------"<<endl;
            goto jump_el;
        }
    }

}
void seat::cost_seat(int q)
{
    if (q == 0)
    {
        switch (a[0])
        {
        case '1':
            extra_cost = 50;
            break;
        case '2':
            extra_cost = 40;
            break;
        case '3':
            extra_cost = 20;
            break;
        case '4':
            extra_cost = 10;
            break;
        case '5':
            extra_cost = 0;
        default:
            break;
        }
    }
    else
    {
        switch (a[0])
        {
        case '1':
            extra_cost = 30;
            break;
        case '2':
            extra_cost = 20;
            break;
        case '3':
            extra_cost = 10;
            break;
        case '4':
            extra_cost = 0;
            break;
        default:
            break;
        }
    }
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------


void cost::moive_cost(int r)
{
    switch (r)
    {
    case 1:
        total_cost = extra_cost + 350;
        break;
    case 2:
        total_cost = extra_cost + 300;
        break;
    case 3:
        total_cost = extra_cost + 250;
        break;
    case 4:
        total_cost = extra_cost + 200;
        break;
    default:
        break;
    }
}









