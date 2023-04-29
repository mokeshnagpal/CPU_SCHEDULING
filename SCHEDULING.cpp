#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
struct Semaphore
{
    int value;
};
struct st
{
    int d;
    struct st *l;
}*start,*s;
class process
{
    int p;
    int bt;
    int a;
    int id;
    int ct;
    int tat;
    int wt;
public :
    process()
    {
        p=0;
        bt=0;
        a=0;
        id=0;
        ct=0;
        tat=0;
        wt=0;
    }
    ~process()
    {
    }
    void schedule();
    void disp();
    void ins(int);
    void del();
};
class cs:public process
{
    public :
    cs()
    {
    }
    void up(struct Semaphore &);
    int down(struct Semaphore &);
    ~cs()
    {
    }
};
void cs::up(Semaphore &S)
{
    if(S.value==0)
    {
        S.value=1;

    }
}
int cs::down(Semaphore &S)
{
    if(S.value==0)
    {
        S.value=1;
    }
    return S.value;
}

void process::ins(int item)
{
    struct st *tmp;
    tmp=(struct st*)malloc(sizeof(struct st));
    tmp->d=item;
    tmp->l=NULL;
    if(start==NULL)
    {
        start=tmp;
        s=tmp;
        return;
    }
    if(s->l!=NULL)
        s=s->l;
    s->l=tmp;
}
void process::del()
{
    struct st *tmp;
    if(start==NULL)
    {
        return;
    }
    if(start->l==NULL)
    {
        free(start);
        s=NULL;
        start=NULL;
        return;
    }
    tmp=start;
    start=start->l;
    free(tmp);
}
void process::disp()
{
    int i=0;
    struct st *tmp=start;
    if(start==NULL)
    {
        cout<<"NULL"<<endl;
        Sleep(1000);
    }
    else
    {
        while(tmp!=NULL)
        {
            Sleep(1000);
            cout<<tmp->d<<endl;
            tmp=tmp->l;
        }
    }
}
void process::schedule()
{
    int pr=0,t=0,k=0,j=0,ta=0;
    cs ob;
    Semaphore S;
    double w=0.0;
    cout<<"NON-PREMPTIVE CPU Scheduling and Critical section:"<<endl<<endl;
    cout<<"Input number of processes arriving in the ready queue"<<endl;
    cin>>pr;
    process z[pr],y[pr];
    system("cls");
    cout<<"1 - First Come First Served (F.C.F.S)"<<endl;
    cout<<"2 - Shortest Job First (S.J.F)"<<endl;
    cout<<"3 - Priority Scheduling "<<endl;
    cout<<"Choosing from above"<<endl;
    cout<<"Input the number for the type of scheduling the CPU is using "<<endl;
    cin>>t;
    cout<<t;
    system("cls");
    for(int i=0;i<pr;i++)
    {
        cout<<"Let first process be P0,"<<endl;
        cout<<"Input the arrival time of P"<<i<<" ="<<endl;
        cin>>z[i].a;
        cout<<"Input the burst time of P"<<i<<" ="<<endl;
        cin>>z[i].bt;
        if(t==3)
        {
        cout<<"Input the priority of P"<<i<<" ="<<endl;
        cin>>z[i].p;
        }
        z[i].id=i;
        system("cls");
    }
    system("cls");
    if(t==1)
    {
    for(int i=0;i<pr-1;i++)
    {
        for(int j=0;j<pr-1-i;j++)
        {
            if(z[i].a>z[i+1].a)
            {
                ta=z[i].a;
                z[i].a=z[i+1].a;
                z[i+1].a=ta;
                ta=z[i].bt;
                z[i].bt=z[i+1].bt;
                z[i+1].bt=ta;
                ta=z[i].p;
                z[i].p=z[i+1].p;
                z[i+1].p=ta;
                ta=z[i].id;
                z[i].id=z[i+1].id;
                z[i+1].id=ta;
            }
        }
    }
    }
    else if(t==2)
    {
    for(int i=0;i<pr-1;i++)
    {
        for(int j=0;j<pr-1-i;j++)
        {
            if(z[i].bt>z[i+1].bt)
            {
                ta=z[i].a;
                z[i].a=z[i+1].a;
                z[i+1].a=ta;
                ta=z[i].bt;
                z[i].bt=z[i+1].bt;
                z[i+1].bt=ta;
                ta=z[i].p;
                z[i].p=z[i+1].p;
                z[i+1].p=ta;
                ta=z[i].id;
                z[i].id=z[i+1].id;
                z[i+1].id=ta;
            }
        }
    }
    }
    else if(t==3)
    {
    for(int i=0;i<pr-1;i++)
    {
        for(int j=0;j<pr-1-i;j++)
        {
            if(z[i].p>z[i+1].p)
            {
                ta=z[i].a;
                z[i].a=z[i+1].a;
                z[i+1].a=ta;
                ta=z[i].bt;
                z[i].bt=z[i+1].bt;
                z[i+1].bt=ta;
                ta=z[i].p;
                z[i].p=z[i+1].p;
                z[i+1].p=ta;
                ta=z[i].id;
                z[i].id=z[i+1].id;
                z[i+1].id=ta;
            }
        }
    }
    }
    else
    {
        cout<<"Wrong input !!!"<<endl<<"Please try again."<<endl;
        exit(0);
    }
    cout<<"Scheduling table -"<<endl;
    z[0].ct=z[0].bt+z[0].a;
    z[0].tat=z[0].ct-z[0].a;
    z[0].wt=z[0].tat-z[0].bt;
    w=z[0].wt;
    cout<<"\tProcess No.\t|\tArrival time\t|\tBurst Time\t|\tPriority Time\t|\tCompletion Time\t|\tTurnaround Time\t|\tWaiting Time "<<endl;
    cout<<"\t"<<z[0].id<<"\t\t|\t"<<z[0].a<<"\t\t|\t"<<z[0].bt<<"\t\t|\t"<<z[0].p<<"\t\t|\t"<<z[0].ct<<"\t\t|\t"<<z[0].tat<<"\t\t|\t"<<z[0].wt<<endl;
    for(int i=1;i<pr;i++)
    {
        if(z[i-1].ct<z[i].a)
            z[i].ct=z[i].a+z[i].bt;
        else
            z[i].ct=z[i-1].ct+z[i].bt;
        z[i].tat=z[i].ct-z[i].a;
        z[i].wt=z[i].tat-z[i].bt;
        w+=z[i].wt;
        if(z[i].ct==0&&t!=4)
            cout<<"\t"<<z[i].id<<"\t|\t"<<z[i].a<<"\t\t|\t"<<z[i].bt<<"\t\t|\t"<<z[i].p<<endl;
        else
            cout<<"\t"<<z[i].id<<"\t\t|\t"<<z[i].a<<"\t\t|\t"<<z[i].bt<<"\t\t|\t"<<z[i].p<<"\t\t|\t"<<z[i].ct<<"\t\t|\t"<<z[i].tat<<"\t\t|\t"<<z[i].wt<<endl;
    }
    w=w/pr;
    cout<<endl<<endl<<"Average waiting time = "<<w;
    cout<<endl<<endl<<"Please press a key to continue "<<endl;
    getch();
    system("cls");
    for(int i=0;i<pr;i++)
    {
        k=i+1;
            cout<<"Process "<<z[i].id<<" arrived at "<<z[i].a<<" second(s)"<<endl;
            cout<<endl<<endl<<"Suspended List -"<<endl;
            while(z[k].a<z[i].ct&&k<pr)
            {
                ob.ins(z[k].id);
                j=ob.down(S);
                k++;
            }
            disp();
            Sleep(1000);
            cout<<endl<<endl<<"Process "<<z[i].id<<" ended "<<endl<<endl;
            ob.up(S);
            ob.del();
            Sleep(5000);
            if(1+i!=pr)
            {
            cout<<"Next Process is grabbed from the Suspended list"<<endl<<endl;
            Sleep(5000);
            }
            else
                cout<<"CPU IS IDLE"<<endl;
            system("cls");
    }
}
int main()
{
    process obj;
    obj.schedule();
    return 0;
}
