#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class LocalText : public  sf::Text 
{
    private:

    
    //dont know why but this mehtod is not working . 
    //  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
    void draw(sf::RenderWindow& window) const;

    // virtual void draw(sf-::RenderTarget& target, sf::RenderStates states) const;
    // if there is a pure virutal function that always declare it else there will be error and the compiler cannot find the virtual table for the program. 
    // sf::Vector2f textWidth;  
    std::string  stringChar; 
    sf::String chars; 
    sf::Text text ; 

    LocalText(std::string stringChar, int xPos , int yPos , sf::Font& font , int fontSize , int lineSpacing, sf::Color fontColor); 

    ~LocalText();
    LocalText();
    LocalText(  LocalText& temp ) ;
    LocalText(LocalText&&) = default;   // dont know about this understand it.  

};

