#pragma once
class NumMatrix {
private:
	vector<vector<int>> sumMatrix;
	vector<vector<int>> matrix;
	int nRow;
	int nCol;
public:
	NumMatrix(vector<vector<int>> &matrix) {
		this->matrix = matrix;
		nRow = static_cast<int>(matrix.size());
		if (nRow) {
			nCol = static_cast<int>(matrix.back().size());
			sumMatrix = vector<vector<int>>(nRow + 1, vector<int>(nCol + 1, 0));
			for (int i = 1; i < nRow + 1; i++) {
				for (int j = 1; j < nCol + 1; j++) {
					sumMatrix[i][j] = sumMatrix[i - 1][j] + sumMatrix[i][j - 1] - sumMatrix[i - 1][j - 1] + matrix[i - 1][j - 1];
				}
			}
		}
		
	}

	void update(int row, int col, int val) {
		int oldVal = matrix[row][col];
		matrix[row][col] = val;
		int diff = val - oldVal;
		if (diff != 0) {
			for (int i = row + 1; i < nRow + 1; i++) {
				for (int j = col + 1; j < nCol + 1; j++) {
					sumMatrix[i][j] = sumMatrix[i][j] + diff;
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sumMatrix[row2 + 1][col2 + 1] - sumMatrix[row1][col1];
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);