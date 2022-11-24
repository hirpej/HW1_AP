#include <iostream>
#include "aphw1.h"
#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "RUNNING TESTS ..." << std::endl;
    int ret{RUN_ALL_TESTS()};
    if (!ret)
        std::cout << "<<<SUCCESS>>>" << std::endl;
    else
        std::cout << "FAILED" << std::endl;
    return 0;
}

// #include <iostream>
// #include "aphw1.h"

// int main()
// {
//     std::cout << "Hello World" << std::endl;
//     // Matrix data{getData("data.txt")};
//     // show(data);
//     // EXPECT_EQ(1, data[0][0]);
//     // EXPECT_EQ(true, (103.4 < data[1][4])&&(103.6 > data[1][4]));

//     //**************************

//     // Matrix a = {{1, 2}, {3, 4}};
//     // Matrix b = {{5, 6}, {7, 8}};
//     // Matrix x;
//     // x = multiply(a, b);
//     // show(x);
//     // std::cout << "After Transpose : " << std::endl;
//     // Matrix y;
//     // y = transpose(x);
//     // show(y);
//     // std::cout << det(y) << std::endl;
//     // Matrix c = {{7, 1, 3},
//     //             {2, 4, 1},
//     //             {1, 5, 1}};
//     // std::cout << "Determinate Of C Is :" << det(c) << std::endl;
//     // Matrix d = {{1, 0, 2, -1},
//     //             {3, 0, 0, 5},
//     //             {2, 1, 4, -3},
//     //             {1, 0, 5, 0}};
//     // std::cout << "Determinate Of D Is :" << det(d) << std::endl;

//     //**************************

//     // Matrix e = {{5, -2, 2, 7},
//     //             {1, 0, 0, 3},
//     //             {-3, 1, 5, 0},
//     //             {3, -1, -9, 4}};
//     // Matrix f;
//     // f = inv(e);
//     // show(f);

//     // Matrix g = {{1, 2, 3},
//     //             {4, 6, 5},
//     //             {9, 8, 7}};
//     // Matrix h;
//     // h = inv(g);
//     // show(h);

//     // double haqir = 5 / float(1000);
//     // std::cout << std::setprecision(4) << std::fixed << haqir << std::endl;

//     // Matrix data{getData("data.txt")};
//     // show(data);
//     // EXPECT_EQ(1, data[0][0]);
//     // EXPECT_EQ(true, (103.4 < data[1][4]) && (103.6 > data[1][4]));

//     // Matrix data{getData("data.txt")};
//     // Matrix X{getX(data)};
//     // EXPECT_EQ(true, (1.05 < data[1][3]) && (1.06 > data[1][3]));

//     // Matrix data{getData("data.txt")};
//     // show(data);
//     // std::cout << "************************" << std::endl;
//     // Matrix y{gety(data)};
//     // show(y);
//     // EXPECT_EQ(true, (103.4 < y[1][0]) && (103.6 > y[1][0]));

//     Matrix w{solve("data.txt")};
//     show(w);
//     // std::cout << w[1][0] << std::endl;
//     // EXPECT_EQ(true, (0.82 < w[1][0]) && (0.84 > w[1][0]));

//     // Matrix a = {{1, 1, 1, 1},
//     //             {2, 2, 2, 2},
//     //             {3, 3, 3, 3},
//     //             {4, 4, 4, 4}};

//     // Matrix b = {{1, 1, 1, 1},
//     //             {2, 2, 2, 2},
//     //             {3, 3, 3, 3},
//     //             {4, 4, 4, 4}};
//     // Matrix c = multiply(a, b);
//     // show(c);

//     // Matrix a = {{2, 4},
//     //             {3, 4},
//     //             {1, 3}};
//     // Matrix b = {{1, 2, 0},
//     //             {1, 3, 2}};
//     // Matrix c = multiply(a, b);
//     // show(c);
// }