#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <curl/curl.h>
#include<string>
#include<sstream>
#include <json/json.h>
Json::Value root;
Json::Reader reader;
using namespace std;
static size_t write_cb(char *ptr, size_t size, size_t nmemb, char *out)
{
	    size_t r;
        r = size * nmemb;
        strncat(out,ptr,r);
        return(r);
}

int main()
{
    char buf[2048];
    char* pBody ;
    std::stringstream ss;
    CURL *curl;
    CURLcode res;
    string url = "http://api.jiankongbao.com/site/task/";
    url += "678470/";
    url += "report";
    url += "/20140306.json";

   memset(buf,0,sizeof buf);
   curl = curl_easy_init();
    if(!curl)
    {
        return 0;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_setopt(curl, CURLOPT_USERPWD, "644104436@qq.com:ucloud.cn");
    curl_easy_setopt(curl, CURLOPT_HTTPGET, true);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);
    //curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, ss.str().c_str());

    res = curl_easy_perform(curl);

	printf("%s\n",buf);

  if(pBody)
    {
       // curl_free(pBody);
    }

  //bool parsingSuccess = reader.parse(buf,root);
  //if(parsingSuccess)
  //{
  //	  for(int i = 0; i< root["tasks"].size(); ++i)
  //    {
  //    	  printf("%s\n", root["tasks"]["task"][i]["task_id"].asString().c_str());
  //    }

  //}

    curl_easy_cleanup(curl);
    return 0;

}
