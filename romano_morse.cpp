#include<iostream>
#include<string>
#include<sstream>
#include<windows.h>
// #include<stdio.h>
// #include<conio.h>
// #include<stdlib.h>
// #include<windows.h>
using namespace std;


string romano(int num) {
    int u,d,c,m;
    stringstream s;
    u=num%10; num/=10;
    d=num%10; num/=10;
    c=num%10; num/=10;
    m=num%10; num/=10;

    switch(m){
        case 1: s<<"M";break;
        case 2: s<<"MM";break;
        case 3: s<<"MMM";break;
    }

    switch(c){
        case 1: s<<"C";break;
        case 2: s<<"CC";break;
        case 3: s<<"CCC";break;
        case 4: s<<"CD";break;
        case 5: s<<"D";break;
        case 6: s<<"DC";break;
        case 7: s<<"DCC";break;
        case 8: s<<"DCCC";break;
        case 9: s<<"CM";break;
    }
    switch(d){
        case 1: s<<"X";break;
        case 2: s<<"XX";break;
        case 3: s<<"XXX";break;
        case 4: s<<"XL";break;
        case 5: s<<"L";break;
        case 6: s<<"LX";break;
        case 7: s<<"LXX";break;
        case 8: s<<"LXXX";break;
        case 9: s<<"XC";break;
    }
    switch(u){
        case 1: s<<"I";break;
        case 2: s<<"II";break;
        case 3: s<<"III";break;
        case 4: s<<"IV";break;
        case 5: s<<"V";break;
        case 6: s<<"VI";break;
        case 7: s<<"VII";break;
        case 8: s<<"VIII";break;
        case 9: s<<"IX";break;
    }
    return s.str();
}

string morse(int num) {
    stringstream s;

    return s.str();
}

int main () {
    int numero,u,d,c,m,i,j;


    // for (int i = 1; i <= 3000; i++) {
    //     cout << romano(i) << endl;
    // }

    // cout<<"Digite su numero: ";
    // cin>>numero;

    // u=numero%10; numero/=10;
    // d=numero%10; numero/=10;
    // c=numero%10; numero/=10;
    // m=numero%10; numero/=10;

    // switch(m){
    //     case 1: cout<<"M";break;
    //     case 2: cout<<"MM";break;
    //     case 3: cout<<"MMM";break;
    // }

    // switch(c){
    //     case 1: cout<<"C";break;
    //     case 2: cout<<"CC";break;
    //     case 3: cout<<"CCC";break;
    //     case 4: cout<<"CD";break;
    //     case 5: cout<<"D";break;
    //     case 6: cout<<"DC";break;
    //     case 7: cout<<"DCC";break;
    //     case 8: cout<<"DCCC";break;
    //     case 9: cout<<"CM";break;
    // }
    // switch(d){
    //     case 1: cout<<"X";break;
    //     case 2: cout<<"XX";break;
    //     case 3: cout<<"XXX";break;
    //     case 4: cout<<"XL";break;
    //     case 5: cout<<"L";break;
    //     case 6: cout<<"LX";break;
    //     case 7: cout<<"LXX";break;
    //     case 8: cout<<"LXXX";break;
    //     case 9: cout<<"XC";break;
    // }
    // switch(u){
    //     case 1: cout<<"I";break;
    //     case 2: cout<<"II";break;
    //     case 3: cout<<"III";break;
    //     case 4: cout<<"IV";break;
    //     case 5: cout<<"V";break;
    //     case 6: cout<<"VI";break;
    //     case 7: cout<<"VII";break;
    //     case 8: cout<<"VIII";break;
    //     case 9: cout<<"IX";break;
    // }


    // char l[7]={'M','C','D','X','L','V','I'};
    // string morse [7]={"--","-.-.","-..","-..-",".-..","...-",".."};
    /* 
        1= .----
        2= ..---
        3= ...--
        4= ....-
        5= .....
        6= -....
        7= --...
        8= ---..
        9= ----.
        0= -----
    */

    // char cadena[15];
    // gets(cadena);

    // for(i=0;i<cadena[i];i++);
    // for(j=0;j<15;j++);



    // if(cadena[i]==l[j]){
    //     cout<<("%l",morse[j]);
    // }
    // getch();

    cout << '\a';

    return 0;
}