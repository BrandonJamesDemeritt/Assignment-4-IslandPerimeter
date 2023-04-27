#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//declare function with prototype
int calc_perimeter(const vector<vector<unsigned int>>&);

int main() {

	//declare variables
	unsigned int rows;
	unsigned int columns;
	unsigned int i;
	unsigned int j;
	unsigned int tempNum;
	vector<vector<unsigned int>> island;

	// open input file
	ifstream fin("island.txt");

	//test input file
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//create output file
	ofstream fout("preimeter.txt");

	//read in rows and columns from file
	fin >> rows;
	fin >> columns;

	//read in vector of island
	island.resize(rows);
	while (fin) {
		for (i = 0; i < rows; ++i) {
			for (j = 0; j < columns; ++j) {
				fin >> tempNum;
				island.at(i).push_back(tempNum);
			}
		}
	}

	//write to output file and call cal_perimeter
	fout << "Prerimeter is : " << calc_perimeter(island);

	//close files and exit
	fout.close();
	fin.close();
	return 0;
}

/*	Calculates the perimeter of the island map
*	@Param vector of a vector of unsigned int
*	@returns the caculated perimeter of the island
*/
int calc_perimeter(const vector<vector<unsigned int>>& land) {

	//declare varaiables used by function
	int perimeter = 0;
	unsigned int y;
	unsigned int x;

	//iterate through the rows
	for (y = 0; y < land.size(); ++y) {

		//iterate through the columns
		for (x = 0; x < land.at(y).size(); ++x) {
			
			//check if land at current position, if so continue to calculate
			if (land.at(y).at(x)) {

				//check if left edge at current position
				if (x != 0) {

					//check if land exists left of current position and add to perimeter if not
					if (!land.at(y).at(x - 1)) {
						perimeter += 1;
					}
				} 
				else { //if at left edge, add to perimeter
					perimeter += 1;
				}

				//check if right edge at current position
				if (x != land.at(y).size() - 1) {

					//check if land is right of current position and add to perimeter if not 
					if (!land.at(y).at(x + 1)) {
						perimeter += 1;
					}
				}
				else { //if at right edge, add to perimeter
					perimeter += 1;
				}

				//check if top edge at current position
				if (y != 0) {

					//if not top edge, check if land above current position and add to perimeter if not
					if (!land.at(y - 1).at(x)) {
						perimeter += 1;
					}
				}
				else { //if at top edge, add to perimeter
					perimeter += 1;
				}

				//check if bottom edge at current position
				if (y != land.size() - 1) {

					//if not at bottom, check if land below current position and add to perimeter if not
					if (!land.at(y + 1).at(x)) {
						perimeter += 1;
					}
				}
				else { //if at bottom edge, add to perimeter
					perimeter += 1;
				}
			}
		}
	}
	return perimeter;
}