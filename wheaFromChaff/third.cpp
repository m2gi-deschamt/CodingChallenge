/*
Ce qui est vraiment trop cool :
ranges::partition(container, condition) --> [éléments qui vérifient la condition | autres éléments]
return ranges::partition(v, ...), v; --> l’opérateur virgule. execute a, return b


*/

#include <range/v3/algorithm/partition.hpp>
using namespace std;
vector<long long> wheatFromChaff( vector<long long> v ) {
  return ranges::partition( v, []( auto n ){ return n < 0; }), v;
}