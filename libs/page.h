#pragma once

#include <SFML/Graphics.hpp>

// the height and weidth for a a4 paper is 
#define WIDTH 595
#define HEIGHT 842



class Page : public sf :: Drawable
{
private:

    int pageNo;
    int width = WIDTH;
    int height = HEIGHT ; 
    int color[4];  // maybe i dont need this as there is already a way to set color to the sprities/ shapes. 
    
    int leftMargin , rightMargin, topMargin, bottomMargin; 
    // int footerLength ;
    // int headerLenght; 
    // int currentFilledTill; 

    
public:
    sf::RectangleShape page;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool setPageNo(int number);
    int  getPageNo();
    int getHeight();
    int getWidth();


    int getLeftMargin();
    bool setLeftMargin(int leftMargin);
    int getRightMargin();
    bool setRightMargin(int rightMargin);
    int getTopMargin();
    bool setTopMargin(int topMargin );
    int getBottomMargin();
    bool setBottomMargin(int bottomMargin);
    // int getFotterLength();
    // bool setFotterLength(int footerLength);
    // int getHeaderLenght();
    // bool setHeaderLenght(int headerLenght);
    
    Page(int pageNumber);

    void build(); // this will set the widht, height and the color of the page including the margins 

    Page();
    ~Page();
};

 


