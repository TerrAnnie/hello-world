#include <iostream>
#include <time.h>
#include <string>
using namespace std;

/* TerrAnnie Scott
   Professer Essmeyer
   Program 1
   2-06-2020

*/
int main() {

    srand(time(0));
    int userScore = 0; //score of the user
    int aiScore = 0; // AI score
    int dieplayer1 = rand() % 6 + 1; // die for player1
    int dieAI = rand() % 6 + 1; // die for player2
    int gameCnt = 0; // Counts how many games have been done
    int roundCount = 1;// Counts how many rounds are done
    int play = 0; // play = true
    string choice; // excepts r or h do you want to roll or hold
    int betagain = 1; // Bet again == true
    int round1 = 1; // Allows to only output score when needed
    int AI_Plays; // Counts how many times a user has played 
    string play_again;
    // move if statement 
    string userName; // Gets the name of the player
    int userPot = 0;// Keeps track of the pot total
    int aiPot = 0;// Keeps track of ai pot
    int fakeScorePlayer = 0;// Calculates what score would be if pot was added to the score
    int fakeScoreAI = 0; // Fakescore for ai
    int roundAI = 0; //Calculates the rounds for AI
    int AIWins = 0;// Calculates how many times AI wins so it can give a winning streak
    int PlayerWins = 0; // Player wins
    cout << "What is your name >>>  "; // ASk for player name 
    cin >> userName;
    cout << endl;

    while (roundCount >= 0) { // If roundCount is anything else the loop will break
        while (gameCnt % 2 == 0 && userScore <= 50 && aiScore <= 50 ) {// Breaks if either player has greater than 50 and gameCnt is incremented each time
            if (round1 == 1) {// So it only outputs one time
                cout << "Score:  " << userName << " :  " << " " << userScore << "  AI : " << aiScore << endl;
                cout << endl;
              
                cout << userName << "'s Turn" << endl;
                cout << "===============" << endl;
                cout << endl;
                round1 = 0;
            }


            dieplayer1 = rand() % 6 + 1; // gives a random number from 1-6
            betagain = 1;

            if (dieplayer1 == 1) { // if the player rolls a one the pot set to sero
                userPot= 0;
                cout << "Die Roll : 1  Bust! " << "Pot has been set to 0" << endl;
                cout << endl;
                gameCnt += 1;
                round1 = 1;
                fakeScorePlayer = userScore;
                break;
            }
            else {
                userPot += dieplayer1; // Add it to the pot and fakeScore, needed so the player doesn't roll too many so it exceeds 50
                fakeScorePlayer += dieplayer1;
               
                cout << "Die : " << dieplayer1 << "  " << "Pot : " << userPot<< "     ";
                if ( fakeScorePlayer >= 50) {// So we can break out of the loop
                    userScore = fakeScorePlayer;
                    break;
                }
                while (betagain == 1) {
                    cout << userName << " would you like to (R)oll or (H)old, r for roll, h for hold. >>>  "; 
               
                    cin >> (choice);
                    if (choice == "R" || choice == "r") {// R or r just in case the enter a lower case will continue their turn
                        betagain = 0;
                        cout << endl;
                    }
                    else if (choice == "H" || choice == "h") { // Otherwise this will exit
                        gameCnt += 1; // add to the game cnt will help in the end so we can tell who goes first each round
                        betagain = 0;
                        round1 = 1;
                        userScore += userPot; // the pot is now added to the score
                        fakeScorePlayer = userScore;// fake score is no reset 
                        userPot = 0;
                        break;
                    }
                    else {
                        cout << userName << " Please enter a valid response , H or R" << endl; // if the dont enter anything valid then this code runs 
                        cout << endl;
                        betagain = 1;
                    }
                }
            }

        }
        cout << endl;
        betagain = 1; //resets beagain
        roundAI = 0;

        
        while (aiScore <= 50 && aiPot <= 20 && gameCnt % 2 != 0 && userScore <= 50) {// Conditions : Aiscore less than 50 and user score less than 50 and they can't roll a pot larger than 20 gamecnt is odd
            if (roundAI == 0) {// Allos the score to print each time the round begins
                cout << "Score:  " << userName << " :" << " " << userScore << "  AI : " << aiScore << endl;
                cout << endl;
                cout << "AI turn" << endl;
                cout << "===============";
                cout << endl;
                cout << endl;
                roundAI = 1;

            }
           
            dieAI = rand() % 6 + 1;
            if (dieAI == 1) {// If 1 is ever rolled then nothing happens and pot is resent
                aiPot = 0;
                cout << "Die Roll : 1  Bust! " << "Pot set to 0!" << endl;
                cout << endl;
                gameCnt += 1;
                fakeScoreAI = aiScore;
                break;
            }
            else {
                aiPot += dieAI;
                fakeScoreAI += dieAI;
                cout << endl;
                cout << "Die : " << dieAI << "  " << "Pot : " << aiPot << endl;
                if (aiPot >= 20) {// If ai Pot is greater than 20 then aiSCore assigned with fake score
                    aiScore = fakeScoreAI;
                    aiPot = 0;
                    gameCnt += 1;
                    break;

                }

                if (fakeScoreAI >= 50) {// exits once it has won
                    aiScore = fakeScoreAI;
                    cout << endl;
                  
                    
                    continue;
                }
                cout << endl;
            }
        }
        if (userScore >= 50 || aiScore >= 50) { //checks to see if there is a winner

            if (aiScore >= 50) { // Ai has one prints the final score, and if a winning streak has occured will print the winning streak
                cout << endl;
                cout << "Final score: " << userName << ": " << userScore << " AI: " << aiScore << endl;
                cout << "AI has won try again next time" << endl;
                cout << endl;
                AIWins += 1; //Adds to their wins 
                PlayerWins = 0;// resets the other players winning streak to 0
                if (AIWins > 1) {
                    cout << "AI has a winning streak of " << AIWins << "!!" << endl; // if the wins is greater than 1 then this will be printed

                }
            }
            else {
                cout << endl; // Player is the winner, prints final score
                cout << "Final score: " << userName << ": " << userScore << " AI: " << aiScore << endl; 
                cout << "Congratulations you have won!!!" << endl;
                PlayerWins += 1; //Adds to winnings
                AIWins = 0; // clears AI winnings
                if (PlayerWins > 1) {
                    cout << userName << " has a winning streak of " << PlayerWins << "!!" << endl;// if they wins is greater than one this will output
                }

            }
            while (play == 0) {
                cout << endl;
                cout << "Would you like to play again? Y for yes and N for no." << endl;
                cin >> play_again;
                cout << endl;
                if (play_again == "Y" || play_again == "y") {// If the play again all scores are reset and pots 
                    gameCnt = 0;
                    userScore = 0;
                    aiScore = 0;
                    roundCount += 1;
                    betagain = 1;
                    round1 = 1;
                    fakeScoreAI = 0;
                    fakeScorePlayer = 0;
                    aiPot = 0;
                    userPot=0;

                    if (roundCount % 2 == 0) {// if the roundnt is divisible by 2 this mean ai goes first 
                 
                        gameCnt += 1;// So game counts is turned into a oddnumber to meet the conditions of the AI loop
                        break;
                    }
                    else {// other wise the user can go first 
                        break;
                    }

                }
                if (play_again == "n" || play_again == "N") {// If n or N then play is reset and roundcount is -1 so everything breaks
                    cout << "Thanks for playing" << endl;
                    play = -1;
                    roundCount = -1;
                    break;
                }

                else {
                    cout << "Please enter a valid response Y for yes and N for no" << endl;// outputs till a valid response is given 
                    continue;
                }


            }
        }

    }

    return 0;
}
