#include <stdlib.h>
#include <string.h> 
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

struct Node {
  char value;
  struct Node* next;
  struct Node* prev;
};

struct DoubleLinkedList {
  size_t size;

  struct Node* first;
  struct Node* last;
};

typedef struct {
  char* title;
  struct DoubleLinkedList* content;
} File_t;


File_t* create_file(char* title) {
  File_t* file = calloc(1, sizeof(File_t));

  if(file) {
    file->title = title;
    file->content = malloc(sizeof(struct DoubleLinkedList));
  }

  return file;
}

void list_files() {
  // creamos un proceso hijo con fork
  int children_pid = fork();

  if(children_pid < 0) {
    perror("error listing existing files");
    return;
  }

  // codigo ejecutado por el hijo
  if(children_pid == 0) {
    // listamos el contenido de la carpeta ./tmp con exec
    // int execl(const char *path, const char *arg, ...);

    char current_working_directory[256];

    if(getcwd(current_working_directory,  sizeof(current_working_directory)) == NULL) {
      perror("error getting the current working directory, try again");
      exit(1);
    }

    // printf("Current working directory: %s\n", current_working_directory);

    char files_path[512];
    snprintf(files_path, sizeof(files_path), "%s/tmp", current_working_directory);

    // printf("Files path: %s\n", files_path);

    execlp("ls", "ls", files_path, (char*)NULL);
    puts("\n");

    perror("execl failed");
    exit(1); 
  
  // codigo ejecutado por el padre
  } else {
    // espera a que el proceso hijo termine
    int status;
    waitpid(children_pid, &status, 0);
  }
}

int main() {
  list_files();
}