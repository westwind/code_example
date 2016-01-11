#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

CURL *curl_init_costum() {
    CURL *handler = NULL;

    handler = curl_easy_init();
    if (handler == NULL) {
        return NULL;
    }

    curl_easy_setopt(handler, CURLOPT_USERAGENT, "mozilla");
    curl_easy_setopt(handler, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(handler, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(handler, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(handler, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(handler, CURLOPT_CONNECTTIMEOUT, 10L);

    return handler;
}

size_t site_survey_download_file_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    FILE *p_file = (FILE *) userp;
    size_t realsize = size * nmemb;

    if (p_file) {
        fwrite((char *) contents, size, nmemb, p_file);
    }
    return realsize;
}

FILE *save_webpage_init(CURL *handler, char *filename) {
    FILE *p_file;

    p_file = fopen(filename, "w+");
    if (p_file == NULL) {
        return p_file;
    } else {
        curl_easy_setopt(handler, CURLOPT_WRITEFUNCTION, site_survey_download_file_callback);
        curl_easy_setopt(handler, CURLOPT_WRITEDATA, (void *) p_file);   
    }

}

void save_webpage_finish(FILE *p_file) {
    fclose(p_file);
}

long download_web_page(char *url, char *filename) {
    FILE *p_file = NULL;
    CURL *curl_handler = NULL;
    CURLcode result;

    curl_handler = curl_init_costum();
    if(curl_handler == NULL) {
        return -1;
    }
   
    curl_easy_setopt(curl_handler, CURLOPT_URL, url);

    p_file = save_webpage_init(curl_handler, filename);
    if (!p_file) {
        return -1;
    }
    result = curl_easy_perform(curl_handler);
    if (result != 0) {
        printf("can not get web\n");
        return -1;
    }
    
    save_webpage_finish(p_file);
    
    long retcode = 0;
    result = curl_easy_getinfo(curl_handler, CURLINFO_RESPONSE_CODE, &retcode);
    
    curl_easy_cleanup(curl_handler);
    return retcode;
}

void extract_domain(const char *line, char *dst) {
    char *s=NULL;
    char domain[20];
    memset(domain, 0, 20);

    char *domain_line = "<span class=\"domain tld\">";
    char *nonEngDomain = "xn--";
    if (s = strstr(line, nonEngDomain) ) {
        return;
    }
    if ( !(s = strstr(line, domain_line)) ) {
        return;
    } else {
        //<span class="domain tld"><a href="/domains/root/db/aaa.html">.aaa</a></span></td>
        sscanf(s, 
            "%*[^/]/%*[^/]/%*[^/]/%*[^/]/%[^.].html%*[^.].%*[^<]</a>",
            domain);
        memcpy(dst, domain, 20);
        return;
    }
}

void extract_type(const char *line, char *dst) {
    char *s = NULL;
    char type[50];
    memset(type, 0, 50);

    char *type_line = "<td>";

    if ( !(s = strstr(line, type_line)) ) {
        return;
    } else {
        // <td>generic</td>
        sscanf(s, 
            "<td>%[^<]</td>",
            type);
        memcpy(dst, type, 50);
        return;
    }
}

void parse_rootzone(const char *filename) {
    FILE *fp;
    char line[1024];
    int step_flag = 0;

    char domain[20];
    char type[50];
    memset(domain, 0, 20);
    memset(type, 0, 50);

    fp = fopen(filename, "r");
    
    printf("domain\t\ttype\n");
    while (fgets(line, 1024, fp) != NULL) {
        if (step_flag == 0) {
            extract_domain(line, domain);
            if (domain[0] != 0)
                step_flag = 1;
        } else if (step_flag == 1) {
            extract_type(line, type);
            if (type[0] != 0) {
                printf("%s\t\t%s\n",domain, type);
                memset(domain, 0, 20);
                memset(type, 0, 50);
                step_flag = 0;
            }
        }
    }
    fclose(fp);
}


int main(int argc, char *argv[]) {
    char *url="http://www.iana.org/domains/root/db";
    char *filename="/tmp/rootZone.db";
    int result;
    result = download_web_page(url, filename);
    printf("fetch web page: %d\n", result);

    parse_rootzone(filename);
}
