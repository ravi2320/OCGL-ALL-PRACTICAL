/*Write C++ program using STL for sorting and searching user defined records such as personal records
(Name, DOB, Telephone number etc) using vector container.
OR Write C++ program using STL for sorting and searching user defined records such as Item records 
(Item code, name, cost, quantity etc) using vector container.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class items
{
    private:
        string name;
        int cost;
        int quantity;
    public:
        int code;
        items(int c,string n,int cs,int q)
        {
            code=c;
            name=n;
            cost=cs;
            quantity=q;
        }
        void display()
        {
            cout<<"Item code="<<code<<"|Name="<<name<<"|Cost="<<cost<<"|Quantity="<<quantity<<endl;
        }
};
    vector<items>v1;
        bool compare(const items &i1, const items &i2)
        {
        return i1.code < i2.code;
        }
int main()
{   
    vector<items>v1;
    int choice;
    while(1)
    {
    cout<<"Enter\n 1.Insert Item \n 2. Display Items \n 3. Search Item \n 4. Sort Item \n 0. Exit"<<endl;
    cin>>choice;
        if(choice==1)
        {
            int code,cost,quantity;
            string name;
            cout<<"Enter Item Details:(In below format)"<<endl;
            cout<<"Code|Name|Cost|Quantity"<<endl;
            cin>>code>>name>>cost>>quantity;
            items item(code,name,cost,quantity);
            v1.push_back(item);
        }
        else if(choice==2)
        {
           for (int i=0;i<v1.size();i++)
           {
               v1[i].display();
           }
        }
        else if(choice==3)
        {
           int search;
           cout<<"Enter the Item code to search:"<<endl;
           cin>>search;
           int flag=0;
           for(int i=0;i<v1.size();i++)
           {
           if(v1[i].code==search)
           {
               v1[i].display();
               flag=1;
               break;
           }
           }
            if(flag==0)
           {
               cout<<"Item is not found!"<<endl;
           }
        }
        else if(choice==4)
        {
            sort(v1.begin(),v1.end(),compare);
            cout<<"Sorted as per item Code:"<<endl;
        }
        else if(choice==0)
        {
          cout<<"Exited"<<endl;
          break;
        }
    }
}

