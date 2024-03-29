#include <iostream>
#include <string>
#include <random>

using namespace std;

// Function prototypes
void zgenerator(string& word, int& index);
void kgenerator(string& word, int& index);
void ggenerator(string& word, int& index);
void mgenerator(string& word, int& index);

/*
<Z>::=(<K>) ♥
<K>::=<G><M> ♥
<G>::=ν|<Z> ♥
<M>::=-<K>|+<K>|ε ♥

time bomb ♥
*/

//random deciders
int decideOneInTwo() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 2);
    return distribution(gen);
}

int decideOneInThree() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 3);
    return distribution(gen);
}

//functions for each iteration that print after the outcome and a global variable that stops them

//the number that kills the program after 150 iterations
int timebomb = 0;

//random_of_session is the random number decided when the function is called
int random_of_session;

//<M>::=-<K>|+<K>|ε ♥
void mgenerator(string& word, int& index){

    timebomb++;
    if (timebomb >= 150)
    {
        return;
    }

    random_of_session = decideOneInThree();
    if(random_of_session == 1){
        word.replace(index, 3, "-<K>");
        index++;
        cout << word << endl;
        kgenerator(word, index);
    }
    else if(random_of_session == 2){
        word.replace(index, 3, "+<K>");
        index++;
        cout << word << endl;
        kgenerator(word, index);
    }
    else{
        word.replace(index, 3, "");
        cout << word << endl;
    }
}

//<G>::=ν|<Z> ♥
void ggenerator(string& word, int& index){

    timebomb++;
    if (timebomb >= 150)
    {
        return;
    }

    random_of_session = decideOneInTwo();
    if (random_of_session == 1)
    {
        word.replace(index, 3, "v");
        index++;
        cout << word << endl;
    } 
    else {
        word.replace(index, 3, "<Z>");
        cout << word << endl;
        zgenerator(word, index);
    }
}

//<K>::=<G><M> ♥
void kgenerator(string& word, int& index){

    timebomb++;
    if (timebomb >= 150)
    {
        return;
    }

    word.replace(index, 3, "<G><M>");
    cout << word << endl;
    //edit G
    ggenerator(word,index);
    //edit M
    mgenerator(word,index);
}

//<Z>::=(<K>) ♥
void zgenerator(string& word, int& index){

    timebomb++;
    if (timebomb >= 150)
    {
        return;
    }
    
    word.replace(index, 3, "(<K>)");
    index ++;
    cout << word << endl;
    kgenerator(word, index);
    index++;
}

int main(){
    int index = 0;
    string answer = "<Z>";
    cout << answer << endl;
    zgenerator(answer, index);
    cout << answer << endl;
    system("pause");
    return 0;
}
