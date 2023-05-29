/* source https://www.youtube.com/watch?v=rbVt5v8NNe8 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Student {

	char name[100];
	int stno;
	double gpa;
};

int main() {
	
	FILE *file;

	file = fopen("students.csv", "r");

	if (file == NULL) {
		cout << "Error opening file" << endl;
		return 1;
	}

	Student students[100];

	int read = 0;
	int records = 0;

	do {

		read = fscanf(file, 
			"%99[^,],%d,%lf\n", 
			students[records].name, 
			&students[records].stno, 
			&students[records].gpa);

		if (read == 3) records++;

		if (read != 3 && !feof(file)) {
			cout << "Invalid file format" << endl;
			return 1;
		}

		if (ferror(file)) {
			cout << "Reading file error" << endl;
			return 1;
		}

	} while (!feof(file));

	fclose(file);

	cout << records << "read" << endl;

	for (int i = 0; i < records; i++) {
		cout << students[i].name << " " << students[i].stno << " " << students[i].gpa << endl;
	}

	return 0;
}


