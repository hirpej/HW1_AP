#include "aphw1.h"

Matrix multiply(Matrix &a, Matrix &b)
{
    Matrix multy(a.size(), std::vector<double>(b[0].size(), 0));
    for (size_t i{}; i < a.size(); i++)
    {
        for (size_t j{}; j < b[0].size(); j++)
        {
            for (size_t k{}; k < b.size(); k++)
            {
                multy[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return multy;
}

Matrix transpose(Matrix &a)
{
    Matrix trans(a[0].size(), std::vector<double>(a.size()));
    for (size_t i{}; i < a.size(); i++)
    {
        for (size_t j{}; j < a[i].size(); j++)
        {
            trans[j][i] = a[i][j];
        }
    }
    return trans;
}

double det(Matrix &a)
{
    Matrix submatrix(a.size() - 1, std::vector<double>(a[0].size() - 1));
    double Det{};
    if (a.size() == 2 && a[0].size() == 2)
        return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
    else
    {
        for (size_t x{}; x < a.size(); x++)
        {
            double subi{};
            for (size_t i{1}; i < a.size(); i++)
            {
                double subj{};
                for (size_t j{}; j < a.size(); j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = a[i][j];
                    subj++;
                }
                subi++;
            }
            Det = Det + (std::pow(-1, x)) * a[0][x] * det(submatrix);
        }
    }
    return Det;
}

Matrix inv(Matrix &a)
{
    Matrix inverse(a.size(), std::vector<double>(a[0].size()));
    if (det(a) == 0)
    {
        std::cout << "This Matris Does Not Have Inverse !" << std::endl;
        return a;
    }
    else
    {
        Matrix Kahad(a.size(), std::vector<double>(a[0].size()));
        Matrix Elhaghi(a.size(), std::vector<double>(a[0].size()));
        Matrix temp(a.size(), std::vector<double>(a[0].size()));
        Matrix temp2(a.size() - 1, std::vector<double>(a[0].size() - 1));
        for (size_t i{}; i < a.size(); i++)
        {
            for (size_t j{}; j < a[i].size(); j++)
            {
                size_t p{}, q{};
                for (size_t row{}; row < a.size(); row++)
                {
                    for (size_t col{}; col < a[row].size(); col++)
                    {
                        if (row != i && col != j)
                        {
                            temp[p][q++] = a[row][col];
                            if (q == a.size() - 1)
                            {
                                q = 0;
                                p++;
                            }
                        }
                    }
                }
                for (size_t x{}; x < temp.size() - 1; x++)
                {
                    for (size_t y{}; y < temp[x].size() - 1; y++)
                    {
                        temp2[x][y] = temp[x][y];
                    }
                }
                if ((i + j) % 2 == 0)
                    Kahad[i][j] = det(temp2);
                else
                    Kahad[i][j] = (-1) * det(temp2);
            }
        }
        Elhaghi = transpose(Kahad);
        for (size_t i{}; i < Elhaghi.size(); i++)
            for (size_t j{}; j < Elhaghi[i].size(); j++)
                inverse[i][j] = (Elhaghi[i][j]) / float(det(a));
    }
    return inverse;
}

void show(Matrix &a)
{
    for (size_t i{}; i < a.size(); i++)
    {
        for (size_t j{}; j < a[i].size(); j++)
        {
            std::cout << std::left << std::setw(10) << std::setprecision(2) << std::fixed << a[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix getData(char const *filename)
{
    Matrix values;
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "something is wrong during open the file !" << std::endl;
        exit(1);
    }
    if (file)
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream sep(line);
            std::string field;
            values.push_back(std::vector<double>());
            values.back().push_back(1);
            while (std::getline(sep, field, ','))
            {
                values.back().push_back(stod(field));
                values.back().push_back(std::sin(stod(field)));
                values.back().push_back(std::sqrt(stod(field)));
            }
        }
    }
    std::for_each(values.begin(), values.end(), [&](std::vector<double> &row) {
        row.erase(std::next(row.begin(), row.size() - 1));
    });
    std::for_each(values.begin(), values.end(), [&](std::vector<double> &row) {
        row.erase(std::next(row.begin(), row.size() - 1));
    });
    return values;
}

Matrix getX(Matrix &GetData)
{
    std::for_each(GetData.begin(), GetData.end(), [&](std::vector<double> &row) {
        row.erase(std::next(row.begin(), row.size() - 1));
    });
    return GetData;
}

Matrix gety(Matrix &data)
{
    size_t x{data[0].size() - 1};
    for (size_t i{}; i < x; i++)
    {
        std::for_each(data.begin(), data.end(), [&](std::vector<double> &row) {
            row.erase(std::next(row.begin(), 0));
        });
    }
    return data;
}

Matrix solve(char const *filename)
{
    Matrix D = getData(filename);
    Matrix X = getX(D);
    Matrix F = getData(filename);
    Matrix Y = gety(F);
    Matrix trans_X = transpose(X);
    Matrix mult1 = multiply(trans_X, X);
    Matrix inv1 = inv(mult1);
    Matrix mult2 = multiply(inv1, trans_X);
    Matrix W = multiply(mult2, Y);
    return W;
}