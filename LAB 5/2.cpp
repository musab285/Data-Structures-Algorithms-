// Assume you are developing a program to simulate a game where players take turns to guess
// a number between 1 and 100. The program generates a random number between 1 and 100 at the
// start of the game, and the player who guesses the correct number wins the game. If a player guesses
// incorrectly, the program tells them whether their guess was too high or too low, and the turn passes
// to the next player. Solve it using Direct Recursion?

#include<bits/stdc++.h>
using namespace std; 

int game(int plnum, int tar){
    int x ; cout<<"Player # "<<plnum<<"Enter your guess: "; cin >> x; 
    if(x==tar) return plnum; 
    if(x<tar) {
        cout<<"Too low"<<endl; 
        return game(plnum+1, tar);
    }
    cout<<"Too High"<<endl; 
    return game(plnum+1, tar);
}

int main(){
    int tar = rand()%100; 
    int win = game(1, tar);
    cout<<"Player # "<<win<<" won !!"<<endl; 
}