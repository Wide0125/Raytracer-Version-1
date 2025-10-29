#ifndef LINE_H
#define LINE_H
#include "vector.hpp"
#include "point.hpp"

struct Line {
    Point origin {};
    Vector direction {};
};

constexpr Line XAXIS {ORIGIN, {1, 0, 0}};
constexpr Line YAXIS {ORIGIN, {0, 1, 0}};
constexpr Line ZAXIS {ORIGIN, {0, 0, 1}};

#endif
