//
// Created by 19233 on 2024/10/12.
//
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;


bool backtrack(vector<int> &A, multiset<int> &sums, int n);
bool reconstruct(int n, vector<int> sorted_sums, vector<int> &A);


bool backtrack(vector<int> &A, multiset<int> &sums, int n) {
    if (A.size() == n) {
        return true;
    }

    int sum_next = *sums.begin();
    int A0 = A[0];
    int Ak = sum_next - A0;

    vector<int> required_sums;
    for(auto &x: A){
        required_sums.push_back(x + Ak);
    }

    for(auto &x: required_sums){
        if(sums.find(x) == sums.end()){
            return false;
        }
    }

    for(auto &x: required_sums){
        auto it = sums.find(x);
        if(it != sums.end()){
            sums.erase(it);
        }
        else{
            for(auto &y: required_sums){
                sums.insert(y);
            }
            return false;
        }
    }

    A.push_back(Ak);

    if(backtrack(A, sums, n)){
        return true;
    }

    A.pop_back();
    for(auto &x: required_sums){
        sums.insert(x);
    }

    return false;
}


bool reconstruct(int n, vector<int> sorted_sums, vector<int> &A) {
    if(n < 2){
        return false;
    }

    for(int i = 0; i < sorted_sums.size(); ++i){
        for(int j = i+1; j < sorted_sums.size(); ++j){
            for(int k = j+1; k < sorted_sums.size(); ++k){
                int sum1 = sorted_sums[i];
                int sum2 = sorted_sums[j];
                int sum3 = sorted_sums[k];

                if( (sum1 + sum2 - sum3) % 2 != 0 ){
                    continue;
                }

                int A0 = (sum1 + sum2 - sum3) / 2;
                int A1 = sum1 - A0;
                int A2 = sum2 - A0;

                if( (A1 + A2) != sum3 ){
                    continue;
                }

                vector<int> tempA = {A0, A1, A2};

                multiset<int> sums(sorted_sums.begin(), sorted_sums.end());
                auto it = sums.find(sum1);
                if(it != sums.end()) sums.erase(it);
                else continue;

                it = sums.find(sum2);
                if(it != sums.end()) sums.erase(it);
                else continue;

                it = sums.find(sum3);
                if(it != sums.end()) sums.erase(it);
                else continue;

                if(backtrack(tempA, sums, n)){
                    A = tempA;
                    sort(A.begin(), A.end());
                    return true;
                }
            }
        }
    }

    return false;
}

std::string solution(int n, std::vector<int> sums) {
    // Please write your code here
    sort(sums.begin(),sums.end());
    vector<int>ans;
    bool sq= reconstruct(n,sums,ans);
    string a;
    if(sq)
    {
        for(auto i:ans)
            a+= to_string(i)+' ';
        a.pop_back();
        return a;
    }
    else
    {
        return "Impossible";
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // You can add more test cases here
    std::vector<int> sums1 = {1269, 1160, 1663};
    std::vector<int> sums2 = {1, 1, 1};
    std::vector<int> sums3 = {226, 223, 225, 224, 227, 229, 228, 226, 225, 227};
    std::vector<int> sums4 = {-1, 0, -1, -2, 1, 0, -1, 1, 0, -1};
    std::vector<int> sums5 = {79950, 79936, 79942, 79962, 79954, 79972, 79960, 79968, 79924, 79932};

    std::cout << (solution(3, sums1) == "383 777 886") << std::endl;
    std::cout << (solution(3, sums2) == "Impossible") << std::endl;
    std::cout << (solution(5, sums3) == "111 112 113 114 115") << std::endl;
    std::cout << (solution(5, sums4) == "-1 -1 0 0 1") << std::endl;
    std::cout << (solution(5, sums5) == "39953 39971 39979 39983 39989") << std::endl;

    return 0;
}
