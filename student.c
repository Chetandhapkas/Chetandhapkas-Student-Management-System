#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX 50
int deletionFailed = 0; // Add this at the top of your file
int searchFailed = 0;

int rollno[MAX];
char name[MAX][50];
int sem[MAX];
double number[MAX];
float sgpa[50];
char skill[MAX][5][30];
int marks[50][5];
int skillcount[MAX];
int totalStudent = 0;

// Function Prototypes
void addStudent();
void displayStudent();
void searchStudent();
void searchBySkill();
void displayAllRowWise();
void deleteStudent();
void updateStudent();
void showStudentLevel();
void generateMarksheet();

//Main function
int main() {
    int choice;
    int loop=1;
   

    do {
	printf("\n--- Student Tracker Menu ---\n");
	printf("1. Add Student\n");
	printf("2. Display Students\n");
	printf("3. Search Student by Roll No\n");
	printf("4. Search Student by Skill\n");
	printf("5. Display All (Row-wise)\n");
	printf("6. Delete Student\n");
	printf("7. Update Student Details\n");
	printf("8. Show Students by Level\n");
	printf("9. Generate Marksheet\n");
	printf("10. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1: {
		char more;
		do {
		    addStudent();
		    printf("Do you want to add another student? (y/n): ");
		    scanf(" %c", &more);
		} while (more == 'y' || more == 'Y');
		break;
	    }

	    case 2: {
		char more;
		do {
		    displayStudent();
		    printf("Do you want to display again? (y/n): ");
		    scanf(" %c", &more);
		} while (more == 'y' || more == 'Y');
		break;
	    }

	    case 3: {
    char more;
    do {
        searchStudent();

         // If 3 wrong attempts, skip asking again
         if (searchFailed == 1) {
            break;  // Go to main menu directly
             }

               printf("Do you want to search another student? (y/n): ");
               scanf(" %c", &more);
           } while (more == 'y' || more == 'Y');
          break;
      }


	    case 4: {
		char more;
		do {
		    searchBySkill();
		    printf("Do you want to search by another skill? (y/n): ");
		    scanf(" %c", &more);
		} while (more == 'y' || more == 'Y');
		break;
	    }

	    case 5: {
		char more;
		do {
		    displayAllRowWise();
		    printf("Do you want to show once again? (y/n): ");
		    scanf(" %c", &more);
		} while (more == 'y' || more == 'Y');
		break;
	    }

	    case 6: {
		char more;
do {
    deleteStudent();

    // If 3 wrong attempts, skip asking again
    if (deletionFailed == 1) {
        break; // directly return to main menu
    }

    printf("Do you want to delete another student? (y/n): ");
    scanf(" %c", &more);
} while (more == 'y' || more == 'Y');
break;

	    }

	    case 7: {
		char more;
		do {
		    updateStudent();
		    printf("Do you want to update another student? (y/n): ");
		    scanf(" %c", &more);
		} while (more == 'y' || more == 'Y');
		break;
	    }

	    case 8: {
		char more;
		do {
		    showStudentLevel();
		    printf("Do you want to view level-wise students again? (y/n): ");
		    scanf(" %c", &more);
		} while (more == 'y' || more == 'Y');
		break;
	    }

	    case 9: {
		    char more;
		do {
		  generateMarksheet();
		    printf("Do you want to generate another marksheet? (y/n): ");
		    scanf(" %c", &more);
		    } while (more == 'y' || more == 'Y');
		    break;
		}


	    case 10:
		printf("Exiting Program...\n");
		return 0;

	    default:
		printf("WRONG CHOICE.\n");
	}

    } while (loop); // infinite loop until choice 9 is selected

    return 0;
}

//------------------ Add Student -------------------
void addStudent() {
    int i, j;
    char tempRoll[20];
    char tempMobile[20];

    if (totalStudent >= MAX) {
        printf("Maximum Student Limit Reached.\n");
        return;
    }

    int newRoll, newSem, newSkillCount;
    char newName[50];
    double newMobile;
    float newSGPA;
    char newSkills[5][30];

    // ==== INPUT ROLL NUMBER WITH VALIDATION ====
    printf("\nEnter Roll Number: ");
    scanf("%s", tempRoll);

    // Check if all characters are digits
    int validInput = 1;
    for (i = 0; tempRoll[i] != '\0'; i++) {
        if (tempRoll[i] < '0' || tempRoll[i] > '9') {
            validInput = 0;
            break;
        }
    }

    if (!validInput || strlen(tempRoll) == 0) {
        printf("Invalid Roll Number! Returning to main menu...\n");
        return;
    }

    // Manual string to integer conversion (no stdlib)
    newRoll = 0;
    for (i = 0; tempRoll[i] != '\0'; i++) {
        newRoll = newRoll * 10 + (tempRoll[i] - '0');
    }

    // ==== INPUT NAME ====
    printf("Enter Name: ");
    scanf(" %[^\n]", newName);

    // ==== INPUT SEMESTER ====
    printf("Enter Semester: ");
    scanf("%d", &newSem);

    // ==== VALIDATE MOBILE NUMBER ====
    while (1) {
        int len = 0, valid = 1;

        printf("Enter Mobile Number: ");
        scanf("%s", tempMobile);

        while (tempMobile[len] != '\0') {
            if (tempMobile[len] < '0' || tempMobile[len] > '9') {
                valid = 0;
                break;
            }
            len++;
        }

        if (len == 10 && valid) {
            // Convert string to double manually
            newMobile = 0;
            for (i = 0; tempMobile[i] != '\0'; i++) {
                newMobile = newMobile * 10 + (tempMobile[i] - '0');
            }
            break;
        } else {
            printf("Invalid Number! Please enter a valid 10-digit number.\n");
        }
    }

    // ==== INPUT SGPA ====
    printf("Enter SGPA: ");
    scanf("%f", &newSGPA);

    // ==== INPUT SKILLS ====
    printf("How many Skills (MAX 5)? ");
    scanf("%d", &newSkillCount);
    if (newSkillCount > 5) newSkillCount = 5;

    for (j = 0; j < newSkillCount; j++) {
        printf("Enter Skill %d: ", j + 1);
        scanf(" %[^\n]", newSkills[j]);
    }

    // ==== INSERT IN SORTED ORDER ====
    int pos = totalStudent;
    for (i = 0; i < totalStudent; i++) {
        if (newRoll < rollno[i]) {
            pos = i;
            break;
        }
    }

    // Shift students
    for (i = totalStudent; i > pos; i--) {
        rollno[i] = rollno[i - 1];
        strcpy(name[i], name[i - 1]);
        sem[i] = sem[i - 1];
        number[i] = number[i - 1]; // double assignment
        sgpa[i] = sgpa[i - 1];
        skillcount[i] = skillcount[i - 1];
        for (j = 0; j < skillcount[i - 1]; j++) {
            strcpy(skill[i][j], skill[i - 1][j]);
        }
    }

    // Insert new student
    rollno[pos] = newRoll;
    strcpy(name[pos], newName);
    sem[pos] = newSem;
    number[pos] = newMobile;
    sgpa[pos] = newSGPA;
    skillcount[pos] = newSkillCount;
    for (j = 0; j < newSkillCount; j++) {
        strcpy(skill[pos][j], newSkills[j]);
    }

    totalStudent++;
    printf("STUDENT ADDED SUCCESSFULLY\n");
}


//------------------ Display Students -------------------
void displayStudent() {
    int i,j;
    if (totalStudent == 0) {
	printf("No Student Data Available.\n");
	return;
    }
    printf("\n");
    for (i = 0; i < totalStudent; i++) {
	printf("\n----------Student no. : %d----------\n",i+1);
	printf("Roll No   : %d\n", rollno[i]);
	printf("Name      : %s\n", name[i]);
	printf("Semester  : %d\n", sem[i]);
	printf("SGPA      : %.2f\n", sgpa[i]);
	printf("Mobile No.: %.0lf\n", number[i]);
	printf("Skills    :");
    printf("\t    ");
	for (j = 0; j < skillcount[i]; j++)
	{
	    printf(" - %s | ", skill[i][j]);
	}
	    if (skillcount[i] > 3)
			printf("Level     : High Level\n");
		    else if (skillcount[i] == 3)
			printf("Level     : Moderate Level\n");
		    else
			printf("Level     : Low Level\n");
	printf("-----------------------------\n");
	printf("\nPress Enter to continue...\n");
	getch();
    }

}

//------------------ Search Student by Roll No -------------------
void searchStudent() {
    int searchno, attempts = 0, found = 0, i, j;

    if (totalStudent == 0) {
        printf("No students added yet.\n");
        searchFailed = 1;
        return;
    }

    while (attempts < 3) {
        printf("\nAll Roll Numbers: ");
        for (i = 0; i < totalStudent; i++) {
            printf("%d, ", rollno[i]);
        }

        printf("\n\nEnter Roll No to Search : ");
        scanf("%d", &searchno);

        for (i = 0; i < totalStudent; i++) {
            if (searchno == rollno[i]) {
                found = 1;
                searchFailed = 0; // Found successfully
                printf("\n\n====STUDENT FOUND====\n\n");
                printf("Roll No   : %d\n", rollno[i]);
                printf("Name      : %s\n", name[i]);
                printf("Semester  : %d\n", sem[i]);
                printf("Mobile No.: %.0lf\n", number[i]);
                printf("CGPA      : %.2f\n", sgpa[i]);
                printf("Skills    :\n");
                for (j = 0; j < skillcount[i]; j++)
                    printf("  - %s\n", skill[i][j]);
                return; // Exit after showing info
            }
        }

        attempts++;
        if (!found && attempts < 3) {
            printf("\nIncorrect roll number. Try again.\n");
            printf("You have %d attempts left, Enter Correct Roll Number.\n", 3 - attempts);
        }
    }

    // If all 3 attempts failed
    printf("\n❌ STUDENT NOT FOUND after 3 incorrect attempts.\n");
    searchFailed = 1;
}

//------------------ Search by Skill -------------------
void searchBySkill() {
    char uniqueSkills[100][50];
    int uniqueCount = 0;
    int i, j, k, found;
    char skillToSearch[30];
    int attempt = 0;
    int validSkill = 0;
    int studentFound = 0;
    int matchedRolls[50]; // To store roll numbers of matched students
    int matchedCount = 0;

    if (totalStudent == 0) {
        printf("No students added yet.\n");
        return;
    }

    // Step 1: Extract all unique skills
    for (i = 0; i < totalStudent; i++) {
        for (j = 0; j < skillcount[i]; j++) {
            found = 0;
            for (k = 0; k < uniqueCount; k++) {
                if (strcmp(skill[i][j], uniqueSkills[k]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(uniqueSkills[uniqueCount], skill[i][j]);
                uniqueCount++;
            }
        }
    }

    if (uniqueCount == 0) {
        printf("No skills available.\n");
        return;
    }

    // Step 2: Show available skills
    printf("\nAvailable Skills:\n");
    for (i = 0; i < uniqueCount; i++) {
        printf(" - %s\n", uniqueSkills[i]);
    }

    // Step 3: Ask user to enter skill (max 3 attempts)
    while (attempt < 3 && !validSkill) {
        printf("\nEnter Skill to Search: ");
        scanf(" %[^\n]", skillToSearch);

        for (i = 0; i < uniqueCount; i++) {
            if (strcmp(skillToSearch, uniqueSkills[i]) == 0) {
                validSkill = 1;
                break;
            }
        }

        if (!validSkill) {
            attempt++;
            if (attempt < 3) {
                printf(" Invalid skill. You have %d attempt(s) left.\n", 3 - attempt);
            }
        }
    }

    if (!validSkill) {
        printf("\n Exceeded maximum attempts. Returning to main menu...\n");
        return;
    }

    // Step 4: Show students with matching skill
    printf("\n✅ Students with skill: %s\n", skillToSearch);
    printf("--------------------------------\n");
    printf("Roll No   | Name\n");
    printf("--------------------------------\n");

    studentFound = 0;
    matchedCount = 0;

    for (i = 0; i < totalStudent; i++) {
        for (j = 0; j < skillcount[i]; j++) {
            if (strcmp(skill[i][j], skillToSearch) == 0) {
                printf("%-9d| %s\n", rollno[i], name[i]);
                matchedRolls[matchedCount++] = rollno[i]; // store matched roll numbers
                studentFound = 1;
                break;
            }
        }
    }

    if (!studentFound) {
        printf("No student found with that skill.\n");
        printf("--------------------------------\n");
        return;
    }

    printf("--------------------------------\n");

    // Step 5: Ask user to select a roll number for full info (only from matched list)
    int selectedRoll, match = 0, rollAttempt = 0;
    while (rollAttempt < 3) {
        printf("\nEnter Roll Number from above to view full details: ");
        scanf("%d", &selectedRoll);

        // check if entered roll is in matchedRolls
        match = 0;
        for (i = 0; i < matchedCount; i++) {
            if (selectedRoll == matchedRolls[i]) {
                match = 1;
                break;
            }
        }

        if (match) {
            // display full details
            for (i = 0; i < totalStudent; i++) {
                if (rollno[i] == selectedRoll) {
                    printf("\n==== STUDENT DETAILS ====\n");
                    printf("Roll No   : %d\n", rollno[i]);
                    printf("Name      : %s\n", name[i]);
                    printf("Semester  : %d\n", sem[i]);
                    printf("Mobile No.: %.0lf\n", number[i]);
                    printf("CGPA      : %.2f\n", sgpa[i]);
                    printf("Skills    : ");
                    printf("\t");
                    for (j = 0; j < skillcount[i]; j++)
                        printf("  - %s | ", skill[i][j]);

                    printf("\n-------------------------\n");    
                    return;
                
                }
            }
        } else {
            rollAttempt++;
            if (rollAttempt < 3) {
                printf("❌ Invalid roll number. You have %d attempt(s) left.\n", 3 - rollAttempt);
            }
        }
    }
}

//------------------ Display Row-wise -------------------
void displayAllRowWise() {
    int i, j;
    char skillLine[100];

    if (totalStudent == 0) {
	printf("No student data available.\n");
	return;
    }

    printf("\nAll Students:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("| %-7s | %-20s | %-3s | %-12s | %-4s | %-30s \n", "Roll No", "Name", "Sem", "Mobile No", "SGPA", "Skills");
    printf("-----------------------------------------------------------------------------\n");

    for (i = 0; i < totalStudent; i++) {
	int firstLine = 1;
	for (j = 0; j < skillcount[i]; j += 2) {
	    strcpy(skillLine, "");
	    strcat(skillLine, skill[i][j]);
	    if (j + 1 < skillcount[i]) {
		strcat(skillLine, ", ");
		strcat(skillLine, skill[i][j + 1]);
	    }

	    if (firstLine) {
		printf("| %-7d | %-20s | %-3d | %-12.0lf | %-4.2f | %-30s \n",
		       rollno[i], name[i], sem[i], number[i], sgpa[i], skillLine);
		firstLine = 0;
	    } else {
		printf("| %-7s | %-20s | %-3s | %-12s | %-4s | %-30s \n",
		       "", "", "", "", "", skillLine);
		//printf("------------------------------------------------------------");
	    }
	}
    }

    printf("------------------------------------------------------------------------\n");
}

//------------------ Delete Student -------------------
void deleteStudent() {
    int i, j;
    int rno, index = -1;
    int attempts = 0;
    char confirm;

    if (totalStudent == 0) {
        printf("No students to delete.\n");
        deletionFailed = 1;
        return;
    }

    printf("All Roll Numbers: ");
    for (i = 0; i < totalStudent; i++) {
        printf("%d ", rollno[i]);
    }

    // 3 Attempt logic
    while (attempts < 3) {
        printf("\nEnter the Roll No of student to delete: ");
        scanf("%d", &rno);

        index = -1;
        for (i = 0; i < totalStudent; i++) {
            if (rollno[i] == rno) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            break;  // Found
        }

        attempts++;
        if (attempts < 3) {
            printf(" Invalid Roll Number. Attempts left: %d\n", 3 - attempts);
        }
    }

    if (index == -1) {
        printf("\n❌ 3 incorrect attempts. Returning to Main Menu...\n");
        deletionFailed = 1;
        return;
    }

    deletionFailed = 0;  // reset flag if student found

    // Show student info
    printf("\n----Student Found----\n");
    printf("Roll No   : %d\n", rollno[index]);
    printf("Name      : %s\n", name[index]);
    printf("Semester  : %d\n", sem[index]);
    printf("SGPA      : %.2f\n", sgpa[index]);
    printf("Mobile No.: %.0lf\n", number[index]);
    printf("Skills    : ");
    printf("\t    ");
    for (j = 0; j < skillcount[index]; j++) {
        printf("   - %s |", skill[index][j]);
    }

    // Confirm deletion
    printf("\n\nDo you confirm to delete this student? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        for (i = index; i < totalStudent - 1; i++) {
            rollno[i] = rollno[i + 1];
            strcpy(name[i], name[i + 1]);
            sem[i] = sem[i + 1];
            number[i] = number[i + 1];
            sgpa[i] = sgpa[i + 1];
            skillcount[i] = skillcount[i + 1];
            for (j = 0; j < skillcount[i]; j++)
                strcpy(skill[i][j], skill[i + 1][j]);
        }
        totalStudent--;
        printf("✅ Student deleted successfully.\n");
    } else {
        printf("❎ Deletion cancelled.\n");
    }
}

//------------------ Update Student -------------------
void updateStudent() {
    int i, j, rno, ch;
    int index = -1;
    char oldName[50];
    int oldSem;
    double oldNumber;
    float oldCgpa;
    char oldSkills[10][30];
    int oldSkillCount;
    char more;
    char oldSemStr[10], newSemStr[10];
    char oldMobileStr[20], newMobileStr[20];
    char oldCgpaStr[10], newCgpaStr[10];
    char rollStr[10];
    int maxSkills;
    int attempts = 0;

    if (totalStudent == 0) {
        printf("No students to update.\n");
        return;
    }

    printf("All Roll Numbers: ");
    for (i = 0; i < totalStudent; i++) {
        printf("%d ", rollno[i]);
    }
    printf("\n");

    while (attempts < 3) {
        printf("Enter Roll No to update: ");
        scanf("%d", &rno);

        for (i = 0; i < totalStudent; i++) {
            if (rollno[i] == rno) {
                index = i;
                break;
            }
        }

        if (index != -1) break;

        attempts++;
        if (attempts < 3) {
            printf("❌ Invalid roll number. Attempts left: %d\n", 3 - attempts);
        }
    }

    if (index == -1) {
        printf("\n❌ Max attempts reached. Returning to main menu...\n");
        return;
    }

    // Backup old data
    oldSem = sem[index];
    oldNumber = number[index];
    oldCgpa = sgpa[index];
    oldSkillCount = skillcount[index];
    strcpy(oldName, name[index]);
    for (j = 0; j < oldSkillCount; j++) {
        strcpy(oldSkills[j], skill[index][j]);
    }

    // Current details
    printf("\n--- Current Details ---\n");
    printf("Roll No     : %d\n", rollno[index]);
    printf("Name        : %s\n", name[index]);
    printf("Semester    : %d\n", sem[index]);
    printf("Mobile No   : %.0lf\n", number[index]);
    printf("SGPA        : %.2f\n", sgpa[index]);
    printf("Skills      : ");
    for (j = 0; j < skillcount[index]; j++) {
        printf("%s%s", skill[index][j], (j < skillcount[index] - 1) ? ", " : "");
    }
    printf("\n");

    do {
        printf("\nWhat do you want to update?\n");
        printf("1. Name\n2. Semester\n3. Mobile Number\n4. SGPA\n5. Skills\n6. All\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter new name: ");
                scanf(" %[^\n]", name[index]);
                break;
            case 2:
                printf("Enter new semester: ");
                scanf("%d", &sem[index]);
                break;
            case 3:
                printf("Enter new mobile number: ");
                scanf("%lf", &number[index]);
                break;
            case 4:
                printf("Enter new SGPA: ");
                scanf("%f", &sgpa[index]);
                break;
            case 5:
                printf("How many new skills? ");
                scanf("%d", &skillcount[index]);
                for (j = 0; j < skillcount[index]; j++) {
                    printf("Enter Skill %d: ", j + 1);
                    scanf(" %[^\n]", skill[index][j]);
                }
                break;
            case 6:
                printf("Enter new name: ");
                scanf(" %[^\n]", name[index]);
                printf("Enter new semester: ");
                scanf("%d", &sem[index]);
                printf("Enter new mobile number: ");
                scanf("%lf", &number[index]);
                printf("Enter new SGPA: ");
                scanf("%f", &sgpa[index]);
                printf("How many new skills? ");
                scanf("%d", &skillcount[index]);
                for (j = 0; j < skillcount[index]; j++) {
                    printf("Enter Skill %d: ", j + 1);
                    scanf(" %[^\n]", skill[index][j]);
                }
                break;
            default:
                printf("Invalid option.\n");
                break;
        }

        // Show Comparison Table
        printf("\n---------------------- COMPARISON TABLE ----------------------\n");
        printf("%-15s | %-30s | %-30s\n", "Attribute", "Old Value", "New Value");
        printf("-----------------+--------------------------------+--------------------------------\n");

        sprintf(rollStr, "%d", rollno[index]);
        printf("%-15s | %-30s | %-30s\n", "Roll No", rollStr, rollStr);

        printf("%-15s | %-30s | %-30s\n", "Name", oldName, name[index]);

        sprintf(oldSemStr, "%d", oldSem);
        sprintf(newSemStr, "%d", sem[index]);
        printf("%-15s | %-30s | %-30s\n", "Semester", oldSemStr, newSemStr);

        sprintf(oldMobileStr, "%.0lf", oldNumber);
        sprintf(newMobileStr, "%.0lf", number[index]);
        printf("%-15s | %-30s | %-30s\n", "Mobile No.", oldMobileStr, newMobileStr);

        sprintf(oldCgpaStr, "%.2f", oldCgpa);
        sprintf(newCgpaStr, "%.2f", sgpa[index]);
        printf("%-15s | %-30s | %-30s\n", "SGPA", oldCgpaStr, newCgpaStr);

        // Skills - 2 per row, first line with attribute
        printf("%-15s | ", "Skills");
        maxSkills = oldSkillCount > skillcount[index] ? oldSkillCount : skillcount[index];

        for (j = 0; j < maxSkills; j += 2) {
            char oldPair[60] = "-", newPair[60] = "-";

            if (j < oldSkillCount) strcpy(oldPair, oldSkills[j]);
            if (j + 1 < oldSkillCount) {
                strcat(oldPair, ", ");
                strcat(oldPair, oldSkills[j + 1]);
            } else if (j < oldSkillCount) {
                strcat(oldPair, ", -");
            }

            if (j < skillcount[index]) strcpy(newPair, skill[index][j]);
            if (j + 1 < skillcount[index]) {
                strcat(newPair, ", ");
                strcat(newPair, skill[index][j + 1]);
            } else if (j < skillcount[index]) {
                strcat(newPair, ", -");
            }

            if (j == 0)
                printf("%-30s | %-30s\n", oldPair, newPair);
            else
                printf("%-15s | %-30s | %-30s\n", "", oldPair, newPair);
        }

        printf("--------------------------------------------------------------------------\n");
        printf("✅ Student details updated successfully.\n");

        printf("\nDo you want to update another field for same student? (y/n): ");
        fflush(stdin); // Turbo C fix
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');
}

//------------------ Show Students by Level -------------------
void showStudentLevel() {
	int i,j;
	char choice;
    if (totalStudent == 0) {
	printf("No students added yet.\n");
	return;
    }

    printf("\n======================== STUDENT LEVEL REPORT =========================\n");
    printf("%-10s | %-20s | %-12s | %-6s\n", "Roll No", "Name", "Level", "SGPA");
    printf("-----------------------------------------------------------------------\n");

    // HIGH LEVEL
    for (i = 0; i < totalStudent; i++) {
	if (skillcount[i] > 3)
	    printf("%-10d | %-20s | %-12s | %-6.2f\n", rollno[i], name[i], "High", sgpa[i]);
    }

    // MODERATE LEVEL
    for (i = 0; i < totalStudent; i++) {
	if (skillcount[i] == 3)
	    printf("%-10d | %-20s | %-12s | %-6.2f\n", rollno[i], name[i], "Moderate", sgpa[i]);
    }

    // LOW LEVEL
    for (i = 0; i < totalStudent; i++) {
	if (skillcount[i] < 3)
	    printf("%-10d | %-20s | %-12s | %-6.2f\n", rollno[i], name[i], "Low", sgpa[i]);
    }

    printf("=======================================================================\n");

    // Ask for search option
    printf("\n🔍 Do you want to search by Roll No or Level? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
	int option;
	printf("1. Search by Roll No\n");
	printf("2. Show all students of a particular level\n");
	printf("Enter your choice: ");
	scanf("%d", &option);

	if (option == 1) {
	    int rno, found = 0;
	    printf("\nAll Roll Numbers: ");
	    for ( i = 0; i < totalStudent; i++)
		{
		    printf("%d ,", rollno[i]);
		}
	    printf("\nEnter Roll No: ");
	    scanf("%d", &rno);

	    for (i = 0; i < totalStudent; i++) {
		if (rollno[i] == rno) {
		    printf("\n STUDENT DETAILS\n");
		    printf("-----------------------------------------------------------\n");
		    printf("Roll No     : %d\n", rollno[i]);
		    printf("Name        : %s\n", name[i]);
		    printf("Semester    : %d\n", sem[i]);
		    printf("Mobile No   : %.0lf\n", number[i]);
		    printf("SGPA        : %.2f\n", sgpa[i]);
		    printf("Skills      :\n");
		    for (j = 0; j < skillcount[i]; j++)
			printf("  - %s\n", skill[i][j]);

		    if (skillcount[i] > 3)
			printf("Level       : High Level\n");
		    else if (skillcount[i] == 3)
			printf("Level       : Moderate Level\n");
		    else
			printf("Level       : Low Level\n");

		    printf("-----------------------------------------------------------\n");
		    found = 1;
		    break;
		}
	    }

	    if (!found)
		printf("❌ No student found with that roll number.\n");
	}

       else if (option == 2) {
    char level[15];
     int found;
     char skillLine[100];
    printf("Enter level to display (High/Moderate/Low): ");
    scanf("%s", level);

     found = 0;

    printf("\n🎯 Students in %s Level:\n", level);
    printf("------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-6s | %-40s |\n", "Roll No", "Name", "SGPA", "Skills");
    printf("------------------------------------------------------------------------------------------\n");

    for (i = 0; i < totalStudent; i++) {
	int match = 0;
	if ((strcmp(level, "High") == 0 || strcmp(level, "high") == 0) && skillcount[i] > 3)
	    match = 1;
	else if ((strcmp(level, "Moderate") == 0 || strcmp(level, "moderate") == 0) && skillcount[i] == 3)
	    match = 1;
	else if ((strcmp(level, "Low") == 0 || strcmp(level, "low") == 0) && skillcount[i] < 3)
	    match = 1;

	if (match) {
	    int firstLine = 1;
	    for (j = 0; j < skillcount[i]; j += 2) {
		 char skillLine[100] = "";
		strcat(skillLine, skill[i][j]);
		if (j + 1 < skillcount[i]) {
		    strcat(skillLine, ", ");
		    strcat(skillLine, skill[i][j + 1]);
		}

		if (firstLine) {
		    printf("| %-10d | %-20s | %-6.2f | %-40s |\n",
			   rollno[i], name[i], sgpa[i], skillLine);
		    firstLine = 0;
		} else {
		    printf("| %-10s | %-20s | %-6s | %-40s |\n", "", "", "", skillLine);
		}
	    }

	    found = 1;
	}
    }

    if (!found)
	printf(" \nNo students found in that level.\n");

    printf("------------------------------------------------------------------------------------------\n");
}

	else {
	    printf("\n Invalid option.\n");
	}
    }
}

//------------------ Generate Marksheet -------------------
void generateMarksheet() {
    int more = 1;
    int i, j, k;
    int generatedIndexes[100];  // stores indexes of students with generated marksheets
    int genCount = 0;
    float percent;
    char grade[4];
    float sgpaTotal;
    float cgpa;
    char ans;
    char showTable;
    float semSgpa[10];
    float summaryCGPA[100];  // stores CGPA for summary table

    while (more) {
        int roll;
        int found = 0;
        int attempts = 0;
        char subjects[5][30] = {"BT", "DAA", "DBMS", "DSA", "OOPJ"};
        int total;

        while (attempts < 3 && !found) {
            printf("\nAvailable Roll Numbers by Semester:\n");

for (int semGroup = 1; semGroup <= 8; semGroup++) {
    int count = 0;
    for (i = 0; i < totalStudent; i++) {
        if (sem[i] == semGroup) {
            if (count == 0)
                printf("Sem-%d : ", semGroup);
            printf("%d ", rollno[i]);
            count++;
        }
    }
    if (count > 0)
        printf("\n");
}


            printf("\nEnter Roll Number to generate marksheet (Attempt %d/3): ", attempts + 1);
            scanf("%d", &roll);

            for (i = 0; i < totalStudent; i++) {
                if (rollno[i] == roll) {
                    found = 1;
                    generatedIndexes[genCount] = i;
                    total = 0;

                    printf("\nEnter marks for the following subjects (out of 100):\n");
                    for (j = 0; j < 5; j++) {
                        printf("%s: ", subjects[j]);
                        scanf("%d", &marks[i][j]);
                        total += marks[i][j];
                    }

                    percent = total / 5.0;

                    if (percent >= 90) strcpy(grade, "A++");
                    else if (percent >= 85) strcpy(grade, "A");
                    else if (percent >= 75) strcpy(grade, "B++");
                    else if (percent >= 70) strcpy(grade, "B");
                    else if (percent >= 60) strcpy(grade, "C");
                    else if (percent >= 50) strcpy(grade, "D");
                    else strcpy(grade, "F");

                    // Ask SGPA for previous semesters
                    if (sem[i] >= 2) {
                        printf("\nEnter SGPA for previous %d semester(s):\n", sem[i] - 1);
                        for (j = 0; j < sem[i] - 1; j++) {
                            printf("Semester %d SGPA: ", j + 1);
                            scanf("%f", &semSgpa[j]);
                        }
                        semSgpa[sem[i] - 1] = sgpa[i]; // current semester SGPA
                        sgpaTotal = 0.0;
                        for (j = 0; j < sem[i]; j++) {
                            sgpaTotal += semSgpa[j];
                        }
                        cgpa = sgpaTotal / sem[i];
                    } else {
                        cgpa = sgpa[i];
                        semSgpa[0] = sgpa[i];
                    }

                    summaryCGPA[genCount] = cgpa; // store for summary
                    genCount++;

                    // Display marksheet
                    printf("\n------- MARKSHEET -------\n");
                    printf("Roll No    : %d\n", rollno[i]);
                    printf("Name       : %s\n", name[i]);
                    printf("Semester   : %d\n", sem[i]);
                    printf("Mobile No. : %.0lf\n", number[i]);
                    printf("SGPA       : %.2f\n", sgpa[i]);
                    printf("Skills     : ");
                    for (j = 0; j < skillcount[i]; j++) {
                        printf("%s ", skill[i][j]);
                    }

                    printf("\n\nMarks:\n");
                    for (j = 0; j < 5; j++) {
                        printf("%-10s: %d\n", subjects[j], marks[i][j]);
                    }

                    printf("\nTotal Marks : %d / 500\n", total);
                    printf("Percentage  : %.2f%%\n", percent);
                    printf("Grade       : %s\n", grade);
                    printf("CGPA        : %.2f\n", cgpa);

                    if (sem[i] >= 2) {
                        printf("\nSemester SGPA:\n");
                        for (j = 0; j < sem[i]; j++) {
                            printf("Sem %-3d", j + 1);
                            if (j != sem[i] - 1) printf(" | ");
                        }
                        printf("\n");
                        for (j = 0; j < sem[i]; j++) {
                            printf("%.2f   ", semSgpa[j]);
                            if (j != sem[i] - 1) printf("| ");
                        }
                        printf("\n");
                    }

                    printf("--------------------------\n\n");
                    break;
                }
            }

            if (!found) {
                printf("Invalid roll number.\n");
                attempts++;
            }
        }

        if (!found && attempts == 3) {
            printf("\n 3 invalid attempts. Skipping this student.\n");
        }

        printf("Do you want to generate marksheet for another student? (Y/N): ");
        scanf(" %c", &ans);
        if (ans == 'N' || ans == 'n') {
            more = 0;
        }
    }

    // Show summary table
    printf("\nDo you want to see marksheet summary in table format? (Y/N): ");
    scanf(" %c", &showTable);

    if (showTable == 'Y' || showTable == 'y') {
        printf("\n==================== MARKSHEET SUMMARY TABLE ===============================\n");
        printf("| %-10s | %-15s | %-12s | %-12s | %-6s | %-6s |\n",
               "Roll No", "Name", "Total Marks", "Percentage", "Grade", "CGPA");
        printf("----------------------------------------------------------------------------\n");

        for (k = 0; k < genCount; k++) {
            int i = generatedIndexes[k];
            int total = 0;
            for (j = 0; j < 5; j++) {
                total += marks[i][j];
            }

            percent = total / 5.0;

            if (percent >= 90) strcpy(grade, "A++");
            else if (percent >= 85) strcpy(grade, "A");
            else if (percent >= 75) strcpy(grade, "B++");
            else if (percent >= 70) strcpy(grade, "B");
            else if (percent >= 60) strcpy(grade, "C");
            else if (percent >= 50) strcpy(grade, "D");
            else strcpy(grade, "F");

            printf("| %-10d | %-15s | %-12d | %-12.2f | %-6s | %-6.2f |\n",
                   rollno[i], name[i], total, percent, grade, summaryCGPA[k]);
        }

        printf("============================================================================\n");
    }
}
