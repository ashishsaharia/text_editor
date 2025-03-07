#include "./text.h"
#include <string>
#include <vector> 
#include <SFML/Graphics.hpp>
#include <iostream> 


//this method is not working. Dont know why 
// void LocalText :: draw(sf::RenderTarget& target,sf:: RenderStates states) const
// {
//     target.draw(text);
//     return ; 
// }

// constructor 

LocalText :: LocalText (std::string stringChar , int xPos , int yPos , sf::Font& font, int fontSize, int lineSpacing, sf::Color fontColor )
{
    chars.insert(0,sf::String(stringChar));
    text.setPosition(xPos , yPos);
    text.setFont(font);
    text.setString(chars);
    text.setCharacterSize(fontSize);
    text.setLineSpacing(lineSpacing);
    text.setFillColor(fontColor);
    //figure how to get the widht of the chars that are in the text
   //  textWidht = static_cast<sf::Vector2f> (chars.getSize());
     
}
 void LocalText ::  draw(sf::RenderWindow& window) const {
        window.draw(text);
 }

 LocalText :: ~LocalText()
 {
    std::cout<<"text has been destoryed "<<std::endl ;
    return ; 
 }
 LocalText :: LocalText(){
    return ;
 };

LocalText :: LocalText(LocalText& temp ) 
{
   stringChar = temp.stringChar;
   chars = temp. chars; 
   text = temp.text;
}