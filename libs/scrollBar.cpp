#include "./scrollBar.h"
#include <iostream>
#include <SFML/Graphics.hpp>

// this si the default constructor

bool Scrollbar::setScrollbarTrackWidht(int widht)
{
    try
    {
        scrollbarTrackWidth = widht;
    }
    catch (const std::exception &e)
    {
        std::cout << "cannot set the widht of the track  " << std::endl;
        return false;
    }
    return true;
}

bool Scrollbar::setScrollbarThumbWidht(int widht)
{
    try
    {
        scrollbarThumbWidth = widht;
    }
    catch (const std::exception &e)
    {
        std::cout << "cannot set the widht of the thumb " << std::endl;
        return false;
    }
    return true;
}

bool Scrollbar::setScrollbarThumbHeight(int height)
{
    try
    {
        scrollbarThumbHeight = height;
    }
    catch (const std::exception &e)
    {
        std::cout << "cannot set the height of the thumb " << std::endl;
        return false;
    }
    return true;
}

int Scrollbar ::getScrollBarThumbHeight()
{
    return scrollbarThumbHeight;
}

int Scrollbar ::getScrollBarThumbWidht()
{
    return scrollbarThumbWidth;
}

int Scrollbar ::getScrollBarTrackWidth()
{
    return scrollbarTrackWidth;
}

Scrollbar ::Scrollbar()
{
    if (!setScrollbarTrackWidht(25))
    {
        return;
    }
    if (!(setScrollbarThumbHeight(100)))
    {
        return;
    }
    if (!setScrollbarThumbWidht(25))
    {
        return;
    }

    scrollbarTrack.setSize(sf::Vector2f(static_cast<float>(getScrollBarTrackWidth()), static_cast<float>(WINDOW_HEIGHT)));
    scrollbarThumb.setSize(sf::Vector2f(static_cast<float>(getScrollBarThumbWidht()), static_cast<float>(getScrollBarThumbHeight())));

    scrollbarTrack.setPosition(sf::Vector2f(WINDOW_WIDHT - getScrollBarTrackWidth(), 0));
    scrollbarThumb.setPosition(sf::Vector2f(WINDOW_WIDHT - getScrollBarThumbWidht(), 0));

    scrollbarTrack.setFillColor(sf::Color::Black);
    scrollbarThumb.setFillColor(sf::Color::Blue);
}

void Scrollbar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(scrollbarTrack);
    target.draw(scrollbarThumb);
}

Scrollbar ::~Scrollbar()
{
    std::cout << "the scroll bar has been deleted" << std::endl;
    return;
}

bool Scrollbar ::isScrollbarClicked() const
{
    return scrollbarClicked;
}

void Scrollbar ::setScrollbarClicked(bool val)
{
    scrollbarClicked = val;
}
