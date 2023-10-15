//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
void change(long long i ){
    printf("Name: ");
    scanf("%s",&(hu[i].name));
    printf("Surname: ");
    scanf("%s",&(hu[i].surname));
    printf("Midname: ");
    scanf("%s",&(hu[i].midname));
    printf("Adress: ");
    scanf("%s",&(hu[i].adress));
    printf("Discount: ");
    chk(&hu[i].dis);
}
void changebynum(long long n){
    printf("enter num of client\n");
    long long i =0;
    chk(&i);
    while(i<1||i>n){
        printf("Incorrect input, try again\n");
        chk(&i);
    }
    change(i);
}
void changebyname(long long n, char name[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(name,hu[i].name)==0){
            change(i);
            tmp++;
        }
    }
    if(tmp==0){
        printf("no way\n");
    }
    else{
        printf("Changed %lld fields",tmp);
    }



}
void changebysurname(long long n , char surname[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(surname,hu[i].surname)==0){
            change(i);
            tmp++;
        }
    }
    if(tmp==0){
        printf("no way\n");
    }
    else{
        printf("Changed %lld fields\n",tmp);
    }

}
void changebymidname(long long n , char midname[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(midname,hu[i].midname)==0){
            change(i);
            tmp++;
        }
    }
    if(tmp==0){
        printf("no way\n");
    }
    else{
        printf("Changed %lld fields",tmp);
    }


}
void changebyadress(long long n , char adress[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(adress,hu[i].adress)==0){
            change(i);
            tmp++;
        }
    }
    if(tmp==0){
        printf("no way\n");
    }
    else{
        printf("Changed %lld fields",tmp);
    }


}
void changebydiscount(long long n , long long dis){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if( dis==hu[i].dis){
            change(i);
            tmp++;
        }
    }
    if(tmp==0){
        printf("no way\n");
    }
    else{
        printf("Changed %lld fields",tmp);
    }
}
void chooseedit(long long n){
    printf("///////////////////////////////////////\n"
           "1 - if you know num of client\n"
           "2- if you know name of a client\n"
           "3- if you know surname of a client\n"
           "4- if you know midname of a client\n"
           "5- if you know adress of a client\n"
           "6- if you know discount of a client\n"

    );
    long long i =0;
    chk(&i);
    while(i<1||i>6){
        printf("Incorrect input, try again\n");
        chk(&i);
    }
    switch(i){
        case(1):{
            changebynum( n);
            break;
        }
        case(2):{
            char tmp[50];
            printf("Name: \n");
            scanf("%s",tmp);
            changebyname(n , tmp);
            break;
        }
        case(3):{
            char tmp[50];
            printf("Surname: \n");
            scanf("%s",tmp);
            changebysurname( n , tmp);
            break;
        }
        case(4):{
            char tmp[50];
            printf("Midname: \n");
            scanf("%s",tmp);
            changebymidname(n , tmp);
            break;
        }
        case(5):{
            char tmp[50];
            printf("Adress: \n");
            scanf("%s",tmp);
            changebyadress( n , tmp);
            break;
        }
        case(6):{
            long long j ;

            printf("Discount: \n");
            chk(&j);
            changebydiscount( n , j);
            break;
        }
        default:{
            printf("wrong input\n");
            break;
        }
    }
}