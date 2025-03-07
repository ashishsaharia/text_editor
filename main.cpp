

#include <SFML/Graphics.hpp>
#include "./libs/page.h"
#include <vector>
#include <iostream>
#include "./libs/scrollBar.h"
#include "./libs/text.h"
#include <math.h>

#define WINDOW_HEIGHT 900
#define WINDOW_WIDHT 1300

//this is to get the closest position of the text to place the blinking line.

// sf::Vector2f getClosestPos(float textWidth, float textHeight, sf::Vector2f& mousePos)
// {   
//     int leftMod = static_cast<int>(mousePos.x ) % static_cast<int> (textWidth); 
//     int rightMod = static_cast<int> (mousePos.x + textWidth) % static_cast<int> (textWidth);
//     if(leftMod > rightMod)
//     {
//         return sf::Vector2f(mousePos.x + rightMod, mousePos.y); 
//     }
//     else if(rightMod > leftMod)
//     {
//        return sf::Vector2f(mousePos.x - leftMod, mousePos.y); 
//     }
//     else
//         return sf::Vector2f(mousePos.x - leftMod , mousePos.y);
// }



void setBlinkingLineCordPos(float& xPos , float& yPos , const int& xIndex , const int& yIndex, const sf::Vector2f& textBoxPos, const int& fontHeight, const float& fontWidth )
{
    xPos = static_cast<float> (xPos + fontWidth);
    yPos = static_cast<float> ((yIndex*fontHeight) + textBoxPos.y); 
    return ; 
}



int count = 0;
int main()
{

    int blinkingLineIndexX = 0 , blinkingLineIndexY ; 
    blinkingLineIndexY = 0 ; 
    float blinkingLineXpos = 0; 
    float blinkingLineYpos = 0; 

    bool isCursorAcitve = false;
    bool isFocusOnPage = false;
    size_t blinkingLineOnPage = 0;
    sf ::Clock clock;
    int blinkingCursorWidth = 1;
    float blinkingCursorLenght = 20;

    sf::RectangleShape blinkingLine(sf::Vector2f(blinkingCursorWidth, blinkingCursorLenght));
    blinkingLine.setFillColor(sf::Color::Black);

    bool blinkingLineVisible = true;

    sf::Cursor cursor;

    sf::Font font;
    if (!font.loadFromFile("../res/Arial.ttf"))
        return EXIT_FAILURE;
    else
        std::cout << "the font has been loaded" << std::endl;

    std::string firstSentence = "";
    int fontSize = 14;
    int lineSpacing = 1;

    size_t pageCount = 1;

    std::vector<Page> pages; // this is the vector of pages that can be dynamically changed . also dont put the size of the vector in advance as it is also resluting to unexpected position of hte page.
    // pages.resize(10);  note  - this resize is having some wierd  behavior as it is chaging the position of the pages unexpectedly.

    for (int a = 0; a < 5; a++)
        pages.emplace_back((pageCount++)); // emplace back was used because it does not make a copy of the object that is to be pushed back onto the vector
    // therefore is more fast and does not waste memory

    // creatting the bounds for each page

    std::vector<LocalText> texts;

    for (int a = 0; a < pages.size(); a++)
    {
        LocalText tempText(firstSentence, pages[a].page.getPosition().x + pages[a].getLeftMargin(), pages[a].page.getPosition().y + pages[a].getTopMargin(), font, fontSize, lineSpacing, sf::Color ::Black);

        texts.emplace_back(tempText);
    }

    std::vector<sf::FloatRect> textBounds; // this is the array that will store the text  bounds of each page.

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDHT, WINDOW_HEIGHT), "GRANTH");

    sf::Vector2u windowSize = window.getSize();

    int windowWidht = windowSize.x;
    int windowHeight = windowSize.y;

    sf::View view(sf::Vector2f(windowWidht / 2, windowHeight / 2), sf::Vector2f(windowWidht, windowHeight));

    Scrollbar scrollbar; // this is the scroll bar that contains the track as well as the thumb.
    sf::Vector2f scrollbarThumbPosition = scrollbar.scrollbarThumb.getPosition();

    window.setView(view); // dont know why i am setting the view here.
    // std::cout << pages.size) << std::endl;

    sf::Vector2i mousePos = sf::Mouse::getPosition(); // Get mouse position relative to the window
    sf::FloatRect scrollbarBounds = scrollbar.scrollbarThumb.getGlobalBounds();

    window.setFramerateLimit(60); // set the frame rate of the application to 30

    sf::String currentString;

    sf::Glyph glyph = font.getGlyph('a', fontSize, false);
    float fontWidht = glyph.advance;


    // blinkingLine.setPosition( sf::Vector2f (   window.mapCoordsToPixel(texts[0].text.getGlobalBounds().getPosition())));
    blinkingLineXpos = texts[0].text.getPosition().x;
    blinkingLineYpos = texts[0].text.getPosition().y;

    // blinkingCursorLenght = fontSize; 
    while (window.isOpen())
    {
        // std::cout << isFocusOnPage << std::endl;

        textBounds.clear();
        for (auto &a : texts)
        {
            // sf::Vector2i textWindowBounds = window.mapCoordsToPixel(a.text.getGlobalBounds().getPosition(), view);
            textBounds.push_back(a.text.getGlobalBounds());
        }
        // blinkingCursorLenght = texts[blinkingLineOnPage].text.getCharacterSize() + texts[blinkingLineOnPage].text.getCharacterSize() /3 ;
        blinkingCursorLenght = fontSize;
        blinkingLine.setSize(sf::Vector2f(blinkingCursorWidth, blinkingCursorLenght));

        bool cursorOnText = false;

        if (clock.getElapsedTime().asMilliseconds() > 500)
        {
            blinkingLineVisible = !blinkingLineVisible;
            clock.restart();
        }
        float scrollDelta = 0;
        float viewDelta = 0;
        sf::Event event;

        while (window.pollEvent(event))
        {

            blinkingLine.setPosition(sf::Vector2f(blinkingLineXpos, blinkingLineYpos));
            // don't need to update the position here 
            // blinkingLine.setPosition(texts[blinkingLineOnPage].text.getPosition() + sf::Vector2f(texts[blinkingLineOnPage].text.getGlobalBounds().getSize().x, 0) + sf::Vector2f(2, 0));

            mousePos = sf::Mouse::getPosition(window);

            scrollbarThumbPosition = scrollbar.scrollbarThumb.getPosition();

            if (!isFocusOnPage)
            {

                if (scrollbarThumbPosition.y < 0)
                {
                    scrollbar.scrollbarThumb.setPosition(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), 0);
                }
                else if (scrollbarThumbPosition.y > WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight())
                {
                    scrollbar.scrollbarThumb.setPosition(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight());
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                {
                    std::cout << "the down key is pressed " << std::endl;
                    scrollbar.scrollbarThumb.move(sf::Vector2f(0, 8));
                    scrollDelta = scrollbar.scrollbarThumb.getPosition().y / (WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight());
                    viewDelta = ((pages.size() * (pages[0].getHeight()))) * scrollDelta;
                    view.move(sf::Vector2f(0, (-view.getCenter().y + viewDelta + windowHeight / 2)));
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                {
                    scrollbar.scrollbarThumb.move(sf::Vector2f(0, -8));
                    scrollDelta = scrollbar.scrollbarThumb.getPosition().y / (WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight());
                    viewDelta = ((pages.size() * (pages[0].getHeight()))) * scrollDelta;
                    view.move(sf::Vector2f(0, (-view.getCenter().y + viewDelta + windowHeight / 2)));
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    bool clickedOnPage = false ; 
                    // this is to check on which page the mouse was clicked and also the position where the mouse was clicked.
                    for (auto &a : pages)
                    {
                        sf::Vector2i pageWindowBounds = window.mapCoordsToPixel(a.page.getPosition(), view);
                        if ((mousePos.x >= pageWindowBounds.x) && (mousePos.x <= (pageWindowBounds.x + a.getWidth())) && ((mousePos.y >= pageWindowBounds.y) && (mousePos.y <= (pageWindowBounds.y + a.getHeight()))))
                        {
                            clickedOnPage = true ;
                            isCursorAcitve = true;
                            isFocusOnPage = true;
                            blinkingLineOnPage = a.getPageNo() - 1; //-1 because the page starts from 1.
                            break;
                        }
                    }
                    if (!clickedOnPage)
                    {
                        isCursorAcitve = false;
                        isFocusOnPage = false;
                    }
                    
                    std::cout<<"is cursor active "<<isCursorAcitve<<std::endl;
                    std::cout <<"is focus on page " <<isFocusOnPage<<std::endl;
                    // set the width of the blinkingLine according to the text.
                    //  for(auto & a : texts)
                    //  {
                    //      std::cout<< "the lenght of the text  is "<< a.text.getGlobalBounds().getSize().y<<std::endl;
                    //  }
                    scrollbarBounds = scrollbar.scrollbarThumb.getGlobalBounds();
                    // Check if mouse position is within scrollbar bounds
                    if (scrollbarBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        scrollbar.setScrollbarClicked(true);

                        if (scrollbarThumbPosition.y < 0)
                        {
                            scrollbar.scrollbarThumb.setPosition(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), 0);
                        }
                        else if (scrollbarThumbPosition.y > WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight())
                        {
                            scrollbar.scrollbarThumb.setPosition(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight());
                        }
                        else
                        {
                            scrollbar.scrollbarThumb.setPosition(sf::Vector2f(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), mousePos.y - scrollbar.getScrollBarThumbHeight() / 2));
                        }

                        scrollDelta = scrollbar.scrollbarThumb.getPosition().y / (WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight());
                        viewDelta = ((pages.size() * (pages[0].getHeight()))) * scrollDelta;
                        view.move(sf::Vector2f(0, (-view.getCenter().y + viewDelta + windowHeight / 2)));

                        // std::cout << "the scroll delta is " << scrollDelta << std::endl;
                        // std::cout << "the view delta is " << viewDelta << std::endl;

                        // for (auto &a : texts)
                        // {
                        //     textBounds.push_back(a.text.getGlobalBounds());
                        // }
                    };
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    scrollbar.setScrollbarClicked(false);
                }
            }

            if (scrollbar.isScrollbarClicked())
            {
                if (scrollbarThumbPosition.y < 0)
                {
                    scrollbar.scrollbarThumb.setPosition(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), 0);
                }
                else if (scrollbarThumbPosition.y > WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight())
                {
                    scrollbar.scrollbarThumb.setPosition(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight());
                }
                else
                {
                    scrollbar.scrollbarThumb.setPosition(sf::Vector2f(WINDOW_WIDHT - scrollbar.getScrollBarThumbWidht(), mousePos.y - scrollbar.getScrollBarThumbHeight() / 2));
                }
                scrollDelta = scrollbar.scrollbarThumb.getPosition().y / (WINDOW_HEIGHT - scrollbar.getScrollBarThumbHeight());
                viewDelta = (pages.size() * (pages[0].getHeight())) * scrollDelta;
                view.move(sf::Vector2f(0, (-view.getCenter().y + viewDelta + windowHeight / 2)));

                // for (auto &a : texts)
                // {
                //     textBounds.push_back(a.text.getGlobalBounds());
                // }
            }

            for (auto &a : textBounds)
            {
                sf::Vector2i windowTextPosition = window.mapCoordsToPixel(a.getPosition(), view);

                if ((mousePos.x >= windowTextPosition.x) && (mousePos.x <= (windowTextPosition.x + a.getSize().x)) && ((mousePos.y >= windowTextPosition.y) && (mousePos.y <= (windowTextPosition.y + a.getSize().y))))
                {
                    // std::cout<<"true "<<count++<<std::endl;
                    if (cursorOnText)
                        continue;
                    cursor.loadFromSystem(sf::Cursor::Text);
                    cursorOnText = true;
                    window.setMouseCursor(cursor);
                    // std::cout << "the cursor is on the text " << std::endl;
                }
            }
            if (!cursorOnText)
            {
                cursor.loadFromSystem(sf::Cursor::Arrow);
                window.setMouseCursor(cursor);
            }

            // if(!cursorOnText)
            // {
            //     cursor.loadFromSystem(sf::Cursor::Arrow);
            //     window.setMouseCursor(cursor);

            // }

            if (isCursorAcitve && event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {   
                    const LocalText& tempText  = texts[blinkingLineOnPage]; 
                    currentString = texts[blinkingLineOnPage].chars;
                    size_t currentStringSize = currentString.getSize();
                    float currentCharWidht = 0 ; 
                    if (event.text.unicode == 8)
                    {
                        if (!currentString.isEmpty()){
                            currentCharWidht = font.getGlyph(currentString[currentStringSize-1],fontSize,false).advance;
                            currentString.erase(currentStringSize - 1, 1);
                            blinkingLineIndexX-- ; 
                            setBlinkingLineCordPos(blinkingLineXpos,blinkingLineYpos,blinkingLineIndexX,blinkingLineIndexY,textBounds[blinkingLineOnPage].getPosition(),fontSize + 2*(lineSpacing),-currentCharWidht);

                        }
                    }
                    else if (event.text.unicode == 13)
                    { // Enter key (optional: handle differently)
                        currentString.insert(currentStringSize, '\n');
                        blinkingLineIndexY++;
                        setBlinkingLineCordPos(blinkingLineXpos,blinkingLineYpos,blinkingLineIndexX,blinkingLineIndexY,textBounds[blinkingLineOnPage].getPosition(),fontSize + 2*(lineSpacing),0);
                        // blinkingLineXpos = window.mapCoordsToPixel(tempText.getPosition()).x;
                        blinkingLineXpos = textBounds[blinkingLineOnPage].getPosition().x;
                        // blinkingLineXpos = 500;

                    }
                    else
                    {
                        currentCharWidht = font.getGlyph(static_cast<char>(event.text.unicode),fontSize,false).advance;
                        currentString.insert(currentStringSize, static_cast<char>(event.text.unicode));
                        blinkingLineIndexX++;
                        setBlinkingLineCordPos(blinkingLineXpos,blinkingLineYpos,blinkingLineIndexX,blinkingLineIndexY,textBounds[blinkingLineOnPage].getPosition(),fontSize + 2*(lineSpacing),currentCharWidht);

                    }
                    texts[blinkingLineOnPage].chars = currentString;
                    texts[blinkingLineOnPage].text.setString(currentString);
                }
            }
            blinkingLine.setPosition(sf::Vector2f(blinkingLineXpos, blinkingLineYpos));
        }

        // std::cout << isCursorAcitve << std::endl;
        window.clear();

        window.setView(view);

        // Draw all the page
        for (const auto &page : pages)
        {
            window.draw(page);
        }

        for (auto &a : texts)
        {
            a.draw(window);
        }

        if (isCursorAcitve)
        {
            if (blinkingLineVisible)
            {
                window.draw(blinkingLine);
            }
        }

        // text.draw(window);

        window.setView(view);
        // if you draw anything after this get defalut view that it will be drawn independent of the view and will remain static.
        window.setView(window.getDefaultView());
        window.draw(scrollbar);

        window.display();
    }
    return 0;
}