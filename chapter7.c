#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

void solveCowRouting()
{
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);

    int to[1001][100000];
    int cost[1001][100000];
    int edge_count[1001] = {0};

    for (int i = 0; i < N; i++)
    {
        int Ci, Mi;
        scanf("%d %d", &Ci, &Mi);
        int route[100];
        for (int j = 0; j < Mi; j++)
        {
            scanf("%d", &route[j]);
        }
        
        for (int j = 0; j < Mi; j++)
        {
            for (int k = j + 1; k < Mi; k++)
            {
                int u = route[j], v = route[k];
                to[u][edge_count[u]] = v;
                cost[u][edge_count[u]++] = Ci;
            }
        }
    }

    int min_cost[1001];
    for (int i = 0; i < 1001; i++) min_cost[i] = INT_MAX;
    min_cost[A] = 0;

    int queue[1001], front = 0, rear = 0;
    queue[rear++] = A;

    while (front < rear)
    {
        int u = queue[front++];
        // Explore all edges from u
        for (int i = 0; i < edge_count[u]; i++)
        {
            int v = to[u][i];
            int new_cost = min_cost[u] + cost[u][i];
            if (new_cost < min_cost[v]) {
                min_cost[v] = new_cost;
                queue[rear++] = v;
            }
        }
    }

    // Output result
    printf("%d\n", min_cost[B] == INT_MAX ? -1 : min_cost[B]);
}

int fencing()
{
    int N, M;
    scanf("%d %d", &N, &M);

    bool covered[N + 1];
    int sensor_count[N + 1];

    for (int i = 0; i <= N; i++) {
        covered[i] = false;
        sensor_count[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = a; j <= b; j++) {
            covered[j] = true;
            sensor_count[j]++;
        }
    }

    int total_covered = 0;
    for (int i = 1; i <= N; i++)
    {
        if (covered[i])
        {
            total_covered++;
        }
    }

    int K;
    scanf("%d", &K);
    printf("%d %d\n", total_covered, sensor_count[K]);

    return 0;
}

int fencing_fast()
{
    int N, M;
    scanf("%d %d", &N, &M);

    bool covered[N + 1];
    int sensor_count[N + 1];

    for (int i = 0; i <= N; i++) {
        covered[i] = false;
        sensor_count[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = a; j <= b; j++) {
            covered[j] = true;
            sensor_count[j]++;
        }
    }

    int total_covered = 0;
    for (int i = 1; i <= N; i++)
    {
        if (covered[i])
        {
            total_covered++;
        }
    }

    int K;
    scanf("%d", &K);
    printf("%d %d\n", total_covered, sensor_count[K]);

    return 0;
}

int threeDigitSum17()
{
    int count = 0;

    for (int num = 100; num <= 999; num++)
    {
        int hundred = num / 100;
        int ten = (num / 10) % 10;
        int unit = num % 10;

        if (hundred + ten + unit == 17)
        {
            count++;
        }
    }

    return count;
}

int fenceProblem()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int min_start = N + 1;
    int max_end = 0;
    int longest_stretch = 0;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a < min_start) min_start = a;
        if (b > max_end) max_end = b;

        int length = b - a + 1;
        if (length > longest_stretch) {
            longest_stretch = length;
        }
    }

    int total_painted = max_end - min_start + 1;

    printf("%d %d\n", total_painted, longest_stretch);
    return 0;
}

typedef struct _Range
{
    int start;
    int end;
} Range;

int FencePainting_Hard()
{
    int n;
    scanf("%d", &n);

    Range cows[n];
    int min_start = 101;
    int max_end = 0;
    int longest_stretch = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cows[i].start, &cows[i].end);
        
        if (cows[i].start < min_start) min_start = cows[i].start;
        if (cows[i].end > max_end) max_end = cows[i].end;
        
        int length = cows[i].end - cows[i].start + 1;
        if (length > longest_stretch)
        {
            longest_stretch = length;
        }
    }

    int total_painted = max_end - min_start + 1;

    printf("%d %d\n", total_painted, longest_stretch);
    return 0;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}

typedef struct _Ranges 
{
    int range_start; 
    int range_end;
} Ranges;

int FencePainting(Ranges firstCow, Ranges secondCow)
{
    int total_painted = (firstCow.range_end - firstCow.range_start + 1) + (secondCow.range_end - secondCow.range_start + 1);
    int overlap = max(0, min(firstCow.range_end, secondCow.range_end) - max(firstCow.range_start, secondCow.range_start) + 1);

    return (total_painted - overlap);
}

int FencePainting_onlyOverlap(const Ranges* cows, int count)
{
    assert(count > 0);

    int start_max=0;
    int end_min=0;

    for (int i = 0; i < count; i++)
    {
        start_max = max(start_max, cows[i].range_start);
        end_min = min(end_min, cows[i].range_end);
    }

    return (end_min - start_max +1);
}

typedef struct { int x; int y; } Point;

void findTreasure_smart(int a, int b)
{
    assert(a > 0);
    assert(b > 0);

    srand(time(0));
    Point treasure = { rand() % a, rand() % b };
    Point guess;
    int attempts = 0;
    const int max_attempts = 5;

    while (attempts < max_attempts)
    {
        printf("Attempt %d/%d: Enter coordinates (X Y): ", attempts + 1, max_attempts);
        if (scanf("%d %d", &guess.x, &guess.y) != 2)
        {
            printf("Invalid input! Please enter two integers.\n");
            while (getchar() != '\n');
            continue;
        }

        if (guess.x == treasure.x && guess.y == treasure.y)
        {
            printf("Congratulations! You found the treasure at (%d, %d)!\n", treasure.x, treasure.y);
            return;
        } 
        else
        {
            printf("Wrong guess. ");
            if (guess.x < treasure.x) printf("Go right. ");
            if (guess.x > treasure.x) printf("Go left. ");
            if (guess.y < treasure.y) printf("Go up. ");
            if (guess.y > treasure.y) printf("Go down. ");
            printf("\n");
        }
        attempts++;
    }
    printf("Game over! The treasure was at (%d, %d).\n", treasure.x, treasure.y);
}

void findTreasure(int a, int b)
{
    assert(a > 0);
    assert(b > 0);

    srand(time(0));
    int num1 = rand() % a;
    int num2 = rand() % b;

    int Xaxis = 0;
    int Yaxis = 0;

    while(1)
    {
        printf("Enter coordinates (X Y): ");
        scanf("%d %d", &Xaxis, &Yaxis);
        
        if ((Xaxis == num1) && (Yaxis == num2))
        {
            printf("Congratulations, You found the treasure at (%d, %d)!\n", num1, num2);
            break;
        }
        else
        {
            printf("Please try again\n");
        }
    }
}      

int findPriceAfterTax(int price, int tax)
{
    assert(price > 0);
    assert(tax > 0);
;    return (price + (price * (tax/100)));
}

void printScalablehouse(int size)
{
    assert(size >0);

    for (int i = 0; i < size; i++) printf(" ");
    printf("*\n");
    
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++) printf(" ");
        printf("*");
        for (int j = 0; j < 2*i - 1; j++) printf(" ");
        printf("*\n");
    }
    
    printf(" ");
    for (int i = 0; i < 2*size - 1; i++) printf("*");
    printf("\n");
    
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < size - i; j++) printf(" ");
        printf("*");
        for (int j = 0; j < 2*i - 1; j++) printf(" ");
        printf("*\n");
    }
    
    for (int i = 0; i < size; i++) printf(" ");
    printf("*\n");
}

int fourleafCloverNum(int num)
{
    assert(num > 0);

    int ones = 0;
    int ten = 0;
    int hundred = 0;
    int thousand = 0;
    
    ones = num % 10;
    ten = (num / 10) % 10;
    hundred = (num / 100) % 10;
    thousand = (num / 1000) % 10;

     
    if ((ones * ones * ones * ones) + 
        (ten * ten * ten * ten) + 
        (hundred * hundred * hundred * hundred) + 
        (thousand * thousand * thousand * thousand) == num)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int fiveleafCloverNum(int num)
{
    assert(num > 0);
    int ones = 0;
    int ten = 0;
    int hundred = 0;
    int thousand = 0;
    
    ones = num % 10;
    ten = (num / 10) % 10;
    hundred = (num / 100) % 10;
    thousand = (num / 1000) % 10;

     
    if ((ones * ones * ones * ones) + 
        (ten * ten * ten * ten) + 
        (hundred * hundred * hundred * hundred) + 
        (thousand * thousand * thousand * thousand) == num)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void printScalableStar(int size)
{
    assert(size > 0);

    for (int i = 0; i < size; i++) printf(" ");
    printf("*\n");
    
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++) printf(" ");
        printf("*");
        for (int j = 0; j < 2*i - 1; j++) printf(" ");
        printf("*\n");
    }
    
    printf(" ");
    for (int i = 0; i < 2*size - 1; i++) printf("*");
    printf("\n");
    
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < size - i; j++) printf(" ");
        printf("*");
        for (int j = 0; j < 2*i - 1; j++) printf(" ");
        printf("*\n");
    }
    
    for (int i = 0; i < size; i++) printf(" ");
    printf("*\n");
}

void printLeftToRightTriangle(int rows)
{
    assert(rows > 0);
    int num = 1;
    for (int i = 1; i <= rows; i++)
    {
        int leadingSpaces = (rows - i) * 3;
        for (int space = 0; space < leadingSpaces; space++)
        {
            printf(" ");
        }
        
        for (int j = 1; j <= i; j++)
        {
            printf("%2d ", num++);
        }
        printf("\n");
    }
}

void printLeftToRightTriangle2(int rows)
{
    assert(rows > 0);
    int num = 1;
    for (int i = 1; i <= rows; i++)
    {
        int leadingSpaces = (rows - i) * 3;
        for (int space = 0; space < leadingSpaces; space++)
        {
            printf(" ");
        }
        
        for (int j = 1; j <= i; j++)
        {
            printf("%2d ", num++);
        }
        printf("\n");
    }
}

int main()
{
	return 0;
}
