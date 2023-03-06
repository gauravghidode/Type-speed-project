#include <iostream>
#include <conio.h>
#include<bits/stdc++.h>
#include <string>
#include "sentences.cpp"
#include<sys/time.h>
#include<windows.h>
using namespace std;

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X =column;
    coord.Y= line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}


long getTime()
{
    struct timeval start;
    gettimeofday(&start,NULL);
    return start.tv_sec*1000000 + start.tv_usec;
}

int getString(string s)
{
    int ch, cnt = 0, n = s.length(), spaceCnt=0, prev=100, j=1, strokes=0;
    long start = getTime(), time;
    gotoxy(0,0);
    for (int i = 0; i < s.length(); i++)
    {
        ch = getch();
        if (ch == s[i])
        {
            cout << s[i];
            if(s[i] == ' ')
                spaceCnt++;
        }
        else
        {
            cout<<"\a";
            i--;
            if(spaceCnt!=prev)
            {
                cnt++;
                strokes++;
                prev = spaceCnt;
            }
        }
        if(s[i]==' ')
        {
            ;
            gotoxy(0,20);
           // float acc = float(spaceCnt -cnt) / (float)spaceCnt;
            float acc = float(i -strokes) / (float)i;
            cout<<"Stroke Accuracy ="<<acc * 100.0<<endl;
            time=getTime();
            cout<<"Current speed = "<<((float)spaceCnt*60)/((time-start))*1000000;
            gotoxy(0,0);
            for(int j=0;j<=i;j++)
                cout<<s[j];
        }

    }
    // cout<<"You pressed "<<cnt<<" wrong key\n";
    float acc = float(spaceCnt -cnt) / (float)spaceCnt;
    cout << "\n\n\nYou have completed the race with a accuracy of " << acc * 100.0 << endl;
    return spaceCnt;
}

int main()
{
    string st = TakeString();
    cout <<st<< endl<<endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    long start = getTime();
    int word = getString(st)+1;
    long end = getTime();

    // Calculating total time taken by the program.
    int timeTaken =(end - start)/1000000;
    cout<<"Your speed is "<<(word/(float)timeTaken)*60 <<" WPM \n";

    getch();
    return 0;
}
