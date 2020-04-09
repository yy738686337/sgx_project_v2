/*
 *  FILE: boost.log.init.hpp
 *  INSTRUCTION: 这个文件用于初始化boost.log
 *  DETAIL: 这里重新定义了日志级别和对应的文本内容. 
 *          文件大小限制等信息被硬编码在cpp文件中，如有需求可以修改。
 */
#ifndef BOOST_LOG_INIT_HPP
#define BOOST_LOG_INIT_HPP

#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/expressions/keyword.hpp>

#include <boost/log/attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>

#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <boost/log/attributes/named_scope.hpp>

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

enum severity_level
{
    Log_Debug,
    Log_Notice,
    Log_Warning,
    Log_Error,
};
typedef severity_level log_level;
typedef src::severity_logger< severity_level > log_t;


// The formatting logic for the severity level
template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (
    std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
{
    static const char* const str[] =
    {
        "Debug",
        "Notice",
        "Warning",
        "Error",
    };
    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;
}

BOOST_LOG_ATTRIBUTE_KEYWORD(log_severity, "Severity", severity_level)
BOOST_LOG_ATTRIBUTE_KEYWORD(log_timestamp, "TimeStamp", boost::posix_time::ptime)
BOOST_LOG_ATTRIBUTE_KEYWORD(log_uptime, "Uptime", attrs::timer::value_type)
BOOST_LOG_ATTRIBUTE_KEYWORD(log_scope, "Scope", attrs::named_scope::value_type)

void init_log(const std::string & path);

#define LOG_ERROR(x)       BOOST_LOG_SEV(x, Log_Error) 
#define LOG_DEBUG(x)       BOOST_LOG_SEV(x, Log_Debug)
#define LOG_NOTICE(x)      BOOST_LOG_SEV(x, Log_Notice) 
#define LOG_NAME(x)        BOOST_LOG_NAMED_SCOPE(x)
#endif