#include <iostream>

using namespace std;

class Matrix
{
private:
    int lines;
    int columns;
    double **matrix;

public:
    Matrix(int lines, int columns)
    {
        this->lines = lines;
        this->columns = columns;

        matrix = new double *[lines];

        for (int i = 0; i < lines; i++)
        {
            matrix[i] = new double[columns];
        }
    }

    void set_value(int line, int column, double value)
    {
        if (line >= 0 && line < lines && column >= 0 && column < columns)
        {
            matrix[line][column] = value;
        }
    }

    double get_value(int line, int row)
    {
        return matrix[line][row];
    }

    ~Matrix()
    {
        for (int i = 0; i < lines; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main()
{
    Matrix M(5, 3);

    M.set_value(2,2, 5.5);
    cout << M.get_value(2,2) << endl;


    return 0;
}