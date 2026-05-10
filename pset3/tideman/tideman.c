#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool search_paths(int path, int destination);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");
    if (voter_count <= 0)
    {
        printf("There should be some voters for the election.\n");
        return 2;
    }

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int temp = 0;
    int temp_add = 0;
    int temp_add_ad = 0;
    int index = 0;
    for (int i = 0; i < pair_count; i++)
    {
        temp = 0;
        index = 0;

        // finding the most strongest victory
        // i because strongest victories are stored before , we are neglecting them.
        for (int j = i; j < pair_count; j++)
        {

            if (temp < preferences[pairs[j].winner][pairs[j].loser] -
                           preferences[pairs[j].loser][pairs[j].winner])
            {

                temp = preferences[pairs[j].winner][pairs[j].loser] -
                       preferences[pairs[j].loser][pairs[j].winner];
                index = j;
            }
        }
        if (index != i)
        {

            temp_add_ad = pairs[index].winner;
            temp_add = pairs[index].loser;
            pairs[index].winner = pairs[i].winner;
            pairs[index].loser = pairs[i].loser;
            pairs[i].winner = temp_add_ad;
            pairs[i].loser = temp_add;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    bool cycle;
    for (int i = 0; i < pair_count; i++)
    {
        if (!search_paths(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    bool edged;
    for (int i = 0; i < candidate_count; i++)
    {
        edged = false;
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[pairs[j].winner][pairs[j].loser])
            {
                if (i == pairs[j].loser)
                {
                    edged = true;
                }
            }
        }
        // assuming to have only one winner
        if (!edged)
        {
            printf("%s\n", candidates[i]);
            break; // prevention for extra iterations
        }
    }
}

bool search_paths(int path, int destination)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (locked[path][j])
        {
            if (j == destination)
            {
                return true;
            }
            if (search_paths(j, destination))
            {
                return true;
            }
        }
    }
    return false;
}
