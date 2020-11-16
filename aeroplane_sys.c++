#include<bits/stdc++.h>
using namespace std;
int check_flight(string op){
    fstream faa;
    faa.open("schu_data.txt");
    string qw;
    int flag=0;
    while(faa){
        getline(faa,qw);
        if(qw==op){
            flag=1;
            break;
        }
    }
    if(flag==1){
        return 0;
    }
    else
    {
        return 1;
    }
    
    faa.close();
}
class management{
    int n,m,j,k;
    string no,a,b;
    public:
    void delay_alt();
    void record();
    void add();
};
void management::add(){
    int dda,mma;
    cout<<"enter date and month: ";
    cin>>dda>>mma;
    string sa;
    stringstream qs;
    int i=6;
    while(1){
    i++;
    qs<<dda<<"/"<<mma<<"-"<<i;
    qs>>sa;
    if(check_flight(sa)==1){
        break;
    }
    }
    string yu,uy,tyu;
    cout<<"enter takeoff point and landing point: ";
    cin>>yu>>uy;
    cout<<"enter time of departure: ";
    cin>>tyu;
    fstream qyu;
    qyu.open("schu_data.txt",ios::app);
    qyu<<sa<<endl<<yu<<" to "<<uy<<endl<<tyu<<endl;
    cout<<"new flight added successfully. flight number:-"<<sa<<endl;
    qyu.close();
}
void management::delay_alt(){

    string msg;
    incrrr:
    cout<<"enter flight number to add delay or any other alert";
    cin>>no;
    if(check_flight(no)==1){
        cout<<"flight not found\n";
        goto incrrr;
    }
    else{
        cout<<"enter message\n";
        cin.ignore();
        getline(cin,msg);
    }
    fstream vb;
    vb.open("alert.txt",ios::app);
    vb<<no<<endl<<msg<<endl;   
    vb.close(); 
}
void management::record(){
    cout<<"\n1.search record by name\n2.search flight record\n\n";
    cin>>n;
    fstream qp,re;
    string gv,vg,po,xzx;
    switch(n){
        case 1:
        cout<<"enter name: ";
        cin.ignore();
        getline(cin,a);
        qp.open("data.txt");
        while(qp){
        getline(qp,gv);
        getline(qp,vg);
        if(vg==a){
            cout<<"flight no:- "<<gv<<endl;
            getline(qp,po);
            cout<<"age:- "<<po<<endl<<endl;
        }
        else
            getline(qp,po);
        }
        qp.close();
        break;
        case 2:
        cout<<"enter flight number: ";
        cin>>xzx;
        cout<<"names of passengers:- \n";
        re.open("data.txt");
        while(re){
            getline(re,gv);
            if(gv==xzx){
            getline(re,vg);
            cout<<"name:- "<<vg<<endl;
            getline(re,po);
            cout<<"age:- "<<po<<endl;
            }
            else{
                getline(re,gv);
                getline(re,gv);
            }
        }
        re.close();
        break;
        default:
        cout<<"enter valid option\n\n";
        }

}
class controls{
    int m,d,mm,dd,yy,age;
    string n,name;
    public:
    void book();
    void details();
    void schudule();
    void alert();
};

void controls::book(){
        wrnof:
        cout<<"enter flight number(see schedule for flight number) ";
        cin>>n;
        cout<<"finding flight info...\n";
        if(check_flight(n)==1){
        cout<<"flight number not found\n ";
        goto wrnof;
        }
        else{
        cout<<"flight found...\n";
        fstream jk;
        jk.open("alert.txt");
        string nm,nnm;
        while(jk){
        getline(jk,nm);
        if(nm==n){
        getline(jk,nnm);
        cout<<nnm<<endl<<endl;
        }
        else{
            getline(jk,nm);
        }
    }
        
    jk.close();


        fstream f1;
        f1.open("data.txt");
        string abc;    
        int count=0;
        while (f1) { 
            getline(f1, abc); 
            if(abc==n){
                count++;
            } 
        } 
        f1.close();
        if(count>=10){
            cout<<"all seats are booked\n";
        }
        else{
            cout<<"Enter full name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"enter age: ";
            cin>>age;
        }
        fstream f;
        f.open("data.txt",ios::app);
        f<<n<<endl<<name<<endl<<age<<endl;
        f.close();
        cout<<"Ticket booked successfully";

    }
}
void controls::schudule(){
    incrrrrr:
    cout<<"enter date in dd/mm/yy format: ";
    cin >> dd;
    cin.get();
    cin >> mm;
    cin.get();
    cin >> yy;
    if(dd>31 ||mm>12 ||yy!=2020){
        cout<<"date incorrect"<<endl;
        goto incrrrrr;
    }
    stringstream ss;  
    ss<<dd<<"/"<<mm;  
    string s;  
    ss>>s;  
    fstream fa;
    string qqww,qqw;
    fa.open("schu_data.txt");
    while(fa){
        getline(fa,qqww);
        string str2 = qqww.substr (0,5);  
        if(str2==s){
            getline(fa,qqw);
            cout<<"details:-"<<qqw<<endl;
            getline(fa,qqw);
            cout<<"time:- "<<qqw<<endl;
            cout<<"flight number: "<<qqww<<endl<<endl;
        }
        else{
            getline(fa,qqw);
            getline(fa,qqw);
        }
    }
    fa.close();
}
void controls::details(){
    cout<<"enter flight number: ";
    string sono;
    cin>>sono;
    fstream jk;
        jk.open("alert.txt");
        string nm,nnm;
        while(jk){
        getline(jk,nm);
        if(nm==sono){
        getline(jk,nnm);
        cout<<nnm<<endl<<endl;
        }
        else{
            getline(jk,nm);
        }
    }
    jk.close();
    fstream faaa;
    faaa.open("schu_data.txt",ios::app);
    string qw;
    while(faaa){
        getline(faaa,qw);
        if(qw==sono){
            getline(faaa,qw);
            cout<<"details:-"<<qw<<endl;
            getline(faaa,qw);
            cout<<"time:- "<<qw<<endl<<endl;
            break;
        }
        else{
            getline(faaa,qw);
            getline(faaa,qw);
        }
    }
    faaa.close();
    cout<<"enter name to check status(for same flight)";
    string pp,op,opp;
    cin.ignore();
    getline(cin, pp);
    fstream ll;
    ll.open("data.txt");
    int fpl=0;
    while(ll){
        getline(ll,op);
        if(op==sono){
            getline(ll,opp);
            if(opp==pp){
                fpl=1;
                break;
            }
        }
        else{
            getline(ll,opp);
        }

    }
    if(fpl==1){
        cout<<"booking found\n";
    }
    else
    {
        cout<<"booking not found\n";
    }
    ll.close();
    
}
void controls::alert(){
    string cv,nm,nnm;
    fstream jk;
    int fgl=0;
    jk.open("alert.txt");
    cout<<"enter flight number to see alerts";
    cin>>cv;
    while(jk){
        getline(jk,nm);
        if(nm==cv){
        fgl=1;
        getline(jk,nnm);
        cout<<nnm<<endl<<endl;
        }
        else{
            getline(jk,nnm);
        }
    }
    if(fgl==0){
        cout<<"no alert message found for this flight\n";
    }
    jk.close();

}
int main(){
    int a=0,b,c,d,e;
    management a1;
    controls a2;
    while(a!=6){
    tgby:
    cout<<"MENU\n1.managmental controls\n2.book ticket\n3.flight details\n4.flight schudule for this month\n5.alerts\n6.exit\n\n";
    cin>>a;
    switch(a){
        case 1:
        cout<<"MENU:\n1.adding delay alert\n2.showing records\n3.add flight\n4.go to main menu\n\n";
        cin>>b;
        switch(b){
            case 1:
            a1.delay_alt();
            break;
            case 2:
            a1.record();
            break;
            case 3:
            a1.add();
            break;
            case 4:
            goto tgby;
            break;
            default:
            cout<<"entre correct choice\n";
        }
        break;
        case 2:
        a2.book();
        break;
        case 3:
        a2.details();
        break;
        case 4:
        a2.schudule();
        break;
        case 5:
        a2.alert();
        break;
        case 6:
        exit(0);
        default:
        cout<<"enter correct choice\n";
    }
    }
    return 0;
}