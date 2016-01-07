#include <stdio.h>
#include <string.h>

int extract_xml_value(const char *data, char *result, const char *search_str) {
    char *s, *e;
    s = strstr(data, search_str);
    if (!s) 
        return -1;
    s = s + strlen(search_str) + 1;
    e = strchr(s, '"');
    if(!e)
        return -1;
    strncpy(result, s, e - s);
    result[e - s] = '\0';
    return 0;
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *fp;
    char line[1024];
    char lat[16], lon[16], id[16];
    char city[128], country[128], sponsor[128];
    char url[256];
    int count =0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }

    while(fgets(line, 1024, fp) != NULL) {
        if (strncmp(line, "<server", 7) != 0)
            continue;
        if (extract_xml_value(line, url, " url=") != 0)
            continue;
        if (extract_xml_value(line, lat, " lat=") != 0)
            continue;
        if (extract_xml_value(line, lon, " lon=") != 0)
            continue;
        if (extract_xml_value(line, city, " name=") != 0)
            continue;
        if (extract_xml_value(line, country, " country=") != 0)
            continue;
        if (extract_xml_value(line, sponsor, " sponsor=") != 0)
            continue;
        if (extract_xml_value(line, id, " id=") != 0)
            continue;
        printf("server:\n\turl: %s, lat: %s, lon: %s, country: %s, city: %s, sponsor: %s, id: %s\n",
            url, lat, lon, country, city, sponsor, id);
        count ++;
    }
    printf("Number of server: %d\n", count);
}
