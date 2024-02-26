//
// Created by Abdu on 13/02/24.
//

#include "MatrixDisplay.hpp"


MatrixDisplay::MatrixDisplay(std::string rMessage) : aMessage(std::move(rMessage)) {}

void MatrixDisplay::MessageToMatrixDisplay() {
    int currentColumn = 0;
    for (char i: aMessage) {
        CharToMatrixDisplay(i, currentColumn);
        if (i == '.' or i == ',') {
            currentColumn += 2;
        } else {
            currentColumn += MATRIX_COLUMN_NUMBER + 1;
        }
    }
}


void MatrixDisplay::CharToMatrixDisplay(unsigned char symbol, int currentColumn) {
    for (int i = 0; i < MATRIX_ROW_NUMBER; i++) {
        for (int jj = 0, j = currentColumn; j < currentColumn + MATRIX_COLUMN_NUMBER; j++, jj++) {
            aMatrixDisplay[i][j] = ((1 << jj)) & ASCII_TO_DOT_MATRIX[symbol][i];
        }
    }
}


void MatrixDisplay::ConvertToMatrixMessage() {
    MessageToMatrixDisplay();
    for (int i = 0; i < MATRIX_ROW_NUMBER; i++) {
        for (int j = 0; j < DISPLAY_COLUMN_NUMBER; j++) {
            if (aMatrixDisplay[i][j]) {
                aMatrixMessageDisplay[i][j] = "■";
            } else {
                aMatrixMessageDisplay[i][j] = ' ';
            }
        }
    }

}

void MatrixDisplay::DisplayMatrixMessage() {
    ConvertToMatrixMessage();
    for (auto &  i : aMatrixMessageDisplay) {
        for ( const std::string& j : i) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

