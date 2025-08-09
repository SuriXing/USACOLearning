#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

void nlanterns(int n)
{
    assert(n > 0);

    for (int i = 1; i * i <= n; i++)//needs to be平方数because only square numbers has a odd number of divisors
    {
        printf("%d\n", i*i);
    }
}

/*Of course! Here is a classic and excellent USACO Bronze problem that covers fundamental concepts like simulation and basic input/output handling.

### Problem: The Bovine Shuffle (USACO Bronze, December 2017)

**Problem Description:**
Farmer John's `N` cows (`3 <= N <= 100`) are standing in a row. Each cow has a distinct integer ID number. To mix things up, he performs a "shuffle," which is a specific set of instructions on how the cows should rearrange themselves.

The shuffle is described by a permutation of `N` numbers, `a1, a2, ..., aN`. This means that the cow currently in position `i` will move to position `a_i` during the shuffle.

For example, if the shuffle is defined by `[2, 3, 1]` for 3 cows:
*   The cow in position 1 moves to position 2.
*   The cow in position 2 moves to position 3.
*   The cow in position 3 moves to position 1.

Farmer John performs this shuffle exactly **three times**. Your task is to determine the final order of the cows after three shuffles.

**Input Format:**
*   **Line 1:** The integer `N`.
*   **Line 2:** The `N` integers `p1, p2, ..., pN`, which are the IDs of the cows in their initial order (from position 1 to position N).
*   **Line 3:** The `N` integers `a1, a2, ..., aN`, which define the shuffle. This line describes where each position's cow moves *to*.

**Output Format:**
*   `N` lines, each containing the ID of a cow. The first line should be the cow in position 1 after three shuffles, the second line the cow in position 2, and so on.

**Example:**
Input (`shuffle.in`):
```
3
1 2 3
2 3 1
```
Output (`shuffle.out`):
```
2
3
1
```

**Explanation:**
Let's trace the shuffles step-by-step:
*   **Start:** `[Cow1, Cow2, Cow3]` at positions `[1, 2, 3]`
*   **After 1st shuffle:**
    *   Cow1 (pos 1) moves to pos 2.
    *   Cow2 (pos 2) moves to pos 3.
    *   Cow3 (pos 3) moves to pos 1.
    *   New order: `[Cow3, Cow1, Cow2]`
*   **After 2nd shuffle:**
    *   Cow3 (pos 1) moves to pos 2.
    *   Cow1 (pos 2) moves to pos 3.
    *   Cow2 (pos 3) moves to pos 1.
    *   New order: `[Cow2, Cow3, Cow1]`
*   **After 3rd shuffle:**
    *   Cow2 (pos 1) moves to pos 2.
    *   Cow3 (pos 2) moves to pos 3.
    *   Cow1 (pos 3) moves to pos 1.
    *   **Final order:** `[Cow1, Cow2, Cow3]`? Wait, that's not right!

Wait, let's track the *positions* more carefully. The shuffle rule `[2, 3, 1]` means "the cow from position `i` goes to position `a_i`".

A more reliable method is to think backwards or use an array to simulate the movement.

**Key Insight & Solution Approach:**
This is a perfect problem for **simulation** and **array manipulation**.

1.  **Read the Inputs:** Read `N`, the initial list of cow IDs, and the shuffle permutation.
2.  **Simulate the Shuffle Three Times:** You need to apply the same shuffle transformation to the order of cows three times.
3.  **How to Apply One Shuffle:**
    *   Create a new temporary array `new_order` of size `N`.
    *   For each current position `i` (from 0 to N-1 in code):
        *   The cow currently at position `i` is supposed to move to position `shuffle[i] - 1` (we subtract 1 because array indices start at 0, but the problem's positions start at 1).
    *   So, we set `new_order[shuffle[i] - 1] = current_order[i]`.
4.  **Repeat:** After calculating `new_order`, this becomes the `current_order` for the next shuffle. Repeat this process two more times.
5.  **Output:** After three iterations, print the final `current_order`, one cow per line.

**Why this is a great Bronze problem:**
*   It teaches how to read input and format output.
*   It involves basic array operations and creating temporary arrays.
*   It requires understanding and applying a simple algorithm (simulation) multiple times.
*   It has a straightforward concept (applying a permutation) that is fundamental to many computer science problems.

You can find this problem and test your solution on the official USACO website: [USACO 2017 December Contest, Bronze - Problem 1. The Bovine Shuffle](http://www.usaco.org/index.php?page=viewproblem2&cpid=760)

Good luck! Try to code it yourself first. The feeling of getting it accepted is fantastic*/

/*Here's a USACO Bronze-level practice problem for you:

​Problem: Cow Gymnastics​
​Problem Statement:​​
In cow gymnastics, Farmer John's cows perform exercises in a rectangular arena. The cows are initially arranged in a certain order, and Farmer John records their positions. After some time, the cows rearrange themselves, and Farmer John records their new positions.

Given the initial and final positions of the cows, determine how many pairs of cows (A, B) switched their relative order. That is, in the initial arrangement, cow A was ahead of cow B, but in the final arrangement, cow B is ahead of cow A.

​Input:​​

The first line contains an integer N (1 ≤ N ≤ 10), the number of cows.
The second line contains N distinct integers representing the initial order of cows (each cow is labeled uniquely from 1 to N).
The third line contains N distinct integers representing the final order of cows.
​Output:​​

A single integer, the number of pairs (A, B) where the relative order of A and B changed.*/


/*Problem: Cow Routing (Bronze/Silver)​​
​Input File:​​ cowroute.in
​Output File:​​ cowroute.out

​Problem Statement:​​
Farmer John's cows need to travel from farm A to farm B (1 ≤ A, B ≤ 1000; A ≠ B). There are N (1 ≤ N ≤ 100) available bidirectional cow routes, each operated by a different company. Route i has a cost C_i (1 ≤ C_i ≤ 100) and passes through M_i farms in a specific order (3 ≤ M_i ≤ 100). A cow can use a route if it boards at any farm along the route and disembarks at any subsequent farm (but cannot go backward).

​Task:​​ Find the minimum total cost for a cow to travel from A to B. If it’s impossible, output -1.
*/

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

/*Problem Statement:​​
Farmer John wants to paint a fence with N wooden panels labeled 1 to N. He hires M cows to help, where each cow paints a ​consecutive range​ of panels (e.g., [a_i, b_i]). However, some cows might paint overlapping ranges.

​Your Task:​​
Given the ranges painted by each cow, calculate:

​Total number of panels painted at least once​ (union of all ranges).
​Longest contiguous stretch painted by a single cow​ (even if others overlap).
​Input Format:​​

Line 1: Two integers N (number of panels, 1 ≤ N ≤ 1000) and M (number of cows, 1 ≤ M ≤ 100).
Next M lines: Two integers a_i and b_i (1 ≤ a_i ≤ b_i ≤ N), representing the range painted by the i-th cow.
​Output Format:​​

A single line with two integers:
First integer: Total panels painted at least once.
Second integer: Longest contiguous stretch by one cow.*/

/*Given N cows (where N ≥ 1), each painting a range [a_i, b_i] on a fence with panels labeled 1 to 100, calculate:

​Total panels painted at least once​ (union of all ranges).
​Longest contiguous stretch painted by any single cow.*/

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

/*Problem Statement
Farmer John is painting a fence that has 100 wooden panels labeled 1 to 100. Each cow paints a consecutive range of panels. However, some cows might paint overlapping ranges.

Given the ranges painted by each cow, calculate:

The ​total number of panels painted at least once.
The ​longest contiguous stretch of panels painted by a single cow​ (even if other cows paint parts of it).
​Input Format:

Line 1: Two integers a and b (the range painted by the first cow).
Line 2: Two integers c and d (the range painted by the second cow).
​Output Format:

A single line with two integers:
First integer: Total panels painted at least once.
Second integer: Longest contiguous stretch by one cow.*/

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
    return (price + (price * (tax/100)));
}

void printScalablehouse(int size)
{
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

int sumOfFraction(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += 1/i;
    }
    return count;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findSmallestNum(int* array, int start, int end)
{
    int smallestNum = start;
    for (int i = start + 1; i < end; i++)
    {
        if (array[i] < array[smallestNum])
        {
            smallestNum = i;
        }
    }
    return smallestNum;
}

void selectArrange(int* array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int smallestNum = findSmallestNum(array, i, rows);
        
        // Swap the found smallest element with the first element of the unsorted part
        int temp = array[i];
        array[i] = array[smallestNum];
        array[smallestNum] = temp;
    }
}

void printRectangleOfAstrics(int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void printRhombusOfAstrics(int side)
{
    for (int i = 1; i <= side; i++)
    {
        for (int j = 1; j <= side; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void printSquareOfAstrics(int side)
{
    for (int i = 1; i <= side; i++)
    {
        for (int j = 1; j <= side; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void printMultiplicationTable__81()
{
    for (int i = 1; i <= 9; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            printf("%d * %d=%-2d  ", j, i, i * j);
        }
        printf("\n");
    }
}

void printCenteredPascalTriangle(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", number);
            number = (number * (i - j)) / (j + 1);
        }
        int count = rows - i;
        while(count > 0)
        {
            printf(" ");
            count --;
        }
        printf("\n");
    }
}

void printPascalTriangle(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", number);
            number = (number * (i - j)) / (j + 1);
        }
        printf("\n");
    }
}

void printPascalTriangle_easierversion(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", number);
            number = (number * (i - j)) / (j + 1);
        }
        printf("\n");
    }
}

void printDiagnolTriangle(int rows)
{
    int current = 1;
    int diagnol = 1;
    
    for (int i = 0; i < rows; i++)
    {
        int num = current;
        int step = diagnol;
        
        for (int j = 0; j < rows - i; j++)
        {
            printf("%d ", num);
            num += step;
            step++;
        }
        
        printf("\n");
        current += diagnol;
        diagnol++;
    }
}

/*
Problem:
The Merry Milk Makers company has N (1 ≤ N ≤ 5000) farmers, each with a certain amount of milk to sell at a certain price. The company wants to buy at least M (1 ≤ M ≤ 2,000,000) units of milk, spending the least amount of money possible.

Given:

N farmers, each with a price per unit (in cents) and maximum amount they can sell
M = total units needed

Output:
The minimum cost to buy at least M units of milk
*/

typedef struct {
    int price;
    int amount;
} Farmer;

int compareFarmers(const void *a, const void *b)
{
    return ((Farmer*)a)->price - ((Farmer*)b)->price;
}

int mixMilk(int N, int M, Farmer farmers[])
{
    qsort(farmers, N, sizeof(Farmer), compareFarmers);
    int cost = 0, remaining = M;
    
    for (int i = 0; i < N && remaining > 0; i++) {
        int take = remaining < farmers[i].amount ? remaining : farmers[i].amount;
        cost += take * farmers[i].price;
        remaining -= take;
    }
    
    return cost;
}

// problem solved//

void simpleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printCenteredReversedTriangle(int rows) 
{
    int start_num = (rows * (rows + 1)) / 2;
    int num = start_num;
    
    for (int i = 1; i <= rows; i++)
    {
        for (int space = 1; space <= rows - i; space++)
        {
            printf("  ");
        }
        
        for (int j = 1; j <= i; j++)
        {
            printf("%-2d ", num--);
        }
        printf("\n");
    }
}

int returnGreaterNum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int abvalue(int num)
{
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        count++;
    }
    return count;
}

int strLength(const char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

int countNotSpaceChars(const char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        if ((*str != ' ') && (*str != '\n') && (*str != '\r')) 
        {
            count++;
        }
        str++;
    }
    return count;
}


int sumOfConsecutiveNum(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    return sum;
}

int grade(int hwGrade, int examGrade, int testGrade)
{
    return (hwGrade/5.0) + (examGrade*3.0/10) + (testGrade/2.0);
}

int sumOfNumOnEdgeOfRectangle(int n, int m, int matrix[][m])
{
    int sum = 0;

       for (int j = 0; j < m; j++)
    {
        sum += matrix[0][j];
        if (n > 1)
        {
            sum += matrix[n - 1][j];
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        sum += matrix[i][0];
        if (m > 1)
        {
            sum += matrix[i][m - 1];
        }
    }

    return sum;
}

void matrixAdd(int n, int m, int A[][m], int B[][m], int C[][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printCenteredNumberTriangle(int rows)
{
    int current_num = 1;
    for (int i = 1; i <= rows; i++) 
    {
        int leading_spaces = (rows - i) * 2;
        for (int s = 0; s < leading_spaces; s++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) 
        {
            printf("%-3d", current_num++);
        }
        printf("\n\n");
    }
}

void printCenteredNumberTriangle2(int rows)
{
    int current_num = 1;
    for (int i = 1; i <= rows; i++) 
    {
        int leading_spaces = (rows - i) * 2;
        for (int s = 0; s < leading_spaces; s++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) 
        {
            printf("%-3d", current_num++);
        }
        printf("\n\n");
    }
}

void printTriangle(int rows)
{
    int num = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", num++);
        }
        printf("\n");
    }
}

void printReversedTriangle(int rows) 
{
    int start_num = (rows * (rows + 1)) / 2;
    int num = start_num;
    
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", num--);
        }
        printf("\n");
    }
}

void printMultiplicationTable()
{
    for (int i = 1; i <= 9; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            printf("%d * %d=%-2d  ", j, i, i * j);
        }
        printf("\n");
    }
}

int absoluteValue(int n)
{
    int count = 0;

    if (n <= 0)
    {
        return n;
    }

    for (int i = 0; i < n; i++)
    {
        count ++;
    }

    return count;
}

bool containsSeven(int num)
{
    while (num > 0)
    {
        int digit = num % 10;
        if (digit == 7)
        {
            return true;
        }
        num /= 10;
    }
    return false;
}

int sumOfSquares_seven(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 7 != 0 && !containsSeven(i))
        {
            sum += i * i;
        }
    }
    return sum;
}

void returnSquare(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n-1)
            {
                printf("*\n");
            }
            else
            {
                printf("*");
            }
        }
    }
}

int howManyLowerThanAverage(int grades[10])
{
    int sum;
    int count;

    for (int i = 0; i <= 10; i++)
    {
        sum += grades[i];
    }

    for (int i = 0; i <= 10; i++)
    {
        if (grades[i] < sum/10)
        {
            count += 1;
        }
    }

    return count;
}

int gcdOfTwoNum(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findLcmOfTwoInt(int a, int b)
{
    if ((a <= 0) || (b <= 0))
    {
        return 0;
    }

    return (a * b)/gcdOfTwoNum(a, b);
}

int whichOneIsBigger(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else if (a == b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int evenNumSum(int n)
{
    int sum = 0;

    for (int i = 2; i <= n; i += 2)
    {
        sum += i;
    }

    return sum;
}

void abcd()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int h = 0; h < 10; h++)
                {
                    if ((((10*i + j) * (10*k + h)) == 1000*i + 100*j + 10*k + h))
                    {
                        printf("%d\n", (1000*i + 100*j + 10*k +h));
                    }
                }
            }
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("\n");
}

void makeArraySmallToBig(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int averageOfArray(int array[], int n)
{
    int sum;

    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }

    return sum/n;
}

void printAstrics(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
}

int changeValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

void returnCommentToGrades()
{
    char grade;
    printf("Enter your grade (A, B, C, D, F): \n");
    scanf(" %c", &grade);
    switch (grade) {
        case 'A':
            printf("Excellent work!\n");
            break;
        case 'B':
            printf("Good job!\n");
            break;
        case 'C':
            printf("You passed.\n");
            break;
        case 'D':
            printf("You need to improve.\n");
            break;
        case 'F':
            printf("You failed. Please try again.\n");
            break;
        default:
            printf("Invalid grade entered.\n");
    }
}

void twoIntegersCalculation() {
    char operation;
    int a, b;
    
    printf("Enter two integers and the operation you want at the end\n");
    scanf("%d %d %c", &a, &b, &operation);

    if (operation == '+') {
        printf("The sum of %d and %d is: %d\n", a, b, a + b);
    }
    else if (operation == '-') {
        printf("The difference of %d and %d is: %d\n", a, b, a - b);
    }
    else if (operation == '*') {
        printf("The product of %d and %d is: %d\n", a, b, a * b);
    }
    else if (operation == '/') {
        if (b != 0) {
            printf("The division of %d by %d is: %.2f\n", a, b, (double)a / b);
        }
        else {
            printf("Division by zero is not allowed.\n");
        }
    }
    else {
        printf("Invalid operation. Please use +, -, *, or /.\n");   
    }
}

bool determineTriangle(int a, int b, int c)
{
    if ((a+b > c) && (a+c > b) && (b+c > a))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool determineLeapYear(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true; // It's a leap year
    }
    else
    {
        return false; // It's not a leap year
    }
}

int selfcheck_PlusOrMinus()
{
    int a, b, c;
    printf("Enter two integers that are separated by a comma & enter 0 if you want to find their sum and 1 if you want to find their difference: \n");
    scanf("%d, %d, %d", &a, &b, &c);
    if (c == 0)
    {
        printf("The sum of %d and %d is: %d\n", a, b, a + b);
    }
    else if (c == 1)
    {
        printf("The difference of %d and %d is: %d\n", a, b, a - b);
    }
    else
    {
        printf("Invalid input for operation. Please enter 0 for sum or 1 for difference.\n");
    }
    return 0;
}

int sumOf2int()
{
    int a, b;
    printf("Enter two integers in the form of integer a, integer b: \n");
    scanf("%d, %d", &a, &b);

    return a+b;
}

int sumOf2int_stepversion()
{
    int a, b;
    printf("Enter two integers in the form of integer a, integer b: \n");
    scanf("%d, %d", &a, &b);

    int sum = a + b;

    printf("You entered: %d and %d\n", a, b);
    printf("Calculating the sum... %d\n", sum);

    return a + b;
}

int main()
{

    int array[5] = {12, 33, 12, 41, 1};

    int grades[10] = {37, 90, 100, 90, 40 , 25, 18, 59, 1, 10};

    /*
    int resultForSum = sumOf2int();
    printf("The sum of the two integers is: %d\n", result);

    int stepResult = sumOf2int_stepversion();
    printf("The sum of the two integers in step version is: %d\n", stepResult);

    int selfcheckResult = selfcheck_PlusOrMinus();

    bool result = determineLeapYear(2020);
    if (result == 1)
    {
        printf("2020 is a leap year.\n");
    }
    else
    {
        printf("2020 is not a leap year.\n");
    }

    int triangleResult = determineTriangle(3, 4, 12);
    printf("The triangle side length is %s\n", triangleResult ? "valid" : "not valid");

    twoIntegersCalculation();
    
    returnCommentToGrades();

    printAstrics(7);

    printArray(array, 5);

    makeArraySmallToBig(array, 5);

    printArray(array, 5);

    abcd();

    int sum = evenNumSum(4);
    printf("%d\n", sum);

    int gcd = gcdOfTwoNum(17, 25);
    printf("The gcd of 17 & 25 is %d\n", gcd);

    int count = howManyLowerThanAverage(grades);
    printf("%d\n", count);
    
    returnSquare(5);

    int lcm = findLcmOfTwoInt(12, 18);
    printf("%d\n", lcm);

    int sumOfSquare = sumOfSquares_seven(21);
    printf("Result: %d\n", sumOfSquare);
    
    int arr[] = {5, 2, 9, 1, 5, 6};
    bubbleSort(arr, 6);
    
    int numberInStr = countNotSpaceChars("ABCD123 674");//10
    printf("%d\n", numberInStr);
    
    printLeftToRightTriangle(6);
    
    printMultiplicationTable_81();

    printCenteredPascalTriangle(7);

    printRectangleOfAstrics(3,5);

    printScalableStar(5);

    fourleafCloverNum(1634);

    findTreasure(5, 6);

    fenceProblem();
    
    printLeftToRightTriangle(6);
    return 0;
    */
    nlanterns(6);
}