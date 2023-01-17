#pragma once
#ifndef STD_FILE_H
#define STD_FILE_H
//#ifndef SDDS_FILE_H
//#define SDDS_FILE_H

bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genre[][11]);
bool readConsumerRating(float* rating);

#endif
//#endif