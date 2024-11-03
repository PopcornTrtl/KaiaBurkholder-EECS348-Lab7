
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin();

  // 2. Display a matrix
  void display() const;

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const;

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const;

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const;

  // 6. Swap matrix rows
  void swapRows(int row1, int row2);
};

void Matrix::readFromStdin() {
  int matrixEntry;
  //Asks the user to enter each entry for the matrix of SIZE
  for(int i = 0; i < SIZE; i++) {
    for(int x = 0; x < SIZE; x++) {
      cin >> matrixEntry;
      data[i][x] = matrixEntry;
    }
  }
  
}

void Matrix::display() const {
  //prints out each element of the matrix
  for (int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      cout << data[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix sum;
  //iterates over the whole matrix, adding the entries + putting them into the sum matrix
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      sum.data[i][j] = data[i][j] + other.data[i][j];
    }
  }
  return sum;
}

Matrix Matrix::operator*(const Matrix& other) const {
  Matrix product;
  //for each row in the first matrix it iterates over each column
  for(int selfRow = 0; selfRow < SIZE; selfRow++) {
    for(int otherColumn = 0; otherColumn < SIZE; otherColumn++) {
      int sum = 0;
      //adds together the multiplications of the entries of both matricies
      for(int i = 0; i < SIZE; i++) {
        sum += data[selfRow][i] * other.data[i][otherColumn];
      }
      //adds the total sum to the matrix
      product.data[selfRow][otherColumn] = sum;
    }
  }

  return product;
}

void Matrix::swapRows(int Row1, int Row2) {
  if (Row1 < SIZE && Row2 < SIZE) {
    int temp[SIZE];
    //Saves row1 in a temporary array
    for (int index = 0; index < SIZE; index++) {
      temp[index] = data[Row1][index];
    }
    //moves row2 to row1
    for (int i = 0; i < SIZE; i++) {
      data[Row1][i] = data[Row2][i];
    }
    //moves row1 to row2, using the temporary array
    for (int j = 0; j < SIZE; j++) {
      data[Row2][j] = temp[j];
    }
  }
}

int Matrix::sumOfDiagonals() const{
  //adds each diagonal element together + returns the sum
  int sum = 0;
  for(int i = 0; i < SIZE; i++) {
    sum += data[i][i];
  }
  return sum;
}

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1 (One entry at a time):" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2 (One entry at a time):" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
