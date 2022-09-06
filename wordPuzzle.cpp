// Nash Steed _ ucq8hz _ Mar 14 2022 _ "wordPuzzle.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
#include "timer.h"
using namespace std;
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

int main(int argc, char** argv){
    hashTable dictionary;

    int rows, cols;
    string line;
  ifstream myfile (argv[1]);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      dictionary.insert(line);
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  readInGrid(argv[2], rows, cols);

  /**timer t;
    t.start();
    */

  int ct=0;
  for(int c=0; c < cols; c++){
    for(int r=0;r<rows;r++){
        for(int l=3;l<23;l++){
            string n=getWordInGrid(r,c,0,l,rows,cols);
            if(n.length()>=l){
                if(dictionary.count(n)>0){
                    cout << "N (" << r << ", " << c << "): " << n << endl;
                    ct++;
                }
            }
            string nE=getWordInGrid(r,c,1,l,rows,cols);
            if(nE.length()>=l){
                if(dictionary.count(nE)>0){
                    cout << "NE (" << r << ", " << c << "): " << nE << endl;
                    ct++;
                }
            }
            string E=getWordInGrid(r,c,2,l,rows,cols);
            if(E.length()>=l){
                if(dictionary.count(E)>0){
                    cout << "E (" << r << ", " << c << "): " << E << endl;
                    ct++;
                }
            }
            string sE=getWordInGrid(r,c,3,l,rows,cols);
            if(sE.length()>=l){
                if(dictionary.count(sE)>0){
                    cout << "SE (" << r << ", " << c << "): " << sE << endl;
                    ct++;
                }
            }
            string S=getWordInGrid(r,c,4,l,rows,cols);
            if(S.length()>=l){
                if(dictionary.count(S)>0){
                    cout << "S (" << r << ", " << c << "): " << S << endl;
                    ct++;
                }
            }
            string sW=getWordInGrid(r,c,5,l,rows,cols);
            if(sW.length()>=l){
                if(dictionary.count(sW)>0){
                    cout << "SW (" << r << ", " << c << "): " << sW << endl;
                    ct++;
                }
            }
            string W=getWordInGrid(r,c,6,l,rows,cols);
            if(W.length()>=l){
                if(dictionary.count(W)>0){
                    cout << "W (" << r << ", " << c << "): " << W << endl;
                    ct++;
                }
            }
            string nW=getWordInGrid(r,c,7,l,rows,cols);
            if(nW.length()>=l){
                if(dictionary.count(nW)>0){
                    cout << "NW (" << r << ", " << c << "): " << nW << endl;
                    ct++;
                }
            }
        }
    }
  }
  
  cout << ct << " words found" << endl;
  /**for (int i = 0; i < 1000000000; i++) {}
    t.stop();
    cout << t << endl;
    cout << t.getTime() << endl;
  return 0;
  */
}