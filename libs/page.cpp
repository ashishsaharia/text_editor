#include "./page.h"
#include <iostream>

Page::Page()
{
    build();
}

Page ::Page(int pageNumber)
{
    setPageNo(pageNumber);
    build();
    setBottomMargin(50);
    setTopMargin(50);
    setLeftMargin(50);
    setRightMargin(50);
}

Page ::~Page()
{
    std::cout << "the page " << pageNo << " has been deleted" << std::endl;
}

bool Page::setPageNo(int number)
{
    try
    {
        this->pageNo = number;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Cannot update the page number: " << e.what() << std::endl;
        return false;
    }
}

void Page::build()
{
    page.setSize(sf::Vector2f(WIDTH, HEIGHT));

    if (pageNo == 1)
    {
        page.setPosition(sf::Vector2f(WIDTH / 2, ((pageNo - 1) * HEIGHT + 100)));
    }
    else
    {
        std::cout << "building page no " << pageNo << std::endl;
        page.setPosition(sf::Vector2f(WIDTH / 2, (pageNo - 1) * (HEIGHT + 20) + 100)); // here the hundred is for the offset due to the utility bar space.
    }
    page.setFillColor(sf::Color::White);
}

void Page::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(page);
}

int Page ::getHeight()
{
    return height;
}

int Page ::getWidth()
{
    return width;
}

int Page ::getLeftMargin()
{
    return leftMargin;
}
int Page ::getRightMargin()
{
    return rightMargin;
}

int Page ::getTopMargin()
{
    return topMargin;
}
int Page ::getBottomMargin()
{
    return bottomMargin;
}

bool Page ::setLeftMargin(int leftMargin)
{
    try
    {
        this->leftMargin = leftMargin;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "cannot set the left margin" << std::endl;
        return false;
    }
    return true;
}

bool Page ::setTopMargin(int topMargin)
{
    try
    {
        this->topMargin = topMargin;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "cannot set the top margin" << std::endl;
        return false;
    }
    return true;
}

bool Page ::setRightMargin(int rightMargin)
{
    try
    {
        this->rightMargin = rightMargin;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "cannot set the right margin" << std::endl;
        return false;
    }
    return true;
}

bool Page ::setBottomMargin(int bottomMargin)
{
    try
    {
        this->bottomMargin = bottomMargin;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << "cannot set the bottom margin" << std::endl;
        return false;
    }
    return true;
}

int Page ::getPageNo()
{
    return pageNo;
}