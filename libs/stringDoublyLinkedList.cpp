#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/System/String.hpp>
#include "./stringDoublyLinkedList.h"

Node :: ~Node()
{
    next = nullptr;
    prev = nullptr; 
    std::cout<<"the text node has been deleted"; 
    return; 
}

Node :: Node(const sf::String& string , const sf::Font & font, unsigned int charSize, Node* next , Node* prev, unsigned int colNo) 
{
    this-> colNo = colNo;
    this->next = next; 
    this->prev = prev;
}

Node :: Node(Node & temp)
{
    next = temp.next;
    prev = temp.prev;
}

Node :: Node()
{
    next = nullptr; 
    prev = nullptr;
}
