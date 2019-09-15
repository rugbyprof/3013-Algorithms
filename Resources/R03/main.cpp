#include <iostream>
#include <fstream>

using namespace std;


struct Employee{
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *Next;

    Employee(){
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }

    Employee(string id,string first,string last,string sex,string mail, double pay){
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

class LinkedList{
private:
    Employee* Head;

public:
    LinkedList(){
        Head = NULL;
    }


    void frontSert(string id,string first,string last,string sex,string mail, double pay){
        Employee* Temp = new Employee(id,first,last,sex,mail,pay);

        if(Head == NULL){
            Head = Temp;
        }else{
            Temp->Next = Head;
            Head = Temp;
        }
        
    }


    void print(){
        Employee* Temp = Head;

        while(Temp != NULL){
            cout<<Temp->emp_id<<", "<<Temp->first_name<<", "<<Temp->last_name<<", "<<Temp->email<<", "<<Temp->gender<<", "<<Temp->hourly_pay;
            if(Temp->Next){
                cout<<"->";
            }
            Temp = Temp->Next;
        }
    }
};

int main(){

    LinkedList EmpList;

    string empid;
    string first;
    string last;
    string email;
    string gender;
    double pay;

    string line;
    string *tokens;
    ifstream fin("employees.dat");


    while(!fin.eof()){

        fin>>empid>>first>>last>>email>>gender>>pay;

        //cout<<empid<<", "<<first<<", "<<last<<", "<<email<<", "<<gender<<", "<<pay<<endl;

        EmpList.frontSert(empid,first,last,email,gender,pay);
    }

    EmpList.print();


    return 0;
}