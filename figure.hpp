#include <vector>
class coordinate
{
    public:
        double x, y;
};

class figure
{
    protected:
        double area;
        coordinate center;
        std::vector<coordinate> points;
    public:
        virtual void printArea()
        {}

        virtual void printCenter()
        {}

        virtual void printCoord()
        {}
};

class triangle: public figure{
    private:
        std::vector<double> len;
    public:

        triangle(std::vector<coordinate> data)
        {
            points.resize(3);
            points = data;
        }

        void length()
        {
            len.resize(3);
            for (int i = 0; i < 3; i++)
            {
                len[i] = sqrt(pow(abs(points[i].x - points[(i + 1) % 3].x), 2) + pow(abs(points[i].y - points[(i + 1) % 3].y), 2));
            }
            
        }

        void areaCalc()
        {
            length();
            double p = (len[0] + len[1] + len[2]) / 2;
            area = sqrt(p * (p - len[0]) * (p - len[1]) * (p - len[2]));
        }

        void centerCalc()
        {
            for(int i = 0; i < points.size(); i++)
            {
                center.x += points[i].x;
                center.y += points[i].y;
            }
            center.x /= points.size();
            center.y /= points.size();
        }

        void printArea()
        {
            areaCalc();
            std::cout << "S = " << area << std::endl;
        }

        void printCenter()
        {
            centerCalc();
            std::cout << "Center: " << "(" << center.x << ";" << center.y << ")" << std::endl;
        }

        void printCoord()
        {
            for(int i = 0; i < points.size(); i++)
            {
                std::cout << "№" << i + 1 << "(" << points[i].x << ";" << points[i].y << ")" << std::endl;
            }
        }
};

class squary: public figure{
    private:
        double len;
    public:

        squary(coordinate cntr, double length)
        {
            points.resize(1);
            points[0] = cntr;
            len = length;
        }

        void areaCalc()
        {
            area = len * len;
        }

        void printArea()
        {
            areaCalc();
            std::cout << "S = " << area << std::endl;
        }

        void printCenter()
        {
            std::cout << "Center: " << "(" << points[0].x << ";" << points[0].y << ")" << std::endl;
        }

        void printCoord()
        {
            std::cout << "№1" << "(" << points[0].x - len / 2 << ";" << points[0].y - len / 2 << ")" << std::endl;
            std::cout << "№2" << "(" << points[0].x + len / 2 << ";" << points[0].y - len / 2 << ")" << std::endl;
            std::cout << "№3" << "(" << points[0].x + len / 2 << ";" << points[0].y + len / 2 << ")" << std::endl;
            std::cout << "№4" << "(" << points[0].x - len / 2 << ";" << points[0].y + len / 2 << ")" << std::endl;
        }
};

class angle8: public figure{ //8-ми угольник
    private:
        double len;
    public:

        angle8(coordinate cntr, double length)
        {
            points.resize(1);
            points[0] = cntr;
            len = length;
        }

        void areaCalc()
        {
            area += points[0].x - len / 2; area -= points[0].y - len / 2 - sin(30 * M_PI / 180);
            area += points[0].x + len / 2; area -= points[0].y - len / 2 - sin(30 * M_PI / 180);
            area += points[0].x + len / 2; area -= points[0].y - len / 2;
            area += points[0].x + len / 2; area -= points[0].y + len / 2;
            area += points[0].x + len / 2; area -= points[0].y - len / 2 + sin(30 * M_PI / 180);
            area += points[0].x - len / 2; area -= points[0].y - len / 2 + sin(30 * M_PI / 180);
            area += points[0].x - len / 2; area -= points[0].y - len / 2;
            area += points[0].x - len / 2; area -= points[0].y + len / 2;

        }

        void printArea()
        {
            areaCalc();
            std::cout << "S = " << area << std::endl;
        }

        void printCenter()
        {
            std::cout << "Center: " << "(" << points[0].x << ";" << points[0].y << ")" << std::endl;
        }

        void printCoord()
        {
            std::cout << "№1" << "(" << points[0].x - len / 2 << ";" << points[0].y - len / 2 - 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№2" << "(" << points[0].x + len / 2 << ";" << points[0].y - len / 2 - 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№3" << "(" << points[0].x + len / 2 << ";" << points[0].y - len / 2 << ")" << std::endl;
            std::cout << "№4" << "(" << points[0].x + len / 2 << ";" << points[0].y + len / 2 << ")" << std::endl;
            std::cout << "№5" << "(" << points[0].x + len / 2 << ";" << points[0].y + len / 2 + 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№6" << "(" << points[0].x - len / 2 << ";" << points[0].y + len / 2 + 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№7" << "(" << points[0].x - len / 2 << ";" << points[0].y + len / 2 << ")" << std::endl;
            std::cout << "№8" << "(" << points[0].x - len / 2 << ";" << points[0].y - len / 2 << ")" << std::endl;
        }
};