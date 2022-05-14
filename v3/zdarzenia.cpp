#include <iostream>
#include "pojazdy.h"
#include <vector>
#include <ctime>
#include <clocale>
#include <cstdlib>

using namespace std;

string LWSending;
string FSending;
string RSending;
string ATrucks;
string Info = "Na miejsce zdarzenia dysponuje: ";
string Info2 = " oraz ";
int flag = 0;

//Pojazdy strazackie nalezace do jednostki//

FireTrucks srt("Iveco ", "SRT", 0, 2);
FireTrucks sd("Mercedes ", "SD", 0, 2);
FireTrucks srchem("Volvo ", "SRCHEM", 0, 3);
FireTrucks gbart("Man ", "GBART", 3000, 6);
FireTrucks gcba1("Man ", "GCBA", 5000, 6);
FireTrucks gcba2("Scania ", "GCBA", 10000, 2);
FireTrucks gcba3("Mercedes ", "GCBA", 6000, 6);
FireTrucks gba1("Volvo ","GBA",2500,6);
FireTrucks gba2("Renault ","GBA",3500,6);
FireTrucks gcbm("Man ","GCBM",20000,2);

char bufor[64];
time_t czas;

    void Fire::setTypeFire()
    {
        int Type;

        cout << "\nRodzaj pozaru:" << endl;
        cout << "[1].Obiekty mieszkalne \n[2].Lasy,pola,trawy,stogi \n[3].Srodki transportu drogowego \n[4].Magazyny "
                "\n[5].Smietniki, wysypiska \n[6].Instytucje, obiekty uzytecznosci publicznej "
                "\n[7].Obiekty gospodarcze i inne rolnicze \n[8].Obiekty produkcyjne, instalacje "
                "technologiczne, rurociagi, urzadzenia \n[9].Inne pozary"<< endl;

        cout << "Podaj numer rodzaju zdarzenia: ";
        cin >> Type;

        if (Type == 1) type = "Obiekty mieszkalne";
        if (Type == 2) type = "Lasy,pola,trawy,stogi";
        if (Type == 3) type = "Srodki transportu drogowego";
        if (Type == 4) type = "Magazyny";
        if (Type == 5) type = "Smietniki, wysypiska";
        if (Type == 6) type = "Instytucje, obiekty uzytecznosci publicznej";
        if (Type == 7) type = "Obiekty gospodarcze i inne rolnicze";
        if (Type == 8) type = "Obiekty produkcyjne, instalacje technologiczne, rurociagi, urzadzenia";
        if (Type == 9) type = "Inne pozary";
        if (Type == 0 || Type > 9) exit(0);
    }

    void Fire::setSmokeFire()
    {
        int Smoke;

        cout << "\nPodaj wystepujace zadymienie: " << endl;
        cout << "[1].Male \n[2].Duze" << endl;

        cout << "Podaj numer zadymienia: ";
        cin >> Smoke;

        if (Smoke == 1) smoke = "Male";
        if (Smoke == 2) smoke = "Duze";
        if (Smoke == 0 || Smoke > 2) exit(0);
    }

    void Fire::setLocationFire()
    {
        cout << "\nWprowadz miejscowosc pozaru: ";
        cin >> location;
    }

    void Fire::setAreaFire() {

        int Area;

        cout << "\nWybierz powierzchnie pozaru: " << endl;
        cout << "[1].Maly (do 70 m^2, do 350 m^3 oraz do 1 ha) \n[2].Sredni (do 300 m^2, do 1500 m^3 oraz do 10 ha) "
                "\n[3].Duzy (do 1000 m^2, do 5000 m^3 oraz do 100 ha) \n[4].Bardzo duzy (ponad 1000 m^2, ponad 5000 m^3 oraz ponad 100 ha)" <<endl;

        cout << "Podaj numer powierzchni: ";
        cin >> Area;

        if (Area == 1) area = "Maly";
        if (Area == 2) area = "Sredni";
        if (Area == 3) area = "Duzy";
        if (Area == 4) area = "Bardzo duzy";
        if (Area == 0 || Area > 4) exit(0);
    }

    void Fire::getWaterAmount()
    {
        int Water1;
        int Water2;
        int Water3;
        int WaterAmount;

        if(type=="Obiekty mieszkalne" || type=="Instytucje, obiekty uzytecznosci publicznej" || type=="Magazyny") Water1 = 10000;
        if(type=="Lasy,pola,trawy,stogi" || type=="Obiekty gospodarcze i inne rolnicze") Water1 = 8000;
        if(type=="Smietniki, wysypiska" || type=="Srodki transportu drogowego" || type=="Obiekty produkcyjne, instalacje technologiczne, rurociagi, urzadzenia") Water1 = 5000;
        if(type=="Inne pozary") Water1 = 2000;
        if(area=="Maly") Water2 = 3000;
        if(area=="Sredni") Water2 = 5000;
        if(area=="Duzy") Water2 = 8000;
        if(area=="Bardzo duzy") Water2 = 15000;
        if(smoke=="Male") Water3 = 5000;
        if(smoke=="Duze") Water3 = 8000;

        if(area=="Maly" && smoke=="Male") WaterAmount = Water1;
        else WaterAmount = Water1 + Water3 + Water2;

        water = WaterAmount;
    }

    void Fire::testSending()
    {
        vector<string> firetrucksNames;
        vector<string> availabletrucks;
        vector<FireTrucks> firetrucksList;

        firetrucksList.push_back(gba1);
        firetrucksList.push_back(gbart);
        firetrucksList.push_back(gba2);
        firetrucksList.push_back(gcba1);
        firetrucksList.push_back(gcba3);
        firetrucksList.push_back(gcba2);
        firetrucksList.push_back(gcbm);

        int suma = 0;

        for(int i = 0; i < firetrucksList.size(); i++)
        {
            firetrucksNames.push_back(firetrucksList[i].getName() + firetrucksList[i].getType() + " ");

            suma += firetrucksList[i].getWatertank();

            flag = i + 1;

            if(suma >= water)
            {
                break;
            }
        }

        cout << "\nFlaga: " << flag << endl;

        for(int j = 0; j < firetrucksNames.size() ;j++)
        {
            FSending += firetrucksNames[j];
        }

        for(int k = flag; k < firetrucksList.size(); k++)
        {
            availabletrucks.push_back(firetrucksList[k].getName() + firetrucksList[k].getType() + " ");
        }

        for(int j = 0; j < availabletrucks.size();j++)
        {
            ATrucks += availabletrucks[j];
        }

    }

    void Fire::fireInformation()
    {
        time(&czas);
        tm czasTM = *localtime(&czas);
        setlocale( LC_ALL, "Polish" );
        strftime(bufor, sizeof(bufor), "%c", &czasTM);

        string housefire = gba2.name + gba2.type + " oraz " + gcba1.name + gcba1.type + " oraz " + gcba2.name + gcba2.type + " oraz " + sd.name + sd.type;

        cout << "\n++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++Informacja o zdarzeniu++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++" << endl;
        cout << "\nData zgloszenia: " << bufor << endl;
        cout << "Rodzaj pozaru: " << type << endl;
        cout << "Miejscowosc zdarzenia: " << location << endl;
        cout << "Powierzchnia: " << area << endl;
        cout << "Zadymienie: " << smoke << endl;
        cout << "Ilosc potrzebnej wody: " << water << " [L] " << endl;
        if(type=="Obiekty mieszkalne" || type=="Instytucje, obiekty uzytecznosci publicznej")  cout << Info + housefire << endl;
        else cout << Info + FSending << endl;
        cout << "Dostepne samochody: " << ATrucks << endl;
        FSending.clear();
        ATrucks.clear();

    }

    void Road::setRoad()
    {
        int Type;
        int Deadlock;

        cout << "\nRodzaj zdarzenia drogowego:" << endl;
        cout << "[1].Kolizja \n[2].Wypadek\n" << endl;

        cout << "Podaj numer rodzaju zdarzenia: ";
        cin >> Type;

        if(Type == 0 || Type > 2) exit(0);
        if(Type == 1) type = "Kolizja";
        if(Type == 2) type = "Wypadek";

        if(type=="Kolizja")
        {
            cout << "\nPodaj liczbe aut bioracych udzial w kolizji: ";

            cin >> cars;

            if(cars<=0) exit(0);

            cout << "\nPodaj liczbe osob poszkodowanych:";

            cin >> victims;

            if(victims<0) exit(0);
        }

        if(type=="Wypadek")
        {
            cout << "\nPodaj liczbe aut bioracych udzial w wypadku: ";

            cin >> cars;

            if(cars<=0) exit(0);

            cout << "\nPodaj liczbe osob poszkodowanych:";

            cin >> victims;

            if(victims<0) exit(0);

            cout << "\nCzy osoby w pojazdach sa zakleszczone?" << endl;
            cout << "[1].Tak \n[2].Nie" << endl;
            cout << "Podaj odpowiedz: ";

            cin >> Deadlock;

            if(Deadlock == 1) deadlock = "Tak";
            if(Deadlock == 2) deadlock = "Nie";
            if(Deadlock == 0 || Deadlock > 2) exit(0);
        }

    }

    void Road::setLocationRoad()
    {
        cout << "\nWprowadz miejscowosc wypadku: ";
        cin >> location;
    }

    void Road::getRescuersAmount()
    {
        int Rescuers1 = 0;
        int Rescuers2 = 0;
        int Rescuers3 = 0;
        int RescuersAmmount;

        if(type=="Kolizja")
        {
            if(cars==1 || cars==2) Rescuers1 = 6;
            if(cars>2) Rescuers1 = 8;
            if(victims>0) Rescuers2 = 6;
            if(victims==0) Rescuers2 = 0;
        }
        if(type=="Wypadek")
        {
            if(cars>=1) Rescuers1 = 8;
            if(victims>0) Rescuers2 = 6;
            if(victims==0) Rescuers2 = 0;
            if(deadlock=="Tak") Rescuers3 = 2;
            if(deadlock=="Nie") Rescuers3 = 0;
        }

        RescuersAmmount = Rescuers1 + Rescuers2 + Rescuers3;
        rescuers = RescuersAmmount;
    }

    void Road::RoadTestSending()
    {
        vector <string> roadtrucksNames;
        vector <FireTrucks> roadtrucksList;

        roadtrucksList.push_back(srt);
        roadtrucksList.push_back(gbart);
        roadtrucksList.push_back(gba1);
        roadtrucksList.push_back(gba2);

        int suma = 0;

        for(int i = 0; i < roadtrucksList.size(); i++)
        {
            roadtrucksNames.push_back(roadtrucksList[i].getName() + roadtrucksList[i].getType() + " ");

            suma += roadtrucksList[i].getFiremans();

            if(suma > rescuers)
            {
                break;
            }

        }

        for(int j = 0; j < roadtrucksNames.size(); j++)
        {
            RSending += roadtrucksNames[j];
        }

    }

    void Road::roadInformation()
    {
        time(&czas);
        tm czasTM = *localtime(&czas);
        setlocale( LC_ALL, "Polish" );
        strftime(bufor, sizeof(bufor), "%c", &czasTM);

        cout << "\n++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++Informacja o zdarzeniu++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++" << endl;
        cout << "\nData zgloszenia: " << bufor << endl;
        cout << "Rodzaj zdarzenia drogowego: " << type << endl;
        cout << "Miejscowosc zdarzenia: " << location << endl;
        cout << "Liczba poszkodowanych: " << victims << endl;
        cout << "Liczba pojazdow: " << cars << endl;
        if(type=="Wypadek") cout << "Zakleszczenie: " << deadlock << endl;
        cout << "Liczba potrzebnych ratownikow: " << rescuers << endl;
        cout << Info + RSending << endl;
        RSending.clear();
    }

    void LocalWarning::setLocalWarning()
    {
        int Type;

        cout << "\nWybierz rodzaj miejscowego zdarzenia: " << endl;

        cout << "\n[1].Powalone drzewo \n[2].Naderwany konar \n[3].Zerwana linia energetyczna \n[4].Pomoc innym sluzbom \n[5].Zagrozenie chemiczne \n[6].Pomoc w otwarciu mieszkania \n[7].Budowlane \n[8].Gniazdo owadow blonkoskrzydlych" << endl;

        cout << "\nPodaj numer rodzaju zdarzenia: ";
        cin >> Type;

        if(Type == 0 || Type > 8) exit(0);
        if (Type == 1) type = "Powalone drzewo";
        if (Type == 2) type = "Naderwany konar";
        if (Type == 3) type = "Zerwana linia energetyczna";
        if (Type == 4) type = "Pomoc innym sluzbom";
        if (Type == 5) type = "Zagrozenie chemiczne";
        if (Type == 6) type = "Pomoc w otwarciu mieszkania";
        if (Type == 7) type = "Budowlane";
        if (Type == 8) type = "Gniazdo owadow blonkoskrzydlych";
    }

    void LocalWarning::setLWLocation()
    {
        cout << "\nWprowadz miejscowosc zdarzenia: ";
        cin >> location;
    }
    void LocalWarning::LocalWarningFireBrigadeSending() const {
        vector<FireTrucks> gbaList;

        gbaList.push_back(gbart);
        gbaList.push_back(gba1);
        gbaList.push_back(gba2);

        srand(time(NULL));

        int vechicleNumber = (rand() % 3);

        if (type == "Naderwany konar")
        {
            LWSending = Info + gbaList[vechicleNumber].getName() + gbaList[vechicleNumber].getType() + Info2 + sd.name + sd.type;
        }
        else if(type == "Zagrozenie chemiczne")
        {
            LWSending = Info + gbaList[vechicleNumber].getName() + gbaList[vechicleNumber].getType() + Info2 + srchem.name + srchem.type;
        }
        else LWSending = Info + gbaList[vechicleNumber].getName() + gbaList[vechicleNumber].getType();

    }


    void LocalWarning::LocalWarningInformation() const
    {
        time(&czas);
        tm czasTM = *localtime(&czas);
        setlocale( LC_ALL, "Polish" );
        strftime(bufor, sizeof(bufor), "%c", &czasTM);

        cout << "\n++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++Informacja o zdarzeniu++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++" << endl;
        cout << "\nData zgloszenia: " << bufor << endl;
        cout << "Rodzaj miejscowego zdarzenia: " << type << endl;
        cout << "Miejscowosc zdarzenia: " << location << endl;
        cout << LWSending;
    }