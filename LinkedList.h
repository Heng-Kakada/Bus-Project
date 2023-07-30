#include <iostream>
#include <string.h>
using namespace std;

typedef struct Bus
{
    int bus_id;
    char bus_code[20];
    char starting_dest[50];
    char ending_dest[50];
    char starting_time[10];
    char reaching_time[10];
    float total_distance;
    int seats;
} Bus;

struct NodeType
{
    Bus BusInfo;
    struct NodeType* next;
};

char fileName[20] = "DataBase.txt";

struct NodeType *GetNode(){
    struct NodeType *p;
    p = new struct NodeType;
    return (p);
}

void FreeNode(struct NodeType * plist){
    delete(plist);
}

Bus Input(Bus bus){
        cout << "Enter Bus ID : "; cin >> bus.bus_id;
        cout << "Enter Bus Code : "; cin.ignore(); cin.get(bus.bus_code, 20);
        cout << "Enter Bus Starting Destination : ";cin.ignore(); cin.get(bus.starting_dest, 50);
        cout << "Enter Bus Ending Destination : ";cin.ignore(); cin.get(bus.ending_dest, 50);
        cout << "Enter Bus Starting Time : ";cin.ignore(); cin.get(bus.starting_time, 10);
        cout << "Enter Bus Reaching time : ";cin.ignore();cin.get(bus.reaching_time, 10);
        cout << "Enter Bus Total Distance : ";cin >> bus.total_distance;
        cout << "Enter Bus Seat : "; cin >> bus.seats;
    return bus;
}

struct NodeType *CreateNode(struct NodeType *plist){
        struct NodeType *p, *ptr;
        Bus bus;
        cout << "Enter Bus Information" << endl;
        p = GetNode();
        p->BusInfo = Input(bus);
        p->next = NULL;
        plist = p;
        ptr = plist;
    return plist;
}

void Traverse (struct NodeType *plist){

    struct NodeType *ptr;
    ptr = plist;
    while (ptr != NULL)
    {
        cout << ptr->BusInfo.bus_id << '\t' << ptr->BusInfo.bus_code << '\t' << ptr->BusInfo.starting_dest << "\t\t" << ptr->BusInfo.ending_dest << "\t\t" << ptr->BusInfo.starting_time << "\t\t" << ptr->BusInfo.reaching_time << "\t\t" << ptr->BusInfo.total_distance << "\t\t" << ptr->BusInfo.seats << endl;
        ptr = ptr->next;
    }

}

int CountNode(struct NodeType *plist){
    int num = 0;
    struct NodeType *ptr = plist;
    
    if (ptr == NULL){
        return num;
    }else{
        while (ptr != NULL)
        {
            num += 1;
            ptr = ptr->next;
        }
        return num;
    }
}

struct NodeType *InsertNode(struct NodeType *plist)
{
    struct NodeType *p, *ptr;
    int pos, i, count;
    Bus bus;
    char op;
    cout << "New Bus Information" << endl;
    p = GetNode();
    p->BusInfo = Input(bus);
    p->next = NULL;

    if(plist == NULL)
    {
        plist = p;
    }
    else
    {
        ptr = plist;
        cout << "Choose a position to at beginning/end/after node" << endl;
        cout << "b/e/a: "; cin >> op;
        if(op == 'b')
        {
            p->next = plist;
            plist = p;
        }
        else if(op == 'e')
        {
            while(ptr->next)
            {
                ptr = ptr->next;
            }
            ptr->next = p;
        }
        else
        {
            count = CountNode(plist);
            cout << "Enter position : "; cin >> pos;
            
            if(pos < 0 || pos > count){
                cout << "Waring: Invalid position of node or You can choose insert at beginning if you want to insert at begin of linked list" << endl;
            }
            else
            {   
                while (pos != 1)
                {
                    ptr = ptr->next;
                    pos--;
                }
                p->next = ptr->next;
                ptr->next = p;
            }
        }
    }
    return plist;
}

void SearchById(struct NodeType *plist){
    bool found;
    int id;
    struct NodeType *ptr;

    cout << "Enter Search ID : ";
    cin >> id;
    found = false;
    ptr = plist;
    while (ptr != NULL)
    {
        if (id == ptr->BusInfo.bus_id){
            cout << ptr->BusInfo.bus_id << '\t' << ptr->BusInfo.bus_code << '\t' << ptr->BusInfo.starting_dest << "\t\t" << ptr->BusInfo.ending_dest << "\t\t" << ptr->BusInfo.starting_time << "\t\t" << ptr->BusInfo.reaching_time << "\t\t" << ptr->BusInfo.total_distance << "\t\t" << ptr->BusInfo.seats << endl;
            found = true;
        }

        ptr = ptr->next;
    }

    if (found == false)
        cout << "ID " << id << " Not Found !..." << endl;
}

void SearchByDestination(struct NodeType *plist){ // end_destination
    bool found; 
    struct NodeType *ptr;
    ptr = plist;
    char start_dest[50];
    char end_dest[50];

    cout << "Enter Start Destionation : ";
    cin.ignore(); cin.get(start_dest, 50);

    cout << "Enter End Destination : ";
    cin.ignore(); cin.get(end_dest, 50);

    found = false;
    while (ptr != NULL)
    {
        if ( strcmp(start_dest, ptr->BusInfo.ending_dest) && strcmp(end_dest, ptr->BusInfo.ending_dest) == 0){
            cout << ptr->BusInfo.bus_id << '\t' << ptr->BusInfo.bus_code << '\t' << ptr->BusInfo.starting_dest << "\t\t" << ptr->BusInfo.ending_dest << "\t\t" << ptr->BusInfo.starting_time << "\t\t" << ptr->BusInfo.reaching_time << "\t\t" << ptr->BusInfo.total_distance << "\t\t" << ptr->BusInfo.seats << endl;
            found = true;
        }
        ptr = ptr->next;
    }

    if(found == false){
        cout << start_dest << " and " << end_dest << " Not Found !" << endl;
    }
}

void SortById(struct NodeType *plist){
    struct NodeType *p, *ptr;
    Bus temp;

    for (p = plist; p!=NULL; p=p->next){
        for (ptr = p->next; ptr != NULL ; ptr = ptr->next)
        {
            if(p->BusInfo.bus_id > ptr->BusInfo.bus_id){
            temp = p->BusInfo;
            p->BusInfo = ptr->BusInfo;
            ptr->BusInfo = temp;
            }  
        }
    }
}

void SortByCode(struct NodeType *plist){
    struct NodeType *p, *ptr;
    Bus temp;

    for (p = plist; p!=NULL; p=p->next){
        for (ptr = p->next; ptr != NULL ; ptr = ptr->next)
        {
            if(strcmp(p->BusInfo.bus_code, ptr->BusInfo.bus_code) > 0 ){
                temp = p->BusInfo;
                p->BusInfo = ptr->BusInfo;
                ptr->BusInfo = temp;
            }
        }
    }
}

struct NodeType *DeleteNode(struct NodeType *plist)
{
    struct NodeType *p, *ptr;
    char op;
    int pos, count;
    if(plist == NULL)
    {
        cout << "Linked list is empty.\n" << endl;
        return (NULL);
    }

    cout << "Choose a position to delete beginning/end/certain position/delete all" << endl;
    cout << "b/e/c/a : ";cin >> op;

    if(op == 'b')
    {
        if(plist->next == NULL)
        {
            plist = NULL;
        }
        else{
            p = plist;
            plist = plist->next;
            FreeNode(p);
            p = NULL;
        }
    }
    else if(op == 'e')
    {
        p = plist;
        while(p->next->next != NULL)
        {
            p = p->next;
        }
        FreeNode(p->next);
        p->next = NULL;
    }
    else if(op == 'c'){
        count = CountNode(plist);
        cout << "Enter node position to delete : ";cin >> pos;
        if(pos < 0 || pos > count){
            cout << "Waring: Invalid position of node or You can choose delete at beginning if you want to delete at begin of linked list";
        }
        else{
            while(pos != 1)
            {
                ptr = p;
                p = p->next;
                pos--;
            }
            ptr->next = p->next;
            FreeNode(p);
            p = NULL;
            cout << "\nSuccess: Congratulations !" << endl;
        }
    }
    else
    {
        ptr = plist;
        while(ptr != NULL)
        {
            ptr = ptr->next;
            FreeNode(plist);
            plist = ptr;
        }
        printf("Linked list have been cleared.\n");
        return plist;
    }
    return plist;
}

void WriteLinkedList(char filename[], struct NodeType *plist){

    struct NodeType *ptr;
    ptr = plist;

    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL)
    {
        cout << "file Node Found..." << endl;
        exit(1);
    }

    while(ptr != NULL){
        fwrite(ptr, sizeof(struct NodeType), 1, file);
        ptr = ptr->next;
    }

    if(fwrite != 0)
    {
        cout << "Linked List stored in the file successfully" << endl;
    }
       else
    {
           cout << "Error While Writing\n" << endl;
    }
    
    fclose(file);

}

struct NodeType *ReadLinkedList(char filename[]){
    
    struct NodeType *ptr;
    ptr = new struct NodeType;

    struct NodeType *plist, *p;

    p = plist = NULL;

    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL)
    {
        cout << "file Node Found..." << endl;
        file = fopen(filename, "w");
        fclose(file);
        exit (1);
    }

    while (fread(ptr, sizeof(struct NodeType), 1, file))
    {
        
        if(plist == NULL){
            plist = p = new struct NodeType;
        }else{
            p->next = new struct NodeType;
            p = p->next;
        }
        p->BusInfo = ptr->BusInfo;
        p->next = NULL;

    }
    
    fclose(file);


    return plist;
}
