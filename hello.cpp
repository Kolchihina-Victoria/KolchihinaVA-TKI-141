#include <iostream>
#include<string>
using namespace std;
class Person
{
    private:
        string lastname;
        string firstname;
        string patronymic;
    public:
        void person(const string& ln,const string& fn,const string& pn="");
        void show();
        void showFormal();
    
};
void Person::person(const string& ln,const string& fn,const string& pn)
{
    lastname=ln;
    firstname=fn;
    patronymic=pn;
}

void Person::show()
{
    cout<<lastname<<" "<<firstname<<endl;
}
void Person::showFormal()
{
    cout<<lastname<<" "<<firstname<<" "<<patronymic<<endl;
}

int main() 
{
    string ln,fn,pn;
  cout<<"ввести фамилию ";
  cin>>ln;
  cout<<"ввести имя ";
  cin>>fn;
  cout<<"ввести отчество";
  cin>>pn;
  Person me;
  me.person(ln,fn,pn);
  me.show();
  me.showFormal();
}
