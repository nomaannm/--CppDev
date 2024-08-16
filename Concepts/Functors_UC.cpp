#include <assert.h>
#include<iostream>
#include <vector>
#include<cmath>

class Matrix {
public:
    Matrix(int rows, int cols) : rows_{rows}, cols_{cols}, data_(rows_, std::vector<double>(cols,0)) {}
    int rows() const {return rows_;}
    int cols() const {return cols_;}

    double& at(int row, int col)  {return data_[row][col] ;}
    double at(int row, int col) const { return data_[row][col] ;}

    Matrix operator*(const Matrix& other) const {
        assert(cols_ == other.rows());
        Matrix result = Matrix(rows_, other.cols());
        for(int i = 0; i < rows_; i++) {
            for(int j = 0; j < other.cols(); j++) {
                for(int k = 0; k < cols_; k++) {
                    result.at(i, j) += at(i,k) * other.at(k, j);
                }

            }
        }
        return result;
    }

    void print() const {
        for(auto row : data_) {
            for(double val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }
private:
    int rows_, cols_;
    std::vector<std::vector<double>> data_;
};

//Functor for matrix transformation
class MatrixTransformer {
public:
    MatrixTransformer(const Matrix& matrix) : matrix_{matrix} {}

    Matrix operator()(const Matrix& transformationMatrix) const {
        Matrix result = matrix_ * transformationMatrix;
        applyElementWiseTransformation(result);
        return result;
    }
private:
    const Matrix matrix_;
    void applyElementWiseTransformation(Matrix& matrix) const {
        for (int i = 0; i < matrix.rows(); ++i) {
            for (int j = 0; j < matrix.cols(); ++j) {
                matrix.at(i, j) = std::sqrt(matrix.at(i, j));  // Example transformation: square root
            }
        }
    }
};

int main() {
    // Define matrices
    Matrix matA(2, 2);
    matA.at(0, 0) = 1; matA.at(0, 1) = 2;
    matA.at(1, 0) = 3; matA.at(1, 1) = 4;

    Matrix matB(2, 2);
    matB.at(0, 0) = 5; matB.at(0, 1) = 6;
    matB.at(1, 0) = 7; matB.at(1, 1) = 8;

    // Create a transformer functor
    MatrixTransformer transformer(matA);

    // Apply transformation
    Matrix result = transformer(matB);

    // Output result
    std::cout << "Transformed Matrix:\n";
    result.print();

    return 0;
}
