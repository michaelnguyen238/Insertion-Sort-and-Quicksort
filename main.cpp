//
//  main.cpp
//  Lab 2
//
//  Created by Michael Nguyen on 2/17/16.
//  Copyright © 2016 Michael. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


using namespace std;

void insertionSort(int[], int, int);
void quickSort(int*, int, int);
int partition(int*, int, int, int);


int main(int argc, const char * argv[]) {

   int NUMS_PER_BYTE = 4;
   float* InsertionRunTimes = new float[10];
   float* QuickRunTimes = new float[10];
   int TIMES_TO_RUN_ALGORITHM = 10;
   float t;
   
   
   cout << "What file would you like to open?" << endl;
   string file;
   
   cin >> file;
   
   cout << "Opening " << file << "..." << endl;
   
   ifstream istream;
   
   istream.open(file, ios :: binary);
   
   istream.seekg(0, istream.end);
   int length = istream.tellg() / NUMS_PER_BYTE;
   istream.seekg(0, istream.beg);
   
   if (istream.is_open()) {
      cout << "Successfully opened file." << endl;
      
      //Create array original and read from file into original
      int original[length];
      istream.read((char *)&original, sizeof(original));
      istream.close();
      
      cout << "Insertion sorting..." << endl;
      
      for (int i = 0; i < TIMES_TO_RUN_ALGORITHM; i++) {
         
         int duplicate1[length];
         for (int i = 0; i < length; i++) {
            duplicate1[i] = original[i];
         }
         
         t = clock();
         insertionSort(duplicate1, 1, length - 1);
         t = clock() - t;
         
         InsertionRunTimes[i] = t / (float)CLOCKS_PER_SEC * 1000;
         
         cout << "(" << i + 1 << "/" << "10" << ") ";
         cout << "Completion time: " << t / (float)CLOCKS_PER_SEC * 1000 << " ms" << endl;
      }

      float average = 0;
      
      for (int i = 0; i < TIMES_TO_RUN_ALGORITHM; i++) {
         average += InsertionRunTimes[i];
      }
      
      average /= (float)TIMES_TO_RUN_ALGORITHM;
      
      cout << "Average completion time: " << average << " ms" << endl;
      
      cout << "Quick sorting..." << endl;
      
      for (int i = 0; i < TIMES_TO_RUN_ALGORITHM; i++) {
         int duplicate2[length];
         for (int i = 0; i < length; i++) {
            duplicate2[i] = original[i];
         }
         
         t = clock();
         quickSort(duplicate2, 1, length - 1);
         t = clock() - t;
         
         QuickRunTimes[i] = t / (float)CLOCKS_PER_SEC * 1000;
         
         cout << "(" << i + 1 << "/" << "10" << ") ";
         cout << "Completion time: " << t / (float)CLOCKS_PER_SEC * 1000 << " ms" << endl;
         
      }
      
      average = 0;
      
      for (int i = 0; i < TIMES_TO_RUN_ALGORITHM; i++) {
         average += QuickRunTimes[i];
      }
      
      average /= (float)TIMES_TO_RUN_ALGORITHM;
      
      cout << "Average completion time: " << average << " ms" << endl;
      
   } else {
      cout << "Error! Unable to open file " << file << endl;
      return -1;
   }
   
   delete[] InsertionRunTimes;
   delete[] QuickRunTimes;
   return 0;
}
void insertionSort(int a[], int left, int right) {
   
   for (int i = left; i <= right; i++) {
      int j, temp = a[i + 1]; //make a copy of a[i]
      for (j = i; j >= 0; j--) {
         if (a[j] > temp) {
            a[j + 1] = a[j]; //inversion detected, move a[j] to the right
         }
         else
            break; //index j is where temp belongs
      }
      
      a[j + 1] = temp;
   }
}

void quickSort(int* a, int left, int right) {
   
   int length = abs(left - (right + 1));
   if (length <= 5) {
      insertionSort(a, left, right);
      return;
   }
   int l = a[left];
   int m = a[(left + right) / 2];
   int r = a[right];
   int temp1 = max(l, m);
   int temp2 = max(m, r);
   int temp3 = max(l, r);
   int pivotPos;
   
   if (temp1 == temp2) {
      pivotPos = left;
   } else if (temp2 == temp3) {
      pivotPos = (left + right) / 2;
   } else {
      pivotPos = right;
   }
   
   int newPivot = partition(a, left, right, pivotPos);
   
   quickSort(a, left, newPivot - 1);
   quickSort(a, newPivot + 1, right);
}

int partition(int* a, int left, int right, int pivotIndex) {
   
   int pivotValue = a[pivotIndex];
   swap(a[pivotIndex], a[right]); //move pivotValue to end
   
   //partition array. upon finding an element smaller than pivot,
   //swap it to the next position in the "store"
   
   int store = left;
   for (int i = left; i < right; i++) {
      
      if (a[i] < pivotValue) {
         swap(a[store], a[i]);
         store++;
      }
   }
   swap(a[right], a[store]); //swap pivot to its final position
   return store;
}
