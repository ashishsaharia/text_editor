#pragma once 

#include <SFML/Graphics.hpp>


#define WINDOW_HEIGHT 900
#define WINDOW_WIDHT 1300


class Scrollbar : public sf::Drawable
{
   public:

    sf::Vector2f getScrollVelocity() const;
    bool setScrollVelocity(sf::Vector2f velocity);
    bool setScrollbarTrackWidht(int widht);
    bool setScrollbarThumbHeight(int height );
    bool setScrollbarThumbWidht(int widht); 
    int getScrollBarTrackWidth();
    int getScrollBarThumbHeight();
    int getScrollBarThumbWidht();

    bool isScrollbarClicked() const ;

    void setScrollbarClicked( bool val );



    
    Scrollbar();
    ~Scrollbar();

    sf::RectangleShape scrollbarTrack ; // there was no way to access the parent class comps withoout making it public . 
    sf::RectangleShape scrollbarThumb; 
 



   private:
    bool scrollbarClicked = false ; 

    sf::Vector2f scroolVelocity; 
    int scrollbarTrackWidth; 
    int scrollbarThumbWidth; 
    int scrollbarThumbHeight; 
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};