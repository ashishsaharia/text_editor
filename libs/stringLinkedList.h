#pragma once 
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Node
{
    private:
        size_t nodeNumber; 
        Node* next ;
        sf::Text text;
        // sf::Font& font ; 

    public:
        const sf::Text& getText()
        {
            return text; 
        }

        void setText(std::string str)
        {
            text.setString(str);
            return ; 
        }

        // function to insert in the node

        Node() = default;

        Node (std::string str, sf::Font& font, int fontSize , size_t num)
        {
            std::cout<<"the new text node has been created"<<std::endl; 
            // this->font = font ; 
            this->nodeNumber = num; 
            this->text = sf::Text(str,font, fontSize);
            this->next = nullptr;
        }

        Node (Node& node)
        {
           std::cout << "text node copied "<<std::endl;
            this->nodeNumber = node.nodeNumber;
            this->text = node.text;
            this->next = node.next; 
        }
        Node (Node && other )
        {
            std::cout<<"the text has been moved"<<std::endl;
            this->nodeNumber = std::move(other.nodeNumber);
            this->text = std::move(other.text);
            this->next = std::move(other.next);
            other.next = nullptr; 
            // delete other;  check this later

        }
    };