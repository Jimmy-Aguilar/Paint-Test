#include <Scribble.h>
#include <cmath>
#include <cfloat>

Scribble::Scribble(Color _color) {
    color = _color;
    x = 0.0f;
    y = 0.0f;
    isSelected = false;
}

void Scribble::addPoint(float px, float py) {
    pts.push_back({px, py});
    x = 0.0f; y = 0.0f;
    for (auto& p : pts) { x += p.first; y += p.second; }
    x /= pts.size(); y /= pts.size();
}

bool Scribble::empty() const { return pts.empty(); }

void Scribble::draw() const {
    if (pts.empty()) return;

    glColor3f(color.r, color.g, color.b);
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        for (auto& p : pts) { glVertex2f(p.first, p.second); }
    glEnd();

    if (isSelected) {
        float minX = pts[0].first,  maxX = pts[0].first;
        float minY = pts[0].second, maxY = pts[0].second;
        for (auto& p : pts) {
            minX = std::min(minX, p.first);  maxX = std::max(maxX, p.first);
            minY = std::min(minY, p.second); maxY = std::max(maxY, p.second);
        }
        float pad = 0.015f;
        glColor3f(0.3f, 0.3f, 0.3f);
        glLineWidth(1.5f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(minX - pad, minY - pad);
            glVertex2f(maxX + pad, minY - pad);
            glVertex2f(maxX + pad, maxY + pad);
            glVertex2f(minX - pad, maxY + pad);
        glEnd();
        glLineWidth(1.0f);
    }
}

bool Scribble::contains(float _x, float _y) const {
    const float r = 0.025f;
    for (auto& p : pts) {
        float dx = _x - p.first;
        float dy = _y - p.second;
        if (dx * dx + dy * dy <= r * r) return true;
    }
    return false;
}

void Scribble::resize(float factor) {
    for (auto& p : pts) {
        p.first  = x + (p.first  - x) * factor;
        p.second = y + (p.second - y) * factor;
    }
    float nx = 0, ny = 0;
    for (auto& p : pts) { nx += p.first; ny += p.second; }
    x = nx / pts.size(); y = ny / pts.size();
}

void Scribble::setX(float _x) {
    float dx = _x - x;
    for (auto& p : pts) { p.first += dx; }
    x = _x;
}

void Scribble::setY(float _y) {
    float dy = _y - y;
    for (auto& p : pts) { p.second += dy; }
    y = _y;
}

Scribble::~Scribble() {}