#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
{
	// if y axis overlap
	bool yaxis = rec1[1] >= rec2[3] || rec1[3] <= rec2[1];
	
	//if x axis overlap
	bool xaxis = rec1[0] >= rec2[2] || rec1[2] <= rec2[0];

	return !(yaxis || xaxis);
}