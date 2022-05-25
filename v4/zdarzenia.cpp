#include <iostream>
#include "pojazdy.h"
#include <vector>
#include <ctime>
#include <clocale>
#include <algorithm>
#include <fstream>

using namespace std;

string LWSending; //zmienna globalna przechowujaca pojazdy wysylane do miejscowych zagrozen
string FSending; //zmienna globalna przechowujaca pojazdy wysylane do pozarow
string RSending; //zmienna globalna przechowujaca pojazdy wysylane do wypadkow i kolizji
string ATrucks; //zmienna globalna przechowujaca pojazdy pozostale, niewyslane do pozarow
string ARTrucks; //zmienna globalna przechowujaca pojazdy pozostale, niewyslane do wypadkow czy kolizji
int firefighters; //zmienna globalna przechowujaca liczbe strazakow wysylanych do zdarzenia

string Info = "Na miejsce zdarzenia dysponuje: ";
string Info2 = " oraz ";

int flag = 0; //flaga wykorzystywana w ustalaniu pozostalych pojazdow, niewyslanych do zdarzen
int Counter = 0;

vector<FireTrucks> firetruckstest; //wektor przechowujacy pojazdy wysylane do pozarow
vector<FireTrucks> roadtrucks; //wektor przechowujacy pojazdy wysylane do wypadkow
vector<FireTrucks> localwarningtrucks; //wektor przechowujacy pojazdy wysylane do miejscowych zagrozen

char bufor[64]; //ustawianie czasu lokalnego
time_t czas;

    void Fire::createDatabase() //metoda pozwalajaca na stworzenie wlasnej bazy danych pojazdow
    {
        int watertank;
        int firemans;
        string name;
        string type;
        int trucksCount;
        int counter = 0;

        cout << "\nIle pojazdow chcesz dodac do listy?\n";
        while(!(cin>>trucksCount)) //sprawdzenie poprawnosci wprowadzonej zmiennej
        {
            cout << "Wprowadziles bledna wartosc!";
            cout << "\nPodaj wartosc jeszcze raz: ";
            cin.clear();
            cin.sync();
        }
        if(trucksCount <= 0) //przerwanie dzialania programu przy spelnieniu warunku
        {
            exit(0);
        }

        ofstream file("database.txt");

        for(int i = 0; i < trucksCount; i++){
            cout << "\nPodaj nazwe " << i + 1 << " pojazdu:";
            cin >> name;
            cout << "Podaj typ " << i + 1 << " pojazdu: ";
            cin >> type;
            cout << "Podaj pojemnosc zbiornika na wode " << i + 1 << " pojazdu: ";
            while(!(cin>>watertank)) //sprawdzenie poprawnosci wprowadzonej zmiennej
            {
                cout << "Wprowadziles bledna wartosc!";
                cout << "\nPodaj pojemnosc zbiornika " << i + 1 << " pojazdu: ";
                cin.clear();
                cin.sync();
            }
            cout << "Podaj liczbe zalogi " << i + 1 << " pojazdu: ";
            while(!(cin>>firemans)) //sprawdzenie poprawnosci wprowadzonej zmiennej
            {
                cout << "Wprowadziles bledna wartosc!";
                cout << "\nPodaj liczbe zalogi " << i + 1 << " pojazdu: ";
                cin.clear();
                cin.sync();
            }

            file << name << ';' << type << ';' << watertank << ';' << firemans << '\n';

            if(type=="GBA" || type=="GBART") //lekkie pojazdy ratownicze przypisywane do wektora obiektow dla zdarzen drogowych i miejscowych zagrozen
            {
                FireTrucks roadtruck(name,type,watertank,firemans);
                roadtrucks.push_back(roadtruck);
                FireTrucks localwarning(name, type, watertank, firemans);
                localwarningtrucks.push_back(localwarning);
                sort(roadtrucks.begin(),roadtrucks.end()); //sortowanie wektora obiektow ze wzgledu na ilosc wody w zbiorniku
                sort(localwarningtrucks.begin(),localwarningtrucks.end()); //sortowanie wektora obiektow ze wzgledu na ilosc wody w zbiorniku
            }

            FireTrucks firetruck(name,type,watertank,firemans);
            firetruckstest.push_back(firetruck);
            sort(firetruckstest.begin(),firetruckstest.end()); //sortowanie wektora obiektow ze wzgledu na ilosc wody w zbiorniku

        }
        Counter = trucksCount;
        file.close();
    }
    void Fire::loadCreatedDatabase() //metoda pozwalajaca na wczytanie wczesniej utworzonej bazy danych
    {
        ifstream file;
        file.open("C:\\Users\\kubam\\CLionProjects\\straz\\cmake-build-debug\\database.txt"); //wczytywanie pliku .txt zawierajacego baze danych

        string line;

        string name;
        string type;
        int watertank;
        int firebrigade;
        int i = 0;
        int counter = 0;

        while(!file.eof()) //zczytywanie danych z pliku do zmiennych nastepnie przypisywanie do obiektow
        {
            counter += i + 1;
            i++;

            getline(file,line,';');
            name=line;

            getline(file,line,';');
            type=line;

            getline(file,line,';');
            watertank = atoi(line.c_str());

            getline(file,line,'\n');
            firebrigade = atoi(line.c_str());

            if(type=="GBA" || type=="GBART") //specyficzne pojazdy dla wektorow dla zdarzen drogowych i miejscowych zagrozen
            {
                FireTrucks roadtruck(name,type,watertank,firebrigade);
                roadtrucks.push_back(roadtruck);
                FireTrucks localwarning(name, type, watertank, firebrigade);
                localwarningtrucks.push_back(localwarning);
                sort(roadtrucks.begin(),roadtrucks.end()); //sortowanie wektora obiektow ze wzgledu na ilosc wody w zbiorniku
                sort(localwarningtrucks.begin(),localwarningtrucks.end()); //sortowanie wektora obiektow ze wzgledu na ilosc wody w zbiorniku
            }

            FireTrucks firetruck(name,type,watertank,firebrigade);
            firetruckstest.push_back(firetruck);
            sort(firetruckstest.begin(),firetruckstest.end()); //sortowanie wektora obiektow ze wzgledu na ilosc wody w zbiorniku

        }

        Counter = counter/4;
    }

    void Fire::loadDatabase() //metoda pozwalajaca na wczytanie pojazdow z bazy danych
    {
        ifstream inputFile;
        inputFile.open("C:\\Users\\kubam\\CLionProjects\\straz\\firebrigade.txt"); //wczytywanie pliku .txt zawierajacego baze danych

        string line;

        string name;
        string type;
        int watertank;
        int firebrigade;
        int i = 0;
        int counter = 0;

        while(!inputFile.eof()) //zczytywanie danych z pliku do zmiennych nastepnie przypisywanie do obiektow
        {
            counter += i + 1;
            i++;

            getline(inputFile,line,';');
            name=line;

            getline(inputFile,line,';');
            type=line;

            getline(inputFile,line,';');
            watertank = atoi(line.c_str());

            getline(inputFile,line,'\n');
            firebrigade = atoi(line.c_str());

            if(type=="GBA" || type=="GBART") //specyficzne pojazdy dla wektorow dla zdarzen drogowych i miejscowych zagrozen
            {
                FireTrucks roadtruck(name,type,watertank,firebrigade);
                roadtrucks.push_back(roadtruck);
                FireTrucks localwarning(name, type, watertank, firebrigade);
                localwarningtrucks.push_back(localwarning);
            }

            FireTrucks firetruck(name,type,watertank,firebrigade);
            firetruckstest.push_back(firetruck);
        }

        Counter = counter/4;
    }

    void Fire::setTypeFire() //metoda pozwalajaca ustawic dany rodzaj pozaru
    {
        int Type;

        cout << "\nRodzaj pozaru:" << endl;
        cout << "[1].Obiekty mieszkalne \n[2].Lasy,pola,trawy,stogi \n[3].Srodki transportu drogowego \n[4].Magazyny "
                "\n[5].Smietniki, wysypiska \n[6].Instytucje, obiekty uzytecznosci publicznej "
                "\n[7].Obiekty gospodarcze i inne rolnicze \n[8].Obiekty produkcyjne, instalacje "
                "technologiczne, rurociagi, urzadzenia \n[9].Inne pozary"<< endl;

        cout << "\nPodaj numer rodzaju zdarzenia:";
        while(!(cin>>Type)) //sprawdzenie poprawnosci wprowadzonej zmiennej
        {
            cout << "Wprowadziles bledna wartosc!";
            cout << "\nPodaj wartosc jeszcze raz: ";
            cin.clear();
            cin.sync();
        }

        if (Type <= 0 || Type > 9) exit(0); //przerwanie dzialania programu przy spelnieniu warunku
        if (Type == 1) type = "Obiekty mieszkalne";
        if (Type == 2) type = "Lasy,pola,trawy,stogi";
        if (Type == 3) type = "Srodki transportu drogowego";
        if (Type == 4) type = "Magazyny";
        if (Type == 5) type = "Smietniki, wysypiska";
        if (Type == 6) type = "Instytucje, obiekty uzytecznosci publicznej";
        if (Type == 7) type = "Obiekty gospodarcze i inne rolnicze";
        if (Type == 8) type = "Obiekty produkcyjne, instalacje technologiczne, rurociagi, urzadzenia";
        if (Type == 9) type = "Inne pozary";
    }

    void Fire::setSmokeFire() //ustawienie zadymienia pozaru
    {
        int Smoke;

        cout << "\nPodaj wystepujace zadymienie: " << endl;
        cout << "[1].Male \n[2].Duze" << endl;

        cout << "Podaj numer zadymienia:";
        while(!(cin>>Smoke)) //sprawdzenie poprawnosci wprowadzonej zmiennej
        {
            cout << "Wprowadziles bledna wartosc!";
            cout << "\nPodaj wartosc jeszcze raz: ";
            cin.clear();
            cin.sync();
        }
        if (Smoke <= 0 || Smoke > 2) exit(0); //przerwanie dzialania programu przy spelnieniu warunku

        if (Smoke == 1) smoke = "Male";
        if (Smoke == 2) smoke = "Duze";
    }

    void Fire::setLocationFire() //metoda pozwalajaca na ustawienie lokalizacji pozaru
    {
        cout << "\nWprowadz miejscowosc pozaru:";
        cin >> location;
    }

    void Fire::setAreaFire() //metoda pozwalajaca na ustawienie powierzchni pozaru
    {
        int Area;

        cout << "\nWybierz powierzchnie pozaru:" << endl;
        cout << "[1].Maly (do 70 m^2, do 350 m^3 oraz do 1 ha) \n[2].Sredni (do 300 m^2, do 1500 m^3 oraz do 10 ha) "
                "\n[3].Duzy (do 1000 m^2, do 5000 m^3 oraz do 100 ha) \n[4].Bardzo duzy (ponad 1000 m^2, ponad 5000 m^3 oraz ponad 100 ha)" <<endl;

        cout << "Podaj numer powierzchni: ";
        while(!(cin>>Area)) //sprawdzenie poprawnosci wprowadzonej zmiennej
        {
            cout << "Wprowadziles bledna wartosc!";
            cout << "\nPodaj wartosc jeszcze raz: ";
            cin.clear();
            cin.sync();
        }

        if (Area <= 0 || Area > 4) exit(0); //przerwanie dzialania programu przy spelnieniu warunku
        if (Area == 1) area = "Maly";
        if (Area == 2) area = "Sredni";
        if (Area == 3) area = "Duzy";
        if (Area == 4) area = "Bardzo duzy";
    }

    void Fire::getWaterAmount()
    {
        int Water1;
        int Water2;
        int Water3;
        int WaterAmount;
        int WaterAmount2;

        if(type=="Obiekty mieszkalne" || type=="Instytucje, obiekty uzytecznosci publicznej" || type=="Magazyny") Water1 = 10000;
        if(type=="Lasy,pola,trawy,stogi" || type=="Obiekty gospodarcze i inne rolnicze") Water1 = 8000;
        if(type=="Smietniki, wysypiska" || type=="Srodki transportu drogowego" || type=="Obiekty produkcyjne, instalacje technologiczne, rurociagi, urzadzenia") Water1 = 5000;
        if(type=="Inne pozary") Water1 = 2000;
        if(area=="Maly") Water2 = 3000;
        if(area=="Sredni") Water2 = 5000;
        if(area=="Duzy") Water2 = 15000;
        if(area=="Bardzo duzy") Water2 = 20000;
        if(smoke=="Male") Water3 = 5000;
        if(smoke=="Duze") Water3 = 8000;

        if(area=="Maly" && smoke=="Male") WaterAmount = Water1 + Water2 / 10 + Water3 / 10; //zliczanie potrzebnej ilosci wody do ugaszenia pozaru
        else WaterAmount = Water1 + Water3 + Water2;

        if(Counter>10) WaterAmount2 = 2 * WaterAmount;
        else WaterAmount2 = WaterAmount;

        water = WaterAmount2;
    }

    void Fire::fireSending() //metoda wysylajaca pojazdy do danego pozaru na podstawie potrzebnej ilosci wody
    {
        vector<string> firetrucksNames; //wektor stringow przechowujacy nazwy i typy pojazdow wysylanych do zdarzen
        vector<string> availabletrucks;

        int suma = 0;

        for(int i = 0; i < firetruckstest.size(); i++) //procedura pozwalajaca na wyslanie pojazdow do pozarow ze wzgledu na wymagana ilosc wody
        {                                              //z lekkim buforem
            firetrucksNames.push_back(firetruckstest[i].getName() + " " + firetruckstest[i].getType() + " ");

            suma += firetruckstest[i].getWatertank(); //zapisywanie ilosci wody danych pojazdow

            firefighters += firetruckstest[i].getFiremans();

            flag = i + 1; //flaga pozwalajaca na okreslenie momentu zakonczenia petli

            if(suma >= water) //jesli suma wody zawartej w zbiornikach pojazdow jest wieksza lub rowna ilosci potrzebnej wody petla konczy zadanie
            {
                break;
            }
        }

        for(int j = 0; j < firetrucksNames.size() ;j++) //petla pozawalajaca przypisac wyslane pojazdy do zmiennej globalnej Ftrucks
        {
            FSending += firetrucksNames[j];
        }

        for(int k = flag; k < firetruckstest.size(); k++) //ustalenie pojazdow dostepnych
        {
            availabletrucks.push_back(firetruckstest[k].getName() + " " + firetruckstest[k].getType() + " ");
        }

        for(int j = 0; j < availabletrucks.size();j++) //przypisanie dostepnych pojazdow do zmiennej globalnej ATrucks
        {
            ATrucks += availabletrucks[j];
        }

    }

    void Fire::fireInformation() //metoda odpowiada za wyswietlanie koncowych informacji dotyczacej pozaru
    {
        FireTrucks sd("Mercedes ", "SD", 0, 2); //pojazd typu drabina potrzebny przy pozarach budynkow itp.

        time(&czas); //procedura ustawiania czasu lokalnego przypisanego do zdarzenia
        tm czasTM = *localtime(&czas);
        setlocale( LC_ALL, "Polish" ); //polski format czasu
        strftime(bufor, sizeof(bufor), "%c", &czasTM);

        string housefire = sd.name + sd.type;

        cout << "\n++++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++Informacja o zdarzeniu++++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++" << endl;
        cout << "\nData zgloszenia: " << bufor << endl;
        cout << "Rodzaj pozaru: " << type << endl;
        cout << "Miejscowosc zdarzenia: " << location << endl;
        cout << "Powierzchnia: " << area << endl;
        cout << "Zadymienie: " << smoke << endl;
        cout << "Ilosc potrzebnej wody: " << water << " [L] " << endl;
        cout << "Ilosc ratownikow: " << firefighters << endl;
        if(type=="Obiekty mieszkalne" || type=="Instytucje, obiekty uzytecznosci publicznej")  cout << Info + FSending + housefire << endl;
        else cout << Info + FSending << endl;
        cout << "Dostepne samochody: " << ATrucks << endl;
        FSending.clear(); //czyszczenie zmiennej globanej
        ATrucks.clear(); //czyszczenie zmiennej globalnej
        firefighters = 0; //zerowanie zmiennej globalnej typu int
    }

    void Road::setRoad()
    {
        int Type;
        int Deadlock;

        cout << "\nRodzaj zdarzenia drogowego:" << endl;
        cout << "[1].Kolizja \n[2].Wypadek\n" << endl;

        cout << "Podaj numer rodzaju zdarzenia: ";
        while(!(cin>>Type)) //sprawdzenie poprawnosci wprowadzonej zmiennej
        {
            cout << "Wprowadziles bledna wartosc!";
            cout << "\nPodaj wartosc jeszcze raz: ";
            cin.clear();
            cin.sync();
        }

        if(Type <= 0 || Type > 2) exit(0); //przerwanie dzialania programu przy spelnieniu warunku
        if(Type == 1) type = "Kolizja";
        if(Type == 2) type = "Wypadek";

        if(type=="Kolizja")
        {
            cout << "\nPodaj liczbe aut bioracych udzial w kolizji: ";

            while(!(cin>>cars)) //sprawdzenie poprawnosci wprowadzonej zmiennej
            {
                cout << "Wprowadziles bledna wartosc!";
                cout << "\nPodaj wartosc jeszcze raz: ";
                cin.clear();
                cin.sync();
            }
            if(cars<=0) exit(0); //przerwanie dzialania programu przy spelnieniu warunku

            cout << "\nPodaj liczbe osob poszkodowanych:";

            while(!(cin>>victims)) //sprawdzenie poprawnosci wprowadzonej zmiennej
            {
                cout << "Wprowadziles bledna wartosc!";
                cout << "\nPodaj wartosc jeszcze raz: ";
                cin.clear();
                cin.sync();
            }

            if(victims<0) exit(0); //przerwanie dzialania programu przy spelnieniu warunku
        }

        if(type=="Wypadek")
        {
            cout << "\nPodaj liczbe aut bioracych udzial w wypadku: ";

            while(!(cin>>cars)) //sprawdzenie poprawnosci wprowadzonej zmiennej
            {
                cout << "Wprowadziles bledna wartosc!";
                cout << "\nPodaj wartosc jeszcze raz: ";
                cin.clear();
                cin.sync();
            }
            if(cars<=0) exit(0); //przerwanie dzialania programu przy spelnieniu warunku

            cout << "\nPodaj liczbe osob poszkodowanych:";

            while(!(cin>>victims)) //sprawdzenie poprawnosci wprowadzonej zmiennej
            {
                cout << "Wprowadziles bledna wartosc!";
                cout << "\nPodaj wartosc jeszcze raz: ";
                cin.clear();
                cin.sync();
            }

            if(victims<0) exit(0); //przerwanie dzialania programu przy spelnieniu warunku

            cout << "\nCzy osoby w pojazdach sa zakleszczone?" << endl;
            cout << "[1].Tak \n[2].Nie" << endl;
            cout << "Podaj odpowiedz: ";

            while(!(cin>>Deadlock)) //sprawdzenie poprawnosci wprowadzonej zmiennej
            {
                cout << "Wprowadziles bledna wartosc!";
                cout << "\nPodaj wartosc jeszcze raz: ";
                cin.clear();
                cin.sync();
            }

            if(Deadlock == 1) deadlock = "Tak";
            if(Deadlock == 2) deadlock = "Nie";
            if(Deadlock == 0 || Deadlock > 2) exit(0); //przerwanie dzialania programu przy spelnieniu warunku
        }

    }

    void Road::setLocationRoad() //metoda sluzy do ustawienia lokalizacji wypadku lub kolizji
    {
        cout << "\nWprowadz miejscowosc wypadku: ";
        cin >> location;
    }

    void Road::getRescuersAmount() //ustawienie ilosci potrzebnych ratownikow do wypadku lub kolizji
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

    void Road::roadSending() //metoda polegajaca na wysylaniu konkretnych pojazdow na podstawie potrzebnej ilosci ratownikow
    {
        FireTrucks srt("Iveco", "SRT", 0, 2); //tworzenie obiektu pojazd specjalny techniczny potrzebny do kazdego wypadku
        roadtrucks.insert(roadtrucks.begin(),srt); //wrzucenie obiektu "srt" na pierwsze miejsce tablicy

        vector <string> roadtrucksNames;
        vector<string> availabletrucksr;

        int suma = 0;

        for(int i = 0; i < roadtrucks.size(); i++) //podobna zasada co w przypadku wysylania pojazdow do pozarow
        {
            roadtrucksNames.push_back(roadtrucks[i].getName() + " " + roadtrucks[i].getType() + " ");

            suma += roadtrucks[i].getFiremans();

            flag = i + 1;

            if(suma > rescuers)
            {
                break;
            }

        }

        for(int j = 0; j < roadtrucksNames.size(); j++) //procedura wysylania pojazdow do zdarzenia drogowego
        {
            RSending += roadtrucksNames[j];
        }

        for(int k = flag; k < roadtrucks.size(); k++) //oznaczanie dostepnych pojazdow
        {
            availabletrucksr.push_back(roadtrucks[k].getName() + " " + roadtrucks[k].getType() + " ");
        }

        for(int j = 0; j < availabletrucksr.size();j++)
        {
            ARTrucks += availabletrucksr[j];
        }

    }

    void Road::roadInformation() //metoda wyswietlajaca informacje na temat kolizji lub wypadku
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
        cout << "Dostepne samochody: " << ARTrucks << endl;
        RSending.clear(); //czyszczenie zmiennej globalnej
        ARTrucks.clear(); //czyszczenie zmiennej globalnej
    }

    void LocalWarning::setLocalWarning() //ustawienie miejscowego zagrozenia
    {
        int Type;

        cout << "\nWybierz rodzaj miejscowego zdarzenia: " << endl;

        cout << "\n[1].Powalone drzewo \n[2].Naderwany konar \n[3].Zerwana linia energetyczna \n[4].Pomoc innym sluzbom \n[5].Zagrozenie chemiczne \n[6].Pomoc w otwarciu mieszkania \n[7].Budowlane \n[8].Gniazdo owadow blonkoskrzydlych" << endl;

        cout << "\nPodaj numer rodzaju zdarzenia: ";
        while(!(cin>>Type)) //sprawdzenie poprawnosci wprowadzonej zmiennej
        {
            cout << "Wprowadziles bledna wartosc!";
            cout << "\nPodaj wartosc jeszcze raz: ";
            cin.clear();
            cin.sync();
        }

        if(Type <= 0 || Type > 8) exit(0);
        if (Type == 1) type = "Powalone drzewo";
        if (Type == 2) type = "Naderwany konar";
        if (Type == 3) type = "Zerwana linia energetyczna";
        if (Type == 4) type = "Pomoc innym sluzbom";
        if (Type == 5) type = "Zagrozenie chemiczne";
        if (Type == 6) type = "Pomoc w otwarciu mieszkania";
        if (Type == 7) type = "Budowlane";
        if (Type == 8) type = "Gniazdo owadow blonkoskrzydlych";
    }

    void LocalWarning::setLWLocation() //ustawienie lokalizacji miejscowego zagrozenia
    {
        cout << "\nWprowadz miejscowosc zdarzenia: ";
        cin >> location;
    }
    void LocalWarning::LocalWarningSending() //wysylanie pojazdow do miejscowych zagrozen bez wzgledu na kryteria, losowo
    {
        FireTrucks sd("Mercedes ", "SD", 0, 2); //tworzenie specjalnych pojzadow
        FireTrucks srchem("Volvo", "SRCHEM", 0,2);

        int vectorSize = localwarningtrucks.size();

        srand(time(NULL));

        int vechicleNumber = (rand() % vectorSize); //ustawianie zasiegu losowania pojazdow

        if (type == "Naderwany konar")
        {
            LWSending = Info + localwarningtrucks[vechicleNumber].getName() + " " + localwarningtrucks[vechicleNumber].getType() + Info2 + sd.name + sd.type;
        }
        else if(type == "Zagrozenie chemiczne")
        {
            LWSending = Info + localwarningtrucks[vechicleNumber].getName() + " " + localwarningtrucks[vechicleNumber].getType() + Info2 + srchem.name + srchem.type;
        }
        else LWSending = Info + localwarningtrucks[vechicleNumber].getName() + " " + localwarningtrucks[vechicleNumber].getType();

    }

    void LocalWarning::LocalWarningInformation() //wyswietlanie informacji na temat miejscowego zagrozenia
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