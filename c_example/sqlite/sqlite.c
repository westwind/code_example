#include <stdio.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;

    printf("argc = %d\n", argc);
    for (i=0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char *filename = "/home/agg2567/sqltest.db";
    sqlite3 *db = NULL;
    int result;
    char *sql = "select * from APP where MAC='90:2B:34:5D:82:DE' and EPOCH=2452768572";
    //char *sql = "select * from APP where MAC='90:2B:34:5D:82:DE' and EPOCH=1452768572";
    char *zErrMsg = 0;

    result = sqlite3_open(filename, &db);
    printf("open sql db: 1\n");
    if (result != 0) {
        printf("can't open database: %s\n", filename);
        return;
    }

    result = sqlite3_open(filename, &db);
    printf("open sql db: 2\n");
    if (result != 0) {
        printf("can't open database: %s\n", filename);
        return;
    }

    if (db != NULL) {
        result = sqlite3_exec(db, sql, callback, NULL, &zErrMsg);
        printf("result = %d\n", result);
        printf("zerrmsg = %s\n", zErrMsg);
    }

}
