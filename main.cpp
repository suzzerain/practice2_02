#include <iostream>
#include <windows.h>
#include <chrono>




using namespace std;
struct list
{
    int data;
    list *head;
    list *tail;
};
list *CreateList()
{
    int userChoice;
    cout << "\n--------------------------------------------------------------\n";
    cout << "Choose the type of creating list\n1 - Get N random elements\n2 - Manual mode" ;
    cout << "\n--------------------------------------------------------------\n";
    while (!(cin >> userChoice)) {
        cout << "\n--------------------------------------------------------------\n";
        cout << "Invalid input";
        cout << "\n--------------------------------------------------------------\n";
    }
    if(userChoice == 1) {
        int Length;
//        srand(time(NULL));
        cout << "\n--------------------------------------------------------------\n";
        cout << "Enter size of list" ;
        cout << "\n--------------------------------------------------------------\n";
        while (!(cin >> Length)) {
            cout << "\n--------------------------------------------------------------\n";
            cout << "Invalid input";
            cout << "\n--------------------------------------------------------------\n";
        }
        auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        list *Curr = 0,
                *Next = 0;
        for (unsigned i = 1; i <= Length; ++i) {
            Curr = new list;
            Curr->head = Next;
            if (Next) {
                Next->tail = Curr;
            }
            Next = Curr;
        }
        Curr->tail = 0;
        list * beg = Curr;
        while ( beg )
        {
            beg->data =rand()%100;
            beg = beg->head;
        }
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\nDuration of creating list: " << end - start << "ns";
        cout << "\n--------------------------------------------------------------\n";
        return Curr;

    }
    if (userChoice==2){
        cout << "\n--------------------------------------------------------------\n";
        cout << "Enter value:(To stop manual mode enter 0)" ;
        cout << "\n--------------------------------------------------------------\n";
        int userValue = 1, Length;
        list *Curr = 0,
                *Tail = 0;
        auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        while (userValue!=0) {
            cin >> userValue;
            if (userValue) {
                Length += 1;
                Curr = new list;
                Curr->data = userValue;
                Curr->tail = Tail;
                if (Tail) {
                    Tail->head = Curr;
                }
                Tail = Curr;
            }
        }
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\nDuration of creating list: " << end - start << "ns\n";
        cout << "\n--------------------------------------------------------------\n";
        if(Length){
            Curr->head = 0;
            while(Curr->tail){
                Curr = Curr->tail;
            }

            return Curr;
        }
        else{
            cout << "\n--------------------------------------------------------------\n";
            cout << "List is empty!\n";
            cout << "\n--------------------------------------------------------------\n";
            return 0;
        }
    }

}
void PrintList(list *&Beg){
    list * Curr = Beg;
    cout << "\n--------------------------------------------------------------\n";
    while(Curr){
        cout << Curr->data << " ";
        Curr = Curr->head;
    }
    cout << "\n--------------------------------------------------------------\n";
}
int GetListLength(list *&Beg){
    list *Curr = Beg;
    int i = 0;
    while(Curr){
        ++i;
        Curr= Curr->head;
    }
    return i;
}
void DeleteList ( list * &Beg ){
    list *Next;
    while ( Beg )
    {

        Next = Beg->head;
        delete Beg;
        Beg = Next;
    }
}
list *getAdr(list * &beg,unsigned index){
    while (beg && (index--)) {
        beg = beg->head;
    }
    return beg;
}

void DelItem( list * &Beg )
{
    int Index;
    list *Curr = Beg;
    cout << "\n--------------------------------------------------------------\n";
    cout << "Enter Index of deleting item:";
    cout << "\n--------------------------------------------------------------\n";
    while(!(cin >> Index)){
        cout << "\n--------------------------------------------------------------\n";
        cout << "Invalid input";
        cout << "\n--------------------------------------------------------------\n";
    }

    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    list * Item;
    if (!Index)
    {
        Item = Beg->head;
        delete Beg;
        Beg = Item;
        Beg->tail = 0;
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\nDuration of deleting item: " << end - start << "ns";
        cout << "\n--------------------------------------------------------------\n";
        return;
    }
    Item = getAdr( Curr, Index-1);
    Curr = Beg;
    list * DItem = Item->head;
    if(DItem->head) {
        Item->head = DItem->head;
        Item->head->tail = Item;
        delete DItem;
    }
    else{
        Item->head = 0;
        delete DItem;
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "\nDuration of deleting item: " << end - start << "ns\n";
    cout << "\n--------------------------------------------------------------\n";
}

void InsertItem(list* &Beg){
    list*Curr = Beg;
    int userValue,userIndex;
    cout << "\n--------------------------------------------------------------\n";
    cout << "Enter value to insert:";
    cout << "\n--------------------------------------------------------------\n";
    while(!(cin>>userValue)){
        cout << "Invalid value\n";
    }
    cout << "\n--------------------------------------------------------------\n";
    cout << "Choose the Position to insert " << userValue;
    cout << "\n--------------------------------------------------------------\n";
    while(!(cin>>userIndex)){
        cout << "Invalid value\n";
    }
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    list*Item = new list;
    Item->data = userValue;
    Curr = Beg;
    if(userIndex==1){
        Beg->tail = Item;
        Item->tail = 0;
        Item->head = Beg;
        Beg = Item;
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\nDuration of inserting item: " << end - start << "ns\n";
        cout << "--------------------------------------------------------------\n";
        return;
    }
    if(userIndex == GetListLength(Curr)){
        Item->head = 0;
        list* lItem = getAdr(Curr,userIndex-1);
        Item->tail = lItem;
        lItem->head = Item;
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\nDuration of inserting item: " << end - start << "ns\n";
        cout << "--------------------------------------------------------------\n";
        return;
    }
    list* lItem = getAdr(Curr,userIndex-2);
    Item->tail = lItem;
    Item->head = lItem->head;
    Item->head->tail =  Item;
    lItem->head = Item;
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "\nDuration of inserting item: " << end - start << "ns\n";
    cout << "--------------------------------------------------------------\n";
    return;

}
void GetItem(list* &Beg){
    int userChoice;
    cout << "\n--------------------------------------------------------------\n";
    cout << "1 - Get item by index\n2 - Get item by value";
    cout << "\n--------------------------------------------------------------\n";
    while(!(cin>>userChoice)){
        cout << "Invalid input\n";
    }
    if(userChoice==1) {
        auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        int userIndex;
        cout << "\n--------------------------------------------------------------\n";
        cout << "Enter Index of item:";
        cout << "\n--------------------------------------------------------------\n";
        while (!(cin >> userIndex)) {
            cout << "Invalid input\n";
        }
        list *Curr = Beg;
        cout << getAdr(Curr, userIndex)->data << endl;
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\nDuration of searching item: " << end - start << "ns\n";
        cout << "--------------------------------------------------------------\n";

    }
    if(userChoice==2){
        auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\n--------------------------------------------------------------\n";
        cout <<"Enter value of item:";
        cout << "\n--------------------------------------------------------------\n";
        int userValue;
        while(!(cin>>userValue)){
            cout << "Invalid input\n";
        }
        list *Curr = Beg;
        bool flag = false;
        while(Curr){
            if(Curr->data==userValue){
                cout << Curr->data << " ";
                flag = true;
            }
            Curr = Curr->head;
        }
        if(!flag){
            cout << "\n--------------------------------------------------------------\n";
            cout <<"Item with value " << userValue <<" wasn't founded";
            cout << "\n--------------------------------------------------------------\n";
        }
        cout << endl;
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "\nDuration of searching item: " << end - start << "ns\n";
        cout << "--------------------------------------------------------------\n";
    }

}
void swapItem(list * &beg){
    int IndexL, IndexR;
    cout << "\n--------------------------------------------------------------\n";
    cout << "Enter left Index of swapping item:";
    cout << "\n--------------------------------------------------------------\n";
    while(!(cin >> IndexL)){
        cout << "\nInvalid input\n";
    }
    cout << "\n--------------------------------------------------------------\n";
    cout << "Enter right Index of swapping item:";
    cout << "\n--------------------------------------------------------------\n";
    while(!(cin >> IndexR)){
        cout << "\nInvalid input\n";
    }
    list * st = beg;

    list * Litem = getAdr(st,IndexL);
    st = beg;
    list * Ritem = getAdr(st,IndexR);
    st = beg;
    if(Litem->tail){
        Litem->tail->head = Ritem;
    }else{
        beg = Ritem;
    }
    if((IndexR-IndexL!=1)){
        Litem->head->tail = Ritem;
        Ritem->tail->head = Litem;
    }
    if(Ritem->head){
        Ritem->head->tail = Litem;
    }


    if((IndexR-IndexL==1)){
        Ritem->tail = Litem->tail;
        Litem->tail = Ritem;
        Litem->head = Ritem->head;
        Ritem->head = Litem;
        return;
    }

    list * buf = Litem->tail;
    Litem->tail = Ritem->tail;
    Ritem->tail = buf;
    buf = Litem->head;
    Litem->head = Ritem->head;
    Ritem->head = buf;

}
int* CreateArray(){
    int arrSize;
    cout << "\n----------------------------------";
    cout << "\nEnter size of array for comparsion:";
    cout << "\n----------------------------------\n";
    while(!(cin>>arrSize)){
        cout << "\nInvalid Input\n";
    }
    int  *arr = (int *)malloc(arrSize * sizeof(int));
    for (int *i = arr; i < arr + arrSize;i++){
        *i = rand()%100;
    }
    return arr;
}
void PrintArray(int* arr,int arrSize){
    for (int *i = arr; i < arr + arrSize;i++){
        cout << *i << " ";
    }
}

void ComparsionIdz(list * &Beg, int*arr,int size){
    int userValue;
    cout << "\n----------------------------------";
    cout << "\nEnter value for any even-numbered item:";
         cout << "\n----------------------------------\n";
    while(!(cin >> userValue)){
        cout << "\nInvalid input\n";
    }
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for (int *i = arr,g=0; i < arr + size;i++,g++){
        if (g%2==0){
            *i -= userValue;
        }
        else{
            *i -= rand()%6;
        }
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "\n--------------------------------------------------------------\n";
    cout << "Duration of operation in dynamic array: " << end - start << "ns\n";
    cout << "--------------------------------------------------------------\n";
    PrintArray(arr,size);
    list*Curr = Beg;
    int i = 0;
    start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    while(Curr){
        if(i%2==0){
            Curr->data -= userValue;
        }
        else{
            Curr->data -= rand()%6;
        }
        Curr = Curr->head;
        i++;
    }

    Curr = Beg;
    end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "\n--------------------------------------------------------------\n";
    cout << "Duration of operation in list: " << end - start << "ns\n";
    cout << "--------------------------------------------------------------\n";
    PrintList(Curr);
    delete [] arr;
    DeleteList(Beg);

}

int main() {
    int cycleMain;
//    bool isListExist = false;
//    List = CreateList();

    int userChoiceIdz;
    while(true) {
        cout << "\n-------------------------------------\n";
        cout << "0 - Start Individual home task #9\n1 - Start main program";
        cout << "\n-------------------------------------\n";
        while (!(cin >> userChoiceIdz)) {
            cout << "\nInvalid Input\n";
        }

        if (!userChoiceIdz) {
            int *arr = CreateArray();
            list *List = 0;
            List = CreateList();
            list *Curr = List;
            list *Beg = List;
            PrintArray(arr, GetListLength(Beg));
            Beg = List;
            PrintList(Beg);
            ComparsionIdz(Curr, arr, GetListLength(Beg));
            Beg = List;

//            Sleep(10000);
        } else {
            list *List = 0;
            list *Curr = List;
            getchar();
            system("cls");
            while (true) {
                cout << "Choose the command:\n1 - Create list\n2 - Print list\n3 - Add new item\n4 - Get item\n5 - Swap items\n6 - Delete item\n0 - Exit\n";
                cin >> cycleMain;
                if (!cycleMain) {
                    DeleteList(List);
                    return 0;
                }
                if (cycleMain == 1) {
                    List = CreateList();
//            isListExist = true;
                    Curr = List;
                    PrintList(Curr);
                } else if (List) {
                    switch (cycleMain) {
                        case 2:
                            PrintList(Curr);
                            break;

                        case 3:
                            InsertItem(Curr);
                            PrintList(Curr);
                            break;
                        case 4:
                            GetItem(Curr);
                            break;
                        case 5:
                            swapItem(Curr);
                            PrintList(Curr);
                            break;

                        case 6:
                            DelItem(Curr);
                            PrintList(Curr);
                            break;
                        default:
                            cout << "\n--------------------------------------------------------------\n";
                            cout << "Error, unknown command";
                            cout << "\n--------------------------------------------------------------\n";
                            break;
                    }
                } else {
                    cout << "\n--------------------------------------------------------------\n";
                    cout << "Error, the list is empty. You have to create list before any operations!";
                    cout << "\n--------------------------------------------------------------\n";
                }


            }
        }
    }

}
