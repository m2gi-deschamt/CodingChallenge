#include <vector>

using namespace std ; // :D

vector <long long int> wheatFromChaff (vector <long long int> values) {
  long long int left=0, right=values.size()-1;
  
   while(right > left) {
    
     if(values[right] > 0) {
       right--;
       continue;
     }
     
     if(values[left] < 0) {
       left++;
       continue;
     }
    
     swap(values[left++], values[right--]);
   } 
    
  return values ;
}