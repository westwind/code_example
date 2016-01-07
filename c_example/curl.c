#include <stdio.h>
#include <curl/curl.h>

static size_t site_survey_download_file_callback(void *contents, size_t size, size_t nmemb, void *userp){
    FILE *p_file = (FILE *) userp;
    size_t realsize = size * nmemb;

    if (p_file) {
        fwrite((char *) contents, size, nmemb, p_file);
    }

    return realsize;
}

int main(int argc, char *argv[]) {
    char *url = "http://www.speedtest.net/speedtest-servers-static.php";
    // char *url = "http://www.speedtest.net/speedtest-config.php";
    char *filename = "/tmp/curl";
    FILE *p_file = NULL;

    CURL *curl_handler = NULL;
    CURLcode result;
 
    curl_handler = curl_easy_init();
    if (curl_handler == NULL) {
        printf("curl_easy_init() error\n");
        return 1;
    }

    if (filename) {
        p_file = fopen(filename, "w+");
        if (p_file == NULL) {
            return 1;
        }
    }

    curl_easy_setopt(curl_handler, CURLOPT_URL, url);
    curl_easy_setopt(curl_handler, CURLOPT_WRITEFUNCTION, site_survey_download_file_callback);
    curl_easy_setopt(curl_handler, CURLOPT_WRITEDATA, (void *) p_file);
    curl_easy_setopt(curl_handler, CURLOPT_USERAGENT, "Mozilla");
    curl_easy_setopt(curl_handler, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(curl_handler, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handler, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl_handler, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl_handler, CURLOPT_CONNECTTIMEOUT, 10L);

    result = curl_easy_perform(curl_handler);

    if (result != CURLE_OK) {
        printf("can not get web\n");
    }
    long retcode = 0;
    result = curl_easy_getinfo(curl_handler, CURLINFO_RESPONSE_CODE , &retcode); 
    printf("%ld\n",retcode);
    curl_easy_cleanup(curl_handler);
}
