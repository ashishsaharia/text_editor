#pragma once
#include "./stringDoublyLinkedList.h"
 

class LineList
{
    // private:
    
    public:
    LineList* next;
    LineList* prev;
    int lineNo;
    Node* head; 
    unsigned int noOfCols; 

    LineList() = default; 
    LineList(unsigned int lineNo, Node* head, LineList * prev , LineList* next);

    ~LineList();
    bool insertNode( Node * nodePtr , int pos );
    bool deleteNode(int pos );

    

};