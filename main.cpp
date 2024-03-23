#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int> > matrix1;
static vector<vector<int> > matrix2;

vector<int> readFile(string fileName){
    fstream fileStream;
    fileStream.open(fileName);
    vector<int> fileCharacters (0);
    int num;
    for(int i = 0; i < 100; i++){
        fileStream >> num;
        fileCharacters.push_back(num);
    }
    fileStream.close(); 

    return fileCharacters;
}

void printMatrix(vector<vector<int> > matrix){
    for(int row = 0; row < matrix.size(); row++){
        for (int col = 0; col < matrix[row].size(); col++){
            cout << matrix[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<vector<int> > addMatrix(vector<vector<int> > matrix1, vector<vector<int> > matrix2){
    vector<vector<int> > returnedMatrix (matrix1.size(), vector<int> (matrix1.size()));

    for(int row = 0; row < matrix1.size(); row++){
        for(int col = 0; col < matrix1[row].size(); col++){
            returnedMatrix[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
    printMatrix(returnedMatrix);

    return returnedMatrix;

}

vector<vector<int> > multiplyMatrix(vector<vector<int> > matrix1, vector<vector<int> > matrix2){
    vector<vector<int> > returnedMatrix (matrix1.size(), vector<int> (matrix1.size())); 
    for(int row = 0; row < matrix1.size(); row++){
        for(int col = 0; col < matrix1[row].size(); col++){
            int sum = 0;
            for(int size = 0; size < matrix1.size(); size++){
                sum += matrix1[row][size] * matrix2[size][col];
            }

            returnedMatrix[row][col] = sum;
        }
    }

    printMatrix(returnedMatrix);

    return returnedMatrix;
}


vector<vector<int> > subtractMatrix(vector<vector<int> > matrix1, vector<vector<int> > matrix2){
    vector<vector<int> > returnedMatrix (matrix1.size(), vector<int> (matrix1.size()));

    for(int row = 0; row < matrix1.size(); row++){
        for(int col = 0; col < matrix1[row].size(); col++){
            returnedMatrix[row][col] = matrix1[row][col] - matrix2[row][col];
        }
    }

    printMatrix(returnedMatrix);

    return returnedMatrix;
}


void updateMatrix(int row, int col, int value){
    if (row > matrix1.size() -1 || row < 0){
        cout << "Invalid row size" << "\n";
    } 
    else if (col > matrix1[0].size() -1 || col < 0){
        cout << "Invalid column size" << "\n";
    } else {
    matrix1[row][col] = value; 
    printMatrix(matrix1);
    }
}


void maxValue(vector<vector<int> > matrix){

    int maximumValue = INT_MIN;
    for(int row = 0; row < matrix.size(); row++){
        for(int col = 0; col < matrix[row].size(); col++){
            if(matrix[row][col] > maximumValue){
                maximumValue = matrix[row][col];
            }
        }
    }
    cout << "Max Value: " << maximumValue << "\n\n";
}


void transposeMatrix(vector<vector<int> > matrix){
    vector<vector<int> > transposedMatrix (matrix.size(), vector<int>(matrix.size()));
    for(int row = 0; row < matrix.size(); row++){
        for(int col = row + 1; col < matrix[row].size(); col++){
            int temp = matrix[row][col];
            matrix[row][col] =  matrix[col][row];
            matrix[col][row] = temp;
        }
    }

    printMatrix(matrix);

}



int main(){
    vector<int> file = readFile("matrix_input.txt");

    int matrixSize = file[0];

    matrix1 = vector<vector<int> >(matrixSize, vector<int>(matrixSize));
    matrix2 = vector<vector<int> >(matrixSize, vector<int>(matrixSize));
    
    int i = 0;
    for(int row = 0; row < matrixSize; row++){
        for(int col = 0; col < matrixSize; col++){
            i++;
            matrix1[row][col] = file[i];
            matrix2[row][col] = file[i + matrixSize*matrixSize];
        }
    }
    
    printMatrix(matrix1);
    printMatrix(matrix2);
    vector<vector<int> > matrix3 = addMatrix(matrix1, matrix2);
    vector<vector<int> > matrix4 = multiplyMatrix(matrix1, matrix2);
    vector<vector<int> > matrix5 = subtractMatrix(matrix1, matrix2);
    updateMatrix(0, 0, 18);
    maxValue(matrix1);
    transposeMatrix(matrix1);

    return 0;
}
