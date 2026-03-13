#include <vector>

using namespace std ; 

void swap(long long int &value1, long long int &value2) {
  int save = value1;
  value1 = value2;
  value2 = save;
}

vector <long long int> wheatFromChaff (vector <long long int> values) {
  
  for (long long int i = 0; i < values.size(); i++) {
    if(values[i] > 0) {
      long long int lastNegativeIndex=-1;
      for(long long int rest = i+1; rest<values.size(); rest++) {
        if(values[rest] < 0) lastNegativeIndex = rest;        
      }
      if(lastNegativeIndex == -1) break;
      swap(values[i], values[lastNegativeIndex]);
    }
  }
  return values ;
}