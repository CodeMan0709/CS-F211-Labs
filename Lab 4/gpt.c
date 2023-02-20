#include <stdio.h>
#include <stdlib.h>

// Structure for each preferred slot
typedef struct
{
    int start;
    int end;
} Slot;

// Comparator function for sorting the slots based on start time
int cmp(const void *a, const void *b)
{
    Slot *s1 = (Slot *)a;
    Slot *s2 = (Slot *)b;
    return s1->start - s2->start;
}

int main()
{
    int n;
    scanf("%d", &n);

    // Allocate memory for the array of slots
    Slot *slots = (Slot *)malloc(n * sizeof(Slot));

    // Read the preferred slots
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &slots[i].start, &slots[i].end);
    }

    // Sort the slots based on start time
    qsort(slots, n, sizeof(Slot), cmp);

    // Merge the overlapping slots
    int num_new_slots = 0;
    Slot *new_slots = (Slot *)malloc(n * sizeof(Slot));
    new_slots[0] = slots[0];
    for (int i = 1; i < n; i++)
    {
        if (slots[i].start <= new_slots[num_new_slots].end)
        {
            // Merge the two slots
            if (slots[i].end > new_slots[num_new_slots].end)
            {
                new_slots[num_new_slots].end = slots[i].end;
            }
        }
        else
        {
            // Add the current slot as a new slot
            num_new_slots++;
            new_slots[num_new_slots] = slots[i];
        }
    }

    // Output the new slots
    printf("%d\n", num_new_slots + 1);
    for (int i = 0; i <= num_new_slots; i++)
    {
        printf("%d %d\n", new_slots[i].start, new_slots[i].end);
    }

    // Free memory
    free(slots);
    free(new_slots);

    return 0;
}
