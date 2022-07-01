#include <bits/stdc++.h>
using namespace std;
void deletecontact(map<string,vector<string>> &m){
    cout<<"Enter the name whose contact details are to be deleted "<<endl;
    string s;
    cin>>s;
    map<string,vector<string>> :: iterator it;
    it = m.find(s);
    if(it == m.end()){
        cout<<"Name/contact number not found :("<<endl<<endl;       
    }
    else{
        m.erase(it->first);
        cout<<"Contact deleted"<<endl<<endl;
    }
}

void updateexistingcontact(map<string,vector<string>> &m){
    cout<<"1-->Add new phone number to an existing contact"<<endl;
    cout<<"2-->Delete phone number from an existing contact"<<endl;
    cout<<endl<<"Press -1 to exit"<<endl;
    string c;
    cin>>c;
    do{
        if(c=="1"){
            string s;
            cout<<"Enter the required contact name"<<endl;
            cin>>s;
            map<string,vector<string>> :: iterator it;
            it = m.find(s);
            if(it == m.end()){
                cout<<"Name not found :("<<endl;       
            }
            else{
                string t;
                cout<<"Enter contact number :"<<endl;
                cin>>t;
                it->second.push_back(t);
                if(t.length()!=10){
                    do{
                        cout<<"Enter valid number"<<endl;
                        cin>>t;
                    }while(t.length()!=10);
                }
                cout<<"New number added."<<endl;
            }
        }
        else if(c=="2"){
            string s,t;
            cout<<"Enter the required contact name"<<endl;
            cin>>s;
            cout<<"Enter the required contact number"<<endl;
            cin>>t;
            map<string,vector<string>> :: iterator it;
            it = m.find(s);
            if(it == m.end()){
                cout<<"Contact name not found :("<<endl;

            }
            else{
                int k=0;
                do{ 
                    k=0;
                    for(int i=0;i<it->second.size();i++){
                        if(t==it->second[i]){
                            it->second.erase(it->second.begin()+i);
                            k=1;
                            break;
                        }
                    }
                    if(k==0){
                        cout<<"Enter valid contact number"<<endl;
                        cin>>t;
                    }
                }while(t.length()!=10 or k==0);
                cout<<"Contact deleted!"<<endl;
            }
        }
        else {
            cout<<"Please select an appropriate option"<<endl;
        }
        cout<<endl<<"Select action:"<<endl;
        cin>>c;
    }while(c!="-1");
}

void newcontact(map<string,vector<string>> &m){
    string s,t;
    vector <string> v;
    cout<<"Enter contact name :"<<endl;
    cin>>s;
    if(m.find(s)!=m.end()){
        cout<<"Contact already exists"<<endl<<endl;
        return;
    }
    cout<<"Enter contact number :"<<endl;
    cin>>t;
    if(t.length()!=10){
        do{
            cout<<"Enter valid contact number"<<endl;
            cin>>t;
        }while(t.length()!=10);
    }
    v.push_back(t);
    m.insert({s,v});
    cout<<"Contact added."<<endl<<endl;
    return;
}


void displaycontact(map<string,vector<string>> &m){
    for(auto it: m){
        cout<<it.first<<" --> ";
        for(int i=0;i<it.second.size();i++){
            cout<<it.second[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}

void searchusingname(map<string,vector<string>> &m){
    string name;
    cout<<"Enter contact name : "<<endl;
    cin>>name;
    map<string,vector<string>> :: iterator itr;
    itr = m.find(name);
    if(itr == m.end()){
        cout<<"Contact name not found :("<<endl<<endl;
    }
    else{
        for(int i=0; i<itr->second.size(); i++){
            cout<<itr->first<<" --> "<<itr->second[i]<<endl;
        }
    }
}

void show(){
    cout<<"Phonebook App-"<<endl;
    cout<<"1-->Create new contact"<<endl;
    cout<<"2-->Update existing contact"<<endl;
    cout<<"3-->Display all contacts"<<endl;
    cout<<"4-->Search using name"<<endl;
    cout<<"5-->Delete contact"<<endl<<endl;
    cout<<"Press -1 to exit"<<endl;
    return ;
}

int main(){
    show();
    cout<<endl<<"Select action:"<<endl<<endl;
    string choice;
    cin>>choice;
    map<string,vector<string>>m;
    do{
        if(choice=="1"){
            newcontact(m);
        }
        else if(choice=="2"){
            updateexistingcontact(m);
        }
        else if(choice=="3"){
            displaycontact(m);
        }
        else if(choice=="4"){
            searchusingname(m);
        }
        else if(choice=="5"){
            deletecontact(m);

        }
        else if(choice!="-1"){
            cout<<"Please select an appropriate option"<<endl;
        }
        
        if(choice!="-1"){
            show();
            cout<<endl<<"Select action:"<<endl;
            cin>>choice;
        }
    }while (choice != "-1");
    return 0;
}