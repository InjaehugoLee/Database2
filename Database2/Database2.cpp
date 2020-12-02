// dbstudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>

#include "mysql.h"
#include "World.h"

using namespace std;
#define FIELDS_COUNTRY "Code, Name, Continent,Region, SurfaceArea, IndepYear, Population, LifeExpectancy, GNP, GNPOld, LocalName, GovernmentForm, HeadOfState, Capital, Code2"
#define FIELDS_CITY "ID, Name, CountryCode, District, Population"
#define FIELDS_COUNTRYLANGUAGE "CountryCode, Language, IsOfficial, Percentage"

void printData(const vector <World*>& vec)
{
    for (auto pc : vec)
    {
        pc->print();
        printf("===============================\n");
    }
}

int main()
{
   
    // mysql db를 사용하기 위한 변수 선언
    MYSQL mysql;

    // 변수 초기화
    if (mysql_init(&mysql) == NULL)
    {
        printf("Fail to initialize mysql\n");
        return 1;
    }

    // 데이터베이스 연결
    if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)
    {
        printf("%s\n", mysql_error(&mysql));
        return 1;
    }

    vector <World*> vec;
    // 질의 전달
    char sql[9999];

    //==========================================================
    //    Country
    //==========================================================
    sprintf_s(sql, "select %s from country", FIELDS_COUNTRY);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // 질의 결과 저장
    MYSQL_RES* res = mysql_store_result(&mysql); //위에랑 달리 res 라는 변수에 넣었으므로 오류 발생시 밑의 내용과 같이 코드해야 함.
    if (res == NULL) // if(!res) 같은 표현
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // 질의 결과 필드 수
    int fieldCount = mysql_num_fields(res);

    // 질의 결과에서 레코드(row)별로 하나씩 담을 변수
    MYSQL_ROW row;

    // 모든 레코드를 다 읽을 때까지 반복 수행
    while (row = mysql_fetch_row(res))
    {
        Country* pc = new Country;
        int idx = 0;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]); idx++;
        if (row[idx])   pc->values.push_back(row[idx]);

        vec.push_back(pc);
    }
    // 질의 결과 메모리 해제
    mysql_free_result(res);

    //==========================================================
    //    City
    //==========================================================
    sprintf_s(sql, "select %s from city", FIELDS_CITY);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // 질의 결과 저장
    res = mysql_store_result(&mysql); //위에랑 달리 res 라는 변수에 넣었으므로 오류 발생시 밑의 내용과 같이 코드해야 함.
    if (res == NULL) // if(!res) 같은 표현
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // 질의 결과 필드 수
    fieldCount = mysql_num_fields(res);

    while (row = mysql_fetch_row(res))
    {
        City* pc = new City;
        int idx = 0;
        if (row[idx]) pc->values.push_back(row[idx]); idx++;
        if (row[idx]) pc->values.push_back(row[idx]); idx++;
        if (row[idx]) pc->values.push_back(row[idx]); idx++;
        if (row[idx]) pc->values.push_back(row[idx]); idx++;
        if (row[idx]) pc->values.push_back(row[idx]); 

        vec.push_back(pc);
    }

    // 질의 결과 메모리 해제
    mysql_free_result(res);

    //==========================================================
    //    CountryLanguage
    //==========================================================
    sprintf_s(sql, "select %s from countrylanguage", FIELDS_COUNTRYLANGUAGE);
    if (mysql_query(&mysql, sql) != 0)
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // 질의 결과 저장
    res = mysql_store_result(&mysql); //위에랑 달리 res 라는 변수에 넣었으므로 오류 발생시 밑의 내용과 같이 코드해야 함.
    if (res == NULL) // if(!res) 같은 표현
    {
        printf("%s\n", mysql_error(&mysql));
        mysql_close(&mysql);
        return 1;
    }

    // 질의 결과 필드 수
    fieldCount = mysql_num_fields(res);

    while (row = mysql_fetch_row(res))
    {
        CountryLang* pc = new CountryLang;
        int idx = 0;
        if (row[idx]) pc->values.push_back(row[idx]); idx++;
        if (row[idx]) pc->values.push_back(row[idx]); idx++;
        if (row[idx]) pc->values.push_back(row[idx]); idx++;
        if (row[idx]) pc->values.push_back(row[idx]); 

        vec.push_back(pc);
    }
    // 질의 결과 메모리 해제
    mysql_free_result(res);

    // 데이터베이스 닫기
    mysql_close(&mysql);

    // 객체를 출력한다
    printData(vec);

  

    // 객체들을 메모리에서 삭제한다
    // 새로운 버전
    for (auto pc : vec)
        delete pc;

    // 기존 버전
    //for (int i = 0; i < vec.size(); i++)
    //    delete vec[i];

    vec.clear();
}