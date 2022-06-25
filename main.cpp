#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <mysql.h>
#include <stdexcept>

#define HOST ""
#define BASE ""
#define USER ""
#define PASS ""

int a=1,b=1,c=1;

using namespace std;


void nowa_osoba()
{

    MYSQL* connect;
    connect = mysql_init(0);
    connect = mysql_real_connect(connect, HOST, USER, PASS, BASE, 0, NULL, 0);

    if(!connect)
    {
        fprintf(stderr, "Rozpoczecie pracy MySQL sie nie powiodlo");
    }

    string problem;
    string kierunek;
    string student_kandydat;
    string tryb;
    string poziom;
    string query;


    cout << "Student czy kandydat? \n1 - Student\n2 - Kandydat" << endl;
    cin >> student_kandydat;
    int student_kandydat1 = stoi(student_kandydat);
    switch(student_kandydat1)
    {
    case 1:
        student_kandydat = "student";
        break;
    case 2:
        student_kandydat = "kandydat";
        break;
    }

    cout << "Ktory kierunek? \n1 - Informatyka\n2 - Elektronika\n3 - Teleinformatyka" << endl;
    cin >> kierunek;
    int kierunek1= stoi(kierunek);
    switch (kierunek1)
    {
    case 1:
        kierunek="informatyka";
        break;
    case 2:
        kierunek="elektronika";
        break;
    case 3:
        kierunek="teleinformatyka";
        break;
    }

    cout<< "Jaki tryb? \n1 - Stacjonarny\n2 - Zaoczny"<<endl;
    cin >>tryb;
    int tryb1 = stoi(tryb);
    switch(tryb1)
    {
    case 1:
        tryb="stacjonarny";
        break;
    case 2:
        tryb="zaoczny";
        break;
    }

    cout << "Ktory poziom studiow? \n1 - Inzynier\n2 - Magister\n3 - Doktorat"<<endl;
    cin>>poziom;
    int poziom1 = stoi(poziom);
    switch(poziom1)
    {
        case 1: poziom="inzynier";break;
        case 2: poziom="magister";break;
        case 3: poziom="doktorat";break;
    }

    cout<< "Jaki masz problem? Wpisz uzywajac max 100 znakow:"<<endl;

    cin.get();
    getline( cin, problem );

    query = "INSERT INTO `" + kierunek + "`(`osoba`,`poziom`,`tryb`,`problem`) VALUES ('" + student_kandydat + "','" + poziom + "','" + tryb + "','" + problem + "');";



    mysql_query(connect, query.c_str());
}

int main()
{
    int wybrana_opcja=0;
    MYSQL* connect;
    connect = mysql_init(0);
    connect = mysql_real_connect(connect, HOST, USER, PASS, BASE, 0, NULL, 0);


    string kieruneka;
    string kierunekb;
    void nowa_osoba();
    while (wybrana_opcja != 4)
    {
        cout << "Witamy w kolejce do dziekanatu" << endl;
        cout << "Menu:\n1 - Dodaj nowego studenta do kolejki \n2 - Student zostal obsluzony \n3 - Pokaz kto ma podejsc do okienka\n4 - Wyjscie" << endl;

        cin >> wybrana_opcja;
        if (wybrana_opcja == 1)
        {
            nowa_osoba();
        }
        else if (wybrana_opcja == 2)
        {
            cout <<"Ktory kierunek? \n1-Informatyka\n2-Elektronika\n3-Teleinformatyka"<<endl;
            cin >> kieruneka;
            if (kieruneka=="1")
            {
                string query;
                string o;
                o = to_string(a);

                query = "DELETE FROM informatyka WHERE id="+ o +";";
                mysql_query(connect, query.c_str());
                a++;
            }
            if (kieruneka=="2")
            {
                string query;
                string o;

                o = to_string(b);

                query = "DELETE FROM elektronika WHERE id="+ o +";";
                mysql_query(connect, query.c_str());
                b++;
            }
            if (kieruneka=="3")
            {
                string query;
                string o;

                o = to_string(c);

                query = "DELETE FROM teleinformatyka WHERE id="+ o +";";
                mysql_query(connect, query.c_str());
                c++;
            }

        }
        else if (wybrana_opcja == 3)
        {
            cout << "Ktory kierunek? \n1-Informatyka\n2-Elektronika\n3-Teleinformatyka"<<endl;
            cin >>kierunekb;
            if (kierunekb=="1")
            {
                MYSQL_ROW row;
                MYSQL_RES* res;

                string o;
                string query;

                o=to_string(a);

                query="SELECT osoba,poziom,tryb,problem FROM informatyka WHERE id="+o+";";


                if(connect)
                {
                    int qstate = mysql_query(connect,query.c_str());
                    if(!qstate)
                    {
                        res = mysql_store_result(connect);

                        while(row = mysql_fetch_row(res))
                        {
                            cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
                        }
                    }
                }

            }
            if (kierunekb=="2")
            {
                MYSQL_ROW row;
                MYSQL_RES* res;

                string o;
                string query;

                o=to_string(b);
                query="SELECT osoba,poziom,tryb,problem FROM elektronika WHERE id="+o+";";

                if(connect)
                {
                    int qstate = mysql_query(connect,query.c_str());
                    if(!qstate)
                    {
                        res = mysql_store_result(connect);

                        while(row = mysql_fetch_row(res))
                        {
                            cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
                        }
                    }
                }

            }

            if (kierunekb=="3")
            {
                MYSQL_ROW row;
                MYSQL_RES* res;

                string o;
                string query;

                o=to_string(c);
                query="SELECT osoba,poziom,tryb,problem FROM teleinformatyka WHERE id="+o+";";

                if(connect)
                {
                    int qstate = mysql_query(connect,query.c_str());
                    if(!qstate)
                    {
                        res = mysql_store_result(connect);

                        while(row = mysql_fetch_row(res))
                        {
                            cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
                        }
                    }
                }

            }

        }
    }


    return 0;
}
