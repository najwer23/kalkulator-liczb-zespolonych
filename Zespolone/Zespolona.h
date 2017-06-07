#include <iostream>
#include <string>

using namespace std;

class Zespolona
{
    double Re;
    double Im;
    char znak;
    double modul;
    double argument;

public:
    Zespolona(double R=0, double I=0, char z='+', double r=0, double kat=0)
    {
        modul=r;
        argument=kat;
        Re=R;
        Im=I;
        znak=z;
    }
    ~Zespolona();
    void load();
    void show();
    void modul_liczby(); // modul liczby zespolonej +++++++++++
    void angle();        // kat liczby ++++++++++++++++++++++++
    friend ostream& operator<< (ostream& out ,Zespolona const&v);
    Zespolona operator *(Zespolona &a); //mnozenie LZ
    Zespolona operator /(Zespolona &a); //dzielenie
    void pierw();//pierwiastkowanie
    void potega();//potegowanie


};
