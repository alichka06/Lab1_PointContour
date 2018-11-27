//19. Трапеція: (0,0), (2a,0), (a,a), (0,a)
#include <bits/stdc++.h>

using namespace std;

int getCont(double &a);
int getPoint (double &x, double &y);
int wherePoint (double a, double x, double y);
double distPointCont (double a, double x, double y, int pos);
void outPoint (double x, double y);
void outCont (double a);
void outResults (double a, double x, double y, double dist, int pos);
void processCont (double a);

int main()
{
    double a;
    int in = 0;
    setlocale(LC_ALL, "Ukrainian");
    while ( !(in == -1) )
    {
        in = getCont(a);
        if ( in == -1 ) return cout << "CONTOUR IS ABSENT\nEND OF WORK", 0;
        if ( in == 0 ) cout << "WRONG PARAMETR\n\n";
        if ( in == 1) processCont(a);
    }
    return 0;
}

int getCont(double &a)
{
    cout << "Введiть параметр контуру а: ";
    cin.clear();
    cin >> a;
    if (cin.eof())
        return -1;
    else if (a > 0)
        return 1;
    else
        return 0;
}

void processCont (double a)
{
    double  x, y, x1, y1, dist;
    int pos, getP, k=0;
    while (1)
    {
        ++k;
        getP = getPoint( x, y);
        if (getP == -1)
        {
            cout << "END OF POINTS\n\n";
            return;
        }
        if (x == x1 && y == y1 && k > 1)
        {
            cout << "POINT REPEAT\n\n";
            return;
        }
        pos = wherePoint(a, x, y);
        dist = distPointCont(a, x, y, pos);
        outResults(a, x, y, dist, pos);
        x1 = x, y1 = y;
    }
}

int getPoint (double &x, double &y)
{
    cout << "Введiть координати точок x та y: ";
    cin.clear();
    cin >> x >> y;
    if (cin.eof())
        return -1;
    else
        return 1;
}

int wherePoint (double a, double x, double y)
{
    if ( ( y==0 && x>=0 && x<=2*a ) || //down
         ( y==a && x>=0 && x<=a ) || //up
         ( x==0 && y>=0 && y<=a ) || //left
         ( y==-x+2*a && x>=a && x<=2*a ) ) return 0;
    if ( y<a && y<-x+2*a && y>0 && x>0 ) return 1;
    return -1;
}

double distPointCont (double a, double x, double y, int pos)
{
    if (pos == 0) return 0;
    if (pos == 1)
        return min(sqrt(2)/2*abs(a-x-y), min(a-y, min(y, x)));
    if (pos == -1)
    {
        if (y > a&& x > 0 && x < a) return y-a;
        if (x < 0 && y < a && y > 0) return -x;
        if (y < 0 && x > 0 && x < 2*a) return -y;
        if (y > -x+a && y < x && y > -x-a) return sqrt(2)/2*abs(a-x-y);
        return min( sqrt((x-a)*(x-a)+(y-a)*(y-a)), min(sqrt((x-2*a)*(x-2*a)+y*y), min(sqrt(x*x+y*y), sqrt(x*x+(y-a)*(y-a)))));
    }
}

void outPoint (double x, double y)
{
    cout << "(" << x << "; " << y << ")";
}

void outCont (double a)
{
    cout << "[" << a << "]";
}

void outResults (double a, double x, double y, double dist, int pos)
{
    cout << "Точка: "; outPoint(x,y);
    cout << "\nЇЇ розташування: ";
    if ( pos == 1 ) cout << "IN_C";
    if ( pos == 0 ) cout << "ON_C";
    if ( pos == -1 ) cout << "OUT_C";
    cout << "\nПараметр контуру: "; outCont(a);
    cout << "\nDISTANCE=" << dist << "\n";
}
