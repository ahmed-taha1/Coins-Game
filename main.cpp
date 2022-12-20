#include <bits\stdc++.h>
using namespace std;

#define NO_GOOD_MOVE  0
#define MAX_MOVE 3
#define HUMAN 1
#define COMPUTER 0
vector<int> piles {7, 8, 9};

bool isBadPosition(int nCoins);

pair<int, int> findGoodMove(int ind = 0) {
    if(ind == 3){
        if(piles[0] > 0)
            return{1, 1};
        else if(piles[1] > 0)
            return{1, 2};
        else
            return{1, 3};
    }
	for (int n = 1; n <= MAX_MOVE; n++){
		if (isBadPosition(piles[ind] - n))
			return {n, ind + 1};
    }
	findGoodMove(ind + 1);
}

bool isBadPosition(int nCoins) {
    if (nCoins == 1)
        return true;
    return
        false;
}

int main() {
    int whoseTurn = HUMAN;
    int pileChoose = 10, coins = 10;
    cout << "Welcome to Nim. We start with 3 piles"<< endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins from a specific pile.\n";

    while (piles[0] > 0 || piles[1] > 0 || piles[2] > 0) {
        cout << "first pile has : " << piles[0] << " coins\n";
        cout << "second pile has : " << piles[1] << " coins\n";
        cout << "third pile has : " << piles[2] << " coins\n";
		cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
            case HUMAN:
                pileChoose = 10;    coins = 10;
                while (pileChoose < 1 || pileChoose > 3 || piles[pileChoose - 1] < 1){
                    cout << "please pick a pile to take coins from it : ";  cin >> pileChoose;
                }
                
                while (coins < 1 || coins > 3 || coins > piles[pileChoose - 1]) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins in this pile: ";  cin >> coins;
                }
                piles[pileChoose - 1]-=coins;
                break;
            case COMPUTER:
                pair<int, int> sol = findGoodMove();
                cout << "Computer choosed pile number" << sol.second << " and computer took from it " << sol.first <<" coins.\n" ;
                piles[sol.second - 1]-=sol.first;
        }
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (whoseTurn ? "Human \n" : "Computer \n");
}
