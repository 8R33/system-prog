#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Variable declaration
    int fd; 
    char buffer[95]; 
    char msg[60] = "Goodmorning Kimani"; 
    // Open the file "find.txt" with both read and write access (O_RDWR).
    // If the file doesn't exist, it will be created.
    fd = open("find.txt", O_RDWR | O_CREAT, 0666);
    
    if (fd != -1) { // Checks if the file was opened successfully
        printf("Find.txt opened with read write access\n");
        write(fd, msg, sizeof(msg));
        lseek(fd, 0, SEEK_SET);
        read(fd, buffer, sizeof(msg));
        printf("%s was written to my file\n", buffer);
        close(fd);
    } else {
        perror("Error opening the file");
    }

    return 0; 
}
