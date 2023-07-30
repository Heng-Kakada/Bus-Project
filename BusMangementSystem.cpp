#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include "LinkedList.h"
using namespace std;

int main(){
    struct NodeType *node = NULL; // Initialize node
    node = ReadLinkedList(fileName);
    char choice;
    int ch,n;
    do
    {
        cout << "Singly Linked list Operator : " << endl;
        cout << "[1]  Create First List" << endl;
        cout << "[2]  View Bus Detail" << endl;
        cout << "[3]  Sorting" << endl;
        cout << "[4]  Insert New Bus" << endl;
        cout << "[5]  Search Bus" << endl;
        cout << "[6]  Delete Bus" << endl;
        cout << "[7]  Save to File" << endl;
        cout << "Noted: Before you quit the system.Please don't forget to save" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
                cout << "Waring: Remember When You Try To Create List. It Mean All Data in DataBse Will eased." << endl;
                cout << "Are you Sure To Create List (Y or N): "; cin >> choice;
                if(choice == 'y' || choice == 'Y'){
                    node = CreateNode(node);
                }
            break;
        case 2:
            cout << "ID" << '\t' << "Code" << '\t' << "Starting Destination" << '\t' << "Ending Destination" << '\t' << "Starting Time" << '\t' << "Reaching Time" << '\t' << "Total Distance (km)" << '\t' << "Bus Seat" << endl;
            Traverse(node);
            break;
        case 3:
            do{
                system("clear");
                cout <<"[1]    Sort ID" << endl;
                cout <<"[2]    Sort Code" << endl;
                cin >> ch;
                switch (ch)
                {
                    case 1:
                        SortById(node);
                        break;
                    case 2:
                        SortByCode(node);
                        break;
                    default:
                        cout << "Invalid !" << endl;
                        break;
                }
                    cout << "do you want to continue (y,n)"; cin >> choice;
                }while (choice == 'y' || choice == 'Y');
            break;
        case 4:
            node = InsertNode(node);
            break;
        case 5:
            system("clear");
                do
                {
                    cout <<"[1]    Search By Id" << endl;
                    cout <<"[2]    Search By Destination" << endl;
                    cin >> ch;
                    switch (ch)
                    {
                    case 1:
                        SearchById(node);
                        break;
                    case 2:
                        SearchByDestination(node);
                        break;
                    default:
                        cout << "Invalid !" << endl;
                        break;
                    }
                    cout << "do you want to continue (y,n)"; cin >> choice;
                } while (choice == 'y' || choice == 'Y');
            break;
        case 6:
            node = DeleteNode(node);
            break;
        case 7:
            WriteLinkedList(fileName,node);
            break;
        default:
            printf("Invalid Selection!");
            break;
        }
    } while (ch != 0);
}
