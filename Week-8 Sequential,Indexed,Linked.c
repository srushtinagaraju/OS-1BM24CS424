#include <stdio.h>

#define MAX 50

void sequential() {
    int files[MAX], start, length, i, j, flag = 0;
    for (i = 0; i < MAX; i++) files[i] = 0;

    printf("\nSequential Allocation\n");
    printf("Enter starting block and length of file: ");
    scanf("%d%d", &start, &length);

    for (i = start; i < start + length; i++) {
        if (files[i] == 1) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        for (i = start; i < start + length; i++) files[i] = 1;
        printf("File allocated from block %d to %d\n", start, start + length - 1);
    } else {
        printf("Blocks not free. Cannot allocate.\n");
    }
}

void indexed() {
    int files[MAX], indexBlock, n, blocks[MAX], i, flag = 0;
    for (i = 0; i < MAX; i++) files[i] = 0;

    printf("\nIndexed Allocation\n");
    printf("Enter index block: ");
    scanf("%d", &indexBlock);
    if (files[indexBlock] == 1) {
        printf("Index block already allocated.\n");
        return;
    }

    printf("Enter number of blocks needed: ");
    scanf("%d", &n);
    printf("Enter blocks: ");
    for (i = 0; i < n; i++) scanf("%d", &blocks[i]);

    for (i = 0; i < n; i++) {
        if (files[blocks[i]] == 1) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        files[indexBlock] = 1;
        for (i = 0; i < n; i++) files[blocks[i]] = 1;
        printf("File allocated with index block %d and blocks: ", indexBlock);
        for (i = 0; i < n; i++) printf("%d ", blocks[i]);
        printf("\n");
    } else {
        printf("Some blocks are already allocated. Cannot allocate.\n");
    }
}

void linked() {
    int files[MAX], n, blocks[MAX], i, flag = 0;
    for (i = 0; i < MAX; i++) files[i] = 0;

    printf("\nLinked Allocation\n");
    printf("Enter number of blocks needed: ");
    scanf("%d", &n);
    printf("Enter blocks: ");
    for (i = 0; i < n; i++) scanf("%d", &blocks[i]);

    for (i = 0; i < n; i++) {
        if (files[blocks[i]] == 1) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        for (i = 0; i < n; i++) files[blocks[i]] = 1;
        printf("File allocated using linked blocks: ");
        for (i = 0; i < n; i++) printf("%d -> ", blocks[i]);
        printf("NULL\n");
    } else {
        printf("Some blocks are already allocated. Cannot allocate.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nFile Allocation Methods\n");
        printf("1. Sequential\n2. Indexed\n3. Linked\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: sequential(); break;
            case 2: indexed(); break;
            case 3: linked(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
