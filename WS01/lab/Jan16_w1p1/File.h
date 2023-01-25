#ifndef SDDS_FILE_H //unless it's defined anywhere, keep compiling
#define SDDS_FILE_H //if it's defined anywhere, ignore body 

namespace sdds {

	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genre[][11]);
	bool readConsumerRating(float* rating);
}

#endif
