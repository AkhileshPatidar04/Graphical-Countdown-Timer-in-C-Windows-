#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
struct time{
    int h;
    int m;
    int s;
    int milli;
};
void print_line(int d1,int d2,int d3,int d4,int d5,int d6 ,int d7){

    if(d1){
        
        printf("%c%c%c",223,223,223);
    }
    else {
        if(d2)printf("  ");
        else printf("%c ",221);
        if(d3)printf("%c",222);
        else printf(" ");
    }
    printf("\b\b\b\033[B");
    
    
    if(d2)printf("%c",221);
    else printf(" ");
    printf(" ");
    if(d3)printf("%c",222);
    else printf(" ");
         

    printf("\033[B\b\b\b");
    if(d4){
        printf("%c%c%c",220,220,220);
    }
    else printf("   ");
    printf("\033[B\b\b\b");
         

    if(d5)printf("%c",221);
    else printf(" ");
    printf(" ");
    if(d6)printf("%c",222);
    else printf(" ");
    printf("\033[B\b\b\b");
         

    if(d7){
        printf("%c%c%c",220,220,220);
    }
    else {
        if(d5)printf("  ");
        else printf("%c ",221);
        if(d6)printf("%c",222);
        else printf(" ");
    }

    printf("\033[4A");
    return;
    
}
void print_x(){
    printf(" \033[B%c\033[2B\b%c\033[3A ",254,254);
}
void print_d(int d){
    switch(d){
        case 0:print_line(1,1,1,0,1,1,1);break;
        case 1:print_line(0,0,1,0,0,1,0);break;
        case 2:print_line(1,0,1,1,1,0,1); break;
        case 3:print_line(1,0,1,1,0,1,1); break;
        case 4:print_line(0,1,1,1,0,1,0); break;
        case 5:print_line(1,1,0,1,0,1,1);break;
        case 6:print_line(1,1,0,1,1,1,1);break;
        case 7:print_line(1,0,1,0,0,1,0);break;
        case 8:print_line(1,1,1,1,1,1,1); break;
        case 9:print_line(1,1,1,1,0,1,1);break;

    }
    return;
}
void print_time(struct time *t){
    for(int j=0;j<5;j++){
    for(int i=0;i<30;i++){
        printf(" ");
    }
    printf("\033[B\033[30D");
    }
    printf("\033[5A");
    print_d(t->m/10);printf("  ");print_d(t->m%10);print_x();
    print_d(t->s/10);printf("  ");print_d(t->s%10);print_x();
    print_d(t->milli/10);printf("  ");print_d(t->milli%10);
    printf("\033[30D");
    
} 
void minus_milli(struct time* t){
    if(t->milli) t->milli--;
    else {
        t->milli=99;
        if(t->s) t->s--;
        else {
            t->s=59;
            if(t->m) t->m--;
            else {
                t->m=59;
                if(t->h) t->h--;
                else return;
            }
            }
        }
        return;
}
void timer(struct time *t1){
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
    while(t1->h||t1->m||t1->s||t1-> milli){
            print_time(t1);
            Sleep(10); // Fixed: changed from Sleep(0) to Sleep(10)
            minus_milli(t1);

    }
    print_time(t1);
    
    
    return;

}
int main(){
    struct time*  t=(struct time*)malloc(sizeof( struct time));
    t->h=0;
    for(int i=0;i<6;i++)
    printf("\tTimer\t");
    printf("\nEnter  Minutes  ");
    scanf("%d",&t->m);
    printf("\nEnter seconds ");
    scanf("%d",&t->s);
    t->milli=0;
    timer(t);
    for(int i=0;i<10;i++){
        Beep(1000,10);
        Sleep(10);
    }
    free(t);
    return 0;
}
