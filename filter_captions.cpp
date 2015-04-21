#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (int argc, char **argv) {
  if (argc < 3) {
     printf("Usage: ./filtering_captions [src] [target] [add_list]\n");
     return -1;
  }

  FILE *fp = fopen(argv[1], "r");
  ifstream fin(argv[3]);
  ofstream fout(argv[2]);

  char captions[1000];
  int idx = 0;
  int val = -1, preVal = -1;
  while (true) {
  //for (int i=0 ; i < 92468 ; i++) {
    fin >> val;
    if (preVal == val)
       break; 
    //printf ("%d", val);
    preVal = val;
    fgets(captions, sizeof(captions), fp);
    while (val > idx) {
       idx++;
       fgets(captions, sizeof(captions), fp);
    }
    fout << captions ;
    idx++;
  }

  fclose(fp);
  fin.close();
  fout.close();
  return 0;
}

       
      
