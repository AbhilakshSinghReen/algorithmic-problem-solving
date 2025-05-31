#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// TODO: make this templated
// TODO: add a version that can accept the output vector as a parameter
vector<vector<int>> matrixClassicalDotProduct(
        vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int nr1 = matrix1.size(), nc1 = matrix1[0].size(), nr2 = matrix2.size(),
        nc2 = matrix2[0].size();

    if (nc1 != nr2) {
        throw runtime_error(
                "Cannot perform matrix dot product as the number of columns of the first matrix is "
                "not the same as the number of rows of the second matrix: " +
                to_string(nc1) + " != " + to_string(nr2) + ". Matrix shapes: [" + to_string(nr1) +
                ", " + to_string(nc1) + "], [" + to_string(nr2) + ", " + to_string(nc2) + "].");
    }

    vector<vector<int>> output(nr1, vector<int>(nc2, 0));

    for (int i = 0; i < nr1; i++) {
        for (int j = 0; j < nc2; j++) {
            for (int p = 0; p < nc1; p++) {
                output[i][j] += matrix1[i][p] * matrix2[p][i];
            }
        }
    }

    return output;
}

vector<vector<int>> matrixDotProduct(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    // Strassen's Matrix Multiplication

    int nr1 = matrix1.size(), nc1 = matrix1[0].size(), nr2 = matrix2.size(),
        nc2 = matrix2[0].size();

    if (nc1 != nr2) {
        throw runtime_error(
                "Cannot perform matrix dot product as the number of columns of the first matrix is "
                "not the same as the number of rows of the second matrix: " +
                to_string(nc1) + " != " + to_string(nr2) + ". Matrix shapes: [" + to_string(nr1) +
                ", " + to_string(nc1) + "], [" + to_string(nr2) + ", " + to_string(nc2) + "].");
    }

    vector<vector<int>> output(nr1, vector<int>(nc2, 0));
    // TODO: completed this, after completing add a version that accepts the output vector as a
    // parameter
    return output;
}