//
// Created by 19233 on 2024/10/18.
//
#include <iostream>
#include <string>
#include <bitset>
#include <map>

using namespace std;

char dic[]={'9', '8', '7', '6','5','4','3','2','1','0','m', 'n', 'b', 'v', 'c',  'x',  'z',  'a',  's',  'd',  'f',  'g',  'h',  'j',  'k',  'l',  'p',  'o',  'i',  'u',  'y',  't'};
map<char,int>has;

void precope()
{
    int e=0;
    for(const auto&i:dic)
    {
        has.insert({i,e++});
    }
}

int rever(const string& rawstr,int x)
{
    int res=0,i=5,e=1;
    while (i--) {
        res+=(rawstr[x+i]-'0')*e;
        e*=2;
    }
    return res;
}
int ren(const string&encodedSter,int x)
{
    int res=0,i=8,e=1;
    while (i--) {
        res+=(encodedSter[x+i]-'0')*e;
        e*=2;
    }
    return res;
}

string encode(const string &rawStr)
{
    string pre;
    int flag,raw;
    for(const auto &i:rawStr)
    {
        if(i==',')
            continue;
        pre+=bitset<8>(i).to_string();
    }
    raw=pre.size()%40;
    switch (raw) {
        case 8:
            raw=6;
            break;
        case 16:
            raw=4;
            break;
        case 24:
            raw=3;
            break;
        case 32:
            raw=1;
            break;
        default:
            raw=0;
    }

    flag=5-pre.size()%5;
    flag=flag==5?0:flag;
    pre+=string(flag,'0');
    string enco;
    for(int i=0;i<pre.size();i+=5)
    {
        enco+=dic[rever(pre, i)];
    }
    enco+=string (raw,'+');
    cout<<enco;
    return enco;
}

int count_plus(const string&encodedSter,int x)
{
    int cnt=1;
    for(int i=x+1;i<encodedSter.size();++i)
    {
        if(encodedSter[i]!='+')
        {
            break;
        }
        ++cnt;
    }
    return cnt;
}

string decode(const string &encodedStr)
{
//    int flag;
//    for(int i=encodedStr.size()-1;i>=0;--i)
//    {
//        if(encodedStr[i]!='+')
//        {
//            flag=encodedStr.size()-i-1;
//            break;
//        }
//    }
    string res,ans;
    int flag;
    for(int i=0;i<encodedStr.size();)
    {
        if(encodedStr[i]=='+')
        {
            flag=count_plus(encodedStr,i);
            i+=flag;
            switch (flag)
            {
                case 6:
                    flag=1;
                    break;
                case 4:
                    flag=2;
                    break;
                case 3:
                    flag=3;
                    break;
                case 1:
                    flag=4;
                    break;
                default:
                    flag=0;
            }

            int sie=res.size()/40+flag*8;
            for(int j=0;j<sie;j+=8)
            {
                ans+=ren(res,j);
            }
            res.clear();
        }
        else
        {
            res+=bitset<5>(has[encodedStr[i]]).to_string();
            ++i;
        }
    }
//    cout<<ans<<endl;
    return ans;
}


std::string solution(std::string rawStr, std::string encodedStr) {
    // Please write your code here
    return encode(rawStr)+':'+decode(encodedStr);
}

int main() {
    // You can add more test cases here
    precope();
//    std::cout << (solution("foo", "b0zj5+++") == "bljhy+++:bar") << std::endl;
    std::cout << (solution("The encoding process represents 40-bit groups of input bits as output strings of 8 encoded characters. Proceeding from left to right, a 40-bit input group is formed by concatenating 5 8bit input groups. These 40 bits are then treated as 8 concatenated 5-bit groups, each of which is translated into a single character in the base 32 alphabet.  When a bit stream is encoded via the base 32 encoding, the bit stream must be presumed to be ordered with the most-significant- bit first. That is, the first bit in the stream will be the high- order bit in the first 8bit byte, the eighth bit will be the low- order bit in the first 8bit byte, and so on.", "bljhy+++b0zj5+++")
    == "maf3m164vlahyl60vlds9i6svuahmiod58l3mi6sbglhmodfcbz61b8vb0fj1162c0jjmi6d58jhb160vlk2mu89b0fj1il9b4ls9oogcak2mu89cvp25pncbuls9oo359i79lncbvjh1ln558ahzknsb4aj1lnscbj7917zc0jh3ln4bafhill9bll3yo09vashbu89cajs9id0buf21n89b5z61b8vb0fj1160vlk2mu89bul3yunz58fj3163vul3pln558a2s166vuj33knfbgj37u60vlds9v0928a3su89v4j29unf58dj5oogc8lsi17fv8sj3l093zk79kd0cals9knsbfz21p64vkz21id4b4p3ml89b4ls9c89bvjhiko8cashiknfbgs79v0vb0fj1162c0jjmi6d4zz3mkn6v9z3yla9cuf3sko158fj316fc0zhiiobb4p3ml89v4j21ol9b5z23pncbuh3m166v8zj5kn6casj5160vkz21p6458a37io459ld5168vak3zkn7bgp7i189muf3moa9b5z35pnf58lj1id4b4hs9pnd58shikoxbash116hv4zs9u61bfz35kndbfz63ba9bgj33oo5v4j3cn89caf3m167v4p79iofc0sh7o09vgpj3u89b0ss9i6sbgljmon4bzz21ol9b0ss9oosbasj5ln558ohsu6158p3zl09vgjj3u8vcvfhcod0blfh3kncczhs9kd0czz3bpnscvp7i17fv8zj1160cbh79u61bfz3bpnscvp79kd0czz3soa9caf3m16dcal3mknv58ohso6b58a3m16fv8ss9p60buf7p16xc0s3mia9b0fj1160vkz21p6458d3siddczz6zkd0czz35ynfbfh79u61bfz3mpn2v8p3z167v4p79uo0vah79kd458p3zl09vajjcn09vul31lns58a3su89v4j79u61bfz3bpnscvp79c67v4p79kdlcassk168vls79iox58jhinz+:foobar")
    << std::endl;

    return 0;
}