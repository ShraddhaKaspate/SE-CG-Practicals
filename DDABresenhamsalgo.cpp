#include <iostream> 
#include <graphics.h> 
#include <math.h> 
using namespace std; 
 
class pixel { 
    int x1, y1, x2, y2, x, y, dx, dy, len; 
public: 
    void dda(int x1, int y1, int x2, int y2, int col, int ch); 
}; 
 
void pixel::dda(int x1, int y1, int x2, int y2, int col, int ch) { 
    float x, y, dx, dy; 
    int len; 
 
    dx = x2 - x1; 
    dy = y2 - y1; 
 
    if (abs(dx) > abs(dy)) { 
        len = abs(dx); 
    } else { 
        len = abs(dy); 
    } 
 
    dx = (x2 - x1) / (float)len; 
    dy = (y2 - y1) / (float)len; 
 
    x = x1; 
    y = y1; 
 
    putpixel(x, y, col); 
 
    int i; 
    int count = 4; 
    switch (ch) { 
        case 1:  // Normal Line 
            i = 1; 
            while (i <= len) { 
                x = x + dx; 
                y = y + dy; 
                putpixel(x, y, col); 
                i++; 
            } 
            break; 
 
        case 2:  // Dotted Line 
            i = 1; 
            while (i <= len) { 
                x = x + dx; 
                y = y + dy; 
                if (i % 3 == 0) {  // Dots every third pixel 
                    putpixel(x, y, col); 
                } 
                i++; 
            } 
            break; 
 
        case 3:  // Dashed Line 
            i = 1; 
            while (i <= len) { 
                x = x + dx; 
                y = y + dy; 
                if (i % 5 < 3) {  // Dashes of length 3 
                    putpixel(x, y, col); 
                } 
                i++; 
            } 
            break; 
 
        case 4:  // Dash Dot Dash Line 
            i = 1; 
            while (i <= len) { 
                x = x + dx; 
                y = y + dy; 
                if (i % 10 < 4 || (i % 10 == 8)) {  // Dash for 4 pixels, then dot 
                    putpixel(x, y, col); 
                } 
                i++; 
            } 
            break; 
 
        case 5:  // Thick Line 
            i = 1; 
            while (i <= len) { 
                x = x + dx; 
                y = y + dy; 
                putpixel(x, y, col); 
                putpixel(x, y + 1, col);  // Adding a second line for thickness 
                i++; 
            } 
            break; 
 
        default: 
            cout << "Invalid choice\n"; 
            break; 
    } 
} 
 
int main() { 
    pixel p; 
    int gd = DETECT, gm, ch; 
    initgraph(&gd, &gm, NULL); 
 
    do { 
        cout << "\n1. Normal Line\n2. Dotted Line\n3. Dashed Line\n4. Dash Dot Dash 
Line\n5. Thick Line\nEnter your choice: "; 
        cin >> ch; 
 
        switch (ch) { 
            case 1: p.dda(100, 100, 500, 100, 1, 1); break; 
            case 2: p.dda(100, 130, 500, 130, 2, 2); break; 
            case 3: p.dda(100, 160, 500, 160, 3, 3); break; 
            case 4: p.dda(100, 190, 500, 190, 4, 4); break; 
            case 5: p.dda(100, 220, 500, 220, 5, 5); break; 
            case 6: cout << "Exiting...\n"; break; 
            default: cout << "Invalid choice\n"; break; 
        } 
 
    } while (ch != 6); 
 
    delay(10000); 
    closegraph(); 
 
    return 0; 
}