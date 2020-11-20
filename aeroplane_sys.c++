#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

 int check_flight(string fno)    //flight no
 {
     fstream new_file;           //File to be opened with variable name new_file
     new_file.open("schu_data.txt");
     string data;
     int flag=0;
     while(new_file)
     {
         getline(new_file,data);
         if(data==fno)         //Data == flight number
         {
             flag=1;
             break;
         }
     }
     if(flag==1)
     {
         return 0;
     }
     else
     {
         return 1;
     }
     new_file.close();
 }

//CLASS FOR ADMIN/MANAGEMENT

class management{
    int n,m,j,k;
    string no,a,b;
    public:
    void delay_alt();
    void record();
    void add();
};

//definition outside class using SRO
void management::add()
{
    int dd,mm;
    cout<<"Enter date and month: ";
    cin>>dd>>mm;
    string sadd;            //string sadd declared
    stringstream ssdata;        //stringstream ssdata declared
    int i=6;
    while(1)
    {
    i++;
    ssdata<<dd<<"/"<<mm<<"-"<<i;       //Add a string to the stringstream object.
    ssdata>>sadd;
    if(check_flight(sadd)==1)
    {
        break;
    }
    }
    string takeoff,land,timeofd;            //string decln 
    cout<<"Enter takeoff point and landing point: ";
    cin>>takeoff>>timeofd;
    cout<<"Enter time of departure: ";
    cin>>timeofd;
    fstream add;
    add.open("schu_data.txt",ios::app);
    add<<sadd<<endl<<takeoff<<" to "<<land<<endl<<timeofd<<endl;
    cout<<"New flight added successfully. flight number:- "<<sadd<<endl;
    add.close();
}

//definition outside class using SRO
void management::delay_alt()
{
    string msg;
    loop:
    cout<<"Enter flight number to add delay or any other alert";
    cin>>no;
    if(check_flight(no)==1){
        cout<<"Flight not found\n";
        goto loop;
    }
    else{
        cout<<"Enter message\n";
        cin.ignore();
        getline(cin,msg);
    }
    fstream delay;
    delay.open("Alert.txt",ios::app);
    delay<<no<<endl<<msg<<endl;
    delay.close();
}

//definition outside class using SRO
void management::record()
{
    cout<<"\n1.Search record by name\n2.Search flight record\n\n";
    cin>>n;
    fstream file1,file2;
    string f_no1,name,age,f_no2;            //flight_no1, 2 declared
    int flag=0,flag2=0;
    switch(n){
        case 1:
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,a);
        file1.open("data.txt");
        while(file1){
        getline(file1,f_no1);
        getline(file1,name);
        if(name==a){
            cout<<"Flight no:- "<<f_no1<<endl;
            getline(file1,age);
            cout<<"Age:- "<<age<<endl<<endl;
            flag=1;
        }
        else
            getline(file1,age);
        }
        if(flag=0){
            cout<<"No record found \n";
        }
        file1.close();
        break;
        case 2:
        again:
        cout<<"Enter flight number: ";
        cin>>f_no2;
        if(check_flight(f_no2)==1){
            cout<<"flight not found\n";
            goto again;
        }
        cout<<"Names of passengers:- \n";
        file2.open("data.txt");
        while(file2){
            getline(file2,f_no1);
            if(f_no1==f_no2){
            getline(file2,name);
            cout<<"Name:- "<<name<<endl;
            getline(file2,age);
            cout<<"Age:- "<<age<<endl;
            flag2=1;

            }
            else{
                getline(file2,f_no1);
                getline(file2,f_no1);
            }
        }
        if(flag2==0){
            cout<<"No record found\n";
        }
        file2.close();
        break;
        default:
        cout<<"Enter valid option\n\n";
        }

}

//CLASS FOR CUSTOMER/CONTROLS
class controls
{
    int m,d,mm,dd,yy,age;
    string n,name;
    public:
    void book();
    void details();
    void schudule();
    void alert();
};

//definition outside class using SRO
void controls::book(){
        loop3:
        cout<<"Enter flight number(see schedule for flight number) ";
        cin>>n;
        cout<<"finding flight info...\n";
        if(check_flight(n)==1)
        {
        cout<<"Flight number not found\n ";
        goto loop3;
        }
        else{
        cout<<"Flight found...\n";
        fstream book;
        book.open("alert.txt");
        string a,b;
        while(book){
        getline(book,a);
        if(a==n)
        {
        getline(book,b);
        cout<<b<<endl<<endl;
        }
        else
        {
            getline(book,a);
        }
    }
    book.close();
        fstream book1;
        book1.open("data.txt");
        string abc;
        int count=0;
        while (book1) {
            getline(book1, abc);
            if(abc==n){
                count++;
            }
        }
        book1.close();
        if(count>=10){
            cout<<"All seats are booked\n";
        }
        else{
            cout<<"Enter full name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter age: ";
            cin>>age;
        }
        fstream book2;
        book2.open("data.txt",ios::app);
        book2<<n<<endl<<name<<endl<<age<<endl;
        book2.close();
        cout<<"Ticket booked successfully";
    }
}

//definition outside class using SRO
void controls::schudule()
{
    loop2:
    cout<<"Enter date in dd/mm/yyyy format: ";
    cin >> dd;
    cin.get();
    cin >> mm;
    cin.get();
    cin >> yy;
    if(dd>31 ||mm>12 ||yy!=2020)
    {
        cout<<"Date incorrect"<<endl;
        goto loop2;
    }
    stringstream ss;            //variable ss
    ss<<dd<<"/"<<mm;
    string s;                   //variable s
    ss>>s;
    fstream schedule;
    string flightno,details;
    int sflag=0;
    schedule.open("schu_data.txt");
    while(schedule){
        getline(schedule,flightno);
        string str2 = flightno.substr(0,5);
        if(str2==s){
            getline(schedule,details);
            cout<<"Details:-"<<details<<endl;
            getline(schedule,details);
            cout<<"Time:- "<<details<<endl;
            cout<<"Flight number: "<<flightno<<endl<<endl;
            sflag=1;
        }
        else{
            getline(schedule,details);
            getline(schedule,details);
        }
    }
    if(sflag==0){
        cout<<"No flight found for this data\n";
    }
    schedule.close();
}

//definition outside class using SRO
void controls::details()
{
    again1:
    cout<<"Enter flight number: ";
    string f_no;
    cin>>f_no;
    if(check_flight(f_no)==1){
        cout<<"flight not found\n";
        goto again1;
    }
    fstream file_d;
        file_d.open("alert.txt");
        string nm,nnm;
        while(file_d){
        getline(file_d,nm);
        if(nm==f_no){
        getline(file_d,nnm);
        cout<<nnm<<endl<<endl;
        }
        else{
            getline(file_d,nm);
        }
    }
    file_d.close();
    fstream file2;
    file2.open("schu_data.txt");
    string details_1;
    while(file2){
        getline(file2,details_1);
        if(details_1==f_no){
            getline(file2,details_1);
            cout<<"Details:-"<<details_1<<endl;
            getline(file2,details_1);
            cout<<"Time:- "<<details_1<<endl<<endl;
            break;
        }
        else{
            getline(file2,details_1);
            getline(file2,details_1);
        }
    }
    file2.close();
    cout<<"Enter name to check status(for same flight)";
    string x,y,z;
    cin.ignore();
    getline(cin,x);
    fstream file3;
    file3.open("data.txt");
    int fpl=0;
    while(file3){
        getline(file3,y);
        if(y==f_no){
            getline(file3,z);
            if(z==x){
                fpl=1;
                getline(file3,z);
                break;
            }
            else{
                getline(file3,z);
            }
        }
        else
        {
            getline(file3,z);
            getline(file3,z);
        }

    }
    if(fpl==1){
        cout<<"Booking found\n";
    }
    else
    {
        cout<<"Booking not found\n";
    }
   file3.close();
    
}

//definition outside class using SRO
void controls::alert()
{
    string text1,text2,text3;
    fstream alert;
    int flag1=0;
    alert.open("alert.txt");
    again2:
    cout<<"Enter flight number to see alerts";
    cin>>text1;
    if(check_flight(text1)==1){
        cout<<"flight not found\n";
        goto again2;
    }
    while(alert)
    {
        getline(alert,text2);
        if(text2==text1)
        {
        flag1=1;
        getline(alert,text3);
        cout<<text3<<endl<<endl;
        }
        else
        {
            getline(alert,text3);
        }
    }
    if(flag1==0)
    {
        cout<<"No alert message found for this flight\n";
    }
    alert.close();

}


//MAIN FUNCTION
int main()
{
    int ch = 0,ch1 = 0,ch2=0;   //For Switch case
    management m1;
    controls c2;
    loop1:
    while(ch!=3)
    {
    cout<<"\n-----------\nMENU\n1.User\n2.Admin\n3.Exit\n";
        cin>>ch;
    switch(ch)
        {
        case 1:      //Menu - user
            {
            cout<<"\nUser-\n 1.Book tickets\n 2.Flight details \n 3.Flight Schedule \n 4.Alerts\n 5.Go To Main-Menu\n";
            cin>>ch1;
            switch(ch1)
            {
            case 1:
                cout<<"Book Tickets\n";
                c2.book();                  //booking tickects -USER
                break;
            case 2:
                c2.details();    //flight details for user
                break;
            case 3:
                c2.schudule();    //flight schedule
                break;
            case 4:
                c2.alert();       //alert messages for users
                break;
            case 5:
                goto loop1;
                break;
            }
            break;
            }
                
        case 2:      //Menu- admin
            {
            cout<<"Admin-\n 1.Adding delay alert\n 2.Showing records \n 3.Add flight \n 4.Go To Main-Menu\n";
            cin>>ch2;
            switch(ch2)
            {
                case 1:
                    cout<<"Add Delay Alert\n";
                    m1.delay_alt();
                    break;
                case 2:
                    cout<<"Displaying Records\n";
                    m1.record();
                    break;
                case 3:
                    cout<<"Add Flight\n";
                    m1.add();
                    break;
                case 4:
                    goto loop1;
                    break;
                default:
                cout<<"Entre Correct Choice\n";
             }
             break;
             }
        case 3:
         cout<<"Thank You!\n";
         break;
}    //END OF SWITCH CASE
    
}    //END OF WHILE LOOP
    return 0;
}   //MAIN FUNCTION END
 
