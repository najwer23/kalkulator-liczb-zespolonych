#include <iostream>
#include "Zespolona.h"
#include <string>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <iomanip>


using namespace std;
void Zespolona :: potega()
{
    cout<<" Podaj wykladnik LZ"<<endl;
    cout<<" --> ";
    int n;
    cin>>n;

    Zespolona z;
    double k=(double)n;
    double cosi; //reprezentacja cossiunsa LZ
    double sini; // reprezentacja sinusa LZ
    double moduli = pow(modul,(k)); // pierwiastek z modul liczby LZ stopnia n

        cosi=cos(argument*n);
        sini=sin(argument*n);

        z.Re=moduli*cosi;
        z.Im=moduli*sini;

        cout<<" "<<setprecision(4)<<fixed<<z<<endl;
}

/////////////////////////////// 9
void Zespolona :: pierw()
{
    cout<<" Podaj stopien pierwiastka"<<endl;
    cout<<" --> ";
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<" Pierwiastek zerowego stopnia?"<<endl;
    }
    else
    {
        double k=1/(double)n; //wazne rzutowanie 2godz szukania bledu
        double cosi[n]; //reprezentacja cossiunsa LZ
        double sini[n]; // reprezentacja sinusa LZ
        double moduli = pow(modul,(k)); // pierwiastek z modul liczby LZ stopnia n

        //ustawienia liczb Re i Im
        for(int i=0;i<n;i++)
        {
        cosi[i]=cos((argument+(2*i*M_PI))/n);
        sini[i]=sin((argument+(2*i*M_PI))/n);
        }

        Zespolona z[n];
        //wczytaj skladowe do LZ
        for(int j=0;j<n;j++)
        {
            z[j].Re=moduli*cosi[j];
            z[j].Im=moduli*sini[j];
        }

        //wypisz na ekran nasze liczby LZ
        for(int k=0;k<n;k++)
        {
            cout<<k+1<<". "<<setprecision(4)<<fixed<<z[k]<<endl;
        }
    }
}


//////////////////////////////// 8
Zespolona Zespolona :: operator /(Zespolona &a)
{
    Zespolona c;
    if(a.znak=='-')
    {
        a.Im=-a.Im; // tu kiedy zrobie funkcje
    }

    if(znak=='-')
    {
        Im=-Im;
    }

    if(a.Re==0&&a.Im==0)
    {
        cout<<" Dzielenie przez 0!"<<endl;
    }
    else
    {
        c.Re=(Re*a.Re+Im*a.Im)/(a.Im*a.Im+a.Re*a.Re);
        c.Im=(Im*a.Re-Re*a.Im)/(a.Im*a.Im+a.Re*a.Re);

    }
    return c;
}

////////////////////////////// 7
Zespolona Zespolona :: operator *(Zespolona &a)
{
    Zespolona c;
    if(a.znak=='-')
    {
        a.Im=-a.Im; // tu kiedys zrobie funkcje
    }
    if(znak=='-')
    {
        Im=-Im;
    }
    c.Re=a.Re*Re-a.Im*Im;
    c.Im=a.Re*Im+Re*a.Im;
    return c;
}


///////////////////////////// 6
 ostream & operator << (ostream &out, Zespolona const&v)
    {
        cout.setf(ios_base::showpos);
        out <<" "<< v.Re << v.Im <<"i"<<endl;
        cout.unsetf(ios_base::showpos);
        return out;
    }


///////////////////////////// 5
void Zespolona :: angle()
{
    if(znak=='-')
    {
        Im=-Im;
    }
    argument=atan(Im/Re);

    if(Re<0)
    {
        argument=argument+M_PI;
    }

}

///////////////////////////// 4
void Zespolona :: modul_liczby()
{
    //modul
    modul=sqrt((Re*Re)+(Im*Im));
}

///////////////////////////// 3
Zespolona::~Zespolona()
{}

///////////////////////////// 2
void Zespolona :: show()
{
    cout<<endl<<" Odczytana liczba          : ";
    cout<<Re;
    if(Im<0)
    {cout<<Im;}
    else
    {cout<<znak<<Im;}
    cout<<"i"<<endl;
    cout<<" Modul LZ                  : "<<setprecision(4)<<fixed<<modul<<endl;
    cout<<" Argument LZ (radiany)     : "<<argument<<" rad"<<endl;
    cout<<" Argument LZ (stopnie)     : "<<fixed<<argument*180/M_PI<<" deg"<<endl;
    cout<<" Postac Trygonometryczna   : "<<fixed<<modul<<"("<<cos(argument);
    cout.setf(ios_base::showpos);
    cout<<sin(argument)<<"i) == "<<modul*cos(argument)<<" "<<modul*sin(argument)<<"i"<<endl;
    cout.unsetf(ios_base::showpos);
    cout<<" Postac Wykladnicza        : "<<modul<<"exp("<<argument<<"i)"<<endl;

}

///////////////////////////// 1
 void Zespolona :: load()
{

    double R=0;
    double I=0;
    char ju;
    int a=1;
    while(a==1)
    {
    cout<<" Podaj liczbe zespolona:"<<endl;
    cout<<" --> ";
    cin>>R;
    if(!cin)
    {
        cout<<" Blad skladni :("<<endl;
        cin.clear(); // czyœcimy flagi b³êdu strumienia
        cin.sync(); // czyœcimy bufor strumienia
        a=1;
        continue;
    }
    else
    {
        a=2;
    }
    cin>>znak;
    if(znak!='-'&&znak!='+')
    {
        cout<<" Zly symbol arytmetyczny :("<<endl;
        cin.clear(); // czyœcimy flagi b³êdu strumienia
        cin.sync(); // czyœcimy bufor strumienia
        a=1;
        continue;
    }
     else
    {
        a=2;
    }

    cin>>I;
    if(!cin)
    {
        cout<<" Blad skladni :("<<endl;
        cin.clear(); // czyœcimy flagi b³êdu strumienia
        cin.sync(); // czyœcimy bufor strumienia
        a=1;
        continue;
    }
     else
    {
        a=2;
    }
    cin>>ju;
    if(ju!='j'&&ju!='i')
    {
        cout<<" Zla jednostka urojona :("<<endl;
        cin.clear(); // czyœcimy flagi b³êdu strumienia
        cin.sync(); // czyœcimy bufor strumienia
        a=1;
        continue;
    }
     else
    {
        a=2;
    }
    }
///////////////////////////////////////

    if(R==0&&I!=0)
    {
        Re=0;
        Im=I;
    }

    if(I==0&&R!=0)
    {
        Re=R;
        Im=I;
    }

    if(I!=0&&R!=0)
    {
        Re=R;
        Im=I;
    }

}
