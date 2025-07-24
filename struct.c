#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 5

// Define the struct to hold IP data
struct NetworkEntry {
    char ip[16];       // For IPv4 in xxx.xxx.xxx.xxx format
    char netmask[16];  // Netmask also in xxx.xxx.xxx.xxx format
    int port;
};

int main() {
    FILE *file;
    struct NetworkEntry entries[MAX_ENTRIES];
    int i;

    // Open the file for reading
    file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file.txt");
        return 1;
    }

    // Read the entries from the file
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (fscanf(file, "%15s %15s %d", entries[i].ip, entries[i].netmask, &entries[i].port) != 3) {
            fprintf(stderr, "Error reading entry %d\n", i + 1);
            break;
        }
    }

    fclose(file);

    // Print the read entries
    printf("Read Network Entries:\n");
    for (int j = 0; j < i; j++) {
        printf("Entry %d: IP = %s, Netmask = %s, Port = %d\n", j + 1,
               entries[j].ip, entries[j].netmask, entries[j].port);
    }

    return 0;
}

