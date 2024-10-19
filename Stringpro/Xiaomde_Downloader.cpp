//
// Created by 19233 on 2024/10/19.
//
//https://www.marscode.cn/practice/9e2x66jvj9n091?problem_no=70
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, std::vector<std::vector<int>> array) {
  // Edit your code here
  vector<int>diff(array.size()+2,0);

  for(auto&vec:array)
  {
    int &i=vec[0],&j=vec[1];
    if(i>j)
      swap(i,j);
    ++diff[i],--diff[j+1];
  }
  for(int i=1;i<=diff.size();++i)
  {
    diff[i]+=diff[i-1];
  }
  auto x=max_element(diff.begin(),diff.end());
  cout<<*x<<' ';
  return *x;
}

int main() {
  // Add your test cases here
//  std::cout << (solution(2, {{1,2}, {2,3}}) == 2) << std::endl;
  std::cout << (solution(4, {{1,2}, {2,3}, {3,5}, {4,3}}) == 3) << std::endl;

  return 0;
}
