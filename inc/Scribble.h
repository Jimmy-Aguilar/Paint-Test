#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include <Shape.h>
#include <GL/freeglut.h>
#include <vector>
#include <utility>
#include <algorithm>


class Scribble : public Shape {
    std::vector<std::pair<float,float>> pts;

public:
    Scribble(Color color);

    void addPoint(float px, float py);

    bool empty() const;

    void draw() const override;

    bool contains(float _x, float _y) const override;

    void resize(float factor) override;

    void setX(float _x) override;
    void setY(float _y) override;

    ~Scribble();
};

#endif