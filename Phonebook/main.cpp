#include<time.h>
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<stdio.h>

#define MAX 100

using namespace std;
//================================
void GotoXY(int x, int y){
    HANDLE hconsoleOutput;
    COORD dwCursorPosition;

    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hconsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hconsoleOutput, dwCursorPosition);
}
//==================================
void ClrScr(){
    system("cls");
}
//===================================
string GetTime(){
    char timeStr[9];
    _strtime(timeStr);
    string time = timeStr;
    return time;
}
//====================================
string GetDate(){
    char datestr[9];
    _strdate(datestr);
    string date = datestr;
    date.insert(6, "20");
    return date;
}
//======================================
//======================================
struct tamrin{
    long long int shomare;
    char name[100];
    int rank;
    string tarikh_ijad;
    string tarikhiIjad;
}tm_info[MAX];

//=========================================
int menuSelect(void){
    char s[10];
    int c;
    ClrScr();
    GotoXY(29, 3);
    cout << "1)  << ezafe kardane mokhateb >>";
    GotoXY(29, 5);
    cout << "2)  << hazfe mokhateb>>";
    GotoXY(29, 7);
    cout << "3)  << Serch mokhateb >>";
    GotoXY(29, 9);
    cout << "4)  << Edit mokhateb >>";
    GotoXY(29, 11);
    cout << "5)  << Show All phon number >>";
    GotoXY(29, 13);
    cout << "6) << exit >>";
    do{
        GotoXY(31, 15);
        cout << "plese enter your choice(1-7): ";
        gets(s);
        c = atoi(s);
    } while (c<0 || c>7);
    return c;
}
//===========================================
int findFree(void){
    int t;
    for (t = 0; tm_info[t].name[0] && t < MAX; ++t);
    if (t == MAX) return -1;
    else
        return t;
}
//===========================================
int findFree2(void){
    int a;
    for (a = 0; tm_info[a].shomare && a < MAX; ++a);
    if (a== MAX) return -1;
    return a;
}
//============================================
void enter(void){
    char a[10], b;
    int slot, slot2, slot3,slot4,slot5,slot6;
    slot = findFree();
    slot2 = findFree2();
    if (slot == -1){
        cout << "\nlist full";
        return;
    }
    GotoXY(5, 17);
    cout << "enter name : ";
    gets(tm_info[slot].name);
    GotoXY(5, 19);
    cout << "enter number : ";
    cin >> (tm_info[slot2].shomare);
    GotoXY(5, 21);
    cout<<"enter rank: ";
    cin >> (tm_info[slot].rank);
    tm_info[slot2].tarikh_ijad=GetTime();
    tm_info[slot2].tarikhiIjad = GetDate();

}
//===============================================
void  numberSearch() {
    int a, n, i;
    int slot;
    cout << "please enter number for search: ";
    cin >> n;
    for (i = 0; i < MAX; i++){
        a = tm_info[i].shomare;
        if (n==a)  {
            cout << tm_info[i].shomare;
            cout << "\n" << tm_info[i].name;
            cout << "\n" << tm_info[i].tarikhiIjad;
        }

    }
    _getch();
}
//=============================================
void  nameSearch(void) {
    char ch;
    char name[100];
    GotoXY(5, 17);
    cout << "enter name: ";
    getchar();
    cin.getline(name, 99);
    do{
        cout << "do you want to continue(y,n)? ";

        cin >> ch;
        if (ch == 'y'){
            int j = 0;
            for (int i = 0; i<MAX; i++){
                if (strcmp(name, tm_info[i].name) == 0){
                    cout << "rank: " << tm_info[i].rank;
                    cout <<"\nname: "<< tm_info[i].name;
                    cout<<"\nnumber: "<<tm_info[i].shomare ;
                    j++;
                }
            }
        }
        else if (ch == 'n')
            cout << "\nyour practice do not delete  ";
        _getch();
    } while (ch != 'y'&& ch != 'n');
}
//====================================================
void deleteE(void){
    char ch;
    char name[100];
    GotoXY(5, 17);
    cout << "enter name: ";
    cin.getline(name,99);
    do{

        for (int i = 0; i<MAX; i++){
            if (strcmp(name, tm_info[i].name) == 0){
                cout<<"name: "<<tm_info[i].name ;
                cout<<"\n"<<"number: "<<tm_info[i].shomare;

            }
        }
        cout << "\ndo you want to continue(y,n)? ";
        cin >> ch;
        if(ch=='y'){
            int j = 0;
            for(int i=0;i<MAX;i++){
                if (strcmp(name,tm_info[i].name)==0){
                    tm_info[i].name[j]=NULL;
                    tm_info[i].shomare = 0;
                    j++;
                }
            }
        }
        else if(ch=='n')
            cout<<"\nyour practice do not delete  ";
        _getch();
    } while (ch != 'y'&& ch != 'n');
}
//===========================================
int menuJost(void){
    char s[2];
    int d;
    ClrScr();
    GotoXY(29, 3);
    cout << "1)  << search to number >>";
    GotoXY(29, 5);
    cout << "2)  << search to name  >>";
    GotoXY(29, 7);
    cout<<"3)  <<  exit  >>";
    do{
        GotoXY(31, 13);
        cout << "plese enter your choice(1-3): ";
        cin >> s;
        d = atoi(s);
    } while (d<1 || d>3);
    _getch();
    return d;
}
//==============================================
void listAll(){
    int  r = 0;
    ClrScr();
    GotoXY(25, 2);
    cout<< "<<  all information in list are:  >>";
    GotoXY(13, 3);
    cout << "**************************";
    cout << "********************";
    cout << "************************";
    GotoXY(10, 4);

    for (int i = 0; i < MAX; i++){
        cout << "\n" << "number: " << tm_info[i].shomare;
        cout << "\n" << "name practice:" << tm_info[i].name;
        cout << " _ " << tm_info[i].tarikhiIjad;
        cout << " _ " << tm_info[i].tarikh_ijad;
        if (tm_info[i].shomare == 0){
            break;
        }
    }
    _getch();
}
//===============================================
void vira(void){
    int c;
    cout << "please enter rank for edit: ";
    cin >> c;
    ClrScr();
    for (int i = 0; i<MAX; i++){
        if (tm_info[i].rank == c){
            tm_info[i].name[0] = NULL;
            cout << "name mokhatab: ";
            cin >> tm_info[i].name;
        }
    }
}
//========================================================
void vira_num(void){
    int c;
    char ch;
    char name[100];
    GotoXY(5, 17);
    cout << "enter name: ";
    cin.getline(name,99);
    do{
        cout << "do you want to continue(y,n)? ";
        cin >> ch;
        if(ch=='y'){
            for(int i=0;i<MAX;i++){
                if (strcmp(name,tm_info[i].name)==0){
                    tm_info[i].shomare=NULL;
                    cout<<"new number: ";
                    cin>>tm_info[i].shomare;

                }
            }
        }
        else if(ch=='n')
            cout<<"\nyour practice do not delete  ";
        _getch();
    } while (ch != 'y'&& ch != 'n');
}

//=========================================================
int menuVira(void){
    char s[10];
    int c;
    ClrScr();
    GotoXY(29, 3);
    cout << "1)  << edit name >>";
    GotoXY(29, 5);
    cout << "2)  << edit number >>";
    GotoXY(29, 7);
    cout << "3)  << exit  >>";

    do{
        GotoXY(31, 7);
        cout << "plese enter your choice(1-3): ";
        gets(s);
        c = atoi(s);
    } while (c<1 || c>3);
    return c;
}
//=============================================
void  selectionSort() {
    for (int i = 0; i < MAX; i++){
        for (int j = i + 1; j<MAX; j++){
            if (tm_info[i].rank > tm_info[j].rank){

                swap(tm_info[i].shomare, tm_info[j].shomare);
                swap(tm_info[i].rank, tm_info[j].rank);
                swap(tm_info[i].name, tm_info[j].name);
                swap(tm_info[i].tarikh_ijad, tm_info[j].tarikh_ijad);
                swap(tm_info[i].tarikhiIjad, tm_info[j].tarikhiIjad);
            }
        }
    }

    int t, r = 0;
    char ch;
    ClrScr();
    GotoXY(25,2);
    cout << "<<  all information in list are  >>";
    GotoXY(13, 3);
    cout << "**************************";
    cout << "****************************";
    cout << "****************************";
    GotoXY(10, 4);
    cout << "	rank	  name	   number		 time		    date	   ";
    GotoXY(10, 5);
    cout << "	_____	  _____	   ______		_______		____________";
    for (t = 0; t < MAX; ++t){
        if (tm_info[t].name){
            GotoXY(17, 6 + r);
            cout << tm_info[t].rank;
            GotoXY(25, 6 + r);
            cout << tm_info[t].name;
            GotoXY(34, 6 + r);
            cout << tm_info[t].shomare;
            if (tm_info[t].shomare == 0){
                continue;
            }
            GotoXY(56, 6 + r);
            cout << tm_info[t].tarikh_ijad;
            GotoXY(73, 6 + r);
            cout << tm_info[t].tarikhiIjad;
            r++;
        }
    }
    GotoXY(13, 6 + r);
    cout << "*********************************";
    cout << "********************************";
    cout << "**********************";
    GotoXY(27, 7 + r);
    cout << "press any key to continue! ";
    _getch();
}
//============================================================

int main(){
    char choice, ch, kh, z, c, j, k;
    int i;
    ClrScr();
    for (;;){
        choice = menuSelect();

        switch (choice){
            case 1:
                ClrScr();
                enter();
                break;
            case 2:
                ClrScr();
                deleteE();
                break;
            case 3:
                z = menuJost();
                switch (z){
                    case 1:
                        ClrScr();
                        numberSearch();
                        break;
                    case 2:
                        ClrScr();
                        nameSearch();
                        break;
                    case 3:
                        ClrScr();

                        break;
                    case 4:
                        ClrScr();

                        break;
                    case 5:

                        break;
                }
                break;
            case 4:
                ClrScr();
                c = menuVira();
                switch (c){
                    case 1:
                        ClrScr();
                        vira();
                        break;
                    case 2:
                        ClrScr();
                        vira_num();
                        break;
                }
                break;
            case 5:
                ClrScr();
                selectionSort();
                break;
            case 6:
                exit(0); break;

        }
    }
    _getch();
    return 0;
}
