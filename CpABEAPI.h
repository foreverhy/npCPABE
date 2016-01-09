/**********************************************************\

  Auto-generated CpABEAPI.h

\**********************************************************/

#include <string>
#include <vector>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "CpABE.h"

#include <unistd.h>
#include <glib.h>
#include <pbc/pbc.h>
#include <pbc/pbc_random.h>
#include <bswabe.h>

#ifndef H_CpABEAPI
#define H_CpABEAPI

class CpABEAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn CpABEAPI::CpABEAPI(const CpABEPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    CpABEAPI(const CpABEPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {
        registerMethod("echo",      make_method(this, &CpABEAPI::echo));
        registerMethod("testEvent", make_method(this, &CpABEAPI::testEvent));
        
        // Read-write property
        registerProperty("testString",
                         make_property(this,
                                       &CpABEAPI::get_testString,
                                       &CpABEAPI::set_testString));
        
        // Read-only property
        registerProperty("version",
                         make_property(this,
                                       &CpABEAPI::get_version));
        // CP-ABE
        //registerMethod("setup", make_method(this, &CpABEAPI::setup));
        registerMethod("get_token", make_method(this, &CpABEAPI::get_token));
        registerMethod("decrypt", make_method(this, &CpABEAPI::decrypt));
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn CpABEAPI::~CpABEAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~CpABEAPI() {};

    CpABEPtr getPlugin();

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method echo
    FB::variant echo(const FB::variant& msg);
    
    // Event helpers
    FB_JSAPI_EVENT(test, 0, ());
    FB_JSAPI_EVENT(echo, 2, (const FB::variant&, const int));

    // Method test-event
    void testEvent();

    // CP-ABE methods, based on libbswabe
    //FB::VariantList setup();
    //std::string keygen(const std::string &pub, const std::string &msk, const FB::VariantList &attrs);
    //void keygen_file(const std::string &pub, const std::string &msk, const FB::VariantList &attrs);
    //void save_file(const std::string path)
    std::string get_token(const std::string &uri);
    std::string decrypt(const std::string &pub_path, const std::string &prv_path, const std::string &hex_cipher);

private:
    CpABEWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_CpABEAPI

