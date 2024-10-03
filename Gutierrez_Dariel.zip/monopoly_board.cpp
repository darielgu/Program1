#include <iostream>
#include <string>
using namespace std;
// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;
    MonopolyBoard(){
        propertyName="Unknown";
        propertyColor = "None";
        value = 0;
        rent = 0;
    }
    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
/*Define overloaded constructor here*/
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value =value;
        this->rent = rent;
    }
    bool isEqual(MonopolyBoard other) {
/*Define is equal here*/
return(propertyName == other.propertyName && propertyColor == other.propertyColor
       && value == other.value && rent == other.rent);
    }
    void print() {
/*Define Print Here*/
cout<< propertyName <<" - Property Name, "<<propertyColor<<" - Property Color, "<<
    value<<" - value, "<<rent<< " - rent,"<< endl;
    }
};
// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;
    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};
// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;
public:
    CircularLinkedList() {
        headNode = nullptr;
    }
// Mandatory Tasks
    void insertAtHead(T value) {

        Node<T>* newNode = new Node<T>(value); // creates a new node
        if(headNode == nullptr) { //If the list is empty set node to head
            headNode = newNode;
            newNode->nextNode = headNode;
        }else {
            Node<T> *temp = headNode; //make a temp node to traverse
            while (temp->nextNode != headNode) { //traverses through looking for head
                temp = temp->nextNode;
            }
            newNode->nextNode = headNode;
            temp->nextNode = newNode;
            // Update the headNode to the new node
            headNode = newNode;
        }
    }
    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if(headNode == nullptr) {
            headNode = newNode;
            newNode->nextNode = newNode;
        }else{
            Node<T>* temp = headNode;
            while(temp->nextNode != headNode){
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
            newNode->nextNode = headNode;
            tailNode = newNode;
        }
    }
    void insertAtPosition(T value, int position) {
        Node<T>* newNode = new Node<T>(value);
        if (position <= 0) {
            cout << "Invalid position. Position must be greater than 0." << endl;
            return;
        }
        if ( position == 1) {
            insertAtHead(value);
            return;
        } else if (headNode == nullptr) {
            cout << "List is empty, cannot insert at that position." << endl;
            return;
        }

        Node<T>* temp = headNode;
        int count = 1;

        while (count < position - 1 && temp->nextNode != headNode) {
            temp = temp->nextNode;
            count++;
        }

        if (count == position - 1) {
            newNode->nextNode = temp->nextNode;
            temp->nextNode = newNode;
        } else {
            cout << "Position out of bounds." << endl;
        }
    }
    void deleteAtHead() {
        if(headNode== nullptr){ // if board is empty
            cout << "List already empty nothing to delete";
            return;
        }
        if(headNode->nextNode == headNode){// if there is only one element in board
            delete headNode;
            headNode= nullptr;
            return;
        }
        Node<T>* temp = headNode;
        while (temp-> nextNode != headNode){
            temp = temp->nextNode;
        }
        Node<T>* toDelete = headNode;
        temp-> nextNode = headNode->nextNode;
        headNode= headNode->nextNode;
        delete toDelete;
    }
    void deleteAtTail() {
        if(headNode== nullptr){ // if board is empty
            cout << "List already empty nothing to delete";
            return;
        }
        if(headNode->nextNode == headNode){ // if only one node in
            delete headNode;
            headNode= nullptr;
            return;
        }
        Node<T>* temp = headNode;
        while(temp-> nextNode->nextNode != headNode){
            temp= temp->nextNode;
        }
        Node<T>* toDelete = temp->nextNode;
        temp->nextNode = headNode;
        delete toDelete;
    }
    void deleteAtPosition(int pos) {
        if(headNode == nullptr){
            cout<<"Nothing to delete";
            return;
        }
        if(pos ==1){
            deleteAtHead();
            return;
        }
        Node<T>* temp = headNode;
        int count = 1;
        while(count <pos-1 && temp->nextNode!= headNode){
            temp = temp->nextNode;
            count++;
        }
       if(temp->nextNode == headNode||count!= pos-1){
           cout<<"Position non existent"; return;
       }
       Node<T>* todelete = temp->nextNode;
       temp->nextNode = todelete->nextNode;
       delete todelete;

    }
    void search(string propertyName) {
        if(headNode == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node<T>* temp = headNode;
        while (temp->nextNode != headNode) {
            if (temp->data.propertyName == propertyName) {
                temp->data.print();
                return;
            }
            temp = temp->nextNode;
        }
        if (temp->data.propertyName == propertyName) {
            temp->data.print();
            return;
        }
        cout << "Property not found in the list." << endl;
    }

    void printList() {

        if(headNode == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node<T>*  temp = headNode;
        do{temp-> data.print();
            temp = temp->nextNode;
            cout<<endl;}
        while(temp!= headNode);
    }
//Optional Tasks
//Basic Funtions
    void reverseCLList() {
        if(headNode == nullptr || headNode->nextNode == headNode){
            cout<<"Nothing to reverse";
            return; //edge case
        }
        Node<T>* prev = nullptr;
        Node<T>* curr = headNode;
        Node<T>* nextNode = nullptr;
        Node<T>* tail = headNode;
        do{ //do while needed to start loop without failure
            nextNode = curr->nextNode;
            curr->nextNode = prev;
            prev=curr;
            curr = nextNode;
        }
        while(curr!= headNode);

        tail->nextNode = prev;
        headNode = prev;
    }
    void sortCLList() {
        if(headNode == nullptr || headNode->nextNode == headNode){
            cout<<"Nothing to sort";
            return;
        }
        bool swap = true;
        Node<T>* temp;
        Node<T>* nextNode ;
        T tempData;
        while(swap){
            swap = false;
            temp = headNode;
            while (temp->nextNode != headNode){
                nextNode = temp->nextNode;
                if(temp->data.propertyName > nextNode->data.propertyName ){
                    tempData = temp->data;
                    temp->data = nextNode->data;
                    nextNode->data = tempData;
                    swap = true;
                }
                temp = temp->nextNode;
            }
        }


    } void printHeadNode() {
        if(headNode == nullptr){
            cout<<"No head node in list"<<endl;
        }else{
            cout<<"Head Node: ";
            headNode->data.print();
        }
    }
    void printLastNode() {
    if(headNode== nullptr){
        cout<<"No Nodes in list"<<endl;
        return;
    }else if(headNode->nextNode == headNode){
        cout<<"Tail node: ";
        headNode->data.print();
        return;
    }
    Node<T>* temp = headNode;
    while(temp->nextNode != headNode){
        temp = temp->nextNode;
    }
    cout<<"Last Node: ";
    temp->data.print();

    }
    void isListEmpty() {
        if(headNode == nullptr){
            cout<<"The list is empty"<<endl;
        }else{
            cout<<"The list is not empty"<<endl;
        }
    }
    void countNodes() {
        if(headNode == nullptr){
            cout<<"There are 0 Nodes"<<endl;
            return;
        }else if(headNode->nextNode == headNode) {
            cout << "There is 1 Node"<<endl;
            return;
        }
        Node<T>* temp = headNode;
        int count = 1;
        while(temp->nextNode != headNode){
            temp = temp->nextNode;
            count++;
        } cout<< "There are "<<count<<" Nodes"<<endl;
    }
//Optional Tasks
// Advanced Functions
    void convertCLList() {
        cout << "Convert Circular List Unwritten." << endl;
    } void updateNodeValue() {
        cout << "update Node value unwritten" << endl;
    } void displaySpecificColorNode() {
        cout << "Display Specific color Node" << endl;
    } void mergeCLList() {
        cout << "Merge Circular Linked List Unwritten" << endl;
    }
};
// Main function to demonstrate the LinkedList class
int main() {
// Create a LinkedList of Data objects
    CircularLinkedList<MonopolyBoard> list;

 //Basic Functions
    list.insertAtHead(MonopolyBoard("firstHead", "a", 0, 0));
    list.insertAtTail(MonopolyBoard("Tail","a",0,0));
    list.insertAtPosition(MonopolyBoard("insert1","",0,0),1);
    list.deleteAtHead();
    list.deleteAtTail();
    list.deleteAtPosition(2);

//Optional Basic Tasks
    list.reverseCLList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    list.countNodes();
////Optional Advanced Tasks
//    list.convertCLList();
//    list.updateNodeValue();
//    list.displaySpecificColorNode();
//    list.mergeCLList();


//    list.printList();
    return 0;
}