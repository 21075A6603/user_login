#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class User{
        private:
        string userName,passWord;
        public:
        User(string name,string pass){
                userName=name;
                passWord=pass;
        }
        string getPassWord(){
                return passWord;
        }
        string getName(){
                return userName;
        }
};
class UserManager{
        private:
        vector<User> users;
        public:
        void RegisterUser(){
                string userName,passWord;
                cout<<"enter the user name:";
                cin>>userName;
                cout<<"enter pass word:";
                cin>>passWord;
                User newUser(userName,passWord);
                users.push_back(newUser);
                cout<<"\t\t user registration sucessfull"<<endl;
        }
        bool login(string name,string pass){
                for(int i=0;i<users.size();i++){
                        if(users[i].getName()==name && users[i].getPassWord()==pass){
                                cout<<"******login successfull******"<<endl;
                                return true;
                        }
                }
                cout<<"\t\t-*-*-*-Invalid username or password-*-*-*-*"<<endl;
                return false;
        }
        void showList()
        {
                cout<<"\t\t_____users List______"<<endl;
                for(int i=0;i<users.size();i++)
                {
                        cout<<"\t\t"<<users[i].getName()<<endl;
                }
        }
        void serachInList(string name){
                for(int i=0;i<users.size();i++){
                        if(users[i].getName()==name){
                                cout<<"\t\tuserfound...";
                        }
                }
        }
        void remUser(string name){
                for(int i=0;i<users.size();i++){
                        if(users[i].getName()==name){
                                users.erase(users.begin()+i);
                                cout<<"\t\tuser removed successfuly";
                        }
                }
        }
};
int main(){
        UserManager usermanager;
        int os;
        char choice;
        do{
                system("clear");
                cout<<"\n\n\t\t1. Register User "<<endl;
                cout<<"\t\t2.Login "<<endl;
                cout<<"\t\t3. Show User List "<<endl; 
                cout<<"\t\t4. Search User "<<endl;
                cout<<"\t\t5. Delete User"<<endl;
                cout<<"\t\t6. Exit"<<endl;
                cout<<"\t\tEnter your choice :";
                cin>>os;
                
               
                switch (os)
                {
                        case 1:
                        {
                                usermanager.RegisterUser();
                                break;
                        }
                        case 2:
                        {
                                string name,pass;
                                cout<<"\t\tenter user name: ";
                                cin>>name;
                                cout<<"\t\tenter your password:  ";
                                cin>>pass;
                                usermanager.login(name,pass);
                                break;
                        }
                        case 3:
                        {
                                usermanager.showList();
                                break;
                        }
                        case 4:
                        {
                                string inputName;
                        cout<<"enter tha name to be search...  ";
                        cin>>inputName;
                        usermanager.serachInList(inputName);
                        break;
                        }
                        case 5:
                        {string name;
                        cout<<"enter the name to be delete:";
                        cin>>name;
                        usermanager.remUser(name);
                        break;}
                        case 6:
                        exit(1);
                       
                }
        
                cout<<"do you want to continue: Y / N    :";
                cin>>choice;
        }
        while(choice=='y' || choice=='Y');
}

