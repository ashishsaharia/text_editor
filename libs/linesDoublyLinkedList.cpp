#include "./linesDoublyLinkedList.h"
#include "./stringDoublyLinkedList.h"

LineList ::LineList(unsigned int lineNo, Node *head, LineList *prev, LineList *next)
{
    this->lineNo = lineNo;
    this->head = head;
    this->next = next;
    this->prev = prev;
}

LineList :: ~LineList()
{
    std::cout<<"the line "<<this->lineNo <<" has been deleted. \n";
    return;  
}

bool LineList :: insertNode(Node* nodePtr, int pos)
{
    if(!head)
    {
        head = nodePtr; 
        noOfCols++; 
        return true; 
    }
    
    if(pos == 1)
    {
        nodePtr -> next = head; 
        nodePtr->prev = NULL;
        head->prev = nodePtr; 
        head = nodePtr;
        noOfCols++;
        return true ; 
    }
    if(pos > noOfCols+1 )
    {
        std::cout<<"there are not enough cols to add at this pos \n "; 
        return false; 
    }
    else
    {
        int count = 1 ;
        Node* temp = head ;
        while(count < pos )
        {
            temp = temp->next; 
            count++;
        }
        if(pos == noOfCols + 1)
        {
            temp->next = nodePtr; 
            nodePtr -> prev = temp;
            nodePtr ->next = NULL;
            temp = nullptr; 
            noOfCols++;
            return true; 
        }
        else
        {
            Node* temp1 = temp->next; 
            nodePtr->next = temp1; 
            nodePtr->prev = temp; 
            temp->next = nodePtr; 
            temp1->prev = nodePtr;
            temp = nullptr;
            noOfCols++;
            return true; 
        }

    }
    return false; 
}


bool LineList :: deleteNode(int pos)
{
    if(!head)
    {
        std::cout<<"cannot delete the is empty\n";
        return false; 
    }
    if(pos == 1)
    {
        Node* temp = head; 
        head = head-> next; 
        head->prev = nullptr; 
        delete temp;
        noOfCols-- ;
        return true; 
    }

    if(pos > noOfCols)
    {
        std::cout<<"not enough elemetns to delete from \n";
        return false ; 
    }
    else
    {
        int count =1 ; 
        Node* temp = head; 
        while(count < pos )
        {
            temp = temp->next; 
            count++;
        }
        if(pos == noOfCols)
        {
            temp->prev->next = nullptr;
            delete temp; 
            noOfCols--; 
            return true; 
        }
        else
        {   
            temp->prev->next = temp->next; 
            temp->next->prev = temp->prev;
            delete temp ; 
            noOfCols--;
            return true;
        }
    }
    return false ;
}