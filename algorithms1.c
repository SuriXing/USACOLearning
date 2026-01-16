#include <stdio.h>

struct student
{
    char name[21];
    int score;
};

void countingSortAscending()
{
    int count[11] = {0};
    int value;
    
    printf("Enter 5 numbers (0-10): ");
    for (int i = 0; i < 5; i++)
    {
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n');
            i--;
            continue;
        }
        
        if (value >= 0 && value <= 10)
        {
            count[value]++;
        } else {
            printf("Number %d out of range (0-10). Try again.\n", value);
            i--;
        }
    }
    
    printf("Sorted ascending: ");
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void countingSortDescending()
{
    int count[1001] = {0};
    int n, value;
    
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid n\n");
        return;
    }
    
    printf("Enter %d numbers (0-1000): ", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n');
            i--;
            continue;
        }
        
        if (value >= 0 && value <= 1000)
        {
            count[value]++;
        } else {
            printf("Number %d out of range (0-1000). Try again.\n", value);
            i--;
        }
    }
    
    printf("Sorted descending: ");
    for (int i = 1000; i >= 0; i--)
    {
        for (int j = 0; j < count[i]; j++)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int a[101], n;
void quickSort(int left, int right)
{
    int i, j, t, temp;
    if (left > right)
    {
        return;
    }

    temp = a[left];
    i = left;
    j = right;

    while (i != j)
    {
        while (a[j] >= temp && i < j)
        {
            j--;
        }
        while (a[i] <= temp && i < j)
        {
            i++;
        }

        if (i<j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    a[left] = a[i];
    a[i] = temp;

    quickSort(left, i-1);
    quickSort(i+1, right);
    
    return;
}

void bubbleSort(struct student a[], int n)
{
    struct student t;
    int i, j;
    
    for (i = 1; i <= n-1; i++)
    {
        for (j = 1; j <= n-i; j++)
        {
            if (a[j].score < a[j+1].score)
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    printf("\nStudents sorted by score (highest first):\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%s %d\n", a[i].name, a[i].score);
    }
}

void deleteRepeatISBNExample()
{
    int student = 0;

    printf("Enter how many students are there in total:\n");
    scanf("%d\n", &student);

    int isbn[student];

    for (int i = 0; i < student; i++)
    {
        printf("Please enter their ISBN one by one:\n");
        scanf("%d\n", &isbn[i]);
    }
    
    int count[256] = {0};
    
    for (int i = 0; i < student; i++)
    {
        count[isbn[i]]++;
        
        if (count[isbn[i]] <= 1)
        {
            printf("%d\n", isbn[i]);
        }
    }
}

int main()
{
    struct student students[8] = 
    {
        {"John Smith", 88},
        {"Maria Garcia", 92},
        {"Kenji Tanaka", 85},
        {"Ananya Patel", 96},
        {"Luca Rossi", 79},
        {"Sophie Martin", 91},
        {"Ahmed Hassan", 83},
        {"Olivia Wilson", 87}
    };

    bubbleSort(a, n);

    countingSortAscending();

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    countingSortDescending();

    deleteRepeatISBNExample();
    
    return 0;
}