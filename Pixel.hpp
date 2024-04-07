
#ifndef PIXEL
#define PIXEL

class Pixel
{
private:

public:

    // Color
    unsigned char R;
    unsigned char G;
    unsigned char B;

    // For intermediate calculations
    bool IsIncluded;

	Pixel();

	Pixel(char r, char g, char b);

    void operator =(Pixel value);
};

#endif // PIXEL
