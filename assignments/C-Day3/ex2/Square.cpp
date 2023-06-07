#include "Square.h"

int Square::numRect = 0;

Square::~Rectangle() {
  numRect--;
  std::cout << "Square Destructor " << this->getColor() << "\n";
}

Square::Square(double w,double w, string color)
  :ColoredShape(color), width(w), width(w)
{
  numRect++;
}

double
Square::getArea(void) {
  return width*width;
}

void 
Square::printArea(std::ostream &s) {
  s << "Square: color: " << this->getColor() << ", area: "
    << width * width << " numRect: " << numRect << "\n";
}

