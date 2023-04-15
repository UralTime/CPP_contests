#include <bits/stdc++.h>
 
using namespace std;
 
const double PI = 3.14159265358979323846;
const double EPS = 1e-8;
const int INF = 1e9 + 50;
 
int sign(double a) {
    if (abs(a) <= EPS) {
        return 0;
    } else if (a > EPS) {
        return 1;
    } else {
        return -1;
    }
}
 
 
struct Point {
    double x;
    double y;
    Point (double a = 0, double b = 0) {
        x = a;
        y = b;
    }
 
};
 
 
struct Vector {
    double x;
    double y;
    Vector (double a = 0, double b = 0) {
        x = a;
        y = b;
    }
    Vector (Point A, Point B) {
        x = B.x - A.x;
        y = B.y - A.y;
    }
    double length() {
        return sqrt(x * x + y * y);
    }
    double length_sqared() {
        return (long long)x * x + (long long)y * y;
    }
};
 
 
struct Line {
    double a;
    double b;
    double c;
    Line (double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }
    Line (Point A, Point B) {
        b = B.x - A.x;
        a = A.y - B.y;
        c = -a * A.x - b * A.y;
    }
    Point GetPoint() {
        double x = - (a * c) / (a * a + b * b);
        double y = - (b * c) / (a * a + b * b);
        return Point(x, y);
    }
};
 
 
struct Circle {
    Point C;
    double r;
    Circle (Point A, double b) {
        C = A;
        r = b;
    }
    Circle (double x, double y, double b) {
        C = Point(x, y);
        r = b;
    }
};
 
 
double cross_product(Vector A, Vector B) {
    return A.x * B.y - B.x * A.y;
}
 
double dot_product(Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}
 
 
bool are_parallel_lines(Line a, Line b) {
    return abs(a.a * b.b - a.b * b.a) < EPS;
}
 
bool are_similar_lines(Line a, Line b) {
    return abs(a.a * b.b - a.b * b.a) < EPS && abs(a.b * b.c - b.b * a.c) < EPS && abs(a.a * b.c - b.a * a.c) < EPS;
}
 
Point cross_line_line(Line line1, Line line2) {
    double y = (line1.c * line2.a - line1.a * line2.c) / (line1.a * line2.b - line1.b * line2.a);
    double x = (line1.b * line2.c - line1.c * line2.b) / (line1.a * line2.b - line1.b * line2.a);
    return Point(x, y);
}
 
bool is_segment_intersec(Point A, Point B, Point C, Point D) {
    Vector AB(A, B);
    Vector CD(C, D);
    Vector CA(C, A);
    Vector CB(C, B);
    Vector AC(A, C);
    Vector AD(A, D);
    Vector BC(B, C);
    Vector BD(B, D);
    Vector DA(D, A);
    Vector DB(D, B);
 
    double prod1 = cross_product(AB, AC);
    double prod2 = cross_product(AB, AD);
    double prod3 = cross_product(CD, CA);
    double prod4 = cross_product(CD, CB);
 
    if (abs(prod1) < EPS && abs(prod2) < EPS && abs(prod3) < EPS && abs(prod4) < EPS) { // все точки на одной прямой
 
        bool b1 = abs(dot_product(AC, AD) + AC.length() * AD.length()) < EPS;
        bool b2 = abs(dot_product(BC, BD) + BC.length() * BD.length()) < EPS;
        bool b3 = abs(dot_product(CA, CB) + CA.length() * CB.length()) < EPS;
        bool b4 = abs(dot_product(DA, DB) + DA.length() * DB.length()) < EPS;
 
        if (b1 || b2 || b3 || b4) {
            return true;
        } else {
            return false;
        }
 
    } else if (prod1 * prod2 <= 0 && prod3 * prod4 <= 0) {
        return true;
    } else {
        return false;
    }
}
 
 
bool is_inside_triangle(Point P, Point A, Point B, Point C) {
    Vector AB(A, B);
    Vector BC(B, C);
    Vector CA(C, A);
    Vector AP(A, P);
    Vector BP(B, P);
    Vector CP(C, P);
    int prod1 = sign(cross_product(AB, AP));
    int prod2 = sign(cross_product(BC, BP));
    int prod3 = sign(cross_product(CA, CP));
    if (prod1 == 0 && prod2 == 0 && prod3 == 0) {
        double max_dist_in_segment = max(max(AB.length(), BC.length()), CA.length());
        double max_dist_to_point = max(max(AP.length(), BP.length()), CP.length());
        return max_dist_in_segment - max_dist_to_point > -EPS;
    } else if (prod1 >= 0 && prod2 >= 0 && prod3 >= 0) {
        return true;
    } else if (prod1 < 0 && prod2 < 0 && prod3 < 0) {
        return true;
    } else {
        return false;
    }
}
 
bool is_inside_polygon(Point A, vector<Point> &polygon) {
    int pts_num = polygon.size();
    double ang = 0;
    for (int i = 0; i < pts_num; ++i) {
        Point pt1 = polygon[i];
        Point pt2 = polygon[(i + 1) % pts_num];
        Vector v1(A, pt1);
        Vector v2(A, pt2);
        if (abs(cross_product(v1, v2)) < EPS && dot_product(v1, v2) < EPS)
            return true;
        ang += atan2(cross_product(v1, v2), dot_product(v1, v2));
    }
    return abs(ang) > PI;
}
 
bool is_inside_segment(Point A, Point B, Point P) {
    // точка на прямой АБ
    Vector AB(A, B);
    Vector BA(B, A);
    Vector AP(A, P);
    Vector BP(B, P);
    return abs(dot_product(AP, BP) + AP.length() * BP.length()) < EPS;
}
 
bool is_inside_ray(Point A, Point B, Point P) {
    Vector AB(A, B);
    Vector AP(A, P);
    return abs(dot_product(AB, AP) - AB.length() * AP.length()) < EPS;
}
 
bool is_inside_convex_polygon(Point A, vector<Point> &polygon) {
    int points_num = polygon.size();
    Vector left_bound(polygon[0], polygon[polygon.size() - 1]);
    Vector right_bound(polygon[0], polygon[1]);
    Vector to_point(polygon[0], A);
    if (cross_product(left_bound, to_point) < EPS && cross_product(right_bound, to_point) > -EPS) {
        int left = 0;
        int right = polygon.size() - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            Vector diag(polygon[0], polygon[mid]);
            if (cross_product(to_point, diag) > -EPS) {
                right = mid;
            } else {
                left = mid;
            }
        }
 
        return is_inside_triangle(A, polygon[0], polygon[left], polygon[left + 1]);
    } else {
        return false;
    }
}
 
 
bool is_convex(vector<Point> &polygon) {
    int pts_num = polygon.size();
    bool has_negative = false;
    bool has_positive = false;
    for (int pt = 0; pt < pts_num; ++pt) {
        Point pt1 = polygon[pt];
        Point pt2 = polygon[(pt + 1) % pts_num];
        Point pt3 = polygon[(pt + 2) % pts_num];
        Vector v12(pt1, pt2);
        Vector v23(pt2, pt3);
        int turn = sign(cross_product(v12, v23));
        if (turn > 0)
            has_positive = true;
        else if (turn < 0)
            has_negative = true;
    }
    return !(has_negative && has_positive);
}
 
 
 
istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
 
ostream& operator<<(ostream& os, Point& p) {
    os << p.x << ' ' << p.y;
    return os;
}
 
Point operator + (Point A, Vector B) {
    return Point(A.x + B.x, A.y + B.y);
}
 
Point operator - (Point A, Vector B) {
    return Point(A.x - B.x, A.y - B.y);
}
 
Vector operator + (Vector A, Vector B) {
    return Vector(A.x + B.x, A.y + B.y);
}
 
Vector operator * (Vector A, double b) {
    return Vector(A.x * b, A.y * b);
}
 
Vector operator * (double b, Vector A) {
    return Vector(A.x * b, A.y * b);
}
 
Vector operator - (Vector A, Vector B) {
    return Vector(A.x - B.x, A.y - B.y);
}
 
Vector operator / (Vector A, double b) {
    return Vector(A.x / b, A.y / b);
}
 
bool operator < (const Point &A,const Point &B) {
    if (abs(A.x - B.x) < EPS) {
        return A.y < B.y;
    } else {
        return A.x < B.x;
    }
}
 
bool operator == (const Point &A, const Point & B) {
    return abs(A.x - B.x) < EPS && abs(A.y - B.y) < EPS;
}
 
 
double distance_point_point (Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
 
double distance_segment_point(Point A, Point B, Point P) {
    Vector AB(A, B);
    Vector BA(B, A);
    Vector AP(A, P);
    Vector BP(B, P);
    Vector PB(P, B);
    Vector PA(P, A);
    double distA = distance_point_point(P, A);
    double distB = distance_point_point(P, B);
    if (dot_product(AB, AP) < EPS || dot_product(BA, BP) < EPS)
        return min(distA, distB);
    else
        return abs(cross_product(PA, PB) / AB.length());
}
 
double distance_line_point(Line f, Point A) {
    return abs(f.a * A.x + f.b * A.y + f.c) / sqrt(f.a * f.a + f.b * f.b);
}
 
double distance_ray_point(Point A, Point B, Point P) {
    Vector AB(A, B);
    Vector AP(A, P);
    if (dot_product(AB, AP) < EPS)
        return distance_point_point(P, A);
    else {
        return distance_line_point(Line(A, B), P);
    }
}
 
double distance_line_line(Line a, Line b) {
    if (are_similar_lines(a, b))
        return 0;
    else if (are_parallel_lines(a, b)) {
        Point P = a.GetPoint();
        return distance_line_point(b, P);
    } else {
        return 0;
    }
 
}
 
double distance_segment_segment(Point A, Point B, Point C, Point D) {
    if (is_segment_intersec(A, B, C, D)) {
        return 0;
    } else {
        return min(min(distance_segment_point(A, B, C), distance_segment_point(A, B, D)),
                   min(distance_segment_point(C, D, A), distance_segment_point(C, D, B)));
    }
}
 
double distance_line_segment(Line f, Point A, Point B) {
    Line g(A, B);
    if (are_similar_lines(f, g))
        return 0;
    else if (are_parallel_lines(f, g)) {
        return distance_line_point(f, A);
    } else {
        Point P = cross_line_line(f, g);
        if (is_inside_segment(A, B, P))
            return 0;
        else
            return min(distance_line_point(f, A), distance_line_point(f, B));
    }
 
}
 
double distance_line_ray(Line f, Point A, Point B) {
    Line g(A, B);
    if (are_parallel_lines(f, g))
        return distance_line_point(f, A);
    else {
        Point P = cross_line_line(f, g);
        if (is_inside_ray(A, B, P))
            return 0;
        else
            return distance_line_point(f, A);
    }
}
 
double distance_ray_ray(Point A, Point B, Point C, Point D) {
    Line f(A, B);
    Line g(C, D);
    Vector AB(A, B);
    Vector CD(C, D);
    Vector CA(C, A);
    Vector AC(A, C);
    double edge_dist = min(distance_ray_point(C, D, A), distance_ray_point(A, B, C));
    if (are_similar_lines(f, g)) {
        if (abs(dot_product(AB, AC) - AB.length() * AC.length()) < EPS || abs(dot_product(CD, CA) - CD.length() * CA.length()) < EPS)
            return 0;
        else {
            return edge_dist;
        }
    } else if (are_parallel_lines(f, g)) {
        return edge_dist;
    } else {
        Point P = cross_line_line(f, g);
        if (is_inside_ray(A, B, P) && is_inside_ray(C, D, P))
            return 0;
        else
            return edge_dist;
    }
}
 
double distance_ray_segment(Point A, Point B, Point C, Point D) {
    Line f(A, B);
    Line g(C, D);
    Vector AB(A, B);
    Vector CD(C, D);
    Vector CA(C, A);
    Vector AC(A, C);
    double edge_dist = min(min(distance_ray_point(A, B, C), distance_ray_point(A, B, D)), distance_segment_point(C, D, A));
    if (are_similar_lines(f, g)) {
        if (is_inside_ray(A, B, C) || is_inside_ray(A, B, D))
            return 0;
        else
            return edge_dist;
    } else if (are_parallel_lines(f, g)) {
        return edge_dist;
    } else {
        Point P = cross_line_line(f, g);
        if (is_inside_ray(A, B, P) && is_inside_segment(C, D, P))
            return 0;
        else {
            return edge_dist;
        }
    }
}
 
 
bool cmp(Point A, Point B) {
    if (abs(A.y * B.x - A.x * B.y) < EPS) {
        return A.x * A.x + A.y * A.y < B.x * B.x + B.y * B.y;
    } else {
        double ang1 = atan2(A.y, A.x);
        double ang2 = atan2(B.y, B.x);
        return ang1 < ang2;
    }
}
 
void build_convex_hull(vector<Point> &polygon, vector<Point> &hull) {
    // в центре самая нижняя левая точка, для целых чисел правильно работает, потом - хз
    long long min_y = INF;
    long long min_x = INF;
 
    for (auto pt: polygon) {
        if (pt.y == min_y)
            min_x = min((long long)pt.x, min_x);
        else if (pt.y < min_y) {
            min_y = pt.y;
            min_x = pt.x;
        }
    }
    for (int i = 0; i < polygon.size(); ++i) {
        polygon[i].x -= min_x;
        polygon[i].y -= min_y;
    }
 
    sort(polygon.begin(), polygon.end(), cmp);
    hull.push_back(polygon[0]);
    hull.push_back(polygon[1]);
    for (int i = 2; i < polygon.size(); ++i) {
        while (hull.size() > 1 && cross_product(Vector(hull[hull.size() - 2], hull.back()), Vector(hull.back(), polygon[i])) < -EPS) {
            hull.pop_back();
        }
        hull.push_back(polygon[i]);
    }
    for (int i = 0; i < polygon.size(); ++i) {
        polygon[i].x += min_x;
        polygon[i].y += min_y;
    }
 
}
 
void restore_convex_polygon(vector<Point> &polygon) {
    double min_x, min_y = 1e6;
    for (Point pt : polygon) {
        if (abs(pt.y - min_y) < EPS) {
            if (pt.x < min_x) min_x = pt.x;
        } else if (pt.y < min_y) {
            min_y = pt.y;
            min_x = pt.x;
        }
    }
    for (int i = 0; i < polygon.size(); ++i) {
        polygon[i].y -= min_y;
        polygon[i].x -= min_x;
        if (abs(polygon[i].y) < EPS) polygon[i].y = 0;
        if (abs(polygon[i].x ) < EPS) polygon[i].x = 0;
    }
    sort(polygon.begin(), polygon.end(), cmp);
    for (int i = 0; i < polygon.size(); ++i) {
        polygon[i].y += min_y;
        polygon[i].x += min_x;
 
    }
 
}
 
double polygon_perimeter(vector<Point> &polygon) {
    double ans = 0;
    for (int i = 0; i < polygon.size(); ++i)
        ans += distance_point_point(polygon[i], polygon[(i + 1) % polygon.size()]);
    return ans;
}
 
double polygon_area_by_Gauss_formula(vector<Point> &polygon) {
    vector<double> x_coord, y_coord;
    for (Point p : polygon) {
        x_coord.push_back(p.x);
        y_coord.push_back(p.y);
    }
 
    long long s = 0;
    for (int i = 0; i < x_coord.size() - 1; ++i) {
        s += x_coord[i] * y_coord[i + 1];
    }
    s += x_coord[x_coord.size() - 1] * y_coord[0];
 
    for (int i = 0; i < y_coord.size() - 1; ++i) {
        s -= y_coord[i] * x_coord[i + 1];
    }
    s -= y_coord[y_coord.size() - 1] * x_coord[0];
 
    return abs(double(s) / 2);
}
 
void pinpoint_turn(Line f, vector<Point> &polygon, vector<Point> &left, vector<Point> &right) {
    for (Point pt : polygon) {
        double eq = f.a * pt.x + f.b * pt.y + f.c;
        if (eq > EPS)
            right.emplace_back(pt);
        else if (eq < -EPS)
            left.emplace_back(pt);
    }
}
 
vector<Point> cross_line_polygon(Line f, vector<Point> &polygon) {
    vector<Point> cross_pts;
    for (int i = 0; i < polygon.size(); ++i) {
        Point A = polygon[i];
        Point B = polygon[(i + 1) % polygon.size()];
        Line AB(A, B);
        if (abs(AB.a * f.b - f.a * AB.b) > EPS) {
            Point inter = cross_line_line(f, AB);
            Vector AP(A, inter);
            Vector BP(B, inter);
            if ( abs(AP.length() * BP.length() + dot_product(AP, BP)) < EPS && (abs(inter.y - A.y) > EPS|| abs(inter.x - A.x) > EPS))
                cross_pts.push_back(inter);
        }
    }
    return cross_pts;
}
 
Point rotate_point(Point A, double angle) {
    double x = A.x * cos(angle) - A.y * sin(angle);
    double y = A.x * sin(angle) + A.y * cos(angle);
    return Point(x, y);
}
 
Vector rotate_vector(Vector A, double angle) {
    double x = A.x * cos(angle) - A.y * sin(angle);
    double y = A.x * sin(angle) + A.y * cos(angle);
    return Vector(x, y);
}
 
Point height_point(Line f, Point A) {
    double dist = distance_line_point(f, A);
    double x = A.x - dist * f.a / sqrt(f.a * f.a + f.b * f.b);
    double y = A.y - dist * f.b / sqrt(f.a * f.a + f.b * f.b);
    return Point(x, y);
}
 
vector<Point> cross_circle_circle(Circle O1, Circle O2) {
    double r1 = O1.r;
    double r2 = O2.r;
    vector<Point> intersection;
    double d = distance_point_point(O1.C, O2.C);
    if (r1 < r2) {
        swap(O1, O2);
        swap(r1, r2);
    }
 
    if (O1.C == O2.C && abs(r1 - r2) < EPS) {
        // бесконечность
        intersection.push_back({O1.C.x, O1.C.y - r1});
        intersection.push_back({O1.C.x, O1.C.y + r1});
        intersection.push_back({O1.C.x + r1, O1.C.y});
 
    } else if (abs(d - r1 - r2) < EPS || abs(r1 - d - r2) < EPS) {
        // одна
        Vector O1O2(O1.C, O2.C);
        Vector resized = O1O2 / O1O2.length() * r1;
        Point P = O1.C + resized;
        intersection.push_back(P);
 
    } else if (d - r1 - r2 > EPS || r1 - d - r2 > EPS) {
        // ноль
 
    } else {
        // две
        Vector O1O2(O1.C, O2.C);
        Vector resized = O1O2 / O1O2.length() * r1;
        double ang = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        Point P1 = O1.C + rotate_vector(resized, ang);
        Point P2 = O1.C + rotate_vector(resized, -ang);
        intersection.push_back(P1);
        intersection.push_back(P2);
    }
    return intersection;
}
 
vector<Line> tangent_point_circle (Point P, Circle O) {
    vector<Line> ans;
    double dist = distance_point_point(P, O.C);
    if (O.r < EPS) {
        // окуржность - точка
        ans.push_back(Line(P, O.C));
    } else if (abs(O.r - dist) < EPS) {
        // точка на покужности
        Line f(O.C, P);
        double a = -f.b;
        double b = f.a;
        double c = - a * P.x - b * P.y;
        ans.push_back(Line(a, b, c));
    } else if (dist + EPS < O.r) {
        // точка в окружности
    }  else {
        // норм
        double l = sqrt(dist * dist - O.r * O.r);
        double ang = asin( O.r / dist);
        Vector PC(P, O.C);
        Vector norm = PC / PC.length() * l;
        Vector norm_turn_1 = rotate_vector(norm, ang);
        Vector norm_turn_2 = rotate_vector(norm, -ang);
        Point T1 = P + norm_turn_1;
        Point T2 = P + norm_turn_2;
        ans.push_back(Line(P, T1));
        ans.push_back(Line(P, T2));
    }
    return ans;
}
 
vector<Point> cross_line_circle(Line f, Circle O) {
    Point C = O.C;
    double r = O.r;
    vector<Point> ans;
    double dist = distance_line_point(f, C);
 
    if (abs(dist - r) < EPS) {
        ans.push_back(height_point(f, C));
    } else if (abs(dist) < r) {
        double l = sqrt(r * r - dist * dist);
        Point H = height_point(f, C);
        Vector to_point(-f.b, f.a);
        to_point = to_point / to_point.length();
        to_point = to_point * l;
        Point A = H + to_point;
        Point B = H - to_point;
        if (B < A)
            swap(B, A);
        ans.push_back(A);
        ans.push_back(B);
    }
    return ans;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(18);
  
}
