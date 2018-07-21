/*
  Idea:
    - Remove any duplicated strings.
    - Remove any string if there is any suffix of it exist.
    - Calculate the probability. 
*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TheLotteryBothDivs {
public:
  double find(vector <string> goodSuffixes) {
    sort(goodSuffixes.begin(), goodSuffixes.end());
    goodSuffixes.resize(unique(goodSuffixes.begin(), goodSuffixes.end()) - goodSuffixes.begin());
    
    for(int i = 0; i < goodSuffixes.size(); ++i)
      for(int j = 0; j < goodSuffixes.size(); ++j)
        if(i != j && goodSuffixes[j].size() >= goodSuffixes[i].size() &&
          goodSuffixes[j].substr(goodSuffixes[j].size() - goodSuffixes[i].size()) == goodSuffixes[i]) {
          goodSuffixes.erase(goodSuffixes.begin() + j);
          i = -1;
          break;
        }
    
    double ret = 0;
    for(int i = 0; i < goodSuffixes.size(); ++i)
      ret += pow(10, 9 - goodSuffixes[i].length()) / pow(10, 9);
    
    return ret;
  }
};
