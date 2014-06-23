#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <WinInet.h>

#include "include/stdafx.h"

#include <boost/asio.hpp>
#include <conio.h>
#include <fstream>


    char buffer [9999999];

void Request()
{


        boost::asio::ip::tcp::iostream stream;
        stream.expires_from_now(boost::posix_time::seconds(60));
        stream.connect("www.mail.ru","http");
        stream << "GET / HTTP/1.1\r\n";
        stream << "Host mail.ru\r\n";
        stream << "User-Agent   Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/536.11 (KHTML, like Gecko) Chrome/20.0.1132.47 Safari/536.11\r\n";
        stream << "Accept   text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n" ;
        stream << "Accept-Encoding  gzip,deflate,sdch\r\n";
        stream << "Accept-Language  en-US,en;q=0.8\r\n";
        stream <<"Accept-Charset    ISO-8859-1,utf-8;q=0.7,*;q=0.3\r\n";
        stream << "Cookie   \r\n\r\n";

    /*stream << "POST https://auth.mail.ru/cgi-bin/auth HTTP/1.1\r\n";
    stream << "Host: auth.mail.ru\r\n";
    stream << "User-Agent: Mozilla/5.0 (Windows NT 6.2; WOW64; rv:13.0) Gecko/20100101 Firefox/13.0.1\r\n";
    stream << "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*///*;q=0.8\r\n";
    /*stream << "Accept-Language: ru-ru,ru;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
    stream << "Accept-Encoding: gzip, deflate\r\n";
    stream << "Connection: keep-alive\r\n";
    stream << "Referer: http://mail.ru/\r\n";
    stream << "X-MailRuSputnik: generic\r\n";
    stream << "Content-Type: application/x-www-form-urlencoded\r\n";
    stream << "Content-Length: 59\r\n";

    stream << "Domain=mail.ru&Login=(login)&Password=(password)&level=0\r\n"; */

        stream.flush();
        using namespace std ;
     // cout << stream.rdbuf();
        ofstream f("output.txt" /*| ios::bin*/);
        f << stream.rdbuf();
        f.close();
        system("pause");
        return 0 ;

}




