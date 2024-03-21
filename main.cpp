#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    
    //static int fileIntegers[100];
    /*
    for(int i = 0; i < sizeof(fileCharacters); i++){
        cout << fileCharacters[i] << "\n";
    }*/
    return fileCharacters;
}

void printMatrix(vector<vector<int> > matrix){
    for(int row = 0; row < matrix.size(); row++){
        for (int col = 0; col < matrix[row].size(); col++){
            cout << matrix[row][col] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int> > addMatrix(vector<vector<int> > matrix1, vector<vector<int> > matrix2){
    vector<vector<int> > returnedMatrix (matrix1.size(), vector<int> (matrix1.size()));

    for(int row = 0; row < matrix1.size(); row++){
        for(int col = 0; col < matrix1[row].size(); col++){
            returnedMatrix[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }

    return returnedMatrix;

}
/*
vector<vector<int> > multiplyMatrix(vector<vector<int> > matrix1, vector<vector<int> > matrix2){
    
}

vector<vector<int> > subtractMatrix(vector<vector<int> > matrix1, vector<vector<int> > matrix2){

}

vector<vector<int> > updateMatrix(vector<vector<int> > matrix){

}


int maxValue(vector<vector<int> > matrix){

}

vector<vector<int> > transposeMatrix(vector<vector<int> > matrix){

}

*/

int main(){
    vector<int> file = readFile("matrix_input.txt");

    int matrixSize = file[0];
    //cout << matrixSize;
    
    int i = 0;
    static vector<vector<int> > matrix1 (matrixSize, vector<int>(matrixSize));
    static vector<vector<int> > matrix2 (matrixSize, vector<int>(matrixSize));
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
    printMatrix(matrix3);

    return 0;
}

/*
for row
    for col

    resultingmatrix row col = matrix1row1 * matrix2 1 col
*/