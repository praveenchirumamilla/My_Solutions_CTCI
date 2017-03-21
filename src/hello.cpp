#include <iostream>
#include "console.h"

#include "grid.h"
#include "vector.h"
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
#include "set.h"
#include "map.h"
#include "hashmap.h"
#include "string.h"
using namespace std;

void permute(string str);
void permuteHelp(string str, string &chosen);
void sublist(Vector<string> v);
void sublistHelp(Vector<string> &v, Vector<string>& chosen);

int main() {

    //diceRoll(2);
   // diceSum(3, 16);
    //permute("marty");
    Vector<string> prav;
    prav += "jane";
    prav += "bob";
    prav += "sara";
    prav += "matt";
    sublist(prav);
    return 0;
}

void sublist(Vector<string> v){
    Vector<string> chosen;
    cout << chosen.toString() << endl;


    for(int i = 0; i < v.size(); i++){
        chosen.add(v[i]);
        v.remove(i);
        sublistHelp(v, chosen);

    }
    chosen.remove(chosen.size()-1);


}

void sublistHelp(Vector<string>& v, Vector<string>& chosen){

    cout << chosen.toString() << endl;
    for(string s : v){
      chosen.add(s);

      cout << chosen.toString() << endl;
      chosen.remove(chosen.size()-1);
    }
}



void permute(string str){
    string chosen = "";
    permuteHelp(str, chosen);
}

void permuteHelp(string str, string& chosen){
    if(str == ""){
        cout << chosen << endl;
    }else{
        for(int i = 0; i < str.length(); i++){
            chosen += str[i];
            str.erase(i, 1);
            permuteHelp(str, chosen);

            str.insert(i, 1, chosen[chosen.length()-1]);
            chosen.erase(chosen.length()-1, 1);
        }
    }

}

void diceRollHelp(int n, string soFar){
    if(n == 0){
        cout << "{" << soFar <<  "}" << endl;
    }else{
        if(n > 1)
            soFar += " , ";
        for(int i = 1; i <= 6; i++ ){

            diceRollHelp(n-1, soFar+ integerToString(i));
        }
    }
}

void diceRoll(int n){
    diceRollHelp(n, "");
}

void diceSumHelper(int n, int sum, Set<int>& chosen){
    if(n == 0){
        int temp = 0;
        for(int i : chosen){
            temp += i;
        }
        if(temp == sum){
          cout << chosen.toString() << endl;
        }
    }else{
        for(int i = 1; i <= 6; i++){
            chosen.add(i);
            diceSumHelper(n-1, sum, chosen);
            chosen.remove(i);
        }

    }
}

void diceSum(int n, int sum){
    Set<int> chosen;
    diceSumHelper(n, sum, chosen);
}
