#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  #include <curl/curl.h>
     #include <openssl/md5.h>
#include<string>
#include<sstream>
using namespace std;
static size_t write_cb(char *ptr, size_t size, size_t nmemb, char *out)
{
	    size_t r;
	        r = size * nmemb;
	            strncat(out,ptr,r);
	                return(r);
}
static long int GetReturnCode(const char* pRet)// point to the buf size 2000
{
	if(pRet == NULL)
		return -1; 

	const char *pState = strstr(pRet, "<result>");
	if(pState != NULL)
	{   
		long int iRet = strtol(pState + sizeof("<result>"), NULL, 10);
		return iRet;
	}   

	return -1; 
}
static const char* GetRetInfo(const char* pRet)
{
    const char* pMsg;
    if(pRet == NULL)
        pMsg = "未知错误";

    static const char* sMsg[]= {"提交成功","账号无效","密码错误","msgid不唯一","存在无效手机号码",
        "手机号码个数超过最大限制","短信内容超过最大限制","扩展子号码无效","发送时间格式无效","请求来源地址无效",
        "内容包含敏感词","余额不足","订购关系无效","短信签名无效","无效的手机子码","产品不存在","号码个数小于最小限制",
        "接入方式错误","系统繁忙","消息格式错误"};


    long int iRet = GetReturnCode(pRet);
    if( iRet >= 0 && iRet < 16) 
        pMsg = sMsg[iRet];
    else if(iRet - 80 > 0 && iRet -80 < 4)
        pMsg = sMsg[iRet - 80];
    else 
        pMsg = "未知错误";

    return pMsg;
}




int main()
{
    char buf[2048];
    char* pBody ;
    std::stringstream ss;
    CURL *curl;
    CURLcode res;
    string url;

 //<?xml version='1.0' encoding='UTF-8'?><message><account>dh20891</account><password>bb43a2c4081bec02fca7b72f38e63021</password></message>";
   memset(buf,0,sizeof buf);
   curl = curl_easy_init();
    if(!curl)
    {
        return 0;
    }
   url = "http://3tong.net/http/sms/Submit";

    ss << "message=";
    ss << "<?xml version='1.0' encoding='UTF-8'?>";
    ss << "<message>";
    ss << "<account>"  << "uname" << "</account>";
    ss << "<password>" << "password" << "</password>";
   ss << "<msgid></msgid>";
   ss << "<phones>"   << "tel"    << "</phones>";
  
   char * p = curl_easy_escape(curl, "172.17.170.147的外网异常，已重置该接口，请密切关注。",0);
   ss << "<content>"  << p << "</content>";
   ss << "<sign>"     << "</sign>";
   ss << "<subcode>"  << "</subcode>";
   ss << "<sendtime>" << "</sendtime>";
    ss << "</message>" ;


    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);
    curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, ss.str().c_str());

    res = curl_easy_perform(curl);
    printf("%s\n", ss.str().c_str());
    if(CURLE_OK == res)
    {
		printf("%s",GetRetInfo(buf));

    }

  if(pBody)
    {
       // curl_free(pBody);
    }

    curl_easy_cleanup(curl);
    return 0;

}
