#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int init_directory()
{
    struct stat st = {0};

    if (stat("/var/file_saver", &st) == -1) {
        if (mkdir("/var/file_saver", 0700) == -1)
        {
            fprintf(stderr ,"%s", strerror(errno));
        }
    }
}



void handle_files(char *f)
{
    char *token;
    FILE *file;
    while ((token = strsep(&f, ",")))
    {
        if ((f = fopen((const char*)token, "r")) == NULL)
        {
            fprintf(stderr ,"%s", strerror(errno));
            continue;
        }

        time_t t = time(NULL);
        char *new_name = ;
        FILE *copy = open( "w")
        while (fputs(/var/file_saver))

    }

}

void write_string(int argc, char *argv[])
{
}

void create_new_session(char *s)
{}

void show_line(int l)
{

}

void check_opt_number(int nb)
{
    if (nb > 1)
    {
        fprintf(stderr, "Only one option is required\n");
        exit(EXIT_FAILURE);
    }

}

int main(int argc, char *argv[])
{
    int opt;
    extern char * optarg; 
    enum {STRING_MODE, FILE_MODE, SHOW_LINE_MODE, FLUSH_MODE} mode = STRING_MODE;
    int nb_opt = 0;
    char *files;
    char *session;
    int number_line;
    while ((opt = getopt(argc, argv, "f:s:n:")) != -1) {
        switch (opt) {
        case 'f': 
            {
                check_opt_number(++nb_opt);
                mode = FILE_MODE;
                files = optarg;
                break;
            }
        case 's': 
            {
                check_opt_number(++nb_opt);
                mode = SHOW_LINE_MODE;
                number_line = atoi(optarg);
                break;
            }
        case 'n':
            {
                check_opt_number(++nb_opt);
                mode = FLUSH_MODE;
                session = optarg;
                break;
            }
        default:
            fprintf(stderr, "Usage: %s [-fsn] [file...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    init_directory();
    if (mode == FILE_MODE)
        handle_files(files);
    else if (mode == SHOW_LINE_MODE)
        show_line(number_line);
    else if (mode == FLUSH_MODE)
        create_new_session(session);
    else if (mode == STRING_MODE)
        write_string(argc, argv);


}
