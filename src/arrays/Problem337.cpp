/*
 * Problem337.cpp
 *
 * Created on: feb. 2021
 * Author: Jhonny Vargas Paredes
 * URL: https://www.aceptaelreto.com/problem/statement.php?id=337&cat=13
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

void resolveCase() {
  short int upperTeeth[6];
  short int downTeeth[6];

  for (unsigned int i = 0; i < 6; i++) {
    cin >> upperTeeth[i];
  }

  bool smile = true;

  cin >> downTeeth[0];

  for (unsigned short int j = 1; j < 6; j++) {
    cin >> downTeeth[j];
    smile =
        smile
            && (upperTeeth[j] + downTeeth[j]
                == upperTeeth[j - 1] + downTeeth[j - 1]);
  }

  if (smile) {
    cout << "SI";
  } else {
    cout << "NO";
  }

  cout << '\n';
}

int main(void) {
  std::ios::sync_with_stdio(false);

  short int numOfCases;

  cin >> numOfCases;

  for (unsigned short int i = 0; i < numOfCases; i++) {
    resolveCase();
  }

  return 0;
}
