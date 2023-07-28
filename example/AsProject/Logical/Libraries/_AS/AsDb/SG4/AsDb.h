/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASDB_
#define _ASDB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define DB_ENCODING_UTF_8 "UTF-8"
 #define DB_ENCODING_ISO_8859_1 "ISO-8859-1"
 #define dbERR_UNSUPPORTED_ENCODING 34945U
 #define dbERR_NOT_AVAILABLE 34944U
 #define dbERR_NULLPOINTER 34943U
 #define dbERR_INVALID_DATATYPE 34942U
 #define dbERR_SQL_EXECUTE_REQUIRED 34941U
 #define dbERR_INVALID_SQL_STATEMENT 34940U
 #define dbERR_INVALID_DATABASE_NAME 34939U
 #define dbERR_INVALID_PASSWORD 34938U
 #define dbERR_INVALID_USERNAME 34937U
 #define dbERR_INVALID_SERVERNAME 34936U
 #define dbERR_BUFFER_SIZE 34935U
 #define dbERR_UNSUPPORTED_DATABASE 34934U
 #define dbERR_INVALID_COLUMN 34933U
 #define dbERR_INVALID_HANDLE 34932U
 #define dbERR_DATABASE 34931U
 #define dbERR_MEMORY 34930U
 #define DB_IT_SQL_XOPEN_CLI_YEAR 10000U
 #define DB_IT_SQL_USER_NAME 47U
 #define DB_IT_SQL_UNION 96U
 #define DB_IT_SQL_TXN_ISOLATION_OPTION 72U
 #define DB_IT_SQL_TXN_CAPABLE 46U
 #define DB_IT_SQL_TIMEDATE_FUNCTIONS 52U
 #define DB_IT_SQL_TIMEDATE_DIFF_INTERVAL 110U
 #define DB_IT_SQL_TIMEDATE_ADD_INTERVALS 109U
 #define DB_IT_SQL_TABLE_TERM 45U
 #define DB_IT_SQL_SYSTEM_FUNCTIONS 51U
 #define DB_IT_SQL_SUBQUERIES 95U
 #define DB_IT_SQL_STRING_FUNCTIONS 50U
 #define DB_IT_SQL_STATIC_SENSITIVITY 83U
 #define DB_IT_SQL_STATIC_CURSOR_ATTR2 168U
 #define DB_IT_SQL_STATIC_CURSOR_ATTR1 167U
 #define DB_IT_SQL_STD_CLI_CONFORMANCE 166U
 #define DB_IT_SQL_SQL92_VALUE_EXPR 165U
 #define DB_IT_SQL_SQL92_STRING_FUNCTIONS 164U
 #define DB_IT_SQL_SQL92_ROW_VALUE_CTOR 163U
 #define DB_IT_SQL_SQL92_REVOKE 162U
 #define DB_IT_SQL_SQL92_REL_JOIN_OPS 161U
 #define DB_IT_SQL_SQL92_PREDICATES 160U
 #define DB_IT_SQL_SQL92_NUM_VALUE_FUNCS 159U
 #define DB_IT_SQL_SQL92_GRANT 158U
 #define DB_IT_SQL_SQL92_FK_UPDATE_RULE 157U
 #define DB_IT_SQL_SQL92_FK_DELETE_RULE 156U
 #define DB_IT_SQL_SQL92_DATETIME_FUNCS 155U
 #define DB_IT_SQL_SQL_CONFORMANCE 118U
 #define DB_IT_SQL_SPECIAL_CHARACTERS 94U
 #define DB_IT_SQL_SERVER_NAME 13U
 #define DB_IT_SQL_SEARCH_PATTERN_ESCAPE 14U
 #define DB_IT_SQL_SCROLL_OPTIONS 44U
 #define DB_IT_SQL_SCROLL_CONCURRENCY 43U
 #define DB_IT_SQL_SCHEMA_USAGE 91U
 #define DB_IT_SQL_SCHEMA_TERM 39U
 #define DB_IT_SQL_ROW_UPDATES 11U
 #define DB_IT_SQL_QUOTED_IDENTIFIER_CASE 93U
 #define DB_IT_SQL_PROCEDURES 21U
 #define DB_IT_SQL_PROCEDURE_TERM 40U
 #define DB_IT_SQL_POSITIONED_STATEMENTS 80U
 #define DB_IT_SQL_POS_OPERATIONS 79U
 #define DB_IT_SQL_PARAM_ARRAY_SELECTS 154U
 #define DB_IT_SQL_PARAM_ARRAY_ROW_COUNTS 153U
 #define DB_IT_SQL_OUTER_JOINS 38U
 #define DB_IT_SQL_ORDER_BY_COLS_IN_SEL 90U
 #define DB_IT_SQL_OJ_CAPABILITIES 115U
 #define DB_IT_SQL_ODBC_VER 10U
 #define DB_IT_SQL_ODBC_SQL_CONFORMANCE 15U
 #define DB_IT_SQL_ODBC_SAG_CLI_CONFORM 12U
 #define DB_IT_SQL_ODBC_IFC_CONFORMANCE 152U
 #define DB_IT_SQL_ODBC_API_CONFORMANCE 9U
 #define DB_IT_SQL_NUMERIC_FUNCTIONS 49U
 #define DB_IT_SQL_NULL_COLLATION 85U
 #define DB_IT_SQL_NON_NULLABLE_COLUMNS 75U
 #define DB_IT_SQL_NEED_LONG_DATA_LEN 111U
 #define DB_IT_SQL_MULTIPLE_ACTIVE_TXN 37U
 #define DB_IT_SQL_MULT_RESULT_SETS 36U
 #define DB_IT_SQL_MAX_USER_NAME_LEN 107U
 #define DB_IT_SQL_MAX_TABLES_IN_SELECT 106U
 #define DB_IT_SQL_MAX_TABLE_NAME_LEN 35U
 #define DB_IT_SQL_MAX_STATEMENT_LEN 105U
 #define DB_IT_SQL_MAX_SCHEMA_NAME_LEN 32U
 #define DB_IT_SQL_MAX_ROW_SIZE_INCL_LONG 103U
 #define DB_IT_SQL_MAX_ROW_SIZE 104U
 #define DB_IT_SQL_MAX_PROCEDURE_NAME_LEN 33U
 #define DB_IT_SQL_MAX_INDEX_SIZE 102U
 #define DB_IT_SQL_MAX_IDENTIFIER_LEN 10005U
 #define DB_IT_SQL_MAX_DRIVER_CONNECTIONS 0U
 #define DB_IT_SQL_MAX_CURSOR_NAME_LEN 31U
 #define DB_IT_SQL_MAX_CONCUR_ACTIVITIES 1U
 #define DB_IT_SQL_MAX_COLUMNS_IN_TABLE 101U
 #define DB_IT_SQL_MAX_COLUMNS_IN_SELECT 100U
 #define DB_IT_SQL_MAX_COLS_IN_ORDER_BY 99U
 #define DB_IT_SQL_MAX_COLUMNS_IN_INDEX 98U
 #define DB_IT_SQL_MAX_COLS_IN_GROUP_BY 97U
 #define DB_IT_SQL_MAX_COLUMN_NAME_LEN 30U
 #define DB_IT_SQL_MAX_CHAR_LITERAL_LEN 108U
 #define DB_IT_SQL_MAX_CATALOG_NAME_LEN 34U
 #define DB_IT_SQL_MAX_BINARY_LITERAL_LEN 112U
 #define DB_IT_SQL_MAX_ASYNC_CONCUR_STMT 10022U
 #define DB_IT_SQL_LOCK_TYPES 78U
 #define DB_IT_SQL_LIKE_ESCAPE_CLAUSE 113U
 #define DB_IT_SQL_KEYWORDS 89U
 #define DB_IT_SQL_KEYSET_CURSOR_ATTR2 151U
 #define DB_IT_SQL_KEYSET_CURSOR_ATTR1 150U
 #define DB_IT_SQL_INTEGRITY 73U
 #define DB_IT_SQL_INSERT_STATEMENT 172U
 #define DB_IT_SQL_INFO_SCHEMA_VIEWS 149U
 #define DB_IT_SQL_INDEX_KEYWORDS 148U
 #define DB_IT_SQL_IDENTIFIER_QUOTE_CHAR 29U
 #define DB_IT_SQL_IDENTIFIER_CASE 28U
 #define DB_IT_SQL_GROUP_BY 88U
 #define DB_IT_SQL_GETDATA_EXTENSIONS 81U
 #define DB_IT_SQL_FORW_ONLY_CURSOR_ATTR2 147U
 #define DB_IT_SQL_FORW_ONLY_CURSOR_ATTR1 146U
 #define DB_IT_SQL_FILE_USAGE 84U
 #define DB_IT_SQL_FETCH_DIRECTION 8U
 #define DB_IT_SQL_EXPRESSIONS_IN_ORDERBY 27U
 #define DB_IT_SQL_DYNAMIC_CURSOR_ATTR2 145U
 #define DB_IT_SQL_DYNAMIC_CURSOR_ATTR1 144U
 #define DB_IT_SQL_DROP_VIEW 143U
 #define DB_IT_SQL_DROP_TRANSLATION 142U
 #define DB_IT_SQL_DROP_TABLE 141U
 #define DB_IT_SQL_DROP_SCHEMA 140U
 #define DB_IT_SQL_DROP_DOMAIN 139U
 #define DB_IT_SQL_DROP_COLLATION 138U
 #define DB_IT_SQL_DROP_CHARACTER_SET 137U
 #define DB_IT_SQL_DROP_ASSERTION 136U
 #define DB_IT_SQL_DRIVER_VER 7U
 #define DB_IT_SQL_DRIVER_ODBC_VER 77U
 #define DB_IT_SQL_DRIVER_NAME 6U
 #define DB_IT_SQL_DRIVER_HSTMT 5U
 #define DB_IT_SQL_DRIVER_HENV 4U
 #define DB_IT_SQL_DRIVER_HDBC 3U
 #define DB_IT_SQL_DESCRIBE_PARAMETER 10002U
 #define DB_IT_SQL_DEFAULT_TXN_ISOLATION 26U
 #define DB_IT_SQL_DDL_INDEX 170U
 #define DB_IT_SQL_DBMS_VER 18U
 #define DB_IT_SQL_DBMS_NAME 17U
 #define DB_IT_SQL_DATETIME_LITERALS 119U
 #define DB_IT_SQL_DATABASE_NAME 16U
 #define DB_IT_SQL_DATA_SOURCE_READ_ONLY 25U
 #define DB_IT_SQL_DATA_SOURCE_NAME 2U
 #define DB_IT_SQL_CURSOR_SENSITIVITY 10001U
 #define DB_IT_SQL_CURSOR_ROLLBACK_BEHAV 24U
 #define DB_IT_SQL_CURSOR_COMMIT_BEHAVIOR 23U
 #define DB_IT_SQL_CREATE_VIEW 134U
 #define DB_IT_SQL_CREATE_TRANSLATION 133U
 #define DB_IT_SQL_CREATE_TABLE 132U
 #define DB_IT_SQL_CREATE_SCHEMA 131U
 #define DB_IT_SQL_CREATE_DOMAIN 130U
 #define DB_IT_SQL_CREATE_COLLATION 129U
 #define DB_IT_SQL_CREATE_CHARACTER_SET 128U
 #define DB_IT_SQL_CREATE_ASSERTION 127U
 #define DB_IT_SQL_CORRELATION_NAME 74U
 #define DB_IT_SQL_CONVERT_WVARCHAR 126U
 #define DB_IT_SQL_CONVERT_WLONGVARCHAR 125U
 #define DB_IT_SQL_CONVERT_WCHAR 122U
 #define DB_IT_SQL_CONVERT_VARCHAR 70U
 #define DB_IT_SQL_CONVERT_VARBINARY 69U
 #define DB_IT_SQL_CONVERT_TINYINT 68U
 #define DB_IT_SQL_CONVERT_TIMESTAMP 67U
 #define DB_IT_SQL_CONVERT_SMALLINT 65U
 #define DB_IT_SQL_CONVERT_REAL 64U
 #define DB_IT_SQL_CONVERT_NUMERIC 63U
 #define DB_IT_SQL_CONVERT_LONGVARCHAR 62U
 #define DB_IT_SQL_CONVERT_LONGVARBINARY 71U
 #define DB_IT_SQL_CONVERT_INTEGER 61U
 #define DB_IT_SQL_CONVERT_FUNCTIONS 48U
 #define DB_IT_SQL_CONVERT_FLOAT 60U
 #define DB_IT_SQL_CONVERT_DECIMAL 58U
 #define DB_IT_SQL_CONVERT_CHAR 56U
 #define DB_IT_SQL_CONVERT_BIT 55U
 #define DB_IT_SQL_CONVERT_BINARY 54U
 #define DB_IT_SQL_CONCAT_NULL_BEHAVIOR 22U
 #define DB_IT_SQL_COLUMN_ALIAS 87U
 #define DB_IT_SQL_CATALOG_USAGE 92U
 #define DB_IT_SQL_CATALOG_TERM 42U
 #define DB_IT_SQL_CATALOG_NAME_SEPARATOR 41U
 #define DB_IT_SQL_CATALOG_NAME 10003U
 #define DB_IT_SQL_CATALOG_LOCATION 114U
 #define DB_IT_SQL_BOOKMARK_PERSISTENCE 82U
 #define DB_IT_SQL_BATCH_SUPPORT 121U
 #define DB_IT_SQL_BATCH_ROW_COUNT 120U
 #define DB_IT_SQL_ASYNC_MODE 10021U
 #define DB_IT_SQL_ALTER_TABLE 86U
 #define DB_IT_SQL_ALTER_DOMAIN 117U
 #define DB_IT_SQL_AGGREGATE_FUNCTIONS 169U
 #define DB_IT_SQL_ACTIVE_ENVIRONMENTS 116U
 #define DB_IT_SQL_ACCESSIBLE_TABLES 19U
 #define DB_SQL_GUID (-11)
 #define DB_SQL_TIMESTAMP 11
 #define DB_SQL_TIME 10
 #define DB_SQL_DATE 9
 #define DB_SQL_DOUBLE 8
 #define DB_SQL_REAL 7
 #define DB_SQL_TINYINT (-6)
 #define DB_SQL_SMALLINT 5
 #define DB_SQL_INTEGER 4
 #define DB_SQL_BIGINT (-25)
 #define DB_SQL_DECIMAL 3
 #define DB_SQL_NUMERIC 2
 #define DB_SQL_CHAR 1
 #define DB_SQL_NO_DATA 100
 #define DB_SQL_INVALID_HANDLE (-2)
 #define DB_SQL_ERROR (-1)
 #define DB_DEFAULT_PORT 5000U
 #define DB_SYSTEM_MS_SQL 2U
 #define DB_SYSTEM_SYBASE 1U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST plcstring DB_ENCODING_UTF_8[13];
 _GLOBAL_CONST plcstring DB_ENCODING_ISO_8859_1[13];
 _GLOBAL_CONST unsigned short dbERR_UNSUPPORTED_ENCODING;
 _GLOBAL_CONST unsigned short dbERR_NOT_AVAILABLE;
 _GLOBAL_CONST unsigned short dbERR_NULLPOINTER;
 _GLOBAL_CONST unsigned short dbERR_INVALID_DATATYPE;
 _GLOBAL_CONST unsigned short dbERR_SQL_EXECUTE_REQUIRED;
 _GLOBAL_CONST unsigned short dbERR_INVALID_SQL_STATEMENT;
 _GLOBAL_CONST unsigned short dbERR_INVALID_DATABASE_NAME;
 _GLOBAL_CONST unsigned short dbERR_INVALID_PASSWORD;
 _GLOBAL_CONST unsigned short dbERR_INVALID_USERNAME;
 _GLOBAL_CONST unsigned short dbERR_INVALID_SERVERNAME;
 _GLOBAL_CONST unsigned short dbERR_BUFFER_SIZE;
 _GLOBAL_CONST unsigned short dbERR_UNSUPPORTED_DATABASE;
 _GLOBAL_CONST unsigned short dbERR_INVALID_COLUMN;
 _GLOBAL_CONST unsigned short dbERR_INVALID_HANDLE;
 _GLOBAL_CONST unsigned short dbERR_DATABASE;
 _GLOBAL_CONST unsigned short dbERR_MEMORY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_XOPEN_CLI_YEAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_USER_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_UNION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_TXN_ISOLATION_OPTION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_TXN_CAPABLE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_TIMEDATE_FUNCTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_TIMEDATE_DIFF_INTERVAL;
 _GLOBAL_CONST unsigned short DB_IT_SQL_TIMEDATE_ADD_INTERVALS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_TABLE_TERM;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SYSTEM_FUNCTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SUBQUERIES;
 _GLOBAL_CONST unsigned short DB_IT_SQL_STRING_FUNCTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_STATIC_SENSITIVITY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_STATIC_CURSOR_ATTR2;
 _GLOBAL_CONST unsigned short DB_IT_SQL_STATIC_CURSOR_ATTR1;
 _GLOBAL_CONST unsigned short DB_IT_SQL_STD_CLI_CONFORMANCE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_VALUE_EXPR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_STRING_FUNCTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_ROW_VALUE_CTOR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_REVOKE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_REL_JOIN_OPS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_PREDICATES;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_NUM_VALUE_FUNCS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_GRANT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_FK_UPDATE_RULE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_FK_DELETE_RULE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL92_DATETIME_FUNCS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SQL_CONFORMANCE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SPECIAL_CHARACTERS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SERVER_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SEARCH_PATTERN_ESCAPE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SCROLL_OPTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SCROLL_CONCURRENCY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SCHEMA_USAGE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_SCHEMA_TERM;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ROW_UPDATES;
 _GLOBAL_CONST unsigned short DB_IT_SQL_QUOTED_IDENTIFIER_CASE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_PROCEDURES;
 _GLOBAL_CONST unsigned short DB_IT_SQL_PROCEDURE_TERM;
 _GLOBAL_CONST unsigned short DB_IT_SQL_POSITIONED_STATEMENTS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_POS_OPERATIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_PARAM_ARRAY_SELECTS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_PARAM_ARRAY_ROW_COUNTS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_OUTER_JOINS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ORDER_BY_COLS_IN_SEL;
 _GLOBAL_CONST unsigned short DB_IT_SQL_OJ_CAPABILITIES;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ODBC_VER;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ODBC_SQL_CONFORMANCE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ODBC_SAG_CLI_CONFORM;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ODBC_IFC_CONFORMANCE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ODBC_API_CONFORMANCE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_NUMERIC_FUNCTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_NULL_COLLATION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_NON_NULLABLE_COLUMNS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_NEED_LONG_DATA_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MULTIPLE_ACTIVE_TXN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MULT_RESULT_SETS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_USER_NAME_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_TABLES_IN_SELECT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_TABLE_NAME_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_STATEMENT_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_SCHEMA_NAME_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_ROW_SIZE_INCL_LONG;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_ROW_SIZE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_PROCEDURE_NAME_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_INDEX_SIZE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_IDENTIFIER_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_DRIVER_CONNECTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_CURSOR_NAME_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_CONCUR_ACTIVITIES;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_COLUMNS_IN_TABLE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_COLUMNS_IN_SELECT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_COLS_IN_ORDER_BY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_COLUMNS_IN_INDEX;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_COLS_IN_GROUP_BY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_COLUMN_NAME_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_CHAR_LITERAL_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_CATALOG_NAME_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_BINARY_LITERAL_LEN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_MAX_ASYNC_CONCUR_STMT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_LOCK_TYPES;
 _GLOBAL_CONST unsigned short DB_IT_SQL_LIKE_ESCAPE_CLAUSE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_KEYWORDS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_KEYSET_CURSOR_ATTR2;
 _GLOBAL_CONST unsigned short DB_IT_SQL_KEYSET_CURSOR_ATTR1;
 _GLOBAL_CONST unsigned short DB_IT_SQL_INTEGRITY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_INSERT_STATEMENT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_INFO_SCHEMA_VIEWS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_INDEX_KEYWORDS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_IDENTIFIER_QUOTE_CHAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_IDENTIFIER_CASE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_GROUP_BY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_GETDATA_EXTENSIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_FORW_ONLY_CURSOR_ATTR2;
 _GLOBAL_CONST unsigned short DB_IT_SQL_FORW_ONLY_CURSOR_ATTR1;
 _GLOBAL_CONST unsigned short DB_IT_SQL_FILE_USAGE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_FETCH_DIRECTION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_EXPRESSIONS_IN_ORDERBY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DYNAMIC_CURSOR_ATTR2;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DYNAMIC_CURSOR_ATTR1;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_VIEW;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_TRANSLATION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_TABLE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_SCHEMA;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_DOMAIN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_COLLATION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_CHARACTER_SET;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DROP_ASSERTION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DRIVER_VER;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DRIVER_ODBC_VER;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DRIVER_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DRIVER_HSTMT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DRIVER_HENV;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DRIVER_HDBC;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DESCRIBE_PARAMETER;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DEFAULT_TXN_ISOLATION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DDL_INDEX;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DBMS_VER;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DBMS_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DATETIME_LITERALS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DATABASE_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DATA_SOURCE_READ_ONLY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_DATA_SOURCE_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CURSOR_SENSITIVITY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CURSOR_ROLLBACK_BEHAV;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CURSOR_COMMIT_BEHAVIOR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_VIEW;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_TRANSLATION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_TABLE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_SCHEMA;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_DOMAIN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_COLLATION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_CHARACTER_SET;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CREATE_ASSERTION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CORRELATION_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_WVARCHAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_WLONGVARCHAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_WCHAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_VARCHAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_VARBINARY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_TINYINT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_TIMESTAMP;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_SMALLINT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_REAL;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_NUMERIC;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_LONGVARCHAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_LONGVARBINARY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_INTEGER;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_FUNCTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_FLOAT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_DECIMAL;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_CHAR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_BIT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONVERT_BINARY;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CONCAT_NULL_BEHAVIOR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_COLUMN_ALIAS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CATALOG_USAGE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CATALOG_TERM;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CATALOG_NAME_SEPARATOR;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CATALOG_NAME;
 _GLOBAL_CONST unsigned short DB_IT_SQL_CATALOG_LOCATION;
 _GLOBAL_CONST unsigned short DB_IT_SQL_BOOKMARK_PERSISTENCE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_BATCH_SUPPORT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_BATCH_ROW_COUNT;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ASYNC_MODE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ALTER_TABLE;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ALTER_DOMAIN;
 _GLOBAL_CONST unsigned short DB_IT_SQL_AGGREGATE_FUNCTIONS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ACTIVE_ENVIRONMENTS;
 _GLOBAL_CONST unsigned short DB_IT_SQL_ACCESSIBLE_TABLES;
 _GLOBAL_CONST signed short DB_SQL_GUID;
 _GLOBAL_CONST signed short DB_SQL_TIMESTAMP;
 _GLOBAL_CONST signed short DB_SQL_TIME;
 _GLOBAL_CONST signed short DB_SQL_DATE;
 _GLOBAL_CONST signed short DB_SQL_DOUBLE;
 _GLOBAL_CONST signed short DB_SQL_REAL;
 _GLOBAL_CONST signed short DB_SQL_TINYINT;
 _GLOBAL_CONST signed short DB_SQL_SMALLINT;
 _GLOBAL_CONST signed short DB_SQL_INTEGER;
 _GLOBAL_CONST signed short DB_SQL_BIGINT;
 _GLOBAL_CONST signed short DB_SQL_DECIMAL;
 _GLOBAL_CONST signed short DB_SQL_NUMERIC;
 _GLOBAL_CONST signed short DB_SQL_CHAR;
 _GLOBAL_CONST signed short DB_SQL_NO_DATA;
 _GLOBAL_CONST signed short DB_SQL_INVALID_HANDLE;
 _GLOBAL_CONST signed short DB_SQL_ERROR;
 _GLOBAL_CONST unsigned short DB_DEFAULT_PORT;
 _GLOBAL_CONST unsigned short DB_SYSTEM_MS_SQL;
 _GLOBAL_CONST unsigned short DB_SYSTEM_SYBASE;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct dbConnect
{
	/* VAR_INPUT (analog) */
	unsigned long pServerName;
	unsigned long pUserName;
	unsigned long pPassword;
	unsigned long pDatabaseName;
	unsigned long databaseSystem;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	unsigned long connectionIdent;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbConnect_typ;

typedef struct dbConnectEnc
{
	/* VAR_INPUT (analog) */
	unsigned long pServerName;
	unsigned long pUserName;
	unsigned long pPassword;
	unsigned long pDatabaseName;
	unsigned long databaseSystem;
	unsigned long pEncoding;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	unsigned long connectionIdent;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbConnectEnc_typ;

typedef struct dbExecuteSql
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	unsigned long pSqlStatement;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbExecuteSql_typ;

typedef struct dbGetAffectedRows
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	unsigned long affectedRows;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbGetAffectedRows_typ;

typedef struct dbGetColumnCount
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	signed short columnCount;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbGetColumnCount_typ;

typedef struct dbFetchNextRow
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbFetchNextRow_typ;

typedef struct dbGetData
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	unsigned long columnIdx;
	signed short dataType;
	unsigned long pData;
	unsigned long dataSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	unsigned long actDataSize;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbGetData_typ;

typedef struct dbDisconnect
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbDisconnect_typ;

typedef struct dbGetInfo
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	unsigned short infoType;
	unsigned long pServerInfo;
	unsigned long serverInfoSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	unsigned short actServerInfoSize;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbGetInfo_typ;

typedef struct dbGetErrorMessage
{
	/* VAR_INPUT (analog) */
	unsigned long connectionIdent;
	unsigned long pErrorMessage;
	unsigned long errorMessageSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short dbError;
	unsigned char sqlState[6];
	signed long nativeError;
	signed short actErrorMessageSize;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} dbGetErrorMessage_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void dbConnect(struct dbConnect* inst);
_BUR_PUBLIC void dbConnectEnc(struct dbConnectEnc* inst);
_BUR_PUBLIC void dbExecuteSql(struct dbExecuteSql* inst);
_BUR_PUBLIC void dbGetAffectedRows(struct dbGetAffectedRows* inst);
_BUR_PUBLIC void dbGetColumnCount(struct dbGetColumnCount* inst);
_BUR_PUBLIC void dbFetchNextRow(struct dbFetchNextRow* inst);
_BUR_PUBLIC void dbGetData(struct dbGetData* inst);
_BUR_PUBLIC void dbDisconnect(struct dbDisconnect* inst);
_BUR_PUBLIC void dbGetInfo(struct dbGetInfo* inst);
_BUR_PUBLIC void dbGetErrorMessage(struct dbGetErrorMessage* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASDB_ */

