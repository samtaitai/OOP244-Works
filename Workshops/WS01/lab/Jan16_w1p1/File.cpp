#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "Movie.h"
#include "File.h"
using namespace std;

namespace sdds {
    FILE* fptr;

    // opens the data file and returns true is successful
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // reads the title of the movie from the global fptr File pointer
    // returns true if successful
    bool readTitle(char title[]) {
        return fscanf(fptr, "%[^(](", title) == 1;
    }

    /*
    fscanf(file pointer, "formatting", save pointer)
    return number of items succesfully filled 

    csv file parsing example
    int read_products(product_t *product) {
        scanf("%[^,],%[^,],%[^,],%lf,%d", product->productType, 
        product->productID, 
        product->productDescription, 
        &product->productPrice, 
        &product->quantityInStock);
    }

    */

    // reads the year of the movie from the global fptr File pointer
    // returns true if successful
    bool readYear(int* year) {
        return fscanf(fptr, "%d)", year) == 1;
    }

    // reads the year of the movie from the global fptr File pointer
    // returns true if successful
    bool readMovieRating(char rating[]) {
        return fscanf(fptr, " %[^|]|", rating) == 1;
    }

    // reads the duration of the movie from the global fptr File pointer
    // returns true if successful
    bool readDuration(int* duration) {
        return fscanf(fptr, "%d|", duration) == 1;
    }

    // reads the genras of the movie from the global fptr File pointer
    // returns true if successful
    bool readGenres(char genre[][11]) { //array([11]) of string(genre[])
        char genres[256];
        int gi = 0; //genres index;
        int i = 0;// genre[i] index
        int j = 0;// genre[i][j] index
        bool res = fscanf(fptr, " %[^|]|", genres);
        if (res) { //spreading csv to array of strings
            res = false;
            while (genres[gi]) {
                if (genres[gi] != ',') { //Comedy, Drama, Romance
                    genre[i][j++] = genres[gi++]; //read C o m e d y
                    res = true;
                }
                else {
                    genre[i][j] = '\0'; //when encounter ',' and then read D r a m a ...go on 
                    i++;
                    gi++;
                    j = 0;
                }
            }
        }
        genre[i++][j] = '\0'; //fail to read any single word; element = \0
        genre[i][0] = '\0'; // NULL terminating the array of strings; string itself = \0
        return res;
    }

    // reads the consumerRating of the movie from the global fptr File pointer
    // returns true if successful
    bool readConsumerRating(float* rating) {
        return fscanf(fptr, "%f\n", rating) == 1;
    }
}



