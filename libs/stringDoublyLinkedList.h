#pragma once 
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/System/String.hpp>

class Node : public sf::Text
{
    public : 
    Node* next;
    Node* prev; 
    unsigned int colNo; 

    // Node() = default;
    Node();
    Node(const sf::String& string , const sf :: Font& font, unsigned int charSize , Node* next , Node* prev , unsigned int colNo )  ;
    Node (Node& temp);
    ~Node();
    // void draw(sf::RenderWindow& window) const; 
};