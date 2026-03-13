#include "coordin.h"
#include <cmath>
#include <iostream>

polar rect_to_polar(rect xypos) {
    using namespace std;
    polar ans;

    ans.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    ans.angle = atan2(xypos.y, xypos.x);
    return ans;
}
void show_polar(polar dapos) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}