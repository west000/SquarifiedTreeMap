#ifndef SquarifiedAlgorithm_H
#define SquarifiedAlgorithm_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math>
#include <io>

using namespace std;

struct ViewRect
{
        float xoffset;
        float yoffset;
        float width;
        float height;

        ViewRect(float x, float y, float w, float h):
                xoffset(x), yoffset(y), width(w), height(h)
        {}

        ViewRect():
                xoffset(0), yoffset(0), width(0), height(0)
        {}
};


class Container
{
public:
        float xoffset;
        float yoffset;
        float width;
        float height;

        Container():
                xoffset(0), yoffset(0), width(0), height(0)
        {}
        
        Container(float x, float y, float w, float h):
                xoffset(x), yoffset(y), width(w), height(h)
        {}
        
        Container cutArea(float area);
        vector< ViewRect > getCoordinates(vector<float>& row);
        float getShortestEdge();
};

float sumArray(const vector<float>& row);
void normalized(vector<float>& dataVec, float area);
void squarify(vector<float>& dataVec, vector<float>& curRow,
        const Container& container, vector< vector<ViewRect> >& stack);
bool isImprovesRatio(const vector<float>& curRow, float nextnode, float length);
float calculateRatio(vector<float>& curRow, int length);
void flattenTreeMap(const vector< vector<ViewRect> >& rawTreeMap, vector<ViewRect>& result);
void getTreeMap(vector<ViewRect>& treemap, vector<float> dataVec,
        float width, float height, float xoffset=0, float yoffset=0);


#endif //! SquarifiedAlgorithm_H

