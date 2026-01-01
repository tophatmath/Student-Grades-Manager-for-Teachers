#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    float grade;
    char status[25];
} Personnel;

    Personnel student[MAX_STUDENTS];
    int count = 0;
    char tryagain;
    char sort;
    int minimalscore;

void ShowPage() {

    
    printf("\n\n\nWelcome to the Student Achievements!\n\n\n");
            printf("How much would you like the minimal score to pass be: ");
        scanf(" %d", &minimalscore);
        while (getchar() != '\n');
    
    
    do {

        printf("\nState the student's name: ");
        fgets(student[count].name, 50, stdin);
        student[count].name[strcspn(student[count].name, "\n")] = '\0'; // safer newline remover

        printf("Input the student's grade: ");
        scanf(" %f", &student[count].grade);
        while (getchar() != '\n'); // clear input buffer

        // Set status based on grade
        if (student[count].grade >= minimalscore) {
            strcpy(student[count].status, "Passed");
        } else {
            strcpy(student[count].status, "Failed");
        }

        printf("\n\nStudent Added:\n");
        printf("Name: %s\n", student[count].name);
        printf("Grade: %.2f\n", student[count].grade);
        printf("Status: %s\n", student[count].status);

        count++;

        printf("\nAll Students So Far:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. Name: %s\n", i + 1, student[i].name);
            printf("   Grade: %.2f\n", student[i].grade);
            printf("   Status: %s\n\n", student[i].status);
        }
        
       printf("Sort Students based on Grades? (y/n): ");
        scanf(" %c", &sort);
        while (getchar() != '\n');
        
        if(sort == 'y'){
            
            int a, b;
            Personnel temp;
            
            for(a = 0; a < count - 1; a++)
            {
                for(b = a+1; b < count; b++)
                {
                    if(student[a].grade < student[b].grade)
                    {
                        temp = student[a];
                        student[a] = student[b];
                        student[b] = temp;
                    }
                }
            }
            for(a = 0; a < count; a++){
                printf("%d. Name: %s\n", a + 1, student[a].name);
            printf("   Grade: %.2f\n", student[a].grade);
            printf("   Status: %s\n\n", student[a].status);
            }
        }


        printf("Would You Like to Add Another Student? (y/n/): ");
        scanf(" %c", &tryagain);
        while (getchar() != '\n');
        
            if(tryagain == 'n'){
            return;
        }
        
    } while (tryagain == 'y' || 'Y');
}

void Stats() {
    
    char quit;
    
    int ranges[10][2] = {
      {0, 10}, // -- 0
      {11, 20}, // -- 1
      {21, 30},
      {31, 40},
      {41, 50},
      {51, 60},
      {61, 70},
      {71, 80},
      {81, 90},
      {91, 100},
    };
    
    int frequencies[10] = {0};
    
    for(int s = 0; s < count; s++) {
        for(int r = 0; r < 10; r++)
        {
            if(student[s].grade >= ranges[r][0] && student[s].grade <= ranges[r][1])
            {
                frequencies[r]++;
                break;
            }
        }
    }
    
    for(int t = 0; t < 10; t++)
    {
         printf("\nRange %d to %d: %d student(s)\n",ranges[t][0], ranges[t][1], frequencies[t]);
    }
    
    printf("\n\nEner anything to go back?: ");
    scanf(" %c", &quit);
    while (getchar() != '\n');
    
    
    
}

void About() {
    printf("\n\nMade by me to give a framework on how teachers should input and sort their students' grades.\n\n");
}



void Main() {
    printf("1. Student Data\n");
    printf("2. Statistics\n");
    printf("3. About\n");
    printf("\n\nPick What to Do: ");
}

int main() {
    char r;

    do {
        Main();
        scanf(" %c", &r);
        while (getchar() != '\n'); // clear buffer

        switch (r) {
            case '1':
                ShowPage();
                break;
            case '2':
                Stats();
                break;
            case '3':
                About();
                break;
            case 'q':  // Add quit option
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (r != 'q'); // Loop until user quits

    return 0;
}
