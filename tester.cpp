#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <deque>
using namespace std;


int main(){
    int n=100;
   
   int s = 0, e = 1;
    while (s+e <= n) {
        int temp = s + e;
        cout<<temp<<" ";
        s = e;
        e = temp;
        
    }
}