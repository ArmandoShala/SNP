//
// Created by armandoshala on 06.03.22.
//

#include <stdio.h>

int test() {
    enum wochentage {
        Mo, Di, Mi, Do, Fr
    };
    enum wochenendtage {
        Sa = 5, So
    };

    enum frucht {
        Apfel = 10, Birne = 15, Zitrone = 20
    };

    enum wochenendtage w1 = Sa; // Wert 5
    enum wochenendtage w2 = 77; // Funzt, blos keine Zuweisung

    typedef enum {
        Jan, Feb, Mrz, Apr
    } Monate;
    Monate m1 = Jan;

    typedef struct{
        double x;
        double y;
        double z;
    } Point3D;
//    Point3D point3D = ...

    struct point3D {
        double x;
        double y;
        double z;
    };
    struct point3D startPoint = {2.0, 4.0, 6.0};

    typedef struct {
        struct point3D start;
        struct point3D end;
    } line3D;
//    struct line3D line = {startPoint, {1.0, 2.0, 3.0}};
//
//    startPoint.x


}