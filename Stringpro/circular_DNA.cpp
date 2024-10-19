//
// Created by 19233 on 2024/10/18.
//
#include <iostream>
#include <string>

using namespace std;

std::string solution(std::string dna_sequence) {
    // Please write your code here
    int n=dna_sequence.size(),j=1,k=0,i=0;
    string s=dna_sequence+dna_sequence;
    while (j<n&&i<n&&k<n) {
        char &x=s[i+k],&y=s[j+k];
        if(x==y)
        {
            ++k;
        }
        else {
            if(x>y)
            {
                i=i+k+1;
            }
            else if(x<y)
            {
                j=j+k+1;
            }
            if(i==j)
                ++i;
            k=0;
        }
    }
    int x=min(i,j);
    string a=s.substr(x,dna_sequence.size());
    return a;
}

int main() {
    // You can add more test cases here
    std::cout << (solution("ATCA") == "AATC") << std::endl;
    std::cout << (solution("CGAGTC") == "AGTCCG") << std::endl;
    std::cout << (solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") == "AGGCTGAGTCCATCTCCAGTAGTCATGGAGTGCTCCTGG") << std::endl;
    return 0;
}