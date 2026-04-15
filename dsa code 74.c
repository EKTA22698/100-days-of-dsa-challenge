/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];      // store unique names
    int count[MAX] = {0};      // vote count for each name
    int unique = 0;

    char temp[LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", temp);

        int found = 0;

        // check if name already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        // if new name, add it
        if (!found) {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    // find winner
    int maxVotes = 0;
    char winner[LEN];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}