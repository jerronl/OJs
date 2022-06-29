#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>

// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
vector<int> reverse(vector<int> arr, int l, int r){
  while(l<r)
    swap(arr[l++],arr[r--]);
  return arr;
}

int minOperations(vector <int> arr) {
  // Write your code here
  auto vhash=[](const vector<int>&v)->size_t{
      string s;
      for(auto n:v)
        s+=to_string(n)+",";
      return hash<string>()(s);
  };
  auto vequal=[](const vector<int>&v1,const vector<int>&v2)->bool{
      if (v1.size()!=v2.size())
        return false;
      for(int i=0,n=v1.size();i<n;++i) 
        if(v1[i]!=v2[i])
            return false;
      return true;
  };
  unordered_set<vector<int>,decltype(vhash),decltype(vequal)> S({arr},10,vhash,vequal);
  vector<vector<int>>Q{arr};
  for(int i=0,n=1,r=0,s=arr.size();i<n;n=Q.size(),++r)
    for(;i<n;++i){
        auto cur=Q[i];
        bool ok=true;
        for(int j=1;j<s;++j)
            if(!(ok=cur[j]>cur[j-1]))
                break;
        if(ok)
            return r;
        for(int j=0;j<s-1;++j)
            for(int k=j+1;k<s;++k){
                auto child=reverse(cur,j,k);
                if(!S.count(child)){
                    S.insert(child);
                    Q.push_back(child);
                }
            }
    }
   return -1 ;
}





// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  int n_1 = 5;
  vector <int> arr_1{1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}