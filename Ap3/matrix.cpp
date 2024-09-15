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

        //creating the matrix
        matrix = new double *[lines];
        for (int i = 0; i < lines; i++)         matrix[i] = new double[columns];
        //initializing the values
        for(int i = 0; i < lines; i++){
            for(int j = 0; j < columns; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void set_value(int line, int column, double value)
    {
        if (line >= 0 && line < lines && column >= 0 && column < columns)       matrix[line][column] = value;

    }

    double get_value(int line, int row)
    {
        return matrix[line][row];
    }

    void printMatrix(){
        for(int i = 0; i < lines; i++){
            for(int j = 0; j < columns; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
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
    Matrix M(5, 4);

    M.set_value(2,2, 5.5);
    M.set_value(0,0, 23);
    M.set_value(0,0, 32);
    M.set_value(0,1, 5);

    cout << M.get_value(2,2) << endl;
    M.printMatrix();


    return 0;
}