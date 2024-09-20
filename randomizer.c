#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_left(const char* text) {
    printf("%s\n", text);
}

void print_hash(int length) {
    for (int i = 0; i < length; i++) {
        printf("#");
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    print_left("---------------------------");
    print_left("--------WELCOME TO---------");
    print_left("------Sky RANDOMIZER-------");
    print_left("---------------------------");

    printf("Press SPACE to randomize a RUN...\n\n\n");
    while(_getch() != ' ');

    time_t start_time = time(NULL);

    char* locations[] = {
        "### Isle ###",
        "### Daylight Prairie ###",
        "### Hidden Forest ###",
        "### Valley of Triumph ###",
        "### Golden Wasteland ###",
        "### Vault of Knowledge ###"
    };

    int num_locations = sizeof(locations) / sizeof(locations[0]);

    for (int i = 0; i < num_locations; i++) {
        print_hash(strlen(locations[i]));
        print_left(locations[i]);
        print_hash(strlen(locations[i]));
        print_left(" ");

        int random_number = rand() % 3;

        if (random_number == 0) {
            print_left("You got the first option!");
        } else if (random_number == 1) {
            print_left("You got the second option!");
        } else {
            print_left("You got the third option!");
        }

        print_left(" ");
    }

    printf("\nPress SPACE to stop the timer...\n");
    while(_getch() != ' ');

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    printf("Press any key to exit...\n");
    _getch();

    return 0;
}
