// rectangle_bounds.cpp

#include "rectangle_bounds.h"
#include <iostream>

namespace StevensDev {
namespace sgds {

RectangleBounds::RectangleBounds() {
    rectX = 0;
    rectY = 0;
    rectWidth = 200;
    rectHeight = 200;
}

RectangleBounds::RectangleBounds( RectangleBounds& otherBounds ) {
    rectX = otherBounds.x();
    rectY = otherBounds.y();
    rectWidth = otherBounds.width();
    rectHeight = otherBounds.height();
}

RectangleBounds::RectangleBounds( float x, float y, float width, float height ) {
    rectX = x;
    rectY = y;
    rectWidth = width;
    rectHeight = height;
}

RectangleBounds::~RectangleBounds() {}

RectangleBounds& RectangleBounds::operator =( const RectangleBounds& otherBounds ) {
    rectX = otherBounds.x();
    rectY = otherBounds.y();
    rectWidth = otherBounds.width();
    rectHeight = otherBounds.height();
}

float RectangleBounds::x() const {
    return rectX;
}

float RectangleBounds::y() const {
    return rectY;
}

float RectangleBounds::width() const {
    return rectWidth;
}

float RectangleBounds::height() const {
    return rectHeight;
}

void RectangleBounds::setX( float x ) {
    rectX = x;
}

void RectangleBounds::setY( float y ) {
    rectY = y;
}

void RectangleBounds::setWidth( float width ) {
    rectWidth = width;
}

void RectangleBounds::setHeight( float height ) {
    rectHeight = height;
}

void RectangleBounds::setDimensions( float width, float height ) {
    rectWidth = width;
    rectHeight = height;
}

void RectangleBounds::setPosition( float x, float y ) {
    rectX = x;
    rectY = y;
}

bool RectangleBounds::doesCollide( const RectangleBounds& candidate ) {
    float candidateX = candidate.x();
    float candidateY = candidate.y();
    float candidateBoundsX = candidate.x() + candidate.width();
    float candidateBoundsY = candidate.y() + candidate.height();
    if( candidateX > rectX && candidateX < rectX + rectWidth )
    {
        if( candidateY > rectY && candidateY < rectY + rectHeight )
        {
            return true;
        }
        else if( candidateY < rectY && rectY < candidateY + candidateBoundsY )
        {
            return true;
        }
    }
    else if( candidateX < rectX && rectX < candidateX + candidateBoundsX )
    {
        if( candidateY > rectY && candidateY < rectY + rectHeight )
        {
            return true;
        }
        else if( candidateY < rectY && rectY < candidateY + candidateBoundsY )
        {
            return true;
        }
    }

    return false;
}

}
}