#include "TestCommon.h"

bool areMatrixEqual(const BmpMatrix& a, const BmpMatrix& b) {
    BmpReal eps = 10e-12;
    CHECK(a.size() == b.size());
    auto n = a.size();
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            CHECK(round(a[i][j]) == b[i][j]);
            CHECK(abs(a[i][j] - b[i][j]) < eps);
        }
    }
    return true;
}

TEST_CASE("Matrix") {
    std::cout.precision(std::numeric_limits<BmpReal>::max_digits10);
    SECTION("inverse") {
        SECTION("m2x2") {
            BmpMatrix m2x2 = { { 3, 4 },{ 5, 7 } };
            const BmpMatrix expected = { { 7, -4 },{ -5, 3 } };
            auto inversedMatrix = MatrixUtils(m2x2).inverse();
            REQUIRE(true == areMatrixEqual(inversedMatrix, expected));
            test::printMatrix(inversedMatrix);
        }

        SECTION("m3x3") {
            BmpMatrix m3x3 = { { 2, 5, 7 },{ 6, 3, 4 },{ 5, -2, -3 } };
            const BmpMatrix expected = { { 1, -1, 1 },{ -38, 41, -34 },{ 27, -29, 24 } };
            auto inversedMatrix = MatrixUtils(m3x3).inverse();
            REQUIRE(true == areMatrixEqual(inversedMatrix, expected));
            test::printMatrix(inversedMatrix);
        }

        SECTION("m4x4") {
            BmpMatrix m4x4 = { { 2, 1, 0, 0 },{ 3, 2, 0, 0 },{ 1, 1, 3, 4 },{ 2, -1, 2, 3 } };
            const BmpMatrix expected = { { 2, -1, 0, 0 },{ -3, 2, 0, 0 },{ 31, -19, 3, -4 },{ -23, 14, -2, 3 } };
            auto inversedMatrix = MatrixUtils(m4x4).inverse();
            REQUIRE(true == areMatrixEqual(inversedMatrix, expected));
            test::printMatrix(inversedMatrix);
        }
    }
}
