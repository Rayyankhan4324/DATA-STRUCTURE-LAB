#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <cstring>

using namespace std;

// ============================================
// 1. CREATE FILE
// ============================================
void createFile() {
    char filename[100];
    cout << "Enter filename: ";
    cin >> filename;

    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        cout << "Error creating file\n";
        return;
    }
    cout << "File created successfully\n";
    close(fd);
}

// ============================================
// 2. WRITE FILE
// ============================================
void writeFile() {
    char filename[100], data[500];
    cout << "Enter filename: ";
    cin >> filename;
    cin.ignore();

    cout << "Enter data: ";
    cin.getline(data, 500);

    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd < 0) {
        cout << "Error opening file\n";
        return;
    }

    write(fd, data, strlen(data));
    write(fd, "\n", 1);
    close(fd);

    cout << "Data written successfully\n";
}

// ============================================
// 3. READ FILE
// ============================================
void readFile() {
    char filename[100], buffer[1024];
    cout << "Enter filename: ";
    cin >> filename;

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        cout << "Error opening file\n";
        return;
    }

    int bytes;
    while ((bytes = read(fd, buffer, 1024)) > 0) {
        write(1, buffer, bytes);
    }
    close(fd);
}

// ============================================
// 4. DELETE FILE
// ============================================
void deleteFile() {
    char filename[100];
    cout << "Enter filename: ";
    cin >> filename;

    if (unlink(filename) == -1) {
        cout << "Error deleting file\n";
        return;
    }
    cout << "File deleted successfully\n";
}

// ============================================
// 5. COPY FILE
// ============================================
void copyFile() {
    char src[100], dest[100], buffer[1024];

    cout << "Enter source file: ";
    cin >> src;
    cout << "Enter destination file: ";
    cin >> dest;

    int fd1 = open(src, O_RDONLY);
    int fd2 = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd1 < 0 || fd2 < 0) {
        cout << "Error copying file\n";
        return;
    }

    int bytes;
    while ((bytes = read(fd1, buffer, 1024)) > 0) {
        write(fd2, buffer, bytes);
    }

    close(fd1);
    close(fd2);
    cout << "File copied successfully\n";
}

// ============================================
// 6. SIMPLE BACKUP (NEW)
// ============================================
void simpleBackup() {
    char src[100], backupName[100], buffer[1024];

    cout << "Enter file to backup: ";
    cin >> src;

    cout << "Enter backup file name: ";
    cin >> backupName;

    mkdir("backup", 0755);

    char backupPath[200];
    sprintf(backupPath, "backup/%s", backupName);

    int fd1 = open(src, O_RDONLY);
    if (fd1 < 0) {
        cout << "Cannot open source file\n";
        return;
    }

    int fd2 = open(backupPath, O_CREAT | O_WRONLY, 0644);
    if (fd2 < 0) {
        cout << "Cannot create backup file\n";
        close(fd1);
        return;
    }

    int bytes;
    while ((bytes = read(fd1, buffer, 1024)) > 0) {
        write(fd2, buffer, bytes);
    }

    close(fd1);
    close(fd2);
    cout << "Backup created in backup folder\n";
}

// ============================================
// MAIN MENU
// ============================================
int main() {
    int choice;

    while (true) {
        cout << "\n==== FILE MANAGER ====\n";
        cout << "1. Create File\n";
        cout << "2. Write File\n";
        cout << "3. Read File\n";
        cout << "4. Delete File\n";
        cout << "5. Copy File\n";
        cout << "6. Backup File (Simple)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createFile(); break;
            case 2: writeFile(); break;
            case 3: readFile(); break;
            case 4: deleteFile(); break;
            case 5: copyFile(); break;
            case 6: simpleBackup(); break;
            case 7: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
