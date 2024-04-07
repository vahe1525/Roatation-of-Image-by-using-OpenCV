
// Project libraries
#include "Pixel.hpp"

Pixel::Pixel()
    : R(255)
    , G(255)
    , B(255)
    , IsIncluded(false)
{
}

Pixel::Pixel(char r, char g, char b)
    : R(r)
    , G(g)
    , B(b)
{
}

void Pixel::operator =(Pixel value)
{
    this->R = value.R;
    this->G = value.G;
    this->B = value.B;
}
