#include <MLV/MLV_all.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int x = 640;
    int y = 480;
    MLV_create_window("hello world", "hello world", x, y);
    MLV_Color couleur = MLV_create_color(255, 0, 0); // Rouge pur
    MLV_draw_rectangle(100, 100, 50, 30, couleur);
    return 0;
}
