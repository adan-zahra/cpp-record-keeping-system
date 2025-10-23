#include<iostream>
#include<string>
using namespace std;
//class
class Entity {
private:
    int Id;
    string Name, Item;
    float CostValue;
public:
    Entity(int Id = 0, string Name = " ", string Item = " ", float CostValue = 0.0) 
    : Id(Id), Name(Name), Item(Item), CostValue(CostValue) {}

    void display() const {
    cout << " ID: " <<Id<< ", Name: " <<Name<< ", Item: " <<Item<< ", Cost_Value: " <<CostValue<< endl;
    }
    int getId() const { return Id; }
};

class EntityManager {
private:
    Entity entities[100];
    int count = 0;

public:
    void addEntity() {
        int Id;
        string Name;
		string Item;
        float CostValue;
      //  cout << " Enter ID, Name, Description/Item, Cost_Value: ";
      //  cin >> Id >> Name >> Description/Item >> CostValue;
        cout<<" Enter ID : ";
		cin>>Id;
        cout<<" Enter Name : ";
        cin>>Name;
        cout<<" Enter an Item : ";
        cin>>Item;
        cout<<" Enter Cost_Value : ";
        cin>>CostValue;
        entities[count++] = Entity(Id, Name, Item, CostValue);
        cout<< "\n _________________________________________________________________\n"<<endl;
    }

    void viewRecords() const {
        for (int i = 0; i < count; i++) {
            entities[i].display();
        }
        cout<< "\n _________________________________________________________________\n"<<endl;
    }

    void searchRecords() const {
        int SearchId;
        cout << " Enter ID to search: ";
        cin >> SearchId;

        for (int i = 0; i < count; i++) {
        if (entities[i].getId() == SearchId) {
        entities[i].display();
        cout<< "\n _________________________________________________________________\n"<<endl;
        return;
            }
        }
        cout << " Record Not Found!" << endl;
    }
};
//main function
int main() {
	cout<< "                              #--Records--#                          "<<endl;
    cout<< "\n-------------------------------------------------------------------"<<endl;
    EntityManager Manager;
    int choice;
    do {
        cout << " Menu:\n 1. Add Entity Data\n 2. View Records\n 3. Search Record\n 4. Exit\n Choice = ";
        cin >> choice;
//switch case
        switch (choice) {
            case 1: Manager.addEntity(); break;
            case 2: Manager.viewRecords(); break;
            case 3: Manager.searchRecords(); break;
            case 4: cout << " Exit!" << endl; break;
            default: cout << " Invalid! Try Again." << endl;
        }
    } while (choice!=4);
      cout<< "\n-------------------------------------------------------------------"<<endl;
      return 0;
}
