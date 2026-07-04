#include <stdio.h>

int main() {
    int score = 0;
    char answer;

    printf("Welcome to the Quiz Application!\n");
    printf("Answer the following questions:\n\n");

    printf("1. What is the capital of France?\n");
    printf("a) London\n");
    printf("b) Paris\n");
    printf("c) Berlin\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B') {
        score++;
    }

    printf("\n2. What is 2 + 2?\n");
    printf("a) 3\n");
    printf("b) 4\n");
    printf("c) 5\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B') {
        score++;
    }

    printf("\n3. What is the largest planet in our solar system?\n");
    printf("a) Earth\n");
    printf("b) Mars\n");
    printf("c) Jupiter\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    if (answer == 'c' || answer == 'C') {
        score++;
    }

    printf("\nQuiz completed!\n");
    printf("Your score: %d/3\n", score);

    return 0;
}
