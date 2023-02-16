#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

enum Ttype
{
    TT_Movie,TT_Travel
};

class Tickets
{
    public:
            string type;
            string date;

            Tickets(string t="NULL", string d="NULL")
            {
                type = t;
                date = d;
            }

            virtual void display() = 0;
            virtual void addTT() = 0;
            virtual int deleteticket(string p) = 0;
};

enum TTtype
{
    Bus,Train,Flight
};

class TravelTickets: public Tickets
{
    public: string pnr;
            string mode;

            TravelTickets(string pnr, string mode, string type, string d):Tickets(type,d)
            {
                this->pnr = pnr;
                this->mode = mode;
            }

            virtual void display() = 0;
            virtual void addTT() = 0;
            virtual int deleteticket(string p) = 0;


};

class FlightTickets: public TravelTickets
{
    public: int gateno;
            string seatno;
            string departure;
            string arrival;
            string deptime;
            string arrtime;

            FlightTickets(string pnr="NULL", string mode="NULL", string type="NULL", int g=0, string s="NULL", string dep="NULL", string arr="NULL", string dt="NULL", string arrt="NULL",string d="NULL"):
            TravelTickets(pnr,mode,type,d)
            {
                gateno = g;
                seatno = s;
                departure = dep;
                arrival = arr;
                deptime = dt;
                arrtime = arrt;
            }

            void addTT()
            {
                type="Travel";
                mode="Flight";
                cout<<"Enter PNR: ";
                cin>>pnr;
                cout<<"Enter Gate Number: ";
                cin>>gateno;
                cout<<"Enter seat number: ";
                cin>>seatno;
                cout<<"Enter Departure City: ";
                cin>>departure;
                cout<<"Enter Destination: ";
                cin>>arrival;
                cout<<"Enter Departure Time: ";
                cin>>deptime;
                cout<<"Enter Arrival Time: ";
                cin>>arrtime;
                cout<<"Enter Date: ";
                cin>>date;
                cout<<endl<<"Flight ticket added successfully."<<endl;
            }

            void display()
            {
                cout<<endl;
                cout<<"PNR: "<<pnr<<endl;
                cout<<"Gate No: "<<gateno<<endl;
                cout<<"Seat No: "<<seatno<<endl;
                cout<<"Departure: "<<departure<<endl;
                cout<<"Destination: "<<arrival<<endl;
                cout<<"Departure Time: "<<deptime<<endl;
                cout<<"Arrival Time: "<<arrtime<<endl;
                cout<<"Date: "<<date<<endl;
                cout<<endl;
            }

            int deleteticket(string p)
            {
                if(this->pnr == p)
                    return 1;
                else
                    return 0;
            }
};

class TrainTickets: public TravelTickets
{
    public: int platformno;
            string seatno;
            string departure;
            string arrival;
            string deptime;
            string arrtime;

            TrainTickets(string pnr="NULL", string mode="NULL", string type="NULL", int p=0, string s="NULL", string dep="NULL", string arr="NULL", string dt="NULL", string arrt="NULL", string d="NULL"):
            TravelTickets(pnr,mode,type,d)
            {
                platformno = p;
                seatno = s;
                departure = dep;
                arrival = arr;
                deptime = dt;
                arrtime = arrt;
            }

            void addTT()
            {
                type="Travel";
                mode="Train";
                cout<<"Enter PNR: ";
                cin>>pnr;
                cout<<"Enter Platform Number: ";
                cin>>platformno;
                cout<<"Enter seat number: ";
                cin>>seatno;
                cout<<"Enter Departure City: ";
                cin>>departure;
                cout<<"Enter Destination: ";
                cin>>arrival;
                cout<<"Enter Departure Time: ";
                cin>>deptime;
                cout<<"Enter Arrival Time: ";
                cin>>arrtime;
                cout<<"Enter Date: ";
                cin>>date;
                cout<<endl<<"Train ticket added successfully."<<endl;

            }

            void display()
            {
                cout<<endl;
                cout<<"PNR: "<<pnr<<endl;
                cout<<"Platform No: "<<platformno<<endl;
                cout<<"Seat No: "<<seatno<<endl;
                cout<<"Departure: "<<departure<<endl;
                cout<<"Destination: "<<arrival<<endl;
                cout<<"Departure Time: "<<deptime<<endl;
                cout<<"Arrival Time: "<<arrtime<<endl;
                cout<<"Date: "<<date<<endl;
                cout<<endl;
            }

            int deleteticket(string p)
            {
                if(this->pnr == p)
                    return 1;
                else
                    return 0;
            }
};

class BusTickets: public TravelTickets
{
    public: string boarding;
            string seatno;
            string departure;
            string arrival;
            string deptime;

            BusTickets(string pnr="NULL", string mode="NULL", string type="NULL", string board="NULL", string s="NULL", string dep="NULL", string arr="NULL", string dt="NULL", string d="NULL"):
            TravelTickets(pnr,mode,type,d)
            {
                boarding = board;
                seatno = s;
                departure = dep;
                arrival = arr;
                deptime = dt;
            }

            void addTT()
            {
                type="Travel";
                mode="Bus";
                cout<<"Enter PNR: ";
                cin>>pnr;
                cout<<"Enter Boarding Point: ";
                cin>>boarding;
                cout<<"Enter seat number: ";
                cin>>seatno;
                cout<<"Enter Departure City: ";
                cin>>departure;
                cout<<"Enter Destination: ";
                cin>>arrival;
                cout<<"Enter Departure Time: ";
                cin>>deptime;
                cout<<"Enter Date: ";
                cin>>date;
                cout<<endl<<"Bus ticket added successfully!"<<endl;
            }

            void display()
            {
                cout<<endl;
                cout<<"PNR: "<<pnr<<endl;
                cout<<"Boarding point: "<<boarding<<endl;
                cout<<"Seat No: "<<seatno<<endl;
                cout<<"Departure: "<<departure<<endl;
                cout<<"Destination: "<<arrival<<endl;
                cout<<"Departure Time: "<<deptime<<endl;
                cout<<"Date: "<<date<<endl;
                cout<<endl;
            }

            int deleteticket(string p)
            {
                if(this->pnr == p)
                    return 1;
                else
                    return 0;
            }
};

class Factory1
{
    public:
            static TravelTickets* create(TTtype t)
            {
                if(t==Bus)
                    return new BusTickets();
                else if(t==Train)
                    return new TrainTickets();
                else if(t==Flight)
                    return new FlightTickets();
                else
                    return NULL;
            }

};

class MovieTickets: public Tickets
{
    public: string moviename;
            string theatre;
            int price;
            string seatno;
            string showtiming;
            float duration;

            MovieTickets(string mn="NULL", string t="NULL", int cost=0, string s="NULL", string st="NULL", float d=0.0, string type="NULL", string dt="NULL"):Tickets(type,dt)
            {
                moviename = mn;
                theatre = t;
                price = cost;
                seatno = s;
                showtiming = st;
                duration = d;
            }

            void addTT()
            {
                type="Movie";
                cout<<"Enter the name of the movie: ";
                cin>>moviename;
                cout<<"Enter the name of the theatre:";
                cin>>theatre;
                cout<<"Enter cost: ";
                cin>>price;
                cout<<"Enter seat number: ";
                cin>>seatno;
                cout<<"Enter show timing: ";
                cin>>showtiming;
                cout<<"Enter duration: ";
                cin>>duration;
                cout<<"Enter date: ";
                cin>>date;
                cout<<endl<<"Movie ticket added successfully"<<endl;
            }

            void display()
            {
                cout<<endl;
                cout<<"Movie Name: "<<moviename<<endl;
                cout<<"Theatre: "<<theatre<<endl;
                cout<<"Seat No: "<<seatno<<endl;
                cout<<"Show timing's: "<<showtiming<<endl;
                cout<<"Duration: "<<duration<<endl;
                cout<<"Price: "<<price<<endl;
                cout<<"Date: "<<date<<endl;
                cout<<endl;
            }


            int deleteticket(string p)
            {
                if(this->moviename == p)
                    return 1;
                else
                    return 0;
            }
};

class Factory3
{
    public:
            static Tickets* create(Ttype t)
            {
                if(t==TT_Movie)
                    return new MovieTickets();
                else if(t==TT_Travel)
                    return NULL;
                else
                    return NULL;
            }

};

class Reservations
{
    public: string type;
            string timing;
            string hotel;
            long hotelphone;
            string date;

            Reservations(string t="NULL", string time="Null", string h="NULL", long phone=0, string d="NULL")
            {
                type = t;
                timing = time;
                hotel = h;
                hotelphone = phone;
                date = d;
            }

            void addreservation()
            {

                cout<<"Enter the type of Reservation:";
                cin>>type;
                cout<<"Enter time: ";
                cin>>timing;
                cout<<"Enter the name of the hotel: ";
                cin>>hotel;
                cout<<"Enter contact number: ";
                cin>>hotelphone;
                cout<<"Enter date: ";
                cin>>date;
                cout<<endl<<"Reservation added successfully."<<endl;

            }


            void displayreservations()
            {
                cout<<endl;
                cout<<"Type: "<<type<<endl;
                cout<<"Location: "<<hotel<<endl;
                cout<<"Timing: "<<timing<<endl;
                cout<<"Phone No: "<<hotelphone<<endl;
                cout<<"Date: "<<date<<endl;
                cout<<endl;
            }
};

class Cards
{
    public: string type;
            long cardno;
            int cvv;
            string validfrom;
            string validthru;
            string bankname;
            string network;

            Cards(string t="Null", long cn=0, int cv=0, string vf="NULL", string vt="NULL", string bn="NULL", string net="NULL")
            {
                type = t;
                cardno = cn;
                cvv = cv;
                validfrom = vf;
                validthru = vt;
                bankname = bn;
                network = net;
            }

            void addcard()
            {
                cout<<"Enter the type of card to be added:";
                cin>>type;
                cout<<"Enter card number:";
                cin>>cardno;
                cout<<"Enter cvv:";
                cin>>cvv;
                cout<<"Enter validfrom:";
                cin>>validfrom;
                cout<<"Enter validthru:";
                cin>>validthru;
                cout<<"Enter bank name:";
                cin>>bankname;
                cout<<"Enter network:";
                cin>>network;
                cout<<"Card added successfully!"<<endl;

            }

            void displaycards()
            {
                cout<<endl;
                cout<<"Bank: "<<bankname<<endl;
                cout<<"Type: "<<type<<endl;
                cout<<"Card No: "<<cardno<<endl;
                cout<<"CVV: "<<cvv<<endl;
                cout<<"Valid From: "<<validfrom<<endl;
                cout<<"Valid Thru: "<<validthru<<endl;
                cout<<"Network: "<<network<<endl;
                cout<<endl;

            }
};

enum Doctype
{
    DT_License,DT_Passport,DT_PAN
};

class Documents
{
    public: string type;

            Documents(string t)
            {
                type = t;
            }

            virtual void display() = 0;
            virtual void add() = 0;
            virtual int deletedoc(string p) = 0;
};


class License: public Documents
{
    public: string licenseno;
            string validtill;
            string doi;
            string cov;

            License(string t="NULL", string ln="NULL", string vt="NULL", string d="NULL", string c="NULL"):Documents(t)
            {
                licenseno = ln;
                validtill = vt;
                doi = d;
                cov = c;
            }

            void add()
            {
                type="License";
                cout<<"Enter license number: ";
                cin>>licenseno;
                cout<<"Enter valid till: ";
                cin>>validtill;
                cout<<"Enter Date of Issue: ";
                cin>>doi;
                cout<<"Enter COV: ";
                cin>>cov;
                cout<<endl<<"License successfully added."<<endl;
            }

            void display()
            {
                cout<<endl;
                cout<<"License No: "<<licenseno<<endl;
                cout<<"Valid Till: "<<validtill<<endl;
                cout<<"Date of Issue: "<<doi<<endl;
                cout<<"Class of Vehicle: "<<cov<<endl;
                cout<<endl;
            }

            int deletedoc(string p)
            {
                if(this->licenseno == p)
                    return 1;
                else
                    return 0;
            }
};

class Pan: public Documents
{
    public: string panno;
            string father;

            Pan(string t="NULL", string p="NULL", string f="NULL"):Documents(t)
            {
                panno = p;
                father = f;
            }

            void add()
            {
                type="PAN";
                cout<<"Enter PAN number: ";
                cin>>panno;
                cout<<"Enter Father's name: ";
                cin>>father;
                cout<<endl<<"PAN Card successfully added."<<endl;
            }

            void display()
            {
                cout<<endl;
                cout<<"PAN No: "<<panno<<endl;
                cout<<"Father's Name: "<<father<<endl;
                cout<<endl;
            }

            int deletedoc(string p)
            {
                if(this->panno == p)
                    return 1;
                else
                    return 0;
            }
};

class Passport: public Documents
{
    public: string passportno;
            string doi;
            string validtill;
            string guardian;

            Passport(string t="NULL", string pn="NULL", string d="NULL", string vt="NULL", string g="NULL"):Documents(t)
            {
                passportno = pn;
                doi = d;
                validtill = vt;
                guardian = g;
            }

            void add()
            {
                type="Passport";
                cout<<"Enter Passport number: ";
                cin>>passportno;
                cout<<"Enter Date of Issue: ";
                cin>>doi;
                cout<<"Enter Valid Till: ";
                cin>>validtill;
                cout<<"Enter Guardian's Name: ";
                cin>>guardian;
                cout<<endl<<"Passport successfully added."<<endl;
            }

            void display()
            {
                cout<<endl;
                cout<<"Passport No: "<<passportno<<endl;
                cout<<"Date of issue: "<<doi<<endl;
                cout<<"Valid till: "<<validtill<<endl;
                cout<<"Guardian: "<<guardian<<endl;
                cout<<endl;
            }

            int deletedoc(string p)
            {
                if(this->passportno == p)
                    return 1;
                else
                    return 0;
            }
};

class Factory2
{
    public:
            static Documents* create(Doctype t)
            {
                if(t==DT_License)
                    return new License();
                else if(t==DT_Passport)
                    return new Passport();
                else if(t==DT_PAN)
                    return new Pan();
                else
                    return NULL;
            }

};



class Wallet
{
    public: string name;
            string dob;
            string gender;
            string username;
            string password;

            Wallet(string n, string birth, string g, string un, string pswd, int nt, int nod, int nor, int noc)
            {
                name = n;
                dob = birth;
                gender = g;
                username = un;
                password = pswd;
                no_tickets = nt;
                no_docs = nod;
                no_reserve = nor;
                no_cards = noc;
            }

            Tickets *T[10];
            Reservations *R[10];
            Cards *C[10];
            Documents *D[10];

            int no_tickets;
            int no_docs;
            int no_reserve;
            int no_cards;
};

int main()
{
    START:
    int key, i, n, inner_flag, flag = 0;
    int choice, choice2, choice3, choice4, choice5;
    Doctype type1;
    TTtype type2;
    Ttype type3;
    Documents *Doc=NULL;

    Wallet W1("Stephen Curry","10-11-1996","Male","steph30","curry30",2,1,1,1);
    Wallet W2("Bill Russell","05-06-1982","Male","billrussel","bill1982",1,1,2,2);
    Wallet W3("Julie Ann","29-03-1994","Female","julieann","julie@29",2,1,1,2);
    Wallet W4("Kevin Durant","27-02-1990","Male","kevindurant","durant",0,1,1,1);
    Wallet W5("James Harden","10-11-1996","Male","jamesharden","cooljames",1,1,0,2);

    Reservations R1("Dinner","20:00","Fortune",928292922,"21/04/2022");
    Reservations R2("Brunch","12:00","Denissons",2732374,"01/01/2021");
    Reservations R3("Lunch","14:00","Travel Inn",94234624,"05/06/2022");
    Reservations R4("Dinner","21:30","Hells Kitchen",43943928,"08/08/2021");
    Reservations R5("Brunch","12:30","Sheraton Grand",239462394,"18/03/2022");

    Cards C1("Debit",423846233,904,"05-20","05-23","Axis Bank","Visa");
    Cards C2("Credit",328746283,754,"07-20","07-25","SBI","Mastercard");
    Cards C3("Credit",39284749,263,"12-19","12-24","Canara Bank","Rupay");
    Cards C4("Debit",1836342913,231,"11-18","11-23","BOI","Visa");
    Cards C5("Credit",32936213,590,"10-21","10-26","PNB","Mastercard");
    Cards C6("Debit",32784232,990,"10-21","10-26","BOI","Mastercard");
    Cards C7("Debit",96570321,810,"10-21","10-26","SBI","Visa");
    Cards C8("Credit",28744324,777,"10-21","10-26","Axis Bank","Mastercard");

    FlightTickets F1("016EE","Flight","Travel",3,"22F","Hubli","Bangalore","16:00","17:00","05/05/2022");
    TrainTickets T1("FSDIUF222","Train","Travel",3,"05L","Mumbai","Delhi","02:00","23:00","17/09/2022");
    BusTickets B1("01FSIU2","Bus","Travel","Srinagar Park","18W","Belgaum","Goa","18:15","15/12/2021");
    FlightTickets F2("192G","Flight","Travel",4,"22A","Delhi","Kolkata","17:30","21:30","27/02/2022");
    MovieTickets M1("Guilty","PVR",290,"18H","14:00",2.5,"Movie","18/08/2022");
    MovieTickets M2("The Revenant","INOX",350,"21F","21:00",3,"Movie","11/06/2022");

    License D1("License","KA250000111","11/2040","11/2020","LMV & MCWG");
    Passport D2("Passport","KJF293234","04/2022","04/2032","Will Russel");
    Pan D3("PAN","FJSOQ6739D","Jack Sparrow");
    License D4("License","KA251123191","07/2025","07/2005","MCWG");
    Passport D5("Passport","ACF193234","10/2018","10/2028","John Harden");

    W1.R[0] = &R1;
    W2.R[0] = &R2;
    W2.R[1] = &R3;
    W3.R[0] = &R4;
    W4.R[0] = &R5;

    W1.C[0] = &C1;
    W2.C[0] = &C2;
    W2.C[1] = &C3;
    W3.C[0] = &C4;
    W3.C[1] = &C5;
    W4.C[0] = &C6;
    W5.C[0] = &C7;
    W5.C[1] = &C8;

    W1.T[0] = &F1;
    W1.T[1] = &T1;
    W2.T[0] = &B1;
    W3.T[0] = &F2;
    W3.T[1] = &M1;
    W5.T[0] = &M2;

    W1.D[0] = &D1;
    W2.D[0] = &D2;
    W3.D[0] = &D3;
    W4.D[0] = &D4;
    W5.D[0] = &D5;

    Wallet Warr[5] = {W1, W2, W3, W4, W5};

    string uname, pswd;

    try{
    cout<<"Enter your username: ";
    cin>>uname;
    cout<<"Enter your password: ";
    cin>>pswd;

    for(i=0; i<5; i++)
    {
        if(Warr[i].username == uname && Warr[i].password == pswd)
        {
            key = i;
            flag = 1;

            cout<<endl;
            cout<<"You have been successfully logged in."<<endl;

        while(1)
        {
            cout<<endl;
            cout<<"Enter 1 to check your account details."<<endl;
            cout<<"Enter 2 to check your tickets."<<endl;
            cout<<"Enter 3 to check your reservations."<<endl;
            cout<<"Enter 4 to check your cards."<<endl;
            cout<<"Enter 5 to check your personal documents."<<endl;
            cout<<"Enter 6 to logout."<<endl;
            cout<<"Enter 7 to exit."<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<endl;
                        cout<<"Name: "<<Warr[key].name<<endl;
                        cout<<"DOB: "<<Warr[key].dob<<endl;
                        cout<<"Gender: "<<Warr[key].gender<<endl;
                        break;

                case 2: cout<<endl;
                        cout<<"Enter 1 to check movie tickets."<<endl;
                        cout<<"Enter 2 to check travel tickets."<<endl;
                        cout<<"Enter 3 to add movie tickets."<<endl;
                        cout<<"Enter 4 to add travel tickets."<<endl;
                        cout<<"Enter 5 to delete movie tickets."<<endl;
                        cout<<"Enter 6 to delete travel tickets."<<endl;
                        cout<<"Enter your choice: ";
                        cin>>choice2;

                        switch(choice2)
                        {
                            case 1: {
                                    inner_flag = 0;
                                    for(int j=0; j<Warr[key].no_tickets; j++)
                                    {
                                        if(Warr[key].T[j]->type == "Movie")
                                        {
                                            Warr[key].T[j]->display();
                                            inner_flag = 1;
                                        }
                                    }
                                    if(inner_flag == 0)
                                        cout<<endl<<"No movie tickets"<<endl;
                                    break;
                                    }

                            case 2: {
                                    inner_flag = 0;
                                    for(int j=0; j<Warr[key].no_tickets; j++)
                                    {
                                        if(Warr[key].T[j]->type == "Travel")
                                        {
                                            Warr[key].T[j]->display();
                                            inner_flag = 1;
                                        }

                                    }
                                    if(inner_flag == 0)
                                        cout<<"No travel tickets"<<endl;
                                    break;
                                    }

                            case 3: {
                                    Warr[key].no_tickets++;
                                    type3=TT_Movie;
                                    Warr[key].T[Warr[key].no_tickets-1]=Factory3::create(type3);
                                    Warr[key].T[Warr[key].no_tickets-1]->addTT();
                                    break;
                                    }

                            case 4: {
                                    cout<<endl;
                                    cout<<"Enter 1 to add Bus Ticket."<<endl;
                                    cout<<"Enter 2 to add Train Ticket."<<endl;
                                    cout<<"Enter 3 to add Flight Ticket."<<endl;
                                    cout<<"Enter your choice: ";
                                    cin>>choice4;
                                    switch(choice4)
                                    {
                                    case 1: Warr[key].no_tickets++;
                                            type2=Bus;
                                            Warr[key].T[Warr[key].no_tickets-1]=Factory1::create(type2);
                                            Warr[key].T[Warr[key].no_tickets-1]->addTT();
                                            break;

                                    case 2: Warr[key].no_tickets++;
                                            type2=Train;
                                            Warr[key].T[Warr[key].no_tickets-1]=Factory1::create(type2);
                                            Warr[key].T[Warr[key].no_tickets-1]->addTT();
                                            break;

                                    case 3: Warr[key].no_tickets++;
                                            type2=Flight;
                                            Warr[key].T[Warr[key].no_tickets-1]=Factory1::create(type2);
                                            Warr[key].T[Warr[key].no_tickets-1]->addTT();
                                            break;

                                    default:cout<<endl;
                                            cout<<"Invalid choice."<<endl;
                                            break;

                                    }

                                    break;
                                    }

                            case 5: {
                                        inner_flag = 0;
                                        int tempflag;
                                        string todel;
                                        cout<<"Enter movie to be deleted: ";
                                        cin>>todel;

                                        for(int j=0; j<Warr[key].no_tickets; j++)
                                        {
                                            if(Warr[key].T[j]->type == "Movie")
                                            {
                                                tempflag = Warr[key].T[j]->deleteticket(todel);
                                                if(tempflag == 1)
                                                {
                                                    swap(Warr[key].T[j],Warr[key].T[Warr[key].no_tickets-1]);
                                                    cout<<endl<<"Movie ticket deleted successfully"<<endl;
                                                    Warr[key].no_tickets--;
                                                    inner_flag = 1;
                                                }
                                            }
                                        }

                                        if(inner_flag == 0)
                                            cout<<"No such movie ticket found."<<endl;
                                        break;
                                        }

                            case 6: {
                                    cout<<endl;
                                    cout<<"Enter 1 to delete Bus Ticket."<<endl;
                                    cout<<"Enter 2 to delete Train Ticket."<<endl;
                                    cout<<"Enter 3 to delete Flight Ticket."<<endl;
                                    cout<<"Enter your choice: ";
                                    cin>>choice5;
                                    switch(choice5)
                                    {
                                        case 1: {
                                                    inner_flag = 0;
                                                    int tempflag;
                                                    string todel;
                                                    cout<<endl<<"Enter PNR to be deleted: ";
                                                    cin>>todel;

                                                    for(int j=0; j<Warr[key].no_tickets; j++)
                                                    {
                                                        if(Warr[key].T[j]->type == "Travel")
                                                        {
                                                            tempflag = Warr[key].T[j]->deleteticket(todel);
                                                            if(tempflag == 1)
                                                            {
                                                                swap(Warr[key].T[j],Warr[key].T[Warr[key].no_tickets-1]);
                                                                cout<<endl<<"Bus ticket deleted successfully."<<endl;
                                                                Warr[key].no_tickets--;
                                                                inner_flag = 1;
                                                            }
                                                        }
                                                    }

                                                    if(inner_flag == 0)
                                                        cout<<endl<<"No such bus ticket found."<<endl;
                                                break;
                                                }


                                        case 2: {
                                                    inner_flag = 0;
                                                    int tempflag;
                                                    string todel;
                                                    cout<<"Enter PNR to be deleted: ";
                                                    cin>>todel;

                                                    for(int j=0; j<Warr[key].no_tickets; j++)
                                                    {
                                                        if(Warr[key].T[j]->type == "Travel")
                                                        {
                                                            tempflag = Warr[key].T[j]->deleteticket(todel);
                                                            if(tempflag == 1)
                                                            {
                                                                swap(Warr[key].T[j],Warr[key].T[Warr[key].no_tickets-1]);
                                                                cout<<endl<<"Train ticket deleted successfully"<<endl;
                                                                Warr[key].no_tickets--;
                                                                inner_flag = 1;
                                                            }
                                                        }
                                                    }

                                                    if(inner_flag == 0)
                                                        cout<<endl<<"No such train ticket found."<<endl;
                                                break;}

                                        case 3: {
                                                    inner_flag = 0;
                                                    int tempflag;
                                                    string todel;
                                                    cout<<"Enter PNR to be deleted: ";
                                                    cin>>todel;

                                                    for(int j=0; j<Warr[key].no_tickets; j++)
                                                    {
                                                        if(Warr[key].T[j]->type == "Travel")
                                                        {
                                                            tempflag = Warr[key].T[j]->deleteticket(todel);
                                                            if(tempflag == 1)
                                                            {
                                                                swap(Warr[key].T[j],Warr[key].T[Warr[key].no_tickets-1]);
                                                                cout<<endl<<"Flight ticket deleted successfully"<<endl;
                                                                Warr[key].no_tickets--;
                                                                inner_flag = 1;
                                                            }
                                                        }
                                                    }

                                                    if(inner_flag == 0)
                                                        cout<<endl<<"No such flight ticket found."<<endl;
                                                break;}

                                        default: cout<<endl;
                                                 cout<<"Invalid choice."<<endl;
                                                 break;

                                    }
                                    break;
                                    }

                            default: cout<<endl;
                                     cout<<"Invalid choice."<<endl;
                                     break;
                        }

                        break;

                case 3: cout<<endl;
                        cout<<"Enter 1 to check your reservations."<<endl;
                        cout<<"Enter 2 to add reservation."<<endl;
                        cout<<"Enter 3 to delete reservation."<<endl;
                        cout<<"Enter your choice: ";
                        cin>>choice4;
                        switch(choice4)
                        {
                            case 1: inner_flag = 0;
                                    for(int j=0; j<Warr[key].no_reserve; j++)
                                    {
                                        Warr[key].R[j]->displayreservations();
                                        inner_flag = 1;
                                    }
                                    if(inner_flag == 0)
                                        cout<<endl<<"No Reservations"<<endl;
                                    break;

                            case 2: Warr[key].no_reserve++;
                                    //Warr[key].R[Warr[key].no_reserve-1]= &R[Warr[key].no_reserve-1];
                                    Warr[key].R[Warr[key].no_reserve-1]= new Reservations;
                                    Warr[key].R[Warr[key].no_reserve-1]->addreservation();
                                    break;

                            case 3: string delres, delhotel;
                                    int tempflag = 0;

                                    cout<<"Enter reservation type and hotel name to be deleted: ";
                                    cin>>delres>>delhotel;

                                    for(int j=0; j<Warr[key].no_reserve; j++)
                                    {
                                        if(Warr[key].R[j]->hotel == delhotel && Warr[key].R[j]->type == delres)
                                        {
                                            //delete Warr[key].C[j];
                                            swap(Warr[key].R[j],Warr[key].R[Warr[key].no_reserve -1]);
                                            Warr[key].no_reserve--;
                                            cout<<endl<<"Reservation deleted successfully."<<endl;
                                            tempflag = 1;
                                        }
                                    }

                                    if(tempflag == 0)
                                        cout<<endl<<"No such reservation found."<<endl;
                                    break;
                        }
                        break;



                case 4: cout<<endl;
                        cout<<"Enter 1 to check cards."<<endl;
                        cout<<"Enter 2 to add a card."<<endl;
                        cout<<"Enter 3 to delete a card."<<endl;
                        cout<<"Enter your choice:"<<endl;
                        cin>>(choice4);
                        switch(choice4)
                        {
                            case 1: inner_flag = 0;
                                    for(int j=0; j<Warr[key].no_cards; j++)
                                    {
                                        Warr[key].C[j]->displaycards();
                                        inner_flag = 1;
                                    }
                                    if(inner_flag == 0)
                                        cout<<endl<<"No cards present"<<endl;
                                    break;

                            case 2: Warr[key].no_cards++;
                                    //Warr[key].R[Warr[key].no_cards-1]= &R[Warr[key].no_reserve-1];
                                    Warr[key].C[Warr[key].no_cards-1]= new Cards;
                                    Warr[key].C[Warr[key].no_cards-1]->addcard();
                                    break;

                            case 3: long delcard;
                                    int tempflag = 0;

                                    cout<<"Enter card number to be deleted: ";
                                    cin>>delcard;

                                    for(int j=0; j<Warr[key].no_cards; j++)
                                    {
                                        if(Warr[key].C[j]->cardno == delcard)
                                        {
                                            //delete Warr[key].C[j];
                                            swap(Warr[key].C[j],Warr[key].C[Warr[key].no_cards -1]);
                                            Warr[key].no_cards--;
                                            cout<<endl<<"Card deleted successfully."<<endl;
                                            tempflag = 1;
                                        }
                                    }

                                    if(tempflag == 0)
                                        cout<<endl<<"No such card found."<<endl;
                                    break;

                        }
                        break;


               case 5: cout<<endl;
                        cout<<"Enter 1 to check license details."<<endl;
                        cout<<"Enter 2 to check passport details."<<endl;
                        cout<<"Enter 3 to check PAN details."<<endl;
                        cout<<"Enter your choice: ";
                        cin>>choice3;

                        switch(choice3)
                        {
                            case 1: cout<<endl;
                                    cout<<"Enter 1 to display license."<<endl;
                                    cout<<"Enter 2 to add license."<<endl;
                                    cout<<"Enter 3 to delete license."<<endl;
                                    cout<<"Enter your choice: ";
                                    cin>>choice4;

                                    switch(choice4)
                                    {
                                        case 1: {
                                                inner_flag = 0;
                                                for(int j=0; j<Warr[key].no_docs; j++)
                                                {
                                                    if(Warr[key].D[j]->type == "License")
                                                    {
                                                        Warr[key].D[j]->display();
                                                        inner_flag = 1;
                                                    }
                                                }
                                                if(inner_flag == 0)
                                                    cout<<endl<<"No license."<<endl;
                                                break;}

                                        case 2: {
                                                Warr[key].no_docs++;
                                                type1=DT_License;
                                                Warr[key].D[Warr[key].no_docs-1]=Factory2::create(type1);
                                                Warr[key].D[Warr[key].no_docs-1]->add();
                                                break; }

                                        case 3: {
                                                inner_flag = 0;
                                                int tempflag;
                                                string todel;
                                                cout<<"Enter license number to be deleted: ";
                                                cin>>todel;

                                                for(int j=0; j<Warr[key].no_docs; j++)
                                                {
                                                    if(Warr[key].D[j]->type == "License")
                                                    {
                                                        tempflag = Warr[key].D[j]->deletedoc(todel);
                                                        if(tempflag == 1)
                                                        {
                                                            swap(Warr[key].D[j],Warr[key].D[Warr[key].no_docs-1]);
                                                            cout<<endl<<"License deleted successfully."<<endl;
                                                            Warr[key].no_docs--;
                                                            inner_flag = 1;
                                                        }
                                                    }
                                                }

                                                if(inner_flag == 0)
                                                    cout<<endl<<"No such license found."<<endl;
                                                break;}

                                       default: cout<<endl;
                                                 cout<<"Invalid choice."<<endl;
                                                 break;
                                    }

                                    break;

                            case 2: cout<<endl;
                                    cout<<"Enter 1 to display passport."<<endl;
                                    cout<<"Enter 2 to add passport."<<endl;
                                    cout<<"Enter 3 to delete passport."<<endl;
                                    cout<<"Enter your choice: ";
                                    cin>>choice4;

                                    switch(choice4)
                                    {
                                        case 1: {
                                                inner_flag = 0;
                                                for(int j=0; j<Warr[key].no_docs; j++)
                                                {
                                                    if(Warr[key].D[j]->type == "Passport")
                                                    {
                                                        Warr[key].D[j]->display();
                                                        inner_flag = 1;
                                                    }
                                                }
                                                if(inner_flag == 0)
                                                    cout<<endl<<"No Passport"<<endl;
                                                break;
                                                }


                                        case 2: {
                                                Warr[key].no_docs++;
                                                type1=DT_Passport;
                                                Warr[key].D[Warr[key].no_docs-1]=Factory2::create(type1);
                                                Warr[key].D[Warr[key].no_docs-1]->add();
                                                break;
                                                }

                                        case 3: {
                                                inner_flag = 0;
                                                int tempflag;
                                                string todel;
                                                cout<<endl<<"Enter passport number to be deleted: ";
                                                cin>>todel;

                                                for(int j=0; j<Warr[key].no_docs; j++)
                                                {
                                                    if(Warr[key].D[j]->type == "Passport")
                                                    {
                                                        tempflag = Warr[key].D[j]->deletedoc(todel);
                                                        if(tempflag == 1)
                                                        {
                                                            swap(Warr[key].D[j],Warr[key].D[Warr[key].no_docs-1]);
                                                            cout<<endl<<"Passport deleted successfully."<<endl;
                                                            Warr[key].no_docs--;
                                                            inner_flag = 1;
                                                        }
                                                    }
                                                }

                                                if(inner_flag == 0)
                                                    cout<<endl<<"No such passport found."<<endl;
                                                break;
                                                }


                                        default: cout<<endl;
                                                 cout<<"Invalid choice."<<endl;
                                                 break;
                                    }

                                    break;

                            case 3: cout<<endl;
                                    cout<<"Enter 1 to display PAN"<<endl;
                                    cout<<"Enter 2 to add PAN."<<endl;
                                    cout<<"Enter 3 to delete PAN."<<endl;
                                    cout<<"Enter your choice: ";
                                    cin>>choice4;

                                    switch(choice4)
                                    {
                                        case 1: {
                                                inner_flag = 0;
                                                for(int j=0; j<Warr[key].no_docs; j++)
                                                {
                                                    if(Warr[key].D[j]->type == "PAN")
                                                    {
                                                        Warr[key].D[j]->display();
                                                        inner_flag = 1;
                                                    }
                                                }
                                                if(inner_flag == 0)
                                                    cout<<endl<<"No PAN."<<endl;
                                                break;
                                                }

                                        case 2: {
                                                Warr[key].no_docs++;
                                                type1=DT_PAN;
                                                Warr[key].D[Warr[key].no_docs-1]=Factory2::create(type1);
                                                Warr[key].D[Warr[key].no_docs-1]->add();
                                                break;
                                                }

                                        case 3: {inner_flag = 0;
                                                int tempflag;
                                                string todel;
                                                cout<<endl<<"Enter PAN to be deleted: ";
                                                cin>>todel;

                                                for(int j=0; j<Warr[key].no_docs; j++)
                                                {
                                                    if(Warr[key].D[j]->type == "PAN")
                                                    {
                                                        tempflag = Warr[key].D[j]->deletedoc(todel);
                                                        if(tempflag == 1)
                                                        {
                                                            swap(Warr[key].D[j],Warr[key].D[Warr[key].no_docs-1]);
                                                            cout<<endl<<"PAN deleted successfully."<<endl;
                                                            Warr[key].no_docs--;
                                                            inner_flag = 1;
                                                        }
                                                    }
                                                }

                                                if(inner_flag == 0)
                                                    cout<<endl<<"No such PAN found."<<endl;

                                                break;
                                                }

                                        default: cout<<endl;
                                                 cout<<"Invalid choice."<<endl;
                                                 break;
                                    }

                                    break;

                            default: cout<<endl;
                                     cout<<"Invalid choice."<<endl;
                                     break;
                        }

                        break;

                case 6: cout<<endl;
                        cout<<"You have been logged out."<<endl;
                        cout<<endl;
                        goto START;
                        break;

                case 7: cout<<endl;
                        cout<<"Thank you."<<endl;
                        exit(0);

                default: cout<<endl;
                         cout<<"Invalid choice."<<endl;
                         break;
            }
        }
        }
    }

    if(flag == 0)
        throw("Wrong username or password");
    }

    catch(const char* message)
    {
        cout<<endl<<message<<endl;
    }

    return 0;
}
