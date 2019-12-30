#include <winsock.h>
#include <MYSQL/mysql.h>

MYSQL * my_MySQL();
void add_app_MySQL(char *path_app, char *version_app, char *name, char *name_exe, MYSQL *connection);
void display_app_MySQL(MYSQL *connection);
