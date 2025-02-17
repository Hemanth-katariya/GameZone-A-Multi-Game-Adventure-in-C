#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
#endif

#define MAX_WIDTH 31
#define MAX_HEIGHT 31
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#define sf scanf
#define pf printf
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

#define MAXRANDOMVALUE 3
#define MAXPREV 500
int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;

}
#endif

#define MAX_WIDTH 31
#define MAX_HEIGHT 31
#define RED 0
#define BLACK 1
#define GREEN 2

#define EVEN 0
#define ODD 1

#define MIN_BET 1
#define MAX_BET 1000

#define PLAYER_HEALTH 100
#define ENEMY_HEALTH 100
// Function to set text color to Magenta and underline
void yellow_underline()
{
    printf("\033[4;33m");
}

// Function to set text color to Magenta
void magenta()
{
    printf("\033[0;35m");
}

// Function to set text color to Cyan
void cyan()
{
    printf("\033[0;36m");
}
// Function to set text color to red
void red()
{
    // Set text color to red
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

// Function to set text color to green
void green()
{
    // Set text color to green
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

// Function to set text color to yellow
void yellow()
{
    // Set text color to yellow
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
}

// Function to set text color to blue
void blue()
{
    // Set text color to blue
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}

// Function to set text color to white
void white()
{
    // Set text color to white
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Function to set text color to green and underline
void green_underline()
{
    // Set text color to green and underline
    printf("\033[32;4m");
}

// Function to print text with typing effect
void printWithTypingEffect(const char *text, int delay) {
    while (*text) {
        putchar(*text++);
        fflush(stdout); // Flush the output buffer to ensure text is printed immediately
        usleep(delay * 40); // Sleep for 'delay' milliseconds
    }
}

// Function to start the program
void start() {
    system("cls"); // Clear the console screen
    // Displaying the project title with typing effect
    cyan();
    printWithTypingEffect("                      _____     _____     __      ___      __  \n", 50);
    printWithTypingEffect("                     / ____|   / ____|   /_ |    / _ \\    /_ \\ \n", 50);
    printWithTypingEffect("                    | |       | (___      | |   | | | |     ) |\n", 50);
    printWithTypingEffect("*****************   | |        \\___ \\     | |   | | | |    / /    *****************\n", 50);
    printWithTypingEffect("                    | |____    ____) |    | |   | |_| /   / /_ \n", 50);
    printWithTypingEffect("                     \\_____|  |_____/     |_|    \\___/    |___|\n\n\n", 50);
    // Displaying project name and team members with typing effect
    white();
    printWithTypingEffect("PROJECT NAME - ", 50);
    red();
    printWithTypingEffect("*", 50);
    yellow_underline();
    printWithTypingEffect("GAME ZONE", 50);
    red();
    printWithTypingEffect("*\n\n", 50);

    blue();
    printWithTypingEffect("SUBMITTED BY Project Group 22 :-\n", 50);

    green_underline();
    printWithTypingEffect("Shashwat Kumar Singh ", 50);
    cyan();
    printWithTypingEffect("(2301CS50)\n", 50);

    green_underline();
    printWithTypingEffect("Shresth Kasyap ", 50);
    cyan();
    printWithTypingEffect("(2301AI22)\n", 50);

    green_underline();
    printWithTypingEffect("Kumar Aryan Raj ", 50);
    cyan();
    printWithTypingEffect("(2301CB22)\n", 50);

    green_underline();
    printWithTypingEffect("Ranjeet Maurya ", 50);
    cyan();
    printWithTypingEffect("(2301CB51)\n", 50);

    green_underline();
    printWithTypingEffect("Devanshu Kumar ", 50);
    cyan();
    printWithTypingEffect("(2301CT22)\n", 50);

    green_underline();
    printWithTypingEffect("Geetha Priya Anand ", 50);
    cyan();
    printWithTypingEffect("(2301CE42)\n", 50);

    green_underline();
    printWithTypingEffect("Mohammad Meraj Ahmad ", 50);
    cyan();
    printWithTypingEffect("(2301CE50)\n", 50);

    green_underline();
    printWithTypingEffect("Hemanth Kumar Katariya ", 50);
    cyan();
    printWithTypingEffect("(2301CS22)\n", 50);

    green_underline();
    printWithTypingEffect("Rohit Gupta ", 50);
    cyan();
    printWithTypingEffect("(2301EE22)\n", 50);

    green_underline();
    printWithTypingEffect("Rajith Kumar Mantrabuddi ", 50);
    cyan();
    printWithTypingEffect("(2301EC22)\n", 50);

    white();
    printf("\nPress Enter to continue...\n");
    getchar();
}
int mountain();
void magicAttack(int *enemyHealth);
void swordAttack(int *enemyHealth);
int game();

void magicAttack(int *enemyHealth) {
    int damage = rand() % 15 + 10;  // Damage ranges from 10 to 24
    printf("\nYou cast a powerful spell!\n");
    *enemyHealth -= damage;
    printf("You deal %d damage.\n", damage);
}

void swordAttack(int *enemyHealth) {
    int damage = rand() % 10 + 5;  // Damage ranges from 5 to 14
    printf("\nYou swing your mighty sword!\n");
    *enemyHealth -= damage;
    printf("You deal %d damage.\n", damage);
}

int game() {
    int playerHealth = PLAYER_HEALTH;
    int enemyHealth = ENEMY_HEALTH;
    int choice;

    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to Battle Arena!\n");
    printf("Both you and your enemy start with 100 health points.\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\nYour health: %d, Enemy's health: %d\n", playerHealth, enemyHealth);
        printf("Choose your attack method:\n");
        printf("1. Magic Attack\n");
        printf("2. Sword Attack\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                magicAttack(&enemyHealth);
                break;
            case 2:
                swordAttack(&enemyHealth);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                continue;
        }

        // Enemy attacks back if still alive
        if (enemyHealth > 0) {
            int enemyDamage = rand() % 12 + 6;  // Enemy damage ranges from 6 to 17
            playerHealth -= enemyDamage;
            printf("The enemy attacks back and deals %d damage.\n", enemyDamage);
        }
    }

    if (playerHealth <= 0) {
        printf("You are defeated! Game over.\n");
        return 0;
    } else if (enemyHealth <= 0) {
        printf("You have defeated the enemy! Victory!\n");
        return 1;
    }


}
int adventure()
{
    int c1, c2, c3, c4, c5, c6, c7, point = 0, creaturepoint = 0, temp, x = 0;
    char yes[20], charr;
    pf("*************-------------------***************\n");

    pf("Escape from Shadow Island: The Depths Unveiled\n");
    pf("------Level 1: The Awakening------\n");
    pf("You are an adventurer who has crash-landed on the infamous Shadow Island,\na place rumored to be cursed with eternal darkness and inhabited by mysterious creatures.\nYour goal is to find the way off the island by navigating through treacherous terrain, solving puzzles, and making critical decisions.\nAlong the way, you'll uncover the secrets of the island and find out that the darkness is not just a lack of light but something far more sinister.\n");
start:
    pf("After regaining consciousness on the storm-ravaged beach, you face the first decision on your path to escape.\n");
    pf("CHOICE 1:Head into the dense , whispering forest.\n");
    pf("CHOICE 2:Explore the ominously silnet cave.\n");
    pf("CHOICE 3:Climb the steep,fog-shrouded mountain.\n");
    scanf("%d", &c1);

    if (c1 == 1)
    {
    first:
        point = 0, creaturepoint = 0;
        pf("You enter the forest and hear a sudden growl\n");
        pf("CHOICE 1:Investigate the source of the growl\n");
        pf("CHOICE 2:Continue deeper into the forest ignoring the sound\n");
    c22:
        scanf("%d", &c2);
        if (c2 == 1)
        {
            pf("The Growl leads to a clearing ,where a shadowy figure waits\n");
            pf("You got two choices now\n");
            pf("CHOICE 1:Attempt to communicate with it\n");
            pf("CHOICE 2:Try to sneak around the creature\n");
        c33:
            scanf("%d", &c3);
            if (c3 == 1)
            {
                pf("The creature offers a deal for safe passage\n");
                pf("CHOICE 1:Accept the creature's deal\n");
                pf("CHOICE 2:Decline and prepare for a confrontation\n");
            c4:
                scanf("%d", &c4);
                if (c4 == 1)
                {
                gohere:
                    pf("He offers to let you go if you defeat him in the battle of SOMETHING\n");
                    while (point < 100 && creaturepoint < 100)
                    {
                        pf("PRESS 1 TO  ATTACK\nPRESS 2 TO DEFENSE\n");
                        scanf("%d", &temp);
                        if (temp == 1)
                        {
                            srand(time(0));
                            point += rand() % 15;
                            creaturepoint += rand() % 16;
                            pf("Great shot!! \n");
                        }
                        else if (temp == 2)
                        {
                            point += rand() % 10;
                            creaturepoint += rand() % 9;
                            pf("Nice defence \n");
                        }
                        else
                        {
                            pf("Wrong Input\n");
                        }
                        pf("YOUR POINTS:%d\nCREATURE POINTS:%d\n", point, creaturepoint);
                    }
                    if (point >= creaturepoint)
                    {
                        pf("You truly are a warrior ggs\n");
                        printf("\n Press any key to continue ..."); //rohit
                        getch();
                        main();
                        return 1;
                    }
                    else
                    {
                        pf("You lost.\n ");//rohit
                        pf("WOULD YOU LIKE TO START AGAIN?y/n");
                        scanf("%s", yes);
                        if (yes[0] == 'y' || yes[0] == 'Y')
                        {
                            goto start;
                        }
                        else{
                        printf("\n Press any key to continue ..."); //rohit
                        getch();
                        main();
                        }
                    }
                }
                else if (c4 == 2)
                {
                    pf("The monster kills you with their fangs");
                    pf("Would you like to play again?y/n");
                    scanf("%s", &charr);
                    if (charr == 'y' || charr == 'Y')
                    {
                        goto start;
                    }
                    else
                        return 0;
                }
                else
                {
                    pf("Wrong Input\n");
                    goto c4;
                }
            }
            else if (c3 == 2)
            {
                pf("You die due to snake bite as you go deep into the forest");
                pf("Would you like to play again?y/n");
                scanf("%s", &charr);
                if (charr == 'y' || charr == 'Y')
                {
                    goto start;
                }
                else
                    return 0;
            }
            else
            {
                printf("WRONG INPUT");
                goto c33;
            }
        }
        else if (c2 == 2)
        {
            pf("You stumble upon ruins whispering old secrets.\n");
            pf("CHOICE 1:Search the ruins for clues and tools.\n");
            pf("CHOICE 2:Ignore the ruins, fearing it's a trap.\n");
        c333:
            scanf("%d", &c3);
            if (c3 == 1)
            {
                pf("You found a relic that manipulates space and time.\n");
                pf("But it needs to be opened with a riddle\n\n");
                pf("In a land of numbers where the integers roam,\nTwo siblings wander far from home.\nOne leaps forward, two steps at a time,\nThe other trails, with a pace that's prime.\n\nThey start their journey from the very same spot,\nA magical number, oh, it is not a lot.\nTheir paths are different, as you can see,\nBut eventually, they'll meet-oh, where will that be?\n\nTheir meeting place is a mystery to unfold,\nA number most even, special and bold.\nSo, can you tell me, with your mind so keen,\nAt which smallest number will their footsteps convene?\n");

                while (1)
                {
                    scanf("%d", &temp);
                    if (temp == 0)
                    {
                        pf("Thats correct.\n");
                        break;
                    }
                    else{
                        pf("try again\n");
                    }
                }
                printf("Now that you have the potion.\n");
                printf("CHOICE 1:You can use it too forsee potential dangers.\n");
                printf("CHOICE 2:Keep the relic safe for later use.\n");
            here:
                scanf("%d", &c4);
                if (c4 == 1)
                {
                    printf("You saw that you are going to have a fight with a giant creature and you get transported to the deep  forest.\n");
                    goto gohere;
                }
                else if (c4 == 2)
                {
                    printf("CONGRATS!! You have found a safe way out with a the correct choices of not using the relic now.\n");
                    printf("\n Press any key to continue ..."); //rohit
                    getch();
                    main();//rohit
                    return 1;
                }
                else
                {
                    printf("WRONG INPUT\n");
                    goto here;
                }
            }
            else if (c3 == 2)
            {
                printf("The ruin ungulfes you and you get lost in the big maze and die due to hunger.\n");
                pf("Would you like to play again?y/n\n");
                scanf("%s", &charr);

                if (charr == 'y' || charr == 'Y')//rohit
                {
                    goto start;
                }
                else{
                    printf("\n Press any key to continue ..."); //rohit
                    getch();
                    main();
                    return 0;
                }
            }
            else
            {
                printf("WRONG INPUT\n");
                goto c333;
            }
        }
        else
        {
            printf("WRONG INPUT\n");
            goto c22;
        }
    }
    else if (c1 == 2)
    {
        int d2, d3, d4, d5, d6, d7, temp2;
        int point2, creaturepoint2;
        point2 = creaturepoint2 = 0;
        char ans;
    start2:
        pf("The Cave Entrance: The cave's mouth yawns wide.\n");
        pf("Two paths diverge in the dim light.\n");
        pf("CHOICE 1: Take the left path, where faint echoes can be heard.\n");
        pf("CHOICE 2: Take the right path, marked by ancient runes.\n");
    s1:
        scanf("%d", &d2);
        if (d2 == 1)
        {
            pf("The left path leads to a cavern of echoes, where every sound is amplified.\n");
            pf("CHOICE 1:Explore the source of the echoes.\n");
            pf("CHOICE 2:Retreat and try the right path\n");
        s11:
            scanf("%d", &d3);
            if (d3 == 1)
            {
                pf("Following the echoes, you encounter a group of lost souls.\n");
                pf("CHOICE 1: Help the souls find peace.\n");
                pf("CHOICE 2: Ignore their pleas and continue on.\n");
            s111:
                scanf("%d", &d4);

                if (d4 == 1)
                {
                    pf("With the curse's knowledge or the peace of lost souls aiding you, you find an ancient temple housing the curse's source.\nFight with the source and try to destroy it.");
                    while (point2 < 100 && creaturepoint2 < 100)
                    {
                        fight:
                        pf("PRESS 1 TO  ATTACK\nPRESS 2 TO DEFENSE\n");
                        scanf("%d", &temp2);
                        if (temp2 == 1)
                        {
                            srand(time(0));
                            point2 += rand() % 15;
                            creaturepoint2 += rand() % 16;
                            pf("Great shot!! \n");
                        }
                        else if (temp2 == 2)
                        {
                            point2 += rand() % 10;
                            creaturepoint2 += rand() % 9;
                            pf("Nice defence \n");
                        }
                        else
                        {
                            pf("Wrong Input");
                        }
                        pf("YOUR POINTS:%d\nCREATURE POINTS:%d\n", point2, creaturepoint2);
                    }
                    if (point2 >= creaturepoint2)
                    {
                        pf("You truly are a warrior ggs\n");//rohit
                        printf("\n Press any key to continue ..."); //rohit
                        getch();
                        main();
                    }
                    else
                    {
                        pf("You lost.\n ");//rohit
                        pf("WOULD YOU LIKE TO START AGAIN?y/n");
                        scanf("%s", yes);
                        if (yes[0] == 'y' || yes[0] == 'Y')
                        {
                            goto start;
                        }
                        else{
                            printf("\n Press any key to continue ..."); //rohit
                            getch();
                            main();
                            return 0;
                        }
                    }
                }
                else if (d4 == 2)
                {
                    pf("You lost your only hope to find the right path. Now you are lost.\n");//rohit
                    pf("Do you want to try again.(y/n)\n");
                    scanf("%c", &ans);
                    if (ans == 'y' || ans == 'Y')
                    {
                        goto start;
                    }
                    else{
                        printf("\n Press any key to continue ..."); //rohit
                        getch();
                        main();
                        return 0;
                    }
                }
                else
                {
                    pf("INVALID INPUT. TRY AGAIN");
                    goto s111;
                }
            }
            else if (d3 == 2)
            {
                goto s2;
            }
            else
            {
                pf("INVALID INPUT. TRY AGAIN");
                goto s11;
            }
        }
        else if (d2 == 2)
        {
        s2:
            pf("The Runes of Power: The right path reveals a chamber lined with glowing runes.\n");
            pf("CHOICE 1: Attempt to decipher the runes.\n");
            pf("CHOICE 2: Ignore the runes, feeling an ominous presence.\n");
        s21:
            scanf("%d", &d3);
            if (d3 == 1)
            {
                pf("Deciphering the runes reveals the island's curse and its source.\n");
                pf("CHOICE 1: Seek out the source to break the curse.\n");
                pf("CHOICE 2: Use the knowledge to find the safest path off the island.\n");
            s211:
                scanf("%d", &d5);
                if (d5 == 1)
                {
                    goto fight;
                }
                else if (d5 == 2)
                {   int answer2;
                    pf("Solve this riddle to go ahead\n");
                    pf("I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?");
                    pf("option 1: A shadow\n");
                    pf("option 2: An echo\n");
                    pf("option 3: A wave\n");
                    pf("option 4: Clouds\n");
                    scanf("%d", &answer2);
                    if (answer2 == 2){
                        printf("You guessed it right. You really are a true genius.\nCONGRATS YOU WON.\n");
                        printf("\n Press any key to continue ..."); //rohit
                        getch();
                        main();
                    }
                    else{
                        pf("OOPS!!!!!!\nYou guessed it wrong.");//rohit
                        printf("\n Press any key to continue ..."); //rohit
                        getch();
                        main();
                    }
                }
                else
                {
                    pf("INVALID INPUT. TRY AGAIN");
                }
            }
            else if (d3 == 2)
            {
                pf("The omnious presence got you.....\n");
                //pf("TRY AGAIN(y/n)\n");
                scanf("%c", &ans);
                if (ans == 'y' || ans == 'Y')
                {
                    goto start;
                }
                else{
                    return 0;
                }
            }
            else
            {
                pf("INVALID INPUT. TRY AGAIN");
                goto s21;
            }
        }
        else
        {
            pf("INVALID INPUT. TRY AGAIN");
            goto s1;
        }
    }
    if(c1==3){
        int a1,a2,a3,a4,a5,a6,a7;
    jj:
    printf("The mountain challenges every step. A split in the path offers two daunting routes.\n");
    printf("CHOICE 1:Take the snowy path leading into a blizzard.\n");
    printf("CHOICE 2: Take the rocky path with precarious footholds.\n");
    scanf("%d",&a1);
    if (a1==1)
    {
        ll:
        pf("The blizzard conceals a frozen guardian blocking your path.\n");
        pf("CHOICE 1:Try to outwit the guardian with a riddle.\n");
        pf("CHOICE 2:Search for a way around the guardian.\n");
        sf("%d",&a2);
        if(a2==1){
            lmao:
            pf("I am a three-digit number.\nMy tens digit is five more than my ones digit, and my hundreds digit is eight less than my tens digit.\nWhat number am I?");
            scanf("%d",&a3);
            if(a3!=194)
            {
                pf("WRONG ANSWER.\nTRY AGAIN.");
                goto lmao;
            }
            else {
                pp:
                pf("The guardian allows passage but warns of a greater danger ahead.\n");
                pf("CHOICE 1:Heed the warning and prepare for battle.\n");
                pf("CHOICE 2:Dismiss the warning and proceed with caution.\n");
                scanf("%d",&a4);
                if (a4==1)
                {
                    shresth:
                    a4;
                    int a=game();
                    char rr;



                    if (a!=1){
                        pf("Would you like to play again.y/n\n");
                           scanf("%c",rr);
                           if (rr=='y')
                           {
                               goto shresth;
                           }
                           else{
                            printf("\n Press any key to continue ..."); //rohit
                            getch();
                            main();
                            return 0;
                           }

                    }
                }
                else if (a4==2){
                    pf("You dismissed the warning and thus you got lost in the wild.\n");//rohit
                    printf("\n Press any key to continue ..."); //rohit
                    getch();
                    main();
                    return 0;
                }
                else{
                    pf("WRONG INPUT\n");
                    goto pp;
                }


            }


        }
        else if (a2==2){
            pf("You have come to a dead end");//rohit
            printf("\n Press any key to continue ..."); //rohit
            getch();
            main();
            return 0;
        }
        else {
            pf("WRONG INPUT");
            goto ll;
        }
    }
    else if (a1==2){
        pf("You walk for a long time and lose hope as time passes ,\n but eventually the path ends at a cliff with a bridge on the other side.\n");
        pf("OPTION 1:Cross the bridge quicklt and ignore the creaking sound.\n");
        pf("OPTION 2:Inspect the bridge.\n");
        scanf("%d",&a2);
        if(a2==1)
        {
            kk:
            pf("CHOICE 1:You take the risk and ran across.\n");
            pf("CHOICE 2:Go back and choose the snowy path.\n");
            scanf("%d",&a3);
                if(a3==1){
                    pf("You have reached the summit and now you are free.\n");
                    pf("You have conquered the island.");//rohit
                    printf("\n Press any key to continue ..."); //rohit
                    getch();
                    main();
                    return 1;
                }
                else if(a3==2){
                    goto ll;
                }
                else{
                    pf("WRONG INPUT");
                    goto kk;
                }
        }
        else if(a2==2)
        {
            pf("There's nothing you can do now.\n");//rohit
            printf("\n Press any key to continue ..."); //rohit
            getch();
            main();
            return 0;
        }
        else {
            printf("WRONG INPUT");
            goto jj;
        }

    }
    }
    return 0;
}

// Function declarations
int playInnings(char* player, int maxOvers);
int getUserInput();
int getRandomNumber();

int cricket() {
    char c[20];
    int maxOvers = 3;  // You can modify the number of overs

    // Initialize random number generator
    srand(time(NULL));

    do {
        int player1Score, player2Score;

        printf("Hand Cricket Game!\n\n");
        printf("Each player can bat and bowl for %d overs.\n", maxOvers);

        // Player 1 innings
        printf("Player 1 is batting.\n");
        player1Score = playInnings("Player 1", maxOvers);

        // Player 2 innings
        printf("Player 2 is batting.\n");
        player2Score = playInnings("Player 2", maxOvers);

        // Display the result of the game
        printf("\nFinal Scores:\nPlayer 1: %d\nPlayer 2: %d\n", player1Score, player2Score);
        if (player1Score > player2Score) {
            printf("Player 1 wins!\n");
        } else if (player2Score > player1Score) {
            printf("Player 2 wins!\n");
        } else {
            printf("The game is a draw!\n");
        }

        printf("Would you like to play again? (y/n): ");
        scanf("%s", c);
    } while (strcmp(c, "y") == 0);

    return 0;
}

// Other functions remain the same...



// Function to simulate a single innings
int playInnings(char* player, int maxOvers) {
    int score = 0;
    int userScore, computerScore;

    for (int over = 0; over < maxOvers; over++) {
        for (int ball = 0; ball < 6; ball++) {
            printf("%s's score: %d\n", player, score);
            userScore = getUserInput();
            computerScore = getRandomNumber();

            printf("You played %d, computer bowled %d.\n", userScore, computerScore);
            if (userScore == computerScore) {
                printf("Out!\n");
                return score;
            } else {
                score += userScore;
            }
        }
    }
    return score;
}

// Function to get user input
int getUserInput() {
    int input;
    do {
        printf("Enter a number (1-6): ");
        scanf("%d", &input);
        if (input < 1 || input > 6) {

            printf("Invalid input! Please choose a number between 1 and 6.\n");
        }
    } while (input < 1 || input > 6);
    return input;
}

// Function to generate a random number between 1 and 6
int getRandomNumber() {
    return (rand() % 6) + 1;
}



char mazes[3][MAX_HEIGHT][MAX_WIDTH + 1] = {
    {
        "####################",
        "#P      #          #",
        "# ##### # ###### ###",
        "#   #   #    K   #E#",
        "### ### #######  # #",
        "#       #          #",
        "# ########### ######",
        "#             G    #",
        "####################",
    },
    {
        "##############################",
        "#P             #             #",
        "# ####### ###### ##########  #",
        "# #    K  #       #        # #",
        "# # ### ### ##### # #### # # #",
        "# # #   #     #   # #  G # # #",
        "# # # # ######### # # #### # #",
        "# # # #           # #      # #",
        "# # # ############# ####### #",
        "# # #               #       #",
        "# # ################# ##### #",
        "# #                 #     # #",
        "# ################### ### # #",
        "#                         #E#",
        "##############################"
    },
    {
    "##############################",
    "#P #       #     #     #    K#",
    "# ### ### # # # # # ### # ###",
    "#   # # # # # # # # #      # #",
    "### # # ### # # # ### ### # ##",
    "# # #   #   # #   #     # #  #",
    "# # ##### ######### ##### # ##",
    "# #     #           #     #  #",
    "# ##### # ########### ##### ##",
    "#     # # #         # #     ##",
    "##### # # # ######### # #####",
    "#   # # # #   #       #     #",
    "# # # # # ### # ########### #",
    "# #   # #     # #     #   # #",
    "### ### ##### # # # # # # # #",
    "#   #   #     # # # # # # # #",
    "# # ## ## ##### # # ### # ###",
    "# #       #     # # #   #   #",
    "# ######### ##### # # ##### #",
    "#         #       # # #   # #",
    "######### ######### # # # # #",
    "#       # #         # # #   #",
    "# ##### # # ######### # #####",
    "# #   # # # #         #     #",
    "# # ### # # # ########### # #",
    "# # #   # # #   #       # # #",
    "# # # ### # ### # ##### # # #",
    "# # # #   #     #     # #   #",
    "# # # # ########### ### #####",
    "# #   #             #      E#",
    "##############################"
}
};

int level = 0;
int playerX = 1, playerY = 1; // Starting position of the player
int hasKey = 0;  // Player does not have the key initially

void printMaze() {
    system("cls"); // Clear the console on Windows, use system("clear") on Unix
    for (int y = 0; y < MAX_HEIGHT; y++) {
        printf("%s\n", mazes[level][y]);
    }
    if (hasKey) {
        printf("\nYou have the key!\n");
    }
}

void movePlayer(int dx, int dy) {
    int nextX = playerX + dx;
    int nextY = playerY + dy;
    char nextCell = mazes[level][nextY][nextX];

    if (nextCell == '#') {
        return; // Hit a wall, do nothing
    }

    if (nextCell == 'K') {
        hasKey = 1; // Pick up the key
    }

    if (nextCell == 'G') {
        if (!hasKey) {
            printf("\nYou need a key to pass!\n");
            return; // Need a key to pass
        }
    }

    if (nextCell == 'E') {
        if (!hasKey) {
            printf("\nYou need the key to exit!\n");
            return; // Need the key to exit
        } else {
            printf("\nYou exit the maze!\n");
            level++;
            if (level >= 3) {
                printf("Congratulations! You've completed all levels!\n");
                exit(0);
            }
            playerX = 1;
            playerY = 1;
            hasKey = 0;
            printMaze();
            return;
        }
    }

    // Move player
    mazes[level][playerY][playerX] = ' ';
    playerX = nextX;
    playerY = nextY;
    mazes[level][playerY][playerX] = 'P';
}

void Maze() {
    printMaze();
    printf("Welcome to MazeGame\n");
    printf("Use W,S,A,D to Interact\n");
    printf("Find key and get to the exit of 3 levels.\n");


    char move;

    while (1) {
        move = getch(); // Wait for user input

        switch (move) {
            case 'w': case 'W':
                movePlayer(0, -1);
                break;
            case 's': case 'S':
                movePlayer(0, 1);
                break;
            case 'a': case 'A':
                movePlayer(-1, 0);
                break;
            case 'd': case 'D':
                movePlayer(1, 0);
                break;
            case 'q': case 'Q':
                return ; // Quit game
        }
        printMaze();                   
    }
}

int casino()
{
    int balance = 1000;
    int betAmount;
    int betType;
    int betNumber;
    char playAgain = 'y';

    srand(time(NULL));

    printf("Welcome to Roulette!\n");
    printf("You start with a balance of $1000.\n");

    while (playAgain == 'y' || playAgain == 'Y')
    {
        printf("\nYour current balance is: $%d\n", balance);

        // Asking player to place a bet
        printf("Place your bet (minimum $%d, maximum $%d): ", MIN_BET, MAX_BET);
        scanf("%d", &betAmount);

        // Check if the bet is valid
        if (betAmount < MIN_BET || betAmount > MAX_BET || betAmount > balance)
        {
            printf("Invalid bet amount.\n");
            continue;
        }

        // Asking player for the bet type
        printf("Choose your bet type:\n");
        printf("1. Single Number(payout 35:1)\n");
        printf("2. Even/Odd(payout 1:1)\n");
        printf("3. Red/Black(payout 1:1)\n");
        printf("4. Low/High (1-18)/(19-36)(payout 2:1)\n");
        printf("Enter your choice: ");
        scanf("%d", &betType);

        // chose bet type
        switch (betType)
        {
        case 1:
            printf("Enter the number you want to bet on (0-36): ");
            scanf("%d", &betNumber);
            if (betNumber < 0 || betNumber > 36)
            {
                printf("Invalid number.\n");
                continue;
            }
            break;
        case 2:
            printf("Choose even (0) or odd (1): ");
            scanf("%d", &betNumber);
            if (betNumber != EVEN && betNumber != ODD)
            {
                printf("Invalid choice.\n");
                continue;
            }
            break;
        case 3:
            printf("Choose red (0) or black (1): ");
            scanf("%d", &betNumber);
            if (betNumber != RED && betNumber != BLACK)
            {
                printf("Invalid choice.\n");
                continue;
            }
            break;
        case 4:
            printf("Choose low (1-18) (0) or high (19-36) (1): ");
            scanf("%d", &betNumber);
            if (betNumber != 0 && betNumber != 1)
            {
                printf("Invalid choice.\n");
                continue;
            }
            break;

        default:
            printf("Invalid choice.\n");
            continue;
        }

        // the roulette spin
        int winningNumber = rand() % 37; // Numbers 0 to 36
        int winningColor;
        if (winningNumber == 0)
        {
            winningColor = GREEN;
        }
        else if (winningNumber % 2 == 0)
        {
            winningColor = RED;
        }
        else
        {
            winningColor = BLACK;
        }

        //  winning number and color
        printf("\nThe winning number is: %d ", winningNumber);
        if (winningColor == RED)
        {
            printf("(Red)\n");
        }
        else if (winningColor == BLACK)
        {
            printf("(Black)\n");
        }
        else
        {
            printf("(Green)\n");
        }
        int Payout = 0;

        if (betType == 1 && betNumber == winningNumber)
        {
            printf("Congratulations! You guessed the number correctly.\n");
            Payout = 35; // Payout is 35:1
        }
        else if (betType == 2 && betNumber == winningColor)
        {
            printf("Congratulations! You guessed the even/odd correctly.\n");
            Payout = 1;
        }
        else if (betType == 3 && betNumber == winningColor)
        {
            printf("Congratulations! You guessed the color correctly.\n");
            Payout = 1;
        }
        else if ((betType == 4 && betNumber == 0 && winningNumber >= 1 && winningNumber <= 18) || (betType == 4 && betNumber == 1 && winningNumber >= 19 && winningNumber <= 36))
        {
            printf("Congratulations! You guessed the number correctly.\n");
            Payout = 2; // Payout is 2:1
        }

        else
        {
            printf("Sorry, you lost.\n\n");
            Payout = -1;
        }
        balance += betAmount * Payout;
        printf("Your current balance is : $%d\n", balance);
        // Check if the player has run out of money
        if (balance <= 0)
        {
            printf("\nYou are out of money. Game over!\n");
            break;
        }
        if (Payout > 0)
        {
            printf("Congratulations! You won with a payout of %d:1\n", Payout);
        }
        // Ask if the player wants to play again
        printf("\nDo you want to bet again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("\nThank you for playing!\n");
    return 0;
}
void rps()
{
    int rock = 1;
    int paper = 2;
    int scissors = 3;
    srand(time(NULL));
    int computer_move = 1 + rand() % 3;
    int user_move;
    printf("Rock Paper Scissors\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    printf("Enter your move\n");
    scanf("%d", &user_move);
    if (user_move == rock)
    {
        if (computer_move == rock)
        {
            printf("Your move: Rock\nComputer's move: Rock\n");
            printf("It's a tie\n");
        }
        else if (computer_move == paper)
        {
            printf("Your move: Rock\nComputer's move: Paper\n");
            printf("Computer wins\n");
        }
        else
        {
            printf("Your move: Rock\nComputer's move: Scissors\n");
            printf("You win\n");
        }
    }
    else if (user_move == paper)
    {
        if (computer_move == rock)
        {
            printf("Your move: Paper\nComputer's move: Rock\n");
            printf("You win\n");
        }
        else if (computer_move == paper)
        {
            printf("Your move: Paper\nComputer's move: Paper\n");
            printf("It's a tie\n");
        }
        else
        {
            printf("Your move: Paper\nComputer's move: Scissors\n");
            printf("Computer wins\n");
        }
    }
    else if (user_move == scissors)
    {
        if (computer_move == rock)
        {
            printf("Your move: Scissors\nComputer's move: Rock\n");
            printf("Computer wins\n");
        }
        else if (computer_move == paper)
        {
            printf("Your move: Scissors\nComputer's move: Paper\n");
            printf("You win\n");
        }
        else
        {
            printf("Your move: Scissors\nComputer's move: Scissors\n");
            printf("It's a tie\n");
        }
    }
    else
    {
        printf("Invalid move\n");
    }
}
void quiz(){
    int a,b,c,d,score;
    score=0;
    a=1;
    b=2;
    c=3;
    d=4;
    printf("You will be given 10 questions\nYou have to select the correct option\nYou will get 1 point for each correct answer\nYou will get -1 points for each wrong answer\n");
    printf("Let's start the quiz.\nPress enter to continue.....\n");
    getchar();
    printf("What is the capital of France?\n");
    printf("1. Paris\n2. London\n3. Berlin\n4. Rome\n");
    int user_answer;
    scanf("%d",&user_answer);
    if(user_answer==a){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Who is the world’s highest-paid athlete in 2023? \n");
    printf("1. Lionel Messi\n2. Cristiano Ronaldo\n3. Conor McGregor\n4. Roger Federer\n");
    scanf("%d",&user_answer);
    if(user_answer==b){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Which country is the largest producer of coffee in the world?\n");
    printf("1. Brazil\n2. India\n3. China\n4. Vietnam\n");
    scanf("%d",&user_answer);
    if(user_answer==a){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Which country is the largest producer of tea in the world?\n");
    printf("1. China\n2. India\n3. Sri Lanka\n4. Kenya\n");
    scanf("%d",&user_answer);
    if(user_answer==b){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Who is the author of the Harry Potter series?\n");
    printf("1. J.K. Rowling\n2. George R.R. Martin\n3. Stephen King\n4. Dan Brown\n");
    scanf("%d",&user_answer);
    if(user_answer==a){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Which is the largest mammal in the world?\n");
    printf("1. Blue Whale\n2. African Elephant\n3. Giraffe\n4. Hippopotamus\n");
    scanf("%d",&user_answer);
    if(user_answer==a){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Which is the largest bird in the world?\n");
    printf("1. Ostrich\n2. Emu\n3. Cassowary\n4. Kiwi\n");
    scanf("%d",&user_answer);
    if(user_answer==a){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Which country is known as the Land of the Rising Sun?\n");
    printf("1. China\n2. Japan\n3. South Korea\n4. North Korea\n");
    scanf("%d",&user_answer);
    if(user_answer==b){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Which is the largest planet in the solar system?\n");
    printf("1. Jupiter\n2. Saturn\n3. Uranus\n4. Neptune\n");
    scanf("%d",&user_answer);
    if(user_answer==a){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Which is the largest ocean in the world?\n");
    printf("1. Pacific Ocean\n2. Atlantic Ocean\n3. Indian Ocean\n4. Arctic Ocean\n");
    scanf("%d",&user_answer);
    if(user_answer==a){
        printf("Correct answer\n");
        score++;
    }
    else{
        printf("Wrong answer\n");
        score--;
    }
    printf("Your score is %d\n",score);

}


int main(){
    start();
    int temp;

    while(1){
        pf("Which game do you want to play?\n") ;
        pf("1. The Adventure \n");
        pf("2. Maze Game\n");
        pf("3. Hand Cricket\n");
        pf("4.Casino.\n");
        pf("5.Rock Paper Scissor.\n");
        pf("6. GK Quiz\n");
        pf("Enter 0 to exit\n");
        scanf("%d",&temp);
        if(temp==1){
            adventure();
            system("cls");

        }
        else if(temp==2){
            Maze();

        }
        else if (temp==0){
            break;
            system("cls");
        }
        else if (temp==3){
            cricket();
            system("cls");
        }
        else if(temp==4){
            casino();
            system("cls");
        }
        else if (temp==5){
            rps();
            //system("cls");
        }
        else if (temp==6){
            quiz();
            system("cls");
        }
        else{
            pf("wrong input");

        }

    }
}
