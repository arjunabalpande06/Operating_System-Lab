#include <stdio.h>

int main() {
    int i, j, n, capacity, page, k;
    int page_faults = 0, found;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    
    printf("Enter page reference sequence: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter memory capacity: ");
    scanf("%d", &capacity);
    
    int memory[capacity]; 
    int last_used[capacity]; 
    
    for(i = 0; i < capacity; i++) {
        memory[i] = -1; 
        last_used[i] = -1; 
    }
    
    int time = 0;
    
    for(i = 0; i < n; i++) {
        page = pages[i];
        found = 0;
        
        
        for(j = 0; j < capacity; j++) {
            if(memory[j] == page) {
                found = 1;
                last_used[j] = time; 
                break;
            }
        }
        
        if(!found) {
            page_faults++;
            
            int lru_index = 0;
            int min_time = last_used[0];
            for(j = 1; j < capacity; j++) {
                if(last_used[j] < min_time) {
                    min_time = last_used[j];
                    lru_index = j;
                }
            }
            memory[lru_index] = page;
            last_used[lru_index] = time;
        }
        
        
        printf("Memory state after accessing page %d: ", page);
        for(k = 0; k < capacity; k++) {
            if(memory[k] != -1)
                printf("%d ", memory[k]);
        }
        printf("\n");
        
        time++;
    }
    
    printf("Total page faults: %d\n", page_faults);
    
    return 0;
}
