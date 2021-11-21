/*
Task: H4 - Flughafen Zeitplan
Family Name: Abdul Moeed
Given Name: Muhammad
*/

#include <iostream>
#include <iomanip>
using namespace std;

enum TimeZone
{
  ACT,
  CET,
  CST,
  EST,
  GMT,
  MSK,
  PST,
  UTC
};

enum flight
{
    arrival,
    departure
};

class LocalTime
{
private:
    int minutes;
    TimeZone time;
public:
    LocalTime() : minutes(-1), time(CET){};
    LocalTime(int h, int m, TimeZone t)
    {
        time = t;
        minutes = (h*60) + m;
    }
    void set_time(int h, int m)
    {
        if ((h>= 0 && h<=24) && (m>=0 && m<=60))
            {
                minutes = (h*60) + m;
            }
        else{minutes = -1;}
    }
    int get_hour()
    {
            return minutes/60;
    }
    int get_minute()
    {
        return minutes % 60;
    }
    bool is_valid()
    {
        if(minutes<0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }


};

ostream& operator<<(ostream& out, LocalTime o1)
{
    if(o1.get_hour() >= 0 && o1.get_hour()<=9)
    {
        out << "0" <<o1.get_hour() << ":" << o1.get_minute();
    }
    else if(o1.get_minute() >= 0 && o1.get_minute() <= 9)
    {
        out <<o1.get_hour() << ":" << "0" << o1.get_minute();
    }
    else
    {
        out << o1.get_hour() << ":" << o1.get_minute();
    }
    return out;
}

class Flight
{
private:
    flight arrivalOrDeparture;
    string code;
    string destination;
    string gate;
    string checkIn;
    string comment;
    LocalTime expected;
public:
    Flight(string, string, string, string, string);
    ~Flight();
    string get_code();
    string get_destination();
    string get_gate();
    string get_checkIn();
    string get_comment();
    LocalTime get_expected();
    void set_comment(string);
    void set_expected(LocalTime);
    bool is_arrival()
    {
        return false;

    }
    bool is_departure()
    {
        return true;
    }
    void print(LocalTime);
};

Flight::Flight(string cod, string dest, string gat, string check_in,string com)
    {
        code = cod;
        destination = dest;
        gate = gat;
        checkIn = check_in;
        comment = com;

    }
Flight::~Flight()
{
    cout<< "flight " << get_code() << " deleted" << endl;
}

string Flight::get_code()
{
    return code;
}
string Flight::get_destination()
{
    return destination;
}
string Flight::get_gate()
{
    return gate;
}
string Flight::get_checkIn()
{
    return checkIn;
}
string Flight::get_comment()
{
    return comment;
}
LocalTime Flight::get_expected()
{
    return expected;
}
void Flight::set_comment(string comm)
{
    comment = comm;
}
void Flight::set_expected(LocalTime obj_t)
{
    expected = obj_t;
}
void Flight::print(LocalTime obj_t)
{
    cout<< setw(20) << get_code() << setw(20) << get_destination() << setw(20) << obj_t << setw(20)<< ""<< setw(20) << get_gate() << setw(20) << get_checkIn() << setw(20) << get_comment() << endl;

}

class Airport
{
private:
    string name;
    Flight *slot[24][60] = {{nullptr}};
public:
    Airport(string n)
    {
        name = n;
    }
    ~Airport()
    {
        cout<<"deleted"<<endl;
    }
    void schedule(LocalTime o4, Flight *r)
    {
        int i = o4.get_hour();
        int j = o4.get_minute();
        slot[i][j]=r;
    }
    void comment(LocalTime o4, string a)
    {
        int i = o4.get_hour();
        int j = o4.get_minute();
        slot[i][j]->set_comment(a);
    }
    void delay(LocalTime o4, LocalTime o5)
    {
        int i = o4.get_hour();
        int j = o4.get_minute();
        if ((slot[i][j]->get_expected().get_hour() != o5.get_hour()) && (slot[i][j]->get_expected().get_minute() != o5.get_minute()))
        {
            slot[i][j]->set_expected(o5);
        }
    }

    void print(flight t)
    {
        if (t==arrival)
        {
            cout << "DUSSELDORF AIRPORT ARRIVALS" << endl;
            cout << "---------------------------" << endl;
            cout << "---------------------------" << endl;
            cout << setw(20) << "Flight" << setw(20) << "From" << setw(20) << "Scheduled" << setw(23) << "Expected" << setw(23) << "Gate" << setw(17)<< "Check-In" << setw(17) << "Comments" << endl;
            for(int l=0; l<24; l++)
            {
                for(int m=0; m<60; m++)
                {
                    if(slot[l][m] != nullptr)
                    {
                        if(slot[l][m]->get_checkIn() == "")
                        {
                            slot[l][m]->print(slot[l][m]->get_expected());

                        }
                    }
                }
            }
        }

        if (t==departure)
        {
            cout << "DUSSELDORF AIRPORT DEPARTURES" << endl;
            cout << "---------------------------" << endl;
            cout << "---------------------------" << endl;
            cout << setw(20) << "Flight" << setw(20) << "To" << setw(20) << "Scheduled" << setw(23) << "Expected" << setw(23) << "Gate" << setw(17)<< "Check-In" << setw(17) << "Comments" << endl;
            for(int n=0; n<24; n++)
            {
                for(int o=0; o<60; o++)
                {
                    if(slot[n][o] != nullptr)
                    {
                         if(slot[n][o]->get_checkIn() != "")
                         {
                            slot[n][o]->print(slot[n][o]->get_expected());

                         }
                    }
                }
            }
        }



    }
};



int main()
{
    Airport obj_a("DUSSELDORF AIRPORT");
    LocalTime obj_t1(12,40,CET);
    //LocalTime obj_t1_1(13,5,CET);
    LocalTime obj_t2(14,50,CET);
    LocalTime obj_t3(9,10,CET);
    LocalTime obj_t4(10,40,CET);
    LocalTime obj_t5(11,15,CET);
    LocalTime obj_t6(13,25,CET);
    LocalTime obj_t7(14,55,CET);
    //LocalTime obj_t7_1(15,20,CET);
    Flight* obj_f1 = new Flight("LH 2010", "Munich", "A04", "", "");
    obj_f1->set_expected(obj_t1);
    obj_a.schedule(obj_t1, obj_f1);
    //obj_a.delay(obj_t1,obj_t1_1);
    Flight* obj_f2 = new Flight("EW 9347", "Manchester", "B04", "","");
    obj_f2->set_expected(obj_t2);
    obj_a.schedule(obj_t2, obj_f2);
    Flight* obj_f3 = new Flight("AF 1307", "Paris", "B51", "192-194","");
    obj_f3->set_expected(obj_t3);
    obj_a.schedule(obj_t3, obj_f3);
    obj_a.comment(obj_t3, "departed");
    Flight* obj_f4 = new Flight("SU 2537 ", "Moscow", "C31", "252-255","");
    obj_f4->set_expected(obj_t4);
    obj_a.schedule(obj_t4, obj_f4);
    obj_a.comment(obj_t4, "boarding");
    Flight* obj_f5 = new Flight("EW 9466", "London-Heathrow", "B35", "151-170","");
    obj_f5->set_expected(obj_t5);
    obj_a.schedule(obj_t5, obj_f5);
    Flight* obj_f6 = new Flight("LH 2011", "Munich", "A40", "115-120","");
    obj_f6->set_expected(obj_t6);
    obj_a.schedule(obj_t6, obj_f6);
    obj_a.comment(obj_t6, "Code Sharing");
    Flight* obj_f7 = new Flight("XQ 959", "Izmir", "C45", "240-242","");
    obj_f7->set_expected(obj_t7);
    obj_a.schedule(obj_t7, obj_f7);
    //obj_a.delay(obj_t7, obj_t7_1);
    obj_a.print(arrival);
    obj_a.print(departure);
    delete obj_f1;
    delete obj_f2;
    delete obj_f3;
    delete obj_f4;
    delete obj_f5;
    delete obj_f6;
    delete obj_f7;
    return 0;

}
