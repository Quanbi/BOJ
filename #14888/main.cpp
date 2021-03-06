#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
  int n;
  int num[101] = {0};
  int temp[101] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    temp[i] = num[i];
  }

  vector<int> v;
  int op[4];
  for (int i = 0; i < 4; i++) {
    cin >> op[i];
    while(op[i]--)  v.push_back(i);
  }
  int minSum = 1000000001;
  int maxSum = -1000000001;
  do{
    int sum = 0;
    memcpy(num,temp,sizeof(temp));
    for (int i = 0; i < n-1; i++) {
      if(v[i] == 0){
        num[i+1] = num[i] + num[i+1];
      }
      else if(v[i] == 1){
        num[i+1] = num[i] - num[i+1];
      }
      else if(v[i] == 2){
        num[i+1] = num[i] * num[i+1];
      }
      else if(v[i] == 3){
        num[i+1] = num[i] / num[i+1];
      }
    }
    sum = num[n-1];
    if(maxSum < sum) maxSum = sum;
    if(minSum > sum) minSum = sum;
  }while(next_permutation(v.begin(), v.end()));
  cout << maxSum << '\n' << minSum;
  return 0;
}
