//
// Created by Roman on 23.12.2022.
//
#include "lab8 1.h"
void remove(long long &n ,long long x ){
    for(long long i=x+1;i<=n;i++){
        strcpy(hu[i-1].name,hu[i].name);
        strcpy(hu[i-1].surname,hu[i].surname);
        strcpy(hu[i-1].midname,hu[i].midname);
        strcpy(hu[i-1].adress,hu[i].adress);
        hu[i-1].dis=hu[i].dis;
    }
    n--;
}
void removebynum(long long n){
    printf("enter num of client\n");
    long long k = 0;
    chk(&k);
    while(k<1||k>n){
        printf("incorrect input, try again\n");
        chk(&k);

    }
    remove(n,k);
}
void removebyname(long long n, char name[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(name,hu[i].name)==0){
            remove(n,i--);
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
void removebysurname(long long n , char surname[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(surname,hu[i].surname)==0){
            remove(n,i--);
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
void removebymidname(long long n , char midname[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(midname,hu[i].midname)==0){
            remove(n,i--);
            tmp++;
        }
    }
    if(tmp==0){
        printf("no way\n");
    }
    else {
        printf("Changed %lld fields\n", tmp);
    }
}
void removebyadress(long long n , char adress[50]){
    long long tmp=0;
    for(long long i =1;i<=n;i++){
        if(strcmp(adress,hu[i].adress)==0){
            remove(n,i--);
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
void removebydiscount(long long n , long long x){
    long long tmp = 0;
    for(long long i = 1 ; i<=n;i++){
        if(x = hu[i].dis){
            remove(n,i--);
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
void chooseremove(long long n ){
    printf("/////////////////////////////\n"
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
            removebynum( n);
            break;
        }
        case(2):{
            char tmp[50];
            printf("Name: \n");
            scanf("%s",tmp);
            removebyname(n , tmp);
            break;
        }
        case(3):{
            char tmp[50];
            printf("Surname: \n");
            scanf("%s",tmp);
            removebysurname( n , tmp);
            break;
        }
        case(4):{
            char tmp[50];
            printf("Midname: \n");
            scanf("%s",tmp);
            removebymidname(n , tmp);
            break;
        }
        case(5):{
            char tmp[50];
            printf("Adress: \n");
            scanf("%s",tmp);
            removebyadress( n , tmp);
            break;
        }
        case(6):{
            long long j ;

            printf("Discount: \n");
            chk(&j);
            removebydiscount( n , j);
            break;
        }
        default:{
            printf("wrong input\n");
            break;
        }
    }


}