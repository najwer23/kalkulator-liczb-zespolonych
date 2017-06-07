#include <iostream>
#include <string>
#include <windows.h>
#include "Zespolona.h"

using namespace std;

void menu()
{
    cout<<endl<<" Menu - Liczby Zespolone"<<endl;
    cout<<" p --- Pokaz Menu."<<endl;
    cout<<" z --- LZ - polimorfizm."<<endl;
    cout<<" m --- Mnozenie 2 LZ."<<endl;
    cout<<" d --- Dzielenie 2 LZ."<<endl;
    cout<<" s --- Pierwiastek n-tego stopnia LZ."<<endl;
    cout<<" a --- Potega n-tego stopnia LZ."<<endl;
    cout<<" k --- Koniec \"Liczby Zespolone\"."<<endl<<endl;
    cout<<"  >> ";
}

int main()
{
    Zespolona Z;
    Zespolona A;
    Zespolona B;
    Zespolona C;
    char pytanie='p';    //pytanie do menu
    while(pytanie!='k')
    {
        switch(pytanie)
        {
            case 'p' :  {
                        system("cls");
                        menu();
                        cin>>pytanie;
                        break;
                        }


             case 'a' : {
                        cin.sync();
                        Z.load();
                        Z.modul_liczby();
                        Z.angle();
                        Z.potega();
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }

            case 's' :  {
                        cin.sync();
                        Z.load();
                        Z.modul_liczby();
                        Z.angle();
                        Z.pierw();
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }

            case 'z' :  {
                        cin.sync();
                        Zespolona Z;
                        Z.load();
                        Z.modul_liczby();
                        Z.angle();
                        Z.show();
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }

            case 'm' :  {
                        cout<<" Mnozenie dwoch liczb zespolonych"<<endl<<endl;
                        cin.sync();
                        A.load();
                        B.load();
                        C=A*B;
                        cout<<endl<<" Wynik:"<<C;
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }

            case 'd' :  {
                        cout<<" Dzielenie dwoch liczb zespolonych"<<endl;
                        cin.sync();
                        A.load();
                        B.load();
                        C=A/B;
                        cout<<endl<<" Wynik:"<<C<<endl;
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;

                        }

            default  :  {
                        cin.ignore(100,'\n'); // gdy napotka spacje przestanie ignorowac
                        cout<<" Bledny znak. Sprobuj ponownie."<<endl;
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }
        }
    }
    cout<<" Koniec pracy programu \"Liczby Zespolone\""<<endl<<endl;
    system("pause");

    return 0;
}
